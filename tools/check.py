#!/usr/bin/env python3
"""Print `PATH: OK` when the file's SHA-1 equals config/SLUS_207.22.sha1, else FAILED (exit 1)."""

import hashlib
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
path = Path(sys.argv[1])
want = (ROOT / "config/SLUS_207.22.sha1").read_text().split()[0]
have = hashlib.sha1(path.read_bytes()).hexdigest()
print(f"{path}: {'OK' if have == want else 'FAILED'} {have}")
sys.exit(have != want)
