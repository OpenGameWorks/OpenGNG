#!/usr/bin/env python3
"""Link the `main` image of SLUS_207.22 from compiled objects and fallbacks.

Units come from config/units.tsv. A function unit is filled from a compiled
object when a source claims its address with `// FUNCTION: 0xADDR` and the
compiled function, after relocation, equals the original bytes; otherwise the
unit keeps its original assembly (the bytes extracted from the user's disc).
Relocations are resolved against the symbol addresses of the unit layout,
which equal config/symbols.tsv because every unit keeps its original size.
A relocation to an MW literal (`@N`) or a file-local static resolves to the
target the original names at that offset, and only after the object's
literal bytes are checked equal to the original's; words the object relocates
(jump tables, pointer tables) are compared after relocation, and a local the
original keeps in .bss must be zero in the object. An undefined extern whose
name equals the original's local target at that offset resolves to that target.

Usage: link.py OUT.bin [OBJ:SRC ...]
Writes OUT.bin and build/link.tsv (addr name status source detail).
"""

from __future__ import annotations

import struct
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

sys.path.insert(0, str(Path(__file__).resolve().parent))
import disasm  # noqa: E402
import srcmeta  # noqa: E402

ROOT = disasm.ROOT
BASE = 0x100000
GP = 0x2CBF70  # .reginfo ri_gp_value


def symbol_table() -> tuple[dict[str, int], dict[int, tuple[int, int, str]]]:
    glob, byindex = {}, {}
    for line in (ROOT / "config/symbols.tsv").read_text().splitlines()[1:]:
        i, a, s, t, b, sh, _, n = line.split("\t")
        byindex[int(i)] = (int(a, 16), int(s), n)
        if b != "STB_LOCAL" and sh != "SHN_UNDEF":
            glob.setdefault(n, int(a, 16))
    return glob, byindex


def original_relocs() -> dict[int, tuple[int, int]]:
    out = {}
    for line in (ROOT / "config/relocs.tsv").read_text().splitlines()[1:]:
        sec, off, typ, si, _ = line.split("\t")
        if sec == "main":
            out[int(off, 16)] = (int(typ), int(si))
    return out


class Obj:
    def __init__(self, path: Path):
        self.f = ELFFile(path.open("rb"))
        self.syms = list(self.f.get_section_by_name(".symtab").iter_symbols())

    def function(self, name: str):
        fn = next((s for s in self.syms if s.name == name and s["st_info"]["type"] == "STT_FUNC"), None)
        if fn is None:
            return None
        shi, start, size = fn["st_shndx"], fn["st_value"], fn["st_size"]
        self.fn = fn
        code = bytearray(self.f.get_section(shi).data()[start:start + size])
        rels = []
        for rs in self.f.iter_sections():
            if isinstance(rs, RelocationSection) and rs["sh_info"] == shi:
                for r in rs.iter_relocations():
                    if start <= r["r_offset"] < start + size:
                        rels.append((r["r_offset"] - start, r["r_info_type"], self.syms[r["r_info_sym"]]))
        return code, sorted(rels, key=lambda x: x[0])

    def symbol_bytes(self, sym) -> bytes | None:
        if not isinstance(sym["st_shndx"], int):
            return None
        sec = self.f.get_section(sym["st_shndx"])
        if sec["sh_type"] == "SHT_NOBITS":
            return bytes(sym["st_size"])
        return sec.data()[sym["st_value"]:sym["st_value"] + sym["st_size"]]

    def data_relocs(self, sym):
        """Relocations inside a data symbol: (offset in symbol, type, target symbol)."""
        shi, start, size = sym["st_shndx"], sym["st_value"], sym["st_size"]
        out = []
        for rs in self.f.iter_sections():
            if isinstance(rs, RelocationSection) and rs["sh_info"] == shi:
                for r in rs.iter_relocations():
                    if start <= r["r_offset"] < start + size:
                        out.append((r["r_offset"] - start, r["r_info_type"], self.syms[r["r_info_sym"]]))
        return out


def local_matches(obj: Obj, sym, oaddr: int, osize: int, addr: int, glob, byindex, orel, image: bytes) -> bool:
    """A file-local data symbol equals the original's: same size and bytes, relocated words included."""
    if sym["st_size"] and sym["st_size"] != osize:
        return False
    mine = obj.symbol_bytes(sym)
    if mine is None:
        return False
    if not BASE <= oaddr < BASE + len(image):
        # The original keeps it in .bss, past the loaded image: zero-initialised.
        return not any(mine)
    theirs = image[oaddr - BASE:oaddr - BASE + osize]
    if len(mine) != len(theirs):
        return False
    mine = bytearray(mine)
    fn = obj.fn
    for off, typ, tsym in obj.data_relocs(sym):
        o = orel.get(oaddr + off)
        if typ != 2 or o is None or o[0] != 2:
            return False
        w = struct.unpack_from("<I", mine, off)[0]
        if tsym["st_info"]["type"] == "STT_SECTION" or tsym.name == fn.name:
            # A jump table into the function being placed: the addend is an offset in it.
            base = fn["st_value"] if tsym.name == fn.name else 0
            rel = w + base - fn["st_value"]
            if tsym["st_shndx"] != fn["st_shndx"] or not 0 <= rel < fn["st_size"]:
                return False
            v = addr + rel
        elif tsym.name in glob:
            v = glob[tsym.name] + w
        elif tsym.name == byindex[o[1]][2]:
            v = byindex[o[1]][0] + w
        else:
            return False
        struct.pack_into("<I", mine, off, v & 0xFFFFFFFF)
    return bytes(mine) == theirs


