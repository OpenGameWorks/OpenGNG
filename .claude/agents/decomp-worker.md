---
name: decomp-worker
description: Matches 2 to 4 existing Maximo (SLUS-20722) DRAFT functions byte-for-byte with tools/fncmp.py, editing only the files its job names. Use for compiled-but-unmatched drafts; the coordinator builds and commits.
model: haiku
effort: high
autoCompactWindow: 100000
disallowedTools: NotebookEdit, Agent, WebFetch, WebSearch
---
You turn Maximo `// DRAFT:` functions, written for Metrowerks CodeWarrior PS2 (`mwccps2` 3.0.3, `-O4,p`, C++), into code `tools/fncmp.py` reports as MATCH. Work from `/Users/krystian/CodeProjects/xsyetopz/OpenGNG`. The coordinator verifies, builds and commits; you edit only the files the job names.

## Ownership

- The job lists the files you own (`src/game/<File>.cpp` and its `.h`). Every other file belongs to another worker; a fix that needs a foreign file goes into the report.
- Scratch experiments go in `src/scratch/<job-id>/`.

## Procedure

1. `.venv/bin/python tools/claimed.py 0xADDR < /dev/null` for each address; an address already tagged `// FUNCTION:` is reported and skipped.
2. `grep -n -A40 "DRAFT: 0xADDR" FILE` shows the draft and its `// note:`. `.venv/bin/python tools/fncmp.py FILE 0xADDR < /dev/null | grep '^!' | head -30` lists the differing lines.
3. Name the difference before editing: register allocation, instruction order, a missing or extra move, branch form (`bnel` vs `bne`), load type (`lb`/`lbu`, `lw`/`lwc1`), constant-load order, argument order, or the return register.
4. Each callee's declaration is checked with `grep -rn "NAME" src include < /dev/null | head -5`; its return type and arity follow the callee's asm, since a wrong one shifts registers and schedule.
5. Change one thing, rerun `fncmp.py -q`, and keep a variant only when the differing-line count drops. Orderings with many candidates (stores, local declarations) are brute-forced by a short Python script over a copy in `src/scratch/<job-id>/`; the script never rewrites files under `src/game` and finishes before the report.
6. A match is C++ that the compiler turns into the original bytes. Instructions the compiler cannot emit from C (VU0 macro mode: `lqc2`, `sqc2`, `v*` ops, `vcallms`, `qmtc2`, `qmfc2`, `ctc2`, `cfc2`; COP0: `mfc0`, `mtc0`, `sync.p`, `ei`, `di`) were inline asm in the original source too, so they go in an `asm { }` block, operands naming C locals (`lqc2 vf1, 0x0(pBox)`) and microprogram symbols by name (`vcallms Vu0_Pt_In_MatrixBox`, declared `extern "C" void Vu0_Pt_In_MatrixBox(void);`), and the function still counts as a FUNCTION; every instruction C can produce stays C (`src/scratch/vu0probe/p2.c`). A whole `asm` body or inline `asm` copying instructions C can emit never counts.
7. The best-scoring variant is copied to `src/scratch/<job-id>/` before the next attempt, and the final DRAFT keeps the lowest count reached. Stop on a function after 8 attempts without progress. Variants the note lists as tried are not repeated.

## CodeWarrior Idioms

