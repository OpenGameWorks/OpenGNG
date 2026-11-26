#!/usr/bin/env python3
"""List FUNCTION tags the last link did not place: a claimed match that regressed.

A FUNCTION tag is a promise that the linker placed compiled bytes; a header edit
or a neighbouring DRAFT can silently break it. Run after `ninja`; exit 1 when
any FUNCTION tag (optionally only in the named sources) is not `match` in
build/link.tsv, and list `draft-match` DRAFTs that are ready to retag.

Usage: regress.py [SOURCE...]
"""

from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import srcmeta  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent


def main() -> int:
    status = {}
    for l in (ROOT / "build/link.tsv").read_text().splitlines():
        p = l.split("\t")
        status[int(p[0], 16)] = (p[2], p[4] if len(p) > 4 else "")
    only = {Path(a).resolve() for a in sys.argv[1:]}
    bad = 0
    for src in sorted((ROOT / "src").rglob("*.c*")):
        if "scratch" in src.parts or (only and src.resolve() not in only):
            continue
        for kind, addr, name, _ in srcmeta.tags(src):
            st, why = status.get(addr, ("unlinked", ""))
            if kind == "FUNCTION" and st != "match":
                print(f"REGRESSED {src.relative_to(ROOT)} 0x{addr:08X} {name}: {st} {why}")
                bad += 1
            elif kind == "DRAFT" and st == "draft-match":
                print(f"RETAG {src.relative_to(ROOT)} 0x{addr:08X} {name}")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
