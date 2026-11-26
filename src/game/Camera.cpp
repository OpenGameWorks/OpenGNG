// FLAGS: -str readonly
#include "Camera.h"
#include "PMat4.h"
#include "MathAPI.h"
#include "pad.h"

// TODO(header): foreign declarations
extern "C" float FastMath_Fabs__Ff(float fValue);
extern Pad gPad;
extern "C" float atan2f(float y, float x);
extern "C" float Round180__Ff(float fAngle);
extern "C" float sceVu0InnerProduct(float *a, float *b);
extern "C" void __mi__5PVec3FR5PVec3(float *ret, float *lhs, float *rhs);
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern "C" float sqrtf(float x);
extern "C" int printf(const char *fmt, ...);
extern "C" void *__dt__12CameraFollowFv(void *pThis, short nFlag);
extern "C" void *__dt__16CameraCutManagerFv(void *pThis, short nFlag);
extern "C" void *__dt__11CameraDebugFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__ct__12CameraFollowFP6Camera(void *pThis, Camera *pCamera);
extern "C" void *__ct__16CameraCutManagerFP6Camera(void *pThis, Camera *pCamera);
extern "C" void *__ct__11CameraDebugFP6Camera(void *pThis, Camera *pCamera);
extern "C" void sceVu0UnitMatrix(float (*pMatrix)[4]);
extern "C" void InitFrustrum__6PWorldFP5PMat4PA4_f(void *pWorld, PMat4 *pMat, float (*pVec)[4]);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern unsigned char gEng[0x1A000];
extern float GAME_FPS;
extern char g_Stabdown_ShakeTable[0x60];
extern char g_Stabdown_ShakeTable_FixedCam[0x40];
extern char g_Stabdown2_ShakeTable[0x500];
extern "C" void sceVu0SubVector(float *dst, float *a, float *b);
extern "C" void sceVu0AddVector(float *dst, float *a, float *b);
extern "C" void sceVu0Normalize(float *dst, float *src);
extern "C" void sceVu0ScaleVector(float *dst, float *src, float s);
extern "C" void GetGroundPos__7PhysicsFv(float *pPos, void *pPhysics);
extern "C" void SetSourceAndTarget__12CameraFollowF5PVec35PVec3(void *pThis, PVec3 a, PVec3 b);

// Layout of the object at Camera::m_unk2B4 as UpdateFromCamBox reads it.
struct CamBoxState {
    unsigned int m_unk00;   // 0x00 init flag
    char _pad04[0x0C];
    float m_unk10[4];       // 0x10 target position
    float m_unk20[4];       // 0x20 source position; m_unk20[0] is a timer in case 2
    float m_unk30;          // 0x30 blend t
    float m_unk34;          // 0x34 blend step
    float m_unk38;          // 0x38 duration
    unsigned int m_unk3C;   // 0x3C
    float m_unk40[4];       // 0x40 goal position
    float m_unk50[4];       // 0x50 scratch vector; m_unk50[1] is the distance at 0x54
    char _pad60[0x70 - 0x60];
    float m_unk70;          // 0x70
    float m_unk74;          // 0x74
    float m_unk78;          // 0x78
    unsigned char m_unk80;  // 0x80
    unsigned char m_unk81;  // 0x81
    unsigned char m_unk82;  // 0x82
    char _pad83;
    float m_unk84;          // 0x84
};

class CVector3 {
public:
    float m_unk0;
    float m_unk4;
    float m_unk8;
};

class PVec3 {
public:
    float m_v[4];
};

class Debug {
public:
    void StartTimer(unsigned int arg0);
    void StopTimer(unsigned int arg0);
    char _pad000[0x10];
};

extern Debug gDebug;

class CameraCutManager {
public:
    void CleanUpCutCameras();
    int CutCameraExists(unsigned int arg0);
    void StartCutCamera(unsigned int arg0, bool arg1);
    void SetupCutCamera_Fixed(unsigned int arg0, unsigned int arg1, float arg2, float arg3, unsigned int arg4, PVec3 arg5, PVec3 arg6, unsigned int arg7, unsigned int arg8, unsigned int arg9, unsigned int arg10, bool arg11, PVec3 arg12, bool arg13, unsigned int arg14);
    void SetupCutCamera_MoveTo(unsigned int arg0, unsigned int arg1, float arg2, float arg3, unsigned int arg4, PVec3 arg5, PVec3 arg6, PVec3 arg7, unsigned int arg8, unsigned int arg9, unsigned int arg10, unsigned int arg11, bool arg12, PVec3 arg13, bool arg14, unsigned int arg15);
    void SetupCutCamera_Pan(unsigned int arg0, unsigned int arg1, float arg2, float arg3, PVec3 arg4, PVec3 arg5, PVec3 arg6, PVec3 arg7, unsigned int arg8, unsigned int arg9, unsigned int arg10, unsigned int arg11, bool arg12, PVec3 arg13, bool arg14, unsigned int arg15);
    void Update();

    char _pad000[0x85];
    unsigned char m_unk85;  // 0x085
};

class CameraFollow {
public:
    void ResetAfterReposition();
    void SetFollowCameraParams(float arg0, float arg1);
    void SetSourceAndTarget(PVec3 arg0, PVec3 arg1);
    void ModifyBossCamera(float arg0, float arg1, float arg2);
    void SetBossPosition(float (*arg0)[4]);
    void SetBossArenaValues(float (*arg0)[4], float arg1, float arg2, bool arg3, bool arg4, float arg5, float arg6, bool arg7);
    void Init(bool arg0);
    void SetCamBoxValue_FollowHeight(float arg0);
    void CamCollideCylinder(PVec3 arg0, float arg1, float arg2);
    void CamCollideSphere(PVec3 arg0, float arg1);
    int SetHeadCam(bool arg0);
    void DrawPolyDebug();
    void DrawTextDebug();
    void Update();
    void ResetFromCamBox();

