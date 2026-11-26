#!/usr/bin/env python3
"""Prepare a fresh checkout from one Maximo: The Army of Zin (USA, SLUS-20722) disc image.

The image is only read, never written. A .chd is first converted to an ISO in
build/disc/ with chdman (extractdvd, falling back to extractcd for a CD-type
CHD); an .iso, .bin or 2352-byte raw image is read directly. Steps:

  1. hash the image (a mismatch with the known Redump ISO only warns: other
     dumps of the same disc carry the same executable)
  2. extract every file to original/extracted/ (tools/iso.py)
  3. require SLUS_207.22 to equal config/SLUS_207.22.sha1 (hard stop otherwise)
  4. write build/info/symbols.tsv, relocs.tsv (tools/elfinfo.py) and filenames.txt
  5. write build.ninja (tools/configure.py)

Then `ninja` must print `build/SLUS_207.22: OK`.

Usage: setup.py IMAGE.(iso|chd|bin)
"""

from __future__ import annotations

import hashlib
import re
import shutil
import subprocess
import sys
from pathlib import Path

print = __import__("functools").partial(print, flush=True)  # keep order with subprocess output
ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import iso  # noqa: E402

ISO_SHA1 = "2825e10c0ecf5e5d2884ef2893f0bef900bd25c0"  # Redump SLUS-20722, 1232011264 bytes
OUT = ROOT / "original/extracted"
INFO = ROOT / "build/info"
# The executable's __FILE__ strings name the game's translation units (config/tus.tsv evidence).
SOURCE_NAME = re.compile(rb"[A-Za-z0-9_./\\:-]+\.(?:cpp|c)")


def sha1(path: Path) -> str:
    h = hashlib.sha1()
    with path.open("rb") as f:
        while chunk := f.read(1 << 20):
            h.update(chunk)
    return h.hexdigest()


def from_chd(chd: Path) -> Path:
    chdman = shutil.which("chdman")
    if not chdman:
        raise SystemExit("setup: a .chd needs chdman (MAME tools) on PATH")
    disc = ROOT / "build/disc"
    disc.mkdir(parents=True, exist_ok=True)
    out = disc / f"{chd.stem}.iso"
    if out.exists():
        return out
    tmp = out.with_suffix(".part")
    tmp.unlink(missing_ok=True)
    if subprocess.call([chdman, "extractdvd", "-i", str(chd), "-o", str(tmp)]) == 0:
        tmp.rename(out)
        return out
    # A CD-type CHD yields raw 2352-byte sectors; tools/iso.py reads them directly.
    tmp.unlink(missing_ok=True)
    out = disc / f"{chd.stem}.bin"
    cue = out.with_suffix(".cue")
    if subprocess.call([chdman, "extractcd", "-i", str(chd), "-o", str(cue), "-ob", str(out)]):
        raise SystemExit(f"setup: chdman could not extract {chd}")
    return out


def filenames(elf: Path) -> list[str]:
    names = set()
    # Whole printable strings only (as `strings` splits them): a name embedded in a longer
    # message, such as a format string, is not a __FILE__ value.
    for m in re.finditer(rb"[\x20-\x7e\t]{4,}", elf.read_bytes()):
        if not SOURCE_NAME.fullmatch(m.group()):
            continue
        base = re.split(r"[\\/]", m.group().decode())[-1]
        if not base.startswith(".") and "sinit" not in base:
            names.add(base)
    return sorted(names)


def main() -> int:
    if len(sys.argv) != 2 or sys.argv[1] in ("-h", "--help"):
        print(__doc__.strip())
        return 2
    src = Path(sys.argv[1]).resolve()
    if not src.is_file():
        raise SystemExit(f"setup: {src} not found")
    image = from_chd(src) if src.suffix.lower() == ".chd" else src
    digest = sha1(image)
    if digest == ISO_SHA1:
        print(f"setup: {image.name} is the known SLUS-20722 ISO")
    else:
        print(f"setup: warning: {image.name} SHA-1 {digest} is not the known ISO {ISO_SHA1}; checking its executable")
    print(f"setup: extracted {iso.extract(image, OUT)} new files to {OUT.relative_to(ROOT)}")
    elf = OUT / "SLUS_207.22"
    want = (ROOT / "config/SLUS_207.22.sha1").read_text().split()[0]
    if not elf.is_file() or sha1(elf) != want:
        raise SystemExit(f"setup: {elf.relative_to(ROOT)} is missing or differs from SHA-1 {want}; this is not SLUS-20722")
    py = sys.executable
    subprocess.check_call([py, str(ROOT / "tools/elfinfo.py"), str(elf), str(INFO)])
    (INFO / "filenames.txt").write_text("".join(f"{n}\n" for n in filenames(elf)))
    subprocess.check_call([py, str(ROOT / "tools/configure.py")], cwd=ROOT)
    print("setup: ready; run `ninja` (expects `build/SLUS_207.22: OK`)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
