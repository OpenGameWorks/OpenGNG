#ifndef ANIMSEGMENTTRIGGER_H
#define ANIMSEGMENTTRIGGER_H

#include "types.h"

// AnimSegmentTrigger derives from EntityBaseClass at offset 0; the base is not declared here,
// so members are named by their offset from the object start.
class EntityBaseClass;

class AnimSegmentTrigger {
public:
    int PlayerInsideTriggerVolume();
    int OnHitEvent(EntityBaseClass *pOther, int nArg1, unsigned int nFlags, unsigned int nArg3);
    void Execute();
    int GetTallyType();
    const char *GetClassName();
    void SetEditableVars(char *);

    void *m_unk0;               // 0x000 vtable pointer (inherited from EntityBaseClass)
    char _pad004[0x20 - 0x04];
    int m_unk20;                // 0x020 state selector (switch in Execute)
    char _pad024[0x3C - 0x24];
    char *m_unk3C;              // 0x03C object whose +0x80 matrix is the trigger origin
    char _pad040[0xE9 - 0x40];
    unsigned char m_unkE9;      // 0x0E9 active flag
    char _pad0EA[0x10C - 0xEA];
    int m_unk10C;               // 0x10C flags (bit 25 cleared on apparition)
    char _pad110[0x190 - 0x110];
    float m_unk190[4];          // 0x190 trigger origin matrix row
    char _pad1A0[0x1B0 - 0x1A0];
    float m_unk1B0;             // 0x1B0 trigger range
    float m_unk1B4[4];          // 0x1B4 trigger box
    char _pad1C4[0x1E4 - 0x1C4];
    int m_unk1E4;               // 0x1E4 volume mode selector
    int m_unk1E8;               // 0x1E8 hit state (must be 1)
    int m_unk1EC;               // 0x1EC sequence index
    int m_unk1F0;               // 0x1F0 anim ID
    short m_unk1F4;             // 0x1F4 anim data start
    char _pad1F6[2];
    short m_unk1F8;             // 0x1F8 anim data start
    char _pad1FA[2];
    short m_unk1FC;             // 0x1FC anim data end
    char _pad1FE[2];
    short m_unk200;             // 0x200 anim data end
    char _pad202[2];
    float m_unk204;             // 0x204 anim speed, copied to 0x224
    unsigned int m_unk208;      // 0x208 cut camera ID
    int m_unk20C;               // 0x20C cut camera flag
    int m_unk210;               // 0x210 apparition flag
    int m_unk214;               // 0x214 gEng flag selector
    short m_unk218;             // 0x218 AnimData copy
    short m_unk21A;
    short m_unk21C;
    short m_unk21E;
    short m_unk220;
    short m_unk222;
    float m_unk224;             // 0x224 AnimData speed
    unsigned char m_unk228;     // 0x228 anim active flag
    unsigned char m_unk229;     // 0x229 player on trigger flag
    unsigned char m_unk22A;     // 0x22A hit-triggered flag
};

#endif
