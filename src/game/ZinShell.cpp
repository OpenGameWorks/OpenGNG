#include "types.h"
#include "ZinShell.h"

// TODO(header): foreign declarations
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int eLoadClass, unsigned int nFlags);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bFlagA, bool bFlagB);
extern "C" void __dl__FPv(void *);
extern "C" void memcpy(void *, const void *, unsigned int);
extern unsigned char __vt__8ZinShell[];

// FUNCTION: 0x001AF330 __dt__8ZinShellFv
ZinShell::~ZinShell() {
    m_unk0 = __vt__8ZinShell;
    __dt__15EntityBaseClassFv(this, 0);
}

// FUNCTION: 0x001AF3A0 SetEditableVars__8ZinShellFPc
void ZinShell::SetEditableVars(char *arg0) {
    memcpy(&m_unk1B0, arg0, 0x20);
    float temp = m_unk1B4;
    if (temp == 0.0f && m_unk1B8 == 0.0f && m_unk1BC == 0.0f) {
        m_unk1D0[0] = (m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190)[0];
        m_unk1D0[1] = 50.0f + (m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190)[1];
        m_unk1D0[2] = (m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190)[2];
    } else {
        m_unk1D0[0] = temp;
        m_unk1D0[1] = m_unk1B8;
        m_unk1D0[2] = m_unk1BC;
    }
    m_unk1E0[0] = (m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190)[0];
    m_unk1E0[1] = (m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190)[1];
    m_unk1E0[2] = (m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190)[2];
}

// DRAFT: 0x001AF500 SetShellStartAndDest__8ZinShellFRA4_fRA4_f
// note: 12 words differ; loads match the original's registers, but the stores run in reverse order (forward stores give a different register mapping), tried 6 local-declaration and store-order variants.
void ZinShell::SetShellStartAndDest(float (&arg0)[4], float (&arg1)[4]) {
    float d = arg0[3];
    float c = arg0[2];
    float b = arg0[1];
    float a = arg0[0];
    m_unk1D0[3] = d;
    m_unk1D0[2] = c;
    m_unk1D0[1] = b;
    m_unk1D0[0] = a;
    float h = arg1[3];
    float g = arg1[2];
    float f = arg1[1];
    float e = arg1[0];
    m_unk1E0[3] = h;
    m_unk1E0[2] = g;
    m_unk1E0[1] = f;
    m_unk1E0[0] = e;
}

// DRAFT: 0x001AFE40 __ct__8ZinShellFv
// note: 35 words differ; original keeps this in 0x1C(sp) and reloads it before each store with no s0 use, ours keeps it in s0. Tried local pointer copy and an empty dtor-bearing member in the header (DIFF 37), neither helped.
ZinShell::ZinShell() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 2, 0);
    m_unk0 = __vt__8ZinShell;
    EnableSleep__15EntityBaseClassFbb(this, false, false);
    m_unk214 = 0;
    m_unk218 = 0;
    m_unk22D = 0;
    m_unk22C = 0;
    m_unk224 = 0;
    m_unk228 = 0;
    m_unk1B0 = 0;
    m_unk1B4 = 0;
    m_unk1B8 = 0;
    m_unk1BC = 0;
}
