#!/usr/bin/env python3
import re
import sys
from pathlib import Path

if len(sys.argv) != 2:
    print("usage: verify_event_scripts.py <event_script.c>", file=sys.stderr)
    sys.exit(2)

text = Path(sys.argv[1]).read_text(encoding='utf-8')

requirements = {
    "kTransactionScript": ["CTL_EVENT_HEARTBEAT", "CTL_EVENT_SET_AMOUNT", "CTL_EVENT_CARD_DATA", "CTL_EVENT_BANK_RESPONSE"],
    "kUpdateScript": ["CTL_EVENT_UPDATE_REQUEST", "CTL_EVENT_UPDATE_PAYLOAD", "CTL_EVENT_UPDATE_INSTALL"],
    "kLogExportScript": ["CTL_EVENT_LOG_EXPORT_REQUEST", "CTL_EVENT_LOG_EXPORT_DATA", "CTL_EVENT_LOG_EXPORT_COMPLETE"],
}

for name, tokens in requirements.items():
    anchor = f"static const CtlEvent {name}"
    start = text.find(anchor)
    if start == -1:
        raise SystemExit(f"missing array: {name}")
    end = text.find("};", start)
    if end == -1:
        raise SystemExit(f"unterminated array: {name}")
    block = text[start:end]
    for token in tokens:
        if token not in block:
            raise SystemExit(f"array {name} missing token {token}")
    count = len(re.findall(r"CTL_EVENT_", block))
    if count < len(tokens):
        raise SystemExit(f"array {name} too short ({count})")
    print(f"{name}: {count} events validated")

sys.exit(0)
