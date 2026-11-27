#!/usr/bin/env python3
"""List switch statements whose case labels are bare numbers.

`case 3:` says nothing about what 3 is: a state, a message, an item kind. Where the executable names the values
(text ids, tables, the code that sends them), an enum says it in the source. This is a report, not part of the
source quality debt (`tools/source_quality.py`): most numbered cases are one class's own state machine with no
evidence for names yet, and a count of every label would outweigh every other check.

    python tools/case_labels.py                # totals, by directory, shared subjects, largest switches
    python tools/case_labels.py --list         # also every switch: path:line, subject, numbered labels
    python tools/case_labels.py --min 1        # count switches with one numbered label or more (default 3)
    python tools/case_labels.py --base master --head my-branch --json out.json   # what a branch changes (CI)

A switch's subject is the last name in what it switches on: `this->state` and `p->state` are `state`, `get_mode()`
is `get_mode`. Shared subjects are those switched on in more than one file. The name alone does not make them one
set of values: `state` is a different state machine in every class, while a `reason` passed to many handlers may
well be one enum. Values from 0 upward with no gaps are mostly state machines; sparse or large ones are more often
ids. Labels that are already names, and character literals, are not counted.
"""
from __future__ import annotations

import argparse
import collections
import json
import re
import sys
from dataclasses import dataclass, field
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from source_quality import SOURCE_ROOTS, SOURCE_SUFFIXES, Repo, blank   # noqa: E402  (tools/, next to this file)

ROOT = Path(__file__).resolve().parent.parent   # --root: another checkout

_SWITCH = re.compile(r"\bswitch\s*\(")
_CASE = re.compile(r"\bcase\b((?:[^:]|::)*?):(?!:)")
_CAST = re.compile(r"\(\s*(?:const\s+)?(?:(?:unsigned|signed)\s+)?[A-Za-z_]\w*(?:\s*\*+)?\s*\)"
                   r"(?=\s*(?:[\w(]|-(?![\s>=-])))")   # `(u8)-1` is a cast, `(x) - 1` and `(p)->f` are not
_NUMBER = re.compile(r"^-?(0[xX][0-9A-Fa-f]+|\d+)[uUlL]*$")


@dataclass
class Switch:
    path: str
    line: int
    subject: str        # the last name in the switched expression
    kind: str           # field, call, name or other
    labels: int         # every case label
    values: list[int]   # the numbered labels' values, sorted
    numbered_lines: list[int] = field(default_factory=list)   # the line of each numbered label

    def on(self, lines: set[int]) -> int:
        """Numbered labels on these lines."""
        return sum(n in lines for n in self.numbered_lines)

    def row(self) -> dict:
        return {"path": self.path, "line": self.line, "subject": self.subject, "kind": self.kind,
                "labels": self.labels, "values": self.values, "shape": self.shape}

    @property
    def shape(self) -> str:
        v = self.values
        if not v:
            return "none"
        if v == list(range(v[0], v[0] + len(v))) and v[0] in (0, 1):
            return "dense"    # 0..N or 1..N: mostly state machines
        return "sparse" if max(abs(n) for n in v) >= 0x40 else "gaps"


def _close(code: str, at: int) -> int:
    """Index of the bracket closing the one at `at` (or the end of the text)."""
    opening = code[at]
    closing = {"(": ")", "{": "}"}[opening]
    depth = 0
    for i in range(at, len(code)):
        if code[i] == opening:
            depth += 1
        elif code[i] == closing:
            depth -= 1
            if depth == 0:
                return i
    return len(code) - 1


def _unwrap(expr: str) -> str:
    expr = expr.strip()
    while expr.startswith("(") and _close(expr, 0) == len(expr) - 1:
        expr = expr[1:-1].strip()
    return expr


def subject(expr: str) -> tuple[str, str]:
    """(kind, name) of a switched expression."""
    e = _unwrap(re.sub(r"\s+", "", _CAST.sub("", expr)))
    call = re.search(r"([A-Za-z_]\w*)\([^()]*\)$", e)
    if call:
        return "call", call[1]
    field = re.search(r"(?:->|\.)([A-Za-z_]\w*)(?:\[[^\]]*\])*$", e)
    if field:
        return "field", field[1]
    name = re.fullmatch(r"(?:\w+::)*([A-Za-z_]\w*)(?:\[[^\]]*\])*", e)
    if name:
        return "name", name[1]
    return "other", e[:40]


