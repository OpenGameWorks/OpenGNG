// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "PShadowVolume.h"
#include "PMNode.h"
#include "PCDFile.h"

// TODO(header): foreign declarations
void operator delete(void *pMem);
void operator delete[](void *pMem);
extern "C" void *__nw__FUi(unsigned int);
extern "C" void *__nwa__FUi(unsigned int);
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void sceVu0UnitMatrix(float (*)[4]);
extern "C" void sceVu0CopyVector(float *, float *);
extern "C" void sceVu0ScaleVectorXYZ(float *, float *, float);
extern "C" void sceVu0Normalize(float *, float *);
extern "C" void CreatePerspectiveMatrix__FPA4_fffff(float (*)[4], float, float, float, float);
extern "C" void Mul__5PMat4FP5PMat4(float (*)[4], float (*)[4], float (*)[4]);
extern "C" void Inverse__5PMat4FP5PMat4(void *, float (*)[4]);
extern "C" void MulVector__5PMat4FPfPf(void *, float *, float *);
extern "C" void BeginShadowVolume__12PDisplayListFP5PMat4PfPfPfPfPf(void *, float (*)[4], float *, float *, float *, float *, float *);
extern "C" void RenderShadowVolume__12PDisplayListFPvi(void *, void *, int);
extern float FOV_Y;
extern float XY_ASPECT;
extern char gGfxEng[1504384];

// DRAFT: 0x001D89C0 Render__13PShadowVolumeFPfPfPfPfPff
// note: 267 words differ: frame size 0x4BC vs 0x4D4, matrix block 0x10 low (mWorld 0xB0 vs 0xC0), prologue sq/daddu scheduling differs; a placeholder-local variant gave the same count.
void PShadowVolume::Render(float *arg0, float *arg1, float *arg2, float *arg3, float *arg4, float arg5) {
    float mWorld[4][4];
    float mProj[4][4];
    float mView[4][4];
    float mTmp[4][4];
    float mInv[4][4];
    float mA[4][4];
    float mB[4][4];
    float mC[4][4];
    float vCam[4];
    float vLight[4];
    float vPos[4];
    float vSel[4];
    float vTmp[4];

    if (m_unk18 != 0) {
        sceVu0UnitMatrix(mWorld);
        sceVu0UnitMatrix(mProj);
        sceVu0UnitMatrix(mView);
        sceVu0UnitMatrix(mTmp);
        CreatePerspectiveMatrix__FPA4_fffff(mProj, FOV_Y, XY_ASPECT, 0.1f, 1000.0f);
        Mul__5PMat4FP5PMat4(mA, mProj, (float (*)[4])(gGfxEng + 0x3A00));
        sceVu0CopyMatrix(mWorld, mA);
        sceVu0CopyVector(vCam, (float *)(gGfxEng + 0x39B0));
        int count = (int)m_array.m_unk0;
        if (count != 1) {
            *(u_long128 *)vPos = *(u_long128 *)arg2;
            vPos[2] += 1500.0f;
        }
        if (count > 0) {
            unsigned int i = 0;
            unsigned int off = 0;
            do {
                PShadowVolumeNode *pNode = (i < m_array.m_unk0) ? (PShadowVolumeNode *)*(void **)((char *)m_array.m_unk8 + off) : 0;
                if (pNode != 0 && pNode->m_unk1C != 0 && pNode->m_unk20 != 0) {
                    if (pNode->m_unk0 == 0x2AF72F02) {
                        if (*(int *)((char *)pNode->m_unk20 + 4) == 0) {
                            CdsAssert("PShadowVolume.cpp", 0xFD, "pNode->m_unk20->m_unk4");
                        }
                        if (*(int *)((char *)pNode->m_unk20 + 0xC) != 0) {
                            sceVu0CopyVector(vSel, (float *)((char *)pNode->m_unk1C + 0x30));
                            vSel[0] -= 2.0f;
                            vSel[1] -= 2.0f;
                            vSel[2] -= 2.0f;
                            if (*(float *)((char *)pNode->m_unk1C + 0x34) <= 5.0f + vCam[1] &&
                                (vCam[0] <= vSel[0] || vCam[1] <= vSel[1] || vCam[2] <= vSel[2] ||
                                 !(vCam[0] < 4.0f + vSel[0]) || !(vCam[1] < 255.0f + vSel[1]) || !(vCam[2] < 4.0f + vSel[2]))) {
                                sceVu0UnitMatrix(mInv);
                                *(u_long128 *)vTmp = *(u_long128 *)((char *)pNode->m_unk1C + 0x30);
                                vLight[0] = arg0[0];
                                vLight[1] = arg0[1];
                                vLight[2] = arg0[2];
                                vLight[3] = 1.0f;
                                if (*(float *)&m_unk10 == -1000000.0f) {
                                    sceVu0ScaleVectorXYZ(vLight, vLight, -(255.0f - arg5));
                                } else {
                                    sceVu0ScaleVectorXYZ(vLight, vLight, -(4.0f + (*(float *)((char *)pNode->m_unk1C + 0x34) - *(float *)&m_unk10)));
                                }
                                vLight[3] = arg0[3];
                                Mul__5PMat4FP5PMat4(mB, mWorld, mView);
                                sceVu0CopyMatrix(mView, mB);
                                BeginShadowVolume__12PDisplayListFP5PMat4PfPfPfPfPf(*(void **)(gGfxEng + 0x154C80), mView, vLight, arg1, vPos, arg3, arg4);
                                RenderShadowVolume__12PDisplayListFPvi(*(void **)(gGfxEng + 0x154C80), pNode->m_unk4, (int)pNode->m_unk8);
                            }
                        }
                    } else {
                        Inverse__5PMat4FP5PMat4(pNode->m_unk1C, mTmp);
                        vLight[0] = arg0[0];
                        vLight[1] = arg0[1];
                        vLight[2] = arg0[2];
                        vLight[3] = arg0[3];
                        MulVector__5PMat4FPfPf(mTmp, vLight, vLight);
                        sceVu0Normalize(vLight, vLight);
                        sceVu0ScaleVectorXYZ(vLight, vLight, -(255.0f - arg5));
                        vLight[3] = arg0[3];
                        Mul__5PMat4FP5PMat4(mC, mWorld, mView);
                        sceVu0CopyMatrix(mView, mC);
                        BeginShadowVolume__12PDisplayListFP5PMat4PfPfPfPfPf(*(void **)(gGfxEng + 0x154C80), mView, vLight, arg1, vPos, arg3, arg4);
                        RenderShadowVolume__12PDisplayListFPvi(*(void **)(gGfxEng + 0x154C80), pNode->m_unk4, (int)pNode->m_unk8);
                    }
                }
                i++;
                off += 4;
            } while ((int)i < count);
        }
    }
}

