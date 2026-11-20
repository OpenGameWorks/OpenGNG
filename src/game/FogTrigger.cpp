#include "types.h"
#include "FogTrigger.h"

// TODO(header): foreign declarations
extern unsigned char __vt__10FogTrigger[];
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
extern "C" void __dl__FPv(void *pMem);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(float (*pA)[4], float (*pB)[4]);
extern "C" void SetColor__11PZBufferFogFPfbf(void *pThis, float *pColor, bool bFlag, float fTime);
extern "C" void SetDensity__11PZBufferFogFfbf(void *pThis, float fDensity, bool bFlag, float fTime);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern char gEng[105360];
extern char *mPlayerAPI__13EntityManager;

// FUNCTION: 0x001CEF10 __dt__10FogTriggerFv
extern "C" FogTrigger *__dt__10FogTriggerFv(FogTrigger *pThis, short nFlag)
{
    if (pThis != 0) {
        pThis->m_unk0 = __vt__10FogTrigger;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// DRAFT: 0x001CEF90 Execute__10FogTriggerFv
// note: 96 words differ; original tests -2 first, reuses one mPlayerAPI load for both 0x3C and +0x190, and has different case 1 store/reload and lbu 0x200 tail layout. Tried case orders 1,0,-1 (99), -1,0,1 (96), if-chain (100), explicit case -2 at top (101) and bottom (101).
void FogTrigger::Execute()
{
    float fColor[3];
    char *pPlayer;
    char *pTarget;
    char *pAlt;

    switch (m_unk20) {
    case -1:
        memcpy(m_unk1F0, m_unk1D4, 0xC);
        SetState__15EntityBaseClassFi(this, 0);
        return;
    case 0:
        if (m_unk200 == 0) {
            pPlayer = mPlayerAPI__13EntityManager;
            pTarget = pPlayer + 0x190;
            pAlt = *(char **)(pPlayer + 0x3C);
            if (pAlt != 0) {
                pTarget = pAlt + 0x80;
            }
            if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])m_unk1F0, (float (*)[4])pTarget) <= m_unk1E0) {
                SetState__15EntityBaseClassFi(this, 1);
            }
        }
        pPlayer = mPlayerAPI__13EntityManager;
        pTarget = pPlayer + 0x190;
        pAlt = *(char **)(pPlayer + 0x3C);
        if (pAlt != 0) {
            pTarget = pAlt + 0x80;
        }
        if (!(Distance__7MathAPIFPA4_fPA4_f((float (*)[4])m_unk1F0, (float (*)[4])pTarget) <= m_unk1E0)) {
            m_unk200 = 0;
        }
        return;
    case 1:
        m_unk204 = (PZBufferFog *)(gEng + 0x8750);
        if (m_unk204 == 0) {
            CdsAssert__FPciPc("FogTrigger.cpp", 0x2F, "m_unk204");
        }
        fColor[0] = 255.0f * m_unk1BC;
        fColor[1] = 255.0f * m_unk1C0;
        fColor[2] = 255.0f * m_unk1C4;
        SetColor__11PZBufferFogFPfbf(m_unk204, fColor, m_unk1CC != 0, m_unk1D0);
        SetDensity__11PZBufferFogFfbf(m_unk204, m_unk1B0, m_unk1B4 != 0, m_unk1B8);
        m_unk200 = 1;
        SetState__15EntityBaseClassFi(this, 0);
        return;
    }
}

// FUNCTION: 0x001CF120 __ct__10FogTriggerFv
extern "C" FogTrigger *__ct__10FogTriggerFv(FogTrigger *pThis)
{
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(pThis, 2, 0);
    pThis->m_unk0 = __vt__10FogTrigger;
    pThis->m_unk200 = 0;
    return pThis;
}
