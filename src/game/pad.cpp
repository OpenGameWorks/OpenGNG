// FLAGS: -str readonly
#include "pad.h"

// TODO(header): foreign declarations
extern "C" void scePad2Init(int);
extern "C" void scePad2End();
extern "C" void sceDbcInit();
extern "C" void sceDbcEnd();
extern "C" void scePad2DeleteSocket(int);
extern "C" int scePad2CreateSocket(int *, void *);
extern "C" void sceVibSetActParam(int, int, void *, int);
extern "C" int sceOpen(const char *, int);
extern "C" int sceWrite(int, void *, int);
extern "C" int sceClose(int);
extern "C" int printf(const char *fmt, ...);
extern "C" void CdsAssert__FPciPc(const char *pFile, int nLine, char *pExpr);
// Engine size is unknown; the placeholder keeps gEng out of small data (threshold 8 bytes).
class Engine { public: char _pad000[0x19A80]; int m_unk19A80; };
extern Engine gEng;
// Vibration lookup table, two bytes per entry (16 entries used by SetVibrate). Placeholder size.
extern unsigned char VibrateTable[0x20];

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

// FUNCTION: 0x0012CCA0 RecordInputData__3PadFUs
void Pad::RecordInputData(unsigned short buttons) {
    int idx = m_unk17C;
    unsigned short *entry = m_unk178 + idx * 2;
    int rec = gEng.m_unk19A80;
    if (buttons != entry[1]) {
        m_unk17C = idx + 1;
        if (m_unk17C >= m_unk180 || (buttons & 8)) {
            entry[0] = 0xFFFF;
            entry[1] = 0;
            m_unk174 = 0;
            int fd = sceOpen("host0:DemoDt.dat", 0x202);
            if (fd >= 0) {
                sceWrite(fd, m_unk178, m_unk17C * 4);
                sceClose(fd);
                printf("Demo data created\n");
            }
        } else {
            entry[0] = (unsigned short)rec;
            entry[3] = buttons;
        }
    }
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

// FUNCTION: 0x0012CDC0 SetInputMode__3PadFQ23Pad10eInputModePQ23Pad9InputDatai
void Pad::SetInputMode(eInputMode mode, InputData *pData, int size) {
    if (mode >= MaxInput) {
        CdsAssert__FPciPc("pad.cpp", 0x182, "eMode < MaxInput");
    }
    switch (mode) {
    case eInputRecord:
        if (pData == 0) {
            CdsAssert__FPciPc("pad.cpp", 0x185, "pData");
        }
        pData->m_unk0 = 0xFFFF;
        pData->m_unk2 = 0;
    case eInputPlay:
        m_unk178 = (unsigned short *)pData;
        m_unk180 = size;
        if (pData == 0) {
            mode = eInputOff;
        }
        m_unk17C = 0;
        gEng.m_unk19A80 = 0;
        break;
    }
    m_unk174 = mode;
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

// DRAFT: 0x0012CEF0 PauseVibrate__3PadFb
// note: 21 words differ; original keeps a dead pause ? VibrateTable : this+0x16C pointer in t0 with a frame, MW drops the dead value and reads through a1 without the a2 copy. Tried a local pointer and an empty arm.
void Pad::PauseVibrate(bool pause) {
    if (m_unk16F != 0 && m_unk16E != 0) {
        int size = m_unk148;
        if (size != 0) {
            sceVibSetActParam(m_unk100, 1, m_unk140, size);
        }
    }
}

// DRAFT: 0x0012CF60 SetVibrate__3PadFQ23Pad7VibTypeUc
// note: 64 words differ, size 0x114 vs 0x140; original tests the 174 branch with a shared epilogue at 0x12D088 and compares switch cases 3,2,1 with the table pointer computed first. Tried a ternary for 16D (65), an if-chain selector (66), and the bool form kept (64).
void Pad::SetVibrate(VibType type, unsigned char value) {
    if (m_unk16F != 0) {
        if (m_unk148 != 0) {
            if (m_unk174 == 0) {
                if ((int)type >= 16) {
                    CdsAssert__FPciPc("pad.cpp", 0x14C, "eType < VibMax");
                }
                m_unk16E = (type != 0) ? value : 0;
                unsigned char *p = VibrateTable + type * 2;
                switch (m_unk140[0] & 3) {
                case 3:
                    m_unk16C = (unsigned char)(((signed char)p[1] << 1) | (signed char)p[0]);
                    m_unk16D = ((signed char)p[1] < 0);
                    break;
                case 2:
                    m_unk16C = p[1];
                    break;
                case 1:
                    m_unk16C = p[0];
                    break;
                }
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

// FUNCTION: 0x0012D610 InitPad__3PadFi
void Pad::InitPad(int arg) {
    // Six-element array: the original reserves a 0x40-byte frame, and smaller arrays give 0x30.
    int params[6];
    params[0] = 2;
    params[1] = arg;
    params[2] = 0;
    m_unk100 = scePad2CreateSocket(params, this);
    if (m_unk100 < 0) {
        CdsAssert__FPciPc("pad.cpp", 0x2C, "miSocket >= 0");
    }
    m_unk104 = 0;
    m_unk16F = 1;
    m_unk174 = 0;
    m_unk178 = 0;
    m_unk170 = 0;
    m_unk108 = 0;
    m_unk10A = 0;
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
