#include "types.h"
#include "PMNode.h"

// TODO(header): foreign declarations
extern "C" void sceVu0ApplyMatrix(float *, float (*)[4], float *);
extern "C" void __dt__5PMeshFv(void *, short);
extern "C" void *__nw__FUi(unsigned int);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" PObjectDisplayList *__ct__18PObjectDisplayListFv(PObjectDisplayList *);
extern "C" void __dt__18PObjectDisplayListFv(PObjectDisplayList *, short);
extern "C" int Create__18PObjectDisplayListFP6PMNodePb(PObjectDisplayList *, PMNode *, bool *);
class PMat4;
class PDisplayList {
public:
    void AddMatrix(PMat4 *pMat, unsigned int uIdx);
};
// TODO(header): gGfxEng is a PDisplayList pointer. The original reaches it with lui/lw, which needs a placeholder larger than 8 bytes.
struct PGfxEngineRef {
    PDisplayList *pDisplayList;
    char _pad04[0x10];
};
extern PGfxEngineRef gGfxEng;
// TODO(header): mst_NextPMNodeRef__6PMNode is a static PMNode counter; a 4-byte int keeps it gp-relative as the original does.
extern "C" int mst_NextPMNodeRef__6PMNode;

class PArray {
public:
    void Add(void *pItem);
};

// Object held at PMNode+0x24. Slot 18 (0x48) is the frame-rate query; slots 0..17 are unknown.
class PFrameSource {
public:
    virtual ~PFrameSource();   // two slots in CodeWarrior (complete and deleting)
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual float GetFrameRate();
};

// FUNCTION: 0x001919E0 CreateObjectDisplayList__6PMNodeFv
int PMNode::CreateObjectDisplayList() {
    PObjectDisplayList *p = m_pObjDisplayList;
    if (p != 0) {
        __dt__18PObjectDisplayListFv(p, 1);
        m_pObjDisplayList = 0;
    }
    p = (PObjectDisplayList *)__nw__FUi(0x1F0);
    if (p != 0) {
        p = __ct__18PObjectDisplayListFv(p);
    }
    m_pObjDisplayList = p;
    if (m_pObjDisplayList == 0) {
        CdsAssert__FPciPc("PMNode.cpp", 0x99E, "mpObjDisplayList");
    }
    if (Create__18PObjectDisplayListFP6PMNodePb(m_pObjDisplayList, this, &m_unkD4) == 0) {
        __dt__18PObjectDisplayListFv(m_pObjDisplayList, 1);
        m_pObjDisplayList = 0;
        return 0;
    }
    return 1;
}

// DRAFT: 0x00192CC0 CopyFxTriggers__6PMNodeFR6PMNode
// note: 32 lines differ in the current form (count>0 guard, do-while). Earlier 26 for for/while/do-while variants not reproduced; count!=0 guard also 32.
void PMNode::CopyFxTriggers(PMNode &src) {
    unsigned int count = src.m_unkD8;
    unsigned int idx = 0;
    if (count > 0) {
        do {
            tagParticleFxTrigger *pTrig = 0;
            if (idx < src.m_unkD8) {
                pTrig = src.m_unkE0[idx];
            }
            if (pTrig != 0 && !(*(int *)((char *)pTrig + 0x24) & 4)) {
                AddFxTrigger(pTrig, false);
            }
            idx++;
        } while (idx < count);
    }
}

// DRAFT: 0x00192D70 AddFxTriggers__6PMNodeFP6PArrayb
// note: 9 lines differ; original has one extra nop before the epilogue. Tried if(count!=0), if(count>0), if(0<count), for loop, bool guard temp, idx-zero guard with ++idx test.
void PMNode::AddFxTriggers(PArray *pArr, bool bFlag) {
    tagParticleFxTrigger *pTrig;
    unsigned int count;
    unsigned int idx;
    if (pArr == 0) {
        CdsAssert__FPciPc("PMNode.cpp", 0x753, "poTriggers");
    }
    count = *(unsigned int *)pArr;
    idx = 0;
    if (idx < count) {
        do {
            pTrig = 0;
            if (idx < *(unsigned int *)pArr) {
                pTrig = (*(tagParticleFxTrigger ***)((char *)pArr + 8))[idx];
            }
            AddFxTrigger(pTrig, bFlag);
        } while (++idx < count);
    }
}

