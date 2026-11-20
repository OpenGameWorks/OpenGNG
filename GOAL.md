# GOAL

Maximo: The Army of Zin (USA, PS2, SLUS-20722) reaches a 100% byte-for-byte C/C++ match. `ninja` ending in `build/SLUS_207.22: OK` is the only acceptable build.

## Scope

- Only game code is decompiled. SCE SDK and third-party code come from original objects or source. Only pieces verified as unobtainable get decompiled.
- The treemap and match totals count game code alone. Original asm never counts as matched.
- VU0 and other code that C/C++ cannot express uses inline asm, and only for the instructions the compiler cannot emit.

## Progress (HEAD 6bfe3c7, 2026-11-21)

- 1466 / 2830 game functions matched, 234152 bytes (~26.1% of game code).
- The session started at 1435 functions (24.6%).
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
4. **Worker limits:** up to 20 concurrent workers, Haiku at effort high (`decomp-worker` / `decomp-writer`), each under 100k context. A worker owns only the files its job names.
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
- An early return matches where an `if` wrapper does not.

## Status

Paused by the user after the last workers finished. Every remainder is committed, and `src/ include/ tools/ config/` are clean. Next step: put the worker policy above in place, then resume with draft jobs.
