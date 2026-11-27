// FLAGS: -str readonly
#include "types.h"
#include "EffectAPI.h"

// TODO(header): foreign declarations
extern char gEng[105360];
extern char gGfxEng[1504384];

class EntityManager {
public:
    void *GetPtrToApparition(unsigned int arg0);
};

// The apparition's delete-event handler sits at vtable byte offset 0x60.
// Slots 0..21 are placeholders; the emitted offset is 0x60 with this layout.
class EffectTarget {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void SendDeleteEvent(int arg0);
};

// The drawable's draw handler sits at vtable byte offset 0xC; the update handler at 0x18.
class EffectDrawable {
public:
    virtual void Slot0(int arg0);
    virtual int Draw(PLightManager *arg0, int arg1, int arg2);
    virtual int Slot2(PLightManager *arg0);
    virtual void Slot3();
    virtual int Slot4(int arg0, int arg1, int arg2, float arg3, float arg4);
};

// The node's update handler sits at vtable byte offset 0x18 (slot 4 after the 8-byte header).
class EffectUpdateNode {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual int Slot4(int arg0, int arg1, int arg2, float arg3, float arg4);
};

// Pling and ghost entries are scanned through vtable slots 3 (type id) and 4 (owner pointer).
class EffectEntry {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual int Slot3();
    virtual void *Slot4();
};

// Animate walks entries through vtable offset 0x8 (slot 0, int arg) and 0xC (slot 1, float arg, int result).
class EffectAnimNode {
public:
    virtual void Slot0(int arg0);
    virtual int Slot1(float arg0);
};

class PMat4;

class PFrustrum {
public:
    int IntersectBox(float (*arg0)[2][4], PMat4 *arg1);
};

enum eBoxIntersect {
    eBoxIntersect_Unknown = 0
};

class EntityBaseClass {
public:
    char _pad00[4];
    int m_unk4;
    char _pad08[0x34];
    void *m_unk3C;
    char _pad40[0x127];
    unsigned char m_unk167;
};

class PMNode {
public:
    virtual ~PMNode();
    virtual void Unk0C();
    virtual void Unk10();
    virtual void Unk14();
    virtual void Unk18(float arg0, float arg1, int arg2, int arg3, int arg4);
    virtual void Unk1C();
    virtual void Unk20(void *arg0);
    void SetAllFrustrumTest(eBoxIntersect arg0);
    void *GetFirstMesh();
    void EnableFx(bool arg0, bool arg1);
    void SetAnimLoopCount(int nCount, bool bFlag);
    void EnableAnim(bool bA, bool bB);
    void SetFrameRate(float fRate, bool bFlag);
    void EnableOneRenderPassOnly(int nPass);

    char _pad04[8];
    int m_unkC;
    char _pad10[0x1C];
    float m_unk2C;
    char _pad30[0xE];
    unsigned char m_unk3E;
    char _pad3F[0x41];
    u_long128 m_unk80;
};

class PResourceManager {
public:
    PMNode *GetResource(unsigned int arg0, bool arg1);
};

extern PFrustrum *mpFrustum__15EntityBaseClass;
extern PResourceManager *mpResMgr__15EntityBaseClass;
extern unsigned char __vt__11PlingEffect[0x20];