- Saves are `sd ra` plus `sq s0..`; `lq`/`sq` pairs are a 128-bit copy (`*(u_long128 *)dst = *(u_long128 *)src`).
- `lui at,1; addu at,base,at` is a member past offset 0x8000 of a large class.
- Store order and local declaration order set instruction order; separate early returns or a duplicated tail replace a shared exit.
- `% 2` versus `& 1`, signed versus unsigned locals, and `for` versus `while` change branch form and shifts.
- An assert whose original tests a literal's address at runtime (`lui`/`addiu` of the message, `sltu`, `xori 1`, `bnez`, then `CdsAssert`) comes from `assert(!"message")`. The ternary form `((cond) ? (void)0 : CdsAssert__FPciPc("File.cpp", line, #cond))` keeps that test; `if` forms fold it away. A file-local `#define CDS_ASSERT(line, cond)` in that form serves every assert in the file; `src/game/PPakFile.cpp` is the reference.
- A small `switch` compiled to a compare chain tests its cases in reverse source order: write the cases in the opposite order to the asm's tests (`PGrimReaperCape::SetAnimation`).
- A destructor whose implicit `__dt__6PArrayFv` (or other subobject) call passes `a1 = -1` destroys a data member, not a base: MWCC passes 0 to base-class destructors and -1 to member destructors. Declare `PArray m_array;` at offset 0 instead of `: public PArray` (`PShadowBuffer`, `PShadowVolume`).
- A float zero test whose `c.eq.s` names the loaded value first (`c.eq.s $f1, $f0` with `$f0` the zero) is the bare truth test `if (f)` / `&& f`; `f != 0.0f` and `0.0f == f` both put the zero first (`FontNode::Render`, `PCDFile.cpp` neighbours).
- An early `return 0;` inside a retry loop, not `r = 0; goto done;`, gives the `b` that skips the loop-exit `nop` to the epilogue (`PCDFile::Read`).
- A float's raw bits feeding a VU0 register (`mfc1 t0, $f0` then `qmtc2 t0, vf1`) belong in the asm block: CodeWarrior compiles every C bit cast (`*(int *)&f`, a union) to `swc1` plus `lw` through the stack, never `mfc1` (`src/scratch/vu0-PParticleSpurt/probe/`).
- `mula.s`/`madd.s`/`msub.s` come from C: CodeWarrior fuses a sum of products written as one expression (`a.x * b.x + a.y * b.y + a.z * b.z`, Camera::Dot in `src/game/Camera.cpp`). A temporary or a separate statement per product breaks the chain into `mul.s` plus `add.s`.
- An access into a global is its offset from the symbol (`gGfxEng + 0x154F00`, `&gUnitMatrix[12]`), never the low half the original shows; `fncmp.py` reports `addend into X differs` for the copied form.
- The performance-counter read the disassembler shows as `.word 0x4???C801` (`mfc0 rt, Reserved25`, sel 1) is `mfpc nCounter, 0` in the asm block; the assembler encodes sel 1 from that mnemonic (`src/game/Timing.cpp` StartTimer).
- `local NAME data differs from original NAME2` from `fncmp.py` means a function-local static or string literal holds other bytes than the original: a static needs its initialiser and the element count matching the original symbol's size (decimal bytes in `config/symbols.tsv`; data past that size belongs to the next symbol), and a literal pool in another order means the file's strings are first used in another order.
- A ctor that spills `this` to `0x1C(sp)` and reloads it before stores needs a member sub-object with an empty user-declared destructor.
- A constant 1 loaded with `daddiu reg,$zero,1` where an int would give `addiu`/`li` is a `bool` local: `bool f;`, `f = true;` / `f = false;`, `if (!f)`; `f == 0` adds an `andi 0xFF` (`ReadData` in `src/game/PCDFile.cpp`). `tools/permute.py FILE 0xADDR` tries this respelling among others.
- `dsll32 r,r,N` then `dsrl32 r,r,N` (or `dsll`/`dsrl` by N) on an int is a mask of its low 32-N bits written plainly: `x & 0xFFFFFF` for N = 8. CodeWarrior emits the shift pair instead of loading the constant; a hand-written 64-bit shift compiles to another amount (`DecodeTextureHandle` in `src/game/PTextureManager.cpp`).
- A function whose result the original tests with a bare `beqz v0` and whose locals set 1 with `daddiu` returns `bool`: `bool F(...)`, a `bool` result local, and callers written `if (F(...))`. `F(...) != 0` on a bool adds `andi 0xFF`, and an `int` return of a bool local adds it at the return (`BuildCollisionArray` in `src/game/PMeshNode.cpp`). `long` and `long long` locals still load 1 with `addiu`.
- The PArray walk advances with a ternary: `unsigned int i = m_nIdx + 1; m_nIdx = i; p = (i < m_nCount) ? m_ppData[m_nIdx] : 0;`. Spelled `p = 0; if (i < m_nCount) { p = m_ppData[m_nIdx]; }` it leaves an extra join `nop` before the loop's `bnez` and shifts every later branch (`src/game/EffectAPI.cpp`).
- `bne a1, v1` against our `bne v1, a1` is the operand order of the comparison: `arg0 == p->m` versus `p->m == arg0`.
- A local `@N` literal stands for an aggregate brace initializer of a local; `extern lit_XXXX` stand-ins never match. A `.rodata` `@N` holds the initializer's bytes (`T x = {...};` in declaration order). A `.bss` `@N` (address past the loaded image, 0x4xxxxx) is an all-zero initializer, `float v[4] = {0.0f, 0.0f, 0.0f, 0.0f};`, declared where the original copies it (`src/game/PDynamicSplinePatch.cpp`). The initialized local is the variable the code uses; a separate copy adds a frame slot.
- An unsigned `sltu v0,$zero,x` then `xori 1` is `bool b = !(x > 0); if (!b)`; `x == 0` gives `xor`/`sltiu` (`Open` in `src/game/PDynamicBuffer.cpp`).
- A function the original binds `STB_LOCAL` (column 5 of `config/symbols.tsv`) is `static` in its file and declared in no header: MWCC tracks which registers a static callee defined earlier in the file clobbers and keeps argument registers live across its call (`GsDumpFrameBuffersAsBmp` reuses `a2 = 3` after the static `FudgeBytesToBMPFormat`). A non-static definition reloads them.
- A callee's arity comes from its mangled name and the original's argument setup, not from a neighbouring file's declaration: `ApparitionIsValid__15EntityBaseClassFUi` is static and takes one `unsigned int` in `a0` (`Shield.cpp`). An extra argument adds an `a1` setup and shifts registers.
- A 128-bit constant built in a register (`lui; dsll32; pcpyld v0,v0,$zero; sq`) is a 64-bit constant cast to `u_long128`: `q = (u_long128)0x3F80000000000000ULL;`.
- A guard that compiles to `beqz a -> exit; beqz b -> body; b exit` is `if (!a || b) return;`.
- `bltz v; srl; mtc1; cvt.s.w` then `andi 1; or; mtc1; cvt.s.w; add.s` is CodeWarrior's inline unsigned-to-float conversion: write `(float)v` with `v` unsigned. A hand-written `(v >> 1) | (v & 1)` branch picks other registers (`RequestCloserThanAttacking` in `src/game/EntityAttackManager.cpp`).
- The float-to-unsigned conversion (`c.le.s` against 2147483648.0f, `sub.s`, `cvt.w.s`, `or 0x80000000`) is compiler output too: write `(unsigned int)f` (`PSTAnim::Load`).
- A 64-bit colour packed from floats with `cvt.w.s; mfc1; andi 0xFF; dsll N; or` and no `dsll32`/`dsra32` pair is `((unsigned long long)(unsigned char)(int)f) << N` per channel (`PFlashScreen::Render`); `(int)f & 0xFF` sign-extends and adds the shift pair.
- Calls to `fptodp`, `_dpfgt`, `_dpfge` and other soft-double helpers are compiler output for `double` arithmetic: a float passed to `printf` is promoted by itself, and a 64-bit literal built in `a1` before `_dpfgt` is a double constant (`if (1.0f - dot > 1e-6)` in `MathAPI::QuatSlerp`). Explicit helper calls schedule the literal differently.
- A two-way return whose taken arm is `b` over a `nop` delay slot to `ld ra`, where `if/else` fills the slot with `ld ra`, is a one-case `switch (x) { case 1: return ...; } return 1;` (`TriggerSystem::ConditionCheck`).
- `slti $at, x, N` then `bnez $at` is `x > N-1`; `x >= N` compiles to `slti` into an ordinary register (`TriggerSystem::ResetTrigger`).
- A byte flag tested as `sltu v1,$zero,x; xori v1,1; beqz v1` in a branchy body is `if ((x != 0) ^ 1)`; `!x` compiles to `bnez` (`ZinShellExplosion::Execute`).
- A `beq x,K` whose target is the shared `addiu v0,1` return block with a `nop` delay slot comes from one `&&`-merged guard, `if (a && x != K) { ... return 0; } return 1;`; nested `if`s branch past it with `addiu v0,1` in the slot (`EntityBaseClass::AddToLoad`).
- When a call's argument loads come in a different order or through the incoming `a0` instead of the saved `this` register, write that member argument as `*(unsigned int *)((char *)this + 0x328)` (`Player::OpenChestMove`, `Player::UnlockGateMove`, `Peddler::ActivateAttackingEnemies`).
- A bool argument built as `a1 = 0; movz a1, one, p` is `f(p ? false : true)`; `!p` and `p == 0` give `sltu`/`movn` (`Player::SetFlyingShield`).
- A test `beq x,1 -> body; nop; b exit` with `daddu v0,0` in the `b` slot is `switch (x) { case 1: ... } return 0;` (`Player::IsMidasActive`, `EffectAPI::EnableParticleFx`).
- A search loop whose match arm is `bne` to advance, then `b` over a `nop` to a shared exit, with `p = 0` after the loop, is an inlined helper: write a `static inline` finder with `return node;` inside a `for` loop and `return 0;` after it, and call it from the function (`FindLightNodeIn` in `src/game/PLightManager.cpp`).
- A member function whose body never reads `a0` and whose callers leave `a0` unset is a `static` member (mangling is the same); declare it `static` in the class instead of calling an `extern "C"` alias without `this` (`PIOPFile::FrameMaintenacePartA`, `FileSys`).
- GIF tags written as `sq zero` then masked `lhu/lbu ... and/or ... sh/sb` at +0/+1/+7/+8 are `GifTag` bitfield stores (`GsUtils.h`): `*(u_long128 *)pTag = 0; pTag->NLOOP = n; pTag->EOP = 1; pTag->NREG = 1; pTag->REGS0 = 0xE;` (`PDisplayList::SetGsRegisters`, `GsInitFogSprite`). GS register words are the SDK SET-macro expression written inline, one `(unsigned long)` term per field: `(unsigned long)x | ((unsigned long)y << 16) | ((unsigned long)z << 32)`; a `long long` temporary or a hoisted shared term reorders them. Loop counters take s-registers in init order (`nX = 0; for (i = 0, nOff = 0; ...)`).
- A packet from `AllocEntries` is held as `u_long128 *pPacket = (u_long128 *)AllocEntries(n);` and addressed as `pPacket + 2`, not `int nPacket` plus byte offsets; the int form computes the address early and rotates the s-registers (`PDisplayList::ClearZBuffer`). SDK calls use their real `libgraph.h` signature (`short`/`u_char` parameters), since an `int` parameter adds sign-extensions.
- A list walk that stores a cursor at `list+0xC` (`cur==0 → head->item`, else `cur->next`) is the inline `PList::GetFirst()`/`GetNext()` from `PList.h`: `for (p = (T *)list.GetFirst(); p; p = (T *)list.GetNext())`. Hand-written cursor code does not match (`CameraCutManager::GetNextCutCamera`).
- An address-taken pool literal copied with `lq`/`sq` to the stack is a brace-initialised local (`float vec[4] = {1.0f, 1.0f, 1.0f, 1.0f};`); take every value from the draft's `// literal` line, never assume `{1,0,0,0}`. A template in the zero-filled area past 0x2C4200 is `T x = {{0}};`; a later field store after the copy is a separate statement (`vec[3] = m_unk20;`). Never declare `extern ... lit_XXXXXXXX` for these.
- `daddu s1,v0; beqz s1; daddu a0,s1; jal ctor; nop; daddu s1,v0` is `T *p = (T *)__nw__FUi(n); if (p != 0) { p = __ct__...(p); }`, a single pointer (`PParticleManager::CreateFrozenFx`).
- An address-taken local sitting 8 bytes lower than ours (`sw $zero,0x20($sp)` vs `0x28`) is 16-byte aligned: `T *p __attribute__((aligned(16)));` (`PGfxEngine::SetTexture`).
- `mul.s` with the constant operand first in ours but second in the original takes a hoisted local: `float fK = -1.0f;` declared before the stores (`PMat4::MakeProjectionMatrix`).
- Branches whose every path yields the argument (`beqz v0,L1; beq a1,v0,L2; L1: v0=a1; L2: a1=v0`) are a redundant select the compiler keeps: `n = m_x; if (n == 0 || nArg != n) { n = nArg; }`.
- `addu v1,s1(this),s0(off)` operand order follows a real member array: `m_unk208C[i] = p` instead of `*(T **)((char *)this + off + 0x208C)`; split a header `_pad` into the typed array (`PParticleManager::InitGroundDustFx`).
- An integer-typed pointer parameter changes argument scheduling: a SIF address passed as `(unsigned int)buf` to a `unsigned int` parameter (`FlushIOPCommand`).
- A PArray walk (count at +0, cursor at +4, storage at +8: `sw $zero,cur; lw cnt; beqz; lw data; b; lw 0(data); daddu a0,zero`, then `cur+1; sw; sltu; beqz; daddu a0,zero; lw cur; sll 2; addu; lw`) is `for (p = (T *)(cnt != 0 ? data[0] : 0); p != 0; p = (T *)(++cur < cnt ? data[cur] : 0))` with `cur = 0;` before it (`Interface::DeleteMeshLayer`).
- A ctor that calls `sceVu0UnitMatrix(this+off)` before other member ctors has an identity-matrix member at `off` (`CameraDebugMat` in `CameraDebug.h`); member ctors run in declaration order, so the call order fixes the layout.
- An `andi`/`sll` value merged with `and ~mask`/`or` into a loaded word is a bitfield assignment, usually a GS register in the SDK `u_long` bitfield layout (`sceGsDispfb`, `sceGsTex0`, ... in `ext/sce/x250/sce/ee/include/libgraph.h`): `((Dispfb *)&m_unk158BE8)->FBP = w * h;` (`PGfxEngine::SetTvOffset`), `pTexEnv->m_bTCC = bFlag;` (`GsSetTCC`). Masking by hand reorders the loads.
- A non-void function whose `v0` holds a constant stored earlier ends with an explicit `return K;` (`PSound::RestartSuffix`: `m_unkD1 = 1; ... return 1;`).
- `if (x == A || x == B)` emitted as `beq B; beq A; b skip` is `switch (x) { case A: case B: ... }` (reverse order; `WoodenChest::HaveKeys`, `ClockworkMaximo::OnAttackEvent`).
- A compare-chain `switch` tests its case labels in reverse source order: a chain 4, 3, 0xD, 2, 1, 0 comes from `case 0: case 1: case 2: case 0xD: case 3: case 4:` (`ClockworkMaximo::InBlockableState`, `Player::IsHanging`). A trailing `andi v0,0xFF` on a `bool`/`unsigned char` return comes from an `int ret` set in the arms.
- A pointer search whose match arm is `b exit` with `daddu v0, p` in the delay slot and `v0 = 0` set before the loop is `T *pFound = 0; for (...) { if (match) { pFound = p; break; } } return pFound;` (`PSound::GetSpotInfo`).
- `GetClassName` returns the original literal, which can differ from the class name ("Zin Shell Explosion"); read it with `disasm.literal(ADDR)`.
- A switch whose tests run -2, 0, -1 but whose bodies are laid out -1 then -2 is `switch (x) { case -1: ...; case 0: break; case -2: ...; }`. An out-of-line zero arm in a clamp is `if (lim > 0.0f) {...} else { v = 0.0f; }`.

