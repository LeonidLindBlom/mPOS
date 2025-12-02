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
LOG_FILE="$LOG_DIR/pal-negative-tests.log"
: > "$LOG_FILE"

run_test() {
    local name="$1"
    shift
    local start_ns end_ns duration
    start_ns=$(date +%s%N)
    printf "RUN  %s\n" "$name" | tee -a "$LOG_FILE"
    if "$@" >>"$LOG_FILE" 2>&1; then
        end_ns=$(date +%s%N)
        duration=$(((end_ns - start_ns)/1000000))
        printf "OK   %s (%s ms)\n" "$name" "$duration" | tee -a "$LOG_FILE"
    else
        printf "FAIL %s\n" "$name" | tee -a "$LOG_FILE"
        echo "See $LOG_FILE for details" >&2
        exit 1
    fi
}

pal_negative_file_exists() {
    [[ -f "$ROOT/pal/tests/controlsys_negative.pal" ]]
}

test_binary_exists() {
    [[ -x "$BUILD_DIR/controlsys/ControlSys" ]]
}

run_test "controlsys-binary" test_binary_exists
run_test "pal-negative-file" pal_negative_file_exists
run_test "pal-negative-min-seq" python3 "$ROOT/tools/verify_pal_structure.py" "$ROOT/pal/tests/controlsys_negative.pal" min_sequences 12
run_test "pal-negative-unsigned" python3 "$ROOT/tools/verify_pal_structure.py" "$ROOT/pal/tests/controlsys_negative.pal" scenario_exists negative_unsigned_transaction
run_test "pal-negative-journal" python3 "$ROOT/tools/verify_pal_structure.py" "$ROOT/pal/tests/controlsys_negative.pal" scenario_exists negative_journal_loss
run_test "pal-negative-update" python3 "$ROOT/tools/verify_pal_structure.py" "$ROOT/pal/tests/controlsys_negative.pal" scenario_exists negative_corrupted_update
run_test "pal-negative-card" python3 "$ROOT/tools/verify_pal_structure.py" "$ROOT/pal/tests/controlsys_negative.pal" scenario_exists negative_card_data_corruption
run_test "pal-negative-replay" python3 "$ROOT/tools/verify_pal_structure.py" "$ROOT/pal/tests/controlsys_negative.pal" scenario_exists negative_replayed_bank_response
run_test "pal-negative-receipt" python3 "$ROOT/tools/verify_pal_structure.py" "$ROOT/pal/tests/controlsys_negative.pal" scenario_exists negative_receipt_without_journal
run_test "pal-negative-power" python3 "$ROOT/tools/verify_pal_structure.py" "$ROOT/pal/tests/controlsys_negative.pal" scenario_exists negative_power_drop_before_card
run_test "pal-negative-third-party" python3 "$ROOT/tools/verify_pal_structure.py" "$ROOT/pal/tests/controlsys_negative.pal" scenario_exists negative_third_party_app
run_test "pal-negative-low-battery" python3 "$ROOT/tools/verify_pal_structure.py" "$ROOT/pal/tests/controlsys_negative.pal" scenario_exists negative_update_low_battery

run_test "pal-negative-unsigned-seq" python3 "$ROOT/tools/verify_pal_structure.py" "$ROOT/pal/tests/controlsys_negative.pal" require_sequences negative_unsigned_transaction ui-bypass-attempt manager-rejects-unsigned
run_test "pal-negative-update-seq" python3 "$ROOT/tools/verify_pal_structure.py" "$ROOT/pal/tests/controlsys_negative.pal" require_sequences negative_corrupted_update corrupted-image verifier-fails
run_test "pal-negative-low-battery-seq" python3 "$ROOT/tools/verify_pal_structure.py" "$ROOT/pal/tests/controlsys_negative.pal" require_sequences negative_update_low_battery battery-warning install-aborted

run_test "pal-negative-python" python3 -m py_compile "$ROOT"/tools/verify_pal_structure.py

echo "PAL NEGATIVE TESTS COMPLETED" | tee -a "$LOG_FILE"
