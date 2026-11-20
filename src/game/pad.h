#ifndef PAD_H
#define PAD_H

#include "types.h"

// Controller state record. Members are named by offset from the object start.
class Pad {
public:
    enum eInputMode { eInputOff = 0, eInputPlay = 1, eInputRecord = 2, MaxInput = 3 };
    struct InputData { unsigned short m_unk0; unsigned short m_unk2; };
    enum VibType { VibMax = 16 };

    ~Pad();
    int ReadNew();
    int ReadPush();
    int IsConnected();
    unsigned short PlayInputData();
    void RecordInputData(unsigned short buttons);
    void SetInputMode(eInputMode mode, InputData *pData, int size);
    void InitPad(int arg);
    void EnableVibrate(bool enable);
    void PauseVibrate(bool pause);
    void SetVibrate(VibType type, unsigned char value);
    unsigned short RemapButton(unsigned short mask);
    void DeletePad();

    char _pad000[0x100];
    int m_unk100;                   // 0x100 scePad2 socket handle, -1 when none
    int m_unk104;                   // 0x104 cleared with the socket
    unsigned short m_unk108;        // 0x108 gate: when set, the low button bits merge in
    unsigned short m_unk10A;        // 0x10A pushed-state button word
    unsigned short m_unk10C;        // 0x10C new-state button word
    char _pad10E[2];
    unsigned short m_unk110;        // 0x110 base word for the push read
    char _pad112[0x118 - 0x112];
    unsigned short m_unk118[16];    // 0x118 button remap table, one halfword per button
    char _pad138[0x140 - 0x138];
    unsigned char m_unk140[8];      // 0x140 vibration parameter block
    int m_unk148;                   // 0x148 vibration parameter size
    char _pad14C[0x16C - 0x14C];
    unsigned char m_unk16C;         // 0x16C vibration state
    unsigned char m_unk16D;         // 0x16D vibration state
    unsigned char m_unk16E;         // 0x16E vibration active flag
    unsigned char m_unk16F;         // 0x16F vibration enable flag
    unsigned char m_unk170;         // 0x170 pad mode index, connected when below 8
    char _pad171[3];
    int m_unk174;                   // 0x174 input mode (eInputMode), 0 when not recording or playing
    unsigned short *m_unk178;       // 0x178 input sequence table, 4 halfwords per entry
    int m_unk17C;                   // 0x17C index into the input sequence table
    int m_unk180;                   // 0x180 input sequence capacity
};

void PadInit();
void PadEnd();

#endif
