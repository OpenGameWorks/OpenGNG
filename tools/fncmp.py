#!/usr/bin/env python3
"""Compile a source and compare one function against SLUS_207.22.

Usage: fncmp.py [-q] [--obj OBJ] SOURCE NAME|0xADDR
Exit 0 = MATCH: every instruction word is identical outside relocated fields,
and every relocation in the compiled function names the same symbol that the
original executable's `.relmain` names at that offset. Relocations against a
section symbol (`.rodata`, `.sdata`, literal pools) are reported as `DATA`
and accepted only when the original also relocates there against a local
`@N` literal or section; the full build confirms them. A function-local
static is named `name$N` with a translation-unit-wide counter N, which only a
complete unit reproduces; `name$N` therefore matches the original's `name$M`,
and the build accepts it only when the static's bytes equal the original's.
Without -q a side-by-side listing marks differing words with `!`.
"""

from __future__ import annotations

import os
import re
import subprocess
import sys
from pathlib import Path

import rabbitizer
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

sys.path.insert(0, str(Path(__file__).resolve().parent))
import disasm  # noqa: E402
import srcmeta  # noqa: E402

ROOT = disasm.ROOT
LOCAL_STATIC = re.compile(r"\$\d+$")
MASK = {4: 0xFC000000, 5: 0xFFFF0000, 6: 0xFFFF0000, 7: 0xFFFF0000, 2: 0}


def compile_source(src: Path, out: Path) -> None:
    out.parent.mkdir(parents=True, exist_ok=True)
    cmd = [sys.executable, str(ROOT / "tools/mwcc.py"), *srcmeta.compile_args(src), "-c", "-o", str(out), str(src)]
    p = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    if p.returncode:
        sys.stdout.write(p.stdout.decode(errors="replace"))
        raise SystemExit(2)


def object_function(obj: Path, name: str):
    f = ELFFile(obj.open("rb"))
    symtab = f.get_section_by_name(".symtab")
    syms = list(symtab.iter_symbols())
    fn = next((s for s in syms if s.name == name and s["st_info"]["type"] == "STT_FUNC"), None)
    if fn is None:
        return None
    sec_index = fn["st_shndx"]
    sec = f.get_section(sec_index)
    start, size = fn["st_value"], fn["st_size"]
    code = sec.data()[start:start + size]
    rels = {}
    for rs in f.iter_sections():
        if isinstance(rs, RelocationSection) and rs["sh_info"] == sec_index:
            for r in rs.iter_relocations():
                off = r["r_offset"]
                if start <= off < start + size:
                    s = syms[r["r_info_sym"]]
                    target = s.name
                    if s["st_info"]["type"] == "STT_SECTION":
                        target = "." + f.get_section(s["st_shndx"]).name.lstrip(".")
                    rels[off - start] = (r["r_info_type"], target)
    return code, rels


def compare(src: Path, key: str, obj: Path | None, quiet: bool) -> int:
    addr, size, name = disasm.lookup(key)
    if obj is None:
        obj = ROOT / "build/fncmp" / f"{os.getpid()}_{src.stem}.o"
        compile_source(src, obj)
        temp = True
    else:
        temp = False
    try:
        got = object_function(obj, name)
    finally:
        if temp:
            obj.unlink(missing_ok=True)
    if got is None:
        print(f"{name}: not defined in {src}")
        return 1
    code, rels = got
    orel = disasm.relocs()
    diffs, notes = 0, []
    n = max(size, len(code)) // 4
    lines = []
    for i in range(n):
        a = addr + i * 4
        want = disasm.word(a) if i * 4 < size else None
        have = int.from_bytes(code[i * 4:i * 4 + 4], "little") if i * 4 < len(code) else None
        ok = want == have
        r = rels.get(i * 4)
        o = orel.get(a)
        if not ok and want is not None and have is not None and r:
            m = MASK.get(r[0], 0xFFFFFFFF)
            ok = (want & m) == (have & m)
        if r or o:
            if bool(r) != bool(o) or r[0] != o[0]:
                ok = False
                notes.append(f"{i * 4:#06x}: reloc {r} vs original {o}")
            elif (r[1] != o[1] and not (r[1].startswith(".") or r[1].startswith("@"))
                  and not ("$" in r[1] and LOCAL_STATIC.sub("", r[1]) == LOCAL_STATIC.sub("", o[1]))):
                ok = False
                notes.append(f"{i * 4:#06x}: {r[1]} is not the original target {o[1]}")
        diffs += not ok
        if not quiet:
            def dis(w, va):
                return "" if w is None else rabbitizer.Instruction(w, vram=va, category=rabbitizer.InstrCategory.R5900).disassemble()
            lines.append(f"{'!' if not ok else ' '} {i * 4:04X} {dis(want, a):<40} {dis(have, a)}")
    if len(code) != size:
        notes.append(f"size {len(code):#x} vs original {size:#x}")
    status = "MATCH" if diffs == 0 and len(code) == size else f"DIFF {diffs} words"
    if not quiet:
        print("\n".join(lines))
        print("\n".join(notes))
    print(f"{name} 0x{addr:08X}: {status}")
    return 0 if status == "MATCH" else 1


def main() -> int:
    args = sys.argv[1:]
    if len([a for a in args if not a.startswith("-")]) < 2 or "-h" in args or "--help" in args:
        print(__doc__.strip())
        return 2
    quiet = "-q" in args
    args = [a for a in args if a != "-q"]
    obj = None
    if "--obj" in args:
        i = args.index("--obj")
        obj = Path(args[i + 1])
        del args[i:i + 2]
    return compare(Path(args[0]), args[1], obj, quiet)


if __name__ == "__main__":
    sys.exit(main())
