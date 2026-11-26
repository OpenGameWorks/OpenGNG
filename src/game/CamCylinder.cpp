// FLAGS: -str readonly
#include "types.h"
#include "CamCylinder.h"
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// TODO(header): foreign declarations
extern unsigned char gEng[0x1A000];
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);

class PVec3 {
public:
    float m_v[4];
};

class Camera {
public:
    void CamCollideCylinder(PVec3 arg0, float arg1, float arg2);
};

// The game's assert evaluates the condition at runtime, so the literal-address test is kept.
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("CamCylinder.cpp", line, #cond))

// FUNCTION: 0x001A3A60 __dt__11CamCylinderFv
CamCylinder::~CamCylinder() {
}

// FUNCTION: 0x001A3AC0 GetClassName__11CamCylinderFv
const char *CamCylinder::GetClassName() {
    return "Camera Collision Cylinder";
}

// FUNCTION: 0x001A3AD0 SetCylinderParams__11CamCylinderFfffff
void CamCylinder::SetCylinderParams(float fA, float fB, float fC, float fD, float fE) {
    m_unk1B0 = fA;
    m_unk1B4 = fB;
    m_unk1B8 = fC;
    m_unk1BC = fD;
    m_unk1C0 = fE;
    m_unk1D0 = m_unk1B0;
    m_unk1D4 = m_unk1B4;
    m_unk1D8 = m_unk1B8;
    m_unk1E0 = m_unk1BC;
    m_unk1E4 = m_unk1C0;
}

// FUNCTION: 0x001A3B10 SetEditableVars__11CamCylinderFPc
void CamCylinder::SetEditableVars(char *pSrc) {
    memcpy((char *)this + 0x1B0, pSrc, 0x14);
}

// DRAFT: 0x001A3B20 Execute__11CamCylinderFv
// note: 10 words differ (was 58): the switch shape and the unsigned m_unk3C[0x3E] byte through a local pointer now match. Left: the vPos setup. The original loads the four floats into f3..f0 before forming &vPos in a1, then stores through a1; ours stores each one in turn. Brace init of vPos gave 32 words; float locals loaded first gave 10 (no change).
void CamCylinder::Execute() {
    switch (m_unk20) {
    case -1:
        m_unk1D0 = m_unk1B0;
        m_unk1D4 = m_unk1B4;
        m_unk1D8 = m_unk1B8;
        m_unk1E0 = m_unk1BC;
        m_unk1E4 = m_unk1C0;
        char *pBox = m_unk3C;
        if (pBox != 0) {
            *(u_long128 *)(pBox + 0x80) = *(u_long128 *)&m_unk1D0;
            ((unsigned char *)pBox)[0x3E] |= 8;
        } else {
            *(u_long128 *)_pad190 = *(u_long128 *)&m_unk1D0;
        }
        SetState(0);
        break;
    case 0: {
        Camera *pCam = (Camera *)(gEng + 0x19760);
        CDS_ASSERT(0x27, pCam);
        PVec3 vPos;
        vPos.m_v[0] = m_unk1D0;
        vPos.m_v[1] = m_unk1D4;
        vPos.m_v[2] = m_unk1D8;
        vPos.m_v[3] = m_unk1DC;
        pCam->CamCollideCylinder(vPos, m_unk1E0, m_unk1E4);
        break;
    }
    }
}

// FUNCTION: 0x001A3C30 __ct__11CamCylinderFv
CamCylinder::CamCylinder() : EntityBaseClass((LoadClass)5, 0) {}
