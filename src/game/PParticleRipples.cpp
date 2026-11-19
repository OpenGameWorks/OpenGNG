#include "types.h"
#include "PParticleRipples.h"

// TODO(header): foreign declarations
extern "C" void FadeAndDie__15PParticleSystemFUi(void *, unsigned int);
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern unsigned char __vt__16PParticleRipples[];

// FUNCTION: 0x001EDAB0 FindFreeRipple__16PParticleRipplesFv
int PParticleRipples::FindFreeRipple() {
    int i = 0;
    unsigned int off = 0;
    do {
        if (*((unsigned char *)this + off + 0x11C) == 0) {
            return i;
        }
        i++;
        off += 0x40;
    } while (i < 0x1E);
    return -1;
}

// FUNCTION: 0x001EDAF0 FadeAndDie__16PParticleRipplesFUi
void PParticleRipples::FadeAndDie(unsigned int uArg) {
    FadeAndDie__15PParticleSystemFUi(this, uArg);
    m_unk018 = 0;
}

// FUNCTION: 0x001EDF30 AutoEmit__16PParticleRipplesFfPfffff
void PParticleRipples::AutoEmit(float fArg0, float *pArr, float fArg2, float fArg3, float fArg4, float fArg5) {
    m_unk868 = fArg0;
    m_unk86C = 0;
    memcpy(m_unk870, pArr, 0x10);
    m_unk880 = fArg2;
    m_unk884 = fArg3;
    m_unk888 = fArg4;
    m_unk88C = fArg5;
}

// DRAFT: 0x001EDFB0 Create__16PParticleRipplesFPffff
// note: DIFF 14 words; original builds 0.01f/0.015f with lui/ori/mtc1 and copies the 1.0f quad via lq into $a3 with sq in the delay slot, ours loads literals from $gp and copies via $v0. Tried: plain literals (14), union bit patterns (17, 0x30 frame), literal locals declared first (14).
void PParticleRipples::Create(float *pArr, float fArg1, float fArg2, float fArg3) {
    float local[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    Create(pArr, local, fArg1, fArg2, 0.0f, fArg3, 0.01f, 0.015f);
}

// FUNCTION: 0x001EE2C0 __ct__16PParticleRipplesFv
PParticleRipples::PParticleRipples() {
    __ct__15PParticleSystemFv(this);
    m_unk000 = __vt__16PParticleRipples;
    m_unk890 = 0;
    m_unk894 = 0;
    m_unk860 = 0;
    m_unk8A8 = 0;
    m_unk8B0 = 0;
    m_unk868 = 0.0f;
    m_unk86C = 0;
    m_unk898 = 0;
    m_unk89C = 0x3ECCCCCD;
    m_unk8A0 = 0x3ECCCCCD;
    m_unk8A4 = 0x3F000000;
    m_unk8B1 = 0;
}
