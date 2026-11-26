#!/usr/bin/env python3
"""Verify that SCE library members located by sdkmatch.py are linked unchanged.

SDK code is supplied from Sony's original archives, never decompiled, so it
counts as a library match only when the member's own `.text` explains the
executable's bytes. For each row of config/sdk.tsv the member is checked at
its placement address on three points:
  bytes     every word equals the executable outside relocated fields
  relocs    the member and the executable's `.relmain` relocate the same
            offsets with the same types (no extra or missing relocations)
  targets   a relocation against a named symbol names the same symbol (or an
            alias at the same address) as the executable's relocation
Relocations against the member's own sections (.data, .rodata, .sdata) are
accepted on position and type alone: where the linker put those sections is
what the executable's relocation records.

Usage: sdklink.py [SDKROOT]
Writes build/sdk_link.tsv: start end archive member status detail
(status `lib` = verified, `bad` = rejected); progress.py reads it.
"""

from __future__ import annotations

import io
import struct
import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

sys.path.insert(0, str(Path(__file__).resolve().parent))
import disasm  # noqa: E402
import sdkmatch  # noqa: E402

ROOT = disasm.ROOT
OUT = ROOT / "build/sdk_link.tsv"


def archives(sdk: Path) -> dict[str, list[Path]]:
    """Archive name -> candidate paths in sdkmatch.py's search order (2.5.2 before 2.5.0,
    then every ee-gcc toolchain version, whose libc/libm/libgcc share names)."""
    out: dict[str, list[Path]] = {}
    libs = sorted((sdk / "x252").rglob("ee/lib/*.a")) + sorted((sdk / "x250").glob("sce/ee/lib/*.a"))
    libs += sorted(sdk.glob("toolchain*/*.a"))
    for lib in libs:
        out.setdefault(lib.name, []).append(lib)
    return out


def check(obj: bytes, start: int, end: int, image: bytes, orel, syms) -> str | None:
    elf = ELFFile(io.BytesIO(obj))
    secs = list(elf.iter_sections())
    tidx = next(i for i, s in enumerate(secs) if s.name == ".text")
    raw = secs[tidx].data()
    if len(raw) != end - start:
        return f"size {len(raw):#x} vs {end - start:#x}"
    symtab = elf.get_section_by_name(".symtab")
    msyms = list(symtab.iter_symbols())
    mine: dict[int, tuple[int, object]] = {}
    for rs in secs:
        if isinstance(rs, RelocationSection) and rs["sh_info"] == tidx:
            for r in rs.iter_relocations():
                mine[r["r_offset"]] = (r["r_info_type"], msyms[r["r_info_sym"]])
    for off in range(0, len(raw), 4):
        a = start + off
        have = struct.unpack_from("<I", raw, off)[0]
        want = struct.unpack_from("<I", image, a - disasm.MAIN_VA)[0]
        m, o = mine.get(off), orel.get(a)
        if bool(m) != bool(o):
            return f"+{off:#x}: reloc {'only in member' if m else 'only in executable'}"
        if m:
            typ, sym = m
            if typ != o[0]:
                return f"+{off:#x}: reloc type {typ} vs {o[0]}"
            mask = sdkmatch.MASK.get(typ, 0)
            if have & mask != want & mask:
                return f"+{off:#x}: bytes"
            if sym["st_info"]["type"] != "STT_SECTION" and sym.name:
                oaddr, _, oname = syms.get(o[1], (None, None, ""))
                if sym.name != oname and disasm_addr(sym.name) != oaddr:
                    return f"+{off:#x}: target {sym.name} vs {oname}"
        elif have != want:
            return f"+{off:#x}: bytes"
    return None


_GLOBALS: dict[str, int] = {}


def disasm_addr(name: str) -> int | None:
    if not _GLOBALS:
        for line in (ROOT / "config/symbols.tsv").read_text().splitlines()[1:]:
            f = line.split("\t")
            _GLOBALS.setdefault(f[7], int(f[1], 16))
    return _GLOBALS.get(name)


def main() -> int:
    sdk = Path(sys.argv[1]) if len(sys.argv) > 1 else ROOT / "ext/sce"
    libs = archives(sdk)
    image = disasm.image()[disasm.MAIN_OFF:]
    orel = disasm.relocs_full()
    syms = {}
    for line in (ROOT / "config/symbols.tsv").read_text().splitlines()[1:]:
        f = line.split("\t")
        syms[int(f[0])] = (int(f[1], 16), int(f[2]), f[7])
    cache: dict[Path, dict[str, bytes]] = {}
    rows, ok = [], 0
    for line in (ROOT / "config/sdk.tsv").read_text().splitlines()[1:]:
        a, b, lib, member = line.split("\t")
        start, end = int(a, 16), int(b, 16)
        if lib not in libs:
            rows.append((start, end, lib, member, "bad", "archive not supplied"))
            continue
        err, src = "member missing", lib
        for path in libs[lib]:
            if path not in cache:
                cache[path] = dict(sdkmatch.members(path))
            obj = cache[path].get(member)
            if obj is not None:
                e = check(obj, start, end, image, orel, syms)
                if e is None or err == "member missing":
                    err, src = e, str(path.relative_to(sdk))
                if e is None:
                    break
        rows.append((start, end, src, member, "bad" if err else "lib", err or ""))
        ok += not err
    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text("".join(f"{s:08X}\t{e:08X}\t{l}\t{m}\t{st}\t{d}\n" for s, e, l, m, st, d in rows))
    print(f"sdklink: {ok}/{len(rows)} library members verified")
    for r in rows:
        if r[4] == "bad":
            print(f"  {r[0]:08X} {r[2]}:{r[3]} {r[5]}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
