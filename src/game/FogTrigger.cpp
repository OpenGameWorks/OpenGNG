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

// FUNCTION: 0x001CEF70 GetClassName__10FogTriggerFv
const char *FogTrigger::GetClassName() {
    return "FogTrigger";
}

// FUNCTION: 0x001CEF80 SetEditableVars__10FogTriggerFPc
void FogTrigger::SetEditableVars(char *pSrc) {
    memcpy((char *)this + 0x1B0, pSrc, 0x34);
}

// FUNCTION: 0x001CEF90 Execute__10FogTriggerFv
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
        break;
    case 0:
        if (m_unk200 == 0) {
            pPlayer = mPlayerAPI__13EntityManager;
            pAlt = *(char **)(pPlayer + 0x3C);
            pTarget = pPlayer + 0x190;
            if (pAlt != 0) {
                pTarget = pAlt + 0x80;
            }
            if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])m_unk1F0, (float (*)[4])pTarget) <= m_unk1E0) {
                SetState__15EntityBaseClassFi(this, 1);
            }
        }
        {
            char *pP = mPlayerAPI__13EntityManager;
            char *pA = *(char **)(pP + 0x3C);
            pTarget = pP + 0x190;
            if (pA != 0) {
                pTarget = pA + 0x80;
            }
        }
        if (!(Distance__7MathAPIFPA4_fPA4_f((float (*)[4])m_unk1F0, (float (*)[4])pTarget) <= m_unk1E0)) {
            m_unk200 = 0;
        }
        break;
    case 1:
        m_unk204 = (PZBufferFog *)(gEng + 0x8750);
        if (m_unk204 == 0) {
            CdsAssert__FPciPc("FogTrigger.cpp", 0x2F, "m_FogObj");
        }
        fColor[0] = 255.0f * m_unk1BC;
        fColor[1] = 255.0f * m_unk1C0;
        fColor[2] = 255.0f * m_unk1C4;
        SetColor__11PZBufferFogFPfbf(m_unk204, fColor, m_unk1CC != 0, m_unk1D0);
        SetDensity__11PZBufferFogFfbf(m_unk204, m_unk1B0, m_unk1B4 != 0, m_unk1B8);
        m_unk200 = 1;
        SetState__15EntityBaseClassFi(this, 0);
        break;
    case -2:
        break;
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
