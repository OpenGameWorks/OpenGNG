#include "types.h"
#include "PProgressBar.h"
#include "PMat4.h"
#include "PGfxEngine.h"

// TODO(header): foreign declarations
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern int SCREEN_OFFSET_X;
extern int SCREEN_OFFSET_Y;
extern "C" void SetReading__12PProgressBarFf(void *pThis, float fReading);
extern "C" void sceVu0UnitMatrix(float (*pMat)[4]);
extern "C" void EndMesh__12PDisplayListFv(void *pThis);
extern "C" void DrawRawVertices__12PDisplayListFPA4_fPA4_fPA4_fPA4_fi(void *pThis, float (*p0)[4], float (*p1)[4], float (*p2)[4], float (*p3)[4], int nCount);
extern PGfxEngine gGfxEng;
extern "C" void sceVu0InterVector(float *pDst, float *pA, float *pB, float fT);
extern "C" void SetMarker__12PProgressBarFPQ212PProgressBar16tagRawVertexDataPfff(void *pThis, void *pRaw, float *pVec, float fA, float fB);

// DRAFT: 0x0016BB90 Render__12PProgressBarFv
// note: only the sp60 literal load differs (lui/addiu of lit_00244CD0 vs @361+0x4CD0 in .rodata, 2 words); frame and calls match
void PProgressBar::Render() {
    float sp20[4][4];

    sceVu0UnitMatrix(sp20);
    float sp60[4] = {1.0f, 0.0f, 0.0f, 0.0f};
    float sp70[4][4];
    float spB0[4][4];
    sceVu0CopyMatrix(sp70, (float (*)[4])((char *)&gGfxEng + 0x16D3C0));
    sceVu0CopyMatrix(spB0, (float (*)[4])((char *)&gGfxEng + 0x16D380));
    ((unsigned char *)&gGfxEng)[0x158E22] = 0;
    gGfxEng.SetWorldMatrix((PMat4 *)sp20);
    gGfxEng.SetViewMatrix((PMat4 *)sp20);
    gGfxEng.SetScreenMatrix((PMat4 *)sp20);
    gGfxEng.SetMaterial(0, sp60, true, 0x44, 0x31001);
    gGfxEng.BeginMesh((eBoxIntersect)1);
    DrawRawVertices__12PDisplayListFPA4_fPA4_fPA4_fPA4_fi(gGfxEng.m_unk154C80, (float (*)[4])((char *)this + 0x80), 0, (float (*)[4])m_unkC0, 0, 4);
    DrawRawVertices__12PDisplayListFPA4_fPA4_fPA4_fPA4_fi(gGfxEng.m_unk154C80, (float (*)[4])this, 0, (float (*)[4])m_unk40, 0, 4);
    DrawRawVertices__12PDisplayListFPA4_fPA4_fPA4_fPA4_fi(gGfxEng.m_unk154C80, (float (*)[4])((char *)this + 0x100), 0, (float (*)[4])((char *)this + 0x140), 0, 4);
    DrawRawVertices__12PDisplayListFPA4_fPA4_fPA4_fPA4_fi(gGfxEng.m_unk154C80, (float (*)[4])((char *)this + 0x180), 0, (float (*)[4])((char *)this + 0x1C0), 0, 4);
    EndMesh__12PDisplayListFv(gGfxEng.m_unk154C80);
    gGfxEng.SetScreenMatrix((PMat4 *)sp70);
    gGfxEng.SetViewMatrix((PMat4 *)spB0);
}