extern "C" void __ct__6PArrayFv(void *);
extern "C" void Allocate__6PArrayFUi(void *, unsigned int);
extern "C" void Remove__6PArrayFPv(void *, void *);
extern "C" void __dl__FPv(void *);
extern "C" int Find__6PArrayFPv(void *pThis, void *pItem);
extern "C" void RemoveAt__6PArrayFi(void *pThis, int nIndex);
extern "C" void RemoveCurrent__6PArrayFv(void *pThis);
extern "C" int printf(const char *fmt, ...);
extern "C" void Add__6PArrayFPv(void *pThis, void *pItem);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" GhostEffect *__ct__11GhostEffectFP9PMeshNode(GhostEffect *pThis, PMeshNode *arg0);
extern "C" OneshotEffect *__ct__13OneshotEffectFUiUiP5PMat4P15EntityBaseClassfib(OneshotEffect *pThis, unsigned int arg0, unsigned int arg1, PMat4 *arg2, EntityBaseClass *arg3, float arg4, int arg5, bool arg6);
extern "C" OneshotEffect *__ct__13OneshotEffectFUiUiPA4_fPA4_fP15EntityBaseClassfbib(OneshotEffect *pThis, unsigned int arg0, unsigned int arg1, float (*arg2)[4], float (*arg3)[4], EntityBaseClass *arg4, float arg5, bool arg6, int arg7, bool arg8);
extern "C" PlingEffect *__ct__11PlingEffectFP15EntityBaseClassPA4_fUiUib(PlingEffect *pThis, EntityBaseClass *arg0, float (*arg1)[4], unsigned int arg2, unsigned int arg3, bool arg4);
class PMesh {
public:
    int Render(int arg0, bool *arg1, bool arg2);
};
extern "C" void sceVu0UnitMatrix(PMat4 *arg0);
void vu1SetWorldMatrix(PMat4 *arg0);
void vu1BeginMesh(eBoxIntersect arg0);
void vu1EndMesh();
float Round180(float arg0);
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern unsigned char mEffectAPI__13EntityManager[0x10];
extern unsigned char __vt__10EffectNode[0x40];
extern unsigned char __vt__11GhostEffect[0x20];
extern unsigned char __vt__13OneshotEffect[0x20];
extern unsigned char __vt__16MotionBlurEffect[0x20];
extern "C" int Create__16MotionBlurEffectFP6PMNodeUii(void *pThis, PMNode *arg0, unsigned int arg1, int arg2);
extern "C" void *__ct__11PMotionBlurFv(void *pThis);

// FUNCTION: 0x155980 CreateMotionBlurEffect__9EffectAPIFP6PMNodeUii
MotionBlurEffect *EffectAPI::CreateMotionBlurEffect(PMNode *arg0, unsigned int arg1, int arg2) {
    MotionBlurEffect *pEffect;
    if ((pEffect = (MotionBlurEffect *)__nw__FUi(0xC0)) != 0) {
        MotionBlurEffect *volatile pThis = pEffect;
        *(void **)pEffect = __vt__10EffectNode;
        pThis->m_unk4 = 0;
        *(unsigned char *)&pThis->m_unkC = 0;
        *(void **)pThis = __vt__16MotionBlurEffect;
        __ct__11PMotionBlurFv(&pThis->m_unk10);
        pThis->m_unk4 = 0;
        pEffect = pThis;
    }
    if (pEffect != 0) {
        if (m_unk0 >= 0x80) {
            CdsAssert("EffectAPI.cpp", 0x2D5, "mEffectList.GetCount() < MAX_EFFECTS");
        }
        if (Create__16MotionBlurEffectFP6PMNodeUii(pEffect, arg0, arg1, arg2) == 0) {
            delete pEffect;
            return 0;
        }
        Add__6PArrayFPv(this, pEffect);
        int nId = m_unk10;
        m_unk10 = nId + 1;
        pEffect->m_unk8 = nId;
    }
    return pEffect;
}

// DRAFT: 0x00155AC0 Update__11PlingEffectFf
// note: 81 words differ; float reg for t/m14, lq/lw order in owner copy, one-word shift before jal (also tried: swapped float compare operands, local m14 variant, no change)
int PlingEffect::Update(float arg0) {
    float f20 = arg0;
    if (m_unk4 != 0) {
        if (m_unk10 != 0 && m_unk20[0] == 0.0f) {
            EntityBaseClass *owner = m_unk10;
            u_long128 *src;
            if (owner->m_unk3C != 0) {
                src = (u_long128 *)((char *)owner->m_unk3C + 0x80);
            } else {
                src = (u_long128 *)((char *)owner + 0x190);
            }
            u_long128 tmp = *src;
            ((float *)&tmp)[1] += m_unk20[1];
            *(u_long128 *)(m_unk4 + 0x80) = tmp;
            ((unsigned char *)m_unk4)[0x3E] |= 8;
        }
        if (*(float *)&m_unk14 != 0.0f) {
            float t = *(float *)(m_unk4 + 0x2C) - *(float *)&m_unk14;
            if (t <= 0.0f) {
                SendDeleteEvent(m_unk18);
                return 0;
            }
            *(float *)(m_unk4 + 0x2C) = t;
        }
        float *pSlot = (float *)(m_unk4 + 0x90);
        pSlot[1] = Round180(180.0f + *(float *)(gEng + 0x19784));
        if (m_unk10->m_unk167 == 0) {
            f20 = 0.0f;
        }
        ((PMNode *)m_unk4)->Unk18(0.0f, f20, 0, 0, 0);
        int test = mpFrustum__15EntityBaseClass->IntersectBox((float (*)[2][4])(m_unk4 + 0x110), (PMat4 *)(m_unk4 + 0x40));
        ((PMNode *)m_unk4)->SetAllFrustrumTest((eBoxIntersect)test);
        if ((signed char)(((signed char *)m_unk4)[0x3F] & 7) != 0) {
            return 1;
        }
    }
    SendDeleteEvent(m_unk18);
    return 0;
}

