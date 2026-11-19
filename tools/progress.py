#!/usr/bin/env python3
"""Report decompilation progress by category from the last link.

A function counts as *matched* only when build/link.tsv says the linker placed
compiled code for it (its relocated bytes equal the original). *Draft* counts
functions claimed by a `// DRAFT:` tag in a compiling source. Everything else
is original assembly and never counts toward source-match totals. Categories
come from config/tus.tsv: `game` (Capcom code), `sdk` (SCE libraries built by
gcc), `unknown` (not yet attributed).

Usage: progress.py [--json]   (--json writes build/progress.json)
"""

from __future__ import annotations

import json
import sys
import time
from bisect import bisect_right
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import srcmeta  # noqa: E402


def load():
    tus = []
    for l in (ROOT / "config/tus.tsv").read_text().splitlines()[1:]:
        a, b, c, f, _ = l.split("\t")
        tus.append((int(a, 16), int(b, 16), c, f))
    starts = [t[0] for t in tus]
    funcs = []
    for l in (ROOT / "config/units.tsv").read_text().splitlines()[1:]:
        a, b, k, n = l.split("\t")
        if k == "func":
            funcs.append((int(a, 16), int(b, 16) - int(a, 16), n))
    status = {}
    lt = ROOT / "build/link.tsv"
    if lt.exists():
        for l in lt.read_text().splitlines():
            p = l.split("\t")
            status[int(p[0], 16)] = p[2]
    drafts = set()
    for s in (ROOT / "src").rglob("*.c*"):
        if "scratch" in s.parts:
            continue
        for kind, addr, _, _ in srcmeta.tags(s):
            if kind == "DRAFT":
                drafts.add(addr)
    return tus, starts, funcs, status, drafts


def main() -> int:
    tus, starts, funcs, status, drafts = load()
    cats: dict[str, dict[str, int]] = {}
    files: dict[str, dict] = {}
    for a, size, n in funcs:
        i = bisect_right(starts, a) - 1
        cat, f = (tus[i][2], tus[i][3]) if i >= 0 and a < tus[i][1] else ("unknown", "?")
        st = "matched" if status.get(a) == "match" else "draft" if (a in drafts or status.get(a) in ("differ", "refs")) else "asm"
        c = cats.setdefault(cat, {"funcs": 0, "bytes": 0, "matched_funcs": 0, "matched_bytes": 0, "draft_funcs": 0, "draft_bytes": 0})
        c["funcs"] += 1
        c["bytes"] += size
        if st != "asm":
            c[f"{st}_funcs"] += 1
            c[f"{st}_bytes"] += size
        fe = files.setdefault(f, {"file": f, "cat": cat, "funcs": 0, "bytes": 0, "matched": 0, "matched_bytes": 0, "draft": 0})
        fe["funcs"] += 1
        fe["bytes"] += size
        fe["matched"] += st == "matched"
        fe["matched_bytes"] += size if st == "matched" else 0
        fe["draft"] += st == "draft"
    ok = (ROOT / "build/SLUS_207.22.ok").exists() and (ROOT / "build/SLUS_207.22.ok").stat().st_mtime >= (ROOT / "build/main.bin").stat().st_mtime if (ROOT / "build/main.bin").exists() else False
    doc = {"updated": time.time(), "build_ok": ok, "categories": cats, "files": sorted(files.values(), key=lambda x: x["file"])}
    for k, c in sorted(cats.items()):
        pf = 100 * c["matched_bytes"] / c["bytes"] if c["bytes"] else 0
        print(f"{k:8} matched {c['matched_funcs']:5}/{c['funcs']:5} funcs  {c['matched_bytes']:8}/{c['bytes']:8} bytes ({pf:6.2f}%)  draft {c['draft_funcs']} funcs")
    if "--json" in sys.argv:
        (ROOT / "build/progress.json").write_text(json.dumps(doc))
    return 0


if __name__ == "__main__":
    sys.exit(main())
