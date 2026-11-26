// FLAGS: -str readonly
#include "CameraDebug.h"
#include "Camera.h"
#include "Debug.h"
#include "PMat4.h"

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
extern "C" void sceVu0ScaleVectorXYZ(float *dst, float *src, float s);
extern "C" void sceVu0AddVector(float *dst, float *src0, float *src1);
extern "C" float FastMath_Fabs__Ff(float f);
extern "C" void Round180__Ff(float f);
extern "C" float atan2f(float y, float x);
extern "C" int _dpfge(long long a, long long b);
extern signed char gPad[448];
void vu1SetScreenMatrix(PMat4 *pMat);
extern "C" void SetViewMatrix__6CameraF5PMat4(Camera *pCamera, PMat4 mat);
extern "C" void UpdatePos__6CameraF5PVec35PVec3(Camera *pCamera, PVec3 a, PVec3 b);

// FUNCTION: 0x0017C850 DrawTextDebug__11CameraDebugFv
void CameraDebug::DrawTextDebug() {
    int y;
    int x = fptodp(m_unk50[0]);
    y = fptodp(m_unk50[1]);
    int z = fptodp(m_unk50[2]);
    sprintf(m_text150, "Cam xyz = %f, %f, %f\n", x, y, z);
    gDebug.DebugDisp(m_text150);
}

