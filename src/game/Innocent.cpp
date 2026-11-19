#include "types.h"
#include "Innocent.h"

// TODO(header): foreign declarations
class EntityBaseClass;
class PMNode;
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int eLoadClass, unsigned int nFlags);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *);
extern unsigned char __vt__8Innocent[];
extern "C" void SequenceViewer__15EntityBaseClassFPPUii(void *pThis, unsigned int **pTable, int nArg);
extern unsigned char SequenceTable[0x40];
// The second argument is not set by the caller; the original passes a1 through unchanged.
extern "C" int InstanceIsValid__15EntityBaseClassFUi(EntityBaseClass *pEntity);
extern "C" void ScaleSet__6PMNodeFffff(PMNode *pThis, float a, float b, float c, float d);

// FUNCTION: 0x0019F260 __dt__8InnocentFv
extern "C" void *__dt__8InnocentFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__8Innocent;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x0019F310 AnimationViewer__8InnocentFi
int Innocent::AnimationViewer(int arg0) {
    SequenceViewer__15EntityBaseClassFPPUii(this, (unsigned int **)SequenceTable, arg0);
    return 0x23;
}

// DRAFT: 0x0019F340 OnWakeEvent__8InnocentFv
// note: 13 words differ; original materializes 1.03f inline (lui/ori/mtc1 in the beqz delay slot), ours loads a pooled gp literal. Tried: function-scope local float, block-scope local float; count unchanged.
void Innocent::OnWakeEvent() {
    if (m_unk1B0 == 3) {
        PMNode *pNode = m_unk3C;
        if (pNode != 0) {
            ScaleSet__6PMNodeFffff(pNode, 1.03f, 1.03f, 1.03f, 1.0f);
        }
    }
}

// FUNCTION: 0x0019F5C0 TrappedEntityRemoved__8InnocentFv
int Innocent::TrappedEntityRemoved() {
    EntityBaseClass **pEnt;
    int i;
    i = 0;
    pEnt = m_unk1EC;
    do {
        if (*pEnt != 0 && InstanceIsValid__15EntityBaseClassFUi(*pEnt)) {
            return 0;
        }
        i++;
        pEnt++;
    } while (i < 3);
    return 1;
}

// FUNCTION: 0x001A1460 __ct__8InnocentFv
Innocent::Innocent() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 6, 0);
    m_unk0 = __vt__8Innocent;
    m_unk274 = 0;
    m_unkD4 = 0;
    m_unk272 = 0;
    m_unk288 = 0;
    m_unk103 = 0xFE;
    m_unk104 = 0x40000000;
    m_unk108 = 0x40800000;
}
