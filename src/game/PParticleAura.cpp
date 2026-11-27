// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "PParticleAura.h"

// TODO(header): foreign declarations
struct tagParticleAuraParams;
class PMat4;
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern "C" void *memcpy(void *, const void *, unsigned int);
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern "C" void sceVu0UnitMatrix(float (*pMatrix)[4]);
extern "C" void MulVector__5PMat4FPfPf(PMat4 *pMat, float *pSrc, float *pDst);
extern "C" void *AllocAuraParticle__16PParticleManagerFv(void *pManager);
extern "C" void FreeAuraParticle__16PParticleManagerFP13tagVuParticle(void *pManager, void *pParticle);
extern "C" float sqrtf(float);
extern unsigned char __vt__13PParticleAura[];
extern char gGfxEng[1504384];
extern float GAME_FPS;

struct tagVuParticle {
    float unk0;
    float unk4;
    float unk8;
    float unkC;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
};

// FUNCTION: 0x001DB7D0 SetPosition__13PParticleAuraFPfPf
void PParticleAura::SetPosition(float *pPos, float *pUnused) {
    sceVu0CopyVector(m_unk120, pPos);
    sceVu0CopyVector(&m_unk80, m_unk120);
}

// FUNCTION: 0x001DB810 ModifyPosition__13PParticleAuraFP5PMat4
void PParticleAura::ModifyPosition(PMat4 *pMat) {
    if (pMat != 0) {
        MulVector__5PMat4FPfPf(pMat, m_unk120, m_unkE0);
        sceVu0CopyVector(&m_unk80, m_unk120);
    }
}

// FUNCTION: 0x001DB850 Render__13PParticleAuraFv
void PParticleAura::Render() {
}

// DRAFT: 0x001DB860 Animate__13PParticleAuraFf
// note: 51 words vs 134-word original (ours 131 words); branch sense at clamp and compare, m_unk130 cached not reloaded per tail store, add.s and compare operand orders tried (flip worse or equal)
void PParticleAura::Animate(float fDelta) {
    if (m_unk130 != 0) {
        if (m_unk17 == 0 && m_unkA4 == 0) {
            ((tagVuParticle *)m_unk130)->unkC = 0;
            return;
        }
        if (m_unk18 == 0) {
            m_unk15 = 0;
        }
        if (m_unk15 == 0) {
            ((tagVuParticle *)m_unk130)->unkC = 0;
        } else {
            ((tagVuParticle *)m_unk130)->unkC = m_unkE0[8];
        }
        if (m_unkE0[9] != 0.0f && m_unk17 == 0 && fDelta != 0.0f) {
            m_unk138 = m_unk134 + m_unk138;
            if (m_unk138 <= 0.61f * m_unkE0[7] || !(m_unk138 < m_unkE0[7])) {
                m_unk134 = -m_unk134;
            }
            goto block_24;
        }
        if (m_unk17 != 0 && fDelta != 0.0f) {
            float fTime = m_unk138;
            if (!(fTime <= 0.0f)) {
                float fLeft = fTime - m_unkE0[7] / (0.5f * GAME_FPS);
                if (fLeft <= 0.0f) {
                    fLeft = 0.0f;
                }
                m_unk138 = fLeft;
                goto block_24;
            }
            FreeAuraParticle__16PParticleManagerFP13tagVuParticle(gGfxEng + 0x154F00, m_unk130);
            m_unk130 = 0;
            m_unk16 = 1;
            m_unk15 = 0;
            return;
        }
        m_unk138 = m_unkE0[7];
block_24:
        ((tagVuParticle *)m_unk130)->unk0 = m_unk120[0];
        ((tagVuParticle *)m_unk130)->unk4 = m_unk120[1];
        ((tagVuParticle *)m_unk130)->unk8 = m_unk120[2];
        ((tagVuParticle *)m_unk130)->unk10 = m_unkE0[4];
        ((tagVuParticle *)m_unk130)->unk14 = m_unkE0[5];
        ((tagVuParticle *)m_unk130)->unk18 = m_unkE0[6];
        ((tagVuParticle *)m_unk130)->unk1C = m_unk138 * m_unkCC;
    }
}

// DRAFT: 0x001DBA80 Create__13PParticleAuraFP21tagParticleAuraParamsfff
// note: size 0x1F4 vs 0x1FC; clamp branch shape differs (no E7 reload at join), 0.6f built before E7 load, m_unk130 cached instead of reloaded per store; tried ternary, else-form, operand reorder, -str readonly (strings now match)
int PParticleAura::Create(tagParticleAuraParams *pParams, float fX, float fY, float fZ) {
    float fDiv;

    memcpy(m_unkE0, pParams, 0x40);
    m_unkE0[0] = m_unkE0[0] + fX;
    m_unkE0[1] = m_unkE0[1] + fY;
    m_unkE0[2] = m_unkE0[2] + fZ;
    sceVu0CopyVector(m_unk120, m_unkE0);
    m_unk04 = 1;
    m_unk15 = 0;
    m_unk18 = 0;
    m_unk14 = 1;
    sceVu0UnitMatrix((float (*)[4])&m_unk40);
    m_unkA0 = m_unkE0[8];
    m_unk0C = 0xA;
    fDiv = 60.0f * (1.0f - m_unkE0[9]);
    if (fDiv <= 2.0f) {
        fDiv = 2.0f;
    }
    m_unk134 = -(m_unkE0[7] * 0.6f / fDiv);
    *(u_long128 *)&m_unk80 = *(u_long128 *)m_unkE0;
    m_unk90 = m_unkA0;
    m_unk94 = m_unkA0;
    m_unk98 = m_unkA0;
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
    m_unk130 = AllocAuraParticle__16PParticleManagerFv(gGfxEng);
    if (m_unk130 == 0) {
        CdsAssert("PParticleAura.cpp", 0x45, "mpParticle");
    }
    ((float *)m_unk130)[0] = m_unkE0[0];
    ((float *)m_unk130)[1] = m_unkE0[1];
    ((float *)m_unk130)[2] = m_unkE0[2];
    ((float *)m_unk130)[3] = m_unkE0[8];
    ((float *)m_unk130)[4] = m_unkE0[4];
    ((float *)m_unk130)[5] = m_unkE0[5];
    ((float *)m_unk130)[6] = m_unkE0[6];
    ((float *)m_unk130)[7] = m_unkE0[7];
    m_unk138 = ((float *)m_unk130)[7];
    return 1;
}

// FUNCTION: 0x001DBC80 __dt__13PParticleAuraFv
extern "C" void *__dt__13PParticleAuraFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PParticleAura *pSelf = (PParticleAura *)pThis;
        *(void **)pThis = __vt__13PParticleAura;
        if (pSelf->m_unk130 != 0) {
            *(int *)((char *)pSelf->m_unk130 + 0xC) = 0;
            *(int *)((char *)pSelf->m_unk130 + 0x1C) = 0;
            FreeAuraParticle__16PParticleManagerFP13tagVuParticle(gGfxEng + 0x154F00, pSelf->m_unk130);
        }
        pSelf->m_unk130 = 0;
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001DBD10 __ct__13PParticleAuraFv
PParticleAura::PParticleAura() {
    *(void **)this = __vt__13PParticleAura;
    m_unk130 = 0;
    m_unk134 = 0.0f;
    m_unk138 = 0.0f;
}