    char _pad000[0x118];
    int m_unk118;           // 0x118
    int m_unk11C;           // 0x11C
    char _pad120[0x148 - 0x120];
    unsigned short m_unk148; // 0x148
    char _pad14A[0x178 - 0x14A];
    int m_unk178;           // 0x178 (float bits)
    char _pad17C[0x210 - 0x17C];
    int m_unk210;           // 0x210
    char _pad214[0x218 - 0x214];
    int m_unk218;           // 0x218
    char _pad21C[0x6318 - 0x21C];
    unsigned int m_unk6318; // 0x6318
};

class CameraDebug {
public:
    void DrawTextDebug();
    void Init(PVec3 arg0);
    void Update(bool arg0);
};

// DRAFT: 0x00177F80 ClosestPointOnLine__6CameraF8CVector38CVector38CVector3
// note: DIFF 153; frame 0x254 vs 0x270 and extra stack temporaries; the original copies each argument into locals before use and returns through the hidden pointer. Tried v1 (155), v2 (153, kept), v3 (156), v4 (164).
CVector3 Camera::ClosestPointOnLine(CVector3 arg0, CVector3 arg1, CVector3 arg2) {
    CVector3 start = arg0;
    CVector3 end = arg1;
    CVector3 pt = arg2;
    CVector3 base = start;
    CVector3 rel;
    CVector3 base2 = base;
    rel.m_unk0 = pt.m_unk0 - base.m_unk0;
    rel.m_unk4 = pt.m_unk4 - base.m_unk4;
    rel.m_unk8 = pt.m_unk8 - base.m_unk8;
    CVector3 dir;
    dir.m_unk0 = end.m_unk0 - base2.m_unk0;
    dir.m_unk4 = end.m_unk4 - base2.m_unk4;
    dir.m_unk8 = end.m_unk8 - base2.m_unk8;
    CVector3 n = Normalize(dir);
    float len = Distance(start, end);
    float t = Dot(n, rel);
    if (t <= 0.0f) {
        return start;
    }
    if (!(t < len)) {
        return end;
    }
    CVector3 scaled;
    scaled.m_unk0 = n.m_unk0 * t;
    scaled.m_unk4 = n.m_unk4 * t;
    scaled.m_unk8 = n.m_unk8 * t;
    CVector3 res;
    res.m_unk0 = scaled.m_unk0 + start.m_unk0;
    res.m_unk4 = scaled.m_unk4 + start.m_unk4;
    res.m_unk8 = scaled.m_unk8 + start.m_unk8;
    return res;
}

// FUNCTION: 0x001781F0 Distance__6CameraF8CVector38CVector3
float Camera::Distance(CVector3 arg0, CVector3 arg1) {
    return sqrtf((arg1.m_unk0 - arg0.m_unk0) * (arg1.m_unk0 - arg0.m_unk0) + (arg1.m_unk4 - arg0.m_unk4) * (arg1.m_unk4 - arg0.m_unk4) + (arg1.m_unk8 - arg0.m_unk8) * (arg1.m_unk8 - arg0.m_unk8));
}

// FUNCTION: 0x00178280 Dot__6CameraF8CVector38CVector3
float Camera::Dot(CVector3 arg0, CVector3 arg1) {
    return arg0.m_unk0 * arg1.m_unk0 + arg0.m_unk4 * arg1.m_unk4 + arg0.m_unk8 * arg1.m_unk8;
}

// DRAFT: 0x001782F0 Normalize__6CameraF8CVector3
// note: 21 differing lines; original keeps per-component load/div/store with v1=sp+0x24 and a0=sp+0x28 computed after the call, ours hoists loads and folds to sp+0x20; tried pointer-to-x/y/z, temp x, pointer-first, direct member variants.
CVector3 Camera::Normalize(CVector3 arg0) {
    CVector3 v = arg0;
    float m = Magnitude(v);
    v.m_unk0 /= m;
    v.m_unk4 /= m;
    v.m_unk8 /= m;
    return v;
}

// FUNCTION: 0x00178380 Magnitude__6CameraF8CVector3
float Camera::Magnitude(CVector3 arg0) {
    return sqrtf(arg0.m_unk0 * arg0.m_unk0 + arg0.m_unk4 * arg0.m_unk4 + arg0.m_unk8 * arg0.m_unk8);
}

// FUNCTION: 0x001783D0 GetEntityYOffset__6CameraFv
unsigned short Camera::GetEntityYOffset() {
    if (m_unkBC != 0) {
        return ((CameraFollow *)m_unkBC)->m_unk148;
    }
}

// FUNCTION: 0x001783F0 SetEntityYOffset__6CameraFUs
void Camera::SetEntityYOffset(unsigned short arg0) {
    CameraFollow *temp_v1 = (CameraFollow *)m_unkBC;
    if (temp_v1 != 0) {
        temp_v1->m_unk148 = arg0;
    }
}

// FUNCTION: 0x001788E0 SetSourceTarget__6CameraFPfPf
void Camera::SetSourceTarget(float *arg0, float *arg1) {
    sceVu0CopyVector(m_unk00, arg0);
    sceVu0CopyVector(m_unk10, arg1);
}

// FUNCTION: 0x00178410 PlayingCutCamera__6CameraFv
unsigned char Camera::PlayingCutCamera() {
    CameraCutManager *temp_v0 = (CameraCutManager *)m_unkC0;
    if (temp_v0 != 0) {
        return temp_v0->m_unk85;
    }
    return 0;
}

// FUNCTION: 0x00178430 RestoreFollowCamPos__6CameraFb
void Camera::RestoreFollowCamPos(bool arg0) {
    if (m_unkBC != 0) {
        if (arg0) {
            PVec3 sp10 = *(PVec3 *)m_unk2F0;
            PVec3 sp20 = *(PVec3 *)m_unk300;
            ((CameraFollow *)m_unkBC)->SetSourceAndTarget(sp10, sp20);
            return;
        }
        PVec3 sp30 = *(PVec3 *)m_unk00;
        PVec3 sp40 = *(PVec3 *)m_unk10;
        ((CameraFollow *)m_unkBC)->SetSourceAndTarget(sp30, sp40);
    }
}

