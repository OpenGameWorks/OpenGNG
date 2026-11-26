#!/usr/bin/env python3
"""Search source-level rewrites of one function body for a byte match.

    permute.py FILE 0xADDR [-j 4] [--iters 400] [--seconds 900] [--seed N] [--apply]

Register allocation and scheduling differences in CodeWarrior output follow
spelling choices the m2c draft cannot know: declaration order, statement
order inside a block, local types and signedness, operand order, `if (x)`
versus `if (x != 0)`, `x += 1` versus `x++`. decomp-permuter mutates a C AST
through pycparser and cannot parse the member functions most game code is
written as, so this search mutates the C++ text of the one body directly.

Each candidate is the whole source with the body replaced, written to
build/permuter/<ADDR>/ and scored by `tools/fncmp.py -q` (differing words;
MATCH is 0, a compile error is skipped). The search is a hill climb: a
candidate replaces the current body when it scores no worse, so equal-score
drift explores. The best body is kept in build/permuter/<ADDR>/best.cpp.

--apply writes a MATCH body into FILE, turns the DRAFT tag into FUNCTION,
drops its `// note:` line and reruns fncmp on FILE; FILE stays unchanged
unless that rerun matches.
"""

from __future__ import annotations

import sys

# tools/ stays off sys.path: tools/queue.py would shadow the stdlib queue module
# that ThreadPoolExecutor imports. A plain `python tools/permute.py` puts the
# script's directory first, so drop it before any import that reaches `queue`.
if sys.path and sys.path[0].rstrip("/").endswith("tools"):
    sys.path.pop(0)

import argparse
import random
import re
import subprocess
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
OUT = ROOT / "build/permuter"
DIFF = re.compile(r"(?:DIFF (\d+) words|(MATCH))\s*$")

KEYWORDS = {"return", "break", "continue", "goto", "case", "default", "if", "else", "for", "while", "do", "switch"}
TYPE_SWAPS = [
    ("unsigned int", "int"), ("unsigned short", "short"), ("unsigned char", "char"),
    ("signed char", "char"), ("int", "short"), ("int", "bool"), ("int", "char"), ("int", "long"),
    ("unsigned int", "unsigned char"), ("float", "double"),
]
DECL = re.compile(r"^(\s*)((?:const\s+)?(?:unsigned\s+|signed\s+)?(?:int|short|char|long|float|bool|u8|u16|u32|s8|s16|s32))(\s+\**\w+.*;)\s*$")


def find_body(text: str, addr: int) -> tuple[int, int]:
    """(start, end) offsets of the body braces' contents for the function tagged at addr."""
    for m in re.finditer(r"^\s*//\s*(?:FUNCTION|DRAFT):\s*0x0*([0-9A-Fa-f]+)\b.*$", text, re.M):
        if int(m.group(1), 16) != addr:
            continue
        i = text.index("{", m.end())
        depth, j = 1, i + 1
        while depth:
            c = text[j]
            depth += (c == "{") - (c == "}")
            j += 1
        return i + 1, j - 1
    raise SystemExit(f"no tag for 0x{addr:X}")


def simple(line: str) -> bool:
    s = line.strip()
    if not s.endswith(";") or "{" in s or "}" in s or s.startswith("//"):
        return False
    head = re.match(r"\w+", s)
    return not head or head.group(0) not in KEYWORDS


def indent(line: str) -> int:
    return len(line) - len(line.lstrip())


def m_swap(lines: list[str], rng: random.Random) -> bool:
    """Swap two adjacent simple statements of one block."""
    idx = [i for i in range(len(lines) - 1) if simple(lines[i]) and simple(lines[i + 1]) and indent(lines[i]) == indent(lines[i + 1])]
    if not idx:
        return False
    i = rng.choice(idx)
    lines[i], lines[i + 1] = lines[i + 1], lines[i]
    return True


def m_move(lines: list[str], rng: random.Random) -> bool:
    """Move a simple statement up or down past up to three siblings."""
    idx = [i for i, l in enumerate(lines) if simple(l)]
    if not idx:
        return False
    i = rng.choice(idx)
    k = i + rng.choice([-3, -2, 2, 3])
    if not (0 <= k < len(lines)):
        return False
    lo, hi = min(i, k), max(i, k)
    if not all(simple(lines[x]) and indent(lines[x]) == indent(lines[i]) for x in range(lo, hi + 1)):
        return False
    lines.insert(k, lines.pop(i))
    return True


