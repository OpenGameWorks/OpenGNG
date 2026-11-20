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

class PMNode {
public:
    void SetAllFrustrumTest(eBoxIntersect arg0);
    void *GetFirstMesh();
    void EnableFx(bool arg0, bool arg1);
};

extern PFrustrum *mpFrustum__15EntityBaseClass;

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
    unsigned char *pFlag = &m_unk90;
    if (m_unk9F != 0) {
        int off = 8 - m_unk9C;
        pVec = m_unk10 + off;
        pFlag = &m_unk90 + off;
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

// DRAFT: 0x1562B0 __ct__11GhostEffectFP9PMeshNode
// note: 50 words differ; post-assert reload of m_unk98 and "mpMesh" literal placement (gp-relative here, lui/addiu in original).
GhostEffect::GhostEffect(PMeshNode *arg0) {
    *(void **)this = __vt__10EffectNode;
    m_unk4 = 0;
    m_unkC = 0;
    *(void **)this = __vt__11GhostEffect;
    m_unk4 = (int)arg0;
    m_unk98 = ((PMNode *)m_unk4)->GetFirstMesh();
    if (m_unk98 == 0) {
        CdsAssert("EffectAPI.cpp", 0x14D, "mpMesh");
    }
    m_unk9C = 0;
    _pad09E[0] = 0;
    m_unk9F = 0;
    m_unk90 = 0;
    _pad091[0] = 0;
    _pad091[1] = 0;
    _pad091[2] = 0;
    _pad091[3] = 0;
    _pad091[4] = 0;
    _pad091[5] = 0;
    _pad091[6] = 0;
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

// DRAFT: 0x00156490 Update__13OneshotEffectFf
// note: 3 differing lines: visibility constant uses addiu (original daddiu) in the delay slot at 0x2C, and the box/matrix args are computed in the opposite order (original a2 first). Tried: pMat local, pBox and pMat locals, pSlot base for the float store.
int OneshotEffect::Update(float arg0) {
    int nVisible;
    if (m_unk4 != 0) {
        nVisible = 1;
        if (m_unk18 != 0) {
            void *pApp = ((EntityManager *)(gEng + 0x137E0))->GetPtrToApparition(m_unk18);
            if (pApp != 0 && ((unsigned char *)pApp)[0x167] == 0) {
                nVisible = 0;
            }
        }
        if (nVisible == 0 || (((EffectUpdateNode *)m_unk4)->Slot4(m_unk10, 8, 0, 0.0f, arg0) & 7) != 0) {
            if (m_unk1C != 0) {
                float *pSlot = (float *)(m_unk4 + 0x90);
                pSlot[1] = Round180(180.0f + *(float *)(gEng + 0x19784));
            }
            PMat4 *pMat = (PMat4 *)(m_unk4 + 0x40);
            float (*pBox)[2][4] = (float (*)[2][4])(m_unk4 + 0x110);
            int test = mpFrustum__15EntityBaseClass->IntersectBox(pBox, pMat);
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

// DRAFT: 0x00156E00 Animate__9EffectAPIFf
// note: frame and saves match; loop rotation differs (original enters with `b` to a bottom test at 0x44, ours tests at top), and the dead-entry store folds the sp+0x60 offset where the original computes sp+0x60 then adds s1. Tried: byte offset nOff, for-loop form, nDead++ before store (no change).
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
            *(EffectAnimNode **)((char *)aDead + nOff) = pNode;
            RemoveCurrent__6PArrayFv(this);
            nOff += 4;
        }
        m_unk4++;
        if (m_unk4 < m_unk0) {
            pNode = (EffectAnimNode *)m_ppEntries[m_unk4];
        } else {
            pNode = 0;
        }
    }
    if (nDead > 0) {
        int nOff2 = 0;
        for (int i = 0; i < nDead; i++) {
            EffectAnimNode *pDead = *(EffectAnimNode **)((char *)aDead + nOff2);
            if (pDead != 0) {
                pDead->Slot0(1);
            }
            nOff2 += 4;
        }
    }
}

// DRAFT: 0x156BB0 Update__10EffectNodeFf
// note: 2 differing lines, a2/a1 addiu order (original computes a2 first). Tried: inline args, pMat local, PMNode struct fields, int base local (4 lines each for the last two).
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

// DRAFT: 0x156D20 EnableParticleFx__9EffectAPIFb
// note: 33 words differ; original guard branch targets a nop before the epilogue, and Slot3 test is beq+b, not bne (tried &&-merged and empty-then forms, same count).
void EffectAPI::EnableParticleFx(bool arg0) {
    m_unk4 = 0;
    EffectNode *pNode = (m_unk0 != 0) ? m_ppEntries[0] : 0;
    if (pNode != 0) {
        do {
            if (((EffectEntry *)pNode)->Slot3() == 1) {
                PMNode *pMesh = (PMNode *)((EffectNode *)pNode)->m_unk4;
                if (pMesh != 0) {
                    pMesh->EnableFx(arg0, 1);
                }
            }
            pNode = 0;
            unsigned int nIndex = m_unk4 + 1;
            m_unk4 = nIndex;
            if (nIndex < m_unk0) {
                pNode = m_ppEntries[m_unk4];
            }
        } while (pNode != 0);
    }
}

// DRAFT: 0x156F30 EffectValid__9EffectAPIFUi
// note: 13 differing words (size 0x90 vs 0x94): loop-top branch form, index update in v0/v1 vs a2, extra nop before the return block. Tried: ternary first fetch (16), local nIndex (13), m_unk4++ (28), ternary index update (17), for-loop form (13), pNode clear before update (13).
EffectNode *EffectAPI::EffectValid(unsigned int arg0) {
    if (arg0 == 0) {
        return 0;
    }
    m_unk4 = 0;
    EffectNode *pNode = (m_unk0 != 0) ? m_ppEntries[0] : 0;
    while (pNode != 0) {
        if (pNode->m_unk8 == arg0) {
            return pNode;
        }
        pNode = 0;
        unsigned int nIndex = m_unk4 + 1;
        m_unk4 = nIndex;
        if (nIndex < m_unk0) {
            pNode = m_ppEntries[m_unk4];
        }
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

// DRAFT: 0x157040 DeleteEffect__9EffectAPIFUi
// note: 15 differing words: loop-top branch form (original beqz at top, ours b to bottom test), pNode=0 store order, bottom bnez. Tried: Slot2 (16, wrong vtable offset 0x10; Slot0 gives 0x8 as original), indexed for-loop (44), dropped inner null check (32).
void EffectAPI::DeleteEffect(unsigned int arg0) {
    m_unk4 = 0;
    EffectNode *pNode = (m_unk0 != 0) ? m_ppEntries[0] : 0;
    while (pNode != 0) {
        if (pNode->m_unk8 == arg0) {
            RemoveCurrent__6PArrayFv(this);
            if (pNode != 0) {
                ((EffectDrawable *)pNode)->Slot0(1);
            }
            return;
        }
        pNode = 0;
        unsigned int nIndex = m_unk4 + 1;
        m_unk4 = nIndex;
        if (nIndex < m_unk0) {
            pNode = m_ppEntries[m_unk4];
        }
    }
}

// DRAFT: 0x157100 DeleteEffect__9EffectAPIFP15EntityBaseClass
// note: 24 differing lines: loop top and bottom match, but the Slot0 guard skips to an extra nop before the join (original 0x7C), and the do-while join lacks the nop before the epilogue. Tried: guarded do-while (24), plain while (24, top becomes b).
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
            pNode = 0;
            unsigned int nIndex = m_unk4 + 1;
            m_unk4 = nIndex;
            if (nIndex < m_unk0) {
                pNode = m_ppEntries[m_unk4];
            }
        } while (pNode != 0);
    }
}

// DRAFT: 0x1571E0 Render__9EffectAPIFP13PLightManager
// note: 11 differing words: loop-top beqz vs our b to bottom test, shared nop before the return block. Tried: guarded while (11), plain while (12), do-while (31).
int EffectAPI::Render(PLightManager *arg0) {
    m_unk4 = 0;
    int nSum = 0;
    EffectNode *pNode = (m_unk0 != 0) ? m_ppEntries[0] : 0;
    if (pNode != 0) {
        while (pNode != 0) {
            nSum += ((EffectDrawable *)pNode)->Slot2(arg0);
            pNode = 0;
            unsigned int nIndex = m_unk4 + 1;
            m_unk4 = nIndex;
            if (nIndex < m_unk0) {
                pNode = m_ppEntries[m_unk4];
            }
        }
    }
    return nSum;
}

// DRAFT: 0x1572A0 Reset__9EffectAPIFv
// note: 29 differing words, size 0xAC vs 0xBC: loop-exit target lands one word early, call-block delay slot is a nop in the original, the assert guard is sltu/xori in the original. Tried: double-negation guard (29, folded by the compiler).
void EffectAPI::Reset() {
    m_unk4 = 0;
    EffectNode *pNode = (m_unk0 != 0) ? m_ppEntries[0] : 0;
    if (pNode != 0) {
        do {
            if (pNode != 0) {
                ((EffectDrawable *)pNode)->Slot0(1);
            }
            m_unk4 = 0;
            pNode = 0;
            if (m_unk0 != 0) {
                pNode = m_ppEntries[0];
            }
        } while (pNode != 0);
    }
    if (m_unk0 != 0) {
        CdsAssert("EffectAPI.cpp", 0x25, "!mEffectList.GetCount()");
    }
    m_unk10 = 1;
}

// DRAFT: 0x157360 __ct__9EffectAPIFv
// note: original keeps this in stack home 0x1C(sp) and never uses s0; compile saves s0 and uses it (9 differing lines). Tried (void*) casts (9 lines) and volatile local (15 lines).
EffectAPI::EffectAPI() {
    __ct__6PArrayFv(this);
    Allocate__6PArrayFUi(this, 0x80);
}

// FUNCTION: 0x157390 __dt__11PlingEffectFv
PlingEffect::~PlingEffect() {
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
