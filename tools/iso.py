#!/usr/bin/env python3
"""Read-only ISO9660 reader for the Maximo: The Army of Zin disc image.

The disc is opened read-only and never written, so the user's image stays
unaltered. 2048-byte user-data images (.iso, chdman extractdvd) and raw
2352-byte sector images (chdman extractcd .bin, Mode 1 or Mode 2 Form 1) are
both accepted; the sector layout is detected from the volume descriptor.

Usage: iso.py list IMAGE
       iso.py extract IMAGE OUTDIR
"""

from __future__ import annotations

import struct
import sys
from pathlib import Path

USER = 2048


class Disc:
    def __init__(self, path: Path):
        self.f = path.open("rb")
        for stride, skip in ((2048, 0), (2352, 16), (2352, 24)):
            self.stride, self.skip = stride, skip
            if self.sector(16)[1:6] == b"CD001":
                break
        else:
            raise SystemExit(f"iso: {path} has no ISO9660 volume descriptor")
        pvd = self.sector(16)
        root = pvd[156:190]
        self.root = (struct.unpack_from("<I", root, 2)[0], struct.unpack_from("<I", root, 10)[0])

    def sector(self, lba: int) -> bytes:
        self.f.seek(lba * self.stride + self.skip)
        return self.f.read(USER)

    def read(self, lba: int, size: int) -> bytes:
        out = bytearray()
        while len(out) < size:
            out += self.sector(lba)
            lba += 1
        return bytes(out[:size])

    def records(self, lba: int, size: int):
        data = self.read(lba, size)
        pos = 0
        while pos < len(data):
            length = data[pos]
            if length == 0:  # records never straddle sectors
                pos = (pos // USER + 1) * USER
                continue
            rec = data[pos:pos + length]
            name = rec[33:33 + rec[32]].decode("ascii", "replace")
            if name not in ("\x00", "\x01"):
                yield name.split(";")[0], struct.unpack_from("<I", rec, 2)[0], struct.unpack_from("<I", rec, 10)[0], bool(rec[25] & 2)
            pos += length

    def walk(self, lba: int | None = None, size: int | None = None, prefix: str = ""):
        """Yield (path, lba, size) for every file below a directory (the root by default)."""
        lba, size = (lba, size) if lba is not None else self.root
        for name, l, s, is_dir in self.records(lba, size):
            if is_dir:
                yield from self.walk(l, s, f"{prefix}{name}/")
            else:
                yield f"{prefix}{name}", l, s


def extract(image: Path, out: Path) -> int:
    """Copy every file of the disc to OUT; a file already present with the same size is kept."""
    disc = Disc(image)
    n = 0
    for path, lba, size in disc.walk():
        dst = out / path
        if dst.is_file() and dst.stat().st_size == size:
            continue
        dst.parent.mkdir(parents=True, exist_ok=True)
        with dst.open("wb") as w:
            done = 0
            while done < size:
                chunk = min(size - done, 512 * USER)
                w.write(disc.read(lba + done // USER, chunk))
                done += chunk
        n += 1
    return n


def main() -> int:
    if len(sys.argv) < 3 or sys.argv[1] not in ("list", "extract"):
        print(__doc__.strip())
        return 2
    if sys.argv[1] == "list":
        for path, lba, size in Disc(Path(sys.argv[2])).walk():
            print(f"{lba:8} {size:10} {path}")
        return 0
    print(f"iso: extracted {extract(Path(sys.argv[2]), Path(sys.argv[3]))} files")
    return 0


if __name__ == "__main__":
    sys.exit(main())
