# GOAL

Maximo: The Army of Zin (USA, PS2, SLUS-20722) reaches a 100% byte-for-byte C/C++ match. `ninja` ending in `build/SLUS_207.22: OK` is the only acceptable build.

## Scope

- Only game code is decompiled. SCE SDK and third-party code come from original objects or source. Only pieces verified as unobtainable get decompiled.
- The treemap and match totals count game code alone. Original asm never counts as matched.
- VU0 and other code that C/C++ cannot express uses inline asm, and only for the instructions the compiler cannot emit.

## Progress (2026-11-26)

- 1494 / 3018 game functions matched, 238992 / 933240 bytes (25.6%). The total grew from 2830 when class-name evidence moved unattributed runs into game files; 159 functions (25 KB) remain unattributed.
- SDK: 773 functions (109 KB) verified against original SCE library objects by `tools/sdklink.py` (94/94 members). They count as library-object, never as decompiled C.
- Fresh checkout: `tools/setup.py IMAGE.iso|.chd`, then `ninja`. Verified on a clean clone from both the ISO and a CHD made from it; the image's SHA-1 is unchanged afterwards.
- Live treemap: `tools/live.py`, port 8722. It builds HEAD in `build/live/head`, so a half-edited working tree never stalls it. When HEAD fails to build, it reports the compiler's error line.

## What produces matches

| Job | Wall time | Yield |
|---|---|---|
| Draft job: 4 low-diff DRAFTs in one file (`src/scratch/takedraft.py`) | 10–15 min | 14 matches over 6 jobs |
| Whole-function write of a large function (Execute, OnHitEvent, UpdateCameraPos) | 2–4.5 h | 0 matches; drafts 320–2782 words off |

**Why the large writes stalled:** nothing capped their wall-clock time, and a single Haiku worker cannot transcribe a 0x1000-byte state machine closely enough to converge.

## Worker policy (next run)

1. **30-minute hard cap per worker.** Every hand-back checks `started` in `build/queue/active.json`. A worker past 30 minutes is stopped, its compiling state is committed as DRAFT with a note, and the job is closed.
2. **No function over 0x400 bytes goes to a Haiku writer.** Such a function is split into case-sized chunk jobs, or, if it cannot be split, routed to one Sonnet task (effort medium).
3. **The queue is filled with small-diff draft jobs first.** `takedraft.py` skips addresses an earlier draft job already left as DRAFT. Those addresses go to the permuter (`tools/permute.py`) or to idiom sweeps (`src/scratch/ternary_sweep.py`).
4. **Worker limits:** at most 3 concurrent workers, Haiku at effort high (`decomp-worker` / `decomp-writer`), each under 100k context. A worker owns only the files its job names.
5. **Coordinator loop:** hand-back → verify the file plus every includer of its header → small commit with explicit staging → `tools/queue.py done ID` → take the next job.

## Proven MWCC idioms

- An if/else that assigns one variable is written as a ternary; that changes delay-slot scheduling.
- Loop-advance tails: `pX = (++i < n) ? arr[i] : 0;`.
- Bool locals produce `daddiu`. unsigned char locals match byte loads.
- Pass the symbol itself, never symbol-minus-offset.
- Clamp as `if (v > 100U) v = 100;`.
- Float constants become locals hoisted to the top of the function (`17.0f`, `255.0f`, `float zero`).
- `if (f)` truthiness flips the `c.eq.s` operand order.
- Function-local `static` arrays match per-function data.
- Declaration order of locals steers register allocation.
- An early return matches where an `if` wrapper does not; inside a retry loop, `return 0;` rather than `r = 0; goto done;`.
- A subobject destructor called with `a1 = -1` is a data member (`PArray m_array;`), not a base class (flag 0).
- A file-local callee or data object in the original (`STB_LOCAL`) is `static` in the source; the linker proves such a call by name.
- A callee's mangled name is ground truth for its parameter types; when the C++ type adds an extension the original lacks (`unsigned short` into `unsigned int` gives an `andi`), call the mangled symbol through an `extern "C"` declaration.
- Range tests: `(unsigned)(x - a) <= n` and `< n + 1` compile differently; the original's `sltiu` immediate tells which.

## Status

Running: waves of up to 3 Haiku jobs (`takedraft.py 5` draft jobs, `queue.py take` writer jobs), each retired after `ninja`, `tools/regress.py` and a commit. `tools/draftscan.py` rescoring keeps the draft list fresh; drafts a job left behind go to `tools/permute.py`.