// FUNCTION: 0x155C70 FindPling__9EffectAPIFP15EntityBaseClass
EffectNode *EffectAPI::FindPling(EntityBaseClass *arg0) {
    m_unk4 = 0;
    EffectNode *pNode = (m_unk0 != 0) ? m_ppEntries[0] : 0;
    if (pNode != 0) {
        do {
            if (((EffectEntry *)pNode)->Slot3() == 3 && ((EffectEntry *)pNode)->Slot4() == arg0) {
                return pNode;
            }
            pNode = 0;
            unsigned int nIndex = m_unk4 + 1;
            m_unk4 = nIndex;
            if (nIndex < m_unk0) {
                pNode = m_ppEntries[m_unk4];
            }
        } while (pNode != 0);
    }
    return 0;
}

// FUNCTION: 0x00155D50 GetEntity__11PlingEffectFv
EntityBaseClass *PlingEffect::GetEntity() {
    return m_unk10;
}

// FUNCTION: 0x00155D60 GetType__10EffectNodeFv
int EffectNode::GetType() {
    return 0;
}

// FUNCTION: 0x155D70 __ct__11PlingEffectFP15EntityBaseClassPA4_fUiUib
PlingEffect::PlingEffect(EntityBaseClass *arg0, float (*arg1)[4], unsigned int arg2, unsigned int arg3, bool arg4) {
    m_unkC = arg4;
    m_unk10 = arg0;
    m_unk18 = (arg0 != 0) ? arg0->m_unk4 : 0;
    m_unk14 = 0;
    m_unk4 = (int)mpResMgr__15EntityBaseClass->GetResource(arg2, 0);
    if (m_unk4 == 0) {
        CdsAssert("EffectAPI.cpp", 0x1BC, "mpMeshNode");
    }
    if (arg3 != 0) {
        PMNode *pAnim = mpResMgr__15EntityBaseClass->GetResource(arg3, 0);
        if (pAnim == 0) {
            CdsAssert("EffectAPI.cpp", 0x1BF, "pAnim");
        }
        ((PMNode *)m_unk4)->Unk20(pAnim);
        ((PMNode *)m_unk4)->SetAnimLoopCount(0, true);
        ((PMNode *)m_unk4)->EnableAnim(true, true);
    }
    *(u_long128 *)m_unk20 = *(u_long128 *)arg1;
    float fZero = 0.0f;
    *(float *)&m_unk2C = fZero;
    if (m_unk20[0] != fZero) {
        PMNode *pNode = (PMNode *)m_unk4;
        *(u_long128 *)&pNode->m_unk80 = *(u_long128 *)m_unk20;
        pNode->m_unk3E |= 8;
    }
}

// DRAFT: 0x155F00 CreatePling__9EffectAPIFP15EntityBaseClassPA4_fUiUib
// note: 20 differing words: this and the result swap s1/s0 (original this=s1, result=s0). Tried: direct cast init, separate pFound, cast at member access, pPling=0 then assign, pSelf=this local.
PlingEffect *EffectAPI::CreatePling(EntityBaseClass *arg0, float (*arg1)[4], unsigned int arg2, unsigned int arg3, bool arg4) {
    PlingEffect *pPling = 0;
    pPling = (PlingEffect *)FindPling(arg0);
    if (pPling != 0) {
        pPling->m_unk14 = 0;
        *(int *)(pPling->m_unk4 + 0x2C) = 0x3F800000;
    } else {
        pPling = (PlingEffect *)__nw__FUi(0x30);
        if (pPling != 0) {
            pPling = __ct__11PlingEffectFP15EntityBaseClassPA4_fUiUib(pPling, arg0, arg1, arg2, arg3, arg4);
        }
        if (pPling != 0) {
            int nId = m_unk10;
            m_unk10 = nId + 1;
            pPling->m_unk8 = nId;
            if (m_unk0 >= 0x80) {
                CdsAssert("EffectAPI.cpp", 0x1AD, "mEffectList.GetCount() < MAX_EFFECTS");
            }
            Add__6PArrayFPv(this, pPling);
        }
    }
    return pPling;
}

