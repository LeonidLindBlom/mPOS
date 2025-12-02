#!/usr/bin/env python3
import sys
from pathlib import Path

if len(sys.argv) != 2:
    print("usage: verify_docs_anchor.py <architecture.md>", file=sys.stderr)
    sys.exit(2)

text = Path(sys.argv[1]).read_text(encoding='utf-8')
checks = [
    "Домены безопасности ControlSys",
    "Сценарии из диаграмм",
    "Тестирование сквозных сценариев",
]

for needle in checks:
    if needle not in text:
        raise SystemExit(f"missing section marker: {needle}")
    print(f"found marker: {needle}")

sys.exit(0)