// DRAFT: 0x0017C8D0 Update__11CameraDebugFb
// note: size 0x9ac vs 0x894 and frame 0x350 vs 0x250 (7 matrix locals too many); branch shape and tail order differ; 583 words
void CameraDebug::Update(bool arg0) {
    int abs(int);
    float sp40[16];
    float sp130[16];
    float sp170[16];
    float sp1B0[16];
    float spB0[16];
    float spF0[16];
    float sp210[16];
    PVec3 sp1F0;
    PVec3 sp200;
    float sp80[4];
    float sp90[4];
    float spA0[4];
    float f0;
    float f1;
    float t;

    sceVu0UnitMatrix(sp40);
    if (arg0) {
        m_unk90 = (signed char)gPad[0x116];
        m_unk91 = (signed char)gPad[0x117];
        m_unkA4 = (signed char)gPad[0x114];
        m_unkA5 = (signed char)gPad[0x115];
        signed char s1 = (signed char)(abs(m_unk90) >> 4);
        signed char s2 = (signed char)(abs(m_unk91) >> 4);
        if ((s1 != 0) && (m_unk90 > 0)) {
            s1 = (signed char)(s1 + 1);
        }
        if ((s2 != 0) && (m_unk91 > 0)) {
            s2 = (signed char)(s2 + 1);
        }
        m_unk94 = (float)s1 / 8.0f;
        m_unk98 = (float)s2 / 8.0f;
        if (m_unk90 < 0) {
            f0 = -m_unk94;
        } else {
            f0 = m_unk94;
        }
        m_unk94 = f0;
        if (m_unk91 < 0) {
            f0 = -m_unk98;
        } else {
            f0 = m_unk98;
        }
        m_unk98 = f0;
        if (!(FastMath_Fabs__Ff(m_unk94) < 0.3f)) {
            if (!(m_unk94 <= 0.0f)) {
                f1 = 0.001f;
            } else {
                f1 = -0.001f;
            }
            t = m_unk104 + f1;
            m_unk104 = t;
            if (t < 0.1f) {
                m_unk104 = 0.1f;
            }
            if (!(m_unk104 <= 1.0f)) {
                m_unk104 = 1.0f;
            }
        }
        if (!(FastMath_Fabs__Ff(m_unk98) < 0.3f)) {
            if (!(m_unk98 <= 0.0f)) {
                f1 = 0.001f;
            } else {
                f1 = -0.001f;
            }
            t = m_unk108 + f1;
            m_unk108 = t;
            if (t < 0.1f) {
                m_unk108 = 0.1f;
            }
            if (!(m_unk108 <= 1.0f)) {
                m_unk108 = 1.0f;
            }
        }
        ((PMat4 *)m_unk110.m_v)->MakeScreenMatrix(m_unk100, m_unk104, m_unk108, 2048.0f, 2048.0f, 100.0f, 1.6777215e7f, 1.0f, 5000.0f);
        vu1SetScreenMatrix((PMat4 *)m_unk110.m_v);
        return;
    }
    if (m_unkB0 != 0) {
        t = m_unkD0;
        if (t <= 1.0f) {
            m_unk50[0] = m_unkE0 + (m_unkF0 * t);
            m_unk50[1] = m_unkE4 + (m_unkF4 * m_unkD0);
            m_unk50[2] = m_unkE8 + (m_unkF8 * m_unkD0);
            m_unkD0 += 0.01f;
        } else {
            m_unkB0 = 0;
        }
        sceVu0UnitMatrix(sp40);
        ((PMat4 *)sp40)->RotateY(-m_unk9C);
        ((PMat4 *)sp40)->RotateX(m_unkA0);
        ((PMat4 *)m_unk10.m_v)->MakeViewMatrix(m_unk50, m_unk70, m_unk80);
        sceVu0CopyMatrix((float (*)[4])spB0, (float (*)[4])m_unk10.m_v);
        ((PMat4 *)spF0)->Mul(*(PMat4 *)sp40);
        sceVu0CopyMatrix((float (*)[4])m_unk10.m_v, (float (*)[4])spF0);
        sceVu0CopyMatrix((float (*)[4])sp130, (float (*)[4])m_unk10.m_v);
        SetViewMatrix__6CameraF5PMat4(m_pCamera, *(PMat4 *)sp130);
        return;
    }
    sceVu0CopyVector(m_unk60, m_unk50);
    m_unk90 = (signed char)gPad[0x116];
    m_unk91 = (signed char)gPad[0x117];
    m_unkA4 = (signed char)gPad[0x114];
    m_unkA5 = (signed char)gPad[0x115];
    signed char s3 = (signed char)(abs(m_unk90) >> 4);
    signed char s4 = (signed char)(abs(m_unk91) >> 4);
    if ((s3 != 0) && (m_unk90 > 0)) {
        s3 = (signed char)(s3 + 1);
    }
    if ((s4 != 0) && (m_unk91 > 0)) {
        s4 = (signed char)(s4 + 1);
    }
    m_unk94 = (float)s3 / 8.0f;
    m_unk98 = (float)s4 / 8.0f;
    if (m_unk90 < 0) {
        f0 = -m_unk94;
    } else {
        f0 = m_unk94;
    }
    m_unk94 = f0;
    if (m_unk91 < 0) {
        f0 = -m_unk98;
    } else {
        f0 = m_unk98;
    }
    m_unk98 = f0;
    if (_dpfge(((long long (*)(float))fptodp)(FastMath_Fabs__Ff(m_unk94)), 0x33333333LL | (0x3FD33333LL << 0x20)) != 0) {
        m_unk9C += m_unk94;
    }
    if (_dpfge(((long long (*)(float))fptodp)(FastMath_Fabs__Ff(m_unk98)), 0x33333333LL | (0x3FD33333LL << 0x20)) != 0) {
        m_unkA0 += m_unk98;
    }
    Round180__Ff(m_unk9C);
    Round180__Ff(m_unkA0);
    signed char s5 = (signed char)(abs(m_unkA4) >> 4);
    signed char s6 = (signed char)(abs(m_unkA5) >> 4);
    if ((s5 != 0) && (m_unkA4 > 0)) {
        s5 = (signed char)(s5 + 1);
    }
    if ((s6 != 0) && (m_unkA5 > 0)) {
        s6 = (signed char)(s6 + 1);
    }
    m_unkA8 = (float)s5 / 8.0f;
    m_unkAC = (float)s6 / 8.0f;
    if (m_unkA4 < 0) {
        f0 = -m_unkA8;
    } else {
        f0 = m_unkA8;
    }
    m_unkA8 = f0;
    if (m_unkA5 < 0) {
        f0 = -m_unkAC;
    } else {
        f0 = m_unkAC;
    }
    m_unkAC = f0;
    ((PMat4 *)sp40)->RotateY(-m_unk9C);
    ((PMat4 *)sp40)->RotateX(m_unkA0);
    ((PMat4 *)m_unk10.m_v)->MakeViewMatrix(m_unk50, m_unk70, m_unk80);
    sceVu0CopyMatrix((float (*)[4])sp170, (float (*)[4])m_unk10.m_v);
    ((PMat4 *)sp1B0)->Mul(*(PMat4 *)sp40);
    sceVu0CopyMatrix((float (*)[4])m_unk10.m_v, (float (*)[4])sp1B0);
    *(float *)((char *)m_pCamera + 0x24) = 57.295776f * atan2f(-m_unk10.m_v[2], -m_unk10.m_v[10]);
    if (_dpfge(((long long (*)(float))fptodp)(FastMath_Fabs__Ff(m_unkAC)), 0x33333333LL | (0x3FD33333LL << 0x20)) != 0) {
        sp90[0] = -m_unk10.m_v[2];
        sp90[1] = -m_unk10.m_v[6];
        sp90[2] = -m_unk10.m_v[10];
        sceVu0ScaleVectorXYZ(sp80, sp90, -(0.5f * m_unkAC));
        sceVu0AddVector(m_unk50, m_unk50, sp80);
    }
    if (_dpfge(((long long (*)(float))fptodp)(FastMath_Fabs__Ff(m_unkA8)), 0x33333333LL | (0x3FD33333LL << 0x20)) != 0) {
        spA0[0] = -m_unk10.m_v[0];
        spA0[1] = -m_unk10.m_v[4];
        spA0[2] = -m_unk10.m_v[8];
        sceVu0ScaleVectorXYZ(sp80, spA0, -(0.5f * m_unkA8));
        sceVu0AddVector(m_unk50, m_unk50, sp80);
    }
    sp1F0.m_v[0] = m_unk50[0];
    sp1F0.m_v[1] = m_unk50[1];
    sp1F0.m_v[2] = m_unk50[2];
    sp1F0.m_v[3] = m_unk50[3];
    sp200.m_v[0] = m_unk50[0];
    sp200.m_v[1] = m_unk50[1];
    sp200.m_v[2] = m_unk50[2];
    sp200.m_v[3] = m_unk50[3];
    UpdatePos__6CameraF5PVec35PVec3(m_pCamera, sp1F0, sp200);
    sceVu0CopyMatrix((float (*)[4])sp210, (float (*)[4])m_unk10.m_v);
    SetViewMatrix__6CameraF5PMat4(m_pCamera, *(PMat4 *)sp210);
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
