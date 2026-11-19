# CLAUDE.md

Byte-for-byte matching decompilation of Maximo: The Army of Zin (PS2, SLUS-20722). `build/SLUS_207.22: OK` from `ninja` is the only acceptable build. The ISO, `original/` and everything extracted from them stay out of git.

- Only game code is decompiled. SCE SDK libraries (gcc-built, `sdk/*.c` in `config/tus.tsv`) and other third-party code come from original library objects or source wherever those are obtainable; decompiling them is a last resort for verified-unobtainable pieces. `tools/progress.py` and the live treemap count game code alone.
- Game code: Metrowerks CodeWarrior PS2 (`mwccps2`, `.comment` "MW MIPS C Compiler (2.4.1.01)"), package `mwcps2-3.0.3-020716`, `-O4`, C++. A source overrides compiler or flags with `// COMPILER:` / `// FLAGS:` in its first four lines.
- Files are flat `src/game/<File>.cpp` named by the executable's own `__FILE__` strings; `config/tus.tsv` maps every address to its file with the evidence used. Functions keep address order inside a file.
- `// FUNCTION: 0xADDR MANGLED` marks a match. `// DRAFT: 0xADDR MANGLED` marks compiled, not-yet-matching code with a one-line note of what differs. Both compile; the linker (`tools/link.py`) places a function only when its relocated bytes equal the original, so unmatched code keeps the original bytes and the build stays OK.
- `.venv/bin/python tools/fncmp.py [-q] FILE 0xADDR` compiles and compares one function (exit 0 = MATCH). `tools/draft.py 0xADDR` prints an m2c draft plus literal values; `tools/disasm.py 0xADDR` prints annotated asm. `tools/claimed.py [0xADDR]` names an address's owner or lists duplicate claims.
- Compiling runs in Docker. Sandboxed sessions compile through `tools/ccd.py` (a daemon outside the sandbox serving `build/ccq/`); `tools/mwcc.py` uses it automatically, so `fncmp.py` needs no sandbox bypass.
- Live progress: `tools/live.py` (port 8722, all interfaces). Worker queue: `tools/queue.py take N | done ID`; per-address results in `build/results/<job>.tsv`.
- Subagents run Haiku at effort high (`decomp-writer`); a worker owns exactly the files its job names and stays under 100k context. Sonnet at effort medium only for a task that needs more context and cannot be split.
- `wc`, `cat`, `xargs`, `grep PATTERN` with no file list wait on stdin; pass `< /dev/null`. `$TMPDIR` differs inside and outside the sandbox; shared scratch goes in `src/scratch/` (gitignored).
