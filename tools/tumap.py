#!/usr/bin/env python3
"""Assign every function of `main` to a translation unit (object file).

Evidence, strongest first:
  1. Local-symbol blocks. The linker writes each object's local symbols as one
     contiguous run of symtab indices (hash-ordered inside the run). A function
     relocating against local symbols i and j therefore proves [i, j] is one
     object; merging those intervals recovers object blocks, and the functions
     referencing a block (plus its local functions) give the object's text span.
  2. A block's own `__FILE__` string literals (`@N` -> "PWorld.cpp") or its
     `__sinit_<file>` name the file. Header names ("Font.h") come from asserts in
     inline code and only name a block that has no source-file string.
  3. gcc objects (the SCE SDK) carry `.text` section markers: `sdk/<VRAM>.c`.
  4. Remaining gaps: a gap whose functions all belong to one class with an
     embedded filename takes that file; otherwise `unk_<VRAM>.cpp`, unattributed.

Writes config/tus.tsv: start end category file nfuncs evidence
"""

from __future__ import annotations

import re
import sys
from bisect import bisect_right
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import disasm  # noqa: E402

ROOT = disasm.ROOT
TEXT_END = 0x218300
SRC = re.compile(r"[\w.]+\.(cpp|c|h)")


def owner_class(name: str) -> str | None:
    i = name.find("__", 1)
    rest = name[i + 2:] if i > 0 else ""
    if rest.startswith("Q"):
        rest = rest[2:]  # nested: the outermost class names the file
    m = re.match(r"(\d+)", rest)
    return rest[len(m.group(1)):len(m.group(1)) + int(m.group(1))] if m else None


def cstring(addr: int) -> str | None:
    off = addr - disasm.MAIN_VA + disasm.MAIN_OFF
    raw = disasm.image()[off:off + 64].split(b"\0", 1)[0]
    try:
        return raw.decode("ascii")
    except UnicodeDecodeError:
        return None


