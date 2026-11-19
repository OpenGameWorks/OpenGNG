#!/usr/bin/env python3
"""Disassemble one function of SLUS_207.22 with relocation targets named.

Usage: disasm.py NAME|0xADDR [--raw]
Relocations from `.relmain` replace immediates with `%hi(sym)`, `%lo(sym)`,
`%gp_rel(sym)` and `jal sym`, so output is directly usable as a reference
for drafting C++ and as input to m2c.
"""

from __future__ import annotations

import struct
import sys
from functools import lru_cache
from pathlib import Path

import rabbitizer

ROOT = Path(__file__).resolve().parent.parent
ELF = ROOT / "original/extracted/SLUS_207.22"
INFO = ROOT / "build/info"
MAIN_OFF = 0x180  # file offset of section `main` (vaddr 0x100000)
MAIN_VA = 0x100000
RTYPE = {2: "R_MIPS_32", 4: "R_MIPS_26", 5: "R_MIPS_HI16", 6: "R_MIPS_LO16", 7: "R_MIPS_GPREL16"}


@lru_cache(None)
def image() -> bytes:
    return ELF.read_bytes()


@lru_cache(None)
def functions() -> list[tuple[int, int, str]]:
    out = []
    for line in (INFO / "symbols.tsv").read_text().splitlines()[1:]:
        _, a, s, t, _, sh, _, n = line.split("\t")
        if t == "STT_FUNC" and sh == "4":
            out.append((int(a, 16), int(s), n))
    return sorted(set(out))


@lru_cache(None)
def relocs() -> dict[int, tuple[int, str]]:
    out = {}
    for line in (INFO / "relocs.tsv").read_text().splitlines()[1:]:
        sec, off, typ, _, name = line.split("\t")
        if sec == "main":
            out[int(off, 16)] = (int(typ), name)
    return out


def lookup(key: str) -> tuple[int, int, str]:
    fns = functions()
    if key.lower().startswith("0x"):
        a = int(key, 16)
        return next(f for f in fns if f[0] == a)
    return next(f for f in fns if f[2] == key)


def word(addr: int) -> int:
    return struct.unpack_from("<I", image(), addr - MAIN_VA + MAIN_OFF)[0]


def render(addr: int, size: int) -> list[str]:
    rel = relocs()
    lines = []
    for a in range(addr, addr + size, 4):
        w = word(a)
        ins = rabbitizer.Instruction(w, vram=a, category=rabbitizer.InstrCategory.R5900)
        text = ins.disassemble()
        if a in rel:
            typ, sym = rel[a]
            text += f"    # {RTYPE.get(typ, typ)} {sym}"
        lines.append(f"/* {a:08X} {w:08X} */  {text}")
    return lines


def main() -> int:
    a, s, n = lookup(sys.argv[1])
    print(f"# {n} 0x{a:08X} size 0x{s:X}")
    print("\n".join(render(a, s)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
