// FLAGS: -str readonly
#include "types.h"
#include "HolyGround.h"
#include "EntityManager.h"
#include "TimerAPI.h"
#include "PMNode.h"
#include "PMat4.h"
#include "PParticleRipples.h"
#include "PParticleSystem.h"
#include "PParticleManager.h"

// TODO(header): foreign declarations
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern unsigned char __vt__10HolyGround[0x7C];
extern "C" float GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(EntityBaseClass *pEnt, float (*pMatrix)[4]);
extern "C" void SpawnPickups__15EntityBaseClassFiiPA4_fb(EntityBaseClass *pThis, int nType, int nCount, float (*pRect)[4], bool bFlag);
extern "C" void SetHolyGround__13EntityManagerFPA4_ffb(EntityManager *pThis, float (*pRect)[4], float fValue, bool bFlag);
extern "C" EntityManager *mpEntMgr__15EntityBaseClass;
extern float gEng[4][4];
extern unsigned int HolyGround_IdleSeq[0x10];
extern unsigned int HolyGround_ActiveSeq[0x10];
extern unsigned int HolyGround_ShatterSeq[0x10];
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__ct__16PParticleRipplesFv(void *pThis);
extern "C" void sceVu0UnitMatrix(float *pOut);
extern "C" void sceVu0ScaleVector(float *pOut, float *pIn, float fScale);
extern "C" void sceVu0AddVector(float *pOut, float *pA, float *pB);
extern char gGfxEng[1504384];
// Polymorphic view of PParticleSystem: ModifyPosition is virtual slot 3 (vtable offset 0x14).
class PSysView {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void ModifyPosition(PMat4 *pMat);
};

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("HolyGround.cpp", line, #cond))

// FUNCTION: 0x001A3320 GetClassName__10HolyGroundFv
const char *HolyGround::GetClassName() {
    return "Holy Ground";
}

// FUNCTION: 0x001A3A20 __ct__10HolyGroundFv
HolyGround::HolyGround() : EntityBaseClass((LoadClass)5, 0U) {}

// FUNCTION: 0x001A32C0 __dt__10HolyGroundFv
HolyGround::~HolyGround() {}

// FUNCTION: 0x001A3330 CreateRipplesFx__10HolyGroundFv
void HolyGround::CreateRipplesFx() {
    PMNode *pNode;
    PParticleRipples *apFx;
    if (*(char **)((char *)this + 0x3C)) {
        pNode = ((PMNode *)m_unk3C)->Find(0x7BF9ACB7);
        if (pNode) {
            float a[4] = {1.2f, 1.2f, 1.2f, 1.0f};
            float b[4] = {0.4f, 1.1f, 1.5f, 1.0f};
            float mat[4][4];
            apFx = (PParticleRipples *)__nw__FUi(0x8C0);
            if (apFx) apFx = (PParticleRipples *)__ct__16PParticleRipplesFv(apFx);
            CDS_ASSERT(0xDF, apFx);
            *(float *)((char *)apFx + 0x898) = 0.4f;
            *(float *)((char *)apFx + 0x89C) = 0.45f;
            *(float *)((char *)apFx + 0x8A0) = 0.45f;
            *(float *)((char *)apFx + 0x8A4) = 0.5f;
            apFx->Init(10, true, true);
            apFx->AutoEmit(120.0f, a, 0.0f, 18.0f, 0.0f, 45.0f);
            *(unsigned char *)((char *)apFx + 0x19) = 1;
            *(int *)((char *)apFx + 0x28) = 0;
            *(int *)((char *)apFx + 0x2C) = 0;
            ((PParticleManager *)(gGfxEng + 0x154F00))->Add((PParticleSystem *)apFx);
            sceVu0UnitMatrix((float *)mat);
            float w[4] = {0.0f, 1.0f, 0.0f, 1.0f};
            ((PMat4 *)mat)->RotateX(*(float *)(m_unk3C ? m_unk3C + 0x90 : (char *)this + 0x1A0));
            ((PMat4 *)mat)->RotateY(*(float *)((m_unk3C ? m_unk3C + 0x90 : (char *)this + 0x1A0) + 4));
            ((PMat4 *)mat)->RotateZ(*(float *)((m_unk3C ? m_unk3C + 0x90 : (char *)this + 0x1A0) + 8));
            ((PMat4 *)mat)->MulVector(w, w);
            sceVu0UnitMatrix((float *)mat);
            sceVu0ScaleVector(w, w, 4.8f);
            sceVu0AddVector(mat[3], w, (float *)(m_unk3C ? m_unk3C + 0x80 : (char *)this + 0x190));
            ((PSysView *)apFx)->ModifyPosition((PMat4 *)mat);
            pNode->AttachFx((unsigned int)apFx, 0.0f, 0.0f, -1.0f, -1.0f, true);

            apFx = (PParticleRipples *)__nw__FUi(0x8C0);
            if (apFx) apFx = (PParticleRipples *)__ct__16PParticleRipplesFv(apFx);
            CDS_ASSERT(0xFB, apFx);
            *(float *)((char *)apFx + 0x898) = 0.0f;
            *(float *)((char *)apFx + 0x89C) = 0.0f;
            *(float *)((char *)apFx + 0x8A0) = 0.0f;
            *(float *)((char *)apFx + 0x8A4) = 0.7f;
            apFx->Init(10, false, false);
            *(int *)((char *)apFx + 0x10) = ((PParticleManager *)(gGfxEng + 0x154F00))->GetFxTexture(0x84000005);
            *(long long *)((char *)apFx + 0x30) = 0x48;
            apFx->AutoEmit(120.0f, b, 0.0f, 18.0f, 0.0f, 45.0f);
            ((PParticleManager *)(gGfxEng + 0x154F00))->Add((PParticleSystem *)apFx);
            ((PSysView *)apFx)->ModifyPosition((PMat4 *)mat);
            pNode->AttachFx((unsigned int)apFx, 0.0f, 0.0f, -1.0f, -1.0f, true);
        }
    }
}

// FUNCTION: 0x001A3690 OnTimerEvent__10HolyGroundFUi
void HolyGround::OnTimerEvent(unsigned int nId) {
    if (nId == (unsigned int)m_unk1B4) {
        m_unk1C4 = 1;
        m_unk1B4 = EntityManager::mTimerAPI.CreateTimer(m_unk04, 120, true);
    } else if (nId == (unsigned int)m_unk1B8) {
        m_unk1C5 = 1;
    }
}

// FUNCTION: 0x001A36F0 OnHitEvent__10HolyGroundFP15EntityBaseClassiUiUi
int HolyGround::OnHitEvent(EntityBaseClass *pAttacker, int nDamage, unsigned int nA, unsigned int nB) {
    if (nDamage != 0) {
        if (pAttacker->m_unk08 == 3 && m_unk20 == 0) {
            *(unsigned int *)((char *)this + 0x10C) &= 0xF8FFFFFF;
            StopSoundBySoundRef(m_unk1BC);
            SetState(1);
            return 1;
        }
    }
    return 4;
}

// DRAFT: 0x001A3770 Execute__10HolyGroundFv
// note: variant 5 (else-if chain 2,1,0,-1 in source order, pointer local in float tail): 161 words, size 0x2a0 vs 0x2a8; goto/block-order variant also 161
void HolyGround::Execute() {
    if (m_unk20 == 2) {
        if (*((unsigned char *)this + 0xE9)) {
            PlaySequence(HolyGround_ActiveSeq);
            m_unk1C0 = ((PMNode *)m_unk3C)->Find(0x6A25E855);
            if (m_unk1C5) {
                *(float *)((char *)m_unk1C0 + 0x2C) = 0.0f;
            } else {
                m_unk1B8 = EntityManager::mTimerAPI.CreateTimer(m_unk04, 1, false);
            }
        }
        if (m_unk1C0) {
            *(float *)((char *)m_unk1C0 + 0x94) = GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, gEng);
            *((unsigned char *)m_unk1C0 + 0x3E) |= 8;
            if (m_unk1C5) {
                float t = *(float *)((char *)m_unk1C0 + 0x2C);
                if (t != 0.0f) {
                    float *p = (float *)((char *)m_unk1C0 + 0x2C);
                    if (t < 0.0f) {
                        *p = 0.0f;
                    } else {
                        *p = t - 0.01f;
                    }
                }
            }
        }
    } else if (m_unk20 == 1) {
        if (*((unsigned char *)this + 0xE9)) {
            WriteApparitionData(3, 1, 0);
            SetHolyGround__13EntityManagerFPA4_ffb(mpEntMgr__15EntityBaseClass, &m_unk190, m_unk1A4, true);
            PlaySequence(HolyGround_ShatterSeq);
            SpawnPickups__15EntityBaseClassFiiPA4_fb(this, 4, 2, 0, true);
            m_unk1C0 = ((PMNode *)m_unk3C)->Find(0x6A25E855);
        }
        if (m_unk1C0) {
            *(float *)((char *)m_unk1C0 + 0x94) = GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, gEng);
            *((unsigned char *)m_unk1C0 + 0x3E) |= 8;
        }
        if (m_unk160 == 0) {
            SetState(2);
        }
    } else if (m_unk20 == 0) {
        if (*((unsigned char *)this + 0xE9)) {
            PlaySequence(HolyGround_IdleSeq);
            CreateRipplesFx();
            m_unk1B4 = EntityManager::mTimerAPI.CreateTimer(m_unk04, 120, true);
            m_unk1BC = PlaySound(0x1C7);
        }
        if (m_unk1C4) {
            PlaySound(0x1C5);
            m_unk1C4 = 0;
        }
    } else if (m_unk20 == -1) {
        if (ReadApparitionData(3, 0)) {
            SetState(2);
        } else {
            *(unsigned int *)((char *)this + 0x10C) = 0x031F0308;
            *(float *)((char *)this + 0x104) = 1.0f;
            *(float *)((char *)this + 0x108) = 5.0f;
            *((unsigned char *)this + 0x103) = 0xFF;
            SetState(0);
            m_unk1C4 = 1;
            m_unk1C5 = 0;
        }
    }
}
