// FLAGS: -str readonly
#include "types.h"
#include "PSeaSerpentTeeth.h"
#include "PResourceManager.h"

// TODO(header): foreign declarations
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void __dl__FPv(void *pMem);
extern "C" int rand(void);
extern "C" void sceVu0ScaleVectorXYZ(float *pDst, float *pSrc, float fScale);
extern "C" void FastMath_ComputeMatrix__FPA4_A4_fPA4_fPA4_fPA4_fPA4_fPA4_fPA4_A4_f(float (*pOut)[4][4], float (*pPos)[4], float (*pRot)[4], float (*pScale)[4], float (*pA)[4], float (*pB)[4], float (*pPivot)[4][4]);
class PMat4;
class PShader {
public:
    void Render(int nFlags, bool bFlag, bool *pFlag);
};
class PGfxEngine {
public:
    void SetWorldMatrix(PMat4 *pMat);
    void BeginStaticInstances(void *pData, int nSize);
};
class PDisplayList {
public:
    void DrawStaticInstances(tagVuStaticInstance *pInst, int nA, int nB, int nC, int nD, bool bE);
};
extern char gGfxEng[1504384];
extern float gUnitMatrix[16];
extern char gLowerTeeth1Info[0x5A0];
extern char gLowerTeeth2Info[0x5A0];
extern char gUpperTeeth1Info[0x5A0];
extern char gUpperTeeth2Info[0x5A0];

// Shader slot held at PSeaSerpentTeeth::m_unk1690 / m_unk1694.
struct tagShaderData {
    int nSize;
    void *pData;
};
struct tagShaderSlot {
    PShader *pShader;
    char _pad004[4];
    unsigned int nCount;
    tagShaderData *pData;
};

