// FLAGS: -str readonly
#include "pad.h"

// TODO(header): foreign declarations
extern "C" void scePad2Init(int);
extern "C" void scePad2End();
extern "C" void sceDbcInit();
extern "C" void sceDbcEnd();
extern "C" void scePad2DeleteSocket(int);
extern "C" int scePad2CreateSocket(int *, void *);
extern "C" void sceVibSetActParam(int, int, void *, int, void *);
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
extern "C" int scePad2GetState(int);
extern "C" int scePad2GetButtonProfile(int, void *);
extern "C" int scePad2Read(int, unsigned short *);
extern "C" unsigned int sceVibGetProfile(int, void *, int);
// Pad profile tables: ActTable$491 holds word pairs, DigitalAnalog$492 holds halfwords.

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

// FUNCTION: 0x0012CE90 EnableVibrate__3PadFb
void Pad::EnableVibrate(bool enable) {
    m_unk16F = enable;
    if (!enable) {
        m_unk16C = 0;
        m_unk16D = 0;
        if (m_unk16E != 0) {
            if (m_unk148 != 0) {
                m_unk16E = 0;
                sceVibSetActParam(m_unk100, 1, m_unk140, m_unk148, &m_unk16C);
            }
        }
    }
}

// FUNCTION: 0x0012CEF0 PauseVibrate__3PadFb
void Pad::PauseVibrate(bool pause) {
    unsigned char *p;
    if (!m_unk16F || !m_unk16E || !m_unk148) {
        return;
    }
    p = pause ? VibrateTable : &m_unk16C;
    sceVibSetActParam(m_unk100, 1, m_unk140, m_unk148, p);
}

// FUNCTION: 0x0012CF60 SetVibrate__3PadFQ23Pad7VibTypeUc
void Pad::SetVibrate(VibType type, unsigned char value) {
    if (!m_unk16F || !m_unk148 || m_unk174 != 0) {
        return;
    }
    if ((int)type >= 16) {
        CdsAssert__FPciPc("pad.cpp", 0x14C, "eType < VibMax");
    }
    m_unk16E = (type != 0) ? value : 0;
    unsigned char *p = VibrateTable + type * 2;
    switch (m_unk140[0] & 3) {
    case 1:
        m_unk16C = p[0];
        break;
    case 2:
        m_unk16C = p[1];
        break;
    case 3:
        m_unk16C = (unsigned char)(((signed char)p[1] << 1) | (signed char)p[0]);
        m_unk16D = ((signed char)p[1] < 0) ? 1 : 0;
        break;
    }
    sceVibSetActParam(m_unk100, 1, m_unk140, m_unk148, &m_unk16C);
}

