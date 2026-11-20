// FLAGS: -str readonly
#include "PGrid.h"
#include "PDisplayList.h"

// TODO(header): foreign declarations
extern "C" int rand();
extern "C" void __dla__FPv(void *pData);
extern "C" void __dl__FPv(void *pData);

// Large enough that gGfxEng is addressed with lui/addiu; the display list pointer sits at +0x154C80.
struct PGridGfxEngine {
    char _pad000[0x154C80];
    PDisplayList *pDisplayList;
};
extern PGridGfxEngine gGfxEng;

// FUNCTION: 0x001F23F0 Enable__5PGridFb
void PGrid::Enable(bool bEnable) {
    if (bEnable) {
        m_2018 = 0;
        m_201C = 1.0f / m_2024;
        m_2030 = 60.0f + (240.0f * ((float)rand() / 2147483648.0f));
        m_bEnabled = 1;
        return;
    }
    m_201C = -1.0f / m_2028;
}

// FUNCTION: 0x001F2670 Render__5PGridFv
void PGrid::Render() {
    long long regs[4];
    long long *p;

    if (m_pData != 0 && m_bEnabled != 0) {
        regs[0] = 0;
        regs[1] = 0x1A;
        p = &regs[2];
        p[0] = 0x158;
        p[1] = 0x1B;
        gGfxEng.pDisplayList->SetGsRegisters((u_long128 *)regs, 2);
        gGfxEng.pDisplayList->SendGsPacket(m_pData, m_nSize * 0x10, true);
    }
}

// FUNCTION: 0x001F2B20 Destroy__5PGridFv
void PGrid::Destroy() {
    if (m_pData != 0) {
        __dla__FPv(m_pData);
        m_pData = 0;
    }
    m_nSize = 0;
    m_10 = 0;
}

// FUNCTION: 0x001F2B60 __dt__5PGridFv
PGrid::~PGrid() {
    Destroy();
}

// FUNCTION: 0x001F2BC0 __ct__5PGridFv
PGrid::PGrid() {
    m_nSize = 0;
    m_pData = 0;
    m_10 = 0;
    m_0C = 0;
    m_08 = 0;
    m_2018 = 0;
    m_201C = 0.0f;
    m_2030 = 0.0f;
    m_202C = 0;
    m_bEnabled = 0;
}
