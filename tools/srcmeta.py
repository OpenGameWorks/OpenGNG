"""Per-source compiler selection and annotation parsing.

Game code is MW CodeWarrior PS2 C++ at `-O4` (scheduling and register use of
0x19A730 PWorld::InitFrustrum match it exactly; `-O2` leaves delay slots
empty). A source overrides the defaults with comment lines within its first
four lines:

    // COMPILER: mwcps2-3.0-011126
    // FLAGS: -inline off

`// FUNCTION: 0xADDR NAME` above a definition claims a matched function;
`// DRAFT: 0xADDR NAME` claims an unmatched draft kept under
`#ifdef NONMATCHING`.
"""

from __future__ import annotations

import re
from pathlib import Path

DEFAULT_COMPILER = "mwcps2-3.0.3-020716"
DEFAULT_FLAGS = ["-O4", "-Iinclude", "-Isrc/game"]
TAG = re.compile(r"^\s*//\s*(FUNCTION|DRAFT):\s*(0x[0-9A-Fa-f]+)(?:\s+(\S+))?")


def header(src: Path) -> dict[str, str]:
    out = {}
    for line in src.read_text(errors="replace").splitlines()[:4]:
        m = re.match(r"\s*//\s*(COMPILER|FLAGS):\s*(.*)", line)
        if m:
            out[m.group(1)] = m.group(2).strip()
    return out


def compile_args(src: Path) -> list[str]:
    h = header(src)
    args = ["--compiler", h.get("COMPILER", DEFAULT_COMPILER), *DEFAULT_FLAGS]
    if "FLAGS" in h:
        args += h["FLAGS"].split()
    return args


def tags(src: Path) -> list[tuple[str, int, str | None, int]]:
    """(kind, address, name, line) for each FUNCTION/DRAFT tag in src."""
    out = []
    for i, line in enumerate(src.read_text(errors="replace").splitlines(), 1):
        m = TAG.match(line)
        if m:
            out.append((m.group(1), int(m.group(2), 16), m.group(3), i))
    return out