// FUNCTION: 0x001D8EA0 SetShadowCaster__13PShadowVolumeFP6PMNode
void PShadowVolume::SetShadowCaster(PMNode *pNode) {
    if (pNode != 0) {
        unsigned int i;
        unsigned int off;
        int count = (int)m_array.m_unk0;
        if (count == 1) {
            unsigned int first = 0;
            PShadowVolumeNode *pFirst = (first < m_array.m_unk0) ? (PShadowVolumeNode *)m_array.m_unk8[first] : 0;
            pFirst->m_unk1C = (char *)pNode + 0x40;
            pFirst->m_unk20 = pNode;
            return;
        }
        if (0 < count) {
            i = 0;
            off = 0;
            do {
                PShadowVolumeNode *pEntry = (i < m_array.m_unk0) ? (PShadowVolumeNode *)*(void **)((char *)m_array.m_unk8 + off) : 0;
                if (pEntry != 0) {
                    PMNode *pFound = pNode->Find(pEntry->m_unk0);
                    if (pFound != 0) {
                        pEntry->m_unk1C = (char *)pFound + 0x40;
                        pEntry->m_unk20 = pFound;
                    } else {
                        pEntry->m_unk1C = 0;
                        pEntry->m_unk20 = 0;
                    }
                }
                i++;
                off += 4;
            } while ((int)i < count);
        }
    } else {
        m_unk18 = 0;
        int count = (int)m_array.m_unk0;
        if (0 < count) {
            unsigned int i = 0;
            do {
                PShadowVolumeNode *pEntry = (i < m_array.m_unk0) ? (PShadowVolumeNode *)m_array.m_unk8[i] : 0;
                pEntry->m_unk1C = 0;
                i++;
                pEntry->m_unk20 = 0;
            } while ((int)i < count);
        }
    }
}

