import json
import os
import socket
import sys
import time
from dataclasses import dataclass
from typing import Any, Dict, Optional


def log(module: str, message: str) -> None:
    sys.stdout.write(f"[{module}] {message}\n")
    sys.stdout.flush()


def env_str(key: str, default: str) -> str:
    return os.getenv(key, default)


def env_int(key: str, default: int) -> int:
    try:
        return int(os.getenv(key, str(default)))
    except (TypeError, ValueError):
        return default


@dataclass
class Message:
    module: str
    event: str
    payload: Dict[str, Any]
    tx_id: str = ""
    seq: int = 0
    target: Optional[str] = None
    error: Optional[Dict[str, Any]] = None

    def as_json(self) -> str:
        doc: Dict[str, Any] = {
            "module": self.module,
            "event": self.event,
            "txId": self.tx_id,
            "seq": self.seq,
            "timestamp": time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime()),
            "payload": self.payload,
        }
        if self.target:
            doc["target"] = self.target
        if self.error:
            doc["error"] = self.error
        return json.dumps(doc, ensure_ascii=False)


class JsonTcpClient:
    def __init__(self, module: str):
        self.module = module
        self.host = env_str("TARGET_HOST", "controlsys")
        self.port = env_int("TARGET_PORT", 0)
        self.seq = 0

    def send(self, event: str, payload: Dict[str, Any], tx_id: str = "", target: Optional[str] = None,
             error: Optional[Dict[str, Any]] = None) -> None:
        if self.port == 0:
            log(self.module, "TARGET_PORT не задан, пропускаю отправку")
            return
        self.seq += 1
        msg = Message(
            module=self.module,
            event=event,
            payload=payload,
            tx_id=tx_id,
            seq=self.seq,
            target=target,
            error=error,
        )
        data = (msg.as_json() + "\n").encode("utf-8")
        try:
            with socket.create_connection((self.host, self.port), timeout=5) as conn:
                conn.sendall(data)
                conn.shutdown(socket.SHUT_WR)
                resp = conn.recv(512)
            log(self.module, f"→ {msg.event} (seq={self.seq}, tx={tx_id or 'n/a'})")
            if resp:
                log(self.module, f"← {resp.decode('utf-8', errors='ignore').strip()}")
        except OSError as exc:
            log(self.module, f"нет связи с {self.host}:{self.port}: {exc}")


def wait_for_input(prompt: str) -> str:
    sys.stdout.write(prompt)
    sys.stdout.flush()
    return sys.stdin.readline().strip()


def run_heartbeat(module: str, interval: float = 5.0) -> None:
    client = JsonTcpClient(module)
    log(module, f"heartbeat каждые {interval}s (host={client.host}, port={client.port})")
    while True:
        client.send("Heartbeat", {"status": "OK"})
        time.sleep(interval)