// FUNCTION: 0x00178500 CleanUpCutCameras__6CameraFv
void Camera::CleanUpCutCameras() {
    CameraCutManager *temp_a0 = (CameraCutManager *)m_unkC0;
    if (temp_a0 != 0) {
        temp_a0->CleanUpCutCameras();
    }
}

// FUNCTION: 0x00178530 StartCutCamera__6CameraFUib
void Camera::StartCutCamera(unsigned int arg0, bool arg1) {
    CameraCutManager *temp_a0 = (CameraCutManager *)m_unkC0;
    if (temp_a0 != 0 && arg0 != -1U && temp_a0->m_unk85 == 0) {
        if (temp_a0->CutCameraExists(arg0) != 0) {
            ((CameraCutManager *)m_unkC0)->StartCutCamera(arg0, arg1);
            return;
        }
        char buf[0x100];
        sprintf(buf, "Cut camera with ID = %d doesn't exist\n", arg0);
        CdsAssert__FPciPc("Camera.cpp", 0x51B, buf);
    }
}

// DRAFT: 0x001785E0 SetupCutCamera_Pan__6CameraFUiUiff5PVec35PVec35PVec35PVec3UiUiUiUib5PVec3bUi
// note: DIFF 71; same failure as MoveTo: the PVec3 copies to stack temps are hoisted above the m_unkC0 check (original copies inside it). Tried: forwarding call inside the if (71); cached cut pointer with early return (71).
void Camera::SetupCutCamera_Pan(unsigned int arg0, unsigned int arg1, float arg2, float arg3, PVec3 arg4, PVec3 arg5, PVec3 arg6, PVec3 arg7, unsigned int arg8, unsigned int arg9, unsigned int arg10, unsigned int arg11, bool arg12, PVec3 arg13, bool arg14, unsigned int arg15) {
    CameraCutManager *cut = (CameraCutManager *)m_unkC0;
    if (cut == 0) {
        return;
    }
    cut->SetupCutCamera_Pan(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15);
}

// DRAFT: 0x00178710 SetupCutCamera_MoveTo__6CameraFUiUiffUi5PVec35PVec35PVec3UiUiUiUib5PVec3bUi
// note: DIFF 61; original copies the four PVec3 args inside the m_unkC0 check, ours hoists the copies above it (frame 0x90 matches). Tried: direct pass, locals before/inside the if, call-site PVec3 temporaries (107), cached cut pointer (61).
void Camera::SetupCutCamera_MoveTo(unsigned int arg0, unsigned int arg1, float arg2, float arg3, unsigned int arg4, PVec3 arg5, PVec3 arg6, PVec3 arg7, unsigned int arg8, unsigned int arg9, unsigned int arg10, unsigned int arg11, bool arg12, PVec3 arg13, bool arg14, unsigned int arg15) {
    if (m_unkC0 != 0) {
        ((CameraCutManager *)m_unkC0)->SetupCutCamera_MoveTo(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, arg15);
    }
}

// DRAFT: 0x00178810 SetupCutCamera_Fixed__6CameraFUiUiffUi5PVec35PVec3UiUiUiUib5PVec3bUi
// note: 49 differing words; original checks m_unkC0 before copying the PVec3 args to stack temps (copies inside the if), ours hoists the copies above the check; also register choice for t0/t1 differs. Tried: early return, local pointer check.
void Camera::SetupCutCamera_Fixed(unsigned int arg0, unsigned int arg1, float arg2, float arg3, unsigned int arg4, PVec3 arg5, PVec3 arg6, unsigned int arg7, unsigned int arg8, unsigned int arg9, unsigned int arg10, bool arg11, PVec3 arg12, bool arg13, unsigned int arg14) {
    if (m_unkC0 != 0) {
        ((CameraCutManager *)m_unkC0)->SetupCutCamera_Fixed(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14);
    }
}

// FUNCTION: 0x00178920 ControlledByApp__6CameraFUi
int Camera::ControlledByApp(unsigned int arg0) {
    return (arg0 == m_unk2E4) ? 1 : 0;
}

// FUNCTION: 0x00178940 SetControlled__6CameraFUib
int Camera::SetControlled(unsigned int arg0, bool arg1) {
    if (m_unk2E4 == 0 || arg0 == 0) {
        m_unk2E4 = arg0;
        m_unk2B8 = (arg1 && m_unk2E4 != 0) ? 1 : 0;
        return 1;
    }
    return 0;
}

// FUNCTION: 0x00178990 ResetAfterReposition__6CameraFv
void Camera::ResetAfterReposition() {
    CameraFollow *temp_a0 = (CameraFollow *)m_unkBC;
    if (temp_a0 != 0) {
        temp_a0->ResetAfterReposition();
    }
}

// FUNCTION: 0x001789C0 FollowCamInBossMode__6CameraFv
int Camera::FollowCamInBossMode() {
    CameraFollow *temp_v0 = (CameraFollow *)m_unkBC;
    if (temp_v0 != 0) {
        return (temp_v0->m_unk6318 != 0) ? 1 : 0;
    }
    return 0;
}

// FUNCTION: 0x001789F0 SetPosAndRot__6CameraFPA4_fPA4_f
void Camera::SetPosAndRot(float (*arg0)[4], float (*arg1)[4]) {
    *(u_long128 *)m_unk00 = *(u_long128 *)arg0;
    *(u_long128 *)m_unk20 = *(u_long128 *)arg1;
}

// FUNCTION: 0x00178A10 SetFollowCameraParams__6CameraFff
void Camera::SetFollowCameraParams(float arg0, float arg1) {
    CameraFollow *temp_a0 = (CameraFollow *)m_unkBC;
    if (temp_a0 != 0) {
        temp_a0->SetFollowCameraParams(arg0, arg1);
    }
}

