#!/usr/bin/env python3
"""Rebuild the functions Nintendo and Metrowerks wrote in assembly, from your copy of the game.

Source files keep those functions' signatures, with a body of
    #include "orig_asm/<unit>/<function>.inc"
This tool writes each of those files from decomp-toolkit's disassembly of the original
(build/<version>/asm/<unit>.s). Instructions become raw words; only an instruction that
needs a relocation is written out, so the compiler can emit the relocation. Labels the
original placed at a function's start or end become entry points of that function.

A unit that is assembly from start to finish (MetroTRK's vector table and file stubs)
is written whole, as .../orig_asm/<unit>.s.

Usage: python tools/orig_asm.py build/<version>/asm config/<version>/symbols.txt OUTPUT [...]
where each OUTPUT is .../orig_asm/<unit>/<function>.inc or .../orig_asm/<unit>.s
"""

import re
import sys
from pathlib import Path

FN = re.compile(r"\.fn (\S+), \w+$")
SYM = re.compile(r"\.sym (\S+), \w+$")
WHERE = re.compile(r"# \.\w+:0x[0-9A-Fa-f]+ \| 0x([0-9A-Fa-f]+) \| size: 0x([0-9A-Fa-f]+)")
LABEL = re.compile(r"\.L_[0-9A-Fa-f]+:$")
INSN = re.compile(r"^/\*\s*[0-9A-F]{8}\s+[0-9A-F]{8}\s+((?:[0-9A-F]{2} ){3}[0-9A-F]{2})\s*\*/\s*(.*)$")
BRANCH = re.compile(r"^b\w*\s+(?:(?:cr\d|\d)\s*,\s*)?([A-Za-z_.@$][\w.@$]*)$")
SDA21 = re.compile(r"([A-Za-z_$][\w$]*)@sda21\((r\d+)\)")


def encode(line: str) -> str:
    m = INSN.match(line)
    if not m:
        raise ValueError(f"no instruction encoding in {line!r}")
    word, text = m.group(1).replace(" ", ""), m.group(2).strip()
    branch = BRANCH.match(text)
    if "@" in text or (branch and not branch.group(1).startswith(".L_")):
        # CodeWarrior writes a small-data reference as sym(rN), not sym@sda21(rN).
        return SDA21.sub(r"\1(\2)", text)
    return f"opword 0x{word}"


def outside_branch(line: str, fn: dict):
    """The unnamed label a branch targets in another function, if it does."""
    m = INSN.match(line)
    branch = m and BRANCH.match(m.group(2).strip())
    if branch and branch.group(1).startswith(".L_"):
        target = int(branch.group(1)[3:], 16)
        if not fn["start"] <= target < fn["end"]:
            return branch.group(1)
    return None


def parse(asm: str) -> list:
    """The unit as ordered items: functions with their bodies, and labels between them."""
    items, fn, where = [], None, None
    for line in asm.splitlines():
        s = line.strip()
        w = WHERE.match(s)
        if w:
            where = (int(w.group(1), 16), int(w.group(2), 16))
            continue
        m = FN.match(s)
        if m:
            fn = {"kind": "fn", "name": m.group(1), "start": where[0], "end": where[0] + where[1],
                  "body": [], "error": None}
            items.append(fn)
            continue
        if fn is None:
            m = SYM.match(s)
            if m:
                items.append({"kind": "sym", "name": m.group(1), "addr": where[0]})
            continue
        if s == f".endfn {fn['name']}":
            fn = None
        elif fn["error"] or not s or s.startswith("#") or LABEL.match(s) or s.startswith(".hidden "):
            continue
        elif SYM.match(s):
            fn["body"].append(f"entry {SYM.match(s).group(1)}")
        elif s.startswith("."):
            fn["error"] = f"unexpected directive {s!r}"
        elif outside_branch(s, fn):
            # As a raw word the branch would lose its relocation, which the original has.
            fn["error"] = (f"branch to {outside_branch(s, fn)} outside the function: "
                           "name that address as a label in symbols.txt")
        else:
            try:
                fn["body"].append(encode(s))
            except ValueError as error:
                fn["error"] = str(error)
    return items


def bodies(asm: str, wanted: set) -> dict:
    """Inline-assembler bodies of the wanted functions, labels at their edges included."""
    items = parse(asm)
    lead, trail = {}, {}
    for i, item in enumerate(items):
        if item["kind"] != "sym":
            continue
        prev = next((x for x in reversed(items[:i]) if x["kind"] == "fn"), None)
        nxt = next((x for x in items[i + 1:] if x["kind"] == "fn"), None)
        if nxt and nxt["name"] in wanted and item["addr"] == nxt["start"]:
            lead.setdefault(nxt["name"], []).append(f"entry {item['name']}")
        elif prev and prev["name"] in wanted and item["addr"] == prev["end"]:
            trail.setdefault(prev["name"], []).append(f"entry {item['name']}")
    out = {}
    for item in items:
        if item["kind"] == "fn" and item["name"] in wanted:
            out[item["name"]] = item["error"] or (
                ["nofralloc", *lead.get(item["name"], []), *item["body"], *trail.get(item["name"], [])])
    return out


def write(out: Path, text: str) -> None:
    out.parent.mkdir(parents=True, exist_ok=True)
    if not out.exists() or out.read_text(encoding="utf-8") != text:
        out.write_text(text, encoding="utf-8")


def whole_unit(asm: str, symbols: str) -> str:
    """A unit written entirely in assembly, with the labels that close it.

    decomp-toolkit leaves out labels at the very end of a unit, such as the end
    marker of a table, so they are added from the symbols file.
    """
    head = re.search(r"^# 0x([0-9A-Fa-f]+)\.\.0x([0-9A-Fa-f]+) \| size: 0x[0-9A-Fa-f]+\n(?:\.section (\S+?),|(\.\w+)$)", asm, re.M)
    if not head:
        raise SystemExit("unit has no section header")
    end, section = int(head.group(2), 16), head.group(3) or head.group(4)
    labels = re.findall(rf"^(\S+) = {re.escape(section)}:0x([0-9A-Fa-f]+); // type:label scope:global", symbols, re.M)
    extra = [name for name, addr in labels if int(addr, 16) == end and f".sym {name}," not in asm]
    return asm.rstrip("\n") + "\n" + "".join(f".sym {name}, global\n" for name in extra)


def main(argv) -> int:
    if len(argv) < 3:
        print(__doc__.strip(), file=sys.stderr)
        return 2
    asm_dir, symbols, outputs = Path(argv[0]), Path(argv[1]), [Path(p) for p in argv[2:]]
    by_unit = {}
    for out in outputs:
        parts = out.parts
        if out.suffix == ".s":
            unit = "/".join(parts[parts.index("orig_asm") + 1:])[:-2]
            write(out, whole_unit((asm_dir / f"{unit}.s").read_text(encoding="utf-8"),
                                  symbols.read_text(encoding="utf-8")))
            continue
        unit = "/".join(parts[parts.index("orig_asm") + 1:-1])
        by_unit.setdefault(unit, []).append(out)
    for unit, outs in by_unit.items():
        found = bodies((asm_dir / f"{unit}.s").read_text(encoding="utf-8"), {o.stem for o in outs})
        for out in outs:
            body = found.get(out.stem)
            if body is None:
                raise SystemExit(f"{out.stem} is not in {asm_dir / unit}.s")
            if isinstance(body, str):
                raise SystemExit(f"{asm_dir / unit}.s: {out.stem}: {body}")
            write(out, "\n".join(body) + "\n")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
