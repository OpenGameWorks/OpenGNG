# Decomp subagent workflow

Shared rules for the `decomp-worker` and `decomp-writer` subagents. The coordinator verifies, builds and commits; a subagent edits only the files its job names and leaves results the coordinator can check.

## Ownership

- The job names the files a subagent owns (`src/game/<File>.cpp` and its `.h`). Every other file belongs to another worker; a fix that needs a foreign file goes into the report.
- Scratch experiments go in `src/scratch/<job-id>/`. A brute-force script writes only copies there, never files under `src/game`, and finishes before the report.
- Files are written with a file tool or a quoted heredoc (`cat > F <<'EOF'`). A bare `cat > F` reads the terminal, which never sends input, so the shell hangs as an orphaned background task that outlives the job.
- A copy outside `src/game` is scored with `fncmp.py -q --as src/game/<File>.cpp COPY 0xADDR`. mwccps2 register scheduling depends on the source and object path lengths, and `--as` compiles the copy with the lengths ninja uses for the real file; without it a copy can report MATCH for code the link rejects.

## What counts as a match

- A match is C++ that the compiler turns into the original bytes. Instructions C cannot emit (VU0 macro mode: `lqc2`, `sqc2`, `v*` ops, `vcallms`, `qmtc2`, `qmfc2`, `ctc2`, `cfc2`; COP0: `mfc0`, `mtc0`, `sync.p`, `ei`, `di`) were inline asm in the original too, so they go in an `asm { }` block with C locals as operands (`lqc2 vf1, 0x0(pBox)`, or `lqc2 vf26, vA` for a stack array) and microprogram symbols by name (`vcallms Vu0_Pt_In_MatrixBox`, declared `extern "C" void Vu0_Pt_In_MatrixBox(void);`). The function still counts as a FUNCTION.
- Every instruction C can produce stays C. A whole `asm` body, or inline `asm` copying instructions C can emit, reproduces the bytes without recovering the source and never counts.
- `fncmp.py`'s verdict line (`MATCH` or `DIFF N words`) is the difference count; counting `^!` lines is unreliable.

## Attempts

- Name the difference before editing: register allocation, instruction order, a missing or extra move, branch form (`bnel` vs `bne`), load type (`lb`/`lbu`, `lw`/`lwc1`), constant-load order, argument order, or the return register. Then search `.claude/rules/mwcc-*.md` for that asm pattern.
- Change one thing, rerun `fncmp.py -q`, and keep a variant only when the count drops. The best variant is copied to `src/scratch/<job-id>/` before the next attempt, because the final DRAFT keeps the lowest count reached.
- Stop on a function after 8 attempts without progress. Variants a `// note:` lists as tried are not repeated.
- A callee's return type and arity follow its own asm and mangled name (`grep -rn "NAME" src include < /dev/null | head -5`); a wrong one shifts registers and schedule.

## Finishing

- MATCH: the tag becomes `// FUNCTION: 0xADDR MANGLED` and the `// note:` line is removed.
- No match: the code keeps compiling under `// DRAFT: 0xADDR MANGLED` with a one-line `// note:` giving the differing count, what differs and the variants tried. A source that does not compile breaks the build.
- An edited body can shift scheduling of the next function: the FUNCTION tag directly after each edited function is rechecked, and an edit that breaks it is reverted. A header or shared-inline change rechecks every FUNCTION in the file.
- `.venv/bin/python tools/claimed.py < /dev/null` prints nothing.
- One row per address is appended to `build/results/<job-id>.tsv` as soon as the address is settled: `0xADDR<TAB>MATCH|DRAFT|SKIP<TAB>differing-words<TAB>file<TAB>note`.

## Environment

- `fncmp.py` compiles through the `tools/ccd.py` spool, so it runs inside the sandbox; a compile under load takes up to a minute.
- Every command runs in the foreground. A foreground command moves to the background after 120 s, so one command checks at most two FUNCTION tags; background commands, sleeps and monitors keep the job open after its report.
- `wc`, `cat`, `xargs` and `grep` with no file list wait on stdin; pass `< /dev/null`.
- Output is read through `head`, `tail` or `grep`, never whole files, so context stays under 100k tokens: source through `grep -n` plus Read with a limit of at most 60 lines, `draft.py` through `| head -60`, `disasm.py` through `| head -90`.
- A context summary asks for a text-only reply for that summary alone; work resumes with tool calls afterwards.
- No commits, no `ninja`, and no edits under `tools/`, `config/` or `include/`. Tool bugs and permission denials go into the report, unworked-around.
