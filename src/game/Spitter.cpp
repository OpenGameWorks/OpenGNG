// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "Spitter.h"

// TODO(header): foreign declarations
#include "MathAPI.h"
#include "Physics.h"
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);
extern "C" void *Spawn__13EntityManagerFUibi(void *, unsigned int, bool, int);
extern void *mpEntMgr__15EntityBaseClass;
extern unsigned char gEng[0x1A000];
extern void *mPlayerAPI__13EntityManager;

// The game's assert evaluates the condition at runtime, so assert(!"msg") keeps the literal-address test.
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert("Spitter.cpp", line, #cond))

// FUNCTION: 0x001D9F90 __dt__7SpitterFv
Spitter::~Spitter() {}

// FUNCTION: 0x001D9FF0 GetClassName__7SpitterFv
char *Spitter::GetClassName() {
    return "Spitter";
}

// FUNCTION: 0x001DA000 NeedsToBeWoken__7SpitterFv
int Spitter::NeedsToBeWoken() {
    return m_unk1E4;
}

// FUNCTION: 0x001DA010 GetWokenVarPos__7SpitterFv
int Spitter::GetWokenVarPos() {
    return 8;
}

// FUNCTION: 0x001DA020 SpawnItem__7SpitterFv
void Spitter::SpawnItem() {
    Spitter *pItem;
    float aTmp[4];

    if (m_unk1C0 == 3) {
        pItem = (Spitter *)Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0x78, false, 0);
        CDS_ASSERT(0xAF, pItem);
        {
            char *pSrc = m_unk3C ? m_unk3C + 0x90 : (char *)m_unk1A0;
            unsigned char *pDst = (unsigned char *)pItem->m_unk3C;
            if (pDst) {
                *(u_long128 *)(pDst + 0x90) = *(u_long128 *)pSrc;
                pDst[0x3E] |= 8;
            } else {
                *(u_long128 *)pItem->m_unk1A0 = *(u_long128 *)pSrc;
            }
        }
        {
            char *pSrc = m_unk3C ? m_unk3C + 0x80 : (char *)m_unk190;
            unsigned char *pDst = (unsigned char *)pItem->m_unk3C;
            if (pDst) {
                *(u_long128 *)(pDst + 0x80) = *(u_long128 *)pSrc;
                pDst[0x3E] |= 8;
            } else {
                *(u_long128 *)pItem->m_unk190 = *(u_long128 *)pSrc;
            }
        }
        pItem->m_unk1B4 = m_unk1DC;
        pItem->m_unk1B8 = m_unk1D4;
        pItem->EnableSleep(false, false);
        return;
    }

    pItem = (Spitter *)Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0x15, false, 0);
    CDS_ASSERT(0xBF, pItem);
    {
        char *pSrc = m_unk3C ? m_unk3C + 0x90 : (char *)m_unk1A0;
        unsigned char *pDst = (unsigned char *)pItem->m_unk3C;
        if (pDst) {
            *(u_long128 *)(pDst + 0x90) = *(u_long128 *)pSrc;
            pDst[0x3E] |= 8;
        } else {
            *(u_long128 *)pItem->m_unk1A0 = *(u_long128 *)pSrc;
        }
    }
    {
        char *pSrc = m_unk3C ? m_unk3C + 0x80 : (char *)m_unk190;
        unsigned char *pDst = (unsigned char *)pItem->m_unk3C;
        if (pDst) {
            *(u_long128 *)(pDst + 0x80) = *(u_long128 *)pSrc;
            pDst[0x3E] |= 8;
        } else {
            *(u_long128 *)pItem->m_unk190 = *(u_long128 *)pSrc;
        }
    }
    aTmp[0] = m_unk1D0;
    aTmp[1] = m_unk1D4;
    aTmp[2] = m_unk1D8;
    if (m_unk1C0 == 2) {
        pItem->m_unk200 = aTmp[0];
    }
    {
        char *pVel = m_unk3C ? m_unk3C + 0x90 : (char *)m_unk1A0;
        MathAPI::VectorRotateY(&aTmp, ((float *)pVel)[1]);
    }
    if (pItem->m_unk38) {
        *(u_long128 *)pItem->m_unk38 = *(u_long128 *)aTmp;
    }
    *(float *)&pItem->m_unk38->m_unk10C = m_unk1DC;
    *(int *)&pItem->m_unk1B8 = m_unk1C0;
    *(int *)&pItem->m_unk1BC = *(int *)&m_unk1E0;
    *(int *)&pItem->m_unk1E0 = *(int *)&m_unk1E8;
    pItem->EnableSleep(false, false);
}

