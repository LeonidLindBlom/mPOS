import json
import sys
from typing import Optional

from common import JsonTcpClient, log, wait_for_input, run_heartbeat


class InputModule:
    def __init__(self):
        self.client = JsonTcpClient("input")

    def _send_amount(self, amount_cents: int, currency: str, note: str) -> None:
        payload = {
            "amount": amount_cents,
            "currency": currency,
            "note": note,
            "operatorId": "cashier-01",
        }
        self.client.send("SetAmount", payload, tx_id="")

    def _send_pin(self, tx_id: str, pin: str, retries: int) -> None:
        payload = {
            "pinToken": pin,
            "method": "plaintext",
            "retriesLeft": retries,
            "cancelled": False,
        }
        self.client.send("PINEntered", payload, tx_id=tx_id)

    def _send_cancel(self, tx_id: str, reason: str) -> None:
        payload = {"reason": reason}
        self.client.send("Cancel", payload, tx_id=tx_id)

    @staticmethod
    def _parse_amount(amount_str: str) -> int:
        amount_str = amount_str.replace(",", ".")
        value = float(amount_str)
        return int(round(value * 100))

    def interactive(self) -> None:
        log("input", "интерактивный режим: команды amount, pin, cancel, json, heartbeat, quit")
        while True:
            line = wait_for_input("input> ")
            if not line:
                continue
            parts = line.split()
            cmd = parts[0].lower()
            try:
                if cmd in ("quit", "exit"):
                    log("input", "выход")
                    break
                if cmd == "amount":
                    amount_str = parts[1] if len(parts) > 1 else wait_for_input("  сумма (рубли): ")
                    currency = parts[2] if len(parts) > 2 else "RUB"
                    note = " ".join(parts[3:]) if len(parts) > 3 else ""
                    amount = self._parse_amount(amount_str)
                    self._send_amount(amount, currency, note)
                elif cmd == "pin":
                    tx_id = parts[1] if len(parts) > 1 else wait_for_input("  txId: ")
                    pin = parts[2] if len(parts) > 2 else wait_for_input("  PIN: ")
                    retries = int(parts[3]) if len(parts) > 3 else 2
                    self._send_pin(tx_id, pin, retries)
                elif cmd == "cancel":
                    tx_id = parts[1] if len(parts) > 1 else wait_for_input("  txId: ")
                    reason = " ".join(parts[2:]) if len(parts) > 2 else "operator_cancel"
                    self._send_cancel(tx_id, reason)
                elif cmd == "json":
                    raw = wait_for_input("  JSON payload: ")
                    payload = json.loads(raw)
                    tx_id = payload.get("txId", "")
                    event = payload.get("event", "Custom")
                    body = payload.get("payload", {})
                    self.client.send(event, body, tx_id=tx_id)
                elif cmd == "heartbeat":
                    self.client.send("Heartbeat", {"status": "OK", "uptimeSec": 0})
                else:
                    log("input", "неизвестная команда")
            except (ValueError, IndexError) as exc:
                log("input", f"ошибка ввода: {exc}")
            except json.JSONDecodeError as exc:
                log("input", f"ошибка JSON: {exc}")

    def auto(self) -> None:
        run_heartbeat("input", interval=10)

    def run(self) -> None:
        if sys.stdin.isatty():
            self.interactive()
        else:
            self.auto()
