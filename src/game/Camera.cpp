// FLAGS: -str readonly
#include "Camera.h"

// TODO(header): foreign declarations
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
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern unsigned char gEng[0x1A000];
extern float GAME_FPS;
extern char g_Stabdown_ShakeTable[0x60];
extern char g_Stabdown_ShakeTable_FixedCam[0x40];
extern char g_Stabdown2_ShakeTable[0x500];

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

class CameraCutManager {
public:
    void CleanUpCutCameras();
    int CutCameraExists(unsigned int arg0);
    void StartCutCamera(unsigned int arg0, bool arg1);
    void SetupCutCamera_Fixed(unsigned int arg0, unsigned int arg1, float arg2, float arg3, unsigned int arg4, PVec3 arg5, PVec3 arg6, unsigned int arg7, unsigned int arg8, unsigned int arg9, unsigned int arg10, bool arg11, PVec3 arg12, bool arg13, unsigned int arg14);
    void SetupCutCamera_MoveTo(unsigned int arg0, unsigned int arg1, float arg2, float arg3, unsigned int arg4, PVec3 arg5, PVec3 arg6, PVec3 arg7, unsigned int arg8, unsigned int arg9, unsigned int arg10, unsigned int arg11, bool arg12, PVec3 arg13, bool arg14, unsigned int arg15);

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

    char _pad000[0x118];
    int m_unk118;           // 0x118
    int m_unk11C;           // 0x11C
    char _pad120[0x178 - 0x120];
    int m_unk178;           // 0x178 (float bits)
    char _pad17C[0x218 - 0x17C];
    int m_unk218;           // 0x218
    char _pad21C[0x6318 - 0x21C];
    unsigned int m_unk6318; // 0x6318
};

class CameraDebug {
public:
    void DrawTextDebug();
    void Init(PVec3 arg0);
};

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

