#ifndef CAMBOX_H
#define CAMBOX_H

#include "types.h"
#include "EntityBaseClass.h"

// Layout from CamBox.cpp: EntityBaseClass occupies 0x000..0x18F.
class CamBox : public EntityBaseClass {
public:
    CamBox();
    virtual ~CamBox();
    virtual void Execute();
    virtual void GetClassName();
    virtual void SetEditableVars(char *pSrc);
    void OnSleepEvent();
    int PointInsideTriggerArea(float (*pPoint)[4], float (*pOther)[4]);

    char _pad190[0x20];
    char m_unk1B0[0x30];        // 0x1B0 trigger box, passed to MathAPI::PointInBoundBox (0xC8 bytes in total)
    int m_unk1E0;               // 0x1E0 mode, switched on in Execute (2, 3, 5, 6)
    float m_unk1E4;             // 0x1E4
    int m_unk1E8;               // 0x1E8 signed value, converted to float in Execute
    float m_unk1EC;             // 0x1EC
    float m_unk1F0;             // 0x1F0
    float m_unk1F4;             // 0x1F4
    char _pad1F8[0x10];
    int m_unk208;               // 0x208
    int m_unk20C;               // 0x20C
    float m_unk210;             // 0x210
    float m_unk214;             // 0x214
    float m_unk218;             // 0x218
    float m_unk21C;             // 0x21C
    float m_unk220;             // 0x220 rotation about X
    float m_unk224;             // 0x224 rotation about Y
    float m_unk228;             // 0x228 rotation about Z
    float m_unk22C;             // 0x22C
    float m_unk230;             // 0x230
    float m_unk234;             // 0x234
    char _pad238[0xC];
    float m_unk244;             // 0x244
    float m_unk248;             // 0x248
    float m_unk24C;             // 0x24C
    char _pad250[0xC];
    float m_unk25C;             // 0x25C
    float m_unk260;             // 0x260
    float m_unk264;             // 0x264
    char _pad268[0xC];
    int m_unk274;               // 0x274
    float m_unk278;             // 0x278 centre x, copied to the Distance argument block
    float m_unk27C;             // 0x27C centre y
    float m_unk280;             // 0x280 centre z
    float m_unk284;             // 0x284 radius compared against Distance
    float m_unk288;             // 0x288 second centre x
    float m_unk28C;             // 0x28C second centre y
    float m_unk290;             // 0x290 second centre z
    float m_unk294;             // 0x294 second radius
    int m_unk298;               // 0x298 trigger mode, switched on in PointInsideTriggerArea
    int m_unk29C;               // 0x29C
    int m_unk2A0;               // 0x2A0
    unsigned char m_unk2A4;     // 0x2A4 cleared by the constructor
};

#endif
