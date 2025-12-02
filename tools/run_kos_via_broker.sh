#!/bin/bash
set -euo pipefail
ROOT=$(realpath "$(dirname "$0")/..")
LOG_FILE="$ROOT/out.txt"
cd "$ROOT"
echo "[run-kos] запускаю ./cross-build.sh" | tee "$LOG_FILE"
./cross-build.sh 2>&1 | tee -a "$LOG_FILE"
echo "[run-kos] стартую брокер + qemu" | tee -a "$LOG_FILE"
CTL_EVENT_TTY=/dev/stdin python3 tools/event_broker.py 2>&1 | tee -a "$LOG_FILE"
