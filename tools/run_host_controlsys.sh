#!/bin/bash
set -euo pipefail
ROOT=$(realpath "$(dirname "$0")/..")
OUT_DIR="$ROOT/build-host"
BIN="$OUT_DIR/ControlSysHost"
if [ ! -x "$BIN" ]; then
    "$ROOT/tools/build_host_controlsys.sh"
fi
cd "$ROOT"
CTL_EVENT_TTY=/dev/stdin python3 tools/event_broker.py --cmd "$BIN"