def main() -> int:
    filenames = set((ROOT / "build/info/filenames.txt").read_text().split())
    stems = {f.rsplit(".", 1)[0]: f for f in filenames if not f.endswith(".h")}
    info = {}
    for line in (ROOT / "config/symbols.tsv").read_text().splitlines()[1:]:
        i, a, s, t, b, sh, _, n = line.split("\t")
        info[int(i)] = (int(a, 16), t, b, sh, n)
    fs = disasm.functions()
    st = [f[0] for f in fs]
    nf = len(fs)

    # 1. local-symbol index intervals per function
    refs: dict[int, set[int]] = {}
    for off, (_, idx) in disasm.relocs_full().items():
        a, t, b, _, _ = info[idx]
        if off < TEXT_END and b == "STB_LOCAL" and t != "STT_SECTION":
            refs.setdefault(bisect_right(st, off) - 1, set()).add(idx)
    for idx, (a, t, b, _, _) in info.items():
        if b == "STB_LOCAL" and t == "STT_FUNC" and a < TEXT_END:
            i = bisect_right(st, a) - 1
            if i >= 0 and fs[i][0] == a:
                refs.setdefault(i, set()).add(idx)
    blocks: list[list[int]] = []
    for lo, hi in sorted((min(v), max(v)) for v in refs.values()):
        if blocks and lo <= blocks[-1][1]:
            blocks[-1][1] = max(blocks[-1][1], hi)
        else:
            blocks.append([lo, hi])
    bstart = [b[0] for b in blocks]

    # 2. block names
    def block_name(k: int) -> tuple[str | None, str]:
        srcs, hdrs, sinit = set(), set(), set()
        for idx in range(blocks[k][0], blocks[k][1] + 1):
            a, t, b, _, n = info[idx]
            if n.startswith("__sinit_"):
                sinit.add(n[len("__sinit_"):])
            elif n.startswith("@") and 0x252700 <= a < 0x2C4200 and (s := cstring(a)) and SRC.fullmatch(s):
                (hdrs if s.endswith(".h") else srcs).add(s)
        if len(srcs) == 1:
            return srcs.pop(), "file-string"
        if sinit:
            return sorted(sinit)[0], "sinit"
        if len(srcs) > 1:
            return None, "conflict:" + ",".join(sorted(srcs))
        return None, ("headers:" + ",".join(sorted(hdrs))) if hdrs else ""

    label: list[tuple[str, str, str] | None] = [None] * nf
    spans: dict[int, list[int]] = {}
    for i, v in refs.items():
        k = bisect_right(bstart, min(v)) - 1
        spans.setdefault(k, []).append(i)
    for k, members in spans.items():
        name, ev = block_name(k)
        lo, hi = min(members), max(members)
        if name is None:
            # class anchors inside the object's own span
            cls = Counter(stems[c] for i in range(lo, hi + 1) if (c := owner_class(fs[i][2])) in stems)
            if cls:
                name, ev = cls.most_common(1)[0][0], f"class-in-object {ev}".strip()
        cat = "game" if name else "unknown"
        name = name or f"unk_{fs[lo][0]:08X}.cpp"
        for i in range(lo, hi + 1):
            if label[i] is None:
                label[i] = (cat, name, ev or "local-block")

    # 3. gcc objects
    markers = sorted(a for a, t, b, sh, n in info.values() if t == "STT_SECTION" and n == ".text" and sh == "4")
    for i, (a, _, n) in enumerate(fs):
        j = bisect_right(markers, a) - 1
        if j >= 0 and (label[i] is None or label[i][1].startswith("unk_")):
            nxt = markers[j + 1] if j + 1 < len(markers) else TEXT_END
            # a marker owns the functions up to the next marker or the next MW-labelled function
            if all(label[k] is None or label[k][0] == "sdk" for k in range(bisect_right(st, markers[j]) - 1, i)) and a < nxt:
                label[i] = ("sdk", f"sdk/{markers[j]:08X}.c", "gcc-marker")
    # 4. gaps. An object is contiguous, so a gap function belongs to the previous or
    # the next object; each side grows into the gap while the function's class
    # already occurs in that object.
    classes: dict[str, set[str]] = {}
    for (a, _, n), l in zip(fs, label):
        if l and (c := owner_class(n)):
            classes.setdefault(l[1], set()).add(c)
    i = 0
    while i < nf:
        if label[i] is not None:
            i += 1
            continue
        j = i
        while j < nf and label[j] is None:
            j += 1
        if i and label[i - 1][0] != "sdk":
            p = label[i - 1]
            while i < j and owner_class(fs[i][2]) in classes.get(p[1], ()):
                label[i] = (p[0], p[1], "class-extends-prev")
                i += 1
        if j < nf and label[j][0] != "sdk":
            q = label[j]
            k = j - 1
            while k >= i and owner_class(fs[k][2]) in classes.get(q[1], ()):
                label[k] = (q[0], q[1], "class-extends-next")
                k -= 1
        i = j
    i = 0
    while i < nf:
        if label[i] is not None:
            i += 1
            continue
        j = i
        while j < nf and label[j] is None:
            j += 1
        prev = label[i - 1] if i else None
        nxt = label[j] if j < nf else None
        cls = {stems.get(owner_class(fs[k][2]) or "") for k in range(i, j)}
        if prev and nxt and prev[1] == nxt[1]:
            lab = (prev[0], prev[1], "between-same-file")
        elif len(cls) == 1 and None not in cls:
            lab = ("game", cls.pop(), "class-anchor")
        else:
            lab = ("unknown", f"unk_{fs[i][0]:08X}.cpp", "gap")
        for k in range(i, j):
            label[k] = lab
        i = j

    rows = []
    for (a, s, n), (cat, f, ev) in zip(fs, label):
        if rows and rows[-1][3] == f and rows[-1][2] == cat:
            rows[-1][1] = a + s
            rows[-1][4] += 1
        else:
            rows.append([a, a + s, cat, f, 1, ev])
    out = ROOT / "config/tus.tsv"
    with out.open("w") as w:
        w.write("start\tend\tcategory\tfile\tnfuncs\tevidence\n")
        for a, b, c, f, k, ev in rows:
            w.write(f"{a:08X}\t{b:08X}\t{c}\t{f}\t{k}\t{ev}\n")
    runs = Counter(r[3] for r in rows)
    split = sorted(f for f, c in runs.items() if c > 1 and not f.startswith("unk_"))
    fc = Counter()
    for r in rows:
        fc[r[2]] += r[4]
    print(f"{len(rows)} runs; functions {dict(fc)}; files split into several runs: {len(split)} {split[:12]}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
