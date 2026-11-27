#ifndef PRANDOM_H
#define PRANDOM_H

// The particle systems' linear congruential generator (the multiplier and increment of MSVC rand).
// Each system keeps its seed in an int member at 0xD0. The original inlines this step at every call
// site; spelling it out in place loads the caller's range literals in the other order, so the inline
// is part of the matching source. The helper's name is ours; no string in the executable names it.
inline float ParticleRand01(int &nSeed) {
    nSeed = nSeed * 0x343FD + 0x269EC3;
    return 0.000030517578f * (float)((nSeed >> 16) & 0x7FFF);
}

#endif
