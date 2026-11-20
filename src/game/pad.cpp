#include "pad.h"

// TODO(header): foreign declarations
extern "C" void scePad2Init(int);
extern "C" void scePad2End();
extern "C" void sceDbcInit();
extern "C" void sceDbcEnd();
extern "C" void scePad2DeleteSocket(int);
extern "C" void sceVibSetActParam(int, int, void *, int);
// Engine size is unknown; the placeholder keeps gEng out of small data (threshold 8 bytes).
class Engine { public: char _pad000[0x19A80]; int m_unk19A80; };
extern Engine gEng;

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

// FUNCTION: 0x0012CD80 PlayInputData__3PadFv
unsigned short Pad::PlayInputData() {
    int idx = m_unk17C;
    unsigned short *entry = m_unk178 + idx * 2;
    if ((unsigned int)gEng.m_unk19A80 >= (unsigned short)*entry) {
        entry += 2;
        m_unk17C = idx + 1;
    }
    return entry[1];
}

// DRAFT: 0x0012CE90 EnableVibrate__3PadFb
// note: 18 words differ; MW keeps this in a3 where the original uses t0 (copy is then a delay-slot addiu t0,t0,0x16C), original size 0x5C vs ours 0x58. Tried nested-if and local self pointer.
void Pad::EnableVibrate(bool enable) {
    m_unk16F = enable;
    if (!enable) {
        m_unk16C = 0;
        m_unk16D = 0;
        if (m_unk16E != 0) {
            if (m_unk148 != 0) {
                m_unk16E = 0;
                sceVibSetActParam(m_unk100, 1, m_unk140, m_unk148);
            }
        }
    }
}

// DRAFT: 0x0012D0A0 RemapButton__3PadFUs
// note: 10 words differ; original reloads bit with addu bit,bit,bit and an extra andi on the entry, ours sign-extends bit via dsll32/dsra32 before sll. Tried int/uint bit, bit+=bit, cast mask, uint entry.
unsigned short Pad::RemapButton(unsigned short mask) {
    unsigned short result = 0;
    unsigned short bit = 1;
    for (int i = 0; i < 16; i++) {
        unsigned short entry = m_unk118[i];
        if (entry != 0 && (mask & entry) == 0) {
            result |= bit;
        }
        bit = bit << 1;
    }
    return result;
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

// FUNCTION: 0x0012D690 DeletePad__3PadFv
void Pad::DeletePad() {
    if (m_unk100 >= 0) {
        scePad2DeleteSocket(m_unk100);
        m_unk100 = -1;
        m_unk104 = 0;
        m_unk170 = 0;
    }
}

// FUNCTION: 0x0012D6F0 __dt__3PadFv
Pad::~Pad() {
    DeletePad();
}
