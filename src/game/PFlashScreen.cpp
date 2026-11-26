#include "types.h"
#include "PFlashScreen.h"
#include "PDisplayList.h"
#include "PSound.h"
#include "GsUtils.h"

// TODO(header): foreign declarations
extern char gGfxEng[1504384];
extern short gDebugExportVars;
extern PSound gSound;

// DRAFT: 0x001CFD60 Render__12PFlashScreenFv
// note: DIFF 48 words; colour packing registers and aRegs pointer allocation (original reuses s0+8 for &aRegs[3], ours uses sp+0x68); 64-bit nColour variants gave 67-76
void PFlashScreen::Render() {
    if (gDebugExportVars != 0) {
        if (m_unk14 == 0) {
            unsigned long long aRegs[4];
            unsigned int nColour;
            unsigned int nR = (int)m_unk20 & 0xFF;
            nColour = nR | (((int)m_unk24 & 0xFF) << 8) | (((int)m_unk28 & 0xFF) << 16) | (((int)m_unk2C & 0xFF) << 24);
            m_unk70 = ((unsigned long long)0x3F800000 << 32) | nColour;

            aRegs[0] = 1;
            aRegs[1] = 0x1A;
            aRegs[2] = 0;
            aRegs[3] = 0x1B;
            ((PDisplayList *)*(void **)(gGfxEng + 0x154C80))->SetGsRegisters((u_long128 *)aRegs, 2);
            ((PDisplayList *)*(void **)(gGfxEng + 0x154C80))->SendGsPacket(m_unk30, 0x2D0, true);

            aRegs[0] = 0;
            aRegs[1] = 0x1A;
            aRegs[2] = 0x18;
            aRegs[3] = 0x1B;
            ((PDisplayList *)*(void **)(gGfxEng + 0x154C80))->SetGsRegisters((u_long128 *)aRegs, 2);
        }
    }
}

// FUNCTION: 0x001CFEB0 Animate__12PFlashScreenFv
void PFlashScreen::Animate() {
    if (m_unk14 == 0) {
        if (m_unk0 == 0) {
            float f = m_unk2C - m_unk4;
            f = (f > 0.0f) ? f : 0.0f;
            m_unk2C = f;
            if (0.0f == f) {
                m_unk2C = m_unk8;
                m_unkC -= 1;
            }
        } else {
            m_unk0 = m_unk0 - 1;
        }
        if (m_unkC == 0) {
            m_unk14 = 1;
            int nSound = m_unk10;
            if (nSound >= 0) {
                gSound.PlaySoundUbiquitous((unsigned int)nSound);
            }
        }
    }
}

// FUNCTION: 0x001CFF70 Init__12PFlashScreenFffffUiUiUii
void PFlashScreen::Init(float fR, float fG, float fB, float fA, unsigned int nFadeIn, unsigned int nHold, unsigned int nFadeOut, int nSound) {
    if (m_unk14 != 0) {
        m_unk20 = fR;
        m_unk24 = fG;
        m_unk28 = fB;
        m_unk2C = fA;
        m_unk8 = fA;
        m_unk10 = nSound;
        m_unk0 = (nFadeIn > 1) ? nFadeIn : 1;
        float fDiv = (float)nHold;
        m_unk4 = fA / fDiv;
        m_unk14 = 0;
        m_unkC = nFadeOut;
        GsInitFogSprite((tagFogSpritePacket *)m_unk30, 0, 0, 0, 0);
        m_unk50 = 0x48;
        m_unk40 = 0x30000;
    }
}

// FUNCTION: 0x001D0040 __dt__12PFlashScreenFv
PFlashScreen::~PFlashScreen() {
}

// FUNCTION: 0x001D0090 __ct__12PFlashScreenFv
PFlashScreen::PFlashScreen() {
    m_unk14 = 1;
    m_unk0 = 0;
    m_unk4 = 0.0f;
}
