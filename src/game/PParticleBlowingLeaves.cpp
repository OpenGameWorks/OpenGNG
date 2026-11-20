#include "types.h"
#include "PParticleBlowingLeaves.h"
#include "PGfxEngine.h"
#include "PDisplayList.h"

// TODO(header): foreign declarations
extern char gGfxEng[1504384];
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dla__FPv(void *);
extern "C" void __dl__FPv(void *);
extern "C" void *memset(void *, int, unsigned int);
extern "C" void *memcpy(void *, const void *, unsigned int);
extern "C" int rand(void);
extern unsigned char __vt__22PParticleBlowingLeaves[];
extern "C" void *__nwa__FUi(unsigned int);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void QwordCopy__FP1P1Ui(u_long128 *pDst, u_long128 *pSrc, unsigned int nQwords);
extern "C" void sceVu0ApplyMatrix(float *, float (*)[4], float *);
extern "C" void sceVu0Normalize(float *pDst, float *pSrc);
extern "C" void sceVu0AddVector(float *pDst, float *pA, float *pB);
extern "C" void sceVu0ScaleVectorXYZ(float *, float *, float);
void FastMath_RotateMatrix(float (*)[4][4], float (*)[4][4], float (*)[4], float (*)[4][4]);
void FastMath_ComputeMatrixLite(float (*)[4][4], float (*)[4], float (*)[4], float (*)[4], float (*)[4][4]);

// FUNCTION: 0x001FD130 GenerateLeafMeshData__22PParticleBlowingLeavesFv
void PParticleBlowingLeaves::GenerateLeafMeshData() {
    float blkA[24] = {
        0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.0f, 0.0f, 0.0f,
        0.5f, 1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 0.0f, 0.0f,
    };
    float blkB[24] = {
        -0.5f, 0.35f, -0.5f, 1.0f,
        -0.5f, 0.35f, 0.5f, 1.0f,
        0.0f, 0.0f, -0.5f, 1.0f,
        0.0f, 0.0f, 0.5f, 1.0f,
        0.5f, 0.35f, -0.5f, 1.0f,
        0.5f, 0.35f, 0.5f, 1.0f,
    };
    int blkC[24] = {
        128, 128, 128, 128, 128, 128, 128, 128,
        128, 128, 128, 128, 128, 128, 128, 128,
        128, 128, 128, 128, 128, 128, 128, 128,
    };
    void *pBuf = __nwa__FUi(0x970);
    if (pBuf == 0) {
        CdsAssert__FPciPc("PParticleBlowingLeaves.cpp", 0x19D, "apPacket");
    }
    ((int *)pBuf)[0] = 6;
    ((int *)pBuf)[1] = 0;
    ((int *)pBuf)[2] = 0;
    ((int *)pBuf)[3] = 0;
    QwordCopy__FP1P1Ui((u_long128 *)((char *)pBuf + 0x10), (u_long128 *)&blkA, 6);
    QwordCopy__FP1P1Ui((u_long128 *)((char *)pBuf + 0x330), (u_long128 *)&blkC, 6);
    QwordCopy__FP1P1Ui((u_long128 *)((char *)pBuf + 0x650), (u_long128 *)&blkB, 6);
    m_unkA54 = 0x970;
    m_unkA50 = pBuf;
}

