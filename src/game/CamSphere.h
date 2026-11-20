#ifndef CAMSPHERE_H
#define CAMSPHERE_H

#include "types.h"
#include "EntityBaseClass.h"

// Layout from CamSphere.cpp: EntityBaseClass occupies 0x000..0x18F.
class CamSphere : public EntityBaseClass {
public:
    CamSphere();
    virtual ~CamSphere();
    virtual void Execute();

    char _pad190[0x20];
    float m_unk1B0;             // 0x1B0 sphere parameters, copied to 0x1C0 on the -1 state
    float m_unk1B4;             // 0x1B4
    float m_unk1B8;             // 0x1B8
    float m_unk1BC;             // 0x1BC radius source, copied to 0x1D0
    float m_unk1C0;             // 0x1C0 sphere centre x, also the 16-byte block copied to 0x80 of m_unk3C
    float m_unk1C4;             // 0x1C4 sphere centre y
    float m_unk1C8;             // 0x1C8 sphere centre z
    float m_unk1CC;             // 0x1CC sphere centre w
    float m_unk1D0;             // 0x1D0 radius passed to Camera::CamCollideSphere
};

#endif
