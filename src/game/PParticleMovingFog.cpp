// FLAGS: -str readonly
#include "types.h"
#include "PParticleMovingFog.h"

// TODO(header): foreign declarations
class PFrustrum;
extern "C" void sceVu0UnitMatrix(float (*pMatrix)[4]);
extern "C" void sceVu0ScaleVectorXYZ(float *dst, float *src, float scale);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void __construct_array(void *pBlock, void (*pCtor)(void *), void (*pDtor)(void *, short), unsigned int nElemSize, unsigned int nCount);
extern "C" void __ct__5PMat4Fv(void *pThis);
extern "C" void __dt__5PMat4Fv(void *pThis, short nFlag);
extern "C" int rand(void);
extern "C" float sqrtf(float x);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
void FastMath_ComputeMatrixLite(float (*pM)[4][4], float (*pA)[4], float (*pB)[4], float (*pC)[4], float (*pD)[4][4]);
extern "C" int GetFxTexture__16PParticleManagerFUi(void *pThis, unsigned int nValue);
extern char gGfxEng[1504384];

// 0x60-byte fog parameter block: the original frame reserves it, not the 0x50-byte struct alone.
struct FogBuf {
    tagParticleFogData d;
    char _pad[0x10];
};

// FUNCTION: 0x001D6160 CreateFogObjects__18PParticleMovingFogFv
void PParticleMovingFog::CreateFogObjects() {
    FogBuf buf;
    float pos[4];
    int tex = GetFxTexture__16PParticleManagerFUi((char *)gGfxEng + 0x154F00, 0x84000002);
    for (unsigned int i = 0; i < m_unk4A0; i++) {
        memset(&buf.d, 0, 0x60);
        pos[0] = m_unk10 + (m_unk20 - m_unk10) * ((float)rand() / 2147483648.0f);
        pos[1] = m_unk14 + (m_unk24 - m_unk14) * ((float)rand() / 2147483648.0f);
        pos[2] = m_unk18 + (m_unk28 - m_unk18) * ((float)rand() / 2147483648.0f);
        pos[3] = 1.0f;
        *(float *)buf.d._pad0C = 1.0f;
        buf.d.unk0 = 0.0f;
        buf.d.unk4 = 0.0f;
        buf.d.unk8 = 0.0f;
        *(u_long128 *)m_unk2A0[i] = *(u_long128 *)pos;
        m_unk300[i] = -180.0f + 360.0f * ((float)rand() / 2147483648.0f);
        rand();
        buf.d.unk10 = 25.0f;
        buf.d.unk14 = 2.0f + 2.0f * ((float)rand() / 2147483648.0f);
        rand();
        buf.d.unk18 = 25.0f;
        buf.d.unk1C = sqrtf(buf.d.unk10 * buf.d.unk10 + buf.d.unk14 * buf.d.unk14 + buf.d.unk18 * buf.d.unk18);
        buf.d.unk20 = *(u_long128 *)m_unk40;
        buf.d.unk30 = 0.1f;
        buf.d.unk34 = 3.0f;
        buf.d.unk38 = 0.85f;
        buf.d.unk3C = 1;
        buf.d.unk40 = 160;
        buf.d.unk44 = 1;
        m_unk60[i].Create(&buf.d, tex);
    }
}

// FUNCTION: 0x001D63E0 Render__18PParticleMovingFogFv
void PParticleMovingFog::Render() {
    float mtx[4][4];
    sceVu0UnitMatrix(mtx);
    for (unsigned int i = 0; i < m_unk4A0; i++) {
        m_unk60[i].Render(&m_unk320[i]);
    }
}

// FUNCTION: 0x001D6460 FrustrumTest__18PParticleMovingFogFP9PFrustrumPfff
void PParticleMovingFog::FrustrumTest(PFrustrum *pFrustum, float *pPos, float fNear, float fFar) {
    for (unsigned int i = 0; i < m_unk4A0; i++) {
        m_unk60[i].FrustrumTest(pFrustum, pPos, fNear, fFar, &m_unk320[i]);
    }
}

// DRAFT: 0x001D6520 Animate__18PParticleMovingFogFf
// note: 127 words differ; the frame is 0xC0 (original 0x80) because the loop keeps s2-s5 live across the rand/FastMath calls (strength-reduced i*4, i*0x40, m_unk2A0 pointer), the original recomputes them; tried loop scoping, signed index, scoped VU0 block, address-expression operands, all 127.
void PParticleMovingFog::Animate(float fDelta) {
    float a[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    float b[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    float d[4];
    float pos[4];
    sceVu0SubVector(d, &m_unk20, &m_unk10);
    for (int i = 0; i < (int)m_unk4A0; i++) {
        {
            float fScale = fDelta * m_unk50;
            int sb;
            float *pPos = (float *)((char *)this + 0x2A0 + i * 16);
            float *pVel = (float *)((char *)this + 0x30);
            asm {
                lqc2 vf1, 0x0(pVel)
                lqc2 vf2, 0x0(pPos)
                vmove.xyzw vf5, vf2
                mfc1 sb, fScale
                qmtc2.i sb, vf3
                vmulx.xyz vf4, vf1, vf3x
                vnop
                vnop
                vnop
                vadd.xyz vf5, vf4, vf2
                vnop
                vnop
                vnop
                sqc2 vf5, 0x0(pPos)
            }
        }
        m_unk2A0[i][3] = 1.0f;
        if (!(m_unk2A0[i][2] <= m_unk28)) {
            pos[0] = m_unk10 + (m_unk20 - m_unk10) * ((float)rand() / 2147483648.0f);
            pos[1] = m_unk14 + (m_unk24 - m_unk14) * ((float)rand() / 2147483648.0f);
            pos[2] = m_unk18;
            pos[3] = 1.0f;
            m_unk300[i] = -180.0f + 360.0f * ((float)rand() / 2147483648.0f);
            *(u_long128 *)m_unk2A0[i] = *(u_long128 *)pos;
        }
        b[1] = m_unk300[i];
        FastMath_ComputeMatrixLite((float (*)[4][4])&m_unk320[i], (float (*)[4])a, (float (*)[4])b, (float (*)[4])m_unk2A0[i], 0);
    }
}

// FUNCTION: 0x001D6730 Create__18PParticleMovingFogFP26tagParticleMovingFogParams
int PParticleMovingFog::Create(tagParticleMovingFogParams *pParams) {
    memcpy(&m_unk10, pParams, 0x50);
    m_unk4A0 = 6;
    sceVu0ScaleVectorXYZ(m_unk40, m_unk40, 255.0f);
    m_unk40[3] *= 128.0f;
    CreateFogObjects();
    return 1;
}

// FUNCTION: 0x001D67A0 __dt__18PParticleMovingFogFv
PParticleMovingFog::~PParticleMovingFog() {}

// FUNCTION: 0x001D6830 __ct__18PParticleMovingFogFv
PParticleMovingFog::PParticleMovingFog() {
    __construct_array(m_unk320, __ct__5PMat4Fv, __dt__5PMat4Fv, 0x40, 6);
    memset(&m_unk10, 0, 0x50);
    m_unk4A0 = 0;
}
