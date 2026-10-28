#!/usr/bin/env python3
"""Compare objdiff reports by original address, surviving renames and TU merges.

Save report.json before editing, then run:
  python tools/report_delta.py build/before-report.json --check

A data range that leaves coverage only fails the check when it could hold
data. Alignment padding passes: in the original DOL its bytes are zero, no
symbol starts inside it, and it is shorter than the alignment of the address
it ends on (at least 8). Splitting a unit off at an aligned address leaves
such a gap outside every unit. The same padding passes when it was exact or
linked before (a hand-written table that spelled the pad out as a zero entry).
"""
from __future__ import annotations

import argparse
import bisect
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CODE_SECTIONS = {".init", ".text", ".fini"}
DOL_MODULE = "psov3"
DOL_PATH = ROOT / "orig/GPOE8P/files/PsoV3.dol"
SYMBOLS_PATH = ROOT / "config/GPOE8P/psov3/symbols.txt"


def module_name(unit: dict) -> str:
    metadata = unit.get("metadata") or {}
    name = metadata.get("module_name")
    if name:
        return str(name)
    module_id = metadata.get("module_id")
    return f"module:{module_id}" if module_id is not None and int(module_id) else ""


def is_code_section(name: str) -> bool:
    return name in CODE_SECTIONS or name.startswith((".text.", ".init.", ".fini."))


def functions_by_address(report: dict, *, complete_only: bool = False) -> dict:
    functions = {}
    for unit in report.get("units", []):
        if complete_only and not (unit.get("metadata") or {}).get("complete", False):
            continue
        module = module_name(unit)
        for function in unit.get("functions", []):
            address = function.get("metadata", {}).get("virtual_address")
            if address is None:
                raise ValueError(f"No original address for {function['name']}")
            key = (module, int(address))
            if key in functions:
                raise ValueError(f"Duplicate original address: {module}:0x{int(address):08X}")
            functions[key] = function
    return functions


def data_ranges(report: dict, *, exact_only: bool = False,
                complete_only: bool = False) -> dict:
    """Original data intervals, independent of TU names/boundaries.

    complete_only uses objdiff's unit metadata: the build selected the unit's
    compiled object. This is separate from whether its bytes compare exactly.
    """
    ranges = {}
    for unit in report.get('units', []):
        if complete_only and not (unit.get('metadata') or {}).get('complete', False):
            continue
        module = module_name(unit)
        for section in unit.get('sections', []):
            size = int(section.get('size', 0))
            if is_code_section(section['name']) or not size:
                continue
            if exact_only and section.get('fuzzy_match_percent') != 100:
                continue
            address = section.get('metadata', {}).get('virtual_address')
            if address is None:
                raise ValueError(f"No original address for section {unit['name']}:{section['name']}")
            start = int(address)
            ranges.setdefault((module, section['name']), []).append((start, start + size))
    # A split or merge must not look like data loss. Normalize adjacent ranges.
    for key, rows in ranges.items():
        merged = []
        for start, end in sorted(rows):
            if merged and start <= merged[-1][1]:
                merged[-1] = (merged[-1][0], max(end, merged[-1][1]))
            else:
                merged.append((start, end))
        ranges[key] = merged
    return ranges


def exact_data_ranges(report: dict) -> dict:
    """Exact original non-text intervals; retained for existing callers."""
    return data_ranges(report, exact_only=True)


def lost_data_ranges(before: dict, after: dict, *, exact_only: bool = True,
                     complete_only: bool = False) -> list:
    old = data_ranges(before, exact_only=exact_only, complete_only=complete_only)
    new = data_ranges(after, exact_only=exact_only, complete_only=complete_only)
    lost = []
    for (module, section), ranges in sorted(old.items()):
        for start, end in ranges:
            cursor = start
            for first, last in new.get((module, section), []):
                if last <= cursor:
                    continue
                if first >= end:
                    break
                if first > cursor:
                    lost.append((module, section, cursor, first))
                cursor = max(cursor, min(last, end))
            if cursor < end:
                lost.append((module, section, cursor, end))
    return [{'module': module, 'section': section, 'address': f'0x{start:08X}',
             'size': end - start} for module, section, start, end in lost]


