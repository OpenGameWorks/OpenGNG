#!/usr/bin/env python3
"""Compile a source and compare one function against SLUS_207.22.

Usage: fncmp.py [-q] [--obj OBJ] [--as REAL] SOURCE NAME|0xADDR
--as names the source file SOURCE stands in for (a permuter candidate, a scratch
copy): mwccps2 codegen depends on the source and object path lengths, so SOURCE
is compiled from a path as long as REAL into an object path as long as ninja's
build/obj/REAL.o.
Exit 0 = MATCH: every instruction word is identical outside relocated fields,
and every relocation in the compiled function names the same symbol that the
original executable's `.relmain` names at that offset, with the same in-place
addend (the offset into that symbol). Relocations against a
section symbol (`.rodata`, `.sdata`, literal pools) are reported as `DATA`
and accepted only when the original also relocates there against a local
`@N` literal or section; the full build confirms them. A function-local
static is named `name$N` with a translation-unit-wide counter N, which only a
complete unit reproduces; `name$N` therefore matches the original's `name$M`.
A file-local data target (a static, a string literal) must also hold the
original's bytes, the same test `link.py` applies before placing the function.
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
import link  # noqa: E402
import srcmeta  # noqa: E402

ROOT = disasm.ROOT
LOCAL_STATIC = re.compile(r"\$\d+$")
MASK = {4: 0xFC000000, 5: 0xFFFF0000, 6: 0xFFFF0000, 7: 0xFFFF0000, 2: 0}
GP = 0x2CBF70  # .reginfo ri_gp_value


def addend_ok(typ: int, have: int, want: int, s: int) -> bool:
    """The compiled in-place addend, applied to the original target, gives the original field."""
    lo = ((have & 0xFFFF) ^ 0x8000) - 0x8000
    if typ == 6:
        return (s + lo) & 0xFFFF == want & 0xFFFF
    if typ == 7:
        return (s + lo - GP) & 0xFFFF == want & 0xFFFF
    if typ == 4:
        return (((have & 0x3FFFFFF) << 2) + s) >> 2 & 0x3FFFFFF == want & 0x3FFFFFF
    # A HI16 addend depends on its LO16 partner, which the LO16 check covers.
    return True


def original_offset(a: int, want: int, ofull, symaddr) -> int | None:
    """Offset into its symbol of the original LO16 at a, paired with the preceding HI16 on the same base."""
    typ, idx = ofull[a]
    if typ != 6:
        return None
    base = (want >> 21) & 0x1F
    for back in range(a - 4, a - 0x200, -4):
        h = ofull.get(back)
        w = disasm.word(back)
        if h == (5, idx) and (w >> 16) & 0x1F == base:
            lo = ((want & 0xFFFF) ^ 0x8000) - 0x8000
            return ((w & 0xFFFF) << 16) + lo - symaddr[idx]
    return None


SCRATCH = "build/q/"


def scratch_path(length: int, suffix: str) -> str:
    """A per-process path relative to ROOT, padded to exactly `length` characters."""
    tag = f"{SCRATCH}{os.getpid():x}"
    pad = length - len(tag) - len(suffix)
    if pad < 0:
        raise SystemExit(f"fncmp: no {length}-character scratch path fits {tag}{suffix}")
    return tag + "_" * pad + suffix


def compile_as(src: Path, real: Path) -> Path:
    """Compile src exactly as ninja compiles real (a path relative to ROOT); return the object.

    mwccps2 codegen depends on the lengths of the source and -o path strings
    (GuardMove__6PlayerFv schedules differently with a shorter path), so the compile
    mirrors the ninja command: cwd ROOT, the source path and an object path of the
    same lengths as `real` and `build/obj/<real>.o`."""
    if src.resolve() == (ROOT / real).resolve():
        cpp = str(real)
    else:
        cpp = scratch_path(len(str(real)), real.suffix)
        (ROOT / cpp).parent.mkdir(parents=True, exist_ok=True)
        (ROOT / cpp).write_bytes(src.read_bytes())
    out = scratch_path(len(str(Path("build/obj") / real.with_suffix(".o"))), ".o")
    (ROOT / out).parent.mkdir(parents=True, exist_ok=True)
    cmd = [sys.executable, str(ROOT / "tools/mwcc.py"), *srcmeta.compile_args(src), "-c", "-o", out, cpp]
    try:
        p = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, cwd=ROOT)
    finally:
        if cpp != str(real):
            (ROOT / cpp).unlink(missing_ok=True)
    if p.returncode:
        sys.stdout.write(p.stdout.decode(errors="replace"))
        raise SystemExit(2)
    return ROOT / out


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


def local_data_diffs(obj: Path, name: str, addr: int) -> dict[int, str]:
    """Offsets whose file-local data target differs from the original's bytes, with a reason."""
    o = link.Obj(obj)
    got = o.function(name)
    if got is None:
        return {}
    _, rels = got
    image = disasm.image()[disasm.MAIN_OFF:disasm.MAIN_OFF + 0x1C4200]
    glob, byindex = link.symbol_table()
    orel = link.original_relocs()
    out = {}
    for off, typ, sym in rels:
        r = orel.get(addr + off)
        if r is None or r[0] != typ or sym["st_info"]["type"] == "STT_SECTION":
            continue
        if not (sym["st_info"]["bind"] == "STB_LOCAL" or sym.name.startswith("@")):
            continue
        if sym["st_info"]["type"] == "STT_FUNC":
            # A call to a static function is proven by name, as in link.py; the callee's
            # own bytes are checked when its unit is compared, not at each call site.
            continue
        oaddr, osize, oname = byindex[r[1]]
        if not link.local_matches(o, sym, oaddr, osize, addr, glob, byindex, orel, image):
            out[off] = f"local {sym.name} data differs from original {oname}"
    return out