// DRAFT: 0x00178940 SetControlled__6CameraFUib
// note: 12 differing lines; branch layout of the arg1 && m_unk2E4 test and the return paths differs. Tried ternary, early return, single trailing return; all 12-16 lines.
int Camera::SetControlled(unsigned int arg0, bool arg1) {
    if (m_unk2E4 == 0 || arg0 == 0) {
        m_unk2E4 = arg0;
        if (arg1 && m_unk2E4 != 0) {
            m_unk2B8 = 1;
        } else {
            m_unk2B8 = 0;
        }
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

// DRAFT: 0x00179810 RestoreCamBox__6CameraFv
// note: 25 differing lines, size 0x84 vs 0x8c; original shares an epilogue via `b` with ld ra in the delay slot and places the 2B0 test as beq; tried early returns, nested if, combined &&, gEng index form, and swapped add operands.
void Camera::RestoreCamBox() {
    if (m_unkB4 != 4) {
        return;
    }
    if (m_unk2B0 != 3) {
        return;
    }
    *(float *)((char *)m_unk2B4 + 0x30) = 1.0f;
    void *temp_v0 = *(void **)&gEng[0x1883C];
    void *temp_v1 = *(void **)((char *)temp_v0 + 0x3C);
    char *var_a1 = (char *)temp_v0 + 0x190;
    if (temp_v1 != 0) {
        var_a1 = (char *)temp_v1 + 0x80;
    }
    sceVu0CopyVector(m_unk10, (float *)var_a1);
    m_unk10[1] = 5.0f + m_unk10[1];
}

// FUNCTION: 0x001798A0 UpdateFromApparition__6CameraFv
void Camera::UpdateFromApparition() {
    PVec3 sp20;
    PVec3 sp30;

    CheckCameraShake(*(PVec3 *)this, *(PVec3 *)&m_unk10, false);
    sp20 = *(PVec3 *)m_unk00;
    sp30 = *(PVec3 *)m_unk10;
    CreateViewMatrix(*(PMat4 *)&_pad020[0x10], sp20, sp30);
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

// FUNCTION: 0x00179F20 CheckCameraShake__6CameraFR5PVec3R5PVec3b
void Camera::CheckCameraShake(PVec3 &arg0, PVec3 &arg1, bool arg2) {
    if (m_unk179 != 0) {
        if (ShakeScreen(arg0, arg1, arg2)) {
            m_unk179 = 0;
        }
    }
}

// FUNCTION: 0x00179F60 SetCamMode__6CameraFsb
// note: not compared yet; first draft from asm (bool branch, switch on m_unkB8 with default assert).
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
// note: 18 differing words; original keeps the copied PVec3 address in v0 and has no null recheck before the reload of m_unkBC; ours uses v1 and adds a recheck. Tried a temp local and direct m_unkBC access.
void Camera::CamCollideCylinder(PVec3 arg0, float arg1, float arg2) {
    if (m_unkBC != 0) {
        ((CameraFollow *)m_unkBC)->CamCollideCylinder(arg0, arg1, arg2);
    }
}

// DRAFT: 0x0017A0C0 CamCollideSphere__6CameraF5PVec3f
// note: 18 differing lines; ours copies the PVec3 param to sp+0x10 at entry and again before the call, original copies once after the null test. Tried plain if, local copy in the if (frame 0x30), early return (copy hoisted, second null test); plain if is the closest.
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

// DRAFT: 0x0017A190 SetCamBoxValue_FollowHeight__6CameraFf
// note: 27 differing words; frame 0x30 vs 0x40 and this in s0 vs s1; original builds the 3.0 double in s0 before fptodp, ours after. Tried literal 3.0 in printf, local double inside the if, function-scope double, cast removed; count unchanged at 27.
void Camera::SetCamBoxValue_FollowHeight(float arg0) {
    double min = 3.0;
    if (m_unkBC != 0) {
        if (arg0 < 3.0f) {
            printf("(Camera Error) Camera height box cannot be less that %f above ground. Value passed = %f\n", min, (double)arg0);
        }
        ((CameraFollow *)m_unkBC)->SetCamBoxValue_FollowHeight(arg0);
    }
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

// DRAFT: 0x0017A280 PolyDebug__6CameraFv
// note: 11 differing words; original branches with b to the shared jr ra exit (ld in delay slot), ours uses bnez. Tried &&, early return, nested if/else, explicit returns; count unchanged.
void Camera::PolyDebug() {
    if (m_unkB4 == 0 && m_unkB0 != 0) {
        ((CameraFollow *)m_unkBC)->DrawPolyDebug();
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

// DRAFT: 0x0017A880 __ct__6CameraFv
// note: original spills this to 0x1C(sp) and keeps no s-regs; ours keeps this in s0 (size 0x114 vs 0x11C, DIFF 68); tried a local Camera* copy, same DIFF.
Camera::Camera() {
    sceVu0UnitMatrix(m_unk30);
    sceVu0UnitMatrix(m_unk70);
    m_unkBC = __nw__FUi(0x64A0);
    if (m_unkBC != 0) {
        m_unkBC = __ct__12CameraFollowFP6Camera(m_unkBC, this);
    }
    if (m_unkBC == 0) {
        CdsAssert__FPciPc("Camera.cpp", 0x18, "m_pFollowCam");
    }
    m_unkC0 = __nw__FUi(0xD0);
    if (m_unkC0 != 0) {
        m_unkC0 = __ct__16CameraCutManagerFP6Camera(m_unkC0, this);
    }
    if (m_unkC0 == 0) {
        CdsAssert__FPciPc("Camera.cpp", 0x1B, "m_pCutManager");
    }
    m_unkC4 = __nw__FUi(0x250);
    if (m_unkC4 != 0) {
        m_unkC4 = __ct__11CameraDebugFP6Camera(m_unkC4, this);
    }
    if (m_unkC4 == 0) {
        CdsAssert__FPciPc("Camera.cpp", 0x1E, "m_pDebugCam");
    }
}
