// FLAGS: -sdatathreshold 0
#include "BGCollision.h"

// TODO(header): foreign declarations
extern "C" void __dl__FPv(void *);
extern float vUp_1253[4];
extern float vGDown[4];
extern "C" void sceVu0SubVector(float *, float *, float *);
extern "C" float sceVu0InnerProduct(float *, float *);
extern "C" float sqrtf(float);
extern "C" void sceVu0ScaleVectorXYZ(float *, float *, float);
extern "C" void sceVu0AddVector(float *, float *, float *);
extern "C" void sceVu0ScaleVector(float *, float *, float);
extern "C" void sceVu0Normalize(float *, float *);
float FastMath_Fabs(float f);
float Fabs(float f);
struct STCollisionPoly;
struct STCollisionNode;
float SphereIntersect(STCollisionPoly *pPoly, float (*pSph)[4], float fRadius);
int FindGroundPos(STCollisionPoly *pPoly, float (*pOut)[4]);
int BoxLineCheck(float (*pBox)[2][4]);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void sceVu0ApplyMatrix(float *, float *, float *);
extern "C" void sceVu0InversMatrix(float *, float *);
void InversMatrix(float (*)[4][4], float (*)[4][4]);
#include "PCDFile.h"
#include "PMeshNode.h"
extern PCDFile gPFile;
extern "C" char *strcpy(char *, const char *);
extern "C" char *strcat(char *, const char *);
extern "C" unsigned int strlen(const char *);
extern "C" void *__nwa__FUi(unsigned int);
extern "C" void FlushCache(int);

