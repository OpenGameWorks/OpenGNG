// FLAGS: -str readonly
#include "CameraAPI.h"
#include "Camera.h"
#include "types.h"

// TODO(header): foreign declarations
class EntityBaseClass {
public:
    char _pad0[4];
    unsigned int m_unk4;
};

void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" int ControlledByApp__6CameraFUi(Camera *pCamera, unsigned int arg);
extern "C" void sceVu0CopyVector(float *dst, float *src);

// FUNCTION: 0x00155280 SetFollowCameraParams__9CameraAPIFff
void CameraAPI::SetFollowCameraParams(float arg0, float arg1) {
    if (m_unk0 == 0) {
        CdsAssert("CameraAPI.cpp", 116, "m_pCamera");
    }
    m_unk0->SetFollowCameraParams(arg0, arg1);
}

// FUNCTION: 0x001552F0 ReleaseControlOfCamera__9CameraAPIFP15EntityBaseClassb
void CameraAPI::ReleaseControlOfCamera(EntityBaseClass *arg0, bool arg1) {
    unsigned char appControlled = ControlledByApp__6CameraFUi(m_unk0, 0);
    if (arg0 == 0 || ControlledByApp__6CameraFUi(m_unk0, arg0->m_unk4)) {
        m_unk0->SetControlled(0, false);
        if (!appControlled) {
            m_unk0->RestoreFollowCamPos(arg1);
            m_unk0->RestoreCamBox();
        }
    }
}

// FUNCTION: 0x00155390 SetCameraLookAtParams__9CameraAPIFP15EntityBaseClassPfPf
void CameraAPI::SetCameraLookAtParams(EntityBaseClass *arg0, float *arg1, float *arg2) {
    if (ControlledByApp__6CameraFUi(m_unk0, arg0->m_unk4)) {
        m_unk0->SetSourceTarget(arg1, arg2);
    }
}

// FUNCTION: 0x001553F0 TakeControlOfCamera__9CameraAPIFP15EntityBaseClassb
bool CameraAPI::TakeControlOfCamera(EntityBaseClass *arg0, bool arg1) {
    if (m_unk0->SetControlled(arg0->m_unk4, arg1)) {
        Camera *cam = m_unk0;
        sceVu0CopyVector(cam->m_unk2F0, (float *)cam);
        sceVu0CopyVector(cam->m_unk300, cam->m_unk10);
        return true;
    }
    return false;
}

// FUNCTION: 0x00155450 FollowCamInBossMode__9CameraAPIFv
void CameraAPI::FollowCamInBossMode() {
    if (m_unk0 == 0) {
        CdsAssert("CameraAPI.cpp", 74, "m_pCamera");
    }
    m_unk0->FollowCamInBossMode();
}

// FUNCTION: 0x001554A0 ModifyBossCamera__9CameraAPIFfff
void CameraAPI::ModifyBossCamera(float arg0, float arg1, float arg2) {
    if (m_unk0 == 0) {
        CdsAssert("CameraAPI.cpp", 60, "m_pCamera");
    }
    m_unk0->ModifyBossCamera(arg0, arg1, arg2);
}

// FUNCTION: 0x00155520 SetBossPosition__9CameraAPIFPA4_f
void CameraAPI::SetBossPosition(float (*arg0)[4]) {
    if (m_unk0 == 0) {
        CdsAssert("CameraAPI.cpp", 53, "m_pCamera");
    }
    m_unk0->SetBossPosition(arg0);
}

// FUNCTION: 0x00155580 SetBossArenaValues__9CameraAPIFPA4_fffbbffb
void CameraAPI::SetBossArenaValues(float (*arg0)[4], float arg1, float arg2, bool arg3, bool arg4, float arg5, float arg6, bool arg7) {
    if (m_unk0 == 0) {
        CdsAssert("CameraAPI.cpp", 46, "m_pCamera");
    }
    m_unk0->SetBossArenaValues(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
}

// FUNCTION: 0x00155650 ShakeScreenUsingTable__9CameraAPIFiUi
void CameraAPI::ShakeScreenUsingTable(int arg0, unsigned int arg1) {
    if (m_unk0 == 0) {
        CdsAssert("CameraAPI.cpp", 31, "m_pCamera");
    }
    if (m_unk0->PlayerInFixedCamBox()) {
        m_unk0->SetupShakeScreen(0.0f, 0.0f, 0.0f, 1, 1, arg1);
        return;
    }
    m_unk0->SetupShakeScreen(0.0f, 0.0f, 0.0f, 1, arg0, arg1);
}

// FUNCTION: 0x00155700 ShakeScreen__9CameraAPIFfffUi
void CameraAPI::ShakeScreen(float arg0, float arg1, float arg2, unsigned int arg3) {
    if (m_unk0 == 0) {
        CdsAssert("CameraAPI.cpp", 16, "m_pCamera");
    }
    if (m_unk0->PlayerInFixedCamBox()) {
        m_unk0->SetupShakeScreen(0.0f, 0.0f, 0.0f, 1, 1, arg3);
        return;
    }
    m_unk0->SetupShakeScreen(arg0, arg1, arg2, 0, 0, arg3);
}
