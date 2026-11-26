// FLAGS: -str readonly
#include "types.h"
#include "MovingFog.h"
#include "MaxEngine.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);
struct tagParticleMovingFogParams;
extern "C" void CreateMovingFog__16PParticleManagerFP26tagParticleMovingFogParams(void *pManager, tagParticleMovingFogParams *pParams);
extern "C" void DestroyMovingFog__16PParticleManagerFv(void *pManager);
extern char gGfxEng[1504384];
extern MaxEngine gEng;

struct MovingFogVec4 {
    float x;
    float y;
    float z;
    float w;
};

// Creation block passed to PParticleManager::CreateMovingFog (0x44 bytes).
struct MovingFogParams {
    MovingFogVec4 vMin;         // 0x00
    MovingFogVec4 vMax;         // 0x10
    int nZero0;                 // 0x20
    int nZero1;                 // 0x24
    int nOne0;                  // 0x28 (float 1.0f bits)
    int nOne1;                  // 0x2C (float 1.0f bits)
    float fEdit[5];             // 0x30 editable-vars tail copied from m_unk1B0 + 0x30
};

// FUNCTION: 0x001D68C0 OutputDebug__9MovingFogFv
void MovingFog::OutputDebug() {
}

// FUNCTION: 0x001D68D0 GetClassName__9MovingFogFv
const char *MovingFog::GetClassName() {
    return "MovingFog";
}

// FUNCTION: 0x001D68E0 SetEditableVars__9MovingFogFPc
void MovingFog::SetEditableVars(char *pSrc) {
    memcpy(m_unk1B0, pSrc, 0x44);
}

// DRAFT: 0x001D68F0 Execute__9MovingFogFv
// note: frame 0x70 vs 0x90 (vMin/vMax temps folded, no lq copies), branch layout and gGfxEng reloc differ; tried local order (vMin,vMax,p and p,vMax,vMin).
void MovingFog::Execute() {
    MovingFogParams p;
    MovingFogVec4 vMax;
    MovingFogVec4 vMin;

    switch (m_unk20) {
    case -1:
        vMin.x = *(float *)(m_unk1B0 + 0x00) - *(float *)(m_unk1B0 + 0x10);
        vMin.y = *(float *)(m_unk1B0 + 0x04) - *(float *)(m_unk1B0 + 0x14);
        vMin.z = *(float *)(m_unk1B0 + 0x08) - *(float *)(m_unk1B0 + 0x18);
        vMax.x = *(float *)(m_unk1B0 + 0x00) + *(float *)(m_unk1B0 + 0x10);
        vMax.y = *(float *)(m_unk1B0 + 0x04) + *(float *)(m_unk1B0 + 0x14);
        vMax.z = *(float *)(m_unk1B0 + 0x08) + *(float *)(m_unk1B0 + 0x18);
        p.vMin = vMin;
        p.nOne0 = 0x3F800000;
        p.nOne1 = 0x3F800000;
        p.vMax = vMax;
        p.nZero0 = 0;
        p.nZero1 = 0;
        p.fEdit[0] = *(float *)(m_unk1B0 + 0x30);
        p.fEdit[1] = *(float *)(m_unk1B0 + 0x34);
        p.fEdit[2] = *(float *)(m_unk1B0 + 0x38);
        p.fEdit[3] = *(float *)(m_unk1B0 + 0x3C);
        p.fEdit[4] = *(float *)(m_unk1B0 + 0x40);
        CreateMovingFog__16PParticleManagerFP26tagParticleMovingFogParams(gGfxEng + 0x154F00, (tagParticleMovingFogParams *)&p);
        gEng.CreateScrollingTrees();
        SetState(0);
        break;
    case 0:
    case -2:
        return;
    }
}

// FUNCTION: 0x001D6A10 __dt__9MovingFogFv
MovingFog::~MovingFog() {
    DestroyMovingFog__16PParticleManagerFv(gGfxEng + 0x154F00);
    gEng.DestroyScrollingTrees();
}

// FUNCTION: 0x001D6A90 __ct__9MovingFogFv
MovingFog::MovingFog() : EntityBaseClass((LoadClass)5, 0) { EnableSleep(false, false); }