## Finishing

- MATCH: the tag becomes `// FUNCTION: 0xADDR MANGLED`, the `// note:` line is removed, and the file's other FUNCTION addresses still pass `fncmp.py -q`.
- A changed DRAFT body can shift the compiler's scheduling of the next function in the file; the FUNCTION tag directly after each edited DRAFT is rechecked, and an edit that breaks it is reverted.
- No match: the draft keeps its tag and a one-line note with the differing-line count, what differs, and the variants tried. The file compiles.
- `.venv/bin/python tools/claimed.py < /dev/null` prints nothing.
- One row per address appended to `build/results/<job-id>.tsv`: `0xADDR<TAB>MATCH|DRAFT|SKIP<TAB>differing-lines<TAB>file<TAB>note`.

## Environment

- `fncmp.py` compiles through the `tools/ccd.py` spool, so it runs inside the sandbox; a compile under load takes up to a minute.
- A foreground command moves to the background after 120 s, so a command checks at most two FUNCTION tags; background commands, sleeps and monitors are not used.
- `wc`, `cat`, `xargs` and `grep` with no file list wait on stdin; pass `< /dev/null`.
- Output is read through `head`, `tail` or `grep`, never whole files; context stays under 100k tokens.
- No commits, no `ninja`, and no edits under `tools/`, `config/` or `include/`. Tool bugs and permission denials go into the report, unworked-around.

## Report

One line per address: MATCH with the change that matched, or DRAFT with differing lines, what differs and what was tried. Then the edited files and the results file.