def dol_reader(path: Path = DOL_PATH):
    """Return read(address, size) over the original DOL's sections.

    Bytes inside .bss read as zero. Returns None for an address the DOL does
    not map, and the reader itself is None when the DOL is unavailable.
    """
    try:
        dol = path.read_bytes()
    except OSError:
        return None
    word = lambda offset: int.from_bytes(dol[offset:offset + 4], "big")
    segments = [(word(0x48 + 4 * i), word(0x90 + 4 * i), word(4 * i)) for i in range(18)]
    bss = (word(0xD8), word(0xDC))

    def read(address: int, size: int) -> bytes | None:
        for start, length, offset in segments:
            if length and start <= address and address + size <= start + length:
                return dol[offset + address - start:offset + address - start + size]
        if bss[0] <= address and address + size <= bss[0] + bss[1]:
            return bytes(size)
        return None
    return read


def symbol_starts(path: Path = SYMBOLS_PATH) -> dict:
    """{section: sorted symbol addresses} from symbols.txt."""
    starts = {}
    try:
        lines = path.read_text().splitlines()
    except OSError:
        return starts
    for line in lines:
        match = re.match(r"\S+ = (\.\w+):0x([0-9A-Fa-f]+);", line)
        if match:
            starts.setdefault(match[1], []).append(int(match[2], 16))
    for addresses in starts.values():
        addresses.sort()
    return starts


def is_alignment_padding(row: dict, read, starts: dict) -> bool:
    if read is None or row["module"] != DOL_MODULE:
        return False
    start, size = int(row["address"], 16), row["size"]
    end = start + size
    alignment = min(end & -end, 32)
    if alignment < 8 or size >= alignment:
        return False
    addresses = starts.get(row["section"], [])
    first = bisect.bisect_left(addresses, start)
    if first < len(addresses) and addresses[first] < end:
        return False
    data = read(start, size)
    return data is not None and not any(data)


