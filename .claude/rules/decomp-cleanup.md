# Source cleanup: placeholders into real constructs

Cleanup jobs rewrite placeholder spellings into the source the original was written in, without changing a single compiled byte. A cleanup worker owns one source file; every `// FUNCTION:` in it matches before and after, and no DRAFT count grows.

## Allocation stand-ins

- `(T *)__nw__FUi(n)` followed by a null test and a ctor call is `new T(...)`; the class shell needs the ctor and the size (`SpawnEntity` in `mwcc-classes.md`).
- `__nwa__FUi(n * K)` is `new T[n]` with `sizeof(T) == K`: `new PSTAnimKeyFrame[n]` (`PSTAnimChannel::Load`), `new PSTAnimChannel *[n]` (`PSTAnim::Load`), `new unsigned char[n]` for a raw buffer (`PSlideShow::Create`).
- `__dl__FPv(p)` is `delete p;` and `__dla__FPv(p)` is `delete[] p;`, cast to the member's real pointee type when the member is `void *` (`delete[] (unsigned char *)m_pBuf` in `PSlideShow::~PSlideShow`).
- A `0x10`-cookie array (`__nwa__FUi(n * K + 0x10)` passed to `__construct_new_array`, freed as `__dla__FPv((char *)p - 0x10)`) is `new T[n]` / `delete[] p` of a class with a ctor or dtor; it converts once that class is declared with both.
- The `extern "C"` declarations of the stand-ins go once the file no longer uses them.

## Assertions

- `CdsAssert(file, line, expr)` is declared in `Debug.h`, which every C++ source includes. C sources (`sound.c`, `FastMath.c`) keep `CdsAssert__FPciPc`.

## Names

- Assert text names the member or parameter it tests: `"mpKeyFrameTable"`, `"muNumKeyFrames"` and `"poFile"` named `PSTAnimChannel`'s members and `Load`'s parameter. The prefix gives the type (`mu` unsigned, `mp` pointer, `mf` float, `mb` bool).
- A rename in a header that other files include touches every one of them; that work stays with the coordinator.

## Procedure

1. Score every FUNCTION and DRAFT tag in the file first (`grep -n "^// \(FUNCTION\|DRAFT\):" FILE < /dev/null`), at most two per command.
2. Convert one site at a time and rescore the function that contains it; a site that changes its function's result is reverted and named in the report.
3. Rescore every tag at the end, and append one row per converted function to `build/results/<job-id>.tsv`.
