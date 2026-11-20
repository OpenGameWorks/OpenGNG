#!/usr/bin/env python3
"""Compile daemon: run mwccps2 jobs that sandboxed clients drop into build/ccq/.

Sandboxed sessions (decomp workers) cannot reach the Docker socket, so they
cannot run the Wine compiler themselves. This daemon runs outside the sandbox
and owns the `mwcc` container; clients only exchange files with it:

  client  writes build/ccq/<id>.req   {"cwd": ..., "argv": [...]}  (atomic rename)
  daemon  claims it as build/ccq/<id>.run                          (atomic rename)
  daemon  writes build/ccq/<id>.res   {"rc": int, "out": str}      (atomic rename)

tools/mwcc.py uses the spool automatically while build/ccq/alive is fresh
(the daemon touches it every second), so callers need no configuration.

Usage: PYTHONSAFEPATH=1 ccd.py [--jobs 8] [--container mwcc]

PYTHONSAFEPATH=1 keeps tools/ off sys.path: tools/queue.py shadows the
standard-library queue module that ThreadPoolExecutor imports.
"""

from __future__ import annotations

import argparse
import json
import os
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
Q = ROOT / "build/ccq"


def run(req: Path, container: str) -> None:
    res = req.with_suffix(".res")
    # Claim the request by renaming it: a stale glob listing can submit the same
    # request twice, and only one run may answer, or the loser overwrites the
    # winner's result with a FileNotFoundError.
    claimed = req.with_suffix(".run")
    try:
        req.rename(claimed)
    except FileNotFoundError:
        return
    try:
        job = json.loads(claimed.read_text())
        cwd = Path(job["cwd"]).resolve()
        # Only compile inside the repository: the spool is writable by any local process.
        if not cwd.is_relative_to(ROOT):
            raise ValueError(f"cwd outside repository: {cwd}")
        env = {**os.environ, "MWCC_CONTAINER": container, "MWCC_NO_SPOOL": "1"}
        p = subprocess.run([sys.executable, str(ROOT / "tools/mwcc.py"), *job["argv"]], cwd=cwd, env=env,
                           stdout=subprocess.PIPE, stderr=subprocess.STDOUT, timeout=300)
        doc = {"rc": p.returncode, "out": p.stdout.decode(errors="replace")}
    except Exception as e:  # report every failure to the waiting client instead of dropping it
        doc = {"rc": 1, "out": f"ccd: {type(e).__name__}: {e}\n"}
    tmp = res.with_suffix(".tmp")
    tmp.write_text(json.dumps(doc))
    tmp.rename(res)
    claimed.unlink(missing_ok=True)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--container", default="mwcc")
    a = ap.parse_args()
    Q.mkdir(parents=True, exist_ok=True)
    taken: set[Path] = set()
    print(f"ccd: serving {Q} with {a.jobs} jobs via container {a.container}", flush=True)
    with ThreadPoolExecutor(a.jobs) as pool:
        while True:
            (Q / "alive").touch()
            for req in sorted(Q.glob("*.req")):
                if req not in taken:
                    taken.add(req)
                    pool.submit(run, req, a.container).add_done_callback(lambda _f, r=req: taken.discard(r))
            time.sleep(0.05 if taken else 0.2)


if __name__ == "__main__":
    sys.exit(main())
