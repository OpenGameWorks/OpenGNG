#ifndef PSTANIMCHANNEL_H
#define PSTANIMCHANNEL_H

#include "types.h"

class PPakFile;

// One keyframe table entry: a time and a value.
struct PSTAnimKeyFrame {
    float mfTime;
    float mfValue;
};

class PSTAnimChannel {
public:
    PSTAnimChannel(PSTAnimChannel &other);
    ~PSTAnimChannel();
    int Load(PPakFile *poFile);
    float GetNumFrames();
    void EvaluateAnim(float fTime, float &fOut);

    PSTAnimChannel();
    unsigned int muNumKeyFrames;
    PSTAnimKeyFrame *mpKeyFrameTable;
    int m_unk8;
};

#endif
