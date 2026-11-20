#include "pad.h"

// TODO(header): foreign declarations
extern "C" void scePad2Init(int);
extern "C" void scePad2End();
extern "C" void sceDbcInit();
extern "C" void sceDbcEnd();

// FUNCTION: 0x0012CC60 ReadNew__3PadFv
int Pad::ReadNew() {
    unsigned int v1 = m_unk108;
    int v0 = m_unk10C;
    if (v1 != 0) {
        v0 = (v0 & 0xFF0F) | (v1 & 0xFFFF);
    }
    return v0;
}

// FUNCTION: 0x0012CC80 ReadPush__3PadFv
int Pad::ReadPush() {
    int v0 = m_unk110;
    if (m_unk108 != 0) {
        v0 = (v0 & 0xFF0F) | m_unk10A;
    }
    return v0;
}

// FUNCTION: 0x0012D100 IsConnected__3PadFv
int Pad::IsConnected() {
    int v0 = m_unk170 < 8;
    if (v0 == 0) {
        v0 = m_unk174 != 0;
    }
    return v0;
}

// FUNCTION: 0x0012D5B0 PadEnd__Fv
void PadEnd() {
    scePad2End();
    sceDbcEnd();
}

// FUNCTION: 0x0012D5E0 PadInit__Fv
void PadInit() {
    sceDbcInit();
    scePad2Init(0);
}
