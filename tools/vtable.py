#!/usr/bin/env python3
"""Print a class's vtable slots from the original executable.

Usage: vtable.py CLASS      e.g. vtable.py ClockworkMaximo

Each line is `0xOFFSET 0xTARGET SYMBOL`. CodeWarrior vtables open with an
8-byte header, so the offset a virtual call loads (`lw t9,N(t9)`) names its
target directly.
"""

from __future__ import annotations

import struct
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parent.parent
ELF = ROOT / "original" / "extracted" / "SLUS_207.22"


def main() -> int:
    if len(sys.argv) != 2:
        print(__doc__.strip(), file=sys.stderr)
        return 2
    cls = sys.argv[1]
    want = f"__vt__{len(cls)}{cls}"
    funcs: dict[int, str] = {}
    vt = None
    for row in (ROOT / "config" / "symbols.tsv").read_text().splitlines():
        p = row.split("\t")
        if len(p) < 8:
            continue
        if p[3] == "STT_FUNC":
            funcs[int(p[1], 16)] = p[7]
        elif p[7] == want:
            vt = (int(p[1], 16), int(p[2]))
    if vt is None:
        print(f"{want} not in config/symbols.tsv", file=sys.stderr)
        return 1
    with ELF.open("rb") as f:
        elf = ELFFile(f)
        seg = next(s for s in elf.iter_segments()
                   if s["p_type"] == "PT_LOAD"
                   and s["p_vaddr"] <= vt[0] < s["p_vaddr"] + s["p_filesz"])
        f.seek(seg["p_offset"] + vt[0] - seg["p_vaddr"])
        data = f.read(vt[1])
    for off in range(0, len(data) - 3, 4):
        (w,) = struct.unpack_from("<I", data, off)
        print(f"0x{off:02X} 0x{w:08X} {funcs.get(w, '')}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
