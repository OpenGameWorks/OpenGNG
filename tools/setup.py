#!/usr/bin/env python3
"""Prepare a fresh checkout from one user-supplied SLUS-20722 disc image, then build it.

The disc is the only input the repository cannot ship: it supplies the original
executable (bytes for unmatched functions, symbols, relocations) and the assets.
The image is opened read-only and never modified. A .chd is converted with
`chdman` into build/disc/ first; DVD-type CHDs become a 2048-byte .iso, CD-type
CHDs a raw .bin that tools/iso.py reads directly.

Steps: convert (CHD only), check the image SHA-1 (a mismatch only warns: a
re-ripped image can differ in padding yet carry the same files), extract the
files into original/extracted/, require the executable's SHA-1 to equal
config/SLUS_207.22.sha1, write build/info/ (symbols, relocations, source file
names), run tools/configure.py, then `ninja` unless --no-build.

Usage: setup.py IMAGE.iso|IMAGE.chd|IMAGE.bin [--no-build]
"""

from __future__ import annotations

import hashlib
import re
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import iso  # noqa: E402

# Redump SLUS-20722 (USA), 2048-byte user data.
ISO_SHA1 = "2825e10c0ecf5e5d2884ef2893f0bef900bd25c0"
OUT = ROOT / "original/extracted"
INFO = ROOT / "build/info"
# Source file names come from the executable's own __FILE__ strings.
SOURCE_NAME = re.compile(rb"[A-Za-z0-9_./\\:-]+\.(?:cpp|c)")


def sha1(path: Path) -> str:
    h = hashlib.sha1()
    with path.open("rb") as f:
        while chunk := f.read(1 << 20):
            h.update(chunk)
    return h.hexdigest()


def from_chd(chd: Path) -> Path:
    tool = shutil.which("chdman") or sys.exit("setup: converting a .chd needs chdman (MAME tools)")
    disc = ROOT / "build/disc"
    disc.mkdir(parents=True, exist_ok=True)
    out = disc / f"{chd.stem}.iso"
    if out.exists():
        return out
    if subprocess.call([tool, "extractdvd", "-i", str(chd), "-o", str(out)]) == 0:
        return out
    # A CD-type CHD refuses extractdvd; its raw sectors are readable as they are.
    out.unlink(missing_ok=True)
    binf = disc / f"{chd.stem}.bin"
    if subprocess.call([tool, "extractcd", "-f", "-i", str(chd), "-o", str(disc / f"{chd.stem}.cue"),
                        "-ob", str(binf)]):
        sys.exit(f"setup: chdman could not extract {chd}")
    return binf


def source_names(elf: bytes) -> list[str]:
    """Basenames of the __FILE__ strings (`strings` runs of 4+ printable bytes)."""
    names = set()
    for run in re.findall(rb"[\x20-\x7e]{4,}", elf):
        if SOURCE_NAME.fullmatch(run):
            base = re.split(r"[/\\:]", run.decode())[-1]
            if not base.startswith(".") and "sinit" not in base:
                names.add(base)
    return sorted(names)


def run(*cmd: str) -> None:
    if subprocess.call(list(cmd), cwd=ROOT):
        sys.exit(f"setup: {' '.join(cmd)} failed")


def main() -> int:
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    if len(args) != 1:
        print(__doc__.strip())
        return 2
    src = Path(args[0]).resolve()
    if not src.is_file():
        sys.exit(f"setup: {src} not found")
    image = from_chd(src) if src.suffix.lower() == ".chd" else src
    if image.stat().st_size % 2048 == 0 and image.stat().st_size % 2352 != 0:
        got = sha1(image)
        if got != ISO_SHA1:
            print(f"setup: warning: image SHA-1 {got}, expected {ISO_SHA1}; checking the executable instead", flush=True)
    print(f"setup: extracted {iso.extract(image, OUT)} new files into {OUT.relative_to(ROOT)}", flush=True)
    elf = OUT / "SLUS_207.22"
    want = (ROOT / "config/SLUS_207.22.sha1").read_text().split()[0]
    if not elf.is_file() or sha1(elf) != want:
        sys.exit(f"setup: {elf.name} is missing or its SHA-1 is not {want}: not the USA SLUS-20722 disc")
    run(sys.executable, "tools/elfinfo.py", str(elf), str(INFO))
    (INFO / "filenames.txt").write_text("".join(f"{n}\n" for n in source_names(elf.read_bytes())))
    run(sys.executable, "tools/configure.py")
    if "--no-build" not in sys.argv:
        run(shutil.which("ninja") or sys.exit("setup: needs ninja"))
    return 0


if __name__ == "__main__":
    sys.exit(main())
