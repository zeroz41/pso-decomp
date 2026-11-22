#!/usr/bin/env python3
"""Render the pull request comment from `check_pr.py --json` output.

    python tools/ci_comment.py result.json --sha <commit> --run-url <url> [--quality quality.json]

A missing or unreadable result file renders as a failure that ran no checks, which is
what a CI run that stopped before the gate looks like. The input is produced by the
pull request's own code, so every value is checked and escaped here before it reaches
the comment.
"""
from __future__ import annotations

import argparse
import json
import re
import urllib.parse
from pathlib import Path

MARKER = "<!-- pso-ci -->"
PASS, FAIL, SKIP = "✅", "❌", "➖"

CHECKS = {
    "build": "Build + DOL SHA-1",
    "report_delta": "No regressions (`report_delta --check`)",
    "link_units": "Linked units still link",
}
METRICS = [
    ("metrics", "matched_data", "Matched data (bytes)"),
    ("metrics", "complete_data", "Complete data (bytes)"),
    ("metrics", "matched_code", "Matched code (bytes)"),
    ("metrics", "complete_code", "Complete code (bytes)"),
    ("metrics", "matched_functions", "Matched functions"),
    ("structure", "linked_units", "Linked units"),
]


def text(value: object, limit: int = 300) -> str:
    """One line of untrusted text, safe inside a table cell."""
    value = re.sub(r"\s+", " ", str(value))[:limit]
    value = value.replace("&", "&amp;").replace("@", "@​").replace("|", "\\|").replace("<", "&lt;").replace(">", "&gt;")
    return value


def block(value: object, limit: int = 6000) -> str:
    """Untrusted multi-line text, safe inside a fenced code block."""
    return str(value)[-limit:].replace("`", "ˋ").replace("@", "@​")


def number(value: object) -> int | None:
    return value if isinstance(value, int) and not isinstance(value, bool) else None


def delta_cell(value: int) -> str:
    return f"**{value:+,}**" if value else "0"


def code(value: object, limit: int = 120) -> str:
    """Untrusted text as an inline code span, safe inside a table cell."""
    value = re.sub(r"\s+", " ", str(value))[:limit].replace("`", "ˋ").replace("|", "\\|").strip()
    return f"`{value}`" if value else ""


def signed(value: int) -> str:
    return f"**{value:+,}**".replace("-", "−") if value else "0"


QUALITY_DOC = "CONTRIBUTING.md#source-quality"
QUALITY_ROWS = 30   # findings and renames listed in the comment; the run log has the rest


def counts(row: object, *keys: str) -> tuple[int, ...] | None:
    values = tuple(number(row.get(k)) for k in keys) if isinstance(row, dict) else (None,)
    return None if None in values else values


def listed(value: dict, key: str) -> list[dict]:
    items = value.get(key)
    return [item for item in items if isinstance(item, dict)] if isinstance(items, list) else []


def render_quality(quality: dict | None, repo: str) -> list[str]:
    """The advisory source quality section, from `source_quality.py --json` (run by master's copy of the
    script over the pull request's merge commit, whose text is untrusted)."""
    lines = ["", "#### Source quality · advisory"]
    total = counts((quality or {}).get("total"), "base", "head", "added", "removed")
    if total is None:
        return lines + ["", "Not measured for this run (see the run log). Check locally with "
                        "`python tools/source_quality.py`."]
    owned = counts(quality.get("ownership_total"), "base", "head", "added", "removed") or (0, 0, 0, 0)
    head = quality.get("head_commit")
    head = head if isinstance(head, str) and re.fullmatch(r"[0-9a-f]{40}", head) else ""

    def where(path: object, line: object) -> str:
        spot = f"{path}:{line}" if number(line) else str(path)
        if repo and head and number(line) and isinstance(path, str):
            return f"[{code(spot)}](https://github.com/{repo}/blob/{head}/{urllib.parse.quote(path)}#L{line})"
        return code(spot)

    base, after, added, removed = total
    lines += ["", f"Net debt {signed(after - base)} (removed {removed:,}, added {added:,}; tree {base:,} → {after:,}). "
              f"Members in the wrong class {signed(owned[1] - owned[0])} (removed {owned[3]:,}, added {owned[2]:,})."]
    rows = []
    for row in listed(quality, "categories"):
        values = counts(row, "base", "head", "added", "removed")
        if values and (values[2] or values[3] or values[0] != values[1]):
            rows.append(f"| {text(row.get('label'), 90)} | {values[3]:,} | {values[2]:,} | {signed(values[1] - values[0])} |")
    if rows:
        lines += ["", "| Check | Removed | Added | Net |", "|---|---:|---:|---:|"] + rows

    new = listed(quality, "new")
    if new:
        lines += ["", f"<details><summary>{len(new):,} new finding{'s' * (len(new) != 1)} on lines this pull request "
                  "adds</summary>", "", "| Where | Check | Text |", "|---|---|---|"]
        lines += [f"| {where(f.get('path'), f.get('line'))} | {text(f.get('key'), 40)} | {code(f.get('text'))} |"
                  for f in new[:QUALITY_ROWS]]
        if len(new) > QUALITY_ROWS:
            lines.append(f"| … {len(new) - QUALITY_ROWS:,} more in the run log | | |")
        lines.append("</details>")

    renames = listed(quality, "renames")
    flagged = [r for r in renames if r.get("flags")]
    if renames:
        shown = (flagged or renames)[:QUALITY_ROWS]
        lines += ["", f"<details><summary>{len(renames):,} renamed symbol{'s' * (len(renames) != 1)}, "
                  f"{len(flagged):,} flagged</summary>", "", "| Address | Old | New | Note |", "|---|---|---|---|"]
        lines += [f"| {code(r.get('address'), 12)} | {code(r.get('old'))} | {code(r.get('new'))} | "
                  f"{text('; '.join(str(x) for x in r.get('flags') or []), 200)} |" for r in shown]
        rest = len(flagged or renames) - len(shown)
        if rest > 0:
            lines.append(f"| … {rest:,} more in the run log | | | |")
        lines.append("</details>")

    for key, one, many in (("added_symbols", "new symbol with a flat or placeholder name",
                            "new symbols with a flat or placeholder name"),
                           ("stale_force_active", "`force_active` entry left naming no symbol",
                            "`force_active` entries left naming no symbol")):
        items = listed(quality, key)
        if items:
            names = ", ".join(code(r.get("name"), 80) for r in items[:QUALITY_ROWS])
            more = f", … {len(items) - QUALITY_ROWS:,} more" if len(items) > QUALITY_ROWS else ""
            lines += ["", f"{len(items):,} {one if len(items) == 1 else many}: {names}{more}"]

    doc = f"https://github.com/{repo}/blob/master/{QUALITY_DOC}" if repo else QUALITY_DOC
    lines += ["", f"What each check means and how to fix it: [CONTRIBUTING.md, Source quality]({doc}). "
              "Run `python tools/source_quality.py` before pushing to see the same report."]
    return lines