// FUNCTION: 0x0020E810 ComputeInstanceData__16PSeaSerpentTeethFP6PMNodeP12tagToothInfoiP19tagVuStaticInstance
void PSeaSerpentTeeth::ComputeInstanceData(PMNode *pNode, tagToothInfo *pTeeth, int nCount, tagVuStaticInstance *pOut) {
    float vIdentW[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    float vScale[4];
    float vPos[4];
    for (int i = 0; i < nCount; i++) {
        char *pTooth = (char *)pTeeth + i * 0x30;
        char *pInst = (char *)pOut + i * 0x50;
        sceVu0ScaleVectorXYZ(vScale, (float *)(pTooth + 0x20), 1.1f);
        vScale[3] = 1.0f;
        *(u_long128 *)vPos = *(u_long128 *)pTooth;
        vPos[3] = 1.0f;
        FastMath_ComputeMatrix__FPA4_A4_fPA4_fPA4_fPA4_fPA4_fPA4_fPA4_A4_f((float (*)[4][4])pInst, (float (*)[4])vPos, (float (*)[4])(pTooth + 0x10), (float (*)[4])vScale, (float (*)[4])vIdentW, (float (*)[4])vIdentW, (float (*)[4][4])((char *)pNode + 0x40));
        float fLife = *(float *)(pTooth + 0xC);
        *(float *)(pInst + 0x40) = 0.8f;
        *(float *)(pInst + 0x44) = 0.9f;
        *(float *)(pInst + 0x48) = 1.0f;
        *(float *)(pInst + 0x4C) = fLife;
    }
}

// FUNCTION: 0x0020E940 KnockOutTeeth__16PSeaSerpentTeethFv
void PSeaSerpentTeeth::KnockOutTeeth() {
    char *pTooth = m_unk10 + (int)(0.5f + 27.0f * ((float)rand() / 2147483648.0f)) * 0x30;
    int nCount = 0;
    while (*(float *)(pTooth + 0xC) == 0.0f && nCount < 0x1C) {
        pTooth = m_unk10 + (int)(0.5f + 27.0f * ((float)rand() / 2147483648.0f)) * 0x30;
        nCount++;
    }
    *(float *)(pTooth + 0xC) = 0.0f;

    int nIndex = (int)(0.5f + 36.0f * ((float)rand() / 2147483648.0f));
    char *pFar;
    if (nIndex < 0x11) {
        pFar = m_unkB50 + nIndex * 0x30;
    } else {
        pFar = m_unk10F0 + nIndex * 0x30;
    }
    nCount = 0;
    while (*(float *)(pFar + 0xC) == 0.0f && nCount < 0x24) {
        nIndex = (int)(0.5f + 36.0f * ((float)rand() / 2147483648.0f));
        if (nIndex < 0x11) {
            pFar = m_unkB50 + nIndex * 0x30;
        } else {
            pFar = m_unk10F0 + nIndex * 0x30;
        }
        nCount++;
    }
    *(float *)(pFar + 0xC) = 0.0f;
}

// DRAFT: 0x0020EB80 Render__16PSeaSerpentTeethFv
// note: 72 words off; first BeginStaticInstances args differ (holder reg, sltu in $at vs named bool; second call untried); 0x0010 branch 5 words short. 8 attempts.
void PSeaSerpentTeeth::Render() {
    if (m_unk3C20 != 0) {
        ComputeInstanceData(m_unk0, (tagToothInfo *)m_unk10, 0x1C, (tagVuStaticInstance *)m_unk16A0);
        ComputeInstanceData(m_unk8, (tagToothInfo *)m_unkB50, 0x11, (tagVuStaticInstance *)m_unk2960);
        ComputeInstanceData(m_unkC, (tagToothInfo *)m_unk10F0, 0x14, (tagVuStaticInstance *)m_unk32C0);
        ((PGfxEngine *)gGfxEng)->SetWorldMatrix((PMat4 *)gUnitMatrix);
        ((tagShaderSlot *)m_unk1690)->pShader->Render(0x80, false, 0);
        tagShaderSlot *pSlot1 = (tagShaderSlot *)m_unk1690;
        bool bHas1 = pSlot1->nCount != 0;
        ((PGfxEngine *)gGfxEng)->BeginStaticInstances(
            bHas1 ? pSlot1->pData->pData : 0,
            bHas1 ? pSlot1->pData->nSize : 0);
        ((PDisplayList *)*(void **)(gGfxEng + 0x154C80))->DrawStaticInstances((tagVuStaticInstance *)m_unk16A0, 0x1C, 0x28, 0, 1, false);
        ((tagShaderSlot *)m_unk1694)->pShader->Render(0x80, false, 0);
        ((PGfxEngine *)gGfxEng)->BeginStaticInstances(
            ((tagShaderSlot *)m_unk1694)->nCount > 0 ?((tagShaderSlot *)m_unk1694)->pData->pData : 0,
            ((tagShaderSlot *)m_unk1694)->nCount > 0 ?((tagShaderSlot *)m_unk1694)->pData->nSize : 0);
        ((PDisplayList *)*(void **)(gGfxEng + 0x154C80))->DrawStaticInstances((tagVuStaticInstance *)m_unk2960, 0x11, 0x28, 0, 1, false);
        ((PDisplayList *)*(void **)(gGfxEng + 0x154C80))->DrawStaticInstances((tagVuStaticInstance *)m_unk32C0, 0x14, 0x28, 0, 1, false);
    }
}

// FUNCTION: 0x0020ED40 Create__16PSeaSerpentTeethFP6PMNodeP6PMNodeP6PMNodeP6PMNodeP16PResourceManager
void PSeaSerpentTeeth::Create(PMNode *pLowerJaw1, PMNode *pLowerJaw2, PMNode *pUpperJaw1, PMNode *pUpperJaw2, PResourceManager *pResMgr) {
    if (pLowerJaw1 == 0) CdsAssert__FPciPc("PSeaSerpentTeeth.cpp", 0x87, "pLowerJaw1");
    if (pLowerJaw2 == 0) CdsAssert__FPciPc("PSeaSerpentTeeth.cpp", 0x88, "pLowerJaw2");
    if (pUpperJaw1 == 0) CdsAssert__FPciPc("PSeaSerpentTeeth.cpp", 0x89, "pUpperJaw1");
    if (pUpperJaw2 == 0) CdsAssert__FPciPc("PSeaSerpentTeeth.cpp", 0x8A, "pUpperJaw2");
    if (pResMgr == 0) CdsAssert__FPciPc("PSeaSerpentTeeth.cpp", 0x8B, "pResMgr");
    m_unk0 = pLowerJaw1;
    m_unk4 = pLowerJaw2;
    m_unk8 = pUpperJaw1;
    m_unkC = pUpperJaw2;

    int i = 0;
    int off = 0;
    do {
        memcpy(m_unk10 + off, gLowerTeeth1Info + off, 0x30);
        i++;
        off += 0x30;
    } while (i < 0x1E);

    i = 0;
    off = 0;
    do {
        memcpy(m_unk10 + 0x5A0 + off, gLowerTeeth2Info + off, 0x30);
        i++;
        off += 0x30;
    } while (i < 0x1E);

    i = 0;
    off = 0;
    do {
        memcpy(m_unkB50 + off, gUpperTeeth1Info + off, 0x30);
        i++;
        off += 0x30;
    } while (i < 0x1E);

    i = 0;
    off = 0;
    do {
        memcpy(m_unk10F0 + off, gUpperTeeth2Info + off, 0x30);
        i++;
        off += 0x30;
    } while (i < 0x1E);

    m_unk1690 = pResMgr->GetResource(0x06000022U, false);
    if (m_unk1690 == 0) CdsAssert__FPciPc("PSeaSerpentTeeth.cpp", 0xA8, "mpLowerToothMesh");
    m_unk1694 = pResMgr->GetResource(0x06000021U, false);
    if (m_unk1694 == 0) CdsAssert__FPciPc("PSeaSerpentTeeth.cpp", 0xAB, "mpUpperToothMesh");
    m_unk3C20 = 1;
}

// FUNCTION: 0x0020EFE0 __ct__16PSeaSerpentTeethFv
PSeaSerpentTeeth::PSeaSerpentTeeth() {
    memset(m_unk10, 0, 0x1680);
    memset(this, 0, 0x10);
    m_unk3C20 = 0;
}

// FUNCTION: 0x0020EF90 __dt__16PSeaSerpentTeethFv
PSeaSerpentTeeth::~PSeaSerpentTeeth() {
}