// FUNCTION: 0x001DA290 SetEditableVars__7SpitterFPc
void Spitter::SetEditableVars(char *pSrc) {
    memcpy((char *)this + 0x1B0, pSrc, 0x3C);
}

// FUNCTION: 0x001DA2A0 OnTimerEvent__7SpitterFUi
void Spitter::OnTimerEvent(unsigned int) {
}

// DRAFT: 0x001DA2B0 Execute__7SpitterFv
// note: 150 words differ. Original keeps this in s0 with a 0x40 frame; ours spills this to s1 (0x50 frame) and tests case 1 before -2. Tried: label orders (-2,0,-1) 159, (-2,-1,0) 175, case 1 first 167; pUnused as Distance arg 150 (kept); pUnused at top, typed mpEntMgr decl, inline pPlayer, mpEntMgr loaded into a local pMgr before the 0x5058 test: no change.
void Spitter::Execute() {
    float aPos[4];
    float fDist;

    if (*(int *)((char *)mpEntMgr__15EntityBaseClass + 0x5058)) {
        return;
    }

    switch (m_unk20) {
    case -1:
    case 0:
    case -2:
        *(unsigned int *)((char *)this + 0x10C) &= 0xF8FFFFFF;
        m_unk1F0 = 0;
        *(int *)&m_unk1EC = 0;
        if (m_unk1B0 == 0.0f && m_unk1B4 == 0.0f && m_unk1B8 == 0.0f) {
            CDS_ASSERT(0x33, !"eif 0, 0, 0 error.  see keith or ted");
        }
        {
            float *pSrc = m_unk3C ? (float *)(m_unk3C + 0x80) : m_unk190;
            m_unk1B0 = pSrc[0];
            m_unk1B4 = pSrc[1];
            m_unk1B8 = pSrc[2];
        }
        aPos[0] = m_unk1B0;
        aPos[1] = m_unk1B4;
        aPos[2] = m_unk1B8;
        {
            EntityBaseClass *pPlayer = (EntityBaseClass *)mPlayerAPI__13EntityManager;
            float *pPos = pPlayer->m_unk3C ? (float *)(pPlayer->m_unk3C + 0x80) : (float *)((char *)pPlayer + 0x190);
            float (*pUnused)[4];
            fDist = ((MathAPI *)aPos)->Distance((float (*)[4])pPos, pUnused);
        }
        if (fDist <= m_unk1BC) {
            if (*(unsigned char *)((char *)this + 0x1B) == 0) {
                EnableSleep(true, false);
            } else {
                EnableSleep(false, false);
            }
        }
        {
            float fT = m_unk1EC - *(float *)&gEng[0x1E8];
            if (fT <= 0.0f) {
                *(int *)&m_unk1EC = 0;
            } else {
                m_unk1EC = fT;
            }
        }
        if (fDist < m_unk1BC) {
            SetState(1);
        }
        break;
    case 1:
        if (m_unk1C0 == 0) {
            PlaySound(0x197);
        }
        if (m_unk1C0 == 1) {
            PlaySound(0x2C5);
        }
        SpawnItem();
        m_unk1F0++;
        if (m_unk1F0 < m_unk1C8) {
            m_unk1EC = m_unk1C4 * 60.0f;
        } else {
            m_unk1EC = m_unk1CC * 60.0f;
            m_unk1F0 = 0;
        }
        SetState(0);
        break;
    }
}

// FUNCTION: 0x001DA570 __ct__7SpitterFv
Spitter::Spitter() : EntityBaseClass((EntityBaseClass::LoadClass)2, 5) {}
