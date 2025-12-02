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
    local start_ns end_ns duration
    start_ns=$(date +%s%N)
    printf "RUN  %s\n" "$name" | tee -a "$LOG_FILE"
    if "$@" >>"$LOG_FILE" 2>&1; then
        end_ns=$(date +%s%N)
        duration=$(( (end_ns - start_ns) / 1000000 ))
        printf "OK   %s (%s ms)\n" "$name" "$duration" | tee -a "$LOG_FILE"
    else
        printf "FAIL %s\n" "$name" | tee -a "$LOG_FILE"
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

pal_file_exists() {
    [[ -f "$ROOT/pal/tests/controlsys_flow.pal" ]]
}

readme_pal_section() {
    grep -q "PAL" "$ROOT/README.md"
}

cmake_has_pal_target() {
    grep -q "pal-test0" "$ROOT/controlsys/CMakeLists.txt"
}

python_compile_checks() {
    python3 -m py_compile "$ROOT"/tools/verify_*.py
}

run_test "controlsys-binary" test_binary_exists
run_test "event-scripts" python3 "$ROOT/tools/verify_event_scripts.py" "$ROOT/controlsys/src/core/event_script.c"
run_test "architecture-doc" python3 "$ROOT/tools/verify_docs_anchor.py" "$ROOT/docs/architecture.md"
run_test "pal-file" pal_file_exists
run_test "pal-min-seq" python3 "$ROOT/tools/verify_pal_structure.py" "$ROOT/pal/tests/controlsys_flow.pal" min_sequences 12
run_test "pal-transaction" python3 "$ROOT/tools/verify_pal_structure.py" "$ROOT/pal/tests/controlsys_flow.pal" require_sequences transaction_flow heartbeat amount card pin bank status receipt
run_test "pal-update" python3 "$ROOT/tools/verify_pal_structure.py" "$ROOT/pal/tests/controlsys_flow.pal" require_sequences update_flow request chunks snapshot verify-signature install
run_test "pal-log-export" python3 "$ROOT/tools/verify_pal_structure.py" "$ROOT/pal/tests/controlsys_flow.pal" require_sequences log_export_flow auth export export-complete
run_test "pal-scenario-exists" python3 "$ROOT/tools/verify_pal_structure.py" "$ROOT/pal/tests/controlsys_flow.pal" scenario_exists transaction_flow
run_test "readme-pal" readme_pal_section
run_test "cmake-pal-target" cmake_has_pal_target
run_test "python-syntax" python_compile_checks

echo "PAL TESTS COMPLETED" | tee -a "$LOG_FILE"