// FUNCTION: 0x156010 CreatePling__9EffectAPIFP15EntityBaseClassfUiUib
void EffectAPI::CreatePling(EntityBaseClass *arg0, float arg1, unsigned int arg2, unsigned int arg3, bool arg4) {
    float vec[4];
    vec[0] = 0.0f;
    vec[1] = arg1;
    vec[2] = 0.0f;
    CreatePling(arg0, &vec, arg2, arg3, arg4);
}

// FUNCTION: 0x156050 Render__11GhostEffectFP13PLightManager
int GhostEffect::Render(PLightManager *arg0) {
    *(unsigned char *)(gGfxEng + 0x158E22) = 1;
    u_long128 mat[4];
    int total = 0;
    sceVu0UnitMatrix((PMat4 *)mat);
    int size = 0x28;
    u_long128 *pVec = m_unk10;
    unsigned char *pFlag = m_unk90;
    if (m_unk9F != 0) {
        int off = 8 - m_unk9C;
        pVec = m_unk10 + off;
        pFlag = m_unk90 + off;
    }
    int i;
    for (i = 0; i < m_unk9C; i++, size -= 4, pVec++, pFlag++) {
        if (*pFlag != 0) {
            mat[3] = *pVec;
            vu1SetWorldMatrix((PMat4 *)mat);
            vu1BeginMesh((eBoxIntersect)4);
            total += ((PMesh *)m_unk98)->Render(size, 0, 0);
            vu1EndMesh();
        }
    }
    return total;
}

// DRAFT: 0x156150 Update__11GhostEffectFf
// note: 65 words differ; frame and parity match, but call position (0x60 vs 0x58) and wrap-return branch shape differ.
int GhostEffect::Update(float arg0) {
    u_long128 sp50;
    float mat[4][4];
    int par = (unsigned char)(m_unk9E + 1);
    m_unk9E = par;
    if ((par & 1) == 0) {
        return 1;
    }
    if (m_unk9F != 0) {
        short n = m_unk9C - 1;
        m_unk9C = n;
        if (n == 0) {
            return 0;
        }
        return 1;
    }
    sceVu0UnitMatrix((PMat4 *)mat);
    sp50 = *(u_long128 *)&((PMNode *)m_unk4)->m_unk80;
    int var = ((PMNode *)m_unk4)->m_unkC;
    if (var == 4) {
        var = 0;
    }
    if (m_unk9C < 8) {
        m_unk90[m_unk9C] = var;
        int old = m_unk9C;
        m_unk9C = old + 1;
        m_unk10[old] = sp50;
    } else {
        m_unk10[0] = m_unk10[1];
        m_unk90[0] = m_unk90[1];
        m_unk10[1] = m_unk10[2];
        m_unk90[1] = m_unk90[2];
        m_unk10[2] = m_unk10[3];
        m_unk90[2] = m_unk90[3];
        m_unk10[3] = m_unk10[4];
        m_unk90[3] = m_unk90[4];
        m_unk10[4] = m_unk10[5];
        m_unk90[4] = m_unk90[5];
        m_unk10[5] = m_unk10[6];
        m_unk90[5] = m_unk90[6];
        m_unk10[6] = m_unk10[7];
        m_unk90[6] = m_unk90[7];
        m_unk90[7] = var;
        m_unk10[7] = sp50;
    }
    return 1;
}

// FUNCTION: 0x1562B0 __ct__11GhostEffectFP9PMeshNode
extern "C" GhostEffect *__ct__11GhostEffectFP9PMeshNode(GhostEffect *volatile pThis, PMeshNode *arg0)
{
    *(void **)pThis = __vt__10EffectNode;
    pThis->m_unk4 = 0;
    *(unsigned char *)&pThis->m_unkC = 0;
    *(void **)pThis = __vt__11GhostEffect;
    pThis->m_unk4 = (int)arg0;
    pThis->m_unk98 = ((PMNode *)arg0)->GetFirstMesh();
    if (pThis->m_unk98 == 0) {
        CdsAssert("EffectAPI.cpp", 0x14D, "mpMesh");
    }
    pThis->m_unk9C = 0;
    pThis->m_unk9E = 0;
    pThis->m_unk9F = 0;
    pThis->m_unk90[0] = 0;
    pThis->m_unk90[1] = 0;
    pThis->m_unk90[2] = 0;
    pThis->m_unk90[3] = 0;
    pThis->m_unk90[4] = 0;
    pThis->m_unk90[5] = 0;
    pThis->m_unk90[6] = 0;
    pThis->m_unk90[7] = 0;
    return pThis;
}

