#!/usr/bin/env python3
"""Start one draft-matching job: the idle file holding the most low-diff drafts.

Drafts come from build/slices/drafts_known.tsv (tools/draftscan.py). A draft
counts only while its source tag is still DRAFT, is at most MAXBYTES long
(larger functions are split or go to a Sonnet task), and has not already been
left as DRAFT by an earlier draft job; those go to tools/permute.py instead.

Usage: takedraft.py [MAXDIFF] [MAXBYTES]
Prints one JSON job and records it in build/queue/active.json.
"""

from __future__ import annotations

import json
import re
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import queue as q  # noqa: E402  (tools/queue.py, the on-disk job queue)

ROOT = Path(__file__).resolve().parent.parent
PER_JOB = 4


def main() -> int:
    maxd = int(sys.argv[1]) if len(sys.argv) > 1 else 20
    maxb = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x400
    act = q.load_active()
    busy = {j["file"] for j in act}
    tried = {int(l.split("\t")[0], 16) for r in (ROOT / "build/results").glob("*-d*.tsv")
             for l in r.read_text().splitlines() if "\tDRAFT" in l}
    files: dict[str, list] = {}
    for l in (ROOT / "build/slices/drafts_known.tsv").read_text().splitlines():
        a, f, d, n, size = l.split("\t")
        if int(d) <= maxd and int(size) <= maxb and f not in busy and int(a, 16) not in tried:
            files.setdefault(f, []).append((int(d), a, n))
    for f, v in sorted(files.items(), key=lambda kv: (-len(kv[1]), sum(d for d, _, _ in kv[1]))):
        src = (ROOT / f).read_text()
        live = [x for x in sorted(v) if re.search(r"// DRAFT: 0x0*%s " % x[1][2:].lstrip("0"), src, re.I)]
        if live:
            pick = live[:PER_JOB]
            stem = Path(f).stem
            job = {"id": f"{stem}-d{int(time.time() * 1000) % 1000000}", "file": f, "header": f"src/game/{stem}.h",
                   "funcs": " ".join(a for _, a, _ in pick),
                   "names": [f"{a} {n} diff {d}" for d, a, n in pick], "started": time.time(), "kind": "draft"}
            q.save_active(act + [job])
            print(json.dumps(job))
            return 0
    print("no draft job", file=sys.stderr)
    return 1


if __name__ == "__main__":
    sys.exit(main())
