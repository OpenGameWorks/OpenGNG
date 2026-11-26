#!/usr/bin/env python3
"""Write build.ninja: compile every source, link `main`, pack the ELF, verify SHA-1.

Sources are src/**/*.cpp and src/**/*.c. Each compiles with the compiler and
flags srcmeta.py selects (MW CodeWarrior PS2 at -O4 unless the source's
header says otherwise). The final step prints `build/SLUS_207.22: OK` only
when the rebuilt executable's SHA-1 equals config/SLUS_207.22.sha1.
"""

from __future__ import annotations

import shlex
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import srcmeta  # noqa: E402


def main() -> int:
    py = ".venv/bin/python"
    srcs = sorted(p for ext in ("*.cpp", "*.c") for p in (ROOT / "src").rglob(ext) if "scratch" not in p.parts)
    lines = [
        "ninja_required_version = 1.10",
        f"py = {py}",
        "rule cc",
        "  command = $py tools/mwcc.py $args -c -o $out $in > $out.log 2>&1 || (cat $out.log; exit 1)",
        "  description = MWCC $in",
        "rule link",
        "  command = $py tools/link.py build/main.bin $pairs",
        "  description = LINK $out",
        "rule pack",
        "  command = $py tools/elfpack.py pack $in $out",
        "  description = PACK $out",
        "rule check",
        "  command = $py tools/check.py $in && touch $out",
        "  description = CHECK $in",
    ]
    objs, pairs = [], []
    for s in srcs:
        rel = s.relative_to(ROOT)
        o = Path("build/obj") / rel.with_suffix(".o")
        args = " ".join(shlex.quote(a) for a in srcmeta.compile_args(s))
        lines += [f"build {o}: cc {rel} | tools/mwcc.py tools/srcmeta.py", f"  args = {args}"]
        objs.append(str(o))
        pairs.append(f"{o}:{rel}")
    deps = "config/units.tsv config/symbols.tsv config/relocs.tsv tools/link.py"
    lines += [
        f"build build/main.bin build/link.tsv: link {' '.join(objs)} | {deps}",
        f"  pairs = {' '.join(pairs)}",
        "build build/SLUS_207.22: pack build/main.bin | config/elf_layout.json tools/elfpack.py",
        "build build/SLUS_207.22.ok: check build/SLUS_207.22 | config/SLUS_207.22.sha1",
    ]
    default = ["build/SLUS_207.22.ok"]
    # SCE archives are user-supplied (never committed); with them present the build also
    # verifies that every located library member is linked unchanged.
    if (ROOT / "ext/sce").is_dir():
        lines += [
            "rule sdklink",
            "  command = $py tools/sdklink.py > build/sdk_link.log",
            "  description = SDKLINK verify library members",
            "build build/sdk_link.tsv: sdklink | config/sdk.tsv tools/sdklink.py tools/sdkmatch.py",
        ]
        default.append("build/sdk_link.tsv")
    lines.append("default " + " ".join(default))
    (ROOT / "build.ninja").write_text("\n".join(lines) + "\n")
    print(f"configure: {len(srcs)} sources")
    return 0


if __name__ == "__main__":
    sys.exit(main())
