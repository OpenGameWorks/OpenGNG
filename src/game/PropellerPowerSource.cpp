// FLAGS: -str readonly
#include "types.h"
#include "PropellerPowerSource.h"
#include "PMNode.h"
#include "CameraAPI.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);
class PParticleSystem;
extern unsigned char gEng[];
extern unsigned char gGfxEng[];
extern char mCameraAPI__13EntityManager;
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void SpawnPickups__15EntityBaseClassFiiPA4_fb(EntityBaseClass *pSelf, int nA, int nB, float (*pTable)[4], bool bFlag);
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("PropellerPowerSource.cpp", line, #cond))

// Create__16PParticleManagerFUifffP6PMNodeb and IsValid__16PParticleManagerFP15PParticleSystem.
class PParticleManager {
public:
    void *Create(unsigned int nId, float fA, float fB, float fC, PMNode *pNode, bool bFlag);
    bool IsValid(PParticleSystem *pSys);
};

// Slot view of PParticleSystem: slot 0x08 is virtual 0, so Start (0x20) is virtual 6.
class PParticleSystemView {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Render();
    virtual void ModifyPosition(void *pMat);
    virtual void FrustrumTest(void *pFrustrum, float *pA, float fB, float fC);
    virtual void FadeAndDie(unsigned int nUnused);
    virtual void Start();
};

// FUNCTION: 0x001F2BF0 __dt__20PropellerPowerSourceFv
PropellerPowerSource::~PropellerPowerSource() {
}

// FUNCTION: 0x001F2CA0 SetEditableVars__20PropellerPowerSourceFPc
void PropellerPowerSource::SetEditableVars(char *pSrc) {
    memcpy(&m_unk1B0, pSrc, 0x20);
    m_unk1D0 = 1000;
    PMNode *pEng = *(PMNode **)gEng;
    if (pEng != 0) {
        pEng->RecurseResetAnimByID(m_unk1B4);
    }
}

// DRAFT: 0x001F2CF0 OnHitEvent__20PropellerPowerSourceFP15EntityBaseClassiUiUi
// note: shared exit matches the original (if/else assigns nRet, one return); still DIFF, see report
int PropellerPowerSource::OnHitEvent(EntityBaseClass *pOther, int nA, unsigned int nB, unsigned int nC) {
    int nRet;
    if ((*(unsigned int *)((char *)pOther + 0x10C) & 0x11) != 0) {
        float fShake = 3.5f * (1.0f - (float)(m_unk1D0 / 1000 + ((unsigned int)m_unk1D0 >> 31)));
        if (m_unk1BC != 0) {
            ((CameraAPI *)&mCameraAPI__13EntityManager)->ShakeScreen(0.0f, 0.5f, fShake, 0);
        }
        FlashTexture(0x84000008, 10);
        PParticleManager *pParticleMgr = (PParticleManager *)gGfxEng;
        CDS_ASSERT(0xC8, pParticleMgr);
        char *pBase = m_unk3C;
        float *pSrc = (pBase != 0) ? (float *)(pBase + 0x80) : &m_unk190;
        PParticleSystemView *pSystem = (PParticleSystemView *)pParticleMgr->Create(0x830001F5, pSrc[0], pSrc[1], pSrc[2], 0, 1);
        if (pSystem != 0 && pParticleMgr->IsValid((PParticleSystem *)pSystem)) {
            pSystem->Start();
        }
        if (pSystem != 0 && pParticleMgr->IsValid((PParticleSystem *)pSystem)) {
            pSystem->FadeAndDie(0);
        }
        int nOld = m_unk1D0;
        bool bType3 = (pOther->m_unk08 == 3);
        m_unk1D0 = nOld - nA;
        if (m_unk1D0 <= 0) {
            m_unk1D0 = 0;
            if (!bType3 && nOld != 0) {
                m_unk1D0 = 1;
            }
        }
        if (bType3) {
            m_unk1D8 += nA;
            if (m_unk1D8 >= 0x12C) {
                SpawnPickups__15EntityBaseClassFiiPA4_fb(this, 4, 1, 0, 1);
                m_unk1D8 = 0;
            }
        }
        SetState(1);
        nRet = 1;
    } else {
        nRet = 0;
    }
    return nRet;
}

// FUNCTION: 0x001F3200 __ct__20PropellerPowerSourceFv
PropellerPowerSource::PropellerPowerSource() : EntityBaseClass((LoadClass)5, 0) {
    *(unsigned int *)((char *)this + 0x10C) = 0x31F0308;
    *(unsigned int *)((char *)this + 0x104) = 0x40000000;
    *(unsigned int *)((char *)this + 0x108) = 0x40000000;
    *(unsigned char *)((char *)this + 0x103) = 0xFF;
    EnableSleep(false, false);
}
