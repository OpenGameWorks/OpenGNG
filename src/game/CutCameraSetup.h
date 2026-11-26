#ifndef CUTCAMERASETUP_H
#define CUTCAMERASETUP_H

#include "types.h"
#include "EntityBaseClass.h"

class Camera;

// Layout from the Execute and constructor asm: EntityBaseClass occupies 0x000..0x18F.
class CutCameraSetup : public EntityBaseClass {
public:
    CutCameraSetup();
    virtual ~CutCameraSetup();
    virtual void Execute();
    virtual const char *GetClassName();
    virtual void SetEditableVars(char *pSrc);

    char _pad190[0x20];
    int m_unk1B0;               // 0x1B0 cut camera mode, switched on in Execute (1, 2, 3)
    unsigned int m_unk1B4;      // 0x1B4 argument to the Camera setup call
    unsigned int m_unk1B8;      // 0x1B8 argument to the Camera setup call
    float m_unk1BC;             // 0x1BC argument to the Camera setup call
    unsigned int m_unk1C0;      // 0x1C0 argument to the Camera setup call
    float m_unk1C4;             // 0x1C4 first point, copied into a PVec3 temporary
    float m_unk1C8;             // 0x1C8 second point
    float m_unk1CC;             // 0x1CC third point
    char _pad1D0[0xC];          // 0x1D0..0x1DB
    float m_unk1DC;             // 0x1DC second-mode point
    float m_unk1E0;             // 0x1E0
    float m_unk1E4;             // 0x1E4
    char _pad1E8[0xC];          // 0x1E8..0x1F3
    float m_unk1F4;             // 0x1F4 third-point group
    float m_unk1F8;             // 0x1F8
    float m_unk1FC;             // 0x1FC
    char _pad200[0xC];          // 0x200..0x20B
    float m_unk20C;             // 0x20C fourth-point group
    float m_unk210;             // 0x210
    float m_unk214;             // 0x214
    char _pad218[0xC];          // 0x218..0x223
    float m_unk224;             // 0x224 argument to the Camera setup call
    int m_unk228;               // 0x228 argument to the Camera setup call
    int m_unk22C;               // 0x22C
    int m_unk230;               // 0x230
    int m_unk234;               // 0x234
    int m_unk238;               // 0x238 flag argument
    float m_unk23C;             // 0x23C vector group
    float m_unk240;             // 0x240
    float m_unk244;             // 0x244
    char _pad248[4];
    float m_unk24C;             // 0x24C
    char _pad250[4];
    int m_unk254;               // 0x254 flag argument
    int m_unk258;               // 0x258
    Camera *m_pMainCamera;      // 0x25C set to gEng + 0x19760 in Execute
};

#endif
