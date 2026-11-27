#!/usr/bin/env python3
"""On-disk job queue for decomp workers; keeps the coordinator's context small.

A job is one game source file plus up to MAXF of its unclaimed functions
(mid-sized first, at most MAXB bytes; functions of TRIVIAL bytes or less stay with the coordinator). A file has at most one active job, so
a worker owns `src/game/<File>.cpp` and `<File>.h` exclusively.

Usage:
  queue.py take N        start N jobs; print one JSON job per line
  queue.py done ID       retire a job (its results stay in build/results/ID.tsv)
  queue.py active        print active jobs
State: build/queue/active.json (served to the live page as /workers.json).
"""

from __future__ import annotations

import json
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import claimed  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
Q = ROOT / "build/queue"
ACTIVE = Q / "active.json"
RESULTS = ROOT / "build/results"
MAXF, MAXB = 5, 0x600
# Functions of TRIVIAL bytes or less (empty bodies, one-load getters) are left out of
# worker jobs, since the coordinator writes them faster; mid-sized functions give the most matched
# bytes per worker token.
TRIVIAL = 0x10
SWEET = (0x20, 0x200)


def load_active() -> list[dict]:
    return json.loads(ACTIVE.read_text())["workers"] if ACTIVE.exists() else []


def save_active(ws: list[dict]) -> None:
    Q.mkdir(parents=True, exist_ok=True)
    tmp = ACTIVE.with_suffix(".tmp")
    tmp.write_text(json.dumps({"workers": ws}, indent=1))
    tmp.rename(ACTIVE)


def tried() -> set[int]:
    """Addresses a finished job already reported as DRAFT or SKIP; not re-queued automatically."""
    out = set()
    for f in RESULTS.glob("*.tsv"):
        for l in f.read_text().splitlines():
            p = l.split("\t")
            if len(p) > 1 and p[1] in ("DRAFT", "SKIP"):
                out.add(int(p[0], 16))
    return out


def candidates() -> dict[str, list[tuple[int, int, str]]]:
    files: dict[str, list] = {}
    tus = [l.split("\t") for l in (ROOT / "config/tus.tsv").read_text().splitlines()[1:]]
    tus = [(int(t[0], 16), int(t[1], 16), t[2], t[3]) for t in tus]
    taken = set(claimed.claims()) | tried()
    for l in (ROOT / "config/units.tsv").read_text().splitlines()[1:]:
        a, b, k, n = l.split("\t")
        a, b = int(a, 16), int(b, 16)
        if k != "func" or a in taken or b - a <= TRIVIAL:
            continue
        tu = next((t for t in tus if t[0] <= a < t[1]), None)
        if tu and tu[2] == "game" and not tu[3].startswith("unk_"):
            files.setdefault(tu[3], []).append((a, b - a, n))
    return files


def take(n: int) -> list[dict]:
    act = load_active()
    busy = {Path(j["file"]).name for j in act}  # candidates() keys are bare file names
    cands = candidates()
    # Files with the most small functions first: the highest matched bytes per worker-hour.
    sweet = lambda s: SWEET[0] <= s <= SWEET[1]
    order = sorted(cands, key=lambda f: -sum(s for _, s, _ in cands[f] if sweet(s)))
    jobs = []
    for f in order:
        if len(jobs) >= n:
            break
        if f in busy:
            continue
        pick, total = [], 0
        for a, s, nm in sorted(cands[f], key=lambda x: (not sweet(x[1]), x[1])):
            if len(pick) < MAXF and total + s <= MAXB:
                pick.append((a, s, nm))
                total += s
        if not pick:
            # Every function left in this file exceeds the byte budget; the smallest
            # becomes a single-function job so large code still reaches a worker.
            a, s, nm = min(cands[f], key=lambda x: x[1])
            pick = [(a, s, nm)]
        stem = Path(f).stem
        jid = f"{stem}-{int(time.time()) % 100000}"
        jobs.append({"id": jid, "file": f"src/game/{f}", "header": f"src/game/{stem}.h",
                     "funcs": " ".join(f"0x{a:08X}" for a, _, _ in sorted(pick)),
                     "names": [f"0x{a:08X} {nm} size 0x{s:X}" for a, s, nm in sorted(pick)],
                     "started": time.time()})
    save_active(act + jobs)
    return jobs


def main() -> int:
    cmd = sys.argv[1] if len(sys.argv) > 1 else "active"
    if cmd == "take":
        for j in take(int(sys.argv[2])):
            print(json.dumps(j))
    elif cmd == "done":
        save_active([j for j in load_active() if j["id"] not in sys.argv[2:]])
    else:
        for j in load_active():
            print(json.dumps(j))
    return 0


if __name__ == "__main__":
    sys.exit(main())
