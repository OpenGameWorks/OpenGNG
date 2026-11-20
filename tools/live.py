#!/usr/bin/env python3
"""Serve a live decomp-progress treemap built from the committed tree.

Usage:
  python tools/live.py [--port 8722] [--interval 5]     (or `just live`)

Open http://127.0.0.1:8722/ . The page polls /progress.json every 3 s and flashes
newly matched functions. Progress reflects HEAD, not the working tree: concurrent workers
keep sources mid-edit (failing variants, half-split headers), so a working-tree build almost
never settles. Every INTERVAL seconds the watcher compares `git rev-parse HEAD`; on a new
commit it mirrors HEAD into build/live/head (rewriting only files whose bytes changed, so
ninja recompiles only those), then runs `tools/configure.py`, `ninja` and
`tools/progress.py --json` there. Untracked inputs (original/, .venv, build/info, compiler
packages) are symlinks into the main tree. Active workers come live from
build/queue/active.json. A failing refresh keeps the last good progress.json and reports
the compiler's error line. The server answers conditional requests, so an unchanged json
costs a 304.
"""

from __future__ import annotations

import argparse
import io
import json
import shutil
import subprocess
import sys
import tarfile
import threading
import time
from http.server import SimpleHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BUILD = ROOT / "build"
MIRROR = BUILD / "live/head"
ROUTES = {"/": ROOT / "tools/live.html", "/index.html": ROOT / "tools/live.html",
          "/progress.json": MIRROR / "build/progress.json", "/status.json": BUILD / "live_status.json",
          "/workers.json": BUILD / "queue/active.json"}
# Untracked build inputs the mirror borrows from the main tree.
LINKS = ["original", ".venv", "build/info"] + [
    str(p.relative_to(ROOT)) for p in sorted((ROOT / "tools/compilers").glob("*")) if p.is_dir()]


class Handler(SimpleHTTPRequestHandler):
    def translate_path(self, path: str) -> str:
        return str(ROUTES.get(path.split("?", 1)[0], ROOT / "build/.missing"))

    def end_headers(self) -> None:
        self.send_header("Cache-Control", "no-cache")  # revalidate via Last-Modified
        super().end_headers()

    def log_message(self, *a) -> None:
        pass


def head() -> str:
    return subprocess.run(["git", "rev-parse", "HEAD"], cwd=ROOT, capture_output=True, text=True,
                          check=True).stdout.strip()


def sync(sha: str) -> None:
    """Make MIRROR equal the tracked tree at SHA, touching only files whose bytes differ."""
    blob = subprocess.run(["git", "archive", sha], cwd=ROOT, capture_output=True, check=True).stdout
    want = set()
    with tarfile.open(fileobj=io.BytesIO(blob)) as tar:
        for m in tar:
            if not m.isfile():
                continue
            want.add(m.name)
            dst = MIRROR / m.name
            data = tar.extractfile(m).read()
            if dst.is_file() and not dst.is_symlink() and dst.read_bytes() == data:
                continue
            dst.parent.mkdir(parents=True, exist_ok=True)
            dst.write_bytes(data)
            dst.chmod(m.mode & 0o777)
    manifest = MIRROR / "build/.live_manifest"
    old = set(manifest.read_text().splitlines()) if manifest.exists() else set()
    for gone in old - want:  # files deleted or renamed upstream
        (MIRROR / gone).unlink(missing_ok=True)
    for rel in LINKS:
        link = MIRROR / rel
        if not link.is_symlink() and (ROOT / rel).exists():
            link.parent.mkdir(parents=True, exist_ok=True)
            link.symlink_to(ROOT / rel)
    seen = MIRROR / "build/match_times.json"
    if not seen.exists() and (BUILD / "match_times.json").exists():  # keep "Recent matches" history
        shutil.copy2(BUILD / "match_times.json", seen)
    manifest.write_text("\n".join(sorted(want)))


def reason_of(cmd: list[str], out: str) -> str:
    """The line that explains a failed step: the first compiler error, else the last output line.

    MWCC prints `#    File: src\\x.cpp`, the source line, a caret line `#   Error: ^^^`, then
    the message on the next `#` line; the file and message together name the breakage."""
    lines = [l for l in out.strip().splitlines() if l.strip() and not l.startswith("ninja:")]
    src = next((l.split("File:", 1)[1].strip() for l in lines if "File:" in l), "")
    for i, l in enumerate(lines[:-1]):
        if "Error:" in l:
            return f"{src}: {lines[i + 1].lstrip('# ').strip()[:300]}"
    pick = lines[-1] if lines else "failed"
    return f"{Path(cmd[-1]).name}: {pick.strip()[:300]}"


def refresh(sha: str) -> str | None:
    """Rebuild progress.json from commit SHA; return None on success, else why it failed.

    A failed step leaves the previous progress.json in place, so the page keeps the last
    good treemap."""
    sync(sha)
    steps = [[sys.executable, "tools/configure.py"], ["ninja"],
             [sys.executable, "tools/progress.py", "--json"]]
    for cmd in steps:
        try:
            r = subprocess.run(cmd, cwd=MIRROR, capture_output=True, text=True)
        except OSError as e:
            return f"{cmd[-1]}: {e}"
        if r.returncode:
            return reason_of(cmd, r.stdout + r.stderr)
    return None


def write_status(pending: str | None) -> None:
    BUILD.mkdir(exist_ok=True)
    (BUILD / "live_status.json").write_text(json.dumps({"ok": pending is None, "message": pending or "", "t": time.time()}))


def watch(interval: float) -> None:
    """Refresh on each new commit. A commit that fails to build is a real breakage, so its
    error stays on the page until a later commit builds; it is not retried."""
    last, pending = None, None
    while True:
        try:
            sha = head()
            if sha != last:
                last = sha
                reason = refresh(sha)
                if reason is None:
                    print(f"live: refreshed {sha[:8]} {time.strftime('%H:%M:%S')}", flush=True)
                else:
                    print(f"live: HEAD {sha[:8]} does not build ({reason})", flush=True)
                write_status(reason)
                pending = reason
        except Exception as e:  # the watcher thread must outlive any single bad tick
            last, pending = None, f"{type(e).__name__}: {e}"  # retry this commit next tick
            print(f"live: tick error ({pending}); retrying", flush=True)
        time.sleep(interval)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--port", type=int, default=8722)
    ap.add_argument("--host", default="0.0.0.0", help="bind address (0.0.0.0 makes the page reachable on the LAN)")
    ap.add_argument("--interval", type=float, default=5.0, help="seconds between change checks")
    args = ap.parse_args()
    try:
        srv = ThreadingHTTPServer((args.host, args.port), Handler)
    except OSError as e:
        raise SystemExit(f"live: port {args.port} unavailable ({e.strerror}); another live.py may be "
                         f"running (`lsof -i :{args.port}`), or pass --port N")
    threading.Thread(target=watch, args=(args.interval,), daemon=True).start()
    print(f"live: http://{args.host}:{args.port}/  (Ctrl-C to stop)", flush=True)
    try:
        srv.serve_forever()
    except KeyboardInterrupt:
        pass
    return 0


if __name__ == "__main__":
    sys.exit(main())
