#include "types.h"
#include "PProgressBar.h"

// TODO(header): foreign declarations
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern int SCREEN_OFFSET_X;
extern int SCREEN_OFFSET_Y;
extern "C" void SetReading__12PProgressBarFf(void *pThis, float fReading);

// FUNCTION: 0x0016C1F0 SetRange__12PProgressBarFf
void PProgressBar::SetRange(float fRange) {
    m_unk234 = fRange;
    float fReading = m_unk238;
    fReading = (fReading < m_unk234) ? fReading : m_unk234;
    SetReading__12PProgressBarFf(this, fReading);
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
