// FLAGS: -str readonly
#include "types.h"
#include "PMeshNode.h"

// TODO(header): foreign declarations
class PArray {
public:
    unsigned int count;
    int index;
    void *table;
    int Find(void *pItem);
    void RemoveAt(int idx);
    void Remove(void *pItem);
};

class PLight {
public:
    char _pad00[0x4C];
    int m_unk4C;
};

class PMNode {
public:
    void InitMembers();
};

extern "C" void *__ct__6PArrayFv(void *pThis);
extern "C" void __dt__6PArrayFv(void *pThis, short flags);
extern "C" void __dt__6PMNodeFv(void *pThis, short flags);
extern "C" void __dla__FPv(void *pMem);
extern "C" void __dl__FPv(void *pMem);
extern "C" void sceVu0UnitMatrix(float *pMatrix);
extern "C" void CdsAssert__FPciPc(const char *pFile, int line, const char *pExpr);

extern unsigned char __vt__9PMeshNode[];
extern unsigned char __vt__6PMNode[];
extern unsigned char __vt__9PResource[];
extern float gUnitMatrix[16];

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

// DRAFT: 0x00190510 RemoveFromCollisionArray__9PMeshNodeFP6PArray
// note: 7 words differ; original has one extra nop before the epilogue (0xA8 vs 0xA4), shifting the beq at 0x58 and the tail.
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

// DRAFT: 0x00191070 __ct__9PMeshNodeFQ29PResource11eResObjType
// note: m2c draft; base-class vtable stores and PResource/PMNode ctor sequence not verified.
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
