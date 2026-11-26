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
    float m_unk60[4];       // 0x060
    float m_unk70[4];       // 0x070 (forward vector from Camera::GetForwardVector)
    float m_unk80[4];       // 0x080
    signed char m_unk90;    // 0x090 pad sample X
    signed char m_unk91;    // 0x091 pad sample Y
    char _pad092[2];        // 0x092
    float m_unk94;          // 0x094
    float m_unk98;          // 0x098
    float m_unk9C;          // 0x09C
    float m_unkA0;          // 0x0A0
    signed char m_unkA4;    // 0x0A4 pad sample
    signed char m_unkA5;    // 0x0A5 pad sample
    char _padA6[2];         // 0x0A6
    float m_unkA8;          // 0x0A8
    float m_unkAC;          // 0x0AC
    unsigned char m_unkB0;  // 0x0B0
    char _padB1[0x1F];      // 0x0B1
    float m_unkD0;          // 0x0D0
    char _padD4[0xC];       // 0x0D4
    float m_unkE0;          // 0x0E0
    float m_unkE4;          // 0x0E4
    float m_unkE8;          // 0x0E8
    char _padEC[4];         // 0x0EC
    float m_unkF0;          // 0x0F0
    float m_unkF4;          // 0x0F4
    float m_unkF8;          // 0x0F8
    char _padFC[4];         // 0x0FC
    float m_unk100;         // 0x100
    float m_unk104;         // 0x104
    float m_unk108;         // 0x108
    char _pad10C[4];        // 0x10C
    CameraDebugMat m_unk110; // 0x110 (PMat4, 64 bytes)
    char m_text150[0x100];  // 0x150 debug text buffer
};

#endif
