#!/bin/bash
set -euo pipefail

ROOT=$(realpath "$(dirname "$0")/..")
if [[ -n "${BUILD_DIR:-}" ]]; then
    BUILD_DIR="$BUILD_DIR"
else
    BUILD_DIR="$ROOT/build"
fi
LOG_DIR="$ROOT/out"
mkdir -p "$LOG_DIR"
LOG_FILE="$LOG_DIR/pal-tests.log"
: > "$LOG_FILE"

run_test() {
    local name="$1"
    shift
    echo "RUN $name" | tee -a "$LOG_FILE"
    if "$@" >>"$LOG_FILE" 2>&1; then
        echo "OK  $name" | tee -a "$LOG_FILE"
    else
        echo "FAIL $name" | tee -a "$LOG_FILE"
        echo "See $LOG_FILE for details" >&2
        exit 1
    fi
}

test_binary_exists() {
    [[ -x "$BUILD_DIR/controlsys/ControlSys" ]]
}

python_check() {
    python3 "$@"
}

run_test "controlsys-binary" test_binary_exists
run_test "event-scripts" python3 "$ROOT/tools/verify_event_scripts.py" "$ROOT/controlsys/src/core/event_script.c"
run_test "architecture-doc" python3 "$ROOT/tools/verify_docs_anchor.py" "$ROOT/docs/architecture.md"

echo "PAL TESTS COMPLETED" | tee -a "$LOG_FILE"