def number(label: str) -> int | None:
    """The value of a numbered case label (`3`, `0x1C`, `-1`, `(u8)3`), None for a name or a character literal."""
    text = re.sub(r"\s+", "", _CAST.sub("", label))
    while text.startswith("(") and text.endswith(")"):
        text = text[1:-1]
    match = _NUMBER.match(text)
    if not match:
        return None
    digits = match[1]
    octal = len(digits) > 1 and digits[0] == "0" and digits[1] not in "xX"
    value = int(digits, 8) if octal else int(digits, 0)   # C: a leading 0 is octal
    return -value if text.startswith("-") else value


def switches(rel: str, text: str) -> list[Switch]:
    code = blank(text)
    out = []
    for match in _SWITCH.finditer(code):
        close = _close(code, match.end() - 1)
        brace = code.find("{", close)
        if brace < 0 or code[close + 1:brace].strip():
            continue
        body = code[brace + 1:_close(code, brace)]
        for inner in reversed(list(_SWITCH.finditer(body))):   # a nested switch's labels are its own
            inner_close = _close(body, inner.end() - 1)
            inner_brace = body.find("{", inner_close)
            if inner_brace >= 0 and not body[inner_close + 1:inner_brace].strip():
                end = _close(body, inner_brace)
                body = body[:inner_brace] + " " * (end - inner_brace + 1) + body[end + 1:]
        labels = list(_CASE.finditer(body))
        numbered = [(m, v) for m in labels if (v := number(m[1])) is not None]
        values = sorted({v for _, v in numbered})   # once each: #if/#else repeat labels
        lines = [code.count("\n", 0, brace + 1 + m.start()) + 1 for m, _ in numbered]
        kind, name = subject(code[match.end():close])
        out.append(Switch(rel, code.count("\n", 0, match.start()) + 1, name, kind, len(labels), values, lines))
    return out


def _source(rel: str) -> bool:
    return Path(rel).suffix.lower() in SOURCE_SUFFIXES


def scan(root: Path) -> list[Switch]:
    out = []
    for top in SOURCE_ROOTS:
        for path in sorted((root / top).rglob("*")):
            if _source(path.name) and path.is_file():
                out += switches(path.relative_to(root).as_posix(), path.read_text(errors="replace"))
    return out


def scan_rev(repo: Repo, rev: str) -> list[Switch]:
    out = []
    for rel, text in sorted(repo.files(rev, SOURCE_ROOTS, keep=_source, limit=None)):
        out += switches(rel, text)
    return out


def totals(found: list[Switch], least: int) -> dict:
    counted = [s for s in found if len(s.values) >= least]
    return {"switches": len(found), "labels": sum(s.labels for s in found),
            "numbered": sum(len(s.values) for s in found),
            "counted_switches": len(counted), "counted_labels": sum(len(s.values) for s in counted)}


def compare(repo: Repo, base: str, head: str, least: int) -> dict:
    """Tree totals at base and head, and the new or changed counted switches: those whose set of numbered values the
    tree has more of at head than at base, with a numbered label on a line head adds (a switch that gains or loses
    a label has a new set). A switch that moves to another file or whose subject is renamed keeps its values and
    is not listed."""
    changed, hunks = repo.diff(base, head, SOURCE_ROOTS)
    new_lines = {rel: {n for _, came in hunks.get(rel, []) for n in came} for rel in changed if _source(rel)}
    base_found, head_found = scan_rev(repo, base), scan_rev(repo, head)
    spare = collections.Counter(tuple(s.values) for s in head_found if len(s.values) >= least)
    spare.subtract(tuple(s.values) for s in base_found if len(s.values) >= least)
    listed = []
    for s in head_found:
        key = tuple(s.values)
        if len(s.values) >= least and spare[key] > 0 and s.on(new_lines.get(s.path, set())):
            spare[key] -= 1
            listed.append(s)
    return {"min": least, "head_commit": repo.commit(head),
            "base": totals(base_found, least), "head": totals(head_found, least),
            "new": [{**s.row(), "added": s.on(new_lines[s.path])} for s in listed]}


