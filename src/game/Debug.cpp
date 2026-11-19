#include "types.h"

// TODO(header): foreign declarations
extern "C" int sceDevConsPrintf(const char *pFmt, ...);

class ETiming {
public:
    void StopSubTimer(unsigned int nId);
    void StartSubTimer(unsigned int nId);
};

#include "Debug.h"

// DRAFT: 0x16A940 StopDebugTimer__5DebugFPv
// note: 1 differing line: compiler keeps the mfc0 counter in v0, original uses a3 for the subu; tried decl order, initialized counter (folds to negu), register keyword.
void Debug::StopDebugTimer(void *pArg) {
    unsigned int nNow;
    unsigned int nDelta;

    asm { .word 0x4007C801 }
    nDelta = nNow - this->m_unk10;
    if (nDelta < this->m_unk14) {
        this->m_unk14 = nDelta;
    }
    if (this->m_unk18 < nDelta) {
        this->m_unk18 = nDelta;
        this->m_unk24 = pArg;
    }
    this->m_unk1C += nDelta;
}

// FUNCTION: 0x16A9B0 ResetDebugTimer__5DebugFv
void Debug::ResetDebugTimer() {
    this->m_unk14 = 0x7FFFFFFF;
    this->m_unk18 = 0;
    this->m_unk1C = 0;
    this->m_unk20 = 0;
    this->m_unk24 = 0;
}

// FUNCTION: 0x16AB00 DebugDisp__5DebugFPc
void Debug::DebugDisp(char *pStr) {
    sceDevConsPrintf(this->m_unk00, pStr);
    this->LineFeed(pStr);
    this->m_unk2D = 1;
}

// FUNCTION: 0x16B260 StopTimer__5DebugFUi
void Debug::StopTimer(unsigned int nId) {
    if (this->m_unk0C != 0) {
        this->m_unk0C->StopSubTimer(nId);
    }
}

// FUNCTION: 0x16B290 StartTimer__5DebugFUi
void Debug::StartTimer(unsigned int nId) {
    if (this->m_unk0C != 0) {
        this->m_unk0C->StartSubTimer(nId);
    }
}
