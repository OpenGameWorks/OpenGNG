#ifndef PRENDERPASS_H
#define PRENDERPASS_H

#include "types.h"

class PPakFile;
class PArray;
class PSTAnim;

class PRenderPass {
public:
    PRenderPass();
    ~PRenderPass();
    int Load(PPakFile *pFile, PArray *pArr);

    unsigned char m_unk0;
    unsigned char m_unk1;
    unsigned char m_unk2;
    unsigned char m_unk3;
    int m_unk4;
    int m_unk8;
    char _padC[4];
    float m_unk10;
    float m_unk14;
    float m_unk18;
    float m_unk1C;
    long long m_unk20;
    PSTAnim *m_unk28;
    int m_unk2C;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3C;
    int m_unk40;
    int m_unk44;
    int m_unk48;
};

#endif