// FUNCTION: 0x001FD290 ComputeWindAxes__22PParticleBlowingLeavesFPf
void PParticleBlowingLeaves::ComputeWindAxes(float *pWind) {
    float mtx[4][4];
    FastMath_RotateMatrix((float (*)[4][4])mtx, 0, (float (*)[4])pWind, 0);
    float vx[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
    float vy[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
    float vz[4] = { 0.0f, 0.0f, 1.0f, 1.0f };
    sceVu0ApplyMatrix(m_unkA10, mtx, vx);
    sceVu0ApplyMatrix(m_unkA20, mtx, vy);
    sceVu0ApplyMatrix(m_unkA30, mtx, vz);
    sceVu0Normalize(m_unkA10, m_unkA10);
    sceVu0Normalize(m_unkA20, m_unkA20);
    sceVu0Normalize(m_unkA30, m_unkA30);
}

struct PParticleBlowingLeaves::tagLeaf {
    float m_unk00;
    float m_unk04;
    float m_unk08;
    float m_unk0C;
    char _pad10[0x10];
    float m_unk20;
    float m_unk24;
    float m_unk28;
    float m_unk2C;
    float m_unk30;
    float m_unk34;
    float m_unk38;
    float m_unk3C;
    char _pad40[0x30];
};

// DRAFT: 0x001FD350 SpawnLeaf__22PParticleBlowingLeavesFPQ222PParticleBlowingLeaves7tagLeaf
// note: size 0x3B8 vs 0x39C, s2/s3 saved (original s0/s1 only); first VU0 block scheduled differently; LCG and float constants after the scale call unverified
void PParticleBlowingLeaves::SpawnLeaf(tagLeaf *pLeaf) {
    float v50[4];
    float v30[4];
    float v40[4];
    int sb;
    float s;
    unsigned int seed;
    int val;
    float r;

    s = -m_unk9F0;
    asm { mfc1 sb, s }
    {
        float *pA30 = m_unkA30;
        float *pE0 = m_unk9E0;
        float *p50 = v50;
        asm {
            lqc2 vf1, 0x0(pA30)
            lqc2 vf2, 0x0(pE0)
            qmtc2.i sb, vf3
            vmulx.xyzw vf4, vf1, vf3x
            vnop
            vnop
            vnop
            vadd.xyzw vf5, vf4, vf2
            vnop
            vnop
            vnop
            sqc2 vf5, 0x0(p50)
        }
    }

    s = -m_unk9C0[0];
    asm { mfc1 sb, s }
    {
        float *pA10 = m_unkA10;
        float *p50 = v50;
        float *p30 = v30;
        asm {
            lqc2 vf1, 0x0(pA10)
            lqc2 vf2, 0x0(p50)
            qmtc2.i sb, vf3
            vmulx.xyzw vf4, vf1, vf3x
            vnop
            vnop
            vnop
            vadd.xyzw vf5, vf4, vf2
            vnop
            vnop
            vnop
            sqc2 vf5, 0x0(p30)
        }
    }

    s = m_unk9C0[0];
    asm { mfc1 sb, s }
    {
        float *pA10 = m_unkA10;
        float *p50 = v50;
        float *p40 = v40;
        asm {
            lqc2 vf1, 0x0(pA10)
            lqc2 vf2, 0x0(p50)
            qmtc2.i sb, vf3
            vmulx.xyzw vf4, vf1, vf3x
            vnop
            vnop
            vnop
            vadd.xyzw vf5, vf4, vf2
            vnop
            vnop
            vnop
            sqc2 vf5, 0x0(p40)
        }
    }

    v30[1] = m_unk9E0[1] - m_unk9C0[1];
    v40[1] = m_unk9E0[1] + m_unk9C0[1];

    m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
    pLeaf->m_unk00 = (float)((m_unkD0 >> 16) & 0x7FFF);
    m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
    pLeaf->m_unk04 = (float)((m_unkD0 >> 16) & 0x7FFF);
    m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
    pLeaf->m_unk08 = (float)((m_unkD0 >> 16) & 0x7FFF);
    sceVu0ScaleVectorXYZ((float *)pLeaf, (float *)pLeaf, 3.0517578125e-5f);

    {
        float *p30 = v30;
        float *p40 = v40;
        float *pOut = (float *)pLeaf;
        asm {
            lqc2 vf1, 0x0(p30)
            lqc2 vf2, 0x0(p40)
            lqc2 vf3, 0x0(pOut)
            vsub.xyz vf4, vf2, vf1
            vnop
            vnop
            vnop
            vmul.xyz vf5, vf4, vf3
            vnop
            vnop
            vnop
            vadd.xyz vf3, vf5, vf1
            vnop
            vnop
            vnop
            sqc2 vf3, 0x0(pOut)
        }
    }

    pLeaf->m_unk0C = 1.0f;
    pLeaf->m_unk28 = 0.6f;
    pLeaf->m_unk2C = 0;

    m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
    r = (float)((m_unkD0 >> 16) & 0x7FFF) * 3.0517578125e-5f;
    pLeaf->m_unk24 = r * 0.3f + 0.7f;
    m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
    r = (float)((m_unkD0 >> 16) & 0x7FFF) * 3.0517578125e-5f;
    pLeaf->m_unk20 = r * 0.25f + 0.8f;
    m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
    r = (float)((m_unkD0 >> 16) & 0x7FFF) * 3.0517578125e-5f;
    pLeaf->m_unk30 = r * 240.0f + 240.0f;
    m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
    r = (float)((m_unkD0 >> 16) & 0x7FFF) * 3.0517578125e-5f;
    pLeaf->m_unk34 = m_unk9F4 * (r * 0.3f + 0.2f);
    pLeaf->m_unk30 = 2.0f * m_unk9F0 / pLeaf->m_unk34;
    pLeaf->m_unk38 = 0;
    m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
    r = (float)((m_unkD0 >> 16) & 0x7FFF) * 3.0517578125e-5f;
    pLeaf->m_unk3C = r * 0.05f + 0.05f;
}

// DRAFT: 0x001FD6F0 InitLeafRotations__22PParticleBlowingLeavesFv
// note: 60 words; register allocation differs (original a2=count, a3=offset, constant in a1; ours offset in a1, pointer in a3); tried quad store as scalars (65), (u_long128)0x3F800000<<96 (compile error), 64-bit shifted quad (60), declaration order swap (60)
void PParticleBlowingLeaves::InitLeafRotations() {
    int i = 0;
    int off = 0;
    do {
        char *pLeaf = (char *)this + off;
        i++;
        *(u_long128 *)(pLeaf + 0xF0) = (u_long128)((unsigned long long)0x3F800000 << 32);
        off += 0x70;
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pLeaf + 0x100) = 2.0f + 4.0f * (3.0517578125e-5f * (float)((m_unkD0 >> 16) & 0x7FFF));
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pLeaf + 0x104) = 1.0f + 1.0f * (3.0517578125e-5f * (float)((m_unkD0 >> 16) & 0x7FFF));
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        float f = 0.5f + 1.5f * (3.0517578125e-5f * (float)((m_unkD0 >> 16) & 0x7FFF));
        *(float *)(pLeaf + 0x110) = f;
        *(float *)(pLeaf + 0x114) = 1.0f;
        *(float *)(pLeaf + 0x118) = f;
        *(float *)(pLeaf + 0x11C) = 1.0f;
    } while (i < 0x14);
}

