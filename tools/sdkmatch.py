#!/usr/bin/env python3
"""Locate SCE library objects inside `main` by relocation-masked byte comparison.

SDK code is linked from Sony's prebuilt archives, not decompiled. Each archive
member's `.text` is compared against the executable with every relocated field
masked on both sides (R_MIPS_26: low 26 bits; HI16/LO16/GPREL16: low 16 bits;
R_MIPS_32: whole word), so an exact masked match means the original object was
linked unchanged at that address.

Archives come from a user-supplied SDK tree (SCE CONFIDENTIAL; never committed):
  ext/sce/x252/tlib_252/ee/lib/*.a   (2.5.2 patch: libkernl, libcdvd) searched first
  ext/sce/x250/sce/ee/lib/*.a        (2.5.0 runtime)

Usage: sdkmatch.py [SDKROOT]
Writes config/sdk.tsv: start end archive member and prints coverage per tus.tsv category.
"""

from __future__ import annotations

import io
import struct
import sys
from bisect import bisect_right
from pathlib import Path

from elftools.elf.elffile import ELFFile

sys.path.insert(0, str(Path(__file__).resolve().parent))
import disasm  # noqa: E402

ROOT = disasm.ROOT
TEXT_END = 0x218300
MASK = {2: 0x00000000, 4: 0xFC000000, 5: 0xFFFF0000, 6: 0xFFFF0000, 7: 0xFFFF0000}
KEY = 4  # words hashed per candidate position


def members(path: Path):
    """Yield (name, bytes) for each object in a GNU/SysV ar archive."""
    data = path.read_bytes()
    pos, longnames = 8, b""
    while pos + 60 <= len(data):
        hdr = data[pos:pos + 60]
        name, size = hdr[:16].decode().strip(), int(hdr[48:58])
        body = data[pos + 60:pos + 60 + size]
        if name == "//":
            longnames = body
        elif name not in ("/", "/SYM64/"):
            if name.startswith("/") and name[1:].isdigit():
                o = int(name[1:])
                name = longnames[o:longnames.index(b"/", o)].decode()
            yield name.rstrip("/"), body
        pos += 60 + size + (size & 1)


def text_words(obj: bytes) -> tuple[list[int], list[tuple[int, str]]] | None:
    """Masked little-endian words of an object's .text and its (offset, name) function
    symbols, or None without one."""
    elf = ELFFile(io.BytesIO(obj))
    sec = elf.get_section_by_name(".text")
    if sec is None or sec.data_size < 4 * KEY:
        return None
    raw = sec.data()
    words = list(struct.unpack(f"<{len(raw) // 4}I", raw[:len(raw) & ~3]))
    tidx = next(i for i, s in enumerate(elf.iter_sections()) if s.name == ".text")
    for rs in elf.iter_sections():
        # pyelftools builds a fresh section object per lookup, so compare indices
        if rs.header.sh_type in ("SHT_REL", "SHT_RELA") and rs.header.sh_info == tidx:
            for r in rs.iter_relocations():
                i = r["r_offset"] // 4
                if i < len(words):
                    words[i] &= MASK.get(r["r_info_type"], 0)
    syms = elf.get_section_by_name(".symtab")
    funcs = [(y["st_value"], y.name) for y in (syms.iter_symbols() if syms else ())
             if y["st_info"]["type"] == "STT_FUNC" and y["st_shndx"] == tidx]
    return words, funcs


def exe_words() -> list[int]:
    img = disasm.image()
    off = disasm.MAIN_OFF
    n = (TEXT_END - disasm.MAIN_VA) // 4
    words = list(struct.unpack(f"<{n}I", img[off:off + 4 * n]))
    for o, (typ, _) in disasm.relocs_full().items():
        i = (o if o < disasm.MAIN_VA else o - disasm.MAIN_VA) // 4
        if 0 <= i < n:
            words[i] &= MASK.get(typ, 0)
    return words


def main() -> int:
    sdk = Path(sys.argv[1]) if len(sys.argv) > 1 else ROOT / "ext/sce"
    libs = sorted((sdk / "x252").rglob("ee/lib/*.a")) + sorted((sdk / "x250").glob("sce/ee/lib/*.a"))
    # ee-gcc toolchain runtime (newlib libc/libm, libgcc); first directory wins per archive name
    libs += sorted(sdk.glob("toolchain*/*.a"))
    if not libs:
        print(f"no SCE archives under {sdk}", file=sys.stderr)
        return 1
    ex = exe_words()
    index: dict[tuple, list[int]] = {}
    for i in range(len(ex) - KEY):
        index.setdefault(tuple(ex[i:i + KEY]), []).append(i)
    names = {a: n for a, _, n in disasm.functions()}
    placed: dict[int, tuple[int, str, str]] = {}
    seen_libs: set[str] = set()
    for lib in libs:
        if lib.name in seen_libs:
            continue  # the 2.5.2 copy of a library supersedes the 2.5.0 one
        seen_libs.add(lib.name)
        for name, obj in members(lib):
            try:
                w = text_words(obj)
            except Exception:
                continue
            if not w:
                continue
            w, funcs = w
            for i in index.get(tuple(w[:KEY]), ()):
                a = disasm.MAIN_VA + 4 * i
                # short generic bodies recur in game code; the exe's own symbols confirm the object
                if ex[i:i + len(w)] == w and all(names.get(a + o) == n for o, n in funcs):
                    if a not in placed:
                        placed[a] = (a + 4 * len(w), lib.name, name)
    rows = sorted(placed.items())
    with (ROOT / "config/sdk.tsv").open("w") as f:
        f.write("start\tend\tarchive\tmember\n")
        for a, (b, l, m) in rows:
            f.write(f"{a:08X}\t{b:08X}\t{l}\t{m}\n")
    # coverage of each tus.tsv category by matched objects
    tus = [l.split("\t")[:4] for l in (ROOT / "config/tus.tsv").read_text().splitlines()[1:]]
    tus = [(int(a, 16), int(b, 16), c) for a, b, c, _ in tus]
    st = [t[0] for t in tus]
    cov: dict[str, int] = {}
    for a, (b, _, _) in rows:
        for x in range(a, b, 4):
            k = bisect_right(st, x) - 1
            c = tus[k][2] if k >= 0 and x < tus[k][1] else "outside"
            cov[c] = cov.get(c, 0) + 4
    tot: dict[str, int] = {}
    for a, b, c in tus:
        tot[c] = tot.get(c, 0) + b - a
    print(f"{len(rows)} objects placed")
    for c in sorted(set(tot) | set(cov)):
        print(f"{c:8} {cov.get(c, 0):8} / {tot.get(c, 0):8} bytes covered by SDK objects")
    return 0


if __name__ == "__main__":
    sys.exit(main())
