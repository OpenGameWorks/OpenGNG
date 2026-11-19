#!/usr/bin/env python3
"""Assign every function of `main` to a translation unit.

Evidence, in priority order:
  1. gcc-built objects (the SCE SDK) carry `.text` section symbols in the
     final symtab; each marker starts an SDK object `sdk/<VRAM>.c`.
  2. A function whose mangled class `__<len><Class>` equals the stem of a
     filename the executable embeds (assert/__FILE__ strings, e.g.
     `PWorld.cpp`) anchors that file. A file spans from its first to its
     last anchor; MW links each object contiguously, so unanchored
     functions inside the span (helpers, static functions, other classes
     defined in the same file) belong to it.
  3. `__sinit_<file>` names the file of a static initialiser.
  4. Remaining runs between files become `unk_<VRAM>.cpp` units for later
     attribution.

Writes config/tus.tsv: start end category file nfuncs
"""

from __future__ import annotations

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
CLASS = re.compile(r"__(?:F|C?(?:Q\d)?)?(\d+)([A-Za-z_]\w*)")


def owner_class(name: str) -> str | None:
    i = name.find("__", 1)
    if i <= 0:
        return None
    rest = name[i + 2:]
    if rest.startswith("Q"):
        rest = rest[2:]  # nested: outermost class names the file
    m = re.match(r"(\d+)", rest)
    if not m:
        return None
    n = int(m.group(1))
    return rest[len(m.group(1)):len(m.group(1)) + n]


def main() -> int:
    files = {l.strip().rsplit(".", 1)[0]: l.strip() for l in (ROOT / "build/info/filenames.txt").read_text().split()}
    sdk_starts = set()
    for line in (ROOT / "config/symbols.tsv").read_text().splitlines()[1:]:
        _, a, _, t, _, sh, _, n = line.split("\t")
        if t == "STT_SECTION" and n == ".text" and sh == "4":
            sdk_starts.add(int(a, 16))
    funcs = []
    for line in (ROOT / "config/units.tsv").read_text().splitlines()[1:]:
        a, b, k, n = line.split("\t")
        if k == "func":
            funcs.append((int(a, 16), int(b, 16), n))
    # SDK objects: from each .text marker up to the next marker or first MW anchor.
    label = [None] * len(funcs)
    for i, (a, b, n) in enumerate(funcs):
        if n.startswith("__sinit_"):
            label[i] = ("game", n[len("__sinit_"):])
            continue
        c = owner_class(n)
        if c and c in files:
            label[i] = ("game", files[c])
    first = {}
    last = {}
    for i, l in enumerate(label):
        if l and not funcs[i][2].startswith("__sinit_"):
            first.setdefault(l[1], i)
            last[l[1]] = i
    for f in first:
        for i in range(first[f], last[f] + 1):
            if label[i] is None:
                label[i] = ("game", f)
    # gcc objects
    cur = None
    for i, (a, b, n) in enumerate(funcs):
        marker = max((s for s in sdk_starts if s <= a), default=None)
        if label[i] is None and marker is not None and (cur is None or marker != cur[1]):
            pass
        if label[i] is None and marker is not None:
            # the object started at the marker and has not been interrupted by game code
            j = i - 1
            while j >= 0 and funcs[j][0] >= marker and label[j] and label[j][0] == "sdk":
                j -= 1
            if all(not (label[k] and label[k][0] == "game") for k in range(j + 1, i)) and a - marker < 0x20000:
                label[i] = ("sdk", f"sdk/{marker:08X}.c")
    for i, (a, b, n) in enumerate(funcs):
        if label[i] is None:
            prev = label[i - 1] if i else None
            if prev and prev[1].startswith("unk_"):
                label[i] = prev
            else:
                label[i] = ("unknown", f"unk_{a:08X}.cpp")
    rows = []
    for i, (a, b, n) in enumerate(funcs):
        cat, f = label[i]
        if rows and rows[-1][3] == f and rows[-1][2] == cat:
            rows[-1][1] = b
            rows[-1][4] += 1
        else:
            rows.append([a, b, cat, f, 1])
    out = ROOT / "config/tus.tsv"
    with out.open("w") as w:
        w.write("start\tend\tcategory\tfile\tnfuncs\n")
        for a, b, c, f, k in rows:
            w.write(f"{a:08X}\t{b:08X}\t{c}\t{f}\t{k}\n")
    from collections import Counter
    cnt = Counter(r[2] for r in rows)
    fc = Counter()
    for r in rows:
        fc[r[2]] += r[4]
    print(f"{len(rows)} TU runs {dict(cnt)}; functions {dict(fc)} -> {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
