#!/usr/bin/env python3
import argparse
import re
from pathlib import Path

parser = argparse.ArgumentParser(description="Validate PAL scenario structure")
parser.add_argument("pal_file")
parser.add_argument("command", choices=["min_sequences", "require_sequences", "scenario_exists"], help="Validation command")
parser.add_argument("args", nargs="*", help="Command arguments")
args = parser.parse_args()

text = Path(args.pal_file).read_text(encoding="utf-8")

assertions = {}
current_assert = None
for line in text.splitlines():
    line_strip = line.strip()
    if line_strip.startswith("assert \""):
        current_assert = re.findall(r'assert\s+"([^"]+)"', line_strip)[0]
        assertions[current_assert] = []
    elif line_strip.startswith("sequence \"") and current_assert:
        seq = re.findall(r'sequence\s+"([^"]+)"', line_strip)[0]
        assertions[current_assert].append(seq)
    elif line_strip == "}" and current_assert and not assertions[current_assert]:
        # closing assert with no sequences (allow) - nothing to do
        continue

all_sequences = sum(len(v) for v in assertions.values())

if args.command == "min_sequences":
    if len(args.args) != 1:
        raise SystemExit("min_sequences requires <number>")
    target = int(args.args[0])
    if all_sequences < target:
        raise SystemExit(f"total sequences {all_sequences} < {target}")
    print(f"Total sequences: {all_sequences} >= {target}")
elif args.command == "scenario_exists":
    if len(args.args) != 1:
        raise SystemExit("scenario_exists requires <name>")
    name = args.args[0]
    if name not in assertions:
        raise SystemExit(f"scenario {name} missing")
    print(f"Scenario {name} present with {len(assertions[name])} sequences")
elif args.command == "require_sequences":
    if len(args.args) < 2:
        raise SystemExit("require_sequences requires <scenario> <seq1> [<seq2>...]")
    name, *seqs = args.args
    if name not in assertions:
        raise SystemExit(f"scenario {name} missing")
    missing = [seq for seq in seqs if seq not in assertions[name]]
    if missing:
        raise SystemExit(f"scenario {name} missing sequences: {', '.join(missing)}")
    print(f"Scenario {name} contains sequences: {', '.join(seqs)}")
