// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "CamBox.h"
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// TODO(header): foreign declarations
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
    int m_unk2C0;
    float m_unk2C4;
    CVector3 ClosestPointOnLine(CVector3 a, CVector3 b, CVector3 c);
    unsigned char PlayingCutCamera();
    void SetCamBoxData(int arg0, void *arg1);
    void SetCamMode(short mode, bool flag);
    void SetCamBoxValue_FollowHeight(float arg0);
};
extern char *mPlayerAPI__13EntityManager;
extern char *mCameraAPI__13EntityManager;
extern "C" void sceVu0UnitMatrix(float *pMatrix);
extern "C" void RotateX__5PMat4Ff(float *pMat, float angle);
extern "C" void RotateY__5PMat4Ff(float *pMat, float angle);
extern "C" void RotateZ__5PMat4Ff(float *pMat, float angle);

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert("CamBox.cpp", line, #cond))

// FUNCTION: 0x0019C530 __dt__6CamBoxFv
CamBox::~CamBox() {}

// FUNCTION: 0x0019C590 GetClassName__6CamBoxFv
const char *CamBox::GetClassName() {
    return "Camera Box";
}

// DRAFT: 0x0019C5A0 PointInsideTriggerArea__6CamBoxFPA4_fPA4_f
// note: this/pPoint registers inverted (orig this=s1, pPoint=s0; draft saves s3/s2), frame 0xC0 vs 0xB0 (extra 16-byte local), gEng reloc; tried py/pz pointer, struct-copy, and py/pz declaration-order variants, 4 attempts.
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

#define CAMBOX_PIT(pt, other) PointInsideTriggerArea((float (*)[4])(pt), (float (*)[4])(other))

// FUNCTION: 0x0019C850 SetEditableVars__6CamBoxFPc
void CamBox::SetEditableVars(char *pSrc) {
    memcpy((char *)this + 0x1B0, pSrc, 0xF4);
}

// DRAFT: 0x0019C860 Execute__6CamBoxFv
// note: 61 differing words; case 5 constant 0x3F800000 reloaded into a3 for +0x7C in the original (draft reuses v0), arg setup hoisted above the neg.s stores, +0x81 if-form gives a bnez; 4 attempts this session (+0x81 if-form kept, others no gain)
void CamBox::Execute() {
    Camera *pCam;
    char *pPlayer;
    char *pvPlayerPos;
    char *pvCamPos;
    char *pCamBox_Flip;
    char *pCamBox_FixedLookAt;
    char *pCamBoxRail;
    float sp50[16];

    pCam = (Camera *)(gEng + 0x19760);
    CDS_ASSERT(0x15, pCam);
    if (pCam->PlayingCutCamera()) {
        m_unk2A4 = 0;
        return;
    }
    if (pCam->m_unk2BC == 0 || pCam->m_unk2BC == (int)this) {
        pPlayer = mPlayerAPI__13EntityManager;
        pvPlayerPos = *(char **)(pPlayer + 0x3C) ? *(char **)(pPlayer + 0x3C) + 0x80 : pPlayer + 0x190;
        CDS_ASSERT(0x2C, pvPlayerPos);
        pvCamPos = mCameraAPI__13EntityManager;
        CDS_ASSERT(0x2F, pvCamPos);
        if (m_unk1E0 == 6) {
            if (m_unk2A4 == 0) {
                if (CAMBOX_PIT(pvPlayerPos, pvCamPos)) {
                    m_unk2A4 = 1;
                    pCam->m_unk2BC = (int)this;
                    pCam->m_unk2C0 = m_unk20C;
                    pCam->m_unk2C4 = m_unk1E4;
                }
            } else if (CAMBOX_PIT(pvPlayerPos, pvCamPos) == 0) {
                m_unk2A4 = 0;
                pCam->m_unk2BC = 0;
                pCam->m_unk2C0 = 0;
                if (m_unk208 != 0) {
                    SetState(-2);
                }
            }
        } else if (m_unk2A4 == 0) {
            if (CAMBOX_PIT(pvPlayerPos, pvCamPos)) {
                m_unk2A4 = 1;
                pCam->m_unk2BC = (int)this;
                switch (m_unk1E0) {
                case 1:
                    break;
                case 2:
                    pCam = (Camera *)(gEng + 0x19760);
                    CDS_ASSERT(0x66, pCam);
                    if (m_unk1EC == 0.0f) {
                        if (m_unk1F0 == 0.0f && m_unk1F4 == 0.0f) {
                            CDS_ASSERT(0x6B, !"eif 0, 0, 0 error.  see keith or ted");
                        } else {
                            goto block34;
                        }
                    } else {
block34:
                        pCamBox_Flip = (char *)pCam + 0x190;
                        CDS_ASSERT(0x72, pCamBox_Flip);
                        *(unsigned char *)(pCamBox_Flip + 0x00) = 0;
                        *(float *)(pCamBox_Flip + 0x10) = m_unk1EC;
                        *(float *)(pCamBox_Flip + 0x14) = m_unk1F0;
                        *(float *)(pCamBox_Flip + 0x18) = m_unk1F4;
                        *(float *)(pCamBox_Flip + 0x20) = (float)(unsigned int)m_unk1E8 * 60.0f;
                        pCam->SetCamBoxData(2, pCamBox_Flip);
                        pCam->SetCamMode(4, false);
                    }
                    break;
                case 3:
                    pCam = (Camera *)(gEng + 0x19760);
                    CDS_ASSERT(0x84, pCam);
                    if (m_unk1EC == 0.0f) {
                        if (m_unk1F0 == 0.0f && m_unk1F4 == 0.0f) {
                            CDS_ASSERT(0x89, !"eif 0, 0, 0 error.  see keith or ted");
                        } else {
                            goto block48;
                        }
                    } else {
block48:
                        pCamBox_FixedLookAt = (char *)pCam + 0x1C0;
                        CDS_ASSERT(0x90, pCamBox_FixedLookAt);
                        *(unsigned char *)(pCamBox_FixedLookAt + 0x00) = 0;
                        *(float *)(pCamBox_FixedLookAt + 0x10) = m_unk1EC;
                        *(float *)(pCamBox_FixedLookAt + 0x14) = m_unk1F0;
                        *(float *)(pCamBox_FixedLookAt + 0x18) = m_unk1F4;
                        *(float *)(pCamBox_FixedLookAt + 0x38) = (float)(unsigned int)m_unk1E8 * 60.0f;
                        *(float *)(pCamBox_FixedLookAt + 0x40) = m_unk210;
                        *(unsigned char *)(pCamBox_FixedLookAt + 0x3C) = 0;
                        pCam->SetCamBoxData(3, pCamBox_FixedLookAt);
                        pCam->SetCamMode(4, false);
                    }
                    break;
                case 5:
                    pCam = (Camera *)(gEng + 0x19760);
                    CDS_ASSERT(0xA5, pCam);
                    pCamBoxRail = (char *)pCam + 0x220;
                    CDS_ASSERT(0xA8, pCamBoxRail);
                    *(unsigned char *)(pCamBoxRail + 0x00) = 0;
                    *(unsigned char *)(pCamBoxRail + 0x50) = 0;
                    *(float *)(pCamBoxRail + 0x10) = m_unk244;
                    *(float *)(pCamBoxRail + 0x14) = m_unk248;
                    *(float *)(pCamBoxRail + 0x18) = m_unk24C;
                    *(float *)(pCamBoxRail + 0x20) = m_unk25C;
                    *(float *)(pCamBoxRail + 0x24) = m_unk260;
                    *(float *)(pCamBoxRail + 0x28) = m_unk264;
                    *(short *)(pCamBoxRail + 0x02) = 0;
                    *(float *)(pCamBoxRail + 0x30) = m_unk214;
                    *(float *)(pCamBoxRail + 0x34) = m_unk218;
                    *(float *)(pCamBoxRail + 0x38) = m_unk21C;
                    *(int *)(pCamBoxRail + 0x3C) = 0x3F800000;
                    *(float *)(pCamBoxRail + 0x40) = m_unk22C;
                    *(float *)(pCamBoxRail + 0x44) = m_unk230;
                    *(float *)(pCamBoxRail + 0x48) = m_unk234;
                    *(int *)(pCamBoxRail + 0x4C) = 0x3F800000;
                    sceVu0UnitMatrix(sp50);
                    if (m_unk220) {
                        RotateX__5PMat4Ff(sp50, m_unk220);
                    }
                    if (m_unk224) {
                        RotateY__5PMat4Ff(sp50, m_unk224);
                    }
                    if (m_unk228) {
                        RotateZ__5PMat4Ff(sp50, m_unk228);
                    }
                    *(float *)(pCamBoxRail + 0x70) = -sp50[8];
                    *(float *)(pCamBoxRail + 0x74) = -sp50[9];
                    *(float *)(pCamBoxRail + 0x78) = -sp50[10];
                    *(int *)(pCamBoxRail + 0x7C) = 0x3F800000;
                    *(unsigned char *)(pCamBoxRail + 0x80) = (m_unk274 != 0);
                    *(float *)(pCamBoxRail + 0x54) = m_unk210;
                    {
                        int f81 = 0;
                        if (m_unk29C == 0) {
                            f81 = 1;
                        }
                        *(unsigned char *)(pCamBoxRail + 0x81) = f81;
                        *(unsigned char *)(pCamBoxRail + 0x82) = (m_unk2A0 == 0) ? 0 : 1;
                    }
                    pCam->SetCamBoxData(5, pCamBoxRail);
                    pCam->SetCamMode(4, false);
                    break;
                default:
                    CdsAssert("CamBox.cpp", 0xE4, "Illegal Camera BoxMode");
                    break;
                }
            }
        } else if (CAMBOX_PIT(pvPlayerPos, pvCamPos) == 0) {
            m_unk2A4 = 0;
            pCam->m_unk2BC = 0;
            if (m_unk208 != 0) {
                SetState(-2);
            }
        } else {
            if (m_unk1E0 != 1) {
                return;
            }
            pCam->SetCamBoxValue_FollowHeight(m_unk1E4);
        }
    }
}

// FUNCTION: 0x0019CEE0 __ct__6CamBoxFv
CamBox::CamBox() : EntityBaseClass((EntityBaseClass::LoadClass)4, 0) {
    EnableSleep(false, false);
    m_unk2A4 = 0;
}

// FUNCTION: 0x0019C7E0 OnSleepEvent__6CamBoxFv
void CamBox::OnSleepEvent() {
    Camera *pCam = (Camera *)(gEng + 0x19760);
    CDS_ASSERT(0x127, pCam);
    if (pCam->m_unk2BC != 0 && pCam->m_unk2BC == (int)this) {
        pCam->m_unk2BC = 0;
    }
}
