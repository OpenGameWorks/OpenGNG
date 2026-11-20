#ifndef PSCREENBLURFX_H
#define PSCREENBLURFX_H

#include "types.h"

struct tagBlurStrip;
struct tagGsScreenBlurPacket;

class PScreenBlurFx {
public:
    PScreenBlurFx();

    int Init(float fA1, float fA2, float fA3, float fA4, float fA5, float fA6, float fA7, bool bFlag);
    void SkipToFadeOut();
    void InitBlurStrip(tagBlurStrip *pStrip, char cA, short sA, short sB, short sC, short sD, float fA, bool bFlag, float fB, float fC);
    void InitBlurPacket(tagGsScreenBlurPacket *pPacket, int nWidth, int nHeight, char cA, char cB, char cC, char cD);
    void WobbleSTGrids(tagGsScreenBlurPacket *pPacket, float fAngle);
    void Animate(float fDelta);
    void Render();

private:
    char _pad00[0x10];
    char m_unk10[0x8440];
    int m_unk8450;
    float m_unk8454;
    float m_unk8458;
    float m_unk845C;
    float m_unk8460;
    float m_unk8464;
    float m_unk8468;
    float m_unk846C;
    float m_unk8470[4];
    int m_unk8480[4];
    int m_unk8490;
    int m_unk8494;
    int m_unk8498;
    float m_unk849C;
    int m_unk84A0;
    bool m_unk84A4;
};

#endif
