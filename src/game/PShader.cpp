// FLAGS: -str readonly
#include "types.h"
#include "PShader.h"
#include "PSTAnim.h"
#include "PRenderPass.h"

// TODO(header): foreign declarations
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void __dla__FPv(void *pMem);
extern "C" void __dl__FPv(void *pMem);
extern "C" void __dt__7PSTAnimFv(void *pThis, short nFlag);
extern "C" void UnloadDynamicTexture__15PTextureManagerFi(void *pThis, int nId);
extern "C" void SetTextures__15PTextureManagerFPiiP12PDisplayListRb(void *pThis, int *pIds, int nCount, void *pDisp, bool &bSet);
extern "C" void SetMaterials__12PDisplayListFP13tagGsMaterialibbPfPUlPUlPb(void *pThis, void *pMat, int nCount, bool bA, bool bB, float *pScale, void *pTagA, void *pTagB, bool *pbOut);
extern "C" void SetMaterials__12PDisplayListFP13tagGsMaterialibbPfPUlPUl(void *pThis, void *pMat, int nCount, bool bA, bool bB, float *pScale, void *pTagA, void *pTagB);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" int Read__7PCDFileFPvUi(void *pThis, void *pBuf, unsigned int nSize);
extern unsigned int guNumShadersInCurModel;
extern int guGlobalShaderIDOffset;
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void *GetTexEnv__15PTextureManagerFi(void *pThis, int nHandle);
extern char gGfxEng[1504384];

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("PShader.cpp", line, #cond))
#define CDS_ASSERT_TXT(line, cond, txt) ((cond) ? (void)0 : CdsAssert__FPciPc("PShader.cpp", line, txt))

// DRAFT: 0x00196890 LoadRenderPass__7PShaderFP8PPakFileP6PArrayUib
// note: DIFF 237; prologue saves s1-s4 under a smaller frame (original saves s0-s7 under 0xE0), size 0x314 vs 0x3FC; bit-31 test variant also 237.
int PShader::LoadRenderPass(PPakFile *pPakFile, PArray *pTextures, unsigned int nIndex, bool bFlag) {
    PRenderPass rp;
    if (!rp.Load(pPakFile, pTextures)) {
        return 0;
    }
    m_unk20[nIndex] = rp.m_unk8;
    m_unk54[nIndex] = rp.m_unk0;
    rp.m_unk0 = 0;
    if (m_unk20[nIndex] > 0) {
        m_unk4 |= 0x20;
    }
    m_unk50[nIndex] = rp.m_unk3;
    m_unk40[nIndex] = rp.m_unk4;
    if (rp.m_unk28) {
        m_unk30[nIndex] = new PSTAnim;
        CDS_ASSERT_TXT(0x167, m_unk30[nIndex], "mpPassSTAnims[uPass]");
        m_unk30[nIndex]->Clone(rp.m_unk28);
    }

    char *pMat = (char *)m_unk0 + nIndex * 0xA0;
    memcpy(pMat + 0x60, &rp.m_unk10, 16);
    m_unk10[nIndex] = *(float *)(pMat + 0x6C);
    memcpy(pMat + 0x70, &rp.m_unk2C, 16);
    memcpy(pMat + 0x80, &rp.m_unk3C, 16);

    int nFlag;
    if (nIndex != 0) {
        nFlag = 1;
    } else {
        nFlag = (*(float *)(pMat + 0x6C) < 1.0f) ? 1 : bFlag;
    }

    *(long long *)(pMat + 0x20) = rp.m_unk20;
    *(long long *)(pMat + 0x28) = 0x42;
    *(long long *)(pMat + 0x30) = rp.m_unk3 ? ((((nFlag == 0) ? 0x7E : 0) << 4) | 0x5000D) : 0x50000;
    *(long long *)(pMat + 0x38) = 0x47;
    *(long long *)(pMat + 0x40) = 0;
    *(long long *)(pMat + 0x48) = 0x1A;
    *(long long *)(pMat + 0x50) = ((nFlag & 0xFF) << 6) | ((m_unk20[nIndex] != 0) << 4) | 8;
    *(long long *)(pMat + 0x58) = 0x1B;
    *(long long *)(pMat + 0x10) = 0;
    *(long long *)(pMat + 0x18) = 0;

    *(unsigned short *)(pMat + 0x10) = (*(unsigned short *)(pMat + 0x10) & -0x8000) | 4;
    *(unsigned char *)(pMat + 0x11) = (*(unsigned char *)(pMat + 0x11) & -0x81) | 0x80;
    *(unsigned char *)(pMat + 0x17) = (*(unsigned char *)(pMat + 0x17) & -0xF1) | 0x10;
    *(unsigned char *)(pMat + 0x18) = (*(unsigned char *)(pMat + 0x18) & -0x10) | 0xE;

    int nGlobalTex = *(int *)(gGfxEng + 0x16D408);
    int nTex = nGlobalTex ? nGlobalTex : m_unk20[nIndex];
    *(void **)(pMat + 4) = GetTexEnv__15PTextureManagerFi(gGfxEng + 0x154C90, nTex);
    CDS_ASSERT_TXT(0x19C, *(void **)(pMat + 4), "mpVuMaterials[uPass].pTexEnv");
    return 1;
}

// DRAFT: 0x00196C90 Render__7PShaderFibPb
// note: DIFF 113 words, size 0x2CC vs 0x2F0. Original loads 0x16D408 into a register and adds it with addu (folded by ours into lui/addiu); the loop uses pointer/offset induction variables and different branch shapes at 0x10C and 0x11C. Tried: local offset variable for the gate (folded, no change).
void PShader::Render(int nArg, bool bFlag, bool *pbOut) {
    bool bSet = false;
    float fScale[4];
    unsigned long long nTagA[4];
    unsigned long long nTagB[4];

    if (m_unk4 & 0x20) {
        if (*(int *)(gGfxEng + 0x16D408)) {
            SetTextures__15PTextureManagerFPiiP12PDisplayListRb(gGfxEng + 0x154C90, (int *)(gGfxEng + 0x16D408), 1, *(void **)(gGfxEng + 0x154C80), bSet);
        } else {
            SetTextures__15PTextureManagerFPiiP12PDisplayListRb(gGfxEng + 0x154C90, m_unk20, m_unk8, *(void **)(gGfxEng + 0x154C80), bSet);
        }
    }

    if (m_unk4 & 1) {
        for (unsigned int i = 0; i < m_unk8; i++) {
            PSTAnim *p = m_unk30[i];
            if (p) {
                *(void **)((char *)m_unk0 + i * 0xA0 + 0x90) = (char *)p + 0x20;
                p->m_unk2 = 0;
            }
        }
    }

    if (nArg != 0x80) {
        for (unsigned int i = 0; i < m_unk8; i++) {
            void *apMaterial = (char *)m_unk0 + i * 0xA0;
            CDS_ASSERT(0xE4, apMaterial);
            fScale[i] = m_unk10[i] * ((float)nArg / 128.0f);
            nTagA[i] = ((unsigned char *)&m_unk50)[i] ? 0x5000D : 0x50000;
            nTagB[i] = ((unsigned long long)(m_unk20[i] != 0) << 4) | 0x48;
        }
        if (pbOut) {
            SetMaterials__12PDisplayListFP13tagGsMaterialibbPfPUlPUlPb(*(void **)(gGfxEng + 0x154C80), m_unk0, m_unk8, bSet, *(bool *)(gGfxEng + 0x158E24), fScale, nTagA, nTagB, pbOut);
        } else {
            SetMaterials__12PDisplayListFP13tagGsMaterialibbPfPUlPUl(*(void **)(gGfxEng + 0x154C80), m_unk0, m_unk8, bSet, *(bool *)(gGfxEng + 0x158E24), fScale, nTagA, nTagB);
        }
    } else {
        if (pbOut && m_unk8 >= 2) {
            SetMaterials__12PDisplayListFP13tagGsMaterialibbPfPUlPUlPb(*(void **)(gGfxEng + 0x154C80), m_unk0, m_unk8, bSet, *(bool *)(gGfxEng + 0x158E24), 0, 0, 0, pbOut);
        } else {
            SetMaterials__12PDisplayListFP13tagGsMaterialibbPfPUlPUl(*(void **)(gGfxEng + 0x154C80), m_unk0, m_unk8, bSet, *(bool *)(gGfxEng + 0x158E24), 0, 0, 0);
        }
    }
}

// FUNCTION: 0x00196F80 Animate__7PShaderFfb
void PShader::Animate(float fTime, bool bFlag) {
    if (m_unk4 & 1) {
        for (unsigned int i = 0; i < m_unk8; i++) {
            PSTAnim *p = m_unk30[i];
            if (p) {
                p->Animate(fTime, bFlag);
            }
        }
    }
}

// FUNCTION: 0x00197010 SetSTAnimOptions__7PShaderFb
void PShader::SetSTAnimOptions(bool bFlag) {
    if (m_unk4 & 1) {
        for (unsigned int i = 0; i < m_unk8; i++) {
            PSTAnim *p = m_unk30[i];
            if (p) {
                p->m_unk3 = bFlag;
            }
        }
    }
}

// FUNCTION: 0x00197060 Load__7PShaderFP8PPakFileP6PArrayb
int PShader::Load(PPakFile *pPakFile, PArray *pTextures, bool bFlag) {
    unsigned int aData[4];

    CDS_ASSERT_TXT(0x49, pPakFile, "poFile");
    CDS_ASSERT_TXT(0x4A, pTextures, "poTextureHandles");
    if (Read__7PCDFileFPvUi(pPakFile, aData, 0x10) != 0x10) {
        return 0;
    }
    if (aData[0] == 0) {
        return 0;
    }
    if (aData[2] & 1) {
        m_unk4 |= 4;
    }
    if (aData[2] & 2) {
        m_unk4 |= 8;
    }
    if (aData[2] & 4) {
        m_unk4 |= 0x80;
    }
    if (bFlag) {
        m_unk4 |= 0x10;
    }
    if (aData[1]) {
        guNumShadersInCurModel = (aData[1] < guNumShadersInCurModel) ? guNumShadersInCurModel : aData[1];
        m_unkC = guGlobalShaderIDOffset + aData[1];
    }
    bool bHasAnim = false;
    CDS_ASSERT_TXT(0x75, aData[0] <= 4, "aData.uNumPasses <= MAX_PASSES_PER_SHADER");
    m_unk0 = __nwa__FUi(aData[0] * 0xA0);
    CDS_ASSERT_TXT(0x79, m_unk0, "mpVuMaterials");
    memset(m_unk0, 0, aData[0] * 0xA0);
    m_unk8 = aData[0];
    for (unsigned int i = 0; i < aData[0]; i++) {
        if (!LoadRenderPass(pPakFile, pTextures, i, bFlag)) {
            return 0;
        }
        if (m_unk30[i]) {
            bHasAnim = true;
        }
    }
    if (bHasAnim) {
        m_unk4 |= 1;
    }
    if (*(float *)((char *)m_unk0 + 0x6C) < 1.0f) {
        m_unk4 |= 0x10;
    }
    m_unk4 |= 2;
    return 1;
}

// FUNCTION: 0x00197300 Destroy__7PShaderFv
void PShader::Destroy() {
    if (m_unk0) {
        __dla__FPv(m_unk0);
        m_unk0 = 0;
    }
    for (unsigned int i = 0; i < m_unk8; i++) {
        if (m_unk30[i]) {
            __dt__7PSTAnimFv(m_unk30[i], 1);
            m_unk30[i] = 0;
        }
        if (m_unk54[i]) {
            if (m_unk20[i]) {
                UnloadDynamicTexture__15PTextureManagerFi(gGfxEng + 0x154C90, m_unk20[i]);
                m_unk54[i] = 0;
                m_unk54[i] = 0;
            }
        }
    }
}

// FUNCTION: 0x001973D0 __dt__7PShaderFv
extern "C" void *__dt__7PShaderFv(PShader *pThis, short nFlag) {
    if (pThis) {
        pThis->Destroy();
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x00197430 __ct__7PShaderFv
PShader::PShader() {
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk8 = 0;
    m_unkC = 0;
    memset(m_unk10, 0, 0x10);
    memset(m_unk20, 0, 0x10);
    memset(m_unk50, 0, 4);
    memset(m_unk30, 0, 0x10);
    memset(m_unk40, 0, 0x10);
    memset(m_unk54, 0, 4);
}
