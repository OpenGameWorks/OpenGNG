// FLAGS: -str readonly
#include "types.h"
#include "CamSphere.h"
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void __dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern unsigned char __vt__9CamSphere[0x7C];
extern unsigned char gEng[0x1A000];
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);

class PVec3 {
public:
    float m_v[4];
};

class Camera {
public:
    void CamCollideSphere(PVec3 arg0, float arg1);
};

// The game's assert evaluates the condition at runtime, so the literal-address test is kept.
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("CamSphere.cpp", line, #cond))

// FUNCTION: 0x001A3100 __dt__9CamSphereFv
CamSphere::~CamSphere() {
}

// FUNCTION: 0x001A3160 GetClassName__9CamSphereFv
const char *CamSphere::GetClassName() {
    return "Camera Collision Sphere";
}

// FUNCTION: 0x001A3170 SetEditableVars__9CamSphereFPc
void CamSphere::SetEditableVars(char *pSrc) {
    memcpy((char *)this + 0x1B0, pSrc, 0x10);
}

// FUNCTION: 0x001A3180 Execute__9CamSphereFv
void CamSphere::Execute() {
    switch (m_unk20) {
    case -1: {
        m_unk1C0 = m_unk1B0;
        m_unk1C4 = m_unk1B4;
        m_unk1C8 = m_unk1B8;
        m_unk1D0 = m_unk1BC;
        char *pBuf = m_unk3C;
        if (pBuf != 0) {
            *(u_long128 *)(pBuf + 0x80) = *(u_long128 *)&m_unk1C0;
            ((unsigned char *)pBuf)[0x3E] |= 8;
        } else {
            *(u_long128 *)_pad190 = *(u_long128 *)&m_unk1C0;
        }
        SetState(0);
        break;
    }
    case 0: {
        Camera *pCam = (Camera *)(gEng + 0x19760);
        CDS_ASSERT(0x26, pCam);
        PVec3 vPos = *(PVec3 *)&m_unk1C0;
        pCam->CamCollideSphere(vPos, m_unk1D0);
        break;
    }
    }
}

// FUNCTION: 0x001A3280 __ct__9CamSphereFv
CamSphere::CamSphere() : EntityBaseClass((LoadClass)4, 0) {}
