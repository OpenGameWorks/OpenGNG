#!/usr/bin/env python3
"""Count float-literal code forms per game translation unit of SLUS_207.22.

MW `-O4,p` builds a float literal inline (`lui`/`ori`/`mtc1`); `-O4` loads it
from a gp-relative pool (`lwc1` relocated to an `@N` literal). The per-file
counts are the evidence for the default `-O4,p` in tools/srcmeta.py.

Usage: fltscan.py
Prints `FILE<TAB>pooled<TAB>inline` for each non-SDK unit in config/tus.tsv.
"""

from __future__ import annotations

import sys
from pathlib import Path

import disasm

ROOT = Path(__file__).resolve().parent.parent
COP1, MTC1, ORI, LWC1 = 0x11, 4, 0x0D, 0x31


def counts(start: int, end: int) -> tuple[int, int]:
    rel = disasm.relocs()
    pooled = inline = 0
    for a in range(start, end, 4):
        w = disasm.word(a)
        if w >> 26 == LWC1 and a in rel and rel[a][1].startswith("@"):
            pooled += 1
        if w >> 26 == COP1 and (w >> 21) & 31 == MTC1:
            rt = (w >> 16) & 31
            # An `ori` into the moved register within the previous four words
            # marks a literal whose low half is nonzero, which -O4 would pool.
            if any(disasm.word(b) >> 26 == ORI and (disasm.word(b) >> 16) & 31 == rt
                   for b in range(a - 4, max(start, a - 20), -4)):
                inline += 1
    return pooled, inline


def main() -> int:
    if len(sys.argv) > 1:
        print(__doc__.strip())
        return 0 if sys.argv[1] in ("-h", "--help") else 2
    rows = (ROOT / "config/tus.tsv").read_text().splitlines()[1:]
    for row in rows:
        start, end, category, name, *_ = row.split("\t")
        if category != "sdk":
            pooled, inline = counts(int(start, 16), int(end, 16))
            print(f"{name}\t{pooled}\t{inline}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
