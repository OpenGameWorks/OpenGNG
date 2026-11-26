#ifndef CAMERADEBUG_H
#define CAMERADEBUG_H

#include "types.h"

// TODO(header): foreign declarations
class PVec3;
class Camera;
extern "C" void sceVu0UnitMatrix(float *pMatrix);

// 64-byte matrix member whose constructor sets it to identity.
class CameraDebugMat {
public:
    CameraDebugMat() { sceVu0UnitMatrix(m_v); }
    ~CameraDebugMat() {}
    float m_v[16];
};

class CameraDebug {
public:
    CameraDebug(Camera *pCamera);
    ~CameraDebug();
    void DrawTextDebug();
    void Init(PVec3 arg0);
    void Update(bool arg0);

    Camera *m_pCamera;      // 0x000
    char _pad004[0xC];      // 0x004
    CameraDebugMat m_unk10; // 0x010 (PMat4, 64 bytes)
    float m_unk50[4];       // 0x050 (PVec3 copied in Init)
    char _pad060[0x10];     // 0x060
    float m_unk70[4];       // 0x070 (forward vector from Camera::GetForwardVector)
    float m_unk80[4];       // 0x080
    char _pad090[0x20];     // 0x090
    unsigned char m_unkB0;  // 0x0B0
    char _padB1[0x4F];      // 0x0B1
    float m_unk100;         // 0x100
    float m_unk104;         // 0x104
    float m_unk108;         // 0x108
    char _pad10C[4];        // 0x10C
    CameraDebugMat m_unk110; // 0x110 (PMat4, 64 bytes)
    char m_text150[0x100];  // 0x150 debug text buffer
};

#endif