// DRAFT: 0x001D8FF0 Load__13PShadowVolumeFP8PPakFile
// note: 68 words differ: size and node pointer swap registers (original keeps &size in s2, node in s1). Tried pointer locals for size/count (121 words), block-scope and function-scope size locals (68).
int PShadowVolume::Load(PPakFile *pFile) {
    char header[0x20];
    char entry[0x38];
    unsigned int size;
    unsigned int i;
    if (pFile == 0) {
        CdsAssert("PShadowVolume.cpp", 0x5C, "poFile");
    }
    if (((PCDFile *)pFile)->Read(header, 0x20) != 0x20) {
        return 0;
    }
    if (*(unsigned int *)header != 0xD00BD00B) {
        return 0;
    }
    if (*(int *)(header + 8) == 0) {
        return 0;
    }
    i = 0;
    while ((int)i < *(int *)(header + 8)) {
        if (((PCDFile *)pFile)->Read(entry, 0x38) != 0x38) {
            return 0;
        }
        size = *(unsigned int *)(entry + 0x14);
        if (size == 0) {
            return 0;
        }
        PShadowVolumeNode *pNode = (PShadowVolumeNode *)__nw__FUi(0x28);
        if (pNode == 0) {
            CdsAssert("PShadowVolume.cpp", 0x78, "apNode");
        }
        pNode->m_unk0 = *(int *)entry;
        memcpy(pNode->m_unkC, entry + 4, 0x10);
        pNode->m_unk8 = size;
        pNode->m_unk1C = 0;
        pNode->m_unk4 = __nwa__FUi(size);
        if (pNode->m_unk4 == 0) {
            CdsAssert("PShadowVolume.cpp", 0x7F, "apNode->pvVertexData");
        }
        if (((PCDFile *)pFile)->Read(pNode->m_unk4, size) != size) {
            operator delete[](pNode->m_unk4);
            operator delete(pNode);
            return 0;
        }
        pNode->m_unk24 = 1;
        m_array.Add(pNode);
        i++;
    }
    return 1;
}

// FUNCTION: 0x001D91D0 __dt__13PShadowVolumeFv
PShadowVolume::~PShadowVolume() {
    int count = (int)m_array.m_unk0;
    if (0 < count) {
        unsigned int i = 0;
        do {
            PShadowVolumeNode *pNode = (i < m_array.m_unk0) ? (PShadowVolumeNode *)m_array.m_unk8[i] : 0;
            if (pNode != 0) {
                if (pNode->m_unk4 != 0 && pNode->m_unk24 != 0) {
                    operator delete[](pNode->m_unk4);
                }
                operator delete(pNode);
            }
            i++;
        } while ((int)i < count);
    }
    if (m_array.m_unk8 != 0) {
        m_array.m_unk0 = 0;
        m_array.m_unk4 = 0;
    }
    m_unk14 = 0;
}

// FUNCTION: 0x001D92D0 __ct__13PShadowVolumeFP13PShadowVolume
PShadowVolume::PShadowVolume(PShadowVolume *pSource) {
    if (pSource == 0) {
        CdsAssert("PShadowVolume.cpp", 0x19, "apNodeArray");
    }
    int count = (int)pSource->m_array.m_unk0;
    if (0 < count) {
        unsigned int i = 0;
        do {
            PShadowVolumeNode *pNode = 0;
            if (i < pSource->m_array.m_unk0) {
                pNode = (PShadowVolumeNode *)pSource->m_array.m_unk8[i];
            }
            if (pNode != 0) {
                PShadowVolumeNode *pCopy = (PShadowVolumeNode *)__nw__FUi(0x28);
                if (pCopy == 0) {
                    CdsAssert("PShadowVolume.cpp", 0x22, "apNewNode");
                }
                memcpy(pCopy, pNode, 0x28);
                pCopy->m_unk24 = 0;
                pCopy->m_unk1C = 0;
                pCopy->m_unk20 = 0;
                m_array.Add(pCopy);
            }
            i++;
        } while ((int)i < count);
    }
    if (m_array.m_unk0 != pSource->m_array.m_unk0) {
        CdsAssert("PShadowVolume.cpp", 0x2B, "moShadowVolumeNodes.GetCount() == apNodeArray->GetCount()");
    }
    m_unk18 = 0;
}

// FUNCTION: 0x001D9410 __ct__13PShadowVolumeFv
PShadowVolume::PShadowVolume() {
    m_unk18 = 0;
    m_unk14 = 0;
    m_unk10 = 0xC9742400;
}
