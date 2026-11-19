#!/usr/bin/env python3
"""Run the Metrowerks PS2 compiler (mwccps2.exe) on any host.

The game was compiled by CodeWarrior for PS2: every MW object stamps
`.comment` with "MW MIPS C Compiler (2.4.1.01)", which the decomp.me packages
mwcps2-3.0-011126, -3.0.1-020123 and -3.0.3-020716 all carry (2.4-001213
needs a FlexLM license and is unusable). The compilers are Win32
executables and run under Wine: natively on x86 Linux, otherwise in the
i386 container `godhand-eecc:wine` (tools/docker/wine.Dockerfile).

Usage: mwcc.py [--compiler NAME] [mwccps2 options] -c -o OUT.o IN.cpp
       mwcc.py --serve [BOX]   start a persistent container (default "mwcc")
Set MWCC_CONTAINER=BOX to exec into a served container: one Wine start per
compile instead of a fresh container (about 1 s instead of 5-30 s).
Packages download on first use into tools/compilers/ and are pinned by SHA-256.
"""

from __future__ import annotations

import hashlib
import json
import os
import platform
import shutil
import subprocess
import sys
import tarfile
import time
import urllib.request
import uuid
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
URL = "https://github.com/decompme/compilers/releases/download/compilers/{}.tar.gz"
PINNED: dict[str, str] = {}  # filled from tools/compilers.sha256 when present
DEFAULT = "mwcps2-3.0.3-020716"
IMAGE = os.environ.get("MWCC_IMAGE", "godhand-eecc:wine")
DOCKERFILE = ROOT / "tools/docker/wine.Dockerfile"


def pins() -> dict[str, str]:
    p = ROOT / "tools/compilers.sha256"
    if not p.exists():
        return {}
    return dict(reversed(line.split()) for line in p.read_text().splitlines() if line.strip())


def ensure_toolchain(name: str) -> Path:
    home = ROOT / "tools/compilers" / name
    if (home / "mwccps2.exe").exists():
        return home
    archive = home.parent / f"{name}.tar.gz"
    home.parent.mkdir(parents=True, exist_ok=True)
    if not archive.exists():
        print(f"mwcc: downloading {URL.format(name)}", file=sys.stderr)
        urllib.request.urlretrieve(URL.format(name), archive)
    digest = hashlib.sha256(archive.read_bytes()).hexdigest()
    want = pins().get(f"{name}.tar.gz")
    if want and digest != want:
        archive.unlink()
        raise SystemExit(f"mwcc: {archive.name} SHA-256 {digest}, expected {want}")
    home.mkdir(exist_ok=True)
    with tarfile.open(archive) as tar:
        tar.extractall(home, filter="tar")
    return home


def docker() -> str:
    d = os.environ.get("MWCC_DOCKER") or shutil.which("docker") or shutil.which("podman")
    if not d:
        raise SystemExit("mwcc: needs x86 Linux with Wine, or Docker/Podman")
    if subprocess.call([d, "image", "inspect", IMAGE], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL):
        cmd = [d, "build", "--platform", "linux/386", "-t", IMAGE, "-f", str(DOCKERFILE), str(DOCKERFILE.parent)]
        if subprocess.call(cmd, stdout=sys.stderr):
            raise SystemExit("mwcc: image build failed")
    return d


def serve(box: str) -> int:
    d = docker()
    subprocess.call([d, "rm", "-f", box], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    subprocess.check_call([d, "run", "-d", "--name", box, "--platform", "linux/386", "-v", f"{ROOT}:{ROOT}",
                           "-e", "WINEDEBUG=-all", IMAGE, "sleep", "infinity"], stdout=subprocess.DEVNULL)
    return subprocess.call([d, "exec", "-d", box, "wineserver", "-p"])


def spooled(argv: list[str]) -> int | None:
    """Hand the compile to tools/ccd.py when its heartbeat is fresh; None when no daemon runs.

    Sandboxed callers cannot reach Docker, so the daemon compiles for them."""
    q = ROOT / "build/ccq"
    alive = q / "alive"
    if os.environ.get("MWCC_NO_SPOOL") or not alive.exists() or time.time() - alive.stat().st_mtime > 5:
        return None
    rid = f"{os.getpid()}-{uuid.uuid4().hex}"
    tmp, req, res = q / f"{rid}.part", q / f"{rid}.req", q / f"{rid}.res"
    tmp.write_text(json.dumps({"cwd": str(Path.cwd().resolve()), "argv": argv}))
    tmp.rename(req)
    deadline = time.time() + 600
    while not res.exists():
        if time.time() > deadline:
            req.unlink(missing_ok=True)
            print("mwcc: compile daemon did not answer in 600 s", file=sys.stderr)
            return 1
        time.sleep(0.05)
    doc = json.loads(res.read_text())
    res.unlink()
    sys.stdout.write(doc["out"])
    return doc["rc"]


def main() -> int:
    argv = sys.argv[1:]
    if argv[:1] == ["--serve"]:
        return serve(argv[1] if len(argv) > 1 else "mwcc")
    if (rc := spooled(argv)) is not None:
        return rc
    name = os.environ.get("MWCC_COMPILER", DEFAULT)
    if argv[:1] == ["--compiler"]:
        name, argv = argv[1], argv[2:]
    exe = str(ensure_toolchain(name) / "mwccps2.exe")
    env = ["-e", "WINEDEBUG=-all", "-e", "MWCIncludes=."]
    cwd = str(Path.cwd().resolve())
    if sys.platform.startswith("linux") and platform.machine() in ("x86_64", "i686") and shutil.which("wine"):
        os.environ.update(WINEDEBUG="-all", MWCIncludes=".")
        cmd = ["wine", exe, *argv]
    elif box := os.environ.get("MWCC_CONTAINER"):
        cmd = [docker(), "exec", "-w", cwd, *env, box, "wine", exe, *argv]
    else:
        cmd = [docker(), "run", "--rm", "--platform", "linux/386", "-v", f"{ROOT}:{ROOT}", "-w", cwd, *env,
               IMAGE, "wine", exe, *argv]
    for _ in range(3):
        p = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        out = p.stdout.decode(errors="replace")
        # Wine's server link can drop under parallel load; that says nothing about the source.
        if p.returncode == 0 or "wine client error" not in out:
            break
    sys.stdout.write(out)
    # mwccps2 under Wine can exit 0 after a fatal error; trust the diagnostics instead.
    if p.returncode == 0 and ("Error" in out and "Usage Warning" not in out.split("Error")[0][-40:]):
        return 1
    return p.returncode


if __name__ == "__main__":
    sys.exit(main())