def compare(before: dict, after: dict, read=None, starts=None) -> dict:
    old = functions_by_address(before)
    new = functions_by_address(after)

    def exact(functions):
        return {key for key, f in functions.items() if f.get("fuzzy_match_percent") == 100}

    old_exact, new_exact = exact(old), exact(new)
    old_linked = functions_by_address(before, complete_only=True)
    new_linked = functions_by_address(after, complete_only=True)

    def rows(keys, functions):
        return [{"module": key[0], "address": f"0x{key[1]:08X}",
                 "name": functions[key]["name"]} for key in sorted(keys)]

    metrics = {}
    for key in ("matched_functions", "matched_code", "matched_data", "complete_code", "complete_data",
                "total_functions", "total_code", "total_data"):
        first = int(before.get("measures", {}).get(key, 0))
        last = int(after.get("measures", {}).get(key, 0))
        metrics[key] = {"before": first, "after": last, "delta": last - first}
    failures = []
    data_regressions = lost_data_ranges(before, after)
    data_coverage_lost = lost_data_ranges(before, after, exact_only=False)
    linked_data_lost = lost_data_ranges(before, after, exact_only=False, complete_only=True)
    if data_coverage_lost or data_regressions or linked_data_lost:
        read = read if read is not None else dol_reader()
        starts = starts if starts is not None else symbol_starts()
    padding_lost = [row for row in data_coverage_lost if is_alignment_padding(row, read, starts)]
    data_coverage_lost = [row for row in data_coverage_lost if row not in padding_lost]
    # The same alignment padding may also have been exact or linked before
    # (a data array that spelled the pad out); it leaves those lists too.
    data_regressions = [row for row in data_regressions if not is_alignment_padding(row, read, starts)]
    linked_data_lost = [row for row in linked_data_lost if not is_alignment_padding(row, read, starts)]
    data_coverage_gained = lost_data_ranges(after, before, exact_only=False)
    linked_data_gained = lost_data_ranges(after, before, exact_only=False, complete_only=True)
    if data_regressions:
        failures.append('Previously exact data ranges regressed or disappeared')
    if data_coverage_lost:
        failures.append('Original data addresses disappeared from coverage')
    if old_exact - new_exact:
        failures.append("Previously exact functions regressed or disappeared")
    if old.keys() - new.keys():
        failures.append("Original function addresses disappeared from coverage")
    if old_linked.keys() - new_linked.keys():
        failures.append("Previously linked functions are no longer selected from source")
    if linked_data_lost:
        failures.append("Previously linked data ranges are no longer selected from source")
    padding_bytes = sum(row["size"] for row in padding_lost)
    for key, values in metrics.items():
        delta = values['delta'] + (padding_bytes if key == 'total_data' else 0)
        if key.startswith('total_') and delta != 0:
            failures.append(f"{key} changed by {values['delta']:+d}; reconcile coverage explicitly")
        elif delta < 0:
            failures.append(f"{key} decreased by {-values['delta']}")
    structure = {}
    for label, field in (("source_bearing_units", "source_path"), ("linked_units", "complete")):
        first = sum(bool((u.get("metadata") or {}).get(field)) for u in before.get("units", []))
        last = sum(bool((u.get("metadata") or {}).get(field)) for u in after.get("units", []))
        structure[label] = {"before": first, "after": last, "delta": last - first}
    return {
        "metrics": metrics,
        "new_matches": rows(new_exact - old_exact, new),
        "regressions": rows(old_exact - new_exact, old),
        "data_regressions": data_regressions,
        "data_coverage_lost": data_coverage_lost,
        "padding_coverage_lost": padding_lost,
        "data_coverage_gained": data_coverage_gained,
        "linked_functions_lost": rows(old_linked.keys() - new_linked.keys(), old_linked),
        "linked_functions_gained": rows(new_linked.keys() - old_linked.keys(), new_linked),
        "linked_data_lost": linked_data_lost,
        "linked_data_gained": linked_data_gained,
        "structure": structure,
        "structure_note": "Unit counts and renames describe report structure; they do not prove "
                          "semantic naming or recovery of original translation units.",
        "renamed_functions": [
            {"module": key[0], "address": f"0x{key[1]:08X}",
             "before": old[key]["name"], "after": new[key]["name"]}
            for key in sorted(old.keys() & new.keys()) if old[key]["name"] != new[key]["name"]
        ],
        "missing_functions": rows(old.keys() - new.keys(), old),
        "failures": failures,
    }


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("before", type=Path)
    parser.add_argument("after", nargs="?", type=Path, default=ROOT / "build/GPOE8P/report.json")
    parser.add_argument("--check", action="store_true", help="fail on regression or lost coverage")
    parser.add_argument("--json", action="store_true")
    args = parser.parse_args()
    try:
        delta = compare(json.loads(args.before.read_text()), json.loads(args.after.read_text()))
    except (OSError, ValueError) as error:
        parser.exit(2, f"Cannot compare reports: {error}\n")
    if args.json:
        print(json.dumps(delta, indent=2))
    else:
        for key, values in delta["metrics"].items():
            print(f"{key}: {values['before']} -> {values['after']} ({values['delta']:+d})")
        print(f"New exact functions: {len(delta['new_matches'])}; regressions: {len(delta['regressions'])}")
        for key, values in delta['structure'].items():
            print(f"{key}: {values['before']} -> {values['after']} ({values['delta']:+d})")
        print(f"Renamed functions: {len(delta['renamed_functions'])}. {delta['structure_note']}")
        for row in delta["new_matches"]:
            print(f"  + {row['address']} {row['name']}")
        for failure in delta["failures"]:
            print(f"FAIL: {failure}")
        for row in delta['linked_functions_lost']:
            print(f"  unlinked: {row['module']} {row['address']} {row['name']}")
        for row in delta['data_regressions']:
            print(f"  data: {row['module']} {row['section']} {row['address']} +{row['size']} bytes")
        for key, label in (('data_coverage_lost', 'lost coverage'),
                           ('padding_coverage_lost', 'padding left coverage'),
                           ('data_coverage_gained', 'new coverage'),
                           ('linked_data_lost', 'lost linked data')):
            for row in delta[key]:
                print(f"  {label}: {row['module']} {row['section']} {row['address']} +{row['size']} bytes")
    return 1 if args.check and delta["failures"] else 0


if __name__ == "__main__":
    raise SystemExit(main())
