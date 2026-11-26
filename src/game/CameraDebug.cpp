// FLAGS: -str readonly
#include "CameraDebug.h"
#include "Camera.h"
#include "Debug.h"

// TODO(header): foreign declarations
class PVec3 {
public:
    PVec3() {}
    PVec3(const PVec3 &o) {
        m_v[0] = o.m_v[0];
        m_v[1] = o.m_v[1];
        m_v[2] = o.m_v[2];
        m_v[3] = o.m_v[3];
    }
    float m_v[4];
};

extern unsigned char gEng[0x1A000];
extern Debug gDebug;
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern "C" void sceVu0UnitMatrix(float *pMatrix);
extern "C" int fptodp(float f);
extern "C" int sprintf(char *buf, const char *fmt, ...);

// FUNCTION: 0x0017C850 DrawTextDebug__11CameraDebugFv
void CameraDebug::DrawTextDebug() {
    int y;
    int x = fptodp(m_unk50[0]);
    y = fptodp(m_unk50[1]);
    int z = fptodp(m_unk50[2]);
    sprintf(m_text150, "Cam xyz = %f, %f, %f\n", x, y, z);
    gDebug.DebugDisp(m_text150);
}

// FUNCTION: 0x0017D170 Init__11CameraDebugF5PVec3
void CameraDebug::Init(PVec3 arg0) {
    sceVu0CopyVector(m_unk50, arg0.m_v);
    ((Camera *)(gEng + 0x19760))->GetForwardVector(m_unk70);
    ((int *)m_unk70)[1] = 0;
}

// FUNCTION: 0x0017D1B0 __dt__11CameraDebugFv
CameraDebug::~CameraDebug() {
}

// FUNCTION: 0x0017D200 __ct__11CameraDebugFP6Camera
CameraDebug::CameraDebug(Camera *pCamera) {
    m_pCamera = pCamera;
    m_unk70[0] = 0.0f;
    m_unk70[1] = 0.0f;
    m_unk70[2] = 1.0f;
    m_unk70[3] = 1.0f;
    m_unk80[0] = 0.0f;
    m_unk80[1] = -1.0f;
    m_unk80[2] = 0.0f;
    m_unk80[3] = 1.0f;
    m_unkB0 = 0;
    m_unk100 = 360.0f;
    m_unk104 = 1.0f;
    m_unk108 = 0.56f;
}
