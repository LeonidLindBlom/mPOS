# mPOS ControlSys под KasperskyOS CE

Центральная система управления (ControlSys) исполняется внутри KasperskyOS (сущность `controlsys.ControlSys`). На текущем этапе он работает автономно (state-machine без POSIX-сокетов), а внешние модули (дисплей, ввод, принтер, сеть, банк) моделируются в Docker-заглушках на хосте. Когда появится полноценный сетевой стек, именно они будут общаться с ControlSys по TCP/JSON через проброшенные порты QEMU.

## Минимальная сборка вне Docker

```bash
source /opt/KasperskyOS-Community-Edition-1.2.0.89/set_env.sh
rm -rf build CMakeCache.txt CMakeFiles
./cross-build.sh
cmake --build build
cmake --build build --target run
```

Контрольные точки:
- `grep -n "ROFS ] File" build/out.txt` — убедиться, что `/ControlSys` попал в образ.
- `sed -n '1,40p' build/einit/EinitQemu-kss/init.yaml` — проверить автозапуск `controlsys.ControlSys`.

## Docker-окружение (WIP)

Каталог `docker/` содержит разные слои для будущей автоматизации (Dockerfile c SDK и заглушки модулей). Пока инфраструктура экспериментальная и тормозится требованием KasperskyOS SDK к интерактивному `set_env.sh`, так что основной способ сборки — локальный. К Docker ещё вернёмся, когда проработаем устойчивый сценарий без интерактивных скриптов.

### Мок-модули (Python)

В `docker/modules/` лежат заглушки:

- `module_stub.py` — точка входа. Для `MODULE_NAME=input` и `MODULE_NAME=card-reader` запускает интерактивные CLI.
- `input_module.py` — команды `amount`, `pin`, `cancel`, `heartbeat`, `quit`. Соединяется с ControlSys по `TARGET_HOST`/`TARGET_PORT`.
- `card_reader_module.py` — команды `card <txId> <PAN> <YYMM> [holder]`, `status`, `heartbeat`, `quit`.

Пример запуска (в отдельном терминале):

```bash
cd docker
docker compose up card_reader
# или интерактивно
docker compose run --rm -it input
```

Остальные сервисы (display/printer/netgw/bank) пока отправляют heartbeat-заглушки и будут дорабатываться по мере появления протокола.

Чтобы прислать событие напрямую в ControlSys (эмуляция UART), во время работы QEMU можно ввести JSON-строку в консоль, например:

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
- `src/core/event_channel.c` (`include/controlsys/event_channel.h`) — приём JSON-событий из stdin (эмуляция UART/TCP).
- `src/core/event_script.c` (`include/controlsys/events.h`) — fallback-сценарий событий, если внешний канал молчит.
- `src/core/state_machine.c` (`include/controlsys/state_machine.h`) — обработчик событий, переводящий автомат между состояниями.
- `src/core/card_verifier.c`, `status_verifier.c`, `auth_module.c`, `journal.c`, `txn_builder.c`, `update_loader.c`, `update_storage.c`, `update_verifier.c`, `update_installer.c` (`include/controlsys/services/*`) — заглушки доменных сервисов (проверка карты, статуса, аутентификация, журнал, сборка и установка обновлений).
- `src/main.c` — точка входа, инициализация и запуск автомата.

Такой раздельный подход позволит позже подключить реальные обработчики событий, сетевой ввод и журналирование, не переписывая монолитный файл.

## Дальнейшие шаги

- Расширить current state machine обработкой реальных событий/сообщений.
- Подключить KSS Flow/Struct/Regex-политику и формализовать JSON-протоколы.
- Заменить `module_stub.py` на полноценные Python-сценарии с логикой входных сигналов/ответов.

© 2024 AO Kaspersky Lab / mPOS Lab
