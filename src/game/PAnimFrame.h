#ifndef PANIMFRAME_H
#define PANIMFRAME_H

#include "PAnim.h"

// Frame-based animation: the PAnim base (size 0x20) followed by frame range and enable fields. Size 0x34.
// Virtuals are declared in __vt__10PAnimFrame slot order.
class AnimData;

class PAnimFrame : public PAnim {
public:
    PAnimFrame(short nFrame);
    PAnimFrame(PAnim *pSrc);
    virtual int Load(PPakFile *pFile);
    virtual int Load(PPakFile *pFile, tagMeshNodeAnimationHeader *pHeader);
    virtual float Animate(float fTime, float fUnused, float (*pMatrix)[4], float *pOut, bool bFlag);
    virtual signed char IsAnimate();
    virtual void SetFrameTime(float);
    virtual short GetEndFrame();
    virtual void SetEndFrame(short);
    virtual short GetLoop();
    virtual void SetAllAnimFlags(AnimData *pData);
    virtual void SetAnimLoopCount(int);
    virtual float GetFrameTime();
    virtual void EnableAnim(bool bEnable);
    virtual void SetLoopFrame(short);
    virtual void SetLoopEndFrame(short);
    virtual void SetFrameRate(float);
    virtual float GetFrameRate();
    virtual int IsPAnimFrame();
    void RestoreAnim(PAnimFrame *pSrc);
    float AnimateFrame(float fTime);
    short m_unk20;                   // 0x20
    short m_unk22;                   // 0x22
    short m_unk24;                   // 0x24
    short m_unk26;                   // 0x26
    short m_unk28;                   // 0x28
    signed char m_unk2A;             // 0x2A
    char _pad2B[1];                  // 0x2B
    float m_unk2C;                   // 0x2C
    float m_unk30;                   // 0x30
};

#endif
