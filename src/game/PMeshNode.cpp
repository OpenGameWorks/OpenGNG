// FLAGS: -str readonly
#include "types.h"
#include "PMeshNode.h"

// TODO(header): foreign declarations
class PArray {
public:
    unsigned int count;
    int index;
    void *table;
    unsigned int size;          // 0x0C GetSize()
    int Find(void *pItem);
    void RemoveAt(int idx);
    void Remove(void *pItem);
    void Add(void *pItem);
};

class PLight {
public:
    char _pad00[0x4C];
    int m_unk4C;
};

class PAnim {
public:
    char _pad00[8];
    short m_unk8;
};

enum eBoxIntersect { eBoxIntersect_Placeholder = 0 };

class PMat4;

// PFrustrum.h does not declare IntersectBox or the member at 0xE0; only those are named here.
class PFrustrum {
public:
    int IntersectBox(float (*pArr)[2][4], PMat4 *pMat);
    char _pad000[0xE0];
    float m_unkE0;
};

class PMNode {
public:
    void InitMembers();
    PMNode *Find(unsigned int uID);
    void RecurseDetachAnim();
    void AttachAnim(PAnim *pAnim, bool bFlag);
    void AddFxTriggers(PArray *pArr, bool bFlag);
    void CopyMNode(PMNode &src, bool bFlag);
    void SetAllFrustrumTest(eBoxIntersect eType);
    int LoadFxTriggers(PPakFile *pFile);
    int LoadMesh(PPakFile *pFile, PArray *pArr, ePsx2FileVersion eVersion);
    int LoadAnim(PPakFile *pFile);
};

extern "C" void *__ct__6PArrayFv(void *pThis);
extern "C" void __dt__6PArrayFv(void *pThis, short flags);
extern "C" void __dt__6PMNodeFv(void *pThis, short flags);
extern "C" void __dla__FPv(void *pMem);
extern "C" void __dl__FPv(void *pMem);
extern "C" void sceVu0UnitMatrix(float *pMatrix);
extern "C" void CdsAssert__FPciPc(const char *pFile, int line, const char *pExpr);
extern "C" void *__nwa__FUi(unsigned int size);
extern "C" void FlushCache(int mode, unsigned int addr, void *pTable, int count);
extern "C" void sceVu0AddVector(float *pDst, float *pA, float *pB);
extern "C" void PBoundBoxToBoundBox__FPA2_A4_fPA2_A4_f(float (*pSrc)[2][4], float (*pDst)[2][4]);
extern "C" void MakePBoundBox__FPfPfPA2_A4_f(float *pMin, float *pMax, float (*pBox)[2][4]);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void memcpy(void *pDst, const void *pSrc, unsigned int size);

class PCDFile {
public:
    int Read(void *pBuf, unsigned int size);
};

extern unsigned char __vt__9PMeshNode[];
extern unsigned char __vt__6PMNode[];
extern unsigned char __vt__9PResource[];
extern float gUnitMatrix[16];
extern float FADE_DISTANCE;
extern float TRANS_DISTANCE;

