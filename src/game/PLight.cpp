// FLAGS: -str readonly
#include "PLight.h"
#include "Debug.h"
#include "PCDFile.h"
#include "PMeshNode.h"

// TODO(header): foreign declarations
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern "C" void sceVu0SubVector(float *dst, float *a, float *b);
extern "C" float sceVu0InnerProduct(float *a, float *b);
extern "C" void sceVu0ScaleVectorXYZ(float *dst, float *src, float scale);
extern "C" float sqrtf(float x);
extern "C" void memcpy(void *dst, const void *src, unsigned int n);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void __dl__FPv(void *pMem);
extern float gUnitMatrix[16];

// FUNCTION: 0x0018E520 ComputeColor__6PLightFPfPf
void PLight::ComputeColor(float *pOut, float *pPos) {
    float tmp[4];
    float d2;
    float r;
    float scale;

    if (m_unk44 == 2) {
        sceVu0SubVector(tmp, pPos, (float *)this);
        d2 = sceVu0InnerProduct(tmp, tmp);
        r = m_unk40;
        if (d2 >= r * r) {
            scale = 0.0f;
        } else {
            scale = (r - sqrtf(d2)) / r;
        }
        sceVu0ScaleVectorXYZ(pOut, m_unk30, scale);
    } else {
        sceVu0CopyVector(pOut, m_unk30);
    }
}

// FUNCTION: 0x0018E5D0 GetBrightness__6PLightFPf
float PLight::GetBrightness(float *pPos) {
    if (m_unk44 == 3) {
        m_unk50 = 0.299f * m_unk30[0] + 0.587f * m_unk30[1] + 0.144f * m_unk30[2];
    } else {
        ComputeColor(m_unk60, pPos);
        m_unk50 = 0.299f * m_unk60[0] + 0.587f * m_unk60[1] + 0.144f * m_unk60[2];
    }
    return m_unk50;
}

// FUNCTION: 0x0018E6A0 Load__6PLightFP8PPakFile
int PLight::Load(PPakFile *pFile) {
    char buf[0x40];

    if (pFile == 0) {
        CdsAssert("PLight.cpp", 0x2E, "poFile");
    }
    if (((PCDFile *)pFile)->Read(buf, 0x40) != 0x40) {
        return 0;
    }
    m_unk44 = *(int *)buf;
    memcpy(m_unk30, buf + 0x24, 16);
    if (m_unk44 == 3) {
        memcpy(&m_unk20, buf + 0x14, 16);
    } else if (m_unk44 == 2) {
        memcpy(&m_unk0, buf + 4, 16);
        *(u_long128 *)&m_unk10 = *(u_long128 *)&m_unk0;
        m_unk40 = *(float *)&buf[0x34];
    }
    m_unk48 = 1;
    return 1;
}

// FUNCTION: 0x0018E780 __dt__6PLightFv
PLight::~PLight() {
    m_unk44 = 0;
    m_unk48 = 0;
    if (m_unk4C != 0) {
        m_unk4C->DetachLight(this);
        m_unk4C = 0;
    }
}

// FUNCTION: 0x0018E7F0 __ct__6PLightFv
PLight::PLight() {
    m_unk10 = *(u_long128 *)&gUnitMatrix[12];
    m_unk0 = *(u_long128 *)&gUnitMatrix[12];
    m_unk20 = *(u_long128 *)&gUnitMatrix[12];
    memset(m_unk30, 0, 16);
    m_unk40 = 1000.0f;
    m_unk44 = 0;
    m_unk48 = 0;
    m_unk4C = 0;
    m_unk50 = 0.0f;
    m_unk60[2] = 0.0f;
    m_unk60[1] = 0.0f;
    m_unk60[0] = 0.0f;
    m_unk60[3] = 1.0f;
}
