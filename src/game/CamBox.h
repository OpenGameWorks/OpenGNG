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
    char m_unk1B0[0xC8];        // 0x1B0 trigger box, passed to MathAPI::PointInBoundBox
    float m_unk278;             // 0x278 centre x, copied to the Distance argument block
    float m_unk27C;             // 0x27C centre y
    float m_unk280;             // 0x280 centre z
    float m_unk284;             // 0x284 radius compared against Distance
    float m_unk288;             // 0x288 second centre x
    float m_unk28C;             // 0x28C second centre y
    float m_unk290;             // 0x290 second centre z
    float m_unk294;             // 0x294 second radius
    int m_unk298;               // 0x298 trigger mode, switched on in PointInsideTriggerArea
    char _pad29C[0x8];          // 0x29C..0x2A3
    unsigned char m_unk2A4;     // 0x2A4 cleared by the constructor
};

#endif
