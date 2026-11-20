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
extern "C" void *InstanceIsValid__15EntityBaseClassFUi(unsigned int nId);
extern "C" void HalfDestroy__15PropellerEngineFv(void *pEngine);
extern "C" void Destroy__15PropellerEngineFv(void *pEngine);
extern "C" void TriggerBGAnim__15EntityBaseClassFUiibUi(EntityBaseClass *pSelf, unsigned int nA, int nB, bool bC, unsigned int nD);
extern "C" void StartCutCamera__6CameraFUib(void *pCam, unsigned int nA, bool bB);
extern "C" void *GetPtrToInstance__13EntityManagerFUi(void *pMgr, unsigned int nId);
extern unsigned int Engine_IdleSeq[15];
extern unsigned int HitSequences[5];
extern unsigned char gInterface[0xA60];
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

// DRAFT: 0x001F2F20 Execute__20PropellerPowerSourceFv
// note: switch on m_unk20 with state 1 body before break; DIFF 177 from branch form at 0x28 (beq vs bne), E9 check placement, nS1 hoisted before E9 test; HitSequences/gEng/gInterface addends unverified. Tried if-chain (179), case 1 last (180), case 1 body after break (186).
void PropellerPowerSource::Execute() {
    switch (m_unk20) {
    case -1:
        m_unk1D0 = 1000;
        m_unk1D4 = 5;
        m_unk1D8 = 0;
        SetState(0);
        return;
    case 0:
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            PlaySequence(Engine_IdleSeq);
            ((PMNode *)m_unk3C)->DisableAllHitBox();
            m_unk1DC = PlaySound(0x5F);
        }
        return;
    case 1:
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            unsigned int nS0 = 0x23;
            int nD0 = m_unk1D0;
            unsigned int nS1;
            if (nD0 != 0) {
                nS1 = ((unsigned int)(nD0 * 5) / 1000U) + 1;
            } else {
                nS1 = 0;
            }
            if (nS1 < 5U) {
                if (m_unk1D4 != (int)nS1) {
                    m_unk1D4 = nS1;
                    PlaySequence((unsigned int *)HitSequences[nS1]);
                    ((PMNode *)m_unk3C)->DisableAllHitBox();
                    if (nS1 == 2) {
                        if (m_unk1B0 != 0) {
                            void *pEngine = InstanceIsValid__15EntityBaseClassFUi(m_unk1B0);
                            if (pEngine != 0) {
                                HalfDestroy__15PropellerEngineFv(pEngine);
                            }
                        }
                    }
                    nS0 = 0x25;
                    if (nS1 == 0) {
                        StopSoundBySoundRef(m_unk1DC);
                        nS0 = 0x64;
                        *(unsigned int *)((char *)this + 0x10C) &= 0xF8FFFFFF;
                        WriteApparitionData(0, 1, 0U);
                        WriteApparitionData(1, -3, 0U);
                        if (m_unk1B4 != 0) {
                            TriggerBGAnim__15EntityBaseClassFUiibUi(this, m_unk1B4, -1, 0, 0);
                        }
                        if (m_unk1B8 != 0) {
                            TriggerBGAnim__15EntityBaseClassFUiibUi(this, -1, m_unk1B8, 0, 0);
                        }
                        if (m_unk1C0 != 0) {
                            StartCutCamera__6CameraFUib(gEng + 0x19760, m_unk1C0, m_unk1C8 != 0);
                            *(short *)(gInterface + 0x414) = 0x1E;
                            *(int *)(gInterface + 0x1C0) &= ~0xE;
                        }
                        if (m_unk1B0 != 0) {
                            void *pEngine = InstanceIsValid__15EntityBaseClassFUi(m_unk1B0);
                            if (pEngine != 0) {
                                Destroy__15PropellerEngineFv(pEngine);
                            }
                        }
                        if (m_unk1BC != 0) {
                            ((CameraAPI *)&mCameraAPI__13EntityManager)->ShakeScreen(0.0f, 2.0f, 6.0f, 0);
                        }
                        if (m_unk1C4 != 0) {
                            void *pInst = GetPtrToInstance__13EntityManagerFUi(gEng + 0x137E0, m_unk1C4);
                            if (pInst != 0) {
                                *((unsigned char *)pInst + 0x1A) = 1;
                            }
                        }
                    }
                }
            }
            PlaySound(nS0);
        }
        break;
    case -2:
        return;
    }
    if (m_unk1D4 == 0 && m_unk160 == 0) {
        SetState(-2);
    }
}

// FUNCTION: 0x001F3200 __ct__20PropellerPowerSourceFv
PropellerPowerSource::PropellerPowerSource() : EntityBaseClass((LoadClass)5, 0) {
    *(unsigned int *)((char *)this + 0x10C) = 0x31F0308;
    *(unsigned int *)((char *)this + 0x104) = 0x40000000;
    *(unsigned int *)((char *)this + 0x108) = 0x40000000;
    *(unsigned char *)((char *)this + 0x103) = 0xFF;
    EnableSleep(false, false);
}
