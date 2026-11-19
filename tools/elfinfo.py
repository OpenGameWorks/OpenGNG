#!/usr/bin/env python3
"""Extract the symbol table and relocations of SLUS_207.22 into TSV files.

The retail executable keeps its full linker symbol table (13.5k symbols,
mangled C++ names, file-local statics) and a REL section per load segment
(`.relmain`, `.rel<Overlay>.bin`). Both are primary evidence: symbols give
names, sizes and link order; relocations give the exact target of every
`jal`, `%hi` and `%lo` field.

Usage: elfinfo.py [ELF] [OUTDIR]
Writes OUTDIR/symbols.tsv  (index addr size type bind shndx section name)
       OUTDIR/relocs.tsv   (section offset type symindex symname addend-in-place)
"""

from __future__ import annotations

import sys
from pathlib import Path

from elftools.elf.elffile import ELFFile

ROOT = Path(__file__).resolve().parent.parent


def main() -> int:
    if len(sys.argv) > 1 and sys.argv[1] in ("-h", "--help"):
        print(__doc__.strip())
        return 0
    elf =Path(sys.argv[1]) if len(sys.argv) > 1 else ROOT / "original/extracted/SLUS_207.22"
    out = Path(sys.argv[2]) if len(sys.argv) > 2 else ROOT / "build/info"
    out.mkdir(parents=True, exist_ok=True)
    with elf.open("rb") as fh:
        f = ELFFile(fh)
        names = {i: s.name for i, s in enumerate(f.iter_sections())}
        st = f.get_section_by_name(".symtab")
        syms = list(st.iter_symbols())
        with (out / "symbols.tsv").open("w") as w:
            w.write("index\taddr\tsize\ttype\tbind\tshndx\tsection\tname\n")
            for i, s in enumerate(syms):
                sh = s["st_shndx"]
                sec = names.get(sh, str(sh)) if isinstance(sh, int) else sh
                w.write(
                    f"{i}\t{s['st_value']:08X}\t{s['st_size']}\t{s['st_info']['type']}\t"
                    f"{s['st_info']['bind']}\t{sh}\t{sec}\t{s.name}\n"
                )
        with (out / "relocs.tsv").open("w") as w:
            w.write("section\toffset\ttype\tsymindex\tsymname\n")
            for sec in f.iter_sections():
                if sec["sh_type"] != "SHT_REL":
                    continue
                target = names[sec["sh_info"]]
                for r in sec.iter_relocations():
                    si = r["r_info_sym"]
                    w.write(f"{target}\t{r['r_offset']:08X}\t{r['r_info_type']}\t{si}\t{syms[si].name}\n")
    print(f"{len(syms)} symbols -> {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