def compare(src: Path, key: str, obj: Path | None, quiet: bool, real: Path | None = None) -> int:
    addr, size, name = disasm.lookup(key)
    if obj is None:
        obj = compile_as(src, (real or src).resolve().relative_to(ROOT))
        temp = True
    else:
        temp = False
    try:
        got = object_function(obj, name)
        bad_locals = local_data_diffs(obj, name, addr) if got else {}
    finally:
        if temp:
            obj.unlink(missing_ok=True)
    if got is None:
        print(f"{name}: not defined in {src}")
        return 1
    code, rels = got
    orel = disasm.relocs()
    ofull = disasm.relocs_full()
    symaddr = {}
    for line in (disasm.INFO / "symbols.tsv").read_text().splitlines()[1:]:
        f = line.split("\t")
        symaddr[int(f[0])] = int(f[1], 16)
    ld = link.linker_defined()
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
        if i * 4 in bad_locals:
            ok = False
            notes.append(f"{i * 4:#06x}: {bad_locals[i * 4]}")
        elif r and not o and r[1] in ld and have is not None and want is not None and r[0] in (5, 6):
            # A linker-script symbol: the original holds its address bits with no relocation.
            s = ld[r[1]]
            lo = ((have & 0xFFFF) ^ 0x8000) - 0x8000
            field = ((s + 0x8000) >> 16) if r[0] == 5 else (s + lo)
            ok = (want & 0xFFFF0000) == (have & 0xFFFF0000) and (want & 0xFFFF) == (field & 0xFFFF)
            if not ok:
                notes.append(f"{i * 4:#06x}: {r[1]} bits differ from the original's bare address")
        elif r or o:
            if bool(r) != bool(o) or r[0] != o[0]:
                ok = False
                notes.append(f"{i * 4:#06x}: reloc {r} vs original {o}")
            elif (r[1] != o[1] and not (r[1].startswith(".") or r[1].startswith("@"))
                  and not ("$" in r[1] and LOCAL_STATIC.sub("", r[1]) == LOCAL_STATIC.sub("", o[1]))):
                ok = False
                notes.append(f"{i * 4:#06x}: {r[1]} is not the original target {o[1]}")
            elif ok and have is not None and not r[1].startswith(".") and not addend_ok(r[0], have, want, symaddr[ofull[a][1]]):
                # Same symbol, different offset into it (a member of a global, an array element).
                ok = False
                off = original_offset(a, want, ofull, symaddr)
                hint = "" if off is None else f", original is {r[1]} + {off:#x}"
                notes.append(f"{i * 4:#06x}: addend into {r[1]} differs{hint}")
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
    real = None
    if "--as" in args:
        i = args.index("--as")
        real = Path(args[i + 1])
        del args[i:i + 2]
    return compare(Path(args[0]), args[1], obj, quiet, real)


if __name__ == "__main__":
    sys.exit(main())
