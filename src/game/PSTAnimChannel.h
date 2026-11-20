#ifndef PSTANIMCHANNEL_H
#define PSTANIMCHANNEL_H

#include "types.h"

class PPakFile;

// One keyframe table entry: a time and a value.
struct PSTAnimKeyFrame {
    float m_unk0;
    float m_unk4;
};

class PSTAnimChannel {
public:
    PSTAnimChannel(PSTAnimChannel &other);
    ~PSTAnimChannel();
    int Load(PPakFile *pFile);
    float GetNumFrames();
    void EvaluateAnim(float fTime, float &fOut);

    int m_unk0;
    PSTAnimKeyFrame *m_unk4;
    int m_unk8;
};

#endif