// FUNCTION: 0x001FD820 SetCameraPosRot__22PParticleBlowingLeavesFPA4_fPA4_f
void PParticleBlowingLeaves::SetCameraPosRot(float (*arg0)[4], float (*arg1)[4]) {
    sceVu0AddVector(m_unk9E0, m_unk9D0, (float *)arg0);
}

// DRAFT: 0x001FD850 Render__22PParticleBlowingLeavesFv
// note: 158 differing lines; this in s6 (orig s0), c.eq.s operand order and bc1t target at 0x2C-0x34, clamp structure 0x58-0xD8; tried fSum addend swap (159), flipped zero compare (158), char *pSelf (158)
void PParticleBlowingLeaves::Render() {
    if (m_unk9B0 != 0.0f) {
        float fSum = m_unkCC + m_unk9B0;
        if (fSum < 1.0f) {
            m_unkCC = fSum;
        }
        float fClamp = (fSum <= 0.0f) ? 0.0f : ((fSum < 1.0f) ? fSum : 1.0f);
        if (fClamp != 0.0f) {
            m_unkCC = fClamp;
        }
        if (fClamp == 1.0f) {
            m_unk9B0 = 0.0f;
        }
    }
    if (m_unk15 == 0) {
        return;
    }
    if (m_unkA4 == 0) {
        return;
    }
    if (m_unkCC == 0.0f) {
        return;
    }

    int nBatches = (m_unkE4 + 0x4F) / 0x50;
    ((PGfxEngine *)gGfxEng)->SetMaterial(m_unk10, (float *)((char *)this + 0xC0), true,
                                         (unsigned long)m_unk30, 0x5000D);
    ((PGfxEngine *)gGfxEng)->BeginFxInstances(m_unkA50, m_unkA54, false);

    int nRemain = m_unkE4;
    int nLeaf = 0;
    int nOff = 0;
    for (int nBatch = 0; nBatch < nBatches; nBatch++) {
        int nCount = (nRemain < 0x50) ? nRemain : 0x50;
        ((nCount * 0x60) < 0x2000) ? (void)0
            : CdsAssert__FPciPc("PParticleBlowingLeaves.cpp", 0x105,
                                "aiNumLeavesPerBatch * sizeof(VuFxInstance) < SPAD_TEMP_BUFFER_SIZE");
        nRemain -= nCount;
        for (int j = 0; j < nCount; j++) {
            char *pDst = (char *)0x70001000 + j * 0x60;
            char *pLeaf = (char *)this + nLeaf * 0x70;
            *(u_long128 *)(pDst + 0x00) = *(u_long128 *)(pLeaf + 0x120);
            *(u_long128 *)(pDst + 0x10) = *(u_long128 *)(pLeaf + 0x130);
            *(u_long128 *)(pDst + 0x20) = *(u_long128 *)(pLeaf + 0x140);
            *(u_long128 *)(pDst + 0x30) = *(u_long128 *)((char *)m_unkE0 + nOff);
            *(u_long128 *)(pDst + 0x40) = *(u_long128 *)((char *)m_unkE0 + nOff + 0x20);
            nLeaf++;
            if (nLeaf == 0x14) {
                nLeaf = 0;
            }
            nOff += 0x40;
        }
        PDisplayList *pList = *(PDisplayList **)((char *)gGfxEng + 0x154C80);
        pList->DrawFxInstances((struct tagVuFxInstance *)0x70001000, nCount, true);
    }
}