// The game's assert evaluates the condition at runtime, so assert(!"msg") keeps the literal-address test.
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("BGCollision.cpp", line, #cond))

// DRAFT: 0x0016C8A0 CheckCeiling__11BGCollisionFPA4_f
// note: only the two lui/addiu words differ; the reloc target is vUp$1253, which C++ cannot name (vUp_1253 emitted).
int BGCollision::CheckCeiling(float (*pVec)[4])
{
    return CheckIntersectAnim(pVec, &vUp_1253, 0, 0x40) != 0;
}

#define CDS_ASSERT_TXT(line, cond, txt) ((cond) ? (void)0 : CdsAssert__FPciPc("BGCollision.cpp", line, txt))
#define BGS_H(p, off) (*(unsigned short *)((char *)(p) + (off)))
#define BGS_B(p, off) (*(unsigned char *)((char *)(p) + (off)))
#define BGS_F(p, off) (*(float *)((char *)(p) + (off)))
#define BGS_U(p, off) (*(unsigned int *)((char *)(p) + (off)))
#define BGS_P(p, off) (*(void **)((char *)(p) + (off)))

// DRAFT: 0x0016C8D0 BGIntersect__11BGCollisionFR5PVec3fUi
// note: DIFF 308 words; frame 0x180 vs original 0x170, grid-loop slots (rX/rZ) 0x10 high, sph/normalize path and node-loop shape differ; local reorder and inner-list rewrite did not change the count.
int BGCollision::BGIntersect(PVec3 &rPos, float fRadius, unsigned int nFlags)
{
    int nX;
    int nZ;
    float r;
    float sph[2][4];
    float nrm[4];
    float nrm2[4];
    float out[4];
    float e0[4];
    float e1[4];
    float mat[4][4];
    float box[2][4];
    char *pNode;
    char *pCell;

    if (m_unk40 != 0) {
        FindGrid((float (*)[4])&rPos, nX, nZ);
        if (!((unsigned int)nX < m_unk38 && (unsigned int)nZ < m_unk3C)) {
            return 0;
        }
        pCell = (char *)((int *)m_unk40)[nZ * m_unk38 + nX];
        if (pCell == 0) {
            return 0;
        }
        unsigned int nCount = BGS_U(pCell, 8);
        void **pItem = (void **)(pCell + 0xC);
        for (; nCount != 0; nCount--, pItem++) {
            STCollisionPoly *pPoly = (STCollisionPoly *)*pItem;
            if ((BGS_U(pPoly, 0xC) & nFlags) == 0) {
                continue;
            }
            *(u_long128 *)sph[0] = *(u_long128 *)&rPos;
            *(u_long128 *)sph[1] = *(u_long128 *)&rPos;
            r = SphereIntersect(pPoly, sph, fRadius * fRadius);
            if (r > 0.0f) {
                *(u_long128 *)nrm = *(u_long128 *)((char *)pPoly + 0x10);
                sceVu0Normalize(nrm2, nrm);
                sceVu0ScaleVector(out, nrm2, r);
                return 1;
            }
            sceVu0ScaleVector((float *)((char *)pPoly + 0x10), (float *)((char *)pPoly + 0x10), -1.0f);
            r = SphereIntersect(pPoly, sph, fRadius * fRadius);
            sceVu0ScaleVector((float *)((char *)pPoly + 0x10), (float *)((char *)pPoly + 0x10), -1.0f);
            if (r > 0.0f) {
                *(u_long128 *)nrm = *(u_long128 *)((char *)pPoly + 0x10);
                sceVu0Normalize(nrm2, nrm);
                sceVu0ScaleVector(out, nrm2, r);
                return 1;
            }
        }
    }

    m_unk70.m_unk4 = 0;
    pNode = (m_unk70.m_unk0 != 0) ? (char *)m_unk70.m_unk8[0] : 0;
    for (; pNode != 0; m_unk70.m_unk4++, pNode = (m_unk70.m_unk4 < m_unk70.m_unk0) ? (char *)m_unk70.m_unk8[m_unk70.m_unk4] : 0) {
        if (BGS_F(pNode, 0x2C) < 0.5f) {
            continue;
        }
        if (BGS_B(pNode, 0x3E) & 0x20) {
            continue;
        }
        CDS_ASSERT_TXT(0xC43, BGS_P(pNode, 0x104) != 0, "node->m_unk104 != 0");
        if ((nFlags & 0x40000000) && BGS_H(pNode, 0x100) != 0) {
            continue;
        }
        if (BGS_B(pNode, 0x3E) & 4) {
            InversMatrix(&mat, (float (*)[4][4])((char *)pNode + 0x40));
        } else {
            sceVu0InversMatrix((float *)mat, (float *)((char *)pNode + 0x40));
        }
        sceVu0ApplyMatrix(e0, (float *)mat, (float *)&rPos);
        sceVu0ApplyMatrix(e1, (float *)mat, (float *)&rPos);
        {
            float *pA = e0;
            float *pB = e1;
            asm {
                lqc2 vf26, 0x0(pA)
                lqc2 vf27, 0x0(pB)
                vsub.xyzw vf27, vf27, vf26
            }
        }
        *(u_long128 *)box[0] = *(u_long128 *)((char *)pNode + 0x110);
        *(u_long128 *)box[1] = *(u_long128 *)((char *)pNode + 0x120);
        box[1][0] = box[1][0] + fRadius;
        box[1][1] = box[1][1] + fRadius;
        box[1][2] = box[1][2] + fRadius;
        if (!BoxLineCheck(&box)) {
            continue;
        }
        {
            unsigned int nItems = BGS_U(BGS_P(pNode, 0x104), 8);
            void **pItem = (void **)((char *)BGS_P(pNode, 0x104) + 0xC);
            for (; nItems != 0; nItems--, pItem++) {
                STCollisionPoly *pPoly = (STCollisionPoly *)*pItem;
                if ((BGS_U(pPoly, 0xC) & nFlags) == 0) {
                    continue;
                }
                *(u_long128 *)sph[0] = *(u_long128 *)e0;
                *(u_long128 *)sph[1] = *(u_long128 *)e1;
                r = SphereIntersect(pPoly, sph, fRadius * fRadius);
                if (r > 0.0f) {
                    *(u_long128 *)nrm = *(u_long128 *)((char *)pPoly + 0x10);
                    nrm[3] = 0.0f;
                    sceVu0ApplyMatrix(nrm, (float *)((char *)pNode + 0x40), nrm);
                    sceVu0ScaleVector(out, nrm, r);
                    return 1;
                }
                sceVu0ScaleVector((float *)((char *)pPoly + 0x10), (float *)((char *)pPoly + 0x10), -1.0f);
                r = SphereIntersect(pPoly, sph, fRadius * fRadius);
                sceVu0ScaleVector((float *)((char *)pPoly + 0x10), (float *)((char *)pPoly + 0x10), -1.0f);
                if (r > 0.0f) {
                    *(u_long128 *)nrm = *(u_long128 *)((char *)pPoly + 0x10);
                    nrm[3] = 0.0f;
                    sceVu0ApplyMatrix(nrm, (float *)((char *)pNode + 0x40), nrm);
                    sceVu0ScaleVector(out, nrm, r);
                    return 1;
                }
            }
        }
    }
    return 0;
}

// DRAFT: 0x0016D2D0 BGDetectionAnim__11BGCollisionFPA2_A4_fP5PMat4P11SurfaceInfoiP9PMeshNode
// note: size 0x4cc vs 0x4ac, 300 words: prologue spills this/pMat (original keeps s5/fp), pCell in s0 not s3, sceVu0 call order differs; asm blocks ruled out (no-asm copy still differs in prologue).
void BGCollision::BGDetectionAnim(float (*pArr)[2][4], PMat4 *pMat, SurfaceInfo *pSurf, int nFlag, PMeshNode *pMesh)
{
    float vT100[4];
    float vT110[4];
    float vT120[4];
    float vT130[4];
    float vT140[4];
    float vT150[4];
    float vT160[4];
    float vT170[4];
    float fSum;
    float fS21;
    float fHit;
    float fT;
    char *pCell;
    char *pNode;
    char *pNodes;
    void **pCursor;
    unsigned int nCount;
    unsigned int nS1;
    unsigned int nS7;
    unsigned int nB0;
    unsigned int nD0;
    int nRet;

    fSum = BGS_F(pMat, 0x34) + (*pArr)[0][1];
    BGS_U(this, 0x74) = 0;
    if (BGS_U(this, 0x70) != 0) {
        pCell = *(char **)BGS_P(this, 0x78);
    } else {
        pCell = 0;
    }
    sceVu0SubVector(vT120, (float *)pSurf, (float *)((char *)pMat + 0x30));
    while (pCell != 0) {
        if (pCell != (char *)pMesh) {
            if (BGS_F(pCell, 0x2C) >= 1.0f || (*(unsigned char *)(pCell + 0x3E) & 0x20)) {
                CDS_ASSERT(0x930, BGS_P(pCell, 0x104));
                nRet = AreaCheckSub((float (*)[2][4])(pCell + 0x110), (float (*)[4][4])(pCell + 0x40), pArr, (float (*)[4][4])pMat, nFlag, *(unsigned char *)(pCell + 0x3E) & 4);
                if (nRet != 0) {
                    nB0 = (nRet & 1) ? (BGS_U(pSurf, 0x4C) & 0x110041) : 0;
                    nD0 = (nRet & 2) ? (BGS_U(pSurf, 0x4C) & 0x8098) : 0;
                    {
                        float *pV = vT100;
                        asm {
                            vmulax.xyzw ACC, vf18, vf16x
                            vmadday.xyzw ACC, vf19, vf16y
                            vmaddaz.xyzw ACC, vf20, vf16z
                            vmaddw.xyzw vf1, vf21, vf16w
                            lqc2 vf2, 0x20(pV)
                            sqc2 vf1, 0x0(pV)
                            vmulax.xyzw ACC, vf22, vf2x
                            vmadday.xyzw ACC, vf23, vf2y
                            vmaddaz.xyzw ACC, vf24, vf2z
                            vmaddw.xyzw vf2, vf25, vf2w
                            vadd.xyzw vf1, vf1, vf2
                            sqc2 vf1, 0x10(pV)
                        }
                    }
                    fS21 = (*pArr)[1][2];
                    pNodes = (char *)BGS_P(pCell, 0x104);
                    pCursor = (void **)(pNodes + 0xC);
                    nCount = BGS_U(pNodes, 0x8);
                    fS21 = fS21 * fS21;
                    while (nCount != 0) {
                        pNode = (char *)*pCursor;
                        nS1 = BGS_U(pNode, 0xC);
                        *(u_long128 *)vT130 = *(u_long128 *)(pNode + 0x10);
                        nS7 = nS1 & nD0;
                        BGS_U(vT130, 0xC) = 0;
                        if (nS7 != 0) {
                            if ((nS7 & 0x8) == 0) {
                                fHit = SphereIntersect((STCollisionPoly *)pNode, (float (*)[4])vT100, fS21);
                                if (fHit != 0.0f) {
                                    BGS_P(pSurf, 0x44) = pNode;
                                    if (nS7 & 0x90) {
                                        BGS_P(pSurf, 0x40) = pCell;
                                    }
                                    sceVu0ScaleVector(vT150, vT130, fHit);
                                    asm {
                                        vadd.xyz vf26, vf26, vf6
                                    }
                                    sceVu0AddVector(vT100, vT100, vT150);
                                    BGS_U(vT100, 0xC) = 0x3F800000;
                                    sceVu0ApplyMatrix(vT160, (float *)(pCell + 0x40), vT130);
                                    sceVu0ScaleVector(vT150, vT160, fHit);
                                    sceVu0AddVector((float *)((char *)pMat + 0x30), (float *)((char *)pMat + 0x30), vT150);
                                    BGS_F(pSurf, 0x10) = BGS_F(pSurf, 0x10) + vT150[0];
                                    BGS_F(pSurf, 0x18) = BGS_F(pSurf, 0x18) + vT150[2];
                                }
                            }
                        }
                        if (nS1 & nB0) {
                            sceVu0ApplyMatrix(vT140, (float *)(pCell + 0x40), vT130);
                            if (vT140[1] > 0.0f) {
                                if (FindGroundPos((STCollisionPoly *)pNode, (float (*)[4])vT170) != 0) {
                                    sceVu0ApplyMatrix(vT140, (float *)(pCell + 0x40), vT170);
                                    fT = BGS_F(pMat, 0x34) + (*pArr)[0][1];
                                    if (nS1 & 0x110001) {
                                        if (vT140[1] > BGS_F(pSurf, 0x24)) {
                                            BGS_F(pSurf, 0x24) = vT140[1];
                                            BGS_U(pSurf, 0x48) = (BGS_U(pSurf, 0x48) & 0xFFEEFFFE) | nS1;
                                        }
                                    } else if (vT140[1] < fT && vT140[1] > BGS_F(pSurf, 0x14)) {
                                        BGS_F(pSurf, 0x14) = vT140[1];
                                        *(u_long128 *)((char *)pSurf + 0x30) = *(u_long128 *)vT170;
                                        BGS_P(pSurf, 0x2C) = pCell;
                                        BGS_P(pSurf, 0x20) = pNode;
                                        BGS_U(pSurf, 0x48) = (BGS_U(pSurf, 0x48) & 0x110001) | nS1;
                                    }
                                }
                            } else if ((BGS_U(pSurf, 0x4C) & 0x80000000) != 0) {
                                if (FindGroundPos((STCollisionPoly *)pNode, (float (*)[4])vT140) != 0) {
                                    sceVu0ApplyMatrix(vT140, (float *)(pCell + 0x40), vT140);
                                    if (vT140[1] < BGS_F(pSurf, 0x28) && fSum < vT140[1]) {
                                        BGS_F(pSurf, 0x28) = vT140[1];
                                    }
                                }
                            }
                        }
                        nCount--;
                        pCursor++;
                    }
                }
            }
        }
        BGS_U(this, 0x74) = BGS_U(this, 0x74) + 1;
        if (BGS_U(this, 0x74) < BGS_U(this, 0x70)) {
            pCell = *(char **)((char *)BGS_P(this, 0x78) + BGS_U(this, 0x74) * 4);
        } else {
            pCell = 0;
        }
    }
}

// DRAFT: 0x0016E1E0 BGDetectionST__11BGCollisionFPA2_A4_fP5PMat4P11SurfaceInfoi
// note: 270 words; original keeps pArr in fp and spills pMat/nFlag/this at 0xC8/0xC4/0xCC, ours uses fp=pMat and spills 0xBC/0xB8; frame 0x130 vs 0x140; vE0 at 0xE0 vs 0xD0; nCount spilled. Tried node-array-first and node-array-last local order (count unchanged).
void BGCollision::BGDetectionST(float (*pArr)[2][4], PMat4 *pMat, SurfaceInfo *pSurf, int nFlag)
{
    float vE0[4];
    float vF0[4];
    float vT100[4];
    float vG110[4];
    float vG120[4];
    STCollisionNode *pNodes[8];
    int i;
    int nCount;
    float f20;
    float f21;
    float f22;
    unsigned int nMask;

    if ((*pArr)[1][2] >= 16.0f) {
        (*pArr)[1][2] = 15.0f;
    }
    nCount = GridCheck(pArr, pMat, pNodes, 0);
    if (nCount != 0) {
        sceVu0ApplyMatrix(vE0, (float *)pMat, (float *)pArr);
        if (nFlag & 2) {
            nMask = BGS_U(pSurf, 0x4C) & 0x8098;
            f22 = (*pArr)[1][2];
            f22 = f22 * f22;
            f20 = BGS_F(pMat, 0x34) + (*pArr)[0][1];
            f21 = (*pArr)[1][1];
            sceVu0SubVector(vF0, (float *)pSurf, (float *)((char *)pMat + 0x30));
            sceVu0AddVector(vF0, vF0, vE0);
            for (i = 0; i < nCount; i++) {
                float *pNode = (float *)pNodes[i];
                if (Fabs(f20 - pNode[0]) < pNode[1] + f21) {
                    int nList = *(int *)((char *)pNode + 8);
                    STCollisionPoly **ppPoly = (STCollisionPoly **)((char *)pNode + 0xC);
                    for (; nList != 0; nList--, ppPoly++) {
                        STCollisionPoly *pPoly = *ppPoly;
                        unsigned int nFl = BGS_U(pPoly, 0xC) & nMask;
                        if (nFl != 0 && !(nFl & 8)) {
                            float fd = SphereIntersect(pPoly, (float (*)[4])vE0, f22);
                            if (fd != 0.0f) {
                                BGS_P(pSurf, 0x44) = pPoly;
                                if (nFl & 0x90) {
                                    *(u_long128 *)vT100 = *(u_long128 *)((char *)pPoly + 0x10);
                                    sceVu0ScaleVector(vT100, vT100, fd);
                                    *(int *)&vT100[3] = 0;
                                    sceVu0AddVector(vE0, vE0, vT100);
                                    BGS_F(pSurf, 0x10) = BGS_F(pSurf, 0x10) + vT100[0];
                                    BGS_F(pSurf, 0x18) = BGS_F(pSurf, 0x18) + vT100[2];
                                }
                            }
                        }
                    }
                }
            }
        }
        if (nFlag & 1) {
            sceVu0SubVector(vG110, vE0, (float *)this);
            if (vG110[0] >= 0.0f && vG110[2] >= 0.0f) {
                int nX = (int)(vG110[0] / m_unk30);
                int nZ = (int)(vG110[2] / m_unk34);
                if ((unsigned int)nX < m_unk38) {
                    if ((unsigned int)nZ < m_unk3C) {
                        int nEnt = *(int *)(m_unk40 + (nX << 2) + ((nZ * (int)m_unk38) << 2));
                        if (nEnt != 0) {
                            *(u_long128 *)vG110 = *(u_long128 *)vE0;
                            nMask = BGS_U(pSurf, 0x4C);
                            {
                                float *pG110 = vG110;
                                float *pDown = vGDown;
                                asm {
                                    lqc2 vf26, 0x0(pG110)
                                }
                                asm {
                                    lqc2 vf27, 0x0(pDown)
                                }
                            }
                            {
                                int nList = *(int *)(nEnt + 8);
                                STCollisionPoly **ppPoly = (STCollisionPoly **)(nEnt + 0xC);
                                for (; nList != 0; nList--, ppPoly++) {
                                    STCollisionPoly *pPoly = *ppPoly;
                                    unsigned int nF = BGS_U(pPoly, 0xC) & nMask;
                                    if (nF & 0x110041) {
                                        if (BGS_F(pPoly, 0x14) > 0.0f) {
                                            if (FindGroundPos(pPoly, (float (*)[4])vG120)) {
                                                f20 = vG120[1];
                                                if (nF & 0x110001) {
                                                    if (f20 > BGS_F(pSurf, 0x24)) {
                                                        BGS_F(pSurf, 0x24) = f20;
                                                        BGS_U(pSurf, 0x48) = (BGS_U(pSurf, 0x48) & 0xFFEEFFFE) | nF;
                                                    }
                                                } else if (f20 < vG110[1]) {
                                                    if (f20 > BGS_F(pSurf, 0x14)) {
                                                        *(u_long128 *)((char *)pSurf + 0x10) = *(u_long128 *)vG120;
                                                        BGS_P(pSurf, 0x20) = pPoly;
                                                        BGS_U(pSurf, 0x48) = (BGS_U(pSurf, 0x48) & 0x110001) | nF;
                                                    }
                                                }
                                            }
                                        } else if (BGS_U(pSurf, 0x4C) & 0x80000000) {
                                            if (FindGroundPos(pPoly, (float (*)[4])vG120)) {
                                                if (vG120[1] < BGS_F(pSurf, 0x28)) {
                                                    if (BGS_F(pMat, 0x34) + (*pArr)[0][1] < vG120[1]) {
                                                        BGS_F(pSurf, 0x28) = vG120[1];
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// DRAFT: 0x0016EDA0 BGDetection__11BGCollisionFPA2_A4_fP5PMat4fR11SurfaceInfoiP9PMeshNode
// note: 1 differing line: fLen compare at 0x24 emits c.eq.s f0,f12 (original f12,f0); tried !(fLen==0), 0.0f!=fLen, empty-then, all same.
void BGCollision::BGDetection(float (*pArr)[2][4], PMat4 *pMat, float fLen, SurfaceInfo &rSurf, int nFlag, PMeshNode *pMesh)
{
    char *pS = (char *)&rSurf;
    *(u_long128 *)(pS + 0x10) = *(u_long128 *)((char *)pMat + 0x30);
    *(int *)(pS + 0x20) = 0;
    *(int *)(pS + 0x48) = 0;
    *(int *)(pS + 0x44) = 0;
    *(float *)(pS + 0x14) = -1000.0f;
    *(float *)(pS + 0x24) = -1000.0f;
    *(float *)(pS + 0x28) = 1000.0f;
    *(int *)(pS + 0x2C) = 0;
    *(int *)(pS + 0x40) = 0;
    if (fLen != 0.0f) {
        float t = 0.5f * fLen;
        pArr[0][0][1] -= t;
        pArr[0][1][1] += FastMath_Fabs(t);
    }
    BGDetectionST(pArr, pMat, &rSurf, nFlag);
    BGDetectionAnim(pArr, pMat, &rSurf, nFlag, pMesh);
    float f1 = *(float *)(pS + 0x28);
    if (1000.0f == f1 || f1 < *(float *)(pS + 0x14)) {
        *(float *)(pS + 0x28) = -1000.0f;
    } else if (!(*(float *)(pS + 0x24) <= f1)) {
        *(float *)(pS + 0x24) = -1000.0f;
    }
    if (*(float *)(pS + 0x24) < *(float *)(pS + 0x14)) {
        *(int *)(pS + 0x48) &= 0xFFEEFFFE;
        *(float *)(pS + 0x24) = -1000.0f;
    }
}

// DRAFT: 0x0016EF20 GridCheck__11BGCollisionFPA2_A4_fP5PMat4PP15STCollisionNodePf
// note: 186 differing words; the neighbour-cell block and the register use of x/z and the 0.5f centre terms differ (original precomputes them early). Tried: separate vs merged Fabs checks (merged kept), nCount placement, x/z swap (192, rejected).
#define GC_NEIGHBOUR(CX, CZ) \
    if ((unsigned int)(CX) < m_unk38 && (unsigned int)(CZ) < m_unk3C) { \
        int nCell = ((int *)m_unk40)[(CZ) * m_unk38 + (CX)]; \
        if (nCell != 0) { \
            *ppOut++ = (STCollisionNode *)nCell; \
            nCount++; \
            if (pOut) { \
                pOut[0] = (m_unk0 + 0.5f * m_unk30) + (float)(CX) * m_unk30; \
                pOut[1] = (m_unk8 + 0.5f * m_unk34) + (float)(CZ) * m_unk34; \
                pOut += 2; \
            } \
        } \
    }

int BGCollision::GridCheck(float (*pArr)[2][4], PMat4 *pMat, STCollisionNode **ppOut, float *pOut)
{
    float a[4];
    float b[4];
    float f20 = pArr[0][1][2];
    int nCount;
    m_unk48 = f20;
    float f21 = m_unk20[0] + f20;
    float f22 = m_unk20[2] + f20;
    sceVu0ApplyMatrix(a, (float *)pMat, (float *)pArr);
    sceVu0SubVector(b, a, m_unk10);
    if (!(Fabs(b[0]) < f21) || !(Fabs(b[2]) < f22)) { return 0; }
    a[0] -= f20;
    a[2] -= f20;
    sceVu0SubVector(a, a, (float *)this);
    nCount = 0;
    f20 *= 2.0f;
    int x = (a[0] < 0.0f) ? -1 : (int)(a[0] / m_unk30);
    int z = (a[2] < 0.0f) ? -1 : (int)(a[2] / m_unk34);
    GC_NEIGHBOUR(x, z)
    int x2 = (int)((a[0] + f20) / m_unk30);
    if (x2 != x) { GC_NEIGHBOUR(x2, z) }
    int z2 = (int)((a[2] + f20) / m_unk34);
    if (z2 != z) { GC_NEIGHBOUR(x, z2) }
    if (x2 != x && z2 != z) { GC_NEIGHBOUR(x2, z2) }
    return nCount;
}
#undef GC_NEIGHBOUR

// FUNCTION: 0x0016F340 FindGroundPos__FP15STCollisionPolyPA4_f
int FindGroundPos(STCollisionPoly *pPoly, float (*pOut)[4])
{
    asm {
        .set noreorder
        lw v1, 0x0(a0)
        lqc2 vf3, 0x10(a0)
        lqc2 vf4, 0x0(v1)
        vmul.xyz vf9, vf27, vf3
        lw v1, 0x4(a0)
        vsub.xyz vf7, vf26, vf4
        vmul.xyz vf8, vf7, vf3
        vaddy.x vf9, vf9, vf9y
        vaddz.x vf9, vf9, vf9z
        vaddy.x vf8, vf8, vf8y
        vaddz.x vf8, vf8, vf8z
        vdiv Q, vf8x, vf9x
        lqc2 vf5, 0x0(v1)
        lw v1, 0x8(a0)
        lqc2 vf6, 0x0(v1)
        vsub.xyz vf5, vf5, vf4
        vsub.xyz vf6, vf6, vf4
        vwaitq
        vmulq.xyz vf8, vf27, Q
        vsub.xyz vf7, vf7, vf8
        vmul.xyz vf9, vf6, vf6
        vmul.xyz vf13, vf5, vf5
        vaddy.x vf9, vf9, vf9y
        vaddz.x vf9, vf9, vf9z
        vaddy.x vf13, vf13, vf13y
        vaddz.x vf13, vf13, vf13z
        vmax.x vf3, vf9, vf13
        vrsqrt Q, vf5w, vf3x
        lui v1, 0xB3D6
        ori v1, v1, 0xBF95
        mtc1 v1, f1
        vwaitq
        vmulq.xyz vf5, vf5, Q
        vmulq.xyz vf6, vf6, Q
        vmulq.xyz vf7, vf7, Q
        vmul.xyz vf8, vf5, vf6
        vmul.xyz vf9, vf6, vf6
        vmul.xyz vf10, vf5, vf7
        vmul.xyz vf11, vf6, vf7
        vaddy.x vf8, vf8, vf8y
        vaddz.x vf8, vf8, vf8z
        vaddy.x vf9, vf9, vf9y
        vaddz.x vf9, vf9, vf9z
        vaddy.x vf10, vf10, vf10y
        vaddz.x vf10, vf10, vf10z
        vaddy.x vf11, vf11, vf11y
        vaddz.x vf11, vf11, vf11z
        vmula.x ACC, vf9, vf10
        vmsub.x vf12, vf8, vf11
        qmfc2.ni v1, vf12
        mtc1 v1, f0
        paddub v0, zero, zero
        c.lt.s f0, f1
        bc1tl fgp_ret
        nop
        vmul.xyz vf13, vf5, vf5
        vaddy.x vf13, vf13, vf13y
        vaddz.x vf13, vf13, vf13z
        vmula.x ACC, vf13, vf11
        vmsub.x vf14, vf8, vf10
        qmfc2.ni v1, vf14
        mtc1 v1, f0
        c.lt.s f0, f1
        bc1tl fgp_ret
        nop
        vaddx.x vf12, vf12, vf14x
        vmula.x ACC, vf13, vf9
        vmsub.x vf13, vf8, vf8
        vabs.x vf13, vf13
        vsub.x vf10, vf13, vf12
        qmfc2.ni v1, vf10
        mtc1 v1, f0
        c.lt.s f0, f1
        bc1tl fgp_ret
        nop
        .word 0x4A0303BD
        addi v0, zero, 0x1
        vwaitq
        vmulq.xyz vf7, vf7, Q
        vadd.xyzw vf7, vf7, vf4
        vmove.w vf7, vf0
        sqc2 vf7, 0x0(a1)
    fgp_ret:
        jr ra
        nop
    }
}

// DRAFT: 0x0016F490 GetGround__11BGCollisionFPA4_fUi
// note: 109 differing lines. vf26/vf27 loads in asm (vGDown via C pointer; asm symbol form rejected); frame 0xC0 vs 0x90 (loop n/pp kept in s-regs across the FindGroundPos call), sqrt.s/c1 hit-scale path and d[] vGDown load absent.
int BGCollision::GetGround(float (*pArr)[4], unsigned int nFlags)
{
    float fBest = -1000.0f;
    unsigned int nRet = 0;
    float out[4];
    float d[4];
    int nX;
    int nZ;
    if (m_unk40 != 0 && FindGrid(pArr, nX, nZ) != 0) {
        int *pBlk = *(int **)((char *)m_unk40 + nX * 4 + nZ * m_unk38 * 4);
        if (pBlk != 0) {
            float *pG = vGDown;
            asm {
                lqc2 vf26, 0x0(pArr)
                lqc2 vf27, 0x0(pG)
            }
            int n = pBlk[2];
            STCollisionPoly **pp = (STCollisionPoly **)(pBlk + 3);
            while (n != 0) {
                STCollisionPoly *pPoly = *pp;
                if ((*(unsigned int *)((char *)pPoly + 0xC) & nFlags) &&
                    !(*(float *)((char *)pPoly + 0x14) <= 0.0f) &&
                    FindGroundPos(pPoly, (float (*)[4])out) != 0 &&
                    out[1] <= pArr[0][1] && !(out[1] <= fBest)) {
                    nRet = *(unsigned int *)((char *)pPoly + 0xC);
                    fBest = out[1];
                }
                n--;
                pp++;
            }
        }
    }
    d[0] = 0.0f;
    d[1] = fBest - pArr[0][1];
    d[2] = 0.0f;
    d[3] = 0.0f;
    float inner = sceVu0InnerProduct(d, d);
    float slot = inner;
    STCollisionPoly *hit = FindIntersectAnim(pArr, (float (*)[4])d, slot, nFlags, 0);
    if (hit != 0) {
        nRet = *(unsigned int *)((char *)hit + 0xC);
        sceVu0ScaleVectorXYZ(d, d, sqrtf(slot) / sqrtf(inner));
    }
    pArr[0][1] += d[1];
    return nRet;
}

struct BGAnimObj {
    char _pad00[0x4];
    unsigned int m_unk4;        // 0x004 type id, 0x207 selects a node
};

struct BGAnimNode {
    char _pad00[0x24];
    BGAnimObj *m_unk24;         // 0x024 object, type id at +4
    char _pad28[0x4];
    float m_unk2C;              // 0x02C compared with 0.5f
    char _pad30[0xE];
    unsigned char m_unk3E;      // 0x03E flags, bit 2 selects InversMatrix
    char _pad3F[0x1];
    float m_unk40[4][4];        // 0x040 matrix inverted into the local copy
    char _pad80[0x80];
    unsigned short m_unk100;    // 0x100 must be zero when bit 30 is set
    char _pad102[0x2];
    void *m_unk104;             // 0x104 collision map
    char _pad108[0x8];
    float m_unk110[2][4];       // 0x110 box
};

struct BGAnimMap {
    char _pad00[0x8];
    unsigned int m_unk8;        // 0x008 polygon count
    STCollisionPoly *m_unkC[1]; // 0x00C polygon pointers
};

// DRAFT: 0x0016F690 FindIntersectAnim__11BGCollisionFPA4_fPA4_fRfUiPA4_f
// note: 163 words differ (size 0x2e4 vs 0x304): frame 0x140 vs 0x150, pB/rT spill slots, entry branch, and the VU0 lqc2 pair before BoxLineCheck (not expressible in C); tried while and for loop shapes, and (void)&pB, all 163
STCollisionPoly *BGCollision::FindIntersectAnim(float (*pA)[4], float (*pB)[4], float &rT, unsigned int nFlags, float (*pOut)[4])
{
    float mat[4][4];
    float vA[4];
    float vB[4];
    float vG[4];
    float vD[4];
    STCollisionPoly *pRet = 0;
    float f20 = 1.0f;
    float f21;

    m_unk70.m_unk4 = 0;
    BGAnimNode *pNode = (m_unk70.m_unk0 != 0) ? (BGAnimNode *)m_unk70.m_unk8[0] : 0;
    while (pNode != 0) {
        if (!(pNode->m_unk2C < 0.5f) && !(pNode->m_unk3E & 0x20)) {
            BGAnimObj *pObj = pNode->m_unk24;
            unsigned int nType = (pObj != 0) ? pObj->m_unk4 : 0;
            if (nType == 0x207) {
                if (pNode->m_unk104 == 0) {
                    CdsAssert__FPciPc("BGCollision.cpp", 0x2DB, "pNode->GetCollisionMap()");
                }
                if (!(nFlags & 0x40000000) || pNode->m_unk100 == 0) {
                    if (pNode->m_unk3E & 4) {
                        InversMatrix(&mat, &pNode->m_unk40);
                    } else {
                        sceVu0InversMatrix((float *)mat, (float *)pNode->m_unk40);
                    }
                    sceVu0ApplyMatrix(vA, (float *)mat, (float *)pA);
                    sceVu0ApplyMatrix(vB, (float *)mat, (float *)pB);
                    if (BoxLineCheck(&pNode->m_unk110)) {
                        f21 = f20 * sceVu0InnerProduct(vB, vB);
                        BGAnimMap *pMap = (BGAnimMap *)pNode->m_unk104;
                        unsigned int n = pMap->m_unk8;
                        STCollisionPoly **pp = pMap->m_unkC;
                        for (; n != 0; --n, ++pp) {
                            STCollisionPoly *pPoly = *pp;
                            unsigned int s3 = *(unsigned int *)((char *)pPoly + 0xC) & nFlags;
                            if (s3 != 0 && FindGroundPos(pPoly, (float (*)[4])vG) != 0) {
                                sceVu0SubVector(vD, vG, vA);
                                if (!(sceVu0InnerProduct(vD, vB) < 0.0f)) {
                                    float f0 = sceVu0InnerProduct(vD, vD);
                                    if (!(f0 <= 1.0f) && f0 < f21) {
                                        f20 = f0 / f21;
                                        pRet = pPoly;
                                        if (pOut != 0) {
                                            sceVu0ApplyMatrix((float *)pOut, (float *)mat, (float *)((char *)pPoly + 0x10));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        unsigned int nIdx = m_unk70.m_unk4 + 1;
        m_unk70.m_unk4 = nIdx;
        pNode = (nIdx < m_unk70.m_unk0) ? (BGAnimNode *)m_unk70.m_unk8[nIdx] : 0;
    }
    if (pRet != 0) {
        rT *= f20;
    }
    return pRet;
}

// DRAFT: 0x0016F9A0 FindIntersectST__11BGCollisionFiiPA4_fPA4_fRfUi
// note: 101 differing lines. vf26/vf27 asm loads before BoxLineCheck tried, count unchanged; prologue saves and s-reg set differ.
STCollisionPoly *BGCollision::FindIntersectST(int nX, int nZ, float (*pA)[4], float (*pB)[4], float &rT, unsigned int nFlags)
{
    STCollisionPoly *pRet = 0;
    if ((unsigned int)nX < m_unk38 && (unsigned int)nZ < m_unk3C) {
        int *pBlk = *(int **)((char *)m_unk40 + nX * 4 + nZ * m_unk38 * 4);
        if (pBlk != 0) {
            *(float *)((char *)this + 0x54) = *(float *)pBlk;
            *(float *)((char *)this + 0x64) = *((float *)pBlk + 1);
            if (BoxLineCheck((float (*)[2][4])((char *)this + 0x50))) {
                int n = pBlk[2];
                STCollisionPoly **pp = (STCollisionPoly **)(pBlk + 3);
                while (n != 0) {
                    STCollisionPoly *pPoly = *pp;
                    if (*(unsigned int *)((char *)pPoly + 0xC) & nFlags) {
                        if (sceVu0InnerProduct((float *)pB, (float *)((char *)pPoly + 0x10)) < 0.0f) {
                            float out[4];
                            float diff[4];
                            if (FindGroundPos(pPoly, (float (*)[4])out) != 0) {
                                sceVu0SubVector(diff, out, (float *)pA);
                                if (!(sceVu0InnerProduct(diff, (float *)pB) < 0.0f)) {
                                    float fd = sceVu0InnerProduct(diff, diff);
                                    if (fd > 1.0f && fd < rT) {
                                        rT = fd;
                                        pRet = pPoly;
                                    }
                                }
                            }
                        }
                    }
                    n--;
                    pp++;
                }
            }
        }
    }
    return pRet;
}

// DRAFT: 0x0016FB60 FindIntersect__11BGCollisionFR5PVec3R5PVec3UiPA4_f
// note: DIFF 149; prologue saves and nRet=0 placement (hoisted, DIFF 173 when moved before m_unk40) still differ; pF/pT locals replaced by reference casts (152 to 149)
int BGCollision::FindIntersect(PVec3 &rFrom, PVec3 &rTo, unsigned int nFlags, float (*pOut)[4])
{
    float diff[4];
    float fT;
    int x0, z0, x1, z1;
    int nRet = 0;
    ((float *)&rTo)[3] = 1.0f;
    ((float *)&rFrom)[3] = 1.0f;
    sceVu0SubVector(diff, ((float *)&rTo), ((float *)&rFrom));
    float fLen = sceVu0InnerProduct(diff, diff);
    fT = fLen;
    if (fLen > 10000.0f) {
        sceVu0ScaleVector(diff, diff, 100.0f / sqrtf(fLen));
        sceVu0AddVector(((float *)&rTo), ((float *)&rFrom), diff);
        fT = 10000.0f;
    }
    if (m_unk40 != 0) {
        FindGrid((float (*)[4])((float *)&rFrom), x0, z0);
        m_unk50 = m_unk0 + ((float)x0 + 0.5f) * m_unk30;
        m_unk58 = m_unk8 + ((float)z0 + 0.5f) * m_unk34;
        FindGrid((float (*)[4])((float *)&rTo), x1, z1);
        bool bFlag = !(Fabs(diff[0]) < Fabs(diff[2]));
        for (;;) {
            STCollisionPoly *pPoly = FindIntersectST(x0, z0, (float (*)[4])((float *)&rFrom), (float (*)[4])diff, fT, nFlags);
            if (pPoly != 0) {
                nRet = 1;
                sceVu0ScaleVectorXYZ(diff, diff, fT / sqrtf(fT));
                sceVu0AddVector(((float *)&rTo), ((float *)&rFrom), diff);
                if (pOut != 0) {
                    *(u_long128 *)pOut = *(u_long128 *)((char *)pPoly + 0x10);
                }
                break;
            }
            int dx = x1 - x0;
            int dz = z1 - z0;
            if (dx == 0 && dz == 0) {
                break;
            }
            FindNextGrid(x0, z0, dx, dz, (float (*)[4])((float *)&rFrom), (float (*)[4])diff, bFlag);
        }
    }
    if (FindIntersectAnim((float (*)[4])((float *)&rFrom), (float (*)[4])diff, fT, nFlags, pOut)) {
        sceVu0ScaleVectorXYZ(diff, diff, fT / sqrtf(fT));
        sceVu0AddVector(((float *)&rTo), ((float *)&rFrom), diff);
        return 1;
    }
    return nRet;
}

// FUNCTION: 0x0016FE70 FindNextGrid__11BGCollisionFRiRiiiPA4_fPA4_fb
void BGCollision::FindNextGrid(int &rX, int &rZ, int nDX, int nDZ, float (*pA)[4], float (*pB)[4], bool bFlag)
{
    float tmp[4];
    float fX0 = m_unk0 + (float)rX * m_unk30;
    float fZ0 = m_unk8 + (float)rZ * m_unk34;
    float fX;
    float fZ;

    if (bFlag) {
        fX = (pB[0][0] < 0.0f) ? fX0 : fX0 + m_unk30;
        sceVu0ScaleVector(tmp, (float *)pB, (fX - pA[0][0]) / pB[0][0]);
        sceVu0AddVector(tmp, (float *)pA, tmp);
        tmp[0] = fX;
        if (tmp[2] < fZ0 || tmp[2] > fZ0 + m_unk34) {
            fZ = (pB[0][2] < 0.0f) ? fZ0 : fZ0 + m_unk34;
            sceVu0ScaleVector(tmp, (float *)pB, (fZ - pA[0][2]) / pB[0][2]);
            sceVu0AddVector(tmp, (float *)pA, tmp);
            tmp[2] = fZ;
        }
    } else {
        fZ = (pB[0][2] < 0.0f) ? fZ0 : fZ0 + m_unk34;
        sceVu0ScaleVector(tmp, (float *)pB, (fZ - pA[0][2]) / pB[0][2]);
        sceVu0AddVector(tmp, (float *)pA, tmp);
        tmp[2] = fZ;
        if (tmp[0] < fX0 || tmp[0] > fX0 + m_unk30) {
            fX = (pB[0][0] < 0.0f) ? fX0 : fX0 + m_unk30;
            sceVu0ScaleVector(tmp, (float *)pB, (fX - pA[0][0]) / pB[0][0]);
            sceVu0AddVector(tmp, (float *)pA, tmp);
            tmp[0] = fX;
        }
    }

    if (nDX != 0) {
        if (tmp[0] <= fX0) {
            rX--;
            m_unk50 -= m_unk30;
        } else if (tmp[0] >= fX0 + m_unk30) {
            rX++;
            m_unk50 += m_unk30;
        }
    }
    if (nDZ != 0) {
        if (tmp[2] <= fZ0) {
            rZ--;
            m_unk58 -= m_unk34;
        } else if (tmp[2] >= fZ0 + m_unk34) {
            rZ++;
            m_unk58 += m_unk34;
        }
    }
}

// FUNCTION: 0x001701E0 FindGrid__11BGCollisionFPA4_fRiRi
int BGCollision::FindGrid(float (*pArr)[4], int &rX, int &rZ)
{
    float diff[4];
    sceVu0SubVector(diff, pArr[0], (float *)this);
    rX = (int)(diff[0] / m_unk30);
    if (!(m_unk0 + (float)rX * m_unk30 <= pArr[0][0])) {
        rX--;
    }
    rZ = (int)(diff[2] / m_unk34);
    if (!(m_unk8 + (float)rZ * m_unk34 <= pArr[0][2])) {
        rZ--;
    }
    int ok = (unsigned int)rX < m_unk38;
    if (ok) {
        ok = (unsigned int)rZ < m_unk3C;
    }
    return ok;
}

// DRAFT: 0x00170300 CheckIntersectAnim__11BGCollisionFPA4_fPA4_fPA4_fUi
// note: 2 lqc2 VU loads before BoxLineCheck are not expressible in C; test
int BGCollision::CheckIntersectAnim(float (*pA)[4], float (*pB)[4], float (*pC)[4], unsigned int nFlags)
{
    float mat[4][4];
    float vA[4];
    float vB[4];
    float vC[4];
    float vG[4];
    float vD[4];
    float f20;

    m_unk70.m_unk4 = 0;
    BGAnimNode *pNode = (m_unk70.m_unk0 != 0) ? (BGAnimNode *)m_unk70.m_unk8[0] : 0;
    while (pNode != 0) {
        if (pNode->m_unk104 == 0) {
            CdsAssert__FPciPc("BGCollision.cpp", 0x1C4, "pNode->GetCollisionMap()");
        }
        if (pNode->m_unk3E & 4) {
            InversMatrix(&mat, &pNode->m_unk40);
        } else {
            sceVu0InversMatrix((float *)mat, (float *)pNode->m_unk40);
        }
        sceVu0ApplyMatrix(vA, (float *)mat, (float *)pA);
        sceVu0ApplyMatrix(vB, (float *)mat, (float *)pB);
        if (pC != 0) {
            sceVu0ApplyMatrix(vC, (float *)mat, (float *)pC);
        }
        if (BoxLineCheck(&pNode->m_unk110)) {
            f20 = sceVu0InnerProduct(vB, vB);
            BGAnimMap *pMap = (BGAnimMap *)pNode->m_unk104;
            unsigned int n = pMap->m_unk8;
            STCollisionPoly **pp = pMap->m_unkC;
            for (; n != 0; --n, ++pp) {
                STCollisionPoly *pPoly = *pp;
                unsigned int s3 = *(unsigned int *)((char *)pPoly + 0xC) & nFlags;
                if (s3 != 0 && !(s3 & 0x20) &&
                    (pC == 0 || sceVu0InnerProduct(vC, (float *)((char *)pPoly + 0x10)) <= -0.5f) &&
                    FindGroundPos(pPoly, (float (*)[4])vG) != 0) {
                    sceVu0SubVector(vD, vG, vA);
                    if (!(sceVu0InnerProduct(vB, vD) < 0.0f)) {
                        float f0 = sceVu0InnerProduct(vD, vD);
                        if (!(f0 <= 1.0f) && f0 < f20) {
                            return (int)s3;
                        }
                    }
                }
            }
        }
        unsigned int nIdx = m_unk70.m_unk4 + 1;
        m_unk70.m_unk4 = nIdx;
        pNode = (nIdx < m_unk70.m_unk0) ? (BGAnimNode *)m_unk70.m_unk8[nIdx] : 0;
    }
    return 0;
}

// DRAFT: 0x00170580 CheckIntersectST__11BGCollisionFiiPA4_fPA4_fPA4_fUi
// note: 112 differing lines. vf26/vf27 loads in asm before BoxLineCheck (was 114); frame 0x90 and saved s-regs differ (BoxLineCheck clobber set unknown to the compiler).
int BGCollision::CheckIntersectST(int nX, int nZ, float (*pA)[4], float (*pB)[4], float (*pC)[4], unsigned int nFlags)
{
    if ((unsigned int)nX >= m_unk38 || (unsigned int)nZ >= m_unk3C) {
        return 0;
    }
    int *pBlk = *(int **)((char *)m_unk40 + nX * 4 + nZ * m_unk38 * 4);
    if (pBlk == 0) {
        return 0;
    }
    *(float *)((char *)this + 0x54) = *(float *)pBlk;
    *(float *)((char *)this + 0x64) = *((float *)pBlk + 1);
    asm {
        lqc2 vf26, 0x0(pA)
        lqc2 vf27, 0x0(pB)
    }
    if (!BoxLineCheck((float (*)[2][4])((char *)this + 0x50))) {
        return 0;
    }
    float fLenSq = sceVu0InnerProduct((float *)pB, (float *)pB);
    int n = pBlk[2];
    STCollisionPoly **pp = (STCollisionPoly **)(pBlk + 3);
    while (n != 0) {
        STCollisionPoly *pPoly = *pp;
        unsigned int nPolyFlags = *(unsigned int *)((char *)pPoly + 0xC) & nFlags;
        if (nPolyFlags != 0 && (nPolyFlags & 0x20) == 0) {
            if (pC == 0 || sceVu0InnerProduct((float *)pC, (float *)((char *)pPoly + 0x10)) <= -0.5f) {
                float out[4];
                float diff[4];
                if (FindGroundPos(pPoly, (float (*)[4])out) != 0) {
                    sceVu0SubVector(diff, out, (float *)pA);
                    if (!(sceVu0InnerProduct((float *)pB, diff) < 0.0f)) {
                        float fd = sceVu0InnerProduct(diff, diff);
                        if (fd > 1.0f && fd < fLenSq) {
                            return nPolyFlags;
                        }
                    }
                }
            }
        }
        n--;
        pp++;
    }
    return 0;
}

// FUNCTION: 0x00170760 CheckIntersect__11BGCollisionFRA4_fRA4_fPA4_fUi
int BGCollision::CheckIntersect(float (&pA)[4], float (&pB)[4], float (*pC)[4], unsigned int nFlags)
{
    float diff[4];
    int nX0;
    int nZ0;
    int nX1;
    int nZ1;
    int dx;
    int dz;
    int ret;
    bool bFlag;

    sceVu0SubVector(diff, pB, pA);
    diff[3] = 0.0f;
    ret = 0;
    if (m_unk40 != 0) {
        FindGrid(&pA, nX0, nZ0);
        m_unk50 = m_unk0 + (0.5f + (float)nX0) * m_unk30;
        m_unk58 = m_unk8 + (0.5f + (float)nZ0) * m_unk34;
        FindGrid(&pB, nX1, nZ1);
        float fA = Fabs(diff[0]);
        bFlag = fA >= Fabs(diff[2]);
        for (;;) {
            ret = CheckIntersectST(nX0, nZ0, &pA, (float (*)[4])&diff, pC, nFlags);
            if (ret != 0) {
                break;
            }
            dx = nX1 - nX0;
            dz = nZ1 - nZ0;
            if (dx != 0 || dz != 0) {
                FindNextGrid(nX0, nZ0, dx, dz, &pA, (float (*)[4])&diff, bFlag);
            } else {
                break;
            }
        }
    }
    if (ret == 0) {
        ret = CheckIntersectAnim(&pA, (float (*)[4])&diff, pC, nFlags);
    }
    return ret;
}

// FUNCTION: 0x00170910 BoxLineCheck__FPA2_A4_f
int BoxLineCheck(float (*pBox)[2][4])
{
    asm {
        .set noreorder
        lqc2 vf3, 0x0(a0)
        lqc2 vf8, 0x10(a0)
        vmove.xyzw vf4, vf27
        lui v0, 0x3F00
        qmtc2.ni v0, vf1
        vmulx.xyz vf4, vf4, vf1x
        vadd.xyz vf1, vf4, vf26
        vsub.xyz vf1, vf1, vf3
        vabs.xyz vf2, vf1
        vabs.xyz vf9, vf4
        vadd.xyz vf9, vf9, vf8
        vsub.xyz vf9, vf9, vf2
        qmfc2.ni t0, vf9
        pcgtw t0, zero, t0
        bnez t0, box_ret
        addi v0, zero, 0x0
        prot3w t0, t0
        bnez t0, box_ret
        vsub.xyz vf3, vf26, vf3
        vopmula.xyz ACC, vf4, vf3
        vopmsub.xyz vf3, vf3, vf4
        vabs.xyz vf6, vf4
        vabs.xyz vf7, vf3
        vopmula.xyz ACC, vf8, vf6
        vsub.xyz vf9, vf0, vf6
        vopmsub.xyz vf6, vf9, vf8
        vsub.xyz vf9, vf7, vf6
        qmfc2.ni t0, vf9
        pcgtw v0, zero, t0
        bnez v0, box_ret
        nop
        prot3w v0, v0
    box_ret:
        jr ra
        nop
    }
}

// FUNCTION: 0x001709A0 GetGroundPos__11BGCollisionFPA4_f
int BGCollision::GetGroundPos(float (*pPos)[4])
{
    float from[4];
    float to[4];

    pPos[0][3] = 1.0f;
    *(u_long128 *)to = *(u_long128 *)pPos[0];
    to[1] -= 100.0f;
    *(u_long128 *)from = *(u_long128 *)pPos[0];
    if (FindIntersect((PVec3 &)from, (PVec3 &)to, 0x40, 0) != 0) {
        *(u_long128 *)pPos[0] = *(u_long128 *)to;
        return 1;
    }
    return 0;
}

// DRAFT: 0x00170A20 ReadCollisionData__11BGCollisionFPcP9PMeshNode
int BGCollision::ReadCollisionData(char *pName, PMeshNode *pMesh)
{
    int aHeader[12];
    char aPath[0x40];
    int aTrailer[4];

    if (m_unk70.m_unk8 != 0) {
        m_unk70.m_unk0 = 0;
        m_unk70.m_unk4 = 0;
    }
    if (pMesh != 0) {
        pMesh->BuildCollisionArray(&m_unk70, 0);
    }
    if (m_unk4C != 0) {
        __dl__FPv(m_unk4C);
        m_unk4C = 0;
    }
    strcpy(aPath, pName);
    int len = strlen(pName);
    char *p = aPath - 3;
    p += len;
    *p = 0;
    strcat(aPath, "CMP");
    if (!gPFile.Open(aPath, OPEN_READ)) {
        return 0;
    }
    if (gPFile.Read(aHeader, 0x30) != 0x30) {
        return 0;
    }
    aHeader[11] -= 0x30;
    m_unk4C = __nwa__FUi(aHeader[11]);
    void *mpData = m_unk4C;
    CDS_ASSERT(0x68, mpData);
    *(u_long128 *)&m_unk0 = *(u_long128 *)aHeader;
    sceVu0AddVector(m_unk10, (float *)aHeader, (float *)(aHeader + 4));
    sceVu0ScaleVector(m_unk10, m_unk10, 0.5f);
    sceVu0SubVector(m_unk20, m_unk10, (float *)aHeader);
    m_unk30 = (float)((short *)aHeader)[18];
    m_unk34 = (float)((short *)aHeader)[19];
    m_unk60 = 0.5f * m_unk30;
    m_unk68 = 0.5f * m_unk34;
    m_unk38 = (unsigned int)(2.0f * m_unk20[0] / m_unk30);
    m_unk3C = (unsigned int)(2.0f * m_unk20[2] / m_unk34);
    int nSize = aHeader[11];
    if (gPFile.Read(m_unk4C, nSize) != nSize) {
        CDS_ASSERT(0x76, !"CMP read error\n");
        __dl__FPv(m_unk4C);
        return 0;
    }
    gPFile.Read(aTrailer, 0x10);
    gPFile.Close();

    int a2 = (int)m_unk4C;
    int a3 = a2 - 0x30;
    m_unk40 = a2 + aTrailer[3] - 0x30;
    int *v1 = (int *)m_unk40;
    for (int t0 = aHeader[8]; t0 != 0; t0--, v1++) {
        if (*v1 != 0) {
            *v1 += a3;
            int *p = (int *)*v1;
            int t1 = p[2];
            if (t1 != 0) {
                int *a0 = p + 3;
                for (; t1 != 0; t1--, a0++) {
                    *a0 += a3;
                    int *a1 = (int *)*a0;
                    if ((unsigned int)a1[0] < (unsigned int)a2) {
                        a1[0] = (a1[0] << 4) + a2;
                        a1[1] = (a1[1] << 4) + a2;
                        a1[2] = (a1[2] << 4) + a2;
                    }
                }
            }
        }
    }
    FlushCache(0);
    return 1;
}

// FUNCTION: 0x00170DD0 Destroy__11BGCollisionFv
void BGCollision::Destroy()
{
    void *p = m_unk4C;
    if (p != 0) {
        __dl__FPv(p);
        m_unk4C = 0;
        m_unk40 = 0;
    }
    if (m_unk70.m_unk8 != 0) {
        m_unk70.m_unk0 = 0;
        m_unk70.m_unk4 = 0;
    }
}

// FUNCTION: 0x00170E20 __ct__11BGCollisionFv
BGCollision::BGCollision()
{
    m_unk4C = 0;
    m_unk40 = 0;
    m_unk44 = 0;
    m_unk70.Allocate(0x80);
}
