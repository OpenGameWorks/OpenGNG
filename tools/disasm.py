#!/usr/bin/env python3
"""Disassemble one function of SLUS_207.22 with relocation targets named.

Usage: disasm.py NAME|0xADDR [--m2c]
Default output annotates each relocated instruction with its `.relmain`
entry. `--m2c` emits GNU-as input for m2c instead: branch labels, and
relocated immediates replaced with `%hi(sym)`, `%lo(sym)`, `%gp_rel(sym)` and
`jal sym` (MW literals `@N` become `lit_<ADDR>`, with their values listed).
"""

from __future__ import annotations

import re
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
GP = 0x2CBF70  # .reginfo ri_gp_value
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


@lru_cache(None)
def symtab() -> dict[int, tuple[int, str, str]]:
    """symbol index -> (address, type, name)."""
    out = {}
    for line in (INFO / "symbols.tsv").read_text().splitlines()[1:]:
        i, a, _, t, _, _, _, n = line.split("\t")
        out[int(i)] = (int(a, 16), t, n)
    return out


@lru_cache(None)
def relocs_full() -> dict[int, tuple[int, int]]:
    """main offset -> (type, symbol index)."""
    out = {}
    for line in (INFO / "relocs.tsv").read_text().splitlines()[1:]:
        sec, off, typ, idx, _ = line.split("\t")
        if sec == "main":
            out[int(off, 16)] = (int(typ), int(idx))
    return out


def ident(name: str, addr: int) -> str:
    # MW literal-pool labels `@N` restart per object and are not C identifiers.
    return f"lit_{addr:08X}" if name.startswith("@") or not name else name


def literal(addr: int) -> str:
    """A pool literal as a C string when it is NUL-terminated text, else as word and float."""
    off = addr - MAIN_VA + MAIN_OFF
    raw = image()[off:off + 256].split(b"\0", 1)[0]
    if len(raw) >= 2 and all(32 <= c < 127 or c in (9, 10) for c in raw):
        return '"' + raw.decode().replace("\\", "\\\\").replace('"', '\\"').replace("\n", "\\n") + '"'
    w = word(addr)
    f = struct.unpack("<f", struct.pack("<I", w))[0]
    return f"0x{w:08X} = {f!r}f"


def target(a: int, typ: int, idx: int, rel: dict[int, tuple[int, int]], end: int) -> tuple[str, int]:
    """Operand text and absolute target for the relocated instruction at a.

    REL relocations keep the addend in the instruction: HI16 pairs with the next
    LO16 of the same symbol, and a LO16 with the preceding HI16."""
    sa, st, sn = symtab()[idx]
    lo = lambda x: (word(x) & 0xFFFF) - ((word(x) & 0x8000) << 1)
    if typ == 4:
        dest = ((word(a) & 0x3FFFFFF) << 2) | (a & 0xF0000000)
        return ident(sn, dest) if st != "STT_SECTION" else f"func_{dest:08X}", dest
    if typ == 5:
        nxt = next((x for x in range(a + 4, end, 4) if rel.get(x) == (6, idx)), None)
        val = ((word(a) & 0xFFFF) << 16) + (lo(nxt) if nxt else 0)
    elif typ == 6:
        prv = next((x for x in range(a - 4, a - 0x400, -4) if rel.get(x) == (5, idx)), None)
        val = ((word(prv) & 0xFFFF) << 16) + lo(a) if prv else ((sa + 0x8000) & ~0xFFFF) + lo(a)
    elif typ == 7:
        val = GP + lo(a)  # the linked field holds S+A-GP
    else:
        return sn, sa
    val &= 0xFFFFFFFF
    if st == "STT_SECTION":
        base = f"D_{val:08X}"
    else:
        off = val - sa
        base = ident(sn, sa) + (f"+0x{off:X}" if off > 0 else f"-0x{-off:X}" if off < 0 else "")
    op = {5: "%hi", 6: "%lo", 7: "%gp_rel"}[typ]
    return f"{op}({base})", val


def decode(a: int) -> rabbitizer.Instruction:
    """R5900 decode; rabbitizer's R5900 table rejects some valid EE encodings
    (cvt.w.s, mfc0 of the performance counter), so fall back to the base CPU table."""
    i = rabbitizer.Instruction(word(a), vram=a, category=rabbitizer.InstrCategory.R5900)
    return i if i.isValid() else rabbitizer.Instruction(word(a), vram=a)


def render_m2c(name: str, addr: int, size: int) -> list[str]:
    """GNU-as listing for m2c: branch labels, relocated operands, literal values."""
    rel = relocs_full()
    end = addr + size
    insns = [decode(a) for a in range(addr, end, 4)]
    labels = {i.getBranchVramGeneric() for i in insns if i.isBranch() and addr <= i.getBranchVramGeneric() < end}
    lines = [f"glabel {ident(name, addr)}"]
    lits = {}
    for i in insns:
        a = i.vram
        if a in labels:
            lines.append(f".L{a:08X}:")
        imm = None
        if a in rel:
            typ, idx = rel[a]
            imm, val = target(a, typ, idx, rel, end)
            sn = symtab()[idx][2]
            if sn.startswith("@") and typ in (6, 7):
                lits[imm] = literal(val)
        elif i.isBranch():
            imm = f".L{i.getBranchVramGeneric():08X}"
        text = i.disassemble(immOverride=imm) if imm else i.disassemble()
        if text.startswith(".word") and "#" in text:
            # rabbitizer prints EE-only forms (cvt.w.s, mfc0 $25) as `.word` and names
            # the real instruction in a comment; recover it so m2c sees an opcode.
            text = re.sub(r"Reserved(\d+)", r"$\1", text.split("#")[1].strip())
        lines.append(f"/* {a:08X} {word(a):08X} */  {text}")
    for k, v in sorted(lits.items()):
        lines.append(f"# literal {k}: {v}")
    return lines


def main() -> int:
    if len(sys.argv) < 2 or sys.argv[1] in ("-h", "--help"):
        print(__doc__.strip())
        return 0 if len(sys.argv) > 1 else 2
    try:
        a, s, n = lookup(sys.argv[1])
    except (StopIteration, ValueError):
        # Data addresses (literals, vtables) and unknown names have no function entry.
        print(f"{sys.argv[1]}: not the start of a function in .main", file=sys.stderr)
        return 1
    if "--m2c" in sys.argv:
        print("\n".join(render_m2c(n, a, s)))
        return 0
    print(f"# {n} 0x{a:08X} size 0x{s:X}")
    print("\n".join(render(a, s)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
