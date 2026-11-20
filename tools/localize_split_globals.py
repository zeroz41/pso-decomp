#!/usr/bin/env python3
"""localize_split_globals.py — unblock exact units that `link_units.py`
refuses with only `missing <sym>`.

dtk exports every symbol of a split object as a global unless symbols.txt
says `scope:local`. A unit whose source keeps that object anonymous (a pooled
`.rodata` double the compiler names `@123`, a string literal, a `static`
callback) compiles to an object without the global, so the link check refuses
it: another unit might reference it. When no other object does, the global is
an artifact of the split, and marking it `scope:local` removes the refusal
without changing a byte of the DOL.

"No other object" is checked against the undefined symbols of the objects
the link actually uses: the split object (build/<version>/obj) of every unit in
report.json and the compiled object (build/<version>/src) of every unit, since
the following scan may link any exact one.
Stale objects of retired splits in those directories are ignored.

  localize_split_globals.py [UNIT...]          # plan
  localize_split_globals.py --write [UNIT...]  # edit symbols.txt, then rebuild
                                               # and run link_units.py check

UNIT is a unit name as link_units.py prints it (pso/effect/TEffHit.cpp).
Without one, every missing-only unit in linked_units_blocked.json is planned.
Run `link_units.py scan` first: it writes that file.
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import link_units as lu  # noqa: E402

SYMBOLS = lu.SYMBOLS
BLOCKED = lu.CFG_DIR / "linked_units_blocked.json"


def elf_symbols(path: Path) -> tuple[set[str], set[str]]:
    """(defined globals, undefined globals) of a big-endian ELF32 object."""
    b = path.read_bytes()
    if b[:4] != b"\x7fELF":
        return set(), set()
    be = lambda o, n=4: int.from_bytes(b[o:o + n], "big")
    shoff, shentsize, shnum = be(0x20), be(0x2E, 2), be(0x30, 2)
    hdrs = [(be(shoff + i * shentsize + 4), be(shoff + i * shentsize + 16),
             be(shoff + i * shentsize + 20), be(shoff + i * shentsize + 24)) for i in range(shnum)]
    defined, undefined = set(), set()
    for typ, off, size, link in hdrs:
        if typ != 2:
            continue
        _, stroff, strsize, _ = hdrs[link]
        strtab = b[stroff:stroff + strsize]
        for o in range(off + 16, off + size, 16):
            name_off, info, shndx = be(o), b[o + 12], be(o + 14, 2)
            if info >> 4 not in (1, 2):
                continue
            end = strtab.index(b"\0", name_off)
            name = strtab[name_off:end].decode(errors="replace")
            (undefined if shndx == 0 else defined).add(name)
    return defined, undefined


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--write", action="store_true")
    ap.add_argument("units", nargs="*", help="limit to these units")
    ap.add_argument("--version", default="GPOE8P", choices=["GPOE8P", "GPOP8P"],
                    help="game version (default: GPOE8P)")
    args = ap.parse_args()
    global SYMBOLS, BLOCKED
    lu.use_version(args.version)
    SYMBOLS = lu.SYMBOLS
    BLOCKED = lu.CFG_DIR / "linked_units_blocked.json"

    if not BLOCKED.exists():
        sys.exit(f"missing {BLOCKED.relative_to(lu.ROOT)}: run tools/link_units.py scan first")
    blocked = json.loads(BLOCKED.read_text())
    if args.units:
        unknown = [u for u in args.units if u not in blocked]
        if unknown:
            sys.exit("not blocked by link_units.py scan: " + ", ".join(unknown))
        blocked = {u: blocked[u] for u in args.units}
    want: dict[str, str] = {}  # symbol -> unit
    for unit, reasons in blocked.items():
        if reasons and all(r.startswith("missing ") for r in reasons):
            for r in reasons:
                want[r.split(" ", 1)[1]] = unit
    if not want:
        print("no missing-only units")
        return 0

    report = json.loads(lu.REPORT.read_text())
    objs = []
    for u in report["units"]:
        n = lu.unit_name(u)
        stem = n[:-len(Path(n).suffix)] + ".o"
        objs.append(lu.SPLIT_OBJ_DIR / stem)
        # Every unit's compiled object, not only linked ones: the scan that
        # follows can link any exact unit, and its compiled object may name
        # the global through a different relocation than its split object.
        objs.append(lu.OBJ_DIR / stem)
    referenced: dict[str, set[Path]] = {s: set() for s in want}
    for obj in objs:
        if not obj.exists():
            continue
        _, undef = elf_symbols(obj)
        for s in undef & want.keys():
            referenced[s].add(obj)

    def own(obj: Path, unit: str) -> bool:
        stem = unit.rsplit(".", 1)[0]
        return obj.as_posix().endswith("/" + stem + ".o")

    ok_units: dict[str, list[str]] = {}
    bad_units: dict[str, list[str]] = {}
    for s, unit in want.items():
        # The unit's own compiled object counts as a referencer: when its
        # source still says `extern f32 lbl_X;` for a literal the unit now
        # owns, localizing leaves lbl_X undefined at link time (the split
        # object that defined it is no longer linked). Fix that unit's source
        # to define the literal instead.
        others = [o for o in referenced[s] if not (own(o, unit) and o.is_relative_to(lu.SPLIT_OBJ_DIR))]
        (bad_units if others else ok_units).setdefault(unit, []).append(s)
    ok_units = {u: v for u, v in ok_units.items() if u not in bad_units}
    for u, v in sorted(bad_units.items()):
        print(f"keep  {u}: {', '.join(v)} referenced elsewhere")
    syms = {s for v in ok_units.values() for s in v}
    print(f"{len(ok_units)} units / {len(syms)} symbols localizable; {len(bad_units)} units referenced elsewhere")

    if args.write and syms:
        lines = SYMBOLS.read_text().splitlines(keepends=True)
        n = 0
        for i, line in enumerate(lines):
            m = re.match(r"(\S+) = ", line)
            if m and m[1] in syms and "scope:" not in line:
                body, nl = line.rstrip("\n"), "\n" if line.endswith("\n") else ""
                lines[i] = (body + (" scope:local" if "//" in body else " // scope:local")) + nl
                n += 1
            elif m and m[1] in syms and "scope:global" in line:
                lines[i] = line.replace("scope:global", "scope:local")
                n += 1
        SYMBOLS.write_text("".join(lines))
        print(f"marked {n} symbols scope:local in {SYMBOLS.relative_to(lu.ROOT)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