// DRAFT: 0x001FDB40 Animate__22PParticleBlowingLeavesFf
// note: DIFF 317: frame 0x80 vs 0x70 with extra sq s4 (loop-1 i*0x70 strength-reduced into s4, original recomputes from s1); this in s0 vs s3; separate epilogue exits; v60 zeroed not rodata copy; char-ptr index and function-scope pLeaf tried, no change
void PParticleBlowingLeaves::Animate(float fDelta) {
    int nSpawn;
    int i;
    int sb;
    float s;

    if (m_unk15 == 0) {
        return;
    }
    if (m_unkCC == 0.0f) {
        return;
    }
    if (fDelta == 0.0f) {
        return;
    }
    if (m_unkA5C) {
        m_unkA44 = m_unkA44 - fDelta;
        if (m_unkA44 <= 0.0f) {
            m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
            m_unkA44 = 60.0f * (10.0f + 10.0f * (3.0517578125e-05f * (float)((m_unkD0 >> 16) & 0x7FFF)));
            m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
            m_unkA48 = (-90.0f + 180.0f * (3.0517578125e-05f * (float)((m_unkD0 >> 16) & 0x7FFF))) / 600.0f;
            m_unkA4C = 600.0f;
        }
        if (m_unkA4C > 0.0f) {
            m_unkA4C = m_unkA4C - fDelta;
        }
        m_unkA00[1] = m_unkA00[1] + m_unkA48;
        ComputeWindAxes(m_unkA00);
    }

    nSpawn = 0;
    {
        float v60[4] = {0.0f, 0.0f, 0.0f, 0.0f};
        for (i = 0; i < 0x14; i++) {
            tagLeaf *pLeaf = (tagLeaf *)(m_unkF0 + i * 0x70);
            if (pLeaf == 0) {
                CdsAssert__FPciPc("PParticleBlowingLeaves.cpp", 0x8A, "apLeafRot");
            }
            sceVu0AddVector((float *)pLeaf, (float *)pLeaf, (float *)pLeaf->_pad10);
            if (pLeaf->m_unk00 > 180.0f) {
                pLeaf->m_unk00 = pLeaf->m_unk00 - 360.0f;
            }
            if (pLeaf->m_unk04 > 180.0f) {
                pLeaf->m_unk04 = pLeaf->m_unk04 - 360.0f;
            }
            FastMath_ComputeMatrixLite((float (*)[4][4])&pLeaf->m_unk30, (float (*)[4])&pLeaf->m_unk20,
                                       (float (*)[4])pLeaf, (float (*)[4])v60, (float (*)[4][4])0);
        }
    }

    for (i = 0; i < m_unkE4; i++) {
        tagLeaf *pLeaf = (tagLeaf *)((char *)m_unkE0 + (i << 6));
        if (pLeaf == 0) {
            CdsAssert__FPciPc("PParticleBlowingLeaves.cpp", 0x9F, "apLeaf");
        }
        if (pLeaf->m_unk30 > 0.0f) {
            float *pA30 = m_unkA30;
            s = pLeaf->m_unk34;
            asm { mfc1 sb, s }
            asm {
                lqc2 vf1, 0x0(pA30)
                lqc2 vf2, 0x0(pLeaf)
                qmtc2.i sb, vf3
                vmulx.xyzw vf4, vf1, vf3x
                vnop
                vnop
                vnop
                vadd.xyzw vf5, vf4, vf2
                vnop
                vnop
                vnop
                sqc2 vf5, 0x0(pLeaf)
            }

            pLeaf->m_unk38 = pLeaf->m_unk38 + pLeaf->m_unk3C;
            if (!(pLeaf->m_unk38 < 1.0f) || pLeaf->m_unk38 < -1.0f) {
                pLeaf->m_unk3C = -pLeaf->m_unk3C;
            }

            {
                float *pA20 = m_unkA20;
                s = 0.06f * pLeaf->m_unk38;
                asm { mfc1 sb, s }
                asm {
                    lqc2 vf1, 0x0(pA20)
                    lqc2 vf2, 0x0(pLeaf)
                    qmtc2.i sb, vf3
                    vmulx.xyzw vf4, vf1, vf3x
                    vnop
                    vnop
                    vnop
                    vadd.xyzw vf5, vf4, vf2
                    vnop
                    vnop
                    vnop
                    sqc2 vf5, 0x0(pLeaf)
                }
            }

            {
                float *pA10 = m_unkA10;
                s = 0.06f * pLeaf->m_unk38;
                asm { mfc1 sb, s }
                asm {
                    lqc2 vf1, 0x0(pA10)
                    lqc2 vf2, 0x0(pLeaf)
                    qmtc2.i sb, vf3
                    vmulx.xyzw vf4, vf1, vf3x
                    vnop
                    vnop
                    vnop
                    vadd.xyzw vf5, vf4, vf2
                    vnop
                    vnop
                    vnop
                    sqc2 vf5, 0x0(pLeaf)
                }
            }

            pLeaf->m_unk30 = pLeaf->m_unk30 - fDelta;
            if (pLeaf->m_unk30 > 20.0f) {
                if (pLeaf->m_unk2C < 1.0f) {
                    pLeaf->m_unk2C = pLeaf->m_unk2C + 0.05f;
                    if (pLeaf->m_unk2C > 1.0f) {
                        pLeaf->m_unk2C = 1.0f;
                    }
                }
            } else if (pLeaf->m_unk2C > 0.0f) {
                pLeaf->m_unk2C = pLeaf->m_unk2C - 0.05f;
                if (pLeaf->m_unk2C < 0.0f) {
                    pLeaf->m_unk2C = 0.0f;
                }
            }
        }
        nSpawn++;
        if (nSpawn < m_unkE4) {
            if (m_unk18) {
                SpawnLeaf(pLeaf);
            }
        } else {
            m_unk15 = 0;
            m_unk16 = m_unk17;
        }
    }
}

