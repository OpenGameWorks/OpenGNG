#!/usr/bin/env python3
"""Partition the `main` image of SLUS_207.22 into link units.

Every byte of `main` (0x100000-0x2C4200) belongs to exactly one unit:
  func  a function symbol's [st_value, st_value+st_size) range
  gap   bytes between two functions (alignment padding)
  blob  everything else: VU microcode, .data, .rodata, .sdata
Units are what the linker (tools/link.py) places; a unit is filled by a
matched compiled function when one claims it, otherwise by the original
bytes. Overlapping function symbols (aliases) keep the first, larger one.

Writes config/units.tsv: start end kind name
"""

from __future__ import annotations

import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
MAIN = (0x100000, 0x2C4200)
TEXT_END = 0x218300  # first .vutext section symbol; MW text ends here


def functions() -> list[tuple[int, int, str]]:
    out = {}
    for line in (ROOT / "config/symbols.tsv").read_text().splitlines()[1:]:
        _, a, s, t, _, sh, _, n = line.split("\t")
        if t == "STT_FUNC" and sh == "4" and int(s):
            a = int(a, 16)
            if a not in out or int(s) > out[a][1]:
                out[a] = (a, int(s), n)
    return sorted(out.values())


def main() -> int:
    units = []
    pos = MAIN[0]
    for a, s, n in functions():
        if a < pos:
            print(f"split: {n} at {a:#x} overlaps previous unit, kept as alias", file=sys.stderr)
            continue
        if a > pos:
            units.append((pos, a, "gap" if pos < TEXT_END and a <= TEXT_END else "blob", f"gap_{pos:08X}"))
        units.append((a, a + s, "func", n))
        pos = a + s
    units.append((pos, MAIN[1], "blob", f"blob_{pos:08X}"))
    # blobs between functions past TEXT_END are data regions holding __sinit code
    out = ROOT / "config/units.tsv"
    with out.open("w") as w:
        w.write("start\tend\tkind\tname\n")
        for a, b, k, n in units:
            w.write(f"{a:08X}\t{b:08X}\t{k}\t{n}\n")
    funcs = sum(1 for u in units if u[2] == "func")
    print(f"{len(units)} units, {funcs} functions -> {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
