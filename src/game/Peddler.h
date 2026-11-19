#ifndef PEDDLER_H
#define PEDDLER_H

class EntityBaseClass;

class Peddler {
public:
    bool TrappedEntityRemoved();
    void OutputDebug();
    void OnTimerEvent(unsigned int arg0);
    unsigned int FindItem(int arg0);

    char _pad000[0x20];
    int m_unk20;                    // 0x020
    char _pad024[0x200 - 0x24];
    EntityBaseClass *m_unk200;      // 0x200
    char _pad204[0x288 - 0x204];
    int m_unk288;                   // 0x288
    char _pad28C[0x29C - 0x28C];
    unsigned char m_unk29C;         // 0x29C
    char _pad29D[0x2A7 - 0x29D];
    unsigned char m_unk2A7;         // 0x2A7
    char _pad2A8[0x2BC - 0x2A8];
    int m_unk2BC;                   // 0x2BC
    char _pad2C0[0x2C4 - 0x2C0];
    int m_unk2C4;                   // 0x2C4
    char _pad2C8[0x2D4 - 0x2C8];
    int m_unk2D4;                   // 0x2D4
    unsigned char m_unk2D8;         // 0x2D8
};

unsigned int GetItemID(unsigned int arg0);

#endif