// DRAFT: 0x001FE090 Create__22PParticleBlowingLeavesFPfPfPfifb
// note: 107 differing lines; this in s4 (orig s0), pA/pB/pC/bFlag register mapping, loop branch 0x77 vs 0x73 words, 0x10-byte size gap; tried local for __nwa result (123)
int PParticleBlowingLeaves::Create(float *pA, float *pB, float *pC, int nNum, float fRate, bool bFlag) {
    if (PParticleSystem::Create(nNum, false) == 0) {
        return 0;
    }
    m_unkE4 = nNum;
    m_unk0C = 0x15;
    m_unk30 = 0x44;
    m_unkE0 = __nwa__FUi(nNum * 0x40);
    if (m_unkE0 == 0) {
        CdsAssert__FPciPc("PParticleBlowingLeaves.cpp", 0x40, "mpLeaves");
    }
    m_unk9F4 = fRate;
    memcpy(m_unk9D0, pA, 0x10);
    memcpy(m_unk9E0, pA, 0x10);
    memcpy(m_unk9C0, pB, 0x10);

    float fMax = (m_unk9C0[0] > m_unk9C0[1]) ? m_unk9C0[0] : m_unk9C0[1];
    if (fMax <= m_unk9C0[2]) {
        m_unk9F0 = m_unk9C0[2];
    } else if (m_unk9C0[0] <= m_unk9C0[1]) {
        m_unk9F0 = m_unk9C0[1];
    } else {
        m_unk9F0 = m_unk9C0[0];
    }

    memcpy(m_unkA00, pC, 0x10);
    ComputeWindAxes(pC);
    InitLeafRotations();
    m_unkA58 = (int)(0.5f + (13456.0f + 9689.0f * ((float)rand() / 2147483648.0f)));
    m_unkD0 = m_unkA58;

    int nOff = 0;
    for (int i = 0; i < m_unkE4; i++) {
        char *pLeaf = (char *)m_unkE0 + nOff;
        if (pLeaf == 0) {
            CdsAssert__FPciPc("PParticleBlowingLeaves.cpp", 0x53, "apLeaf");
        }
        SpawnLeaf((tagLeaf *)pLeaf);
        nOff += 0x40;
    }

    m_unkA40 = 900.0f;
    m_unkA44 = 900.0f;
    m_unkA48 = 0;
    m_unkA4C = 0;
    m_unkA5C = bFlag;
    m_unk9B0 = 0.0f;
    return 1;
}

// FUNCTION: 0x001FE2F0 __dt__22PParticleBlowingLeavesFv
extern "C" void *__dt__22PParticleBlowingLeavesFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PParticleBlowingLeaves *pSelf = (PParticleBlowingLeaves *)pThis;
        *(void **)pThis = __vt__22PParticleBlowingLeaves;
        if (pSelf->m_unkE0 != 0) {
            __dla__FPv(pSelf->m_unkE0);
            pSelf->m_unkE0 = 0;
        }
        if (pSelf->m_unkA50 != 0) {
            __dla__FPv(pSelf->m_unkA50);
            pSelf->m_unkA50 = 0;
        }
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001FE390 __ct__22PParticleBlowingLeavesFv
PParticleBlowingLeaves::PParticleBlowingLeaves() {
    *(void **)this = __vt__22PParticleBlowingLeaves;
    m_unkE0 = 0;
    m_unkE4 = 0;
    m_unkA50 = 0;
    m_unkA54 = 0;
    memset(m_unkF0, 0, 0x8C0);
    m_unk9B0 = 0;
    GenerateLeafMeshData();
}