// FUNCTION: 0x00192E30 AddFxTrigger__6PMNodeFP20tagParticleFxTriggerb
int PMNode::AddFxTrigger(tagParticleFxTrigger *pTrigger, bool bFlag) {
    char *pBlk = (char *)__nw__FUi(0x28);
    if (pBlk == 0) {
        CdsAssert__FPciPc("PMNode.cpp", 0x746, "apTrigger");
    }
    memcpy(pBlk, pTrigger, 0x28);
    *(int *)(pBlk + 0x20) = 0;
    *(int *)(pBlk + 0x24) = bFlag ? 4 : 0;
    ((PArray *)((char *)this + 0xD8))->Add(pBlk);
    return 1;
}

// DRAFT: 0x00192FD0 SetAllFade__6PMNodeFf
// note: 5 words differ, the join nop at 0x84 before the epilogue and the f20 copy of fFade in the first beqz delay slot. Tried: local float copy (5), do-while on child count (30).
void PMNode::SetAllFade(float fFade) {
    PMNode *pChild;
    unsigned int idx;
    m_unk2C = fFade;
    m_unk18 = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    } else {
        pChild = 0;
    }
    if (pChild != 0) {
        do {
            pChild->SetAllFade(fFade);
            idx = m_unk18 + 1;
            m_unk18 = idx;
            if (idx < m_unk14) {
                pChild = m_unk1C[m_unk18];
            } else {
                pChild = 0;
            }
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00193070 GetFrameRate__6PMNodeFv
float PMNode::GetFrameRate() {
    void *pObj = m_unk24;
    if (pObj != 0) {
        return ((PFrameSource *)pObj)->GetFrameRate();
    }
    return 0.0f;
}

// FUNCTION: 0x00193540 BuildDispList__6PMNodeFP6PArray
void PMNode::BuildDispList(PArray *pArr) {
    PMNode *pChild;
    unsigned int idx;
    if (m_unk10 != 0 || m_unkD0 >= 0) {
        pArr->Add(this);
    }
    m_unk18 = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    } else {
        pChild = 0;
    }
    if (pChild != 0) {
        do {
            pChild->BuildDispList(pArr);
            idx = m_unk18 + 1;
            m_unk18 = idx;
            if (idx < m_unk14) {
                pChild = m_unk1C[m_unk18];
            } else {
                pChild = 0;
            }
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00193600 AddBoneMatrixToDisplayList__6PMNodeFb
void PMNode::AddBoneMatrixToDisplayList(bool bRecurse) {
    PMNode *pChild;
    if (m_unkD0 >= 0) {
        gGfxEng.pDisplayList->AddMatrix((PMat4 *)m_unk40, m_unkD0 * 4 + 0x296);
    }
    if (bRecurse) {
        m_unk18 = 0;
        if (m_unk14 != 0) {
            pChild = *m_unk1C;
        } else {
            pChild = 0;
        }
        if (pChild != 0) {
            do {
                pChild->AddBoneMatrixToDisplayList(bRecurse);
                unsigned int idx = m_unk18 + 1;
                m_unk18 = idx;
                if (idx < m_unk14) {
                    pChild = m_unk1C[m_unk18];
                } else {
                    pChild = 0;
                }
            } while (pChild != 0);
        }
    }
}

// FUNCTION: 0x00193B10 GetWorldMeshCenter__6PMNodeFPf
int PMNode::GetWorldMeshCenter(float *pOut) {
    u_long128 tmp;
    char *pMesh = (char *)GetFirstMesh();
    if (pMesh != 0) {
        sceVu0ApplyMatrix((float *)&tmp, m_unk40, (float *)(pMesh + 0x10));
        *(u_long128 *)pOut = tmp;
        return 0;
    }
    *(u_long128 *)pOut = *(u_long128 *)m_unk40[3];
    return 0;
}

// DRAFT: 0x00194340 DisableAllHitBox__6PMNodeFv
// note: 5 words differ, all the join nop at 0x84 before the epilogue; original has it, this does not. Tried: else-arm reorder (30), pChild=0 after m_unk18 (5, kept), trailing return (5), while form (25), nested if (27), ternary tail (12).
void PMNode::DisableAllHitBox() {
    PMNode *pChild;
    unsigned int idx;
    if (m_unk10 != 0) {
        ((unsigned char *)m_unk10)[0xD] = 0;
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    }
    if (pChild != 0) {
        do {
            pChild->DisableAllHitBox();
            idx = m_unk18 + 1;
            m_unk18 = idx;
            if (idx < m_unk14) {
                pChild = m_unk1C[m_unk18];
            } else {
                pChild = 0;
            }
        } while (pChild != 0);
    }
}

// DRAFT: 0x00194920 Find__6PMNodeFP6PMNode
// note: 2 words differ at the loop-exit beqz delay slot (original nop, ours daddu $v0,$zero,$zero); tried while, result var with break, idx indexing, early return guard.
int PMNode::Find(PMNode *pNode) {
    PMNode *pChild;
    if (this == pNode) {
        return 1;
    }
    m_unk18 = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    } else {
        pChild = 0;
    }
    if (pChild != 0) {
        do {
            if (pChild->Find(pNode) != 0) {
                return 1;
            }
            unsigned int idx = m_unk18 + 1;
            m_unk18 = idx;
            if (idx < m_unk14) {
                pChild = m_unk1C[m_unk18];
            } else {
                pChild = 0;
            }
        } while (pChild != 0);
    }
    return 0;
}

// DRAFT: 0x00194AD0 GetFirstMesh__6PMNodeFv
// note: 2 lines differ; zero-v0 move sits in the delay slot of the pChild guard beqz, original branches to a separate zero move with nop delay. Tried: pResult+break (larger), early return 0 with duplicated tail (26).
void *PMNode::GetFirstMesh() {
    PMNode *pChild;
    unsigned int idx;
    void *pMesh = m_unk10;
    if (pMesh != 0) {
        return pMesh;
    }
    m_unk18 = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    } else {
        pChild = 0;
    }
    if (pChild != 0) {
        do {
            void *pFound = pChild->GetFirstMesh();
            if (pFound != 0) {
                return pFound;
            }
            idx = m_unk18 + 1;
            m_unk18 = idx;
            if (idx < m_unk14) {
                pChild = m_unk1C[m_unk18];
            } else {
                pChild = 0;
            }
        } while (pChild != 0);
    }
    return 0;
}

// DRAFT: 0x00194B80 SetAllFrustrumTest__6PMNodeF13eBoxIntersect
// note: 7 lines differ; beq offset 0x1C vs 0x1B at 0x24 and missing join nop at 0x94 before epilogue (rest is shift). Tried: early return on m_unk04==2 (also 7, reverted).
void PMNode::SetAllFrustrumTest(eBoxIntersect eMode) {
    PMNode *pChild;
    unsigned int idx;
    m_unk0C = (int)eMode;
    if (m_unk04 != 2) {
        m_unk18 = 0;
        if (m_unk14 != 0) {
            pChild = *m_unk1C;
        } else {
            pChild = 0;
        }
        if (pChild != 0) {
            do {
                pChild->SetAllFrustrumTest(eMode);
                idx = m_unk18 + 1;
                m_unk18 = idx;
                if (idx < m_unk14) {
                    pChild = m_unk1C[m_unk18];
                } else {
                    pChild = 0;
                }
            } while (pChild != 0);
        }
    }
}

// FUNCTION: 0x00194C30 ScaleSet__6PMNodeFffff
void PMNode::ScaleSet(float a, float b, float c, float d) {
    m_unkA0[0] = a;
    m_unkA0[1] = b;
    m_unkA0[2] = c;
    m_unkA0[3] = d;
    m_unk3E |= 8;
}

// DRAFT: 0x00195180 DestroyChildren__6PMNodeFv
// note: original keeps an inner pChild != 0 guard before the slot-8 call (CW drops it here) and calls through t9 with a nop after jalr; tried cast, local fn pointer, for-break loop; all leave the same diff.
void PMNode::DestroyChildren() {
    PMNode *pChild;
    m_unk18 = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    } else {
        pChild = 0;
    }
    if (pChild != 0) {
        do {
            if (pChild != 0) {
                void (*pfn)(PMNode *, int) = *(void (**)(PMNode *, int))(*(int *)pChild + 8);
                pfn(pChild, 1);
            }
            unsigned int idx = m_unk18 + 1;
            m_unk18 = idx;
            if (idx < m_unk14) {
                pChild = m_unk1C[m_unk18];
            } else {
                pChild = 0;
            }
        } while (pChild != 0);
    }
    if (m_unk1C != 0) {
        m_unk14 = 0;
        m_unk18 = 0;
    }
}

// FUNCTION: 0x00195240 DestroyMesh__6PMNodeFv
void PMNode::DestroyMesh() {
    void *pMesh = m_unk10;
    if (pMesh != 0 && (m_unk3E & 1)) {
        __dt__5PMeshFv(pMesh, 1);
        StopAmbientSoundsByObject();
    }
    m_unk10 = 0;
    m_unk3E &= 0xEE;
    m_unk28 = 0;
    m_unk3C = 0;
}

// DRAFT: 0x001952B0 RecurseSetFade__6PMNodeFf
// note: 5 words differ, the join nop at 0x84 before the epilogue, same shape as SetAllFade. Tried: same structure as SetAllFade (not separately varied).
void PMNode::RecurseSetFade(float fFade) {
    PMNode *pChild;
    unsigned int idx;
    m_unk2C = fFade;
    m_unk18 = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    } else {
        pChild = 0;
    }
    if (pChild != 0) {
        do {
            pChild->RecurseSetFade(fFade);
            idx = m_unk18 + 1;
            m_unk18 = idx;
            if (idx < m_unk14) {
                pChild = m_unk1C[m_unk18];
            } else {
                pChild = 0;
            }
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00195D30 DestroyAnim__6PMNodeFv
void PMNode::DestroyAnim() {
    unsigned char flags = m_unk3E;
    if (flags & 2) {
        m_unk3E = flags & 0xFD;
        if (m_unk24 != 0) {
            delete (PFrameSource *)m_unk24;
        }
    }
    m_unk3E |= 8;
    m_unk24 = 0;
    m_unk28 = 0;
    m_unk3C = 0;
    StopAmbientSoundsByObject();
    m_unk3F = 0;
    *(unsigned int *)&m_unk2C = 0x3F800000;
    m_unk30 = 0;
    m_unk34 = 0;
    *(unsigned int *)&m_unk38 = 0xC61C4000;
}

// FUNCTION: 0x00195DD0 RecurseDetachAnim__6PMNodeFv
void PMNode::RecurseDetachAnim() {
    PMNode *pChild;
    unsigned int idx;
    DestroyAnim();
    DestroyFxTriggers(true, false, false);
    m_unk18 = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    } else {
        pChild = 0;
    }
    if (pChild != 0) {
        do {
            pChild->RecurseDetachAnim();
            idx = m_unk18 + 1;
            m_unk18 = idx;
            if (idx < m_unk14) {
                pChild = m_unk1C[m_unk18];
            } else {
                pChild = 0;
            }
        } while (pChild != 0);
    }
}

// DRAFT: 0x00196220 InitMembers__6PMNodeFv
// note: sqc2 $vf0 zeroing stores are raw .word; base a1 is scheduled late, small constants take other registers, float constants use mtc1/cvt (25 words differ).
void PMNode::InitMembers() {
    m_unk08 = 0;
    m_unk10 = 0;
    m_unk24 = 0;
    m_unk28 = 0;
    m_unk3C = 0;
    m_unk3E = 8;
    m_unk3D = 3;
    m_unk3F = 0;
    asm {
        .word 0xF8A00000
        .word 0xF8A00010
        .word 0xF8A00030
        .word 0xF8A00040
    }
    m_unkA0[3] = 1.0f;
    m_unkA0[2] = 1.0f;
    m_unkA0[1] = 1.0f;
    m_unkA0[0] = 1.0f;
    m_unk2C = 1.0f;
    m_unk30 = 0;
    m_unk34 = 0;
    m_unk38 = -10000.0f;
    m_unk04 = 3;
    m_unk0C = 4;
    m_unkD4 = true;
    m_unkD5 = 1;
    m_unkD6 = 1;
    m_unkD7 = 1;
    m_unkD0 = -1;
    m_pObjDisplayList = 0;
    m_unkE8 = mst_NextPMNodeRef__6PMNode;
    mst_NextPMNodeRef__6PMNode = mst_NextPMNodeRef__6PMNode + 1;
    m_unkEC = 0;
    m_unkF0 = 0;
    m_unkF4 = 0;
}
