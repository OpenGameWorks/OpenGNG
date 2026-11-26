#ifndef CAMCYLINDER_H
#define CAMCYLINDER_H

#include "types.h"
#include "EntityBaseClass.h"

// Layout from CamCylinder.cpp: EntityBaseClass occupies 0x000..0x18F.
class CamCylinder : public EntityBaseClass {
public:
    CamCylinder();
    virtual ~CamCylinder();
    virtual void Execute();
    void SetCylinderParams(float fA, float fB, float fC, float fD, float fE);
    const char *GetClassName();
    void SetEditableVars(char *);

    char _pad190[0x20];
    float m_unk1B0;             // 0x1B0 cylinder parameters, written by SetCylinderParams
    float m_unk1B4;             // 0x1B4
    float m_unk1B8;             // 0x1B8
    float m_unk1BC;             // 0x1BC
    float m_unk1C0;             // 0x1C0
    char _pad1C4[0xC];
    float m_unk1D0;             // 0x1D0 copy of the parameters, passed to the camera
    float m_unk1D4;             // 0x1D4
    float m_unk1D8;             // 0x1D8
    float m_unk1DC;             // 0x1DC
    float m_unk1E0;             // 0x1E0 camera-collision radius
    float m_unk1E4;             // 0x1E4 camera-collision height
};

#endif
