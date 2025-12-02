#!/bin/bash
set -euo pipefail
ROOT=$(realpath "$(dirname "$0")/..")
OUT_DIR=${1:-"$ROOT/build-host"}
mkdir -p "$OUT_DIR"
SRC_DIR="$ROOT/controlsys"
SRC_FILES=(
    "$SRC_DIR/src/main.c"
    "$SRC_DIR/src/core/auth_module.c"
    "$SRC_DIR/src/core/card_verifier.c"
    "$SRC_DIR/src/core/event_channel.c"
    "$SRC_DIR/src/core/event_script.c"
    "$SRC_DIR/src/core/journal.c"
    "$SRC_DIR/src/core/log.c"
    "$SRC_DIR/src/core/state_machine.c"
    "$SRC_DIR/src/core/status_verifier.c"
    "$SRC_DIR/src/core/tx.c"
    "$SRC_DIR/src/core/txn_builder.c"
    "$SRC_DIR/src/core/update_installer.c"
    "$SRC_DIR/src/core/update_loader.c"
    "$SRC_DIR/src/core/update_storage.c"
    "$SRC_DIR/src/core/update_verifier.c"
)
CC=${CC:-gcc}
CFLAGS="${CFLAGS:--std=c11 -Wall -Wextra -Wconversion -O2}"
INCLUDES=(-I"$SRC_DIR/include")
OUT_BIN="$OUT_DIR/ControlSysHost"
$CC $CFLAGS "${INCLUDES[@]}" "${SRC_FILES[@]}" -o "$OUT_BIN"
echo "[host-build] собран $OUT_BIN"
