// FLAGS: -str readonly
#include "types.h"
#include "CamSphere.h"

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

// DRAFT: 0x001A3180 Execute__9CamSphereFv
// note: 54 words differ; branch polarity on the copy block (original beq into it, then b to epilogue) and call-block placement differ, gEng lui/addiu immediates are unresolved relocs. Variants: zero test first 55 words, nested else-if 61 words.
void CamSphere::Execute() {
    if (m_unk20 != 0) {
        if (m_unk20 == -1) {
            m_unk1C0 = m_unk1B0;
            m_unk1C4 = m_unk1B4;
            m_unk1C8 = m_unk1B8;
            m_unk1D0 = m_unk1BC;
            if (m_unk3C != 0) {
                *(u_long128 *)(m_unk3C + 0x80) = *(u_long128 *)&m_unk1C0;
                m_unk3C[0x3E] |= 8;
            } else {
                *(u_long128 *)_pad190 = *(u_long128 *)&m_unk1C0;
            }
            SetState(0);
        }
    } else {
        Camera *pCam = (Camera *)gEng;
        CDS_ASSERT(0x26, pCam);
        PVec3 vPos;
        vPos.m_v[0] = m_unk1C0;
        vPos.m_v[1] = m_unk1C4;
        vPos.m_v[2] = m_unk1C8;
        vPos.m_v[3] = m_unk1CC;
        pCam->CamCollideSphere(vPos, m_unk1D0);
    }
}

// FUNCTION: 0x001A3280 __ct__9CamSphereFv
CamSphere::CamSphere() : EntityBaseClass((LoadClass)4, 0) {}
