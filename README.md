# mPOS ControlSys под KasperskyOS CE

Центральная система управления (ControlSys) исполняется внутри KasperskyOS (сущность `controlsys.ControlSys`). Внешние события теперь приходят через выделенный «виртуальный UART»: QEMU пробрасывает дополнительный сериал-порт на сокет `0.0.0.0:28090`, а ControlSys читает из соответствующего TTY (`/dev/ttyAMA1`). Любой модуль (в Docker или вне его) может установить TCP-подключение к этому порту и отправлять JSON-события. Если порт недоступен, используется fallback-stdin + встроенный сценарий.

## Минимальная сборка вне Docker

```bash
source /opt/KasperskyOS-Community-Edition-1.2.0.89/set_env.sh
rm -rf build CMakeCache.txt CMakeFiles
./cross-build.sh          # строим образ (по умолчанию qemu не запускается)
cmake --build build
# при необходимости запустить qemu: cmake --build build --target run
```

Контрольные точки:
- `grep -n "ROFS ] File" build/out.txt` — убедиться, что `/ControlSys` попал в образ.
- `sed -n '1,40p' build/einit/EinitQemu-kss/init.yaml` — проверить автозапуск `controlsys.ControlSys`.

## Docker-окружение (WIP)

Каталог `docker/` содержит разные слои для будущей автоматизации (Dockerfile c SDK и заглушки модулей). Пока инфраструктура экспериментальная и тормозится требованием KasperskyOS SDK к интерактивному `set_env.sh`, так что основной способ сборки — локальный. К Docker ещё вернёмся, когда проработаем устойчивый сценарий без интерактивных скриптов.

Сервис `controlsys` внутри `docker-compose` запускает QEMU с параметрами:

- дополнительный сериал-порт `-chardev socket,...,port=${CONTROL_SYS_EVENT_PORT:-28090}` → `-serial chardev:eventbus`;
- user-net `-netdev user,id=hostnet0${CONTROL_SYS_QEMU_HOSTFWD}`.

На машине разработчика доступны порты:

- `28080` — event channel (JSON-события для state-machine);
- `28081`/`28082`/`28083`/`28084` — дальнейшие каналы для модулей ввода/ридера/дисплея/принтера;
- `29090` — зарезервировано под сетевой шлюз / банк.
- `28090` — UART-мост (подключение к ControlSys через virtio/tty). Поведение задаётся переменными `CONTROL_SYS_EVENT_HOST` (по умолчанию 127.0.0.1) и `CONTROL_SYS_EVENT_PORT` (по умолчанию 28090). В docker-compose эти переменные выставлены в `0.0.0.0`/`28090`, чтобы порт был доступен извне контейнера.

### Мок-модули (Python)

В `docker/modules/` лежат заглушки:

- `module_stub.py` — точка входа. Для `MODULE_NAME=input` и `MODULE_NAME=card-reader` запускает интерактивные CLI.
- `input_module.py` — команды `amount`, `pin`, `cancel`, `heartbeat`, `quit`. Соединяется с ControlSys по `TARGET_HOST`/`TARGET_PORT`.
- `card_reader_module.py` — команды `card <txId> <PAN> <YYMM> [holder]`, `status`, `heartbeat`, `quit`.
- `event_sender.py` — быстрый сценарий, который шлёт полную успешную транзакцию + цикл обновления (удобно для smoke-тестов TCP-канала).

Пример запуска (в отдельном терминале):

```bash
cd docker
docker compose up card_reader
# или интерактивно
docker compose run --rm -it input
```

Остальные сервисы (display/printer/netgw/bank) пока отправляют heartbeat-заглушки и будут дорабатываться по мере появления протокола.

### Быстрый запуск через брокер событий

Чтобы не отправлять JSON вручную в терминал, есть скрипт-брокер `tools/event_broker.py`, который:

1. Запускает ControlSys (`cmake --build build --target run`);
2. Слушает TCP (по умолчанию `0.0.0.0:28090`);
3. Каждую строку JSON от клиентов пересылает в stdin ControlSys.

Использование:

```bash
./cross-build.sh                 # собираем образ для KOS
tools/run_kos_via_broker.sh      # брокер + запуск cmake --build build --target run
```

Брокер слушает `0.0.0.0:28090` и пересылает строки в stdin ControlSys (который уже работает в KOS). Любой модуль может слать JSON на этот порт:

```bash
cd docker
EVENT_HOST=127.0.0.1 EVENT_PORT=28090 python3 modules/event_sender.py
```

Если хочется руками протестировать сценарий, можно подключиться `nc 127.0.0.1 28090` и вводить строки вроде:

