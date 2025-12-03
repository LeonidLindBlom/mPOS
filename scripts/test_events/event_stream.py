#!/usr/bin/env python3
import json
import os
import socket
import time
from typing import Iterable, Dict, Any

HOST = os.getenv("EVENT_HOST", "127.0.0.1")
PORT = int(os.getenv("EVENT_PORT", "28090"))
INTERVAL = float(os.getenv("EVENT_STREAM_INTERVAL", "1.5"))
RETRY_DELAY = float(os.getenv("EVENT_STREAM_RETRY", "2.0"))

BASE_SEQUENCE = [
    {"type": "Heartbeat", "network": 1, "ping": 1, "power": 1,
     "seq": 0, "signal": 85, "mv": 3800, "soc": 80, "droop": 1},
    {"type": "SetAmount", "amount": 12345, "currency": "RUB"},
    {"type": "CardData", "emvOk": 1,
     "pan": "4256********9310", "expiry": "2712", "holder": "CARDHOLDER"},
    {"type": "PinEntered"},
    {"type": "BankResponse", "approved": 1, "seq": 1, "latency": 100},
    {"type": "UpdateRequest", "role": "operator"},
    {"type": "UpdatePayload", "version": "1.0.1", "size": 1048576,
     "chunk": 1, "chunks": 2, "sig": 1},
    {"type": "UpdatePayload", "version": "1.0.1", "size": 1048576,
     "chunk": 2, "chunks": 2, "sig": 1},
    {"type": "UpdateVerify", "sig": 1},
    {"type": "UpdateInstall", "ok": 1},
]

def stream_events(sequence: Iterable[Dict[str, Any]]) -> None:
    seq_counter = 1
    while True:
        try:
            with socket.create_connection((HOST, PORT)) as sock:
                print(f"[stream] connected to {HOST}:{PORT}")
                for template in sequence:
                    event = dict(template)
                    if event.get("type") == "Heartbeat":
                        event["seq"] = seq_counter
                        seq_counter += 1
                    payload = json.dumps(event, ensure_ascii=False)
                    sock.sendall(payload.encode("utf-8") + b"\n")
                    print("->", payload)
                    time.sleep(INTERVAL)
        except (OSError, ConnectionError) as exc:
            print(f"[stream] connection error: {exc}; retry in {RETRY_DELAY}s")
            time.sleep(RETRY_DELAY)


def main() -> None:
    sequence = BASE_SEQUENCE
    stream_events(sequence)


if __name__ == "__main__":
    main()
