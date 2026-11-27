#!/usr/bin/env python3
"""Score every DRAFT tag against the objects `ninja` already built.

The coordinator queues the closest drafts first, so the scan reads
build/obj/src/**/X.o rather than recompiling: run `ninja` beforehand.
A draft scores the number of differing words fncmp.py reports; a size
mismatch or a missing definition scores 9999.

Usage: draftscan.py [--max N]
Writes build/slices/drafts_known.tsv: addr file diff name size (sorted by diff).
"""

from __future__ import annotations

import contextlib
import io
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import disasm  # noqa: E402
import fncmp  # noqa: E402
import srcmeta  # noqa: E402

ROOT = disasm.ROOT
OUT = ROOT / "build/slices/drafts_known.tsv"
VERDICT = re.compile(r"(MATCH|DIFF (\d+) words)$")


def score(src: Path, obj: Path, addr: int) -> int:
    buf = io.StringIO()
    with contextlib.redirect_stdout(buf):
        try:
            fncmp.compare(src, f"0x{addr:X}", obj, True)
        except Exception:  # noqa: BLE001 - a broken object scores as unusable
            return 9999
    text = buf.getvalue()
    if "size " in text or "not defined" in text:
        return 9999
    m = VERDICT.search(text.strip().splitlines()[-1]) if text.strip() else None
    if not m:
        return 9999
    return 0 if m.group(1) == "MATCH" else int(m.group(2))


def main() -> int:
    rows = []
    for src in sorted((p for p in (ROOT / "src").rglob("*.c*") if p.suffix in (".c", ".cpp"))):
        if "scratch" in src.relative_to(ROOT).parts:
            continue
        obj = ROOT / "build/obj" / src.relative_to(ROOT).with_suffix(".o")
        tags = [t for t in srcmeta.tags(src) if t[0] == "DRAFT"]
        if not tags or not obj.exists():
            continue
        for _, addr, name, _ in tags:
            _, size, _ = disasm.lookup(f"0x{addr:X}")
            rows.append((score(src, obj, addr), addr, src.relative_to(ROOT), name, size))
    rows.sort()
    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text("".join(f"0x{a:08X}\t{f}\t{d}\t{n}\t{s}\n" for d, a, f, n, s in rows))
    for lim in (0, 5, 20, 50, 200):
        print(f"diff <= {lim:4}: {sum(1 for r in rows if r[0] <= lim)}")
    print(f"{len(rows)} drafts -> {OUT.relative_to(ROOT)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
