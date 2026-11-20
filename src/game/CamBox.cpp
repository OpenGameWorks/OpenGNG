// FLAGS: -str readonly
#include "types.h"
#include "CamBox.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *file, int line, char *expr);
extern unsigned char gEng[0x1A000];
extern unsigned char gCamTarget[0x10];
struct tagBOX;
class MathAPI {
public:
    static int PointInBoundBox(float (*pPoint)[4], tagBOX *pBox);
    static float Distance(float (*pA)[4], float (*pB)[4]);
};
class CVector3 {
public:
    float m_unk0;
    float m_unk4;
    float m_unk8;
};
class Camera {
public:
    char _pad0[0x2BC];
    int m_unk2BC;
    CVector3 ClosestPointOnLine(CVector3 a, CVector3 b, CVector3 c);
};

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("CamBox.cpp", line, #cond))

// FUNCTION: 0x0019C530 __dt__6CamBoxFv
CamBox::~CamBox() {}

// DRAFT: 0x0019C5A0 PointInsideTriggerArea__6CamBoxFPA4_fPA4_f
// note: this/pPoint registers inverted (orig this=s1, pPoint=s0), frame 0xC0 vs 0xB0, gEng reloc; tried py/pz pointer and struct-copy variants, 3 attempts.
int CamBox::PointInsideTriggerArea(float (*pPoint)[4], float (*pOther)[4]) {
    float f20;
    float blk60[4];
    float *py;
    float *pz;
    CVector3 seg0;
    CVector3 seg1;
    if (m_unk298 == 0) {
        if (MathAPI::PointInBoundBox(pPoint, (tagBOX *)m_unk1B0)) {
            return 1;
        }
        return 0;
    }
    if (m_unk298 == 1) {
        blk60[0] = m_unk278;
        blk60[1] = m_unk27C;
        blk60[2] = m_unk280;
        f20 = m_unk284;
        return (MathAPI::Distance(pPoint, &blk60) < f20) ? 1 : 0;
    }
    if (m_unk298 == 2) {
        py = &blk60[1];
        pz = &blk60[2];
        blk60[0] = m_unk278;
        *py = m_unk27C;
        *pz = m_unk280;
        f20 = m_unk284;
        seg0 = *(CVector3 *)blk60;
        if (MathAPI::Distance(pPoint, &blk60) < f20) {
            return 1;
        }
        blk60[0] = m_unk288;
        *py = m_unk28C;
        *pz = m_unk290;
        f20 = m_unk294;
        seg1 = *(CVector3 *)blk60;
        if (MathAPI::Distance(pPoint, &blk60) < f20) {
            return 1;
        }
        char *pTgt = *(char **)gCamTarget;
        CDS_ASSERT(0x180, pTgt);
        char *pSrc = *(char **)(pTgt + 0x3C) ? *(char **)(pTgt + 0x3C) + 0x80 : pTgt + 0x190;
        CVector3 pt = *(CVector3 *)pSrc;
        Camera *pCam = (Camera *)gEng;
        CVector3 ret = pCam->ClosestPointOnLine(seg0, seg1, pt);
        blk60[0] = ret.m_unk0;
        *py = ret.m_unk4;
        *pz = ret.m_unk8;
        return (MathAPI::Distance(pPoint, &blk60) < f20) ? 1 : 0;
    }
    CDS_ASSERT(0x197, 0);
    return 0;
}

// FUNCTION: 0x0019CEE0 __ct__6CamBoxFv
CamBox::CamBox() : EntityBaseClass((EntityBaseClass::LoadClass)4, 0) {
    EnableSleep(false, false);
    m_unk2A4 = 0;
}

// FUNCTION: 0x0019C7E0 OnSleepEvent__6CamBoxFv
void CamBox::OnSleepEvent() {
    Camera *pCam = (Camera *)gEng;
    CDS_ASSERT(0x127, pCam);
    if (pCam->m_unk2BC != 0 && pCam->m_unk2BC == (int)this) {
        pCam->m_unk2BC = 0;
    }
}
