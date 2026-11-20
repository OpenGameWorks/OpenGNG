#ifndef PSTANIM_H
#define PSTANIM_H

#include "types.h"

class PPakFile;
class PSTAnimChannel;

class PSTAnim {
public:
    PSTAnim();
    void Animate(float fTime, bool bFlag);
    int Load(PPakFile *pFile);

    unsigned char m_unk0;
    unsigned char m_unk1;
    unsigned char m_unk2;
    unsigned char m_unk3;
    PSTAnimChannel **m_unk4;
    unsigned char m_unk8;
    short m_unkA;
    float m_unkC;
    float m_unk10;
    float m_unk14;
    int m_unk18;
    int m_unk1C;
    float m_unk20[12];
    float m_unk50;
    float m_unk54;
};

#endif
