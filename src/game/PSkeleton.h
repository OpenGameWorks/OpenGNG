#ifndef PSKELETON_H
#define PSKELETON_H

#include "types.h"

class PArray;
class PObjectDisplayList;

class PSkeleton {
public:
    // Slots 0-2 are not yet identified; VSlot3 sits at vtable offset 0x14.
    virtual void VSlot0();
    virtual void VSlot1();
    virtual void VSlot2();
    virtual void VSlot3(unsigned int nId);

    void EnableBone(unsigned int *pIds, bool bEnable);
    void SetFrameTime(float fTime);
    void BuildDispList();
    void InitMembers();

    // 0x000 vtable pointer is implicit (virtual functions).
    unsigned int m_unk4;                // 0x004 cleared by InitMembers
    char _pad008[0x10 - 0x8];
    void *m_unk10;                      // 0x010 PMesh *, passed to PObjectDisplayList::Create
    unsigned int m_unk14;               // 0x014 child count
    unsigned int m_unk18;               // 0x018 child index
    void **m_unk1C;                     // 0x01C child array
    char _pad020[0x24 - 0x20];
    void *m_unk24;                      // 0x024 frame source; vtable slot 0x1C returns the frame value
    char _pad028[0x34 - 0x28];
    float m_unk34;                      // 0x034 frame time
    float m_unk38;                      // 0x038 previous frame time
    char _pad03C[0x3E - 0x3C];
    unsigned char m_unk3E;              // 0x03E flags; 0x08 set by SetFrameTime
    char _pad03F[0xD4 - 0x3F];
    bool m_unkD4;                       // 0x0D4 out flag from PObjectDisplayList::Create
    char _padD5[0xF8 - 0xD5];
    PObjectDisplayList *m_unkF8;        // 0x0F8
    char _pad0FC[0x150 - 0xFC];
    char m_unk150[0x4];                 // 0x150 PArray, passed by address
    int m_unk154;                       // 0x154
    int m_unk158;                       // 0x158
    int m_unk15C;                       // 0x15C
};

#endif