def _values(values) -> str:
    shown = ", ".join(str(v) if -10 < v < 10 else hex(v) for v in sorted(values)[:12])
    return shown + (", ..." if len(values) > 12 else "")


def main() -> int:
    ap = argparse.ArgumentParser(description=(__doc__ or "").split("\n\n")[0])
    ap.add_argument("--root", type=Path, default=ROOT, help="the checkout to read (default: this one)")
    ap.add_argument("--min", type=int, default=3, help="numbered labels a switch needs to be counted (default 3)")
    ap.add_argument("--top", type=int, default=30, help="rows per section (default 30)")
    ap.add_argument("--list", action="store_true", help="also list every counted switch")
    ap.add_argument("--json", type=Path, metavar="PATH", help="also write every counted switch to PATH as JSON")
    ap.add_argument("--base", help="compare against this revision: totals before and after, and the new or changed "
                                   "switches (written with --json)")
    ap.add_argument("--head", default="HEAD", help="the revision to compare (with --base; default HEAD)")
    ap.add_argument("--git-dir", help="read revisions from this git directory (CI; with --base)")
    args = ap.parse_args()

    if args.base:
        result = compare(Repo(args.git_dir) if args.git_dir else Repo(None), args.base, args.head, args.min)
        before, after = result["base"], result["head"]
        for key, label in (("numbered", "numbered labels"), ("counted_switches", f"switches with {args.min}+"),
                           ("counted_labels", f"labels in switches with {args.min}+")):
            print(f"{label}: {before[key]:,} -> {after[key]:,}")
        print(f"{len(result['new']):,} new or changed switches with {args.min}+ numbered labels")
        for s in result["new"]:
            print(f"  {s['path']}:{s['line']}  {s['subject']}  {s['added']} added")
        if args.json:
            args.json.parent.mkdir(parents=True, exist_ok=True)
            args.json.write_text(json.dumps(result, indent=1) + "\n")
        return 0

    found = scan(args.root)
    counted = [s for s in found if len(s.values) >= args.min]
    labels = sum(len(s.values) for s in counted)
    print(f"{len(found):,} switches, {sum(s.labels for s in found):,} case labels, "
          f"{sum(len(s.values) for s in found):,} numbered")
    print(f"{len(counted):,} switches with {args.min} or more numbered labels: {labels:,} labels")
    shapes = collections.Counter()
    for s in counted:
        shapes[s.shape] += len(s.values)
    print(f"  values 0..N or 1..N {shapes['dense']:,}, small with gaps {shapes['gaps']:,}, "
          f"sparse or 0x40 and up {shapes['sparse']:,}")

    by_dir = collections.Counter()
    for s in counted:
        by_dir["/".join(s.path.split("/")[:3])] += len(s.values)
    print("\nBy directory:")
    for where, n in by_dir.most_common(args.top):
        print(f"  {n:>7,}  {where}")

    shared = collections.defaultdict(list)
    for s in counted:
        if s.kind != "other":
            shared[s.subject].append(s)
    shared = {k: v for k, v in shared.items() if len({s.path for s in v}) > 1}
    print(f"\nShared subjects ({len(shared):,}): switches, numbered labels, files, values")
    for name, group in sorted(shared.items(), key=lambda kv: -sum(len(s.values) for s in kv[1]))[:args.top]:
        values = {v for s in group for v in s.values}
        print(f"  {name:<32} {len(group):>5} {sum(len(s.values) for s in group):>6} "
              f"{len({s.path for s in group}):>5}  {_values(values)}")

    print("\nLargest switches:")
    for s in sorted(counted, key=lambda s: -len(s.values))[:args.top]:
        print(f"  {len(s.values):>4}  {s.path}:{s.line}  {s.subject} ({s.shape})")

    if args.list:
        print("\nEvery switch:")
        for s in counted:
            print(f"  {s.path}:{s.line}  {s.subject}  {len(s.values)}/{s.labels}  {_values(s.values)}")
    if args.json:
        args.json.parent.mkdir(parents=True, exist_ok=True)
        args.json.write_text(json.dumps([s.row() for s in counted], indent=1) + "\n")
    return 0


if __name__ == "__main__":
    sys.exit(main())
