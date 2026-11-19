#!/usr/bin/env python3
"""Write SLUS_207.22 from a linked `main` image and the link tables.

The retail file is an MW linker (mwldps2) ELF: program headers for `main`,
the six level overlays and `heap`, then `.shstrtab`, `.strtab`, `.symtab`,
`main`, `.mwcats`, the REL sections and `.comment`/`.reginfo`. The layout of
that container (offsets, flags, program headers) lives in
config/elf_layout.json; symbols and relocations come from
config/symbols.tsv and config/relocs.tsv, which `tools/elfinfo.py`
extracts and the build regenerates.

Usage: elfpack.py dump ELF          write config/elf_layout.json
       elfpack.py pack MAIN.bin OUT write OUT from the tables
"""

from __future__ import annotations

import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
LAYOUT = ROOT / "config/elf_layout.json"
STT = {"STT_NOTYPE": 0, "STT_OBJECT": 1, "STT_FUNC": 2, "STT_SECTION": 3, "STT_FILE": 4}
STB = {"STB_LOCAL": 0, "STB_GLOBAL": 1, "STB_WEAK": 2, "STB_LOPROC": 13}
SHN = {"SHN_UNDEF": 0, "SHN_ABS": 0xFFF1, "SHN_COMMON": 0xFFF2}


def dump(elf: Path) -> int:
    from elftools.elf.elffile import ELFFile

    raw = elf.read_bytes()
    f = ELFFile(elf.open("rb"))
    secs = []
    for s in f.iter_sections():
        h = dict(s.header)
        h["sh_type"] = f.structs.Elf_Shdr.subcons[1].encoding.get(h["sh_type"], h["sh_type"]) if False else s["sh_type"]
        secs.append({"name": s.name, **{k: (v if isinstance(v, int) else str(v)) for k, v in h.items()}})
    hdr = raw[:52]
    phdrs = raw[52:52 + 32 * f.header.e_phnum]
    # Section types as raw integers keep unknown vendor types such as .mwcats.
    sh_raw = [struct.unpack_from("<10I", raw, f.header.e_shoff + 40 * i) for i in range(f.header.e_shnum)]
    keep = {}
    for s, r in zip(secs, sh_raw):
        if s["name"] in (".mwcats", ".comment", ".reginfo"):
            keep[s["name"]] = raw[r[4]:r[4] + r[5]].hex()
    out = {
        "ehdr": hdr.hex(),
        "phdrs": phdrs.hex(),
        "shdrs": [[s["name"], *r] for s, r in zip(secs, sh_raw)],
        "blobs": keep,
        "size": len(raw),
    }
    LAYOUT.parent.mkdir(exist_ok=True)
    LAYOUT.write_text(json.dumps(out, indent=1) + "\n")
    print(f"wrote {LAYOUT}")
    return 0


def read_symbols() -> list[list[str]]:
    rows = [l.split("\t") for l in (ROOT / "config/symbols.tsv").read_text().splitlines()[1:]]
    return rows


def build_strtab_symtab(rows: list[list[str]]) -> tuple[bytes, bytes]:
    # The MW linker emits names in symbol order with no suffix sharing; offsets
    # are recomputed here and checked against the original by the sha1.
    strtab = bytearray(b"\0")
    seen: dict[str, int] = {}
    sym = bytearray()
    for _, addr, size, typ, bind, shndx, _, name in rows:
        if name == "":
            off = 0
        elif name in seen and False:
            off = seen[name]
        else:
            off = len(strtab)
            strtab += name.encode() + b"\0"
            seen[name] = off
        sh = SHN.get(shndx, None)
        if sh is None:
            sh = int(shndx)
        info = (STB[bind] << 4) | STT[typ]
        sym += struct.pack("<IIIBBH", off, int(addr, 16), int(size), info, 0, sh)
    return bytes(strtab), bytes(sym)


def build_rels(names: list[str]) -> dict[str, bytes]:
    out: dict[str, bytearray] = {n: bytearray() for n in names}
    for line in (ROOT / "config/relocs.tsv").read_text().splitlines()[1:]:
        sec, off, typ, si, _ = line.split("\t")
        out[".rel" + sec] += struct.pack("<II", int(off, 16), (int(si) << 8) | int(typ))
    return {k: bytes(v) for k, v in out.items()}


def pack(main_bin: Path, out_path: Path) -> int:
    lay = json.loads(LAYOUT.read_text())
    main = main_bin.read_bytes()
    strtab, symtab = build_strtab_symtab(read_symbols())
    rels = build_rels([s[0] for s in lay["shdrs"] if s[0].startswith(".rel")])
    content = {".strtab": strtab, ".symtab": symtab, "main": main, **rels}
    content.update({k: bytes.fromhex(v) for k, v in lay["blobs"].items()})
    # mwldps2 writes .shstrtab in its own emission order (.comment, .reginfo
    # and .mwcats follow .symtab), not section-table order.
    shstr = bytearray(b"\0")
    name_off = {}
    for s in sorted(lay["shdrs"][1:], key=lambda s: s[1]):
        name_off[s[0]] = len(shstr)
        shstr += s[0].encode() + b"\0"
    buf = bytearray(lay["size"])
    buf[:52] = bytes.fromhex(lay["ehdr"])
    ph = bytes.fromhex(lay["phdrs"])
    buf[52:52 + len(ph)] = ph
    shoff = struct.unpack_from("<I", buf, 0x20)[0]
    for i, (name, nm, typ, flags, addr, off, size, link, info, align, ent) in enumerate(lay["shdrs"]):
        if i == 0:
            hdr = (0,) * 10
        else:
            nm = name_off[name]
            data = content.get(name)
            if data is not None:
                if len(data) != size:
                    raise SystemExit(f"elfpack: {name} is {len(data):#x} bytes, layout expects {size:#x}")
                buf[off:off + size] = data
            hdr = (nm, typ, flags, addr, off, size, link, info, align, ent)
        struct.pack_into("<10I", buf, shoff + 40 * i, *hdr)
    shs = lay["shdrs"][1]
    if shs[0] != ".shstrtab" or len(shstr) != shs[6]:
        raise SystemExit("elfpack: .shstrtab size mismatch")
    buf[shs[5]:shs[5] + len(shstr)] = shstr
    out_path.write_bytes(buf)
    return 0


def main() -> int:
    if sys.argv[1] == "dump":
        return dump(Path(sys.argv[2]))
    return pack(Path(sys.argv[2]), Path(sys.argv[3]))


if __name__ == "__main__":
    sys.exit(main())