// DRAFT: 0x0016BD20 SetReading__12PProgressBarFf
// note: 267 words differ, size 0x488 vs 0x4AC; clamp branch layout differs (bc1f/b vs bc1t at 0x50-0x60), tail counter and unk23C/unk240 blocks misordered; tried if/else, empty-then, and ternary clamp forms
void PProgressBar::SetReading(float fReading) {
    float fVal = fReading;
    float fMin = (fReading < m_unk234) ? fReading : m_unk234;
    if (!(0.0f <= fMin)) {
        fVal = 0.0f;
    } else if (!(fVal < m_unk234)) {
        fVal = m_unk234;
    }
    m_unk238 = fVal;

    m_unk248--;
    float fA;
    if (m_unk248 <= 0) {
        m_unk248 = m_unk244;
        fA = m_unk238;
    } else {
        fA = m_unk238;
        if (fA <= m_unk23C) {
            fA = m_unk23C;
        }
    }
    m_unk23C = fA;

    float fB = m_unk240;
    if (fB <= m_unk238) {
        fB = m_unk238;
    }
    m_unk240 = fB;

    float fInv = 1.0f / m_unk234;
    float f22 = m_unk238 * fInv;
    float f20 = m_unk23C * fInv;
    float f21 = m_unk240 * fInv;

    float vA[4];
    float vB[4];
    float vC[4];
    sceVu0InterVector(vA, &m_unk210, m_unk200, f22);
    sceVu0InterVector(vB, &m_unk210, m_unk200, f20);
    sceVu0InterVector(vC, &m_unk210, m_unk200, f21);

    m_unk10 = (float)SCREEN_OFFSET_X + m_unk220;
    float fY = m_unk224 - f22 * m_unk22C;
    m_unk14 = (float)SCREEN_OFFSET_Y + fY;
    m_unk18 = 0x3F800000;
    m_unk1C = 0x3F800000;
    m_unk30 = m_unk228 + ((float)SCREEN_OFFSET_X + m_unk220);
    m_unk34 = (float)SCREEN_OFFSET_Y + fY;
    m_unk38 = 0x3F800000;
    m_unk3C = 0x3F800000;

    m_unk50[0] = (unsigned int)vA[0];
    m_unk50[1] = (unsigned int)vA[1];
    m_unk50[2] = (unsigned int)vA[2];
    m_unk50[3] = (unsigned int)vA[3];
    m_unk70[0] = (unsigned int)vC[0];
    m_unk70[1] = (unsigned int)vC[1];
    m_unk70[2] = (unsigned int)vC[2];
    m_unk70[3] = (unsigned int)vC[3];

    SetMarker__12PProgressBarFPQ212PProgressBar16tagRawVertexDataPfff(this, (char *)this + 0x100, vB, m_unk224 - f20 * m_unk22C, 1.25f * m_unk228);
    SetMarker__12PProgressBarFPQ212PProgressBar16tagRawVertexDataPfff(this, (char *)this + 0x180, vC, m_unk224 - f21 * m_unk22C, 1.5f * m_unk228);
}

// FUNCTION: 0x0016C1D0 ResetReading__12PProgressBarFv
void PProgressBar::ResetReading() {
    m_unk248 = 0;
    m_unk240 = 0;
    SetReading(0.0f);
}

// FUNCTION: 0x0016C1F0 SetRange__12PProgressBarFf
void PProgressBar::SetRange(float fRange) {
    m_unk234 = fRange;
    float fReading = m_unk238;
    fReading = (fReading < m_unk234) ? fReading : m_unk234;
    SetReading__12PProgressBarFf(this, fReading);
}

// FUNCTION: 0x0016C220 SetColor2__12PProgressBarFffff
void PProgressBar::SetColor2(float fR, float fG, float fB, float fA) {
    m_unk210 = fR;
    m_unk214 = fG;
    m_unk218 = fB;
    m_unk21C = fA;
}

// FUNCTION: 0x0016C240 SetColor1__12PProgressBarFffff
void PProgressBar::SetColor1(float fR, float fG, float fB, float fA) {
    m_unk200[0] = fR;
    m_unk200[1] = fG;
    m_unk200[2] = fB;
    m_unk200[3] = fA;
    if (m_unk230) {
        unsigned int r = (unsigned int)fR;
        m_unk40[0] = r;
        unsigned int g = (unsigned int)fG;
        m_unk40[1] = g;
        unsigned int b = (unsigned int)fB;
        m_unk40[2] = b;
        unsigned int a = (unsigned int)fA;
        m_unk40[3] = a;
        m_unk60[0] = r;
        m_unk60[1] = g;
        m_unk60[2] = b;
        m_unk60[3] = a;
    } else {
        unsigned int r = (unsigned int)fR;
        m_unk40[0] = r;
        unsigned int g = (unsigned int)fG;
        m_unk40[1] = g;
        unsigned int b = (unsigned int)fB;
        m_unk40[2] = b;
        unsigned int a = (unsigned int)fA;
        m_unk40[3] = a;
        m_unk50[0] = r;
        m_unk50[1] = g;
        m_unk50[2] = b;
        m_unk50[3] = a;
    }
}