// FUNCTION: 0x0012D0A0 RemapButton__3PadFUs
unsigned short Pad::RemapButton(unsigned short mask) {
    unsigned short result = 0;
    unsigned short bit = 1;
    for (int i = 0; i < 16; i++, bit += bit) {
        unsigned short entry = m_unk118[i];
        if (entry && !(mask & entry)) {
            result |= bit;
        }
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

// DRAFT: 0x0012D120 UpdatePad__3PadFv
// note: 279 words differ. Frame 0x70 vs 0x80, so every sp offset shifts; pad[1]/pad[2] not in s3/s2; scePad2GetState tests run 1,2,3,0 in the original. Tried: pointer locals plus reordered state tests (281).
void Pad::UpdatePad() {
    static int ActTable[8] = {0, 0, 0, 1, 1, 1, 0, 2};
    static unsigned short DigitalAnalog[16] = {0x8080, 0x80, 0x80ff, 0xff, 0xff80, 0x8080, 0xffff, 0x80ff,
                                               0x8000, 0x0, 0x8080, 0x80, 0xff00, 0x8000, 0xff80, 0x8080};
    unsigned short pad[3];
    unsigned short buttons = 0;
    unsigned int prof;
    unsigned short bit;
    unsigned short prev;
    unsigned short changed;
    int bits;
    int i;
    int st;
    int n;
    int r;
    int idx;

    pad[1] = 0x8080;
    pad[2] = 0x8080;
    st = scePad2GetState(m_unk100);
    m_unk184 = st;
    if (st != 1) {
        if (st == 0 || st == 3) {
            m_unk104 = 0;
            m_unk170++;
        }
        goto input;
    }
    m_unk170 = 0;
    if (m_unk104 == 0) {
        m_unk16E = 0;
        m_unk148 = 0;
        n = scePad2GetButtonProfile(m_unk100, _pad138);
        if (n <= 0) {
            goto input;
        }
        if (n >= 9) {
            CdsAssert__FPciPc("pad.cpp", 0x7C, "iProfileSize <= sizeof(mProfile)");
        }
        prof = *(unsigned int *)_pad138;
        if (prof == 0xFFFFFFFF) {
            m_unk104 = 3;
        } else if (prof == 0xFFFF9) {
            m_unk104 = 2;
        } else if (prof == 0xFFF9) {
            m_unk104 = 1;
        } else {
            m_unk104 = 4;
            printf("Unknown pad type %x\n", prof);
        }
        bit = 1;
        for (i = 0; i < 16; i++) {
            if (prof & 1) {
                m_unk118[i] = bit;
                bit = (unsigned short)(bit * 2);
            } else {
                m_unk118[i] = 0;
            }
            prof >>= 1;
        }
        n = sceVibGetProfile(m_unk100, m_unk140, 0x20);
        if ((unsigned int)n >= 5) {
            CdsAssert__FPciPc("pad.cpp", 0x9D, "iSize <= sizeof(mVibProfile)");
        }
        idx = (n > 0) ? m_unk140[0] & 3 : 0;
        *(int *)&m_unk140[4] = ActTable[idx * 2];
        m_unk148 = ActTable[idx * 2 + 1];
    }
    r = scePad2Read(m_unk100, pad);
    if (r <= 0) {
        printf("Pad2Read error\n");
    } else {
        if (r >= 25) {
            CdsAssert__FPciPc("pad.cpp", 0xA4, "iButtons <= sizeof(buf)");
        }
        buttons = RemapButton(pad[0]);
        if (m_unk104 == 1) {
            pad[2] = DigitalAnalog[(buttons >> 4) & 0xF];
        }
    }
    if (m_unk16E != 0) {
        m_unk16E--;
        if (m_unk16E == 0) {
            m_unk16C = 0;
            m_unk16D = 0;
            sceVibSetActParam(m_unk100, 1, m_unk140, m_unk148, &m_unk16C);
        } else if (m_unk16E < 10) {
            if (m_unk140[0] & 2) {
                ((unsigned char *)this + 0x16A)[m_unk140[0] & 3] -= 5;
            }
        }
    }
input:
    if (m_unk174 == 2) {
        RecordInputData(buttons);
        pad[2] = DigitalAnalog[(buttons >> 4) & 0xF];
        pad[1] = 0x7F80;
    } else if (m_unk174 == 1) {
        buttons = (unsigned short)(PlayInputData() | (buttons & 8));
        pad[2] = DigitalAnalog[(buttons >> 4) & 0xF];
        pad[1] = 0x7F80;
    }
    prev = m_unk10C;
    changed = (unsigned short)(buttons ^ prev);
    *(unsigned short *)_pad10E = prev;
    m_unk10C = buttons;
    m_unk110 = (unsigned short)(changed & buttons);
    *(unsigned short *)_pad112 = (unsigned short)(changed & prev);
    _pad112[2] = (char)(*(signed char *)&pad[2] - 0x80);
    _pad112[3] = (char)(0x7F - (pad[2] >> 8));
    _pad112[4] = (char)(*(signed char *)&pad[1] - 0x80);
    _pad112[5] = (char)(0x7F - (pad[1] >> 8));
    bits = 0;
    if (_pad112[2] >= 100) {
        bits = 0x20;
    } else if (_pad112[2] < -99) {
        bits = 0x80;
    }
    if (_pad112[3] >= 100) {
        bits |= 0x10;
    } else if (_pad112[3] < -99) {
        bits |= 0x40;
    }
    m_unk10A = (unsigned short)(bits & (m_unk108 ^ bits));
    m_unk108 = (unsigned short)bits;
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

// FUNCTION: 0x0012D6E0 __ct__3PadFv
Pad::Pad() {
    m_unk100 = -1;
}

// FUNCTION: 0x0012D6F0 __dt__3PadFv
Pad::~Pad() {
    DeletePad();
}
