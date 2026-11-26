#ifndef ZINSHELL_H
#define ZINSHELL_H

#include "types.h"
#include "EntityBaseClass.h"

// Object pointed to by EntityBaseClass::m_unk3C when ZinShell uses a source; SetEditableVars reads only its float block at +0x80.
class ZinShellSource {
public:
    char _pad000[0x80];
    float m_unk80[4];
    float m_unk90;              // 0x90 yaw, written by Execute
};

class ZinShell : public EntityBaseClass {
public:
    ZinShell();
    virtual ~ZinShell();
    void SetEditableVars(char *arg0);
    void SetShellStartAndDest(float (&arg0)[4], float (&arg1)[4]);
    void Execute();
    const char *GetClassName();

    float m_unk190[8];          // 0x190 fallback vector (position at 0x190, yaw at 0x1A0), used when m_unk3C is null
    int m_unk1B0;               // 0x1B0 editable-vars block, copied by memcpy (0x20 bytes)
    float m_unk1B4;             // 0x1B4
    float m_unk1B8;             // 0x1B8
    float m_unk1BC;             // 0x1BC
    float m_unk1C0[3];          // 0x1C0 trigger-check vector
    float m_unk1CC;             // 0x1CC trigger radius
    float m_unk1D0[4];          // 0x1D0 start vector
    float m_unk1E0[4];          // 0x1E0 destination vector
    float m_unk1F0[4];          // 0x1F0 direction vector
    float m_unk200[3];          // 0x200 chaser vector
    float m_unk20C;             // 0x20C
    float m_unk210;             // 0x210 speed scale
    int m_unk214;               // 0x214
    float m_unk218;             // 0x218 orbit angle, degrees
    int m_unk21C;               // 0x21C orbit count
    int m_unk220;               // 0x220 apparition id
    int m_unk224;               // 0x224
    int m_unk228;               // 0x228
    char m_unk22C;              // 0x22C
    char m_unk22D;              // 0x22D
    char _pad22E[0x230 - 0x22E];
    int m_unk230;               // 0x230 sound reference
    void *m_unk234;             // 0x234 apparition pointer
    void *m_unk238;             // 0x238 apparition handle
    char _pad23C[0x240 - 0x23C];
};

#endif