```
{"type":"SetAmount","amount":15000,"currency":"RUB"}
{"type":"CardData","emvOk":1}
{"type":"PinEntered"}
{"type":"BankResponse","approved":1}
{"type":"UpdateRequest","role":"operator"}
{"type":"UpdatePayload","version":"1.0.2","size":1048576,"chunk":1,"chunks":1,"sig":1}
{"type":"UpdateVerify","sig":1}
{"type":"UpdateInstall","ok":1}
```

Каждая строка соответствует событию `CtlEvent` и сразу отправляется в state machine.

## Архитектура ControlSys

Исходники лежат в `controlsys/src` и разбиты на модули:

- `src/core/log.c` (`include/controlsys/log.h`) — единый логгер с таймстемпами.
- `src/core/tx.c` (`include/controlsys/tx.h`) — контекст транзакции и вспомогательные функции state-machine.
- `src/core/event_channel.c` — читает события из stdin (переменная `CTL_EVENT_TTY` позволяет указать другой источник, но по умолчанию достаточно подавать JSON в stdin процесса ControlSys).
- `src/core/event_script.c` (`include/controlsys/events.h`) — fallback-сценарий событий, если внешний канал молчит.
- `src/core/state_machine.c` (`include/controlsys/state_machine.h`) — обработчик событий, переводящий автомат между состояниями.
- `src/core/net_verifier.c`, `power_verifier.c`, `init_module.c`, `card_verifier.c`, `status_verifier.c`, `output_controller.c`, `auth_module.c`, `journal.c`, `txn_builder.c`, `update_loader.c`, `update_storage.c`, `update_verifier.c`, `update_installer.c` (`include/controlsys/services/*`) — доменные сервисы (проверка канала связи, питания, разрешение старта, проверка карты и ответа банка, управление выводом, аутентификация, журнал и цепочка обновлений).
- `src/main.c` — точка входа, инициализация и запуск автомата.
- `external/env` — обёртка, которая раздаёт переменные окружения и аргументы для сущностей ControlSys.

Такой раздельный подход позволит позже подключить реальные обработчики событий, сетевой ввод и журналирование, не переписывая монолитный файл.

⚠️ В текущем демо-варианте внешний канал событий отключён: `state_machine.c` последовательно проигрывает три встроенных сценария (`event_script.c`) — транзакцию, обновление и выгрузку журнала. Это позволяет отладить логику доменов, не подключая брокер. Когда понадобится принять реальные команды, достаточно вернуть чтение из `event_channel.c` в `sm_run_demo()`.

Подробный отчёт по доменам безопасности, каналам связи и сценариям (PlantUML → реализация) живёт в `docs/architecture.md`. Обновляем его при изменении интерфейсов.

## Дальнейшие шаги

- Расширить current state machine обработкой реальных событий/сообщений.
- Подключить KSS Flow/Struct/Regex-политику и формализовать JSON-протоколы.
- Заменить `module_stub.py` на полноценные Python-сценарии с логикой входных сигналов/ответов.
- Следить за актуальной архитектурой/каналами связи в `docs/architecture.md` — сюда заносим все принятые решения по мостам, UART, сетям и т.д.
- Развивать брокер: сейчас он просто пересылает события в stdin ControlSys; далее можно добавить подтверждения, маршрутизацию по `target` и т.п.

## PAL‑тесты

Smoke-проверки собраны в кастомный таргет `pal-test0`, который вызывает `tools/run_pal_tests.sh` и прогоняет статические проверки (наличие бинарника, целостность сценариев, ключевые разделы документации).

Для описания потоков взаимодействия подготовлен файл `pal/tests/controlsys_flow.pal`, где декларативно зафиксированы сценарии "transaction_flow", "update_flow" и "log_export_flow" (setup, взаимные вызовы и ожидаемые grant/response). Его можно использовать как основу для будущих PAL‑проверок и расширять негативными кейсами.

```bash
./cross-build.sh --target pal-test0
```

Каждый тест выводится в формате `RUN <test>` / `OK <test>` и дублируется в `out/pal-tests.log`.

Для негативных сценариев (нарушение условий безопасности, откаты обновлений и т.д.) добавлен отдельный набор `pal/tests/controlsys_negative.pal` и таргет:

```bash
./cross-build.sh --target pal-test-negative
```

Скрипт `tools/run_pal_negative_tests.sh` так же выводит каждую проверку (`RUN/OK`) и сохраняет журнал в `out/pal-negative-tests.log`.

© 2024 AO Kaspersky Lab / mPOS Lab