def render(result: dict | None, sha: str, run_url: str, quality: dict | None = None,
           measured: bool = False, repo: str = "") -> str:
    checks = {c.get("name"): c for c in (result or {}).get("checks", []) if isinstance(c, dict)}
    passed = isinstance(result, dict) and result.get("result") == "pass" and checks.get("build", {}).get("ok") is True
    sha = re.sub(r"[^0-9a-f]", "", sha)[:10]
    lines = [MARKER, f"### {PASS if passed else FAIL} CI {'passed' if passed else 'failed'}"
             + (f" · `{sha}`" if sha else "") + (f" · [run]({run_url})" if run_url else ""), ""]
    quality_lines = render_quality(quality, repo) if measured else []
    if result is None:
        lines.append("The run stopped before the gate wrote its results; see the run log.")
        return "\n".join(lines + quality_lines) + "\n"

    lines += ["| Check | Result |", "|---|:---:|"]
    for name, label in CHECKS.items():
        c = checks.get(name, {})
        ok = c.get("ok")
        mark = PASS if ok is True else FAIL if ok is False else SKIP
        reason = f" {text(c['reason'])}" if ok is False and c.get("reason") else ""
        lines.append(f"| {label} | {mark}{reason} |")

    delta = result.get("delta")
    if isinstance(delta, dict):
        rows = []
        for group, key, label in METRICS:
            row = (delta.get(group) or {}).get(key) or {}
            before, after, change = (number(row.get(k)) for k in ("before", "after", "delta"))
            if None not in (before, after, change):
                rows.append(f"| {label} | {before:,} | {after:,} | {delta_cell(change)} |")
        if rows:
            lines += ["", "| Metric | Base | PR | Δ |", "|---|---:|---:|---:|"] + rows
        counts = []
        for key, label in (("new_matches", "new exact functions"), ("regressions", "function regressions"),
                           ("renamed_functions", "renamed functions")):
            if isinstance(delta.get(key), list):
                counts.append(f"{len(delta[key])} {label}")
        if counts:
            lines += ["", ", ".join(counts).capitalize() + "."]
        failures = delta.get("failures")
        if isinstance(failures, list) and failures:
            lines += [""] + [f"- {FAIL} {text(f)}" for f in failures[:20]]

    failed = [c for c in checks.values() if c.get("ok") is False and c.get("output")]
    for c in failed:
        lines += ["", f"<details><summary>{text(CHECKS.get(c.get('name'), c.get('name'))).replace('`', '')} output</summary>", "",
                  "```", block(c["output"]), "```", "</details>"]
    return "\n".join(lines + quality_lines) + "\n"


def load(path: Path) -> dict | None:
    try:
        value = json.loads(path.read_text())
    except (OSError, ValueError):
        return None
    return value if isinstance(value, dict) else None


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("result", type=Path)
    parser.add_argument("--sha", default="")
    parser.add_argument("--run-url", default="")
    parser.add_argument("--quality", type=Path, help="source_quality.py --json output (missing: not measured)")
    args = parser.parse_args()
    result, quality = load(args.result), load(args.quality) if args.quality else None
    found = re.fullmatch(r"https://github\.com/([\w.-]+/[\w.-]+)/actions/runs/\d+(/attempts/\d+)?", args.run_url)
    run_url, repo = (args.run_url, found[1]) if found else ("", "")
    print(render(result, args.sha, run_url, quality, measured=args.quality is not None, repo=repo), end="")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
