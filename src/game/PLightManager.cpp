// FLAGS: -str readonly
#include "PLightManager.h"

// TODO(header): foreign declarations
extern "C" void __ct__5PListFv(void *pThis);
extern "C" void __dt__5PListFv(void *pThis, short nFlag);

// Light node: id at 0x00, next node at 0x04.
struct PLightNode {
    unsigned int m_unk0;
    PLightNode *m_unk4;
};

// FUNCTION: 0x0018E880 LightCompareBrightness__FPvPv
bool LightCompareBrightness(void *pA, void *pB) {
    return *(float *)((char *)pA + 0x50) < *(float *)((char *)pB + 0x50);
}

// DRAFT: 0x0018EC70 GetLightObject__13PLightManagerFUi
// note: 8 words differ; the original keeps the node in v1 and tests a shared tail with beqz v1, we emit movz. Tried: return nId (12), ternary tail (8, best), if/pResult tail (14), else-arm loop (14), while loop (17).
void *PLightManager::GetLightObject(unsigned int nId) {
    PLightNode *pNode = (PLightNode *)m_unk14;
    if (pNode != 0) {
        do {
            if (pNode->m_unk0 == nId) {
                break;
            }
            pNode = pNode->m_unk4;
        } while (pNode != 0);
    }
    return (void *)(pNode != 0 ? nId : 0);
}

// FUNCTION: 0x0018ECC0 SetLightColor__13PLightManagerFUiPf
void PLightManager::SetLightColor(unsigned int nId, float *pColor) {
    char *pObj = (char *)GetLightObject(nId);
    if (pObj != 0) {
        *(float *)(pObj + 0x30) = pColor[0];
        *(float *)(pObj + 0x34) = pColor[1];
        *(float *)(pObj + 0x38) = pColor[2];
    }
}

// FUNCTION: 0x0018F4C0 __dt__13PLightManagerFv
PLightManager::~PLightManager() {
    DestroyAllStaticLights();
    DestroyAllDynamicLights();
    __dt__5PListFv(m_unk10, -1);
}

// FUNCTION: 0x0018F540 __ct__13PLightManagerFv
PLightManager::PLightManager() {
    __ct__5PListFv(m_unk10);
    m_unk20 = 0;
    m_unk0.Allocate(0x20U);
}
