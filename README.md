# mPOS ControlSys под KasperskyOS CE

Это эталонная реализация центрального менеджера mPOS, запущенная как набор изолированных доменов KasperskyOS. Менеджер принимает JSON‑события (heartbeat, SetAmount, CardData, BankResponse, обновления) и маршрутизирует их в отдельные доверенные компоненты (верификаторы, журнал, загрузчик обновлений и т.д.). Внешние модули общаются с системой через простой TCP‑прокси, который перекидывает строки JSON в stdin ControlSys.

Никакой Docker‑окружение больше не требуется — всё собирается и запускается напрямую на хосте с установленным KasperskyOS SDK.

## Структура репозитория

| Путь | Содержимое |
| --- | --- |
| `controlsys/src` | Общие исходники ControlSys (state machine, event channel, доменные сервисы). |
| `controlsys/domains/*` | Отдельные бинарники-домены (`InputGuard`, `OutputController`, …) с собственным `main.c`, которые подключают код из `controlsys/src/core`. |
| `controlsys/include` | Публичные заголовки (`log.h`, `services/*.h`, `ipc_transport.h`). |
| `resources/idl`, `resources/edl` | Интерфейсы IDL/EDL для генерации прокси и security policy. |
| `einit/` | PSL-политика, init.yaml и сборка образа KOS/QEMU. |
| `tools/` | Утилиты для запуска QEMU (`run_kos_via_broker.sh`, `event_broker.py`), PAL‑тестов и вспомогательных проверок. |
| `scripts/test_events/` | Python‑скрипты, которые генерируют JSON‑события (`event_sender.py`, `event_stream.py`, заглушки модулей). Достаточно запускать их обычным `python3`. |
| `pal/tests/` | PAL‑описания позитивных и негативных сценариев. |
| `out/`, `out.txt` | Логи сборки, QEMU и PAL‑прогонов. |

## Сборка и запуск

```bash
source /opt/KasperskyOS-Community-Edition-1.2.0.89/set_env.sh
./cross-build.sh --target kos-qemu-image    # один раз после изменений
```

Образ лежит в `build/einit/kos-qemu-image`. Дальше есть два способа запустить ControlSys.

### 1. Прямой запуск QEMU (демо-сценарий)

```bash
CONTROL_SYS_EVENT_HOST=0.0.0.0 CONTROL_SYS_EVENT_PORT=28090 \
  /opt/KasperskyOS-Community-Edition-1.2.0.89/toolchain/bin/cmake \
  --build build --target sim | tee out.txt
```

State machine проиграет встроенные сквозные сценарии (транзакция → обновление → выгрузка журнала) и в конце напишет «ожидаю внешние события». В этот момент ControlSys читает stdin — можно вручную вводить JSON.

### 2. QEMU + брокер событий (рекомендуется для автотестов)

`tools/event_broker.py` стартует сборку `sim`, слушает выбранный порт и каждую строку от клиентов пересылает в stdin ControlSys.

```bash
CONTROL_SYS_EVENT_HOST=0.0.0.0 CONTROL_SYS_EVENT_PORT=28090 \
CTL_EVENT_TTY=/dev/stdin \
python3 tools/event_broker.py \
  --host 0.0.0.0 --port 28100 \
  --cmd /opt/KasperskyOS-Community-Edition-1.2.0.89/toolchain/bin/cmake \
  --build build --target sim
```

Во втором терминале запустите генератор событий:

```bash
EVENT_HOST=127.0.0.1 EVENT_PORT=28100 \
  python3 scripts/test_events/event_stream.py
# или однократный сценарий
EVENT_HOST=127.0.0.1 EVENT_PORT=28100 \
  python3 scripts/test_events/event_sender.py
```

`event_stream.py` поддерживает `EVENT_STREAM_INTERVAL` (секунды между событиями) и автоматически переподключается при сбоях.

## Доменная архитектура

Каждый Security Domain собирается отдельным бинарем и запускается EInit’ом. Сервисные идентификаторы описаны в `einit/src/init.yaml.in`, а политика обмена — в `einit/src/security.psl.in`.

