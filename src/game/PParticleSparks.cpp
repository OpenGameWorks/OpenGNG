// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "PParticleSparks.h"
#include "PRandom.h"

// TODO(header): foreign declarations
class PMat4;
struct tagVuFxLine;
extern "C" void MulVector__5PMat4FPfPf(PMat4 *pMat, float *pSrc, float *pDst);
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dla__FPv(void *);
extern "C" void __dl__FPv(void *);
extern unsigned char __vt__15PParticleSparks[];
extern "C" int rand();
extern char gGfxEng[1504384];
extern "C" void SetWorldMatrix__10PGfxEngineFP5PMat4(void *, PMat4 *);
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *, int, float *, bool, unsigned long, unsigned long);
extern "C" void BeginFxLines__10PGfxEngineFv(void *);
extern "C" void DrawFxLines__10PGfxEngineFP11tagVuFxLineiffb(void *, tagVuFxLine *, int, float, float, bool);
extern "C" void EndFxLines__10PGfxEngineFv(void *);
extern "C" float sqrtf(float x);
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void sceVu0ScaleVectorXYZ(float *pDst, float *pSrc, float fScale);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void *AllocParticles__12PDisplayListFii(void *pThis, unsigned int nCount, int nType);
extern "C" void sceVu0Normalize(float *dst, float *src);
extern "C" void sceVu0SubVector(float *dst, float *a, float *b);

// DRAFT: 0x001F7F10 InitSparkDirections__15PParticleSparksFv
// note: DIFF 191, size 0x344 vs 0x32C; frame 0xB0 with s4..s6 saved vs 0x70 with s0..s3 only. Tried bool flag (218), function-scope i (192, frame 0x80), locals moved after the Normalize call, nBits in loop.
void PParticleSparks::InitSparkDirections() {
    u_long128 vTmp;
    float vec[4];
    int nBits;
    int bRandom = 0;
    if (m_unk140 == 0) CdsAssert("PParticleSparks.cpp", 0xE2, "mpDirections");
    if (m_unkF0 == 0.0f) {
        if (m_unkF4 == 0.0f) {
            if (m_unkF8 == 0.0f) bRandom = 1;
        }
    }
    for (int i = 0; i < m_unk118; i++) {
        float *pS2 = (float *)((char *)m_unk140 + (i << 5));
        float *pT = (float *)&vTmp;
        float *pA2 = (float *)&m_unk150;
        float fScale = m_unk128;
        if (bRandom) {
            vec[0] = 2.0f * ParticleRand01(m_unkD0) - 1.0f;
            vec[1] = 2.0f * ParticleRand01(m_unkD0) - 1.0f;
            vec[2] = 2.0f * ParticleRand01(m_unkD0) - 1.0f;
        } else {
            float t = m_unk11C;
            float u = ParticleRand01(m_unkD0);
            vec[0] = m_unkF0 + (-t + (t + t) * u);
            u = ParticleRand01(m_unkD0);
            vec[1] = m_unkF4 + (-t + (t + t) * u);
            u = ParticleRand01(m_unkD0);
            vec[2] = m_unkF8 + (-t + (t + t) * u);
        }
        sceVu0Normalize(pS2, vec);
        asm {
            lqc2 vf1, 0x0(pS2)
            lqc2 vf2, 0x0(pA2)
            lqc2 vf5, 0x0(pT)
            mfc1 nBits, fScale
            qmtc2.i nBits, vf3
            vmulx.xyz vf4, vf1, vf3x
            vnop
            vnop
            vnop
            vadd.xyz vf5, vf4, vf2
            vnop
            vnop
            vnop
            sqc2 vf5, 0x0(pT)
        }
        ((float *)&vTmp)[1] = ((float *)&vTmp)[1] - m_unk12C;
        sceVu0SubVector(vec, pT, pA2);
        sceVu0Normalize(vec, vec);
        sceVu0SubVector(pS2 + 4, vec, pS2);
    }
}

// FUNCTION: 0x001F8240 ModifyPosition__15PParticleSparksFP5PMat4
void PParticleSparks::ModifyPosition(PMat4 *pMat) {
    MulVector__5PMat4FPfPf(pMat, (float *)&m_unk150, (float *)&m_unkE0);
    m_unk80 = ((float *)&m_unk150)[0];
    m_unk84 = ((float *)&m_unk150)[1];
    m_unk88 = ((float *)&m_unk150)[2];
}

// FUNCTION: 0x001F8290 Start__15PParticleSparksFv
void PParticleSparks::Start() {
    m_unk148 = 0;
    m_unk170 = (int)(0.5f + (62315.0f + (-10989.0f * ((float)rand() / 2147483648.0f))));
    m_unk160 = m_unk150;
    InitSparkDirections();
    m_unk15 = 1;
    m_unk18 = 1;
}

// DRAFT: 0x001F8330 Render__15PParticleSparksFv
// note: DIFF 37; the m_unk08 test is bnez to body, nop, b epilogue in the original; ours is beqz to epilogue. Tried nested-if, if/else, empty-then, combined &&, four early returns, trailing return in body, trailing return after if.
void PParticleSparks::Render() {
    if (m_unk15 == 0) {
        return;
    }
    if (m_unk16 != 0) {
        return;
    }
    if (m_unkA4 == 0) {
        return;
    }
    if (m_unk08 != 0) {
        SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, (PMat4 *)&m_unk40);
        SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, 0, (float *)&m_unkC0, true, m_unk30, 0x50000);
        BeginFxLines__10PGfxEngineFv(gGfxEng);
        DrawFxLines__10PGfxEngineFP11tagVuFxLineiffb(gGfxEng, (tagVuFxLine *)m_unk08, m_unk04, 0.0f, 128.0f, m_unk1A);
        EndFxLines__10PGfxEngineFv(gGfxEng);
    }
    return;
}

