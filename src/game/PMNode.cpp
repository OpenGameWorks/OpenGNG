#include "types.h"
#include "PMNode.h"

// TODO(header): foreign declarations
extern "C" void sceVu0ApplyMatrix(float *, float (*)[4], float *);
extern "C" void __dt__5PMeshFv(void *, short);

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

// FUNCTION: 0x00193070 GetFrameRate__6PMNodeFv
float PMNode::GetFrameRate() {
    void *pObj = m_unk24;
    if (pObj != 0) {
        return ((PFrameSource *)pObj)->GetFrameRate();
    }
    return 0.0f;
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

// FUNCTION: 0x00194C30 ScaleSet__6PMNodeFffff
void PMNode::ScaleSet(float a, float b, float c, float d) {
    m_unkA0[0] = a;
    m_unkA0[1] = b;
    m_unkA0[2] = c;
    m_unkA0[3] = d;
    m_unk3E |= 8;
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