| Домен | Ответственность | Ключевые модули |
| --- | --- | --- |
| `controlsys.InputGuard` | Принимает heartbeat, анализирует состояние сети/питания, решает, можно ли начинать транзакцию. | `net_verifier.c`, `power_verifier.c`, `init_module.c`. |
| `controlsys.OutputController` | Управляет отображением и печатью, рисует рамки сообщений, печатает чек. | `output_controller.c`. |
| `controlsys.CardVerifier` | Проверяет данные карты и введённый PIN, выдаёт статус (OK/отказ). | `card_verifier.c`. |
| `controlsys.TransactionGenerator` | Собирает транзакцию, подписывает и отправляет в сеть. | `txn_builder.c`, `tx.c`. |
| `controlsys.StatusVerifier` | Проверяет ответ банка (seq/подпись), переводит автомат в Approved/Declined. | `status_verifier.c`. |
| `controlsys.AuthModule` | Аутентифицирует оператора/инженера перед выгрузкой журнала или обновлением. | `auth_module.c`. |
| `controlsys.Journal` | Ведёт журнал транзакций, поддерживает выгрузку записей. | `journal.c`. |
| `controlsys.UpdateLoader` | Получает поток пакетов обновления. | `update_loader.c`. |
| `controlsys.UpdateStorage` | Собирает пакеты, хранит во временном буфере. | `update_storage.c`. |
| `controlsys.UpdateVerifier` | Проверяет подпись и целостность обновления. | `update_verifier.c`. |
| `controlsys.UpdateInstaller` | Применяет проверенное обновление. | `update_installer.c`. |

Файл `controlsys/src/core/state_machine.c` остаётся централизованным менеджером, который принимает события (`event_channel.c`), ведёт состояние и вызывает нужные домены через IPC (`clients.c`, `ipc_transport.c`).

## Сервисные модули `controlsys/src/core`

- `event_channel.c` — читает JSON либо из /dev/tty*, либо из stdin (по умолчанию). Поддерживает буферизацию и автоматический fallback.
- `event_script.c` — набор встроенных сценариев (три последовательности: транзакция, обновление, выгрузка журнала). Удобен для smoke‑тестов, когда внешний канал отключён.
- `log.c` — таймстемпы в стиле `[2025-12-03T20:31:35Z] Message`.
- `clients.c` / `clients.h` — обёртки над NK IPC для каждого домена (`status_verifier_client`, `update_loader_client`, …).
- `ipc_transport.[ch]` — подготовка `NkKosTransport`, установка соединения по Service Locator.
- `tx.c` / `tx.h` — описание состояния транзакции, генерация идентификаторов, вспомогательные функции state machine.

Все заголовки доступны из `controlsys/include/controlsys`.

## Отказ от Docker


## PAL‑тесты

```bash
./cross-build.sh --target pal-test0           # позитивные сценарии
./cross-build.sh --target pal-test-negative   # негативные
```

Скрипты `tools/run_pal_tests.sh` и `tools/run_pal_negative_tests.sh` сохраняют отчёты в `out/pal-tests.log` и `out/pal-negative-tests.log`. Сценарии описаны в:

- `pal/tests/controlsys_flow.pal` — транзакция, обновление, выгрузка журнала.
- `pal/tests/controlsys_negative.pal` — нарушения ЦБ-1…ЦБ-7 (подмена карты, сбой батареи, сторонние приложения и т.д.).

## Полезные файлы

- `docs/architecture.md` — подробные последовательности (PlantUML), цели безопасности и допущения.
- `resources/romfs/etc/hosts` — содержимое ROMFS (например, сетевой конфиг).
- `tools/event_broker.py` — универсальный мост TCP→stdin.
- `scripts/test_events/event_sender.py`, `event_stream.py` — генераторы событий (без Docker).

## Что дальше

- Расширить state machine реальным асинхронным каналом (события из брокера или virtio‑UART).
- Доработать скрипты в `scripts/test_events` (больше негативных сценариев, параметризация).
- Формализовать JSON‑протоколы в `resources/idl` и связать их с security policy (Flow/Struct).

© 2024 AO Kaspersky Lab / mPOS Lab