def m_type(lines: list[str], rng: random.Random) -> bool:
    """Change the type of one local declaration."""
    idx = [i for i, l in enumerate(lines) if DECL.match(l)]
    if not idx:
        return False
    i = rng.choice(idx)
    m = DECL.match(lines[i])
    t = re.sub(r"\s+", " ", m.group(2).replace("const ", ""))
    opts = [b for a, b in TYPE_SWAPS if a == t] + [a for a, b in TYPE_SWAPS if b == t]
    if not opts:
        return False
    lines[i] = m.group(1) + rng.choice(opts) + m.group(3)
    return True


def m_split_init(lines: list[str], rng: random.Random) -> bool:
    """Split `T x = e;` into `T x;` and `x = e;`, or join them back."""
    idx = [i for i, l in enumerate(lines) if (m := DECL.match(l)) and "=" in m.group(3) and "," not in m.group(3)]
    if not idx:
        return False
    i = rng.choice(idx)
    m = DECL.match(lines[i])
    name, expr = m.group(3).split("=", 1)
    var = name.strip().lstrip("*")
    lines[i] = f"{m.group(1)}{m.group(2)}{name.rstrip()};"
    lines.insert(i + 1, f"{m.group(1)}{var} ={expr.rstrip()}")
    return True


def m_expr(lines: list[str], rng: random.Random) -> bool:
    """One expression-level rewrite on one line."""
    rules = [
        (r"\b([\w\->\.\[\]]+) != 0\b", r"\1"),
        (r"if \(!([\w\->\.\[\]]+)\)", r"if (\1 == 0)"),
        (r"if \(([\w\->\.\[\]]+) == 0\)", r"if (!\1)"),
        (r"if \(([\w\->\.\[\]]+)\)", r"if (\1 != 0)"),
        (r"\b([\w\->\.\[\]]+) (==|!=) ([\w\->\.\[\]]+)\b", r"\3 \2 \1"),
        (r"\b([\w\->\.\[\]]+) ([+*&|^]) ([\w\->\.\[\]]+)\b", r"\3 \2 \1"),
        (r"\b([\w\->\.\[\]]+) (<|>) ([\w\->\.\[\]]+)\b", lambda m: f"{m.group(3)} {'>' if m.group(2) == '<' else '<'} {m.group(1)}"),
        (r"\b(\w+)\+\+;", r"\1 += 1;"),
        (r"\b(\w+) \+= 1;", r"\1++;"),
        (r"\b(\w+)\+\+;", r"++\1;"),
        (r"\b(\w+) ([+\-*|&^]|<<|>>)= ([^;]+);", r"\1 = \1 \2 \3;"),
        (r"\b(\w+) = \1 ([+\-*|&^]|<<|>>) ([^;]+);", r"\1 \2= \3;"),
        (r"\(([\w\->\.\[\]]+) - ([\w\->\.\[\]]+)\)", r"(-\2 + \1)"),
    ]
    cand = [(i, p, r) for i, l in enumerate(lines) if not l.strip().startswith("//") for p, r in rules if re.search(p, l)]
    if not cand:
        return False
    i, p, r = rng.choice(cand)
    hits = list(re.finditer(p, lines[i]))
    h = rng.choice(hits)
    new = h.expand(r) if isinstance(r, str) else r(h)
    lines[i] = lines[i][:h.start()] + new + lines[i][h.end():]
    return True


def m_bool(lines: list[str], rng: random.Random) -> bool:
    """Respell one integer local as bool throughout the body.

    CodeWarrior loads a constant 1 stored to a bool with `daddiu`, to an int
    with `addiu`, and a bool compared with `== 0` gains an `andi 0xFF`; only
    the whole spelling (`bool f; if (!f) ... f = true;`) reproduces the bool
    code, so the declaration and every literal use change together.
    """
    idx = [i for i, l in enumerate(lines) if (m := DECL.match(l)) and m.group(2).strip() in ("int", "char", "unsigned char", "u8", "s32")
           and "," not in m.group(3) and re.match(r"\s*\w", m.group(3))]
    if not idx:
        return False
    i = rng.choice(idx)
    m = DECL.match(lines[i])
    var = re.match(r"\s*(\w+)", m.group(3)).group(1)
    lines[i] = m.group(1) + "bool" + m.group(3)
    v = re.escape(var)
    for k in range(len(lines)):
        if k == i:
            lines[k] = re.sub(rf"\b{v} = 0;", f"{var} = false;", re.sub(rf"\b{v} = 1;", f"{var} = true;", lines[k]))
            continue
        s = lines[k]
        s = re.sub(rf"\b{v} = 1;", f"{var} = true;", s)
        s = re.sub(rf"\b{v} = 0;", f"{var} = false;", s)
        s = re.sub(rf"\b{v} == 0\b", f"!{var}", s)
        s = re.sub(rf"\b{v} != 0\b", var, s)
        lines[k] = s
    return True