// FUNCTION: 0x156390 CreateGhost__9EffectAPIFP9PMeshNode
GhostEffect *EffectAPI::CreateGhost(PMeshNode *arg0) {
    GhostEffect *pGhost = (GhostEffect *)__nw__FUi(0xA0);
    if (pGhost != 0) {
        pGhost = __ct__11GhostEffectFP9PMeshNode(pGhost, arg0);
    }
    if (pGhost != 0) {
        if (m_unk0 >= 0x80) {
            CdsAssert("EffectAPI.cpp", 0x142, "mEffectList.GetCount() < MAX_EFFECTS");
        }
        Add__6PArrayFPv(this, pGhost);
        int nId = m_unk10;
        m_unk10 = nId + 1;
        pGhost->m_unk8 = nId;
    }
    return pGhost;
}

// FUNCTION: 0x156440 SendDeleteEvent__10EffectNodeFi
void EffectNode::SendDeleteEvent(int arg0) {
    if (arg0 == 0) {
        return;
    }
    EffectTarget *pTarget = (EffectTarget *)((EntityManager *)(gEng + 0x137E0))->GetPtrToApparition(arg0);
    if (pTarget != 0) {
        pTarget->SendDeleteEvent(m_unk8);
    }
}

// FUNCTION: 0x001566B0 __ct__13OneshotEffectFUiUiP5PMat4P15EntityBaseClassfib
OneshotEffect::OneshotEffect(unsigned int arg0, unsigned int arg1, PMat4 *arg2, EntityBaseClass *arg3, float arg4, int arg5, bool arg6) {
    m_unkC = 0;
    m_unk1C = arg6;
    m_unk14 = arg3;
    m_unk18 = (arg3 != 0) ? arg3->m_unk4 : 0;
    m_unk10 = (int)arg2;
    m_unk4 = (int)mpResMgr__15EntityBaseClass->GetResource(arg0, 0);
    if (m_unk4 == 0) {
        CdsAssert("EffectAPI.cpp", 0xFC, "mpMeshNode");
    }
    PMNode *pAnim = mpResMgr__15EntityBaseClass->GetResource(arg1, 0);
    if (pAnim == 0) {
        CdsAssert("EffectAPI.cpp", 0xFE, "pAnim");
    }
    ((PMNode *)m_unk4)->Unk20(pAnim);
    ((PMNode *)m_unk4)->EnableAnim(true, true);
    if (arg4 != 0.5f) {
        ((PMNode *)m_unk4)->SetFrameRate(arg4, true);
    }
    ((PMNode *)m_unk4)->EnableOneRenderPassOnly(arg5);
    ((PMNode *)m_unk4)->Unk14();
}

// FUNCTION: 0x00156490 Update__13OneshotEffectFf
int OneshotEffect::Update(float arg0) {
    bool bVisible;
    if (m_unk4 != 0) {
        bVisible = true;
        if (m_unk18 != 0) {
            void *pApp = ((EntityManager *)(gEng + 0x137E0))->GetPtrToApparition(m_unk18);
            if (pApp != 0 && ((unsigned char *)pApp)[0x167] == 0) {
                bVisible = false;
            }
        }
        if (!bVisible ||(((EffectUpdateNode *)m_unk4)->Slot4(m_unk10, 8, 0, 0.0f, arg0) & 7) != 0) {
            if (m_unk1C != 0) {
                float *pSlot = (float *)(m_unk4 + 0x90);
                pSlot[1] = Round180(180.0f + *(float *)(gEng + 0x19784));
            }
            int test = mpFrustum__15EntityBaseClass->IntersectBox((float (*)[2][4])(*(char **)((char *)this + 4) + 0x110), (PMat4 *)(m_unk4 + 0x40));
            ((PMNode *)m_unk4)->SetAllFrustrumTest((eBoxIntersect)test);
            return 1;
        }
    }
    SendDeleteEvent(m_unk18);
    return 0;
}

