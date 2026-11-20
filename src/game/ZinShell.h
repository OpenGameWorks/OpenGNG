#ifndef ZINSHELL_H
#define ZINSHELL_H

#include "types.h"

// ZinShell derives from EntityBaseClass at offset 0; the base is not declared here,
// so members are named by their offset from the object start.

// Object pointed to by ZinShell::m_unk3C; SetEditableVars reads only its float block at +0x80.
class ZinShellSource {
public:
    char _pad000[0x80];
    float m_unk80[4];
};

class ZinShell {
public:
    ZinShell();
    ~ZinShell();
    void SetEditableVars(char *arg0);
    void SetShellStartAndDest(float (&arg0)[4], float (&arg1)[4]);

    void *m_unk0;               // 0x000 vtable pointer (inherited from EntityBaseClass)
    char _pad004[0x3C - 0x04];
    ZinShellSource *m_unk3C;    // 0x03C
    char _pad040[0x190 - 0x40];
    float m_unk190[8];          // 0x190 fallback vector, used when m_unk3C is null
    int m_unk1B0;               // 0x1B0 editable-vars block, copied by memcpy (0x20 bytes)
    float m_unk1B4;             // 0x1B4
    float m_unk1B8;             // 0x1B8
    float m_unk1BC;             // 0x1BC
    char _pad1C0[0x1D0 - 0x1C0];
    float m_unk1D0[4];          // 0x1D0 start vector
    float m_unk1E0[4];          // 0x1E0 destination vector
    char _pad1F0[0x214 - 0x1F0];
    int m_unk214;               // 0x214
    int m_unk218;               // 0x218
    char _pad21C[0x224 - 0x21C];
    int m_unk224;               // 0x224
    int m_unk228;               // 0x228
    char m_unk22C;              // 0x22C
    char m_unk22D;              // 0x22D
    char _pad22E[0x230 - 0x22E];
};

#endif