// FUNCTION: 0x00178A40 ModifyBossCamera__6CameraFfff
void Camera::ModifyBossCamera(float arg0, float arg1, float arg2) {
    CameraFollow *temp_a0 = (CameraFollow *)m_unkBC;
    if (temp_a0 != 0) {
        temp_a0->ModifyBossCamera(arg0, arg1, arg2);
    }
}

// FUNCTION: 0x00178A70 SetBossPosition__6CameraFPA4_f
void Camera::SetBossPosition(float (*arg0)[4]) {
    CameraFollow *temp_a0 = (CameraFollow *)m_unkBC;
    if (temp_a0 != 0) {
        temp_a0->SetBossPosition(arg0);
    }
}

// FUNCTION: 0x00178AA0 SetBossArenaValues__6CameraFPA4_fffbbffb
void Camera::SetBossArenaValues(float (*arg0)[4], float arg1, float arg2, bool arg3, bool arg4, float arg5, float arg6, bool arg7) {
    CameraFollow *temp_a0 = (CameraFollow *)m_unkBC;
    if (temp_a0 != 0) {
        temp_a0->SetBossArenaValues(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    }
}

// FUNCTION: 0x00178AD0 SetCamBoxData__6CameraFiPv
void Camera::SetCamBoxData(int arg0, void *arg1) {
    switch (arg0) {
    case 2:
        m_unk2B0 = 2;
        m_unk2B4 = arg1;
        break;
    case 3:
        m_unk2B0 = 3;
        m_unk2B4 = arg1;
        break;
    case 5:
        m_unk2B0 = 5;
        m_unk2B4 = arg1;
        break;
    }
}

// DRAFT: 0x00178B30 UpdateFromCamBox__6CameraFv
// note: rebuilt by hand from the m2c draft; case 5 ring average, ground offset and ClosestPointOnLine blend are omitted, and the CheckCameraShake arguments are a guess, so the size and instruction order differ.
int Camera::UpdateFromCamBox() {
    PVec3 sp150;
    PVec3 sp160;
    PVec3 sp170;
    PVec3 sp180;
    float spE0[4];
    float spF0[4];
    float sp90[4];
    float spA0[4];
    float spB0[4];
    CamBoxState *pBox;
    char *pPlayer;
    char *pTarget;
    float t;
    int ret;
    int i;

    if (m_unk2B0 != 2 && m_unk2BC == 0) {
        return 1;
    }
    pPlayer = *(char **)&gEng[0x1883C];
    ((pPlayer != 0) ? (void)0 : CdsAssert__FPciPc("Camera.cpp", 0x2D0, "pPlayer"));
    pTarget = pPlayer + 0x190;
    if (*(char **)(pPlayer + 0x3C) != 0) {
        pTarget = *(char **)(pPlayer + 0x3C) + 0x80;
    }
    ret = 0;
    switch (m_unk2B0) {
    case 2:
        pBox = (CamBoxState *)m_unk2B4;
        if (pBox->m_unk00 == 0) {
            m_unkD0 = 0;
            pBox->m_unk00 = 1;
        }
        if (!(pBox->m_unk20[0] <= 0.0f)) {
            m_unk2B8 = 1;
            pBox->m_unk20[0] = pBox->m_unk20[0] - *(float *)&gEng[0x1E8];
            m_unk00[0] = pBox->m_unk10[0];
            m_unk00[1] = pBox->m_unk10[1];
            m_unk00[2] = pBox->m_unk10[2];
            sceVu0CopyVector(m_unk10, (float *)pTarget);
            m_unk10[1] += 5.0f;
        } else {
            m_unk2B8 = 0;
            sp150 = *(PVec3 *)m_unk00;
            sp160 = *(PVec3 *)m_unk10;
            SetSourceAndTarget__12CameraFollowF5PVec35PVec3(m_unkBC, sp150, sp160);
        }
        break;
    case 3:
        pBox = (CamBoxState *)m_unk2B4;
        if (pBox->m_unk00 == 0) {
            sceVu0CopyVector(pBox->m_unk20, m_unk00);
            pBox->m_unk30 = 0.0f;
            if (pBox->m_unk38 != 0.0f) {
                pBox->m_unk34 = 1.0f / pBox->m_unk38;
            } else {
                pBox->m_unk34 = 1.0f;
            }
            if (pBox->m_unk40[0] != 0.0f) {
                pBox->m_unk3C = 1;
            }
            pBox->m_unk00 = 1;
        }
        pBox->m_unk30 = pBox->m_unk30 + pBox->m_unk34;
        if (!(pBox->m_unk30 <= 1.0f)) {
            pBox->m_unk30 = 1.0f;
        }
        m_unk00[0] = pBox->m_unk20[0] + pBox->m_unk30 * (pBox->m_unk10[0] - pBox->m_unk20[0]);
        m_unk00[1] = pBox->m_unk20[1] + pBox->m_unk30 * (pBox->m_unk10[1] - pBox->m_unk20[1]);
        m_unk00[2] = pBox->m_unk20[2] + pBox->m_unk30 * (pBox->m_unk10[2] - pBox->m_unk20[2]);
        sceVu0CopyVector(spE0, m_unk10);
        sceVu0CopyVector(spF0, (float *)pTarget);
        spF0[1] += 5.0f;
        m_unk10[0] = spE0[0] + 0.1f * (spF0[0] - spE0[0]);
        m_unk10[1] = spE0[1] + 0.1f * (spF0[1] - spE0[1]);
        m_unk10[2] = spE0[2] + 0.1f * (spF0[2] - spE0[2]);
        if (pBox->m_unk3C != 0) {
            if (pBox->m_unk30 <= 1.0f) {
                sceVu0SubVector(pBox->m_unk50, m_unk00, m_unk10);
            } else {
                sceVu0SubVector(pBox->m_unk50, pBox->m_unk10, m_unk10);
            }
            sceVu0Normalize(sp90, pBox->m_unk50);
            sceVu0SubVector(spA0, m_unk10, m_unk00);
            t = sqrtf(spA0[0] * spA0[0] + spA0[1] * spA0[1] + spA0[2] * spA0[2]);
            if (t != pBox->m_unk40[0]) {
                float s = t + 0.1f * (pBox->m_unk40[0] - t);
                sceVu0ScaleVector(spB0, sp90, s);
                m_unk00[0] = m_unk10[0] + spB0[0];
                m_unk00[2] = m_unk10[2] + spB0[2];
            }
        }
        ret = 0;
        break;
    case 5:
        pBox = (CamBoxState *)m_unk2B4;
        if (pBox->m_unk00 == 0) {
            for (i = 0; i < 20; i++) {
                m_unkD4[i] = 0;
            }
            m_unk2C8 = 20;
            pBox->m_unk84 = 0.001f;
            pBox->m_unk00 = 1;
        }
        sceVu0CopyVector(spE0, m_unk10);
        sceVu0CopyVector(spF0, (float *)pTarget);
        if (pBox->m_unk84 > 0.1f) {
            pBox->m_unk84 = 0.1f;
        }
        m_unk10[0] = spE0[0] + pBox->m_unk84 * (spF0[0] - spE0[0]);
        m_unk10[1] = spE0[1] + pBox->m_unk84 * (spF0[1] - spE0[1]);
        m_unk10[2] = spE0[2] + pBox->m_unk84 * (spF0[2] - spE0[2]);
        ret = 0;
        break;
    default:
        CdsAssert__FPciPc("Camera.cpp", 0x41F, "0");
        break;
    }
    sp150 = *(PVec3 *)m_unk00;
    sp160 = *(PVec3 *)m_unk10;
    CheckCameraShake(sp150, sp160, false);
    CreateViewMatrix(*(PMat4 *)m_unk30, sp150, sp160);
    if (m_unk2B0 == 3 || m_unk2B0 == 5) {
        if (m_unkBC != 0) {
            sp170 = *(PVec3 *)m_unk00;
            sp180 = *(PVec3 *)m_unk10;
            SetSourceAndTarget__12CameraFollowF5PVec35PVec3(m_unkBC, sp170, sp180);
        }
    }
    return ret;
}

// FUNCTION: 0x00179810 RestoreCamBox__6CameraFv
void Camera::RestoreCamBox() {
    if (m_unkB4 != 4) {
        return;
    }
    switch (m_unk2B0) {
    case 3:
        *(float *)((char *)m_unk2B4 + 0x30) = 1.0f;
        void *temp_v0 = *(void **)&gEng[0x1883C];
        void *temp_v1 = *(void **)((char *)temp_v0 + 0x3C);
        char *var_a1 = (char *)temp_v0 + 0x190;
        if (temp_v1 != 0) {
            var_a1 = (char *)temp_v1 + 0x80;
        }
        sceVu0CopyVector(m_unk10, (float *)var_a1);
        m_unk10[1] += 5.0f;
        break;
    }
}

// FUNCTION: 0x001798A0 UpdateFromApparition__6CameraFv
void Camera::UpdateFromApparition() {
    PVec3 sp20;
    PVec3 sp30;

    CheckCameraShake(*(PVec3 *)this, *(PVec3 *)&m_unk10, false);
    sp20 = *(PVec3 *)m_unk00;
    sp30 = *(PVec3 *)m_unk10;
    CreateViewMatrix(*(PMat4 *)m_unk30, sp20, sp30);
}

// DRAFT: 0x00179930 SetupShakeScreen__6CameraFfffiiUi
// note: 24 diff lines; original keeps idx*4 in a0 and does addiu/addu/lw(0) without folding the 0x17C displacement, and its bne skip is one insn longer. Tried: m_unk17C[idx], explicit pointer, idx*4 local, this+0x17C base, typed int* base (24), arg3 test (44).
void Camera::SetupShakeScreen(float arg0, float arg1, float arg2, int arg3, int arg4, unsigned int arg5) {
    int idx = arg4;
    m_unk179 = 1;
    m_unk170 = 0;
    m_unk148 = arg3;
    if (m_unk148 == 1) {
        if (idx >= 3) {
            CdsAssert__FPciPc("Camera.cpp", 0x289, "iTableIdx < CAMERA_SHAKE_TABLE_MAX");
        }
        int *base = (int *)((char *)this + 0x17C);
        m_unk14C = base[idx];
    } else {
        m_unk14C = 0;
    }
    m_unk158 = arg0 * GAME_FPS;
    m_unk15C = arg1 * GAME_FPS;
    m_unk174 = arg2;
}

struct CameraShakeEntry {
    float m_x;   // +0x0
    float m_y;   // +0x4
    float m_z;   // +0x8
    float m_div; // +0xC
    float m_mul; // +0x10
};

// FUNCTION: 0x00179A00 ShakeScreenTable__6CameraFR5PVec3R5PVec3b
int Camera::ShakeScreenTable(PVec3 &arg0, PVec3 &arg1, bool arg2) {
    if (m_unk14C == 0) {
        CdsAssert__FPciPc("Camera.cpp", 0x242, "m_pCurrentShakeTable");
    }
    if (m_unk128 != 0) {
        CameraShakeEntry *pEntry = (CameraShakeEntry *)m_unk14C + m_unk144;
        m_unk130 = (pEntry->m_x * pEntry->m_mul) / pEntry->m_div;
        m_unk134 = (pEntry->m_y * pEntry->m_mul) / pEntry->m_div;
        m_unk138 = (pEntry->m_z * pEntry->m_mul) / pEntry->m_div;
        m_unk140 = pEntry->m_div;
        m_unk128 = 0;
    }
    float fTime = m_unk140;
    if (fTime > 0.0f) {
        float fScale = 1.0f;
        m_unk140 = fTime - 1.0f;
        if (arg2) {
            fScale = 0.5f;
        }
        arg0.m_v[0] += m_unk130 * fScale;
        arg0.m_v[1] += m_unk134 * fScale;
        arg0.m_v[2] += m_unk138 * fScale;
        arg1.m_v[0] += m_unk130 * fScale;
        arg1.m_v[1] += m_unk134 * fScale;
        arg1.m_v[2] += m_unk138 * fScale;
    } else {
        m_unk144 += 1;
        CameraShakeEntry *pNext = (CameraShakeEntry *)m_unk14C + m_unk144;
        if (pNext->m_x == 0.0f && pNext->m_y == 0.0f && pNext->m_z == 0.0f) {
            return 1;
        }
        m_unk128 = 1;
    }
    return 0;
}

// DRAFT: 0x00179C10 ShakeScreen__6CameraFR5PVec3R5PVec3b
// note: DIFF 155; the fFrameDelay test polarity is fixed (> 0 takes -=), but the static is gp-relative in ours (-0x7BC8) vs 0x0($gp) in the original, constants load into v1 not v0, the case-0 branch layout differs, and the SetVibrate relocation is missing.
bool Camera::ShakeScreen(PVec3 &arg0, PVec3 &arg1, bool arg2) {
    static float fFrameDelay;

    if (m_unk170 != 0) {
        switch (m_unk148) {
        case 0:
            if (fFrameDelay > 0.0f) {
                fFrameDelay -= 60.0f / GAME_FPS;
                return 0;
            }
            fFrameDelay += 2.0f;
            if (m_unk154 > 0.0f) {
                m_unk154 -= 1.0f;
            }
            if (m_unk178 != 0) {
                float t = m_unk154 / m_unk15C;
                m_unk160 = MathAPI::RandomFloatRange(0.0f, 0.2f) * m_unk174 * t;
                m_unk168 = MathAPI::RandomFloatRange(0.0f, 0.2f) * m_unk174 * t;
                m_unk178 = 0;
            } else {
                float v;
                m_unk178 = 1;
                v = -m_unk160;
                if (m_unk160 < 0.0f) {
                    v = FastMath_Fabs__Ff(m_unk160);
                }
                m_unk160 = v;
                v = -m_unk168;
                if (m_unk168 < 0.0f) {
                    v = FastMath_Fabs__Ff(m_unk168);
                }
                m_unk168 = v;
            }
            arg0.m_v[0] += m_unk160;
            arg0.m_v[2] += m_unk168;
            arg1.m_v[0] += m_unk160;
            arg1.m_v[2] += m_unk168;
            return 0;
        case 1:
            if (ShakeScreenTable(arg0, arg1, arg2) != 0) {
                return 1;
            }
            return 0;
        }
    } else {
        switch (m_unk148) {
        case 0:
            if (m_unk158 > 0.0f) {
                m_unk158 -= 1.0f;
            } else {
                fFrameDelay = 2.0f;
                m_unk178 = 1;
                m_unk15C = m_unk15C / 2.0f;
                m_unk154 = m_unk15C;
                m_unk170 = 1;
                gPad.SetVibrate((Pad::VibType)1, (unsigned char)(int)m_unk15C);
            }
            break;
        case 1:
            m_unk128 = 1;
            m_unk144 = 0;
            m_unk170 = 1;
            m_unk15C = 0.5f * GAME_FPS / 2.0f;
            gPad.SetVibrate((Pad::VibType)1, (unsigned char)(int)m_unk15C);
            break;
        }
    }
    return 0;
}

// FUNCTION: 0x00179F20 CheckCameraShake__6CameraFR5PVec3R5PVec3b
void Camera::CheckCameraShake(PVec3 &arg0, PVec3 &arg1, bool arg2) {
    if (m_unk179 != 0) {
        if (ShakeScreen(arg0, arg1, arg2)) {
            m_unk179 = 0;
        }
    }
}

// FUNCTION: 0x00179F60 SetCamMode__6CameraFsb
void Camera::SetCamMode(short arg0, bool arg1) {
    if (!arg1) {
        m_unkB4 = arg0;
        if (m_unkB4 == 0) {
            CameraFollow *follow = (CameraFollow *)m_unkBC;
            follow->m_unk11C = follow->m_unk118;
            follow->m_unk118 = arg0;
        }
        ((CameraFollow *)m_unkBC)->m_unk218 = 5;
        return;
    }
    m_unkC8 = 0;
    m_unkB8 = arg0;
    switch (m_unkB8) {
    case 0:
        m_unkB4 = 0;
        ((CameraFollow *)m_unkBC)->m_unk178 = 0x41200000;
        return;
    case 1: {
        m_unkB4 = 3;
        PVec3 tmp = *(PVec3 *)m_unk00;
        ((CameraDebug *)m_unkC4)->Init(tmp);
        return;
    }
    case 2:
        m_unkB4 = 0;
        m_unkC8 = 1;
        return;
    case 3:
        m_unkB4 = 0;
        return;
    default:
        CdsAssert__FPciPc("Camera.cpp", 0x19B, "0");
    }
}

// DRAFT: 0x0017A070 CamCollideCylinder__6CameraF5PVec3ff
// note: 18 differing words; original keeps the copied PVec3 address in v0 and has no null recheck before the reload of m_unkBC; ours uses v1 and adds a recheck. Tried a temp local and direct m_unkBC access. Non-POD PVec3 (user ctor) matches this but shifts three other FUNCTIONs in this file, so it is reverted. A non-POD PVec3 with an inline `PVec3(const PVec3 &o) { *this = o; }` matches both CamCollide functions and SetCamMode, but UpdateFromApparition (18) and RestoreFollowCamPos (51) then copy their by-value arguments right-to-left where the original goes left-to-right.
void Camera::CamCollideCylinder(PVec3 arg0, float arg1, float arg2) {
    if (m_unkBC != 0) {
        ((CameraFollow *)m_unkBC)->CamCollideCylinder(arg0, arg1, arg2);
    }
}

// DRAFT: 0x0017A0C0 CamCollideSphere__6CameraF5PVec3f
// note: 18 differing lines; ours copies the PVec3 param to sp+0x10 at entry and again before the call, original copies once after the null test. Tried plain if, local copy in the if (frame 0x30), early return (copy hoisted, second null test); plain if is the closest. Non-POD PVec3 (user ctor) matches this but shifts three other FUNCTIONs in this file, so it is reverted. A non-POD PVec3 with an inline `PVec3(const PVec3 &o) { *this = o; }` matches both CamCollide functions and SetCamMode, but UpdateFromApparition (18) and RestoreFollowCamPos (51) then copy their by-value arguments right-to-left where the original goes left-to-right.
void Camera::CamCollideSphere(PVec3 arg0, float arg1) {
    if (m_unkBC != 0) {
        ((CameraFollow *)m_unkBC)->CamCollideSphere(arg0, arg1);
    }
}

// FUNCTION: 0x0017A110 PlayerInFixedCamBox__6CameraFv
bool Camera::PlayerInFixedCamBox() {
    if (m_unkB4 == 4) {
        switch (m_unk2B0) {
        case 2:
        case 3:
        case 5:
            return true;
        }
    }
    return false;
}

// FUNCTION: 0x0017A170 ResetCamBoxCount__6CameraFv
void Camera::ResetCamBoxCount() {
    if (m_unkBC != 0) {
        ((CameraFollow *)m_unkBC)->m_unk210 = 0;
    }
}

// DRAFT: 0x0017A190 SetCamBoxValue_FollowHeight__6CameraFf
// note: 27 differing words; original keeps this in s1 and the 3.0 double in s0 across the fptodp call (constant built before the call); ours evaluates the (double)arg0 call first and rebuilds 3.0 after it. Also tried: split double local before the cast, assign inside the guard, implicit float promotion; all 27.
void Camera::SetCamBoxValue_FollowHeight(float arg0) {
    double min = 3.0;
    if (m_unkBC != 0) {
        if (arg0 < 3.0f) {
            printf("(Camera Error) Camera height box cannot be less that %f above ground. Value passed = %f\n", min, (double)arg0);
        }
        ((CameraFollow *)m_unkBC)->SetCamBoxValue_FollowHeight(arg0);
    }
}

// FUNCTION: 0x0017A210 GetForwardVector__6CameraFRA4_f
void Camera::GetForwardVector(float (&arg0)[4]) {
    arg0[0] = m_unk30[0][2];
    arg0[1] = m_unk30[1][2];
    arg0[2] = m_unk30[2][2];
}

// FUNCTION: 0x0017A230 SetHeadCam__6CameraFb
int Camera::SetHeadCam(bool arg0) {
    if (m_unkB4 == 0) {
        CameraFollow *temp_a0 = (CameraFollow *)m_unkBC;
        if (temp_a0 != 0) {
            int flag = (temp_a0->m_unk6318 != 0) ? 1 : 0;
            if (flag != 0) {
                return 0;
            }
            return temp_a0->SetHeadCam(arg0);
        }
    }
    return 0;
}

// FUNCTION: 0x0017A280 PolyDebug__6CameraFv
void Camera::PolyDebug() {
    switch (m_unkB4) {
    case 0:
        if (m_unkB0 != 0) {
            ((CameraFollow *)m_unkBC)->DrawPolyDebug();
        }
        break;
    }
}

// FUNCTION: 0x0017A2C0 TextDebug__6CameraFv
void Camera::TextDebug() {
    if (m_unkC8 != 0 || m_unkB4 == 3) {
        switch (m_unkB4) {
        case 0:
            ((CameraFollow *)m_unkBC)->DrawTextDebug();
            return;
        case 3:
            ((CameraDebug *)m_unkC4)->DrawTextDebug();
            break;
        }
    }
}

// DRAFT: 0x0017A330 CreateViewMatrix__6CameraFR5PMat45PVec35PVec3
// note: DIFF 130; CW copies the by-value PVec3 args (arg1, arg2) into the frame at entry, original forwards $a2/$a3 with no copy; frame 0xB0 vs 0xA0, sd ra at 0x30 vs 0x40. Tried local pointer aliases (still 130).
void Camera::CreateViewMatrix(PMat4 &arg0, PVec3 arg1, PVec3 arg2) {
    float tmp[4];
    float d[4];
    float col0[4];
    float col1[4];
    float col2[4];

    __mi__5PVec3FR5PVec3(tmp, arg2.m_v, arg1.m_v);
    *(u_long128 *)d = *(u_long128 *)tmp;
    m_unk20[0] = 57.295776f * atan2f(-d[1], sqrtf(d[2] * d[2] + d[0] * d[0]));
    m_unk20[0] = Round180__Ff(m_unk20[0] + 180.0f);
    m_unk20[1] = 57.295776f * atan2f(d[0], -d[2]);
    m_unk20[1] = Round180__Ff(m_unk20[1]);
    m_unk20[2] = *(float *)&m_unkD0;
    m_unk20[2] = Round180__Ff(m_unk20[2]);
    sceVu0UnitMatrix(arg0.m_unk00);
    arg0.RotateY(m_unk20[1]);
    arg0.RotateX(m_unk20[0]);
    arg0.RotateZ(m_unk20[2]);
    col0[0] = arg0.m_unk00[0][0];
    col0[1] = arg0.m_unk00[1][0];
    col0[2] = arg0.m_unk00[2][0];
    col0[3] = 1.0f;
    col1[0] = arg0.m_unk00[0][1];
    col1[1] = arg0.m_unk00[1][1];
    col1[2] = arg0.m_unk00[2][1];
    col1[3] = 1.0f;
    col2[0] = arg0.m_unk00[0][2];
    col2[1] = arg0.m_unk00[1][2];
    col2[2] = arg0.m_unk00[2][2];
    col2[3] = 1.0f;
    arg0.m_unk00[3][0] = -sceVu0InnerProduct(col0, arg1.m_v);
    arg0.m_unk00[3][1] = -sceVu0InnerProduct(col1, arg1.m_v);
    arg0.m_unk00[3][2] = -sceVu0InnerProduct(col2, arg1.m_v);
    m_unk20[1] = Round180__Ff(57.295776f * atan2f(-arg0.m_unk00[0][2], -arg0.m_unk00[2][2]));
}

// FUNCTION: 0x0017A530 Update__6CameraFv
void Camera::Update() {
    gDebug.StartTimer(4);
    if (!((unsigned int)m_unkB4 < 5)) {
        CdsAssert__FPciPc("Camera.cpp", 0x5C, "m_iCameraMode < MAX_MODE");
    }
    switch (m_unkB4) {
    case 0:
        if (m_unkB0 != 0) {
            if (m_unk2E4 != 0) {
                UpdateFromApparition();
            } else {
                ((CameraFollow *)m_unkBC)->Update();
            }
        } else {
            char *pMgr = (char *)gEng + 0x137E0;
            if (pMgr == 0) {
                CdsAssert__FPciPc("Camera.cpp", 0x72, "pEntityMgr");
            }
            char *pPlayer = *(char **)(pMgr + 0x505C);
            if (pPlayer == 0) {
                CdsAssert__FPciPc("Camera.cpp", 0x75, "pPlayer");
            }
            if (*(int *)(pPlayer + 0x3C) != 0) {
                if (m_unkCC == 0) {
                    m_unkB0 = 1;
                    ((CameraFollow *)m_unkBC)->Init(false);
                } else {
                    m_unkCC--;
                }
            }
        }
        break;
    case 4:
        if (m_unk2E4 != 0) {
            UpdateFromApparition();
        } else if (UpdateFromCamBox() != 0) {
            ((CameraFollow *)m_unkBC)->ResetFromCamBox();
            m_unkB4 = 0;
        }
        break;
    case 1:
        ((CameraCutManager *)m_unkC0)->Update();
        break;
    case 3:
        ((CameraDebug *)m_unkC4)->Update(false);
        break;
    case 2:
        ((CameraDebug *)m_unkC4)->Update(true);
        break;
    }
    InitFrustrum__6PWorldFP5PMat4PA4_f((void *)gEng, (PMat4 *)m_unk30, (float (*)[4])this);
    gDebug.StopTimer(4);
}

// FUNCTION: 0x0017A710 __dt__6CameraFv
extern "C" Camera *__dt__6CameraFv(Camera *pThis, short nFlag) {
    if (pThis != 0) {
        __dt__12CameraFollowFv(pThis->m_unkBC, 1);
        __dt__16CameraCutManagerFv(pThis->m_unkC0, 1);
        __dt__11CameraDebugFv(pThis->m_unkC4, 1);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x0017A780 ResetFollowCamera__6CameraFv
void Camera::ResetFollowCamera() {
    if (m_unkBC != 0) {
        m_unkB4 = 0;
        ((CameraFollow *)m_unkBC)->Init(false);
    }
}

// DRAFT: 0x0017A7B0 Init__6CameraFv
// note: DIFF 36; zero loop differs (original keeps byte-offset a1 with 8-wide unroll); tried index, pointer, do-while, while, unrolled, end-pointer forms (36-48).
void Camera::Init() {
    int i;
    int *p;

    m_unkB4 = 0;
    m_unkB1 = 1;
    m_unkB0 = 0;
    m_unkC8 = 0;
    m_unkB8 = m_unkB4;
    m_unkCC = 0;
    m_unkD0 = 0;
    m_unk2B0 = 0;
    m_unk2B8 = 0;
    m_unk2BC = 0;
    m_unk2E4 = 0;
    m_unk124 = 0;
    m_unk2C0 = 0;
    m_unk179 = 0;
    p = m_unkD4;
    i = 0;
    do {
        *p++ = 0;
        i++;
    } while (i < 20);
    m_unk17C[0] = (int)g_Stabdown_ShakeTable;
    m_unk17C[1] = (int)g_Stabdown_ShakeTable_FixedCam;
    m_unk17C[2] = (int)g_Stabdown2_ShakeTable;
    CleanUpCutCameras();
}

// FUNCTION: 0x0017A880 __ct__6CameraFv
extern "C" Camera *__ct__6CameraFv(Camera *volatile pThis)
{
    sceVu0UnitMatrix(pThis->m_unk30);
    sceVu0UnitMatrix(pThis->m_unk70);
    void *pm_unkBC = __nw__FUi(0x64A0);
    if (pm_unkBC != 0) {
        pm_unkBC = __ct__12CameraFollowFP6Camera(pm_unkBC, pThis);
    }
    pThis->m_unkBC = pm_unkBC;
    if (pThis->m_unkBC == 0) {
        CdsAssert__FPciPc("Camera.cpp", 0x18, "m_pFollowCam");
    }
    void *pm_unkC0 = __nw__FUi(0xD0);
    if (pm_unkC0 != 0) {
        pm_unkC0 = __ct__16CameraCutManagerFP6Camera(pm_unkC0, pThis);
    }
    pThis->m_unkC0 = pm_unkC0;
    if (pThis->m_unkC0 == 0) {
        CdsAssert__FPciPc("Camera.cpp", 0x1B, "m_pCutManager");
    }
    void *pm_unkC4 = __nw__FUi(0x250);
    if (pm_unkC4 != 0) {
        pm_unkC4 = __ct__11CameraDebugFP6Camera(pm_unkC4, pThis);
    }
    pThis->m_unkC4 = pm_unkC4;
    if (pThis->m_unkC4 == 0) {
        CdsAssert__FPciPc("Camera.cpp", 0x1E, "m_pDebugCam");
    }
    return pThis;
}
