#!/usr/bin/env python3
"""Check unit names against the class names the game itself carries.

The disc has no object or source file names for the game code, but most classes carry their own name: the
constructor stores a class-name string in `m_name` (`TObject::m_name = "TObjEneSaver"`). Those strings are the
true names: a unit holding a constructor that stores one, or defining the string itself (the string's data sits in
the unit that compiled it), is named after that class. A name taken from what a
unit does (`ChallengeRank.cpp`) is only a fallback for units no such string names.

    python tools/true_unit_names.py            # units whose name differs from the class names stored in them
    python tools/true_unit_names.py --all      # every unit with a stored class name, named right or not

Each line is one unit: `rename` (one class name, its file is free), `swap` (that file exists and holds other
code), `multi` (several class names, the unit is named after none of them nor after the prefix they share) or
`ok`. A `*Data.cpp` unit holding only a class's data is not renamed: it folds into that class's unit.
"""
from __future__ import annotations

import argparse
import collections
import re
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent   # --root: another checkout
SOURCE = (".c", ".cpp", ".cc", ".cp")

# char NAME[] = "..."; const char *NAME = "..."; const char *Class::NAME = "...";
DEF = re.compile(r'(?:const\s+)?char\s*(?:const\s*)?\*?\s*(?:const\s+)?((?:\w+::)?[A-Za-z_]\w*)\s*(?:\[\w*\])?\s*=\s*"([^"]*)"')
ALIAS = re.compile(r'(?:const\s+)?char\s*(?:const\s*)?\*\s*(?:const\s+)?((?:\w+::)?[A-Za-z_]\w*)\s*=\s*((?:\w+::)?[A-Za-z_]\w*)\s*;')
CTOR = re.compile(r'^\s*([A-Za-z_]\w*)::\1\s*\(', re.M)
MNAME = re.compile(r'\bm_name\s*=\s*([^;]+);')
CLASS = re.compile(r'\b(?:class|struct)\s+([A-Za-z_]\w*)\s*(?:final\s*)?[:{]')


def tracked(*patterns: str) -> list[str]:
    return subprocess.run(["git", "ls-files", *patterns], cwd=ROOT, capture_output=True, text=True,
                          check=True).stdout.split()


def stored_names() -> tuple[dict[str, dict[str, list[int]]], set[str]]:
    """unit -> {class name stored by a constructor in it, or a class-name string defined in it: [lines]}, and
    every declared class."""
    texts = {}
    for rel in tracked("src/*.c", "src/*.cpp", "src/*.cc", "src/*.cp", "include/*.h", "include/*.hpp"):
        try:
            texts[rel] = (ROOT / rel).read_text(errors="replace")
        except OSError:
            pass
    strings: dict[str, set[str]] = collections.defaultdict(set)
    aliases: dict[str, set[str]] = collections.defaultdict(set)
    classes: set[str] = set()
    for text in texts.values():
        for m in DEF.finditer(text):
            strings[m[1]].add(m[2])
        for m in ALIAS.finditer(text):
            aliases[m[1]].add(m[2])
        classes.update(CLASS.findall(text))
    for _ in range(3):
        for name, targets in aliases.items():
            for target in targets:
                strings[name] |= strings.get(target, set())
    out: dict[str, dict[str, list[int]]] = {}
    for rel, text in texts.items():
        if not rel.startswith("src/") or not rel.endswith(SOURCE):
            continue
        local = {m[1]: m[2] for m in DEF.finditer(text)}
        ctors = [(m.start(), m[1]) for m in CTOR.finditer(text)]
        found: dict[str, list[int]] = collections.defaultdict(list)
        for i, (start, cls) in enumerate(ctors):
            end = ctors[i + 1][0] if i + 1 < len(ctors) else len(text)
            for m in MNAME.finditer(text, start, end):
                expr = re.sub(r'^\((?:const\s+)?char\s*\*\)\s*', '', m[1].strip())
                if "::" not in expr and f"{cls}::{expr}" in local.keys() | strings.keys():
                    expr = f"{cls}::{expr}"
                if expr.startswith('"'):
                    values = {expr.strip('"')}
                elif expr in local:
                    values = {local[expr]}
                else:
                    values = strings.get(expr, set())
                for value in values:
                    if re.fullmatch(r"[A-Za-z_]\w*", value):
                        found[value].append(text.count("\n", 0, m.start()) + 1)
        for m in DEF.finditer(text):
            if m[2] in classes and "name" in m[1].lower():
                found[m[2]].append(text.count("\n", 0, m.start()) + 1)
        if found:
            out[rel] = dict(found)
    return out, classes


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    ap.add_argument("--all", action="store_true", help="also list units already named after a stored class name")
    ap.add_argument("--root", type=Path, help="the checkout to check (default: this one)")
    args = ap.parse_args()
    global ROOT
    ROOT = (args.root or ROOT).resolve()
    stored, _ = stored_names()
    units = {rel for rel in tracked("src/*") if rel.endswith(SOURCE)}
    stems = collections.defaultdict(list)
    for rel in units:
        stems[Path(rel).stem].append(rel)
    counts = collections.Counter()
    for rel in sorted(stored):
        names = stored[rel]
        stem = Path(rel).stem
        # a unit named after its class: or after the family its classes share (TOHangceilingCave01Key, ...Normal)
        if stem in names or len(names) > 1 and all(n.startswith(stem) for n in names):
            counts["ok"] += 1
            if args.all:
                print(f"ok      {rel}")
            continue
        if len(names) == 1:
            (name,) = names
            target = str(Path(rel).with_name(name + Path(rel).suffix))
            others = [u for u in stems.get(name, []) if u != rel]
            kind = "swap" if others else "rename"
            print(f"{kind:7} {rel} -> {target}" + (f"  ({', '.join(others)} has that name)" if others else ""))
        else:
            kind = "multi"
            print(f"multi   {rel}: {', '.join(sorted(names))}")
        counts[kind] += 1
    print(f"{sum(counts.values())} units store a class name: " + ", ".join(f"{k} {v}" for k, v in sorted(counts.items())))


if __name__ == "__main__":
    main()