// FUNCTION: 0x001901C0 TestMeshNodeInFrustum__9PMeshNodeFP9PFrustrum
void PMeshNode::TestMeshNodeInFrustum(PFrustrum *pFrustrum) {
    float (*pMat)[2][4] = (float (*)[2][4])m_unk110;
    if (m_unk3E & 4) {
        float scale = 1.0f;
        if (m_unkA0 > scale) {
            scale = m_unkA0;
        }
        if (m_unkA4 > scale) {
            scale = m_unkA4;
        }
        if (m_unkA8 > scale) {
            scale = m_unkA8;
        }
        if (scale != 1.0f) {
            float clip[2][4];
            *(u_long128 *)&clip[0][0] = *(u_long128 *)pMat;
            *(u_long128 *)&clip[1][0] = *(u_long128 *)((char *)pMat + 0x10);
            clip[1][3] *= scale;
            pMat = &clip;
        }
    }
    int result = pFrustrum->IntersectBox(pMat, (PMat4 *)m_unk40);
    m_unkC = result;
    if (result == 0) {
        ((PMNode *)this)->SetAllFrustrumTest(eBoxIntersect_Placeholder);
        return;
    }
    if (m_unk3E & 0x20) {
        if (result == 4 && pFrustrum->m_unkE0 > FADE_DISTANCE) {
            float d = TRANS_DISTANCE - pFrustrum->m_unkE0;
            m_unk2C = (d > 0.0f) ? d / (TRANS_DISTANCE - FADE_DISTANCE) : 0.0f;
        } else {
            m_unk2C = 1.0f;
        }
    }
    m_unk18 = 0;
    PMeshNode *var = (m_unk14 != 0) ? m_unk1C[0] : 0;
    if (var != 0) {
        do {
            var->TestMeshNodeInFrustum(pFrustrum);
            unsigned int next = m_unk18 + 1;
            m_unk18 = next;
            var = (next < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (var != 0);
    }
}

// DRAFT: 0x00190390 AdjustPickup__9PMeshNodeFv
// note: 11 words differ; original addresses the first clamp through m_unk10+0x10 (one base reg) and reloads m_unk10 for the second clamp. Tried a cached local pointer (15 words, worse).
void PMeshNode::AdjustPickup() {
    if (m_unk10 != 0) {
        if (m_unk10->m_unk20 < 1.0f) {
            m_unk10->m_unk20 = 1.0f;
        }
        if (m_unk10->m_unk28 < 1.0f) {
            m_unk10->m_unk28 = 1.0f;
        }
    }
    m_unk18 = 0;
    PMeshNode *var = (m_unk14 != 0) ? m_unk1C[0] : 0;
    if (var != 0) {
        do {
            var->AdjustPickup();
            unsigned int next = m_unk18 + 1;
            m_unk18 = next;
            var = (next < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (var != 0);
    }
}

// FUNCTION: 0x00190470 DetachAllLights__9PMeshNodeFv
void PMeshNode::DetachAllLights() {
    if (m_unk138 != 0) {
        m_unk130 = 0;
        m_unk134 = 0;
    }
    m_unk102 = 1;
}

// FUNCTION: 0x00190490 DetachLight__9PMeshNodeFP6PLight
void PMeshNode::DetachLight(PLight *pLight) {
    if (pLight == 0) {
        CdsAssert__FPciPc("PMeshNode.cpp", 0x256, "pLight");
    }
    int idx = ((PArray *)&m_unk130)->Find(pLight);
    if (idx >= 0) {
        ((PArray *)&m_unk130)->RemoveAt(idx);
        pLight->m_unk4C = 0;
    }
    if (((PArray *)&m_unk130)->count == 0) {
        m_unk102 = 0;
    }
}

// FUNCTION: 0x00190510 RemoveFromCollisionArray__9PMeshNodeFP6PArray
void PMeshNode::RemoveFromCollisionArray(PArray *pArr) {
    if (m_unk104 != 0) {
        pArr->Remove(this);
    }
    m_unk18 = 0;
    PMeshNode *var = (m_unk14 != 0) ? m_unk1C[0] : 0;
    if (var != 0) {
        do {
            if (var->m_unk04 == 3) {
                return;
            }
            var->RemoveFromCollisionArray(pArr);
            unsigned int next = m_unk18 + 1;
            m_unk18 = next;
            var = (next < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (var != 0);
    }
}

// FUNCTION: 0x001905D0 BuildCollisionArray__9PMeshNodeFP6PArrayUi
bool PMeshNode::BuildCollisionArray(PArray *pArr, unsigned int flag) {
    bool result = false;
    if (m_unk104 != 0) {
        if (pArr->size <= pArr->count) {
            CdsAssert__FPciPc("PMeshNode.cpp", 0x202, "pArray->GetSize() > pArray->GetCount()");
        }
        pArr->Add(this);
        m_unk100 = (short)flag;
        result = true;
    }
    m_unk18 = 0;
    PMeshNode *var = (m_unk14 != 0) ? m_unk1C[0] : 0;
    if (var != 0) {
        do {
            if (var->m_unk04 == 3) {
                return result;
            }
            if (var->BuildCollisionArray(pArr, flag)) {
                result = true;
            }
            unsigned int next = m_unk18 + 1;
            m_unk18 = next;
            var = (next < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (var != 0);
    }
    return result;
}

// DRAFT: 0x001906F0 LoadCollision__9PMeshNodeFP8PPakFile
// note: 30 words differ (rechecked after job PMeshNode-73530); mask/tag constant in a0/v1 not v3/a1, tbase in a1 not t0, `or` store value duplicated into the bnez delay slot (orig computes it after sync+nop), count-- hoisted above sw. Tried a local tag constant, table store order, and hoisting the store (all 33).
void PMeshNode::LoadCollision(PPakFile *pPak) {
    unsigned int size;
    if (((PCDFile *)pPak)->Read(&size, 4) == 4) {
        int *block = (int *)__nwa__FUi(size);
        if (block == 0) {
            CdsAssert__FPciPc("PMeshNode.cpp", 0x1E0, "p");
        }
        if (size != (unsigned int)((PCDFile *)pPak)->Read(block, size)) {
            __dla__FPv(block);
            return;
        }
        m_unk104 = (void *)((unsigned int)block | 0x30000000);
        m_unk103 = 1;
        int *table = (int *)((char *)block + 0xC);
        int count = block[2];
        int *entry = (int *)((char *)block + (((count + 6) & ~3) * 4));
        unsigned int tbase = ((unsigned int)entry + (count << 5)) | 0x20000000;
        while (count != 0) {
            int v = entry[0];
            if (!(v & 0x20000000)) {
                entry[0] = tbase + v * 16;
                entry[1] = tbase + entry[1] * 16;
                entry[2] = tbase + entry[2] * 16;
                asm { sync }
            }
            *table++ = (int)entry | 0x20000000;
            count--;
            entry += 8;
        }
        FlushCache(0, 0x20000000, table, count);
    }
}

// FUNCTION: 0x00190840 Load__9PMeshNodeFP8PPakFileP6PArray16ePsx2FileVersion
int PMeshNode::Load(PPakFile *pPak, PArray *pArr, ePsx2FileVersion ver) {
    ((pPak) ? (void)0 : CdsAssert__FPciPc("PMeshNode.cpp", 0x148, "poFile"));
    unsigned char rec0[0xD0];
    unsigned char rec1[0xB4];
    int tag;
    if (ver >= 0x20000) {
        if (((PCDFile *)pPak)->Read(rec1, 0xB4) != 0xB4) {
            return 0;
        }
        m_unk8 = *(int *)rec1;
        memcpy(m_unk80, rec1 + 0x4, 16);
        memcpy(m_unk90, rec1 + 0x14, 16);
        memcpy(&m_unkA0, rec1 + 0x24, 16);
        memcpy(m_unkB0, rec1 + 0x34, 16);
        memcpy(m_unkC0, rec1 + 0x44, 16);
        memcpy(m_unk110, rec1 + 0x94, 16);
        memcpy(m_unk120, rec1 + 0xA4, 16);
    } else {
        if (((PCDFile *)pPak)->Read(rec0, 0xD0) != 0xD0) {
            return 0;
        }
        m_unk8 = *(int *)rec0;
        memcpy(m_unk80, rec0 + 0x20, 16);
        memcpy(m_unk90, rec0 + 0x30, 16);
        memcpy(&m_unkA0, rec0 + 0x40, 16);
        memcpy(m_unkB0, rec0 + 0x50, 16);
        memcpy(m_unkC0, rec0 + 0x60, 16);
        memcpy(m_unk110, rec0 + 0xB0, 16);
        memcpy(m_unk120, rec0 + 0xC0, 16);
    }
    if (ver >= 0x10001) {
        if (!((PMNode *)this)->LoadFxTriggers(pPak)) {
            return 0;
        }
    }
    ((PMNode *)this)->LoadMesh(pPak, pArr, ver);
    tag = 0;
    if (((PCDFile *)pPak)->Read(&tag, 4) != 4) {
        return 0;
    }
    if (tag == 4) {
        if (!((PMNode *)this)->LoadAnim(pPak)) {
            return 0;
        }
        m_unk3E |= 2;
        tag = 0;
        if (((PCDFile *)pPak)->Read(&tag, 4) != 4) {
            return 0;
        }
    }
    if (tag == 0x10) {
        LoadCollision(pPak);
        tag = 0;
        if (((PCDFile *)pPak)->Read(&tag, 4) != 4) {
            return 0;
        }
    }
    if (tag == 2) {
        return 1;
    }
    while (tag == 1) {
        PMeshNode *child = new PMeshNode((PResource::eResObjType)m_unk04);
        if (child == 0) {
            return 0;
        }
        ((PArray *)&m_unk14)->Add(child);
        if (!child->Load(pPak, pArr, ver)) {
            return 0;
        }
        tag = 0;
        if (((PCDFile *)pPak)->Read(&tag, 4) != 4) {
            return 0;
        }
        if (tag == 2) {
            return 1;
        }
    }
    return 0;
}

// Leading virtuals of PMeshNode's vtable (__vt__9PMeshNode); a call through this view
// loads the slot into $t9 as the original's virtual calls do. ComputeBoundingBox is index 7.
class PMeshNodeVirtuals {
public:
    virtual ~PMeshNodeVirtuals();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void ComputeBoundingBox();
};

// DRAFT: 0x00190BC0 ComputeBoundingBox__9PMeshNodeFv
// note: 98 words differ; pickup flag loaded into v0 not a0, and the pSrc/call-arg branch order and box-to-bounds store order differ. Tried: &&-gated ternary, if-form pickup test (121), w-constant reorder (no change).
void PMeshNode::ComputeBoundingBox() {
    float pts[2][4];
    float box[2][4];
    float bounds[2][4];
    PMeshNode *child;
    float (*pSrc)[2][4];
    int i;

    pSrc = (m_unk10 != 0) ? ((m_unk10->m_unk0D != 0) ? (float (*)[2][4])((char *)m_unk10 + 0x10) : 0) : 0;
    if (pSrc != 0) {
        PBoundBoxToBoundBox__FPA2_A4_fPA2_A4_f((m_unk10->m_unk0D != 0) ? (float (*)[2][4])((char *)m_unk10 + 0x10) : 0, &box);
        bounds[0][0] = box[0][0];
        bounds[0][1] = box[0][1];
        bounds[0][2] = box[0][2];
        bounds[0][3] = 1.0f;
        bounds[1][0] = box[1][0];
        bounds[1][1] = box[1][1];
        bounds[1][2] = box[1][2];
        bounds[1][3] = 1.0f;
    } else {
        bounds[0][0] = 32767.0f;
        bounds[0][1] = 32767.0f;
        bounds[0][2] = 32767.0f;
        bounds[0][3] = 1.0f;
        bounds[1][0] = -32767.0f;
        bounds[1][1] = -32767.0f;
        bounds[1][2] = -32767.0f;
        bounds[1][3] = 1.0f;
    }

    m_unk18 = 0;
    child = (m_unk14 != 0) ? m_unk1C[0] : 0;
    while (child != 0) {
        float *pm;
        ((PMeshNodeVirtuals *)child)->ComputeBoundingBox();
        pm = child->m_unk110;
        *(u_long128 *)pts[0] = *(u_long128 *)pm;
        sceVu0AddVector(pts[0], pts[0], child->m_unk80);
        *(u_long128 *)pts[1] = *(u_long128 *)(pm + 4);
        PBoundBoxToBoundBox__FPA2_A4_fPA2_A4_f(&pts, &box);
        for (i = 0; i < 3; i++) {
            if (box[0][i] < bounds[0][i]) {
                bounds[0][i] = box[0][i];
            }
            if (box[1][i] > bounds[1][i]) {
                bounds[1][i] = box[1][i];
            }
        }
        m_unk18++;
        child = (m_unk18 < m_unk14) ? m_unk1C[m_unk18] : 0;
    }
    MakePBoundBox__FPfPfPA2_A4_f(bounds[0], bounds[1], (float (*)[2][4])m_unk110);
}

// One 0x18-byte entry of a PMeshNodeAnimDataTable: key, anim, then a PArray at +8.
struct AnimTableEntry {
    unsigned int key;
    PAnim *anim;
    char arr[0x10];
};

// DRAFT: 0x00190DC0 RecurseAttachAnim__9PMeshNodeFP22PMeshNodeAnimDataTable
// note: 76 words differ; the frame is 0x80 not 0x90 and the original keeps this in s6, entries in s7, pAnimDataTable in s0. Tried a do-while, a for loop over entries[i], and a for loop with an offset.
int PMeshNode::RecurseAttachAnim(PMeshNodeAnimDataTable *pAnimDataTable) {
    if (pAnimDataTable == 0) {
        CdsAssert__FPciPc("PMeshNode.cpp", 0x50, "pAnimDataTable");
    }
    ((PMNode *)this)->RecurseDetachAnim();
    AnimTableEntry *entries = (AnimTableEntry *)pAnimDataTable->m_unk0C;
    if (entries == 0) {
        CdsAssert__FPciPc("PMeshNode.cpp", 0x56, "apAnimTable");
    }
    unsigned int count = pAnimDataTable->m_unk08;
    unsigned int off = 0;
    for (unsigned int i = 0; i < count; i++, off += 0x18) {
        AnimTableEntry *e = (AnimTableEntry *)((char *)entries + off);
        PMNode *found = ((PMNode *)this)->Find(e->key);
        if (found != 0) {
            found->AttachAnim(e->anim, true);
            found->AddFxTriggers((PArray *)e->arr, true);
            short animTime = e->anim->m_unk8;
            if (m_unk108 < animTime) {
                m_unk108 = animTime;
            }
        }
        m_unk108 -= 1;
    }
    return 1;
}

// FUNCTION: 0x00190F00 __dt__9PMeshNodeFv
PMeshNode::~PMeshNode() {
    m_unk00 = __vt__9PMeshNode;
    DetachAllLights();
    if (m_unk103) {
        __dla__FPv(m_unk104);
        m_unk104 = 0;
        m_unk103 = 0;
    }
    __dt__6PArrayFv(&m_unk130, -1);
    __dt__6PMNodeFv(this, 0);
}

// DRAFT: 0x00190F90 __ct__9PMeshNodeFR9PMeshNode
// note: 51 words differ; original spills this to 0x28/0x2C and keeps other in s0 (ours keeps this in s0, other in s1); spill needs PArray-with-dtor members, header uses char arrays. Not fixed.
PMeshNode::PMeshNode(PMeshNode &other) {
    *(void **)this = __vt__9PResource;
    m_unk04 = 0;
    *(void **)this = __vt__6PMNode;
    __ct__6PArrayFv(&m_unk14);
    sceVu0UnitMatrix(&m_unk40[0][0]);
    __ct__6PArrayFv(&m_unkD8);
    ((PMNode *)this)->InitMembers();
    *(void **)this = __vt__9PMeshNode;
    __ct__6PArrayFv(&m_unk130);
    InitMembers();
    ((PMNode *)this)->CopyMNode(*(PMNode *)&other, true);
    m_unk104 = other.m_unk104;
    *(u_long128 *)m_unk110 = *(u_long128 *)other.m_unk110;
    *(u_long128 *)m_unk120 = *(u_long128 *)other.m_unk120;
}

// DRAFT: 0x00191070 __ct__9PMeshNodeFQ29PResource11eResObjType
// note: 40 words differ; m2c draft; base-class vtable stores and PResource/PMNode ctor sequence not matched (PArray ctor/member layout as in copy ctor).
PMeshNode::PMeshNode(PResource::eResObjType eType) {
    *(void **)this = __vt__9PResource;
    m_unk04 = 0;
    *(void **)this = __vt__6PMNode;
    __ct__6PArrayFv(&m_unk14);
    sceVu0UnitMatrix(&m_unk40[0][0]);
    __ct__6PArrayFv(&m_unkD8);
    ((PMNode *)this)->InitMembers();
    *(void **)this = __vt__9PMeshNode;
    __ct__6PArrayFv(&m_unk130);
    InitMembers();
    m_unk04 = (int)eType;
}

// FUNCTION: 0x00191120 InitMembers__9PMeshNodeFv
void PMeshNode::InitMembers() {
    m_unk103 = 0;
    m_unk104 = 0;
    m_unk100 = 0;
    m_unk108 = 0;
    *(u_long128 *)m_unk110 = *(u_long128 *)&gUnitMatrix[12];
    *(u_long128 *)m_unk120 = *(u_long128 *)&gUnitMatrix[12];
    m_unk04 = 1;
    m_unk102 = 1;
}
