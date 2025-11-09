import os
import sys

from card_reader_module import CardReaderModule
from common import JsonTcpClient, log, run_heartbeat
from input_module import InputModule


def default_client():
    role = os.getenv("MODULE_NAME", "stub")
    interval = float(os.getenv("HEARTBEAT_INTERVAL", "8"))
    log(role, "режим заглушки: heartbeat-loop")
    run_heartbeat(role, interval=interval)


def main():
    role = os.getenv("MODULE_NAME", "stub").lower()
    if role == "input":
        InputModule().run()
        return
    if role in ("card-reader", "card_reader"):
        CardReaderModule().run()
        return

    mode = os.getenv("MODULE_MODE", "client").lower()
    if mode == "server":
        # временно используем heartbeat вместо сервера
        log(role, "server mode пока не реализован, использую heartbeat")
    default_client()


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        sys.exit(0)
