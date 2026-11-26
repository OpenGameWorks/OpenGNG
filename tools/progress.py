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
import re
import sys
import time
from bisect import bisect_right
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import srcmeta  # noqa: E402

# First time each address was seen matched; feeds the page's "Recent matches".
SEEN = ROOT / "build/match_times.json"
CAT = {"game": "Game", "sdk": "SDK", "unknown": "Unattributed"}
# Only code with no obtainable original source or object is decompiled; the treemap and
# headline totals cover it alone. SDK code comes from library objects, and unattributed
# runs join a category once evidence assigns them.
DECOMP = {"game"}


def pretty(mangled: str, addr: int) -> str:
    """`Class::Method` from a CodeWarrior mangled name; plain C names unchanged."""
    i = mangled.find("__", 1)
    rest = mangled[i + 2:] if i > 0 else ""
    m = re.match(r"(\d+)", rest)
    if m:
        n = int(m.group(1))
        return f"{rest[len(m.group(1)):len(m.group(1)) + n]}::{mangled[:i]}"
    return mangled or f"func_{addr:08X}"


def load():
    tus = []
    for l in (ROOT / "config/tus.tsv").read_text().splitlines()[1:]:
        a, b, c, f = l.split("\t")[:4]
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
    # Functions inside an SCE archive member that tools/sdklink.py verified come from the
    # original library object: a library match, kept apart from decompiled C/C++.
    sl = ROOT / "build/sdk_link.tsv"
    if sl.exists():
        libs = [(int(p[0], 16), int(p[1], 16)) for p in (l.split("\t") for l in sl.read_text().splitlines()) if p[4] == "lib"]
        for a, size, _ in funcs:
            if any(s <= a and a + size <= e for s, e in libs) and a not in status:
                status[a] = "lib"
    return tus, starts, funcs, status, drafts


def main() -> int:
    tus, starts, funcs, status, drafts = load()
    cats: dict[str, dict[str, int]] = {}
    files: dict[str, dict] = {}
    groups: dict[str, dict] = {}
    recent: list[dict] = []
    now = time.time()
    seen = json.loads(SEEN.read_text()) if SEEN.exists() else {}
    for a, size, n in funcs:
        i = bisect_right(starts, a) - 1
        cat, f = (tus[i][2], tus[i][3]) if i >= 0 and a < tus[i][1] else ("unknown", "?")
        st = "matched" if status.get(a) == "match" else "lib" if status.get(a) == "lib" else "draft" if (a in drafts or status.get(a) in ("differ", "refs", "missing", "draft-match")) else "asm"
        c = cats.setdefault(cat, {"funcs": 0, "bytes": 0, "matched_funcs": 0, "matched_bytes": 0, "draft_funcs": 0, "draft_bytes": 0, "lib_funcs": 0, "lib_bytes": 0})
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
        if cat not in DECOMP:
            continue
        groups.setdefault(f, {"name": Path(f).stem, "cat": CAT[cat], "size": 0, "fns": []})
        groups[f]["size"] += size
        groups[f]["fns"].append([pretty(n, a), size, st == "matched"])
        if st == "matched":
            seen.setdefault(f"{a:08X}", now)
            recent.append({"fn": pretty(n, a), "group": Path(f).stem, "t": seen[f"{a:08X}"]})
    okf, binf = ROOT / "build/SLUS_207.22.ok", ROOT / "build/main.bin"
    ok = okf.exists() and binf.exists() and okf.stat().st_mtime >= binf.stat().st_mtime
    g = cats.get("game", {"funcs": 0, "bytes": 0, "matched_funcs": 0, "matched_bytes": 0})
    tot = {k: sum(c[k] for n, c in cats.items() if n in DECOMP) for k in ("funcs", "bytes", "matched_funcs", "matched_bytes")}
    pf = 100 * g["matched_funcs"] / g["funcs"] if g["funcs"] else 0
    build = [f"SLUS_207.22 SHA-1: {'OK' if ok else 'NOT VERIFIED'}",
             f"game drafts: {g.get('draft_funcs', 0)}"]
    doc = {"title": f"Maximo: {pf:.2f}% ({g['matched_funcs']}/{g['funcs']} game functions)",
           "updated": now, "build_ok": ok, "build": build,
           "functions": {"matched": tot["matched_funcs"], "total": tot["funcs"]},
           "bytes": {"matched": tot["matched_bytes"], "total": tot["bytes"]},
           "recent": sorted(recent, key=lambda r: -r["t"])[:40],
           "groups": list(groups.values()),
           "categories": cats, "files": sorted(files.values(), key=lambda x: x["file"])}
    for k, c in sorted(cats.items()):
        pf = 100 * c["matched_bytes"] / c["bytes"] if c["bytes"] else 0
        lib = f"  library-object {c['lib_funcs']} funcs {c['lib_bytes']} bytes" if c["lib_funcs"] else ""
        print(f"{k:8} matched {c['matched_funcs']:5}/{c['funcs']:5} funcs  {c['matched_bytes']:8}/{c['bytes']:8} bytes ({pf:6.2f}%)  draft {c['draft_funcs']} funcs{lib}")
    if "--json" in sys.argv:
        SEEN.write_text(json.dumps(seen))
        tmp = ROOT / "build/progress.json.tmp"
        tmp.write_text(json.dumps(doc))
        tmp.rename(ROOT / "build/progress.json")  # the live server never serves a half-written file
    return 0


if __name__ == "__main__":
    sys.exit(main())
