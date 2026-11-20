#ifndef PLIGHT_H
#define PLIGHT_H

#include "types.h"

class PMeshNode;
class PPakFile;

class PLight {
public:
    PLight();
    ~PLight();
    void ComputeColor(float *pOut, float *pPos);
    float GetBrightness(float *pPos);
    int Load(PPakFile *pFile);

    /* 0x00 */ u_long128 m_unk0;
    /* 0x10 */ u_long128 m_unk10;
    /* 0x20 */ u_long128 m_unk20;
    /* 0x30 */ float m_unk30[4];
    /* 0x40 */ float m_unk40;
    /* 0x44 */ int m_unk44;
    /* 0x48 */ signed char m_unk48;
    /* 0x49 */ char _pad49[0x3];
    /* 0x4C */ PMeshNode *m_unk4C;
    /* 0x50 */ float m_unk50;
    /* 0x54 */ char _pad54[0xC];
    /* 0x60 */ float m_unk60[4];
};

#endif
