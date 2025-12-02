#!/usr/bin/env python3
"""
Простой брокер событий:
 - запускает команду (по умолчанию `cmake --build build --target run`);
 - слушает TCP-порт (по умолчанию 0.0.0.0:28090);
 - каждый принятый JSON от клиента пересылает в stdin ControlSys;
 - stdout/stderr ControlSys транслируются в консоль брокера.

Использование:
    ./cross-build.sh        # один раз, чтобы собрать
    python3 tools/event_broker.py \
        --cmd "/opt/.../cmake --build build --target run" \
        --host 0.0.0.0 --port 28090
"""

import argparse
import socket
import threading
import subprocess
import sys
from pathlib import Path

DEFAULT_CMD = ["/opt/KasperskyOS-Community-Edition-1.2.0.89/toolchain/bin/cmake",
               "--build", "build", "--target", "run"]


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Event broker for ControlSys")
    parser.add_argument("--host", default="0.0.0.0",
                        help="Адрес для прослушивания TCP (default: %(default)s)")
    parser.add_argument("--port", type=int, default=28090,
                        help="Порт для прослушивания TCP (default: %(default)s)")
    parser.add_argument("--cmd", nargs=argparse.REMAINDER,
                        help="Команда для запуска ControlSys "
                             "(default: cmake --build build --target run)")
    return parser.parse_args()


def spawn_controlsys(cmd: list[str]) -> subprocess.Popen:
    print(f"[broker] стартую ControlSys: {' '.join(cmd)}", flush=True)
    return subprocess.Popen(
        cmd,
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
        bufsize=1,
        universal_newlines=True,
    )


def pump_stdout(proc: subprocess.Popen) -> None:
    assert proc.stdout
    for line in proc.stdout:
        sys.stdout.write(line)
    sys.stdout.flush()


def handle_client(conn: socket.socket, addr: tuple[str, int],
                  proc: subprocess.Popen, lock: threading.Lock) -> None:
    print(f"[broker] соединение от {addr[0]}:{addr[1]}", flush=True)
    try:
        with conn, conn.makefile("r") as reader:
            for line in reader:
                payload = line.strip()
                if not payload:
                    continue
                with lock:
                    if proc.stdin:
                        proc.stdin.write(payload + "\n")
                        proc.stdin.flush()
                conn.sendall(b'{"status":"accepted"}\n')
    except Exception as exc:
        print(f"[broker] ошибка клиента {addr}: {exc}", flush=True)


def main() -> None:
    args = parse_args()
    cmd = args.cmd if args.cmd else DEFAULT_CMD

    if not Path("build/CMakeCache.txt").exists():
        print("[broker] каталога build нет. Сначала запусти ./cross-build.sh", file=sys.stderr)
        sys.exit(1)

    proc = spawn_controlsys(cmd)
    stdout_thread = threading.Thread(target=pump_stdout, args=(proc,), daemon=True)
    stdout_thread.start()

    client_lock = threading.Lock()

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as srv:
        srv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        srv.bind((args.host, args.port))
        srv.listen(5)
        print(f"[broker] слушаю {args.host}:{args.port}", flush=True)

        try:
            while proc.poll() is None:
                conn, addr = srv.accept()
                threading.Thread(
                    target=handle_client,
                    args=(conn, addr, proc, client_lock),
                    daemon=True,
                ).start()
        except KeyboardInterrupt:
            print("[broker] остановка по Ctrl+C", flush=True)
        finally:
            if proc.poll() is None:
                proc.terminate()
                proc.wait()


if __name__ == "__main__":
    main()