// FUNCTION: 0x001565A0 CreateOneshot__9EffectAPIFUiUiP5PMat4P15EntityBaseClassfib
int EffectAPI::CreateOneshot(unsigned int arg0, unsigned int arg1, PMat4 *arg2, EntityBaseClass *arg3, float arg4, int arg5, bool arg6) {
    int nId = 0;
    OneshotEffect *pOneshot = (OneshotEffect *)__nw__FUi(0x20);
    if (pOneshot != 0) {
        pOneshot = __ct__13OneshotEffectFUiUiP5PMat4P15EntityBaseClassfib(pOneshot, arg0, arg1, arg2, arg3, arg4, arg5, arg6);
    }
    if (pOneshot != 0) {
        if (m_unk0 >= 0x80) {
            CdsAssert("EffectAPI.cpp", 0x10E, "mEffectList.GetCount() < MAX_EFFECTS");
        }
        Add__6PArrayFPv(this, pOneshot);
        nId = m_unk10;
        m_unk10 = nId + 1;
        pOneshot->m_unk8 = nId;
    }
    return nId;
}

// FUNCTION: 0x00156850 CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib
int EffectAPI::CreateOneshot(unsigned int arg0, unsigned int arg1, float (*arg2)[4], float (*arg3)[4], EntityBaseClass *arg4, float arg5, bool arg6, int arg7, bool arg8) {
    int nId = 0;
    OneshotEffect *pOneshot = (OneshotEffect *)__nw__FUi(0x20);
    if (pOneshot != 0) {
        pOneshot = __ct__13OneshotEffectFUiUiPA4_fPA4_fP15EntityBaseClassfbib(pOneshot, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
    }
    if (pOneshot != 0) {
        if (m_unk0 >= 0x80) {
            CdsAssert("EffectAPI.cpp", 0xEC, "mEffectList.GetCount() < MAX_EFFECTS");
        }
        Add__6PArrayFPv(this, pOneshot);
        nId = m_unk10;
        m_unk10 = nId + 1;
        pOneshot->m_unk8 = nId;
    }
    return nId;
}

// FUNCTION: 0x00156980 __ct__13OneshotEffectFUiUiPA4_fPA4_fP15EntityBaseClassfbib
OneshotEffect::OneshotEffect(unsigned int arg0, unsigned int arg1, float (*arg2)[4], float (*arg3)[4], EntityBaseClass *arg4, float arg5, bool arg6, int arg7, bool arg8) {
    m_unkC = arg6;
    m_unk1C = arg8;
    m_unk4 = (int)mpResMgr__15EntityBaseClass->GetResource(arg0, 0);
    if (m_unk4 == 0) {
        CdsAssert("EffectAPI.cpp", 0xC9, "mpMeshNode");
    }
    m_unk14 = arg4;
    if (arg4 == 0) {
        m_unk10 = 0;
        m_unk18 = 0;
        {
            char *node = (char *)m_unk4;
            *(u_long128 *)(node + 0x80) = *(u_long128 *)arg2;
            ((unsigned char *)node)[0x3E] |= 8;
        }
        if (arg3 != 0) {
            char *node = (char *)m_unk4;
            *(u_long128 *)(node + 0x90) = *(u_long128 *)arg3;
            ((unsigned char *)node)[0x3E] |= 8;
        }
    } else {
        m_unk18 = arg4->m_unk4;
        void *owner = arg4->m_unk3C;
        if (owner == 0) {
            CdsAssert("EffectAPI.cpp", 0xD6, "pNode");
        }
        m_unk10 = (int)((char *)owner + 0x40);
    }
    if (arg1 != 0) {
        PMNode *pAnim = mpResMgr__15EntityBaseClass->GetResource(arg1, 0);
        if (pAnim == 0) {
            CdsAssert("EffectAPI.cpp", 0xDB, "pAnim");
        }
        ((PMNode *)m_unk4)->Unk20(pAnim);
        ((PMNode *)m_unk4)->EnableAnim(true, true);
        if (arg5 != 0.5f) {
            ((PMNode *)m_unk4)->SetFrameRate(arg5, true);
        }
    }
    ((PMNode *)m_unk4)->EnableOneRenderPassOnly(arg7);
    ((PMNode *)m_unk4)->Unk14();
}

// DRAFT: 0x00156E00 Animate__9EffectAPIFf
// note: 28 words (was 34): pre-increment m_unk4 ternary, (&aDead[0])[nOff / 4] store, no nDead>0 guard on the second loop (original tests 0 < nDead in the for header). Remaining: the dead-entry store still folds sp+0x60 (original computes the array base then adds the offset) and the GetNext reload order. A goto-entered loop is wrong here: the original tests pNode at the loop top (beqz at 0x44).
void EffectAPI::Animate(float arg0) {
    EffectAnimNode *aDead[64];
    int nDead = 0;
    EffectAnimNode *pNode;
    m_unk4 = 0;
    if (m_unk0 != 0) {
        pNode = (EffectAnimNode *)m_ppEntries[0];
    } else {
        pNode = 0;
    }
    int nOff = 0;
    while (pNode != 0) {
        if (pNode->Slot1(arg0) == 0) {
            nDead++;
            (&aDead[0])[nOff / 4] = pNode;
            RemoveCurrent__6PArrayFv(this);
            nOff += 4;
        }
        pNode = (++m_unk4 < m_unk0) ? (EffectAnimNode *)m_ppEntries[m_unk4] : 0;
    }
    for (int i = 0; i < nDead; i++) {
        EffectAnimNode *pDead = aDead[i];
        if (pDead != 0) {
            pDead->Slot0(1);
        }
    }
}

// DRAFT: 0x156BB0 Update__10EffectNodeFf
// note: 2 words, a2/a1 addiu order (original computes a2 first). Tried: inline args, pMat local, PMNode struct fields, int base local, frustum local, inline wrapper with swapped params, declare-then-assign in both orders.
int EffectNode::Update(float arg0) {
    if (m_unk4 != 0) {
        if (((EffectDrawable *)m_unk4)->Slot4(0, 0, 0, 0.0f, arg0) & 7) {
            PMat4 *pMat = (PMat4 *)(m_unk4 + 0x40);
            int test = mpFrustum__15EntityBaseClass->IntersectBox((float (*)[2][4])(m_unk4 + 0x110), pMat);
            ((PMNode *)m_unk4)->SetAllFrustrumTest((eBoxIntersect)test);
            return 1;
        }
    }
    return 0;
}

// FUNCTION: 0x156C30 Render__10EffectNodeFP13PLightManager
int EffectNode::Render(PLightManager *arg0) {
    if (m_unk4 != 0) {
        *(unsigned char *)(gGfxEng + 0x158E22) = m_unkC;
        return ((EffectDrawable *)m_unk4)->Draw(m_unkC ? arg0 : 0, 0x80, 0);
    }
    return 0;
}

// FUNCTION: 0x156C90 __dt__10EffectNodeFv
extern "C" void *__dt__10EffectNodeFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__10EffectNode;
        EffectNode *pNode = (EffectNode *)pThis;
        EffectDrawable *pDrawable = (EffectDrawable *)pNode->m_unk4;
        if (pDrawable != 0) {
            if (pDrawable != 0) {
                pDrawable->Slot0(1);
            }
            pNode->m_unk4 = 0;
        }
        Remove__6PArrayFPv(&mEffectAPI__13EntityManager, pThis);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x156D20 EnableParticleFx__9EffectAPIFb
void EffectAPI::EnableParticleFx(bool arg0) {
    m_unk4 = 0;
    EffectNode *pNode = (m_unk0 != 0) ? m_ppEntries[0] : 0;
    while (pNode != 0) {
        switch (((EffectEntry *)pNode)->Slot3()) {
        case 1:
            PMNode *pMesh = (PMNode *)((EffectNode *)pNode)->m_unk4;
            if (pMesh != 0) {
                pMesh->EnableFx(arg0, 1);
            }
            break;
        }
        unsigned int nIndex = m_unk4 + 1;
        m_unk4 = nIndex;
        pNode = (nIndex < m_unk0) ? m_ppEntries[m_unk4] : 0;
    }
}

// FUNCTION: 0x156F30 EffectValid__9EffectAPIFUi
EffectNode *EffectAPI::EffectValid(unsigned int arg0) {
    if (arg0 == 0) {
        return 0;
    }
    m_unk4 = 0;
    EffectNode *pNode = (m_unk0 != 0) ? m_ppEntries[0] : 0;
    while (pNode != 0) {
        if (arg0 == pNode->m_unk8) {
            return pNode;
        }
        unsigned int nIndex = m_unk4 + 1;
        m_unk4 = nIndex;
        pNode = (nIndex < m_unk0) ? m_ppEntries[m_unk4] : 0;
    }
    return 0;
}

// FUNCTION: 0x156FD0 DeleteEffect__9EffectAPIFP10EffectNode
void EffectAPI::DeleteEffect(EffectNode *arg0) {
    int nIndex = Find__6PArrayFPv(this, arg0);
    if (nIndex >= 0) {
        RemoveAt__6PArrayFi(this, nIndex);
        if (arg0 != 0) {
            ((EffectDrawable *)arg0)->Slot0(1);
        }
    } else {
        printf("EffectNode not found\n");
    }
}

// FUNCTION: 0x157040 DeleteEffect__9EffectAPIFUi
void EffectAPI::DeleteEffect(unsigned int arg0) {
    m_unk4 = 0;
    EffectNode *pNode = (m_unk0 != 0) ? m_ppEntries[0] : 0;
    while (pNode != 0) {
        if (arg0 == pNode->m_unk8) {
            RemoveCurrent__6PArrayFv(this);
            if (pNode != 0) {
                ((EffectDrawable *)pNode)->Slot0(1);
            }
            return;
        }
        unsigned int nIndex = m_unk4 + 1;
        m_unk4 = nIndex;
        pNode = (nIndex < m_unk0) ? m_ppEntries[m_unk4] : 0;
    }
}

// FUNCTION: 0x157100 DeleteEffect__9EffectAPIFP15EntityBaseClass
void EffectAPI::DeleteEffect(EntityBaseClass *arg0) {
    m_unk4 = 0;
    EffectNode *pNode = (m_unk0 != 0) ? m_ppEntries[0] : 0;
    if (pNode != 0) {
        do {
            if (((EffectEntry *)pNode)->Slot4() == arg0) {
                RemoveCurrent__6PArrayFv(this);
                if (pNode != 0) {
                    ((EffectDrawable *)pNode)->Slot0(1);
                }
            }
            unsigned int nIndex = m_unk4 + 1;
            m_unk4 = nIndex;
            pNode = (nIndex < m_unk0) ? m_ppEntries[m_unk4] : 0;
        } while (pNode != 0);
    }
}

// FUNCTION: 0x1571E0 Render__9EffectAPIFP13PLightManager
int EffectAPI::Render(PLightManager *arg0) {
    m_unk4 = 0;
    int nSum = 0;
    EffectNode *pNode = (m_unk0 != 0) ? m_ppEntries[0] : 0;
    if (pNode != 0) {
        while (pNode != 0) {
            nSum += ((EffectDrawable *)pNode)->Slot2(arg0);
            unsigned int nIndex = m_unk4 + 1;
            m_unk4 = nIndex;
            pNode = (nIndex < m_unk0) ? m_ppEntries[m_unk4] : 0;
        }
    }
    return nSum;
}

// FUNCTION: 0x1572A0 Reset__9EffectAPIFv
void EffectAPI::Reset() {
    m_unk4 = 0;
    EffectNode *pNode = (m_unk0 != 0) ? m_ppEntries[0] : 0;
    if (pNode != 0) {
        do {
            if (pNode != 0) {
                ((EffectDrawable *)pNode)->Slot0(1);
            }
            m_unk4 = 0;
            pNode = (m_unk0 != 0) ? m_ppEntries[0] : 0;
        } while (pNode != 0);
    }
    (!m_unk0) ? (void)0 : CdsAssert("EffectAPI.cpp", 0x25, "!mEffectList.GetCount()");
    m_unk10 = 1;
}

// FUNCTION: 0x157360 __ct__9EffectAPIFv
extern "C" EffectAPI *__ct__9EffectAPIFv(EffectAPI *volatile pThis)
{
    __ct__6PArrayFv(pThis);
    Allocate__6PArrayFUi(pThis, 0x80);
    return pThis;
}

// FUNCTION: 0x157390 __dt__11PlingEffectFv
PlingEffect::~PlingEffect() {
}

// FUNCTION: 0x001573F0 GetType__11PlingEffectFv
int PlingEffect::GetType() {
    return 3;
}

// FUNCTION: 0x157400 __dt__11GhostEffectFv
extern "C" void *__dt__11GhostEffectFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__11GhostEffect;
        __dt__10EffectNodeFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x00157460 GetType__11GhostEffectFv
int GhostEffect::GetType() {
    return 2;
}

// FUNCTION: 0x157470 __dt__13OneshotEffectFv
extern "C" void *__dt__13OneshotEffectFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__13OneshotEffect;
        __dt__10EffectNodeFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001574D0 GetType__13OneshotEffectFv
int OneshotEffect::GetType() {
    return 1;
}

// FUNCTION: 0x001574E0 GetEntity__13OneshotEffectFv
EntityBaseClass *OneshotEffect::GetEntity() {
    return m_unk14;
}
