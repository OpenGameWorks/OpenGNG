#!/usr/bin/env python3
"""Print an m2c C++ draft of one function, followed by its literal values.

Usage: draft.py 0xADDR|NAME [m2c options]
Runs m2c (target mipsee-mwcc-c++) on `disasm.py --m2c` output. The draft is
a starting point: m2c names members `unkXX` and types callees `?`; the mangled
name gives the real signature, and `# literal` lines give float and string
pool values that the source writes as plain literals.
"""

from __future__ import annotations

import os
import subprocess
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import disasm  # noqa: E402

ROOT = disasm.ROOT
# m2c is vendored by the sibling GodHand checkout until OpenGNG pins its own copy.
M2C = Path(os.environ.get("M2C", ROOT.parent / "GodHand/tools/ext/m2c/m2c.py"))


def main() -> int:
    a, s, n = disasm.lookup(sys.argv[1])
    lines = disasm.render_m2c(n, a, s)
    with tempfile.NamedTemporaryFile("w", suffix=".s", delete=False) as f:
        f.write("\n".join(l for l in lines if not l.startswith("#")) + "\n")
    try:
        r = subprocess.run([sys.executable, str(M2C), "-t", "mipsee-mwcc-c++", *sys.argv[2:], f.name],
                           capture_output=True, text=True, timeout=120)
    finally:
        os.unlink(f.name)
    sys.stdout.write(r.stdout or r.stderr)
    for l in lines:
        if l.startswith("# literal"):
            print("//", l[2:])
    return r.returncode


if __name__ == "__main__":
    sys.exit(main())