MUTATORS = [(m_swap, 4), (m_move, 2), (m_type, 2), (m_split_init, 1), (m_expr, 3), (m_bool, 1)]


def mutate(body: str, rng: random.Random) -> str:
    lines = body.split("\n")
    for _ in range(rng.choice([1, 1, 1, 2, 2, 3])):
        fns = [f for f, w in MUTATORS for _ in range(w)]
        for _ in range(8):
            if rng.choice(fns)(lines, rng):
                break
    return "\n".join(lines)


def score(src_text: str, body: tuple[int, int], new_body: str, path: Path, addr: int, real: Path) -> int | None:
    path.write_text(src_text[:body[0]] + new_body + src_text[body[1]:])
    p = subprocess.run([sys.executable, str(ROOT / "tools/fncmp.py"), "-q", "--as", str(real), str(path), f"0x{addr:X}"],
                       stdin=subprocess.DEVNULL, capture_output=True, text=True, timeout=300)
    m = DIFF.search(p.stdout.strip().splitlines()[-1] if p.stdout.strip() else "")
    if not m:
        return None
    return 0 if m.group(2) else int(m.group(1))


def apply(src: Path, addr: int, best: str) -> bool:
    text = src.read_text()
    a, b = find_body(text, addr)
    new = text[:a] + best + text[b:]
    new = re.sub(rf"^(\s*//\s*)DRAFT(:\s*0x0*{addr:X}\b.*\n)(\s*//\s*note:.*\n)?", r"\1FUNCTION\2", new, count=1, flags=re.M | re.I)
    src.write_text(new)
    p = subprocess.run([sys.executable, str(ROOT / "tools/fncmp.py"), "-q", str(src), f"0x{addr:X}"], stdin=subprocess.DEVNULL, capture_output=True, text=True)
    if p.returncode:
        src.write_text(text)
        return False
    return True


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("src", type=Path)
    ap.add_argument("addr", type=lambda s: int(s, 0))
    ap.add_argument("-j", type=int, default=4)
    ap.add_argument("--iters", type=int, default=400)
    ap.add_argument("--seconds", type=int, default=900)
    ap.add_argument("--seed", type=int)
    ap.add_argument("--apply", action="store_true")
    a = ap.parse_args()

    text = a.src.read_text()
    span = find_body(text, a.addr)
    out = OUT / f"{a.addr:08X}"
    out.mkdir(parents=True, exist_ok=True)
    rng = random.Random(a.seed)
    cur = best = text[span[0]:span[1]]
    base = score(text, span, cur, out / f"{a.src.stem}_0.cpp", a.addr, a.src)
    if base is None:
        print("base does not compile")
        return 2
    cur_s = best_s = base
    print(f"base {base}", flush=True)
    seen = {cur}
    deadline = time.time() + a.seconds
    n = 0
    with ThreadPoolExecutor(a.j) as pool:
        while n < a.iters and best_s and time.time() < deadline:
            cands = []
            for _ in range(a.j * 2):
                c = mutate(cur, rng)
                if c not in seen:
                    seen.add(c)
                    cands.append(c)
            if not cands:
                continue
            paths = [out / f"{a.src.stem}_{k % (a.j * 2) + 1}.cpp" for k in range(len(cands))]
            scores = list(pool.map(lambda cp: score(text, span, cp[0], cp[1], a.addr, a.src), zip(cands, paths)))
            n += len(cands)
            for c, s in sorted(((c, s) for c, s in zip(cands, scores) if s is not None), key=lambda x: x[1]):
                if s <= cur_s:
                    cur, cur_s = c, s
                if s < best_s:
                    best, best_s = c, s
                    (out / "best.cpp").write_text(text[:span[0]] + best + text[span[1]:])
                    print(f"iter {n}: {s}", flush=True)
                break
            if rng.random() < 0.05:  # restart from the best to leave a drift plateau
                cur, cur_s = best, best_s
    for f in out.glob(f"{a.src.stem}_*.cpp"):
        f.unlink()
    print(f"best {best_s} after {n} candidates (base {base})")
    if best_s == 0 and a.apply:
        ok = apply(a.src, a.addr, best)
        print("applied" if ok else "apply failed: FILE unchanged")
    return 0 if best_s == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
