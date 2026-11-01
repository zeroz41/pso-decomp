#!/usr/bin/env python3
"""Fetch the objdiff report CI already made for a master commit, so nothing rebuilds it.

Usage: python tools/ci_report.py --sha COMMIT --out build/GPOE8P/baseline.json

CI keeps each build's report as the artifact `report-<tree hash>`. A report counts for a
commit only when it was built from that commit's tree by a run that can vouch for it:
  - a successful ci.yml run of the merged pull request's final head (the PR's build of its
    merge commit is master's build when the PR merged with master unchanged), or
  - a successful progress.yml run of that very master commit.
Any other run could name an artifact after the tree, so its report is ignored.

Exits 0 with the report written to --out, or 1 when no trusted report exists.
Needs GITHUB_TOKEN (actions: read) and GITHUB_REPOSITORY; uses only the standard library.
"""

import argparse
import io
import json
import os
import sys
import urllib.error
import urllib.request
import zipfile
from pathlib import Path

API = "https://api.github.com"


class NoRedirect(urllib.request.HTTPRedirectHandler):
    def redirect_request(self, *args, **kwargs):
        return None


def request(url, token, accept="application/vnd.github+json", follow=True):
    headers = {"Accept": accept, "X-GitHub-Api-Version": "2022-11-28", "User-Agent": "pso-decomp-ci"}
    if token:
        headers["Authorization"] = f"Bearer {token}"
    opener = urllib.request.build_opener() if follow else urllib.request.build_opener(NoRedirect)
    try:
        with opener.open(urllib.request.Request(url, headers=headers), timeout=60) as response:
            return response.read()
    except urllib.error.HTTPError as error:
        if not follow and error.code in (301, 302, 303, 307, 308):
            return error.headers["Location"]
        raise


def api(path, token):
    return json.loads(request(f"{API}/{path}", token))


def trusted(run, sha, merged_heads):
    if run.get("conclusion") != "success":
        return False
    if run.get("path") == ".github/workflows/ci.yml":
        return run.get("event") == "pull_request" and run.get("head_sha") in merged_heads
    if run.get("path") == ".github/workflows/progress.yml":
        return (run.get("event") in ("push", "workflow_dispatch") and run.get("head_branch") == "master"
                and run.get("head_sha") == sha)
    return False


def fetch(repo, sha, token):
    """The report.json bytes CI kept for this commit, or None."""
    tree = api(f"repos/{repo}/commits/{sha}", token)["commit"]["tree"]["sha"]
    merged_heads = {pull["head"]["sha"] for pull in api(f"repos/{repo}/commits/{sha}/pulls", token)
                    if pull.get("merged_at")}
    artifacts = api(f"repos/{repo}/actions/artifacts?name=report-{tree}&per_page=100", token)["artifacts"]
    for artifact in artifacts:
        if artifact.get("expired"):
            continue
        run = api(f"repos/{repo}/actions/runs/{artifact['workflow_run']['id']}", token)
        if not trusted(run, sha, merged_heads):
            continue
        # The archive URL redirects to signed storage that must not see our token.
        location = request(f"{API}/repos/{repo}/actions/artifacts/{artifact['id']}/zip", token, follow=False)
        archive = request(location, None, accept="*/*") if isinstance(location, str) else location
        with zipfile.ZipFile(io.BytesIO(archive)) as zipped:
            report = zipped.read("report.json")
        print(f"report for {sha[:10]} (tree {tree[:10]}) from run {run['id']} ({run['path']}, {run['event']})")
        return report
    print(f"no trusted report for {sha[:10]} (tree {tree[:10]})")
    return None


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--sha", required=True, help="master commit")
    parser.add_argument("--out", required=True, type=Path, help="where to write report.json")
    parser.add_argument("--repo", default=os.environ.get("GITHUB_REPOSITORY"))
    args = parser.parse_args()
    if not args.repo:
        parser.error("--repo or GITHUB_REPOSITORY is required")
    try:
        report = fetch(args.repo, args.sha, os.environ.get("GITHUB_TOKEN") or os.environ.get("GH_TOKEN"))
    except (urllib.error.URLError, KeyError, ValueError, zipfile.BadZipFile) as error:
        print(f"could not fetch a report: {error}", file=sys.stderr)
        return 1
    if report is None:
        return 1
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.out.write_bytes(report)
    return 0


if __name__ == "__main__":
    sys.exit(main())