def resolve(obj: Obj, code: bytearray, rels, addr: int, glob, byindex, orel, image: bytes) -> str | None:
    """Patch code in place; return an error string when a target cannot be proven."""
    targets = []
    for off, typ, sym in rels:
        o = orel.get(addr + off)
        if o is None or o[0] != typ:
            return f"reloc {typ} at +{off:#x} absent in original"
        oaddr, osize, oname = byindex[o[1]]
        local = sym["st_info"]["bind"] == "STB_LOCAL" or sym.name.startswith("@")
        if sym["st_info"]["type"] == "STT_SECTION":
            return f"section-relative reloc at +{off:#x}"
        if local:
            if not local_matches(obj, sym, oaddr, osize, addr, glob, byindex, orel, image):
                return f"local {sym.name} differs from original {oname}"
            s = oaddr
        elif sym.name in glob:
            s = glob[sym.name]
        elif sym["st_shndx"] == "SHN_UNDEF" and sym.name == oname:
            # An extern for a file-local static the source does not define yet: the
            # original relocation at this offset names the same symbol, so it proves the target.
            s = oaddr
        else:
            return f"undefined {sym.name}"
        targets.append((off, typ, s))
    # REL addends live in place; a HI16 pairs with the next LO16 of the same target.
    for i, (off, typ, s) in enumerate(targets):
        w = struct.unpack_from("<I", code, off)[0]
        if typ == 4:
            v = (w & 0xFC000000) | ((((w & 0x3FFFFFF) << 2) + s) >> 2 & 0x3FFFFFF)
        elif typ == 5:
            lo = next((t for t in targets[i + 1:] if t[1] == 6 and t[2] == s), None)
            lo_w = struct.unpack_from("<I", code, lo[0])[0] if lo else 0
            ahl = ((w & 0xFFFF) << 16) + ((lo_w & 0xFFFF) ^ 0x8000) - 0x8000
            val = s + ahl
            v = (w & 0xFFFF0000) | (((val + 0x8000) >> 16) & 0xFFFF)
        elif typ == 6:
            v = (w & 0xFFFF0000) | ((s + (w & 0xFFFF)) & 0xFFFF)
        elif typ == 7:
            a = ((w & 0xFFFF) ^ 0x8000) - 0x8000
            v = (w & 0xFFFF0000) | ((s + a - GP) & 0xFFFF)
        elif typ == 2:
            v = (w + s) & 0xFFFFFFFF
        else:
            return f"unsupported reloc type {typ}"
        struct.pack_into("<I", code, off, v)
    return None


def main() -> int:
    out = Path(sys.argv[1])
    pairs = [a.split(":", 1) for a in sys.argv[2:]]
    image = disasm.image()[disasm.MAIN_OFF:disasm.MAIN_OFF + 0x1C4200]
    buf = bytearray(image)
    glob, byindex = symbol_table()
    orel = original_relocs()
    units = {}
    for line in (ROOT / "config/units.tsv").read_text().splitlines()[1:]:
        a, b, k, n = line.split("\t")
        units[int(a, 16)] = (int(b, 16), k, n)
    report = []
    placed = 0
    claimed: dict[int, str] = {}
    for objp, srcp in pairs:
        obj = Obj(Path(objp))
        for kind, addr, name, _ in srcmeta.tags(Path(srcp)):
            # DRAFT sources compile too; they are verified like FUNCTION claims, and a
            # draft whose bytes already equal the original is reported for retagging.
            if addr in claimed:
                report.append((addr, name, "duplicate", srcp, claimed[addr]))
                continue
            claimed[addr] = srcp
            u = units.get(addr)
            if u is None or u[1] != "func":
                report.append((addr, name, "nounit", srcp, ""))
                continue
            end, _, uname = u
            got = obj.function(name or uname)
            if got is None:
                report.append((addr, uname, "missing", srcp, ""))
                continue
            code, rels = got
            if len(code) != end - addr:
                report.append((addr, uname, "differ", srcp, f"size {len(code):#x} vs {end - addr:#x}"))
                continue
            err = resolve(obj, code, rels, addr, glob, byindex, orel, image)
            if err:
                report.append((addr, uname, "refs", srcp, err))
                continue
            if bytes(code) != image[addr - BASE:end - BASE]:
                report.append((addr, uname, "differ", srcp, "bytes"))
                continue
            buf[addr - BASE:end - BASE] = code
            placed += 1
            report.append((addr, uname, "match" if kind == "FUNCTION" else "draft-match", srcp, ""))
    out.write_bytes(buf)
    with (ROOT / "build/link.tsv").open("w") as w:
        for r in sorted(report):
            w.write(f"{r[0]:08X}\t{r[1]}\t{r[2]}\t{r[3]}\t{r[4]}\n")
    bad = [r for r in report if r[2] != "match"]
    print(f"link: {placed} compiled functions placed, {len(bad)} kept as original asm")
    return 0


if __name__ == "__main__":
    sys.exit(main())
