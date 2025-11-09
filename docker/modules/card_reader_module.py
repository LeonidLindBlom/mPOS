import sys

from common import JsonTcpClient, log, wait_for_input, run_heartbeat


def mask_pan(pan: str) -> str:
    if len(pan) <= 6:
        return pan
    return f"{pan[:4]}{'*' * (len(pan) - 6)}{pan[-2:]}"


class CardReaderModule:
    def __init__(self):
        self.client = JsonTcpClient("card-reader")

    def send_card(self, tx_id: str, pan: str, expiry: str, holder: str) -> None:
        payload = {
            "panMasked": mask_pan(pan),
            "expiry": expiry,
            "track2": f"{pan}={expiry}123456789",
            "cardholderName": holder,
            "emv": {
                "aid": "A0000000031010",
                "cryptogram": "BEEF0102",
                "atc": 1,
            },
        }
        self.client.send("CardData", payload, tx_id=tx_id)

    def send_status(self, status: str) -> None:
        self.client.send("ReaderStatus", {"status": status})

    def interactive(self) -> None:
        log("card-reader", "интерактивный режим: команды card, status, heartbeat, quit")
        while True:
            line = wait_for_input("card> ")
            if not line:
                continue
            parts = line.split()
            cmd = parts[0].lower()
            if cmd in ("quit", "exit"):
                log("card-reader", "выход")
                break
            if cmd == "card":
                tx_id = parts[1] if len(parts) > 1 else wait_for_input("  txId: ")
                args = parts[2:]
                pan = args[0] if len(args) >= 1 else wait_for_input("  PAN: ")
                expiry = args[1] if len(args) >= 2 else wait_for_input("  expiry YYMM: ")
                holder = " ".join(args[2:]) if len(args) >= 3 else "JOHN DOE"
                self.send_card(tx_id, pan, expiry, holder)
            elif cmd == "status":
                status = parts[1] if len(parts) > 1 else "ready"
                self.send_status(status)
            elif cmd == "heartbeat":
                self.client.send("Heartbeat", {"status": "OK"})
            else:
                log("card-reader", "неизвестная команда")

    def auto(self) -> None:
        run_heartbeat("card-reader", interval=12)

    def run(self) -> None:
        if sys.stdin.isatty():
            self.interactive()
        else:
            self.auto()
