#!/usr/bin/env python3
"""Check a change before sending it: the checks a pull request has to pass.

On the commit your change starts from:
  python configure.py && ninja && ninja baseline
Then, with your change in place:
  python tools/check_pr.py

It runs, in order:
  1. ninja: rebuilds everything and checks PsoV3.dol against the original's SHA-1.
  2. report_delta.py --check against build/GPOE8P/baseline.json: no match, linked
     function or data range may be lost, compared by original address.
  3. link_units.py check: every unit in linked_units.txt still links from source.
  4. link_units.py scan: lists units that now match completely but are not linked
     yet. That is not a failure; link them with `link_units.py scan --write`.

With --json PATH it also writes the result of each check and the report delta to PATH,
which CI turns into the pull request comment.

The checks are for the USA version (GPOE8P): it stops if the build is configured for another
version, since ninja would build that one while the checks read build/GPOE8P/.
"""
from __future__ import annotations

import argparse
import json
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BASELINE = ROOT / "build/GPOE8P/baseline.json"
REPORT = ROOT / "build/GPOE8P/report.json"


def run(title: str, command: list[str]) -> tuple[bool, str]:
    print(f"== {title}", flush=True)
    result = subprocess.run(command, cwd=ROOT, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    return result.returncode == 0, result.stdout


def configured_version() -> str | None:
    """The --version build.ninja was configured with, or None without a build.ninja."""
    path = ROOT / "build.ninja"
    if not path.exists():
        return None
    for line in path.read_text().splitlines():
        if line.startswith("configure_args ="):
            parser = argparse.ArgumentParser(add_help=False)
            parser.add_argument("-v", "--version", default="GPOE8P")
            return parser.parse_known_args(line.split("=", 1)[1].split())[0].version
    return "GPOE8P"


def check(name: str, ok: bool | None, output: str = "", reason: str = "") -> dict:
    return {"name": name, "ok": ok, "reason": reason, "output": "\n".join(output.strip().splitlines()[-40:])}


def write_json(path: Path | None, checks: list[dict], delta: dict | None) -> None:
    if path is None:
        return
    passed = all(c["ok"] is not False for c in checks)
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps({"result": "pass" if passed else "fail", "checks": checks, "delta": delta}, indent=2))


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--baseline", type=Path, default=BASELINE)
    parser.add_argument("--no-build", action="store_true", help="use the current build instead of running ninja")
    parser.add_argument("--json", type=Path, metavar="PATH", help="also write the results to PATH as JSON")
    args = parser.parse_args()
    if not args.baseline.exists():
        parser.exit(2, f"missing {args.baseline}: run `ninja baseline` on the commit your change starts from\n")

    version = configured_version()
    if version not in (None, "GPOE8P"):
        parser.exit(2, f"build.ninja is configured for {version}: run `python configure.py` (GPOE8P) first\n")

    python = sys.executable
    failed = []
    checks = []
    if not args.no_build:
        ok, out = run("ninja", ["ninja"])
        lines = out.strip().splitlines()
        print("\n".join(lines[-15:] if not ok else [l for l in lines if l.endswith(": OK")]))
        if not ok:
            reason = "the build failed or PsoV3.dol does not match the original"
            print(f"FAIL: {reason}")
            write_json(args.json, [check("build", False, "\n".join(lines[-15:]), reason),
                                   check("report_delta", None), check("link_units", None)], None)
            return 1
        checks.append(check("build", True, "\n".join(l for l in lines if l.endswith(": OK"))))

    ok, out = run("report_delta.py --check", [python, "tools/report_delta.py", str(args.baseline), str(REPORT),
                                               "--check"])
    print(out.rstrip())
    reason = "something that matched, linked or was covered before is lost"
    if not ok:
        failed.append(f"report_delta.py: {reason}")
    checks.append(check("report_delta", ok, out, "" if ok else reason))
    delta = None
    if args.json:
        result = subprocess.run([python, "tools/report_delta.py", str(args.baseline), str(REPORT), "--json"],
                                cwd=ROOT, stdout=subprocess.PIPE, text=True)
        if result.returncode == 0:
            delta = json.loads(result.stdout)

    ok, out = run("link_units.py check", [python, "tools/link_units.py", "check"])
    print(out.rstrip())
    reason = ("a linked unit no longer links from source; "
              "see linked_units_blocked.json after `link_units.py scan`")
    if not ok:
        failed.append(f"link_units.py check: {reason}")
    checks.append(check("link_units", ok, out, "" if ok else reason))

    _, out = run("link_units.py scan", [python, "tools/link_units.py", "scan"])
    print(out.rstrip())
    write_json(args.json, checks, delta)

    if failed:
        for reason in failed:
            print(f"FAIL: {reason}")
        return 1
    print("PASS")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
