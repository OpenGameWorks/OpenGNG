#!/usr/bin/env python3
"""Name the source that claims an address, or list duplicate claims.

Usage: claimed.py 0xADDR ...   prints `0xADDR free` or `0xADDR KIND FILE:LINE`
       claimed.py              prints addresses claimed more than once (empty = clean)
"""

from __future__ import annotations

import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import srcmeta  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent


def claims() -> dict[int, list[str]]:
    out: dict[int, list[str]] = defaultdict(list)
    for s in sorted((p for p in (ROOT / "src").rglob("*.c*") if p.suffix in (".c", ".cpp"))):
        # Editors write atomic saves as `X.cpp.tmp.<pid>.<hash>`; only real
        # sources claim addresses.
        if "scratch" in s.relative_to(ROOT).parts or s.suffix not in (".c", ".cpp"):
            continue
        for kind, addr, _, line in srcmeta.tags(s):
            out[addr].append(f"{kind} {s.relative_to(ROOT)}:{line}")
    return out


def main() -> int:
    c = claims()
    if len(sys.argv) > 1:
        for a in sys.argv[1:]:
            v = c.get(int(a, 16))
            print(f"0x{int(a, 16):08X} {'; '.join(v) if v else 'free'}")
        return 0
    bad = {a: v for a, v in c.items() if len(v) > 1}
    for a, v in sorted(bad.items()):
        print(f"0x{a:08X} {'; '.join(v)}")
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