// FUNCTION: 0x0016C4B0 SetBgColor__12PProgressBarFffff
void PProgressBar::SetBgColor(float fR, float fG, float fB, float fA) {
    unsigned int r = (unsigned int)fR;
    m_unkC0[0] = r;
    unsigned int g = (unsigned int)fG;
    m_unkC0[1] = g;
    unsigned int b = (unsigned int)fB;
    m_unkC0[2] = b;
    unsigned int a = (unsigned int)fA;
    m_unkC0[3] = a;
    m_unkC0[4] = r;
    m_unkC0[5] = g;
    m_unkC0[6] = b;
    m_unkC0[7] = a;
    m_unkC0[8] = r;
    m_unkC0[9] = g;
    m_unkC0[10] = b;
    m_unkC0[11] = a;
    m_unkC0[12] = r;
    m_unkC0[13] = g;
    m_unkC0[14] = b;
    m_unkC0[15] = a;
}

// FUNCTION: 0x0016C600 Init__12PProgressBarFffffi
int PProgressBar::Init(float fX, float fY, float fW, float fH, int nArg4) {
    m_unk220 = fX;
    m_unk224 = fY;
    m_unk228 = fW;
    m_unk22C = fH;
    m_unk244 = nArg4;
    m_unk248 = m_unk244;
    m_unk238 = 0.0f;
    m_unk23C = 0;
    m_unk240 = 0;
    m_unk0 = (float)SCREEN_OFFSET_X + fX;
    m_unk4 = (float)SCREEN_OFFSET_Y + fY;
    m_unk8 = 1.0f;
    m_unkC = 1.0f;
    m_unk20 = m_unk228 + ((float)SCREEN_OFFSET_X + fX);
    m_unk24 = (float)SCREEN_OFFSET_Y + fY;
    m_unk28 = 1.0f;
    m_unk2C = 1.0f;
    m_unk80 = ((float)SCREEN_OFFSET_X + fX) - 1.0f;
    m_unk84 = (float)SCREEN_OFFSET_Y + fY;
    m_unk88 = 1.0f;
    m_unk8C = 1.0f;
    m_unk90 = ((float)SCREEN_OFFSET_X + fX) - 1.0f;
    m_unk94 = ((float)SCREEN_OFFSET_Y + fY) - m_unk22C;
    m_unk98 = 1.0f;
    m_unk9C = 1.0f;
    m_unkA0 = 1.0f + (m_unk228 + ((float)SCREEN_OFFSET_X + fX));
    m_unkA4 = (float)SCREEN_OFFSET_Y + fY;
    m_unkA8 = 1.0f;
    m_unkAC = 1.0f;
    m_unkB0 = 1.0f + (m_unk228 + ((float)SCREEN_OFFSET_X + fX));
    m_unkB4 = ((float)SCREEN_OFFSET_Y + fY) - m_unk22C;
    m_unkB8 = 1.0f;
    m_unkBC = 1.0f;
    return 1;
}

// FUNCTION: 0x0016C760 __dt__12PProgressBarFv
PProgressBar::~PProgressBar() {
}

// FUNCTION: 0x0016C7B0 __ct__12PProgressBarFv
PProgressBar::PProgressBar() {
    memset(this, 0, 0x80);
    memset((char *)this + 0x80, 0, 0x80);
    memset((char *)this + 0x100, 0, 0x80);
    memset((char *)this + 0x180, 0, 0x80);
    m_unk218 = 0;
    m_unk214 = 0;
    m_unk210 = 0;
    m_unk21C = 1.0f;
    m_unk228 = 0.0f;
    m_unk22C = 0.0f;
    m_unk230 = 1;
    m_unk234 = 0.0f;
    m_unk238 = 0.0f;
    m_unk23C = 0;
    m_unk240 = 0;
    m_unk244 = 0x3C;
    m_unk248 = 0x3C;
}