// DRAFT: 0x001F83F0 Animate__15PParticleSparksFf
// note: DIFF 153, size 0x2C8 vs 0x2C0; shared exit of the two early tests (original beqz to one epilogue) and saved-register set (s5 vs s6) differ. Tried pBuf local, if-wrapped body, for-loop variants.
void PParticleSparks::Animate(float fDelta) {
    int nCount = 0;
    UpdateLoopDelay(fDelta);
    if (m_unk15 == 0) {
        return;
    }
    if (m_unk16 != 0) {
        return;
    }
    m_unkD0 = m_unk170;
    m_unk08 = AllocParticles__12PDisplayListFii(*(void **)(gGfxEng + 0x154C80), m_unk04, 2);
    if (m_unk08 == 0) CdsAssert("PParticleSparks.cpp", 0x70, "apLines");
    m_unk148 = m_unk148 + fDelta;
    for (int j = 0; j < m_unk04; j++) {
        float *pP = (float *)((char *)m_unk08 + (j << 5));
        float *pQ = (float *)((char *)m_unk140 + (j << 5));
        float fScale = m_unk130 + (1.0f - m_unk130) * ParticleRand01(m_unkD0);
        float fT = m_unk148 * fScale;
        if (!(fT < m_unk144)) {
            fT = m_unk144;
            if (++nCount >= m_unk118) {
                fT = 0.0f;
                m_unk148 = 0;
                UpdateLoopCounter();
                m_unk160 = m_unk150;
                if (m_unk15 == 0) {
                    return;
                }
            }
        }
        float fRatio = fT / m_unk144;
        float fRatioSq = fRatio * fRatio;
        float *pPv = (float *)((char *)pP + 0x10);
        float *pQ10 = (float *)((char *)pQ + 0x10);
        int nBits;
        asm {
            lqc2 vf1, 0x0(pQ10)
            lqc2 vf2, 0x0(pQ)
            lqc2 vf5, 0x0(pPv)
            mfc1 nBits, fRatio
            qmtc2.i nBits, vf3
            vmulx.xyz vf4, vf1, vf3x
            vnop
            vnop
            vnop
            vadd.xyz vf5, vf4, vf2
            vnop
            vnop
            vnop
            sqc2 vf5, 0x0(pPv)
        }
        float fRatio2 = m_unk128 * fRatio;
        float *pM160 = (float *)&m_unk160;
        asm {
            lqc2 vf1, 0x0(pPv)
            lqc2 vf2, 0x0(pM160)
            lqc2 vf5, 0x0(pP)
            mfc1 nBits, fRatio2
            qmtc2.i nBits, vf3
            vmulx.xyz vf4, vf1, vf3x
            vnop
            vnop
            vnop
            vadd.xyz vf5, vf4, vf2
            vnop
            vnop
            vnop
            sqc2 vf5, 0x0(pP)
        }
        float s = 0.25f * m_unk120;
        pP[3] = fRatio * (m_unk120 + (-s + (s + s) * ParticleRand01(m_unkD0)));
        pP[7] = m_unk110 + fRatioSq * (m_unk114 - m_unk110);
    }
}

// FUNCTION: 0x001F86B0 Create__15PParticleSparksFP23tagParticleSparksParamsfff
int PParticleSparks::Create(tagParticleSparksParams *pParams, float fA, float fB, float fC) {
    if (pParams == 0) CdsAssert("PParticleSparks.cpp", 0x26, "pParams");
    if (!PParticleSystem::Create(pParams->m_unk38, false)) {
        return 0;
    }
    m_unk0C = 0xE;
    m_unk30 = 0x48;
    memcpy(&m_unkE0, pParams, 0x60);
    ((float *)&m_unkE0)[0] += fA;
    ((float *)&m_unkE0)[1] += fB;
    ((float *)&m_unkE0)[2] += fC;
    *(u_long128 *)&m_unk150 = *(u_long128 *)&m_unkE0;
    *(u_long128 *)&m_unk160 = *(u_long128 *)&m_unkE0;
    m_unk144 = 5.0f + 175.0f * (1.0f - m_unk124);
    m_unk148 = 0;
    m_unk170 = (int)(0.5f + (62315.0f + (-10989.0f * ((float)rand() / 2147483648.0f))));
    m_unk80 = ((float *)&m_unk150)[0];
    m_unk84 = ((float *)&m_unk150)[1];
    m_unk88 = ((float *)&m_unk150)[2];
    m_unk8C = 0x3F800000;
    m_unk90 = m_unk128;
    m_unk94 = m_unk128;
    m_unk98 = m_unk128;
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
    sceVu0ScaleVectorXYZ((float *)&m_unkC0, (float *)((char *)this + 0x100), 1.0f / 255.0f);
    m_unkCC = 1.0f;
    m_unk140 = __nwa__FUi(m_unk04 << 5);
    if (m_unk140 == 0) {
        return 0;
    }
    return 1;
}

// FUNCTION: 0x001F88C0 __dt__15PParticleSparksFv
PParticleSparks::~PParticleSparks() {
    *(void **)this = __vt__15PParticleSparks;
    if (m_unk140 != 0) {
        __dla__FPv(m_unk140);
        m_unk140 = 0;
    }
}

// FUNCTION: 0x001F8940 __ct__15PParticleSparksFv
PParticleSparks::PParticleSparks() {
    *(void **)this = __vt__15PParticleSparks;
    m_unk140 = 0;
}
