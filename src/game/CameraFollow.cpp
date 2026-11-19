#include "CameraFollow.h"

// TODO(header): foreign declarations
extern "C" void sceVu0CopyVector(float *dst, float *src);

class PVec3 {
public:
    PVec3(const PVec3 &) {}
    float m_v[4];
};

class Camera {
public:
    void SetSourceTarget(PVec3 arg0, PVec3 arg1);
    void UpdatePos(PVec3 arg0, PVec3 arg1);

    float m_src[4];         // 0x000
    float m_tgt[4];         // 0x010
};

class Physics {
public:
    void GetGroundPos();

    float m_unk0;           // 0x000
    float m_unk4;           // 0x004
    float m_unk8;           // 0x008
    int m_unkC;             // 0x00C
};

// FUNCTION: 0x00173C50 __dt__15tag_ControlDataFv
tag_ControlData::~tag_ControlData() {
}

// FUNCTION: 0x00173E70 SetSourceTarget__6CameraF5PVec35PVec3
void Camera::SetSourceTarget(PVec3 arg0, PVec3 arg1) {
    sceVu0CopyVector(m_src, arg0.m_v);
    sceVu0CopyVector(m_tgt, arg1.m_v);
}

// FUNCTION: 0x00174770 UpdatePos__6CameraF5PVec35PVec3
void Camera::UpdatePos(PVec3 arg0, PVec3 arg1) {
    sceVu0CopyVector(m_src, arg0.m_v);
    sceVu0CopyVector(m_tgt, arg1.m_v);
}

// FUNCTION: 0x00174AF0 SetSourceAndTarget__12CameraFollowF5PVec35PVec3
void CameraFollow::SetSourceAndTarget(PVec3 arg0, PVec3 arg1) {
    sceVu0CopyVector(m_unk20, arg0.m_v);
    sceVu0CopyVector(m_unk40, arg1.m_v);
}

// FUNCTION: 0x00176170 GetGroundPos__7PhysicsFv
void Physics::GetGroundPos() {
    asm {
        lwc1 f0, 0xB0(a1)
        lui v1, 0x3F80
        swc1 f0, 0x0(a0)
        lwc1 f0, 0xB4(a1)
        swc1 f0, 0x4(a0)
        lwc1 f0, 0xB8(a1)
        swc1 f0, 0x8(a0)
        sw v1, 0xC(a0)
        jr ra
    }
}
