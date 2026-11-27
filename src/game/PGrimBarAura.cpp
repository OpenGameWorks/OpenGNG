#include "types.h"
#include "Debug.h"
#include "PGrimBarAura.h"
#include "PParticleManager.h"
#include "PDisplayList.h"

// TODO(header): foreign declarations
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern "C" void __dla__FPv(void *);
extern "C" void *__nwa__FUi(unsigned int size);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern unsigned char __vt__12PGrimBarAura[];
extern char gGfxEng[1504384];

// FUNCTION: 0x00213DA0 FrustrumTest__12PGrimBarAuraFP9PFrustrumPfff
void PGrimBarAura::FrustrumTest(PFrustrum *, float *, float, float) {
    *(int *)((char *)this + 0xA4) = 1;
}

// DRAFT: 0x00213DB0 Animate__12PGrimBarAuraFf
// note: 58 words differ: register allocation (m_unk108/m_unk10C/m_unk100 f-regs swapped), loop off/pOut registers swapped, element-test c.eq.s operand order, clamp branch layout. Tried: if/else clamp (77), ternary clamp (77), swapped i/off declarations (60), 0.0f compare operand order (58), unsigned char pElem (58).
void PGrimBarAura::Animate(float fDelta) {
    if (m_unk15 != 0) {
        m_unk08 = ((PDisplayList *)*(char **)(gGfxEng + 0x154C80))->AllocParticles(m_unk04, 2);
        if (m_unk08 == 0) {
            CdsAssert("PGrimBarAura.cpp", 0x63, "mpVuParticles");
        }
        if (m_unk100 != 0.0f) {
            float fT = m_unk10C + (fDelta * m_unk108);
            m_unk10C = fT;
            if ((fT <= 0.6f) || !(fT < 1.0f)) {
                m_unk108 = -m_unk108;
            }
        }
        unsigned int i = 0;
        int off = 0;
        while (i < m_unk04) {
            unsigned char *pElem = (unsigned char *)m_unkE0 + off;
            char *pOut = (char *)m_unk08 + off;
            if (*(float *)(pElem + 0x10) != 0.0f && pElem[0x14] == 0) {
                float v = *(float *)(pElem + 0x10) - (fDelta * (1.0f / m_unk104));
                if (v <= 0.0f) {
                    v = 0.0f;
                }
                *(float *)(pElem + 0x10) = v;
            }
            off += 0x20;
            i++;
            *(u_long128 *)pOut = *(u_long128 *)pElem;
            *(u_long128 *)(pOut + 0x10) = m_unkF0;
            *(float *)(pOut + 0x1C) = *(float *)(pOut + 0x1C) * (*(float *)(pElem + 0x10) * m_unk10C);
            *(float *)(pOut + 0xC) = m_unkA0;
        }
    }
}

// DRAFT: 0x00213F50 EnableParticle__12PGrimBarAuraFib
// note: original keeps addiu +0x10/+0x14 before the index addu and reloads m_unkE0 per block; MW folds the constant into sw/sb immediates (14 words). Tried: inline offsets, locals, char* base; none reduced the count.
void PGrimBarAura::EnableParticle(int nIndex, bool bEnable) {
    if (nIndex < (int)m_unk04) {
        if (bEnable) {
            char *pBase = m_unkE0 + 0x10;
            *(float *)(pBase + (nIndex << 5)) = 1.0f;
        }
        char *pByte = m_unkE0 + 0x14;
        *(pByte + (nIndex << 5)) = bEnable;
    }
}

// FUNCTION: 0x00213FA0 SetParticlePos__12PGrimBarAuraFiPf
void PGrimBarAura::SetParticlePos(int nIndex, float *pPos) {
    if (nIndex < (int)m_unk04) {
        *(u_long128 *)(m_unkE0 + (nIndex << 5)) = *(u_long128 *)pPos;
    }
}

// DRAFT: 0x00213FD0 Create__12PGrimBarAuraFifffPf
// note: 42 words differ (size 0x150 vs 0x154). Original copies nNum after the nonzero branch, and our prologue copies it before; the clamp uses c.le.s/bc1t. Tried: early return on nNum==0 (58 words), reversed clamp compare (42, no change). Open: prologue order, bc1 sense, gGfxEng constant form.
int PGrimBarAura::Create(int nNum, float fA, float fB, float fC, float *pPos) {
    if (nNum != 0) {
        if (!PParticleSystem::Create(nNum, false)) {
            return 0;
        }
        m_unkE0 = (char *)__nwa__FUi(nNum << 5);
        if (m_unkE0 == 0) {
            CdsAssert("PGrimBarAura.cpp", 0x2D, "mpAuraParticles");
        }
        memset(m_unkE0, 0, nNum << 5);
        m_unk100 = fB;
        m_unk104 = fC;
        m_unkF0 = *(u_long128 *)pPos;
        float t = 60.0f * (1.0f - m_unk100);
        if (t <= 2.0f) {
            t = 2.0f;
        }
        m_unk108 = -(1.0f / t);
        m_unkA0 = fA;
        m_unkD4 = 3;
        m_unk10 = ((PParticleManager *)(gGfxEng + 0x154F00))->GetFxTexture(0x84000004);
        m_unk30 = 0x48;
        m_unk15 = 1;
        return 1;
    }
    return 1;
}

// FUNCTION: 0x00214130 __dt__12PGrimBarAuraFv
extern "C" void *__dt__12PGrimBarAuraFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PGrimBarAura *pSelf = (PGrimBarAura *)pThis;
        *(void **)pThis = __vt__12PGrimBarAura;
        if (pSelf->m_unkE0 != 0) {
            __dla__FPv(pSelf->m_unkE0);
            pSelf->m_unkE0 = 0;
        }
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x002141B0 __ct__12PGrimBarAuraFv
PGrimBarAura::PGrimBarAura() {
    *(void **)this = __vt__12PGrimBarAura;
    m_unkE0 = 0;
    m_unk100 = 0.0f;
    m_unk104 = 0.0f;
    m_unk10C = 1.0f;
}
