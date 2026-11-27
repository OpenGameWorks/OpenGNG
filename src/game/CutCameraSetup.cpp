// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "CutCameraSetup.h"
#include "Camera.h"
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// TODO(header): foreign declarations
extern unsigned char gEng[0x1A000];
class PVec3 { public: float m_v[4]; };

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert("CutCameraSetup.cpp", line, #cond))

// FUNCTION: 0x001DC2A0 __dt__14CutCameraSetupFv
CutCameraSetup::~CutCameraSetup() {}

// FUNCTION: 0x001DC300 GetClassName__14CutCameraSetupFv
const char *CutCameraSetup::GetClassName() {
    return "CutCameraSetup";
}

// FUNCTION: 0x001DC310 SetEditableVars__14CutCameraSetupFPc
void CutCameraSetup::SetEditableVars(char *pSrc) {
    memcpy((char *)this + 0x1B0, pSrc, 0xAC);
}

// DRAFT: 0x001DC320 Execute__14CutCameraSetupFv
// note: frame is 0x120 vs 0x170, local slots 0x10 apart vs 0x20, mode compare order 1,3,2 vs 3,2,1 (switch lowering not controlled by case order). Tried: explicit -2 return (208->205), hoisted PVec3 locals (205->196).
void CutCameraSetup::Execute() {
    if (m_unk20 == -2) {
        return;
    }
    switch (m_unk20) {
    case -1:
        m_pMainCamera = (Camera *)(gEng + 0x19760);
        CDS_ASSERT(0x1B, m_pMainCamera);
        PVec3 p0, p1, p2, p3, p4;
        switch (m_unk1B0) {
        case 3: {
            p0.m_v[0] = m_unk1C4; p0.m_v[1] = m_unk1C8; p0.m_v[2] = m_unk1CC;
            p1.m_v[0] = m_unk1DC; p1.m_v[1] = m_unk1E0; p1.m_v[2] = m_unk1E4;
            p2.m_v[0] = m_unk1F4; p2.m_v[1] = m_unk1F8; p2.m_v[2] = m_unk1FC;
            p3.m_v[0] = m_unk20C; p3.m_v[1] = m_unk210; p3.m_v[2] = m_unk214;
            p4.m_v[0] = m_unk23C; p4.m_v[1] = m_unk240; p4.m_v[2] = m_unk244; p4.m_v[3] = m_unk24C;
            m_pMainCamera->SetupCutCamera_Pan(m_unk1B4, m_unk1B8, m_unk224, m_unk1BC, p0, p1, p2, p3,
                                              m_unk228, m_unk22C, m_unk230, m_unk234, m_unk238 != 0,
                                              p4, m_unk254 != 0, m_unk258);
            break;
        }
        case 2: {
            p0.m_v[0] = m_unk1C4; p0.m_v[1] = m_unk1C8; p0.m_v[2] = m_unk1CC;
            p1.m_v[0] = m_unk1DC; p1.m_v[1] = m_unk1E0; p1.m_v[2] = m_unk1E4;
            p2.m_v[0] = m_unk1F4; p2.m_v[1] = m_unk1F8; p2.m_v[2] = m_unk1FC;
            p3.m_v[0] = m_unk23C; p3.m_v[1] = m_unk240; p3.m_v[2] = m_unk244; p3.m_v[3] = m_unk24C;
            m_pMainCamera->SetupCutCamera_MoveTo(m_unk1B4, m_unk1B8, m_unk224, m_unk1BC, m_unk1C0, p0, p1, p2,
                                                 m_unk228, m_unk22C, m_unk230, m_unk234, m_unk238 != 0,
                                                 p3, m_unk254 != 0, m_unk258);
            break;
        }
        case 1: {
            p0.m_v[0] = m_unk1C4; p0.m_v[1] = m_unk1C8; p0.m_v[2] = m_unk1CC;
            p1.m_v[0] = m_unk1F4; p1.m_v[1] = m_unk1F8; p1.m_v[2] = m_unk1FC;
            p2.m_v[0] = m_unk23C; p2.m_v[1] = m_unk240; p2.m_v[2] = m_unk244; p2.m_v[3] = m_unk24C;
            m_pMainCamera->SetupCutCamera_Fixed(m_unk1B4, m_unk1B8, m_unk224, m_unk1BC, m_unk1C0, p0, p1,
                                                m_unk228, m_unk22C, m_unk230, m_unk234, m_unk238 != 0,
                                                p2, m_unk254 != 0, m_unk258);
            break;
        }
        default:
            CdsAssert("CutCameraSetup.cpp", 0x8F, "Invalid Cut Camera type from layout tool");
            break;
        }
        SetState(-2);
        break;
    }
}


// FUNCTION: 0x001DC700 __ct__14CutCameraSetupFv
CutCameraSetup::CutCameraSetup() : EntityBaseClass((LoadClass)5, 0) { EnableSleep(false, false); }
