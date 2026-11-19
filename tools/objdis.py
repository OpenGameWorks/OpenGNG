#!/usr/bin/env python3
"""Disassemble every function symbol in a MIPS ELF object (R5900).

Usage: objdis.py OBJ [SYMBOL]
"""
import sys

import rabbitizer
from elftools.elf.elffile import ELFFile

f = ELFFile(open(sys.argv[1], "rb"))
want = sys.argv[2] if len(sys.argv) > 2 else None
for sym in f.get_section_by_name(".symtab").iter_symbols():
    if sym["st_info"]["type"] != "STT_FUNC" or (want and sym.name != want):
        continue
    sec = f.get_section(sym["st_shndx"])
    data = sec.data()[sym["st_value"]: sym["st_value"] + sym["st_size"]]
    print(f"# {sym.name} ({sec.name}) size 0x{sym['st_size']:X}")
    for i in range(0, len(data), 4):
        w = int.from_bytes(data[i:i + 4], "little")
        ins = rabbitizer.Instruction(w, vram=i, category=rabbitizer.InstrCategory.R5900)
        print(f"/* {i:04X} {w:08X} */  {ins.disassemble()}")
