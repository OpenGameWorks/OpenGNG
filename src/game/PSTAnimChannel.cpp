// FLAGS: -str readonly
#include "PSTAnimChannel.h"
#include "Debug.h"
#include "types.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *, const void *, unsigned int);
class PCDFile {
public:
    int Read(void *pBuf, unsigned int nSize);
};

// DRAFT: 0x0019A2D0 GetNumFrames__14PSTAnimChannelFv
// note: 3 words: mpKeyFrameTable[muNumKeyFrames - 1] with an unsigned index local; the original folds the -1 into the table base (addiu -8 on the table) where ours subtracts 1 from the count. Tried direct, pointer, base-minus-one, p--, (q-1)->, char* arithmetic and int-arithmetic indexing (5-8; every -1-on-base form folds -8 into the lwc1 offset), raw member reads (4-5), local declaration order (3), table-first local (3-8), inline accessors taking this/table with the -1 inside or outside (3-8), Prev() helper (8), raw unsigned arithmetic (5).
float PSTAnimChannel::GetNumFrames() {
    if (mpKeyFrameTable == 0) {
        CdsAssert("PSTAnimChannel.cpp", 0x8E, "mpKeyFrameTable");
    }
    if (muNumKeyFrames == 0) {
        CdsAssert("PSTAnimChannel.cpp", 0x8F, "muNumKeyFrames");
    }
    unsigned int nIdx = muNumKeyFrames - 1;
    return mpKeyFrameTable[nIdx].mfTime;
}

// DRAFT: 0x0019A350 EvaluateAnim__14PSTAnimChannelFfRf
// note: DIFF 53 words; the original's 2-keyframe branch (count == 2 jumps into the lerp) and its loop register layout are missing, and the first branch differs at 0x60.
void PSTAnimChannel::EvaluateAnim(float fTime, float &fOut) {
    if (mpKeyFrameTable == 0) {
        CdsAssert("PSTAnimChannel.cpp", 0x53, "mpKeyFrameTable");
    }
    if (muNumKeyFrames == 0) {
        CdsAssert("PSTAnimChannel.cpp", 0x54, "muNumKeyFrames");
    }
    PSTAnimKeyFrame *pNext = mpKeyFrameTable;
    int nIdx = 0;
    while (nIdx < muNumKeyFrames) {
        pNext = &mpKeyFrameTable[nIdx];
        if (pNext->mfTime > fTime) {
            break;
        }
        nIdx++;
    }
    if (nIdx >= muNumKeyFrames) {
        fOut = pNext->mfValue;
    } else if (nIdx - 1 >= 0) {
        PSTAnimKeyFrame *pPrev = &mpKeyFrameTable[nIdx - 1];
        fOut = pPrev->mfValue + ((fTime - pPrev->mfTime) / (pNext->mfTime - pPrev->mfTime)) * (pNext->mfValue - pPrev->mfValue);
    } else {
        fOut = pNext->mfValue;
    }
}

// FUNCTION: 0x0019A490 Load__14PSTAnimChannelFP8PPakFile
int PSTAnimChannel::Load(PPakFile *poFile) {
    if (poFile == 0) {
        CdsAssert("PSTAnimChannel.cpp", 0x2B, "poFile");
    }
    int aHeader[4];
    if (((PCDFile *)poFile)->Read(aHeader, 0x10) != 0x10) {
        return 0;
    }
    if (aHeader[0] == 0) {
        return 0;
    }
    m_unk8 = aHeader[1];
    mpKeyFrameTable = new PSTAnimKeyFrame[aHeader[0]];
    if (mpKeyFrameTable == 0) {
        return 0;
    }
    unsigned int nBytes = aHeader[0] * 8;
    if ((int)nBytes != ((PCDFile *)poFile)->Read(mpKeyFrameTable, nBytes)) {
        delete[] mpKeyFrameTable;
        mpKeyFrameTable = 0;
        return 0;
    }
    muNumKeyFrames = aHeader[0];
    return 1;
}

// FUNCTION: 0x0019A580 __ct__14PSTAnimChannelFR14PSTAnimChannel
PSTAnimChannel::PSTAnimChannel(PSTAnimChannel &other) {
    muNumKeyFrames = other.muNumKeyFrames;
    m_unk8 = other.m_unk8;
    mpKeyFrameTable = new PSTAnimKeyFrame[muNumKeyFrames];
    if (mpKeyFrameTable == 0) {
        CdsAssert("PSTAnimChannel.cpp", 0x20, "mpKeyFrameTable");
    }
    memcpy(mpKeyFrameTable, other.mpKeyFrameTable, muNumKeyFrames * 8);
}

// FUNCTION: 0x0019A610 __dt__14PSTAnimChannelFv
PSTAnimChannel::~PSTAnimChannel() {
    if (mpKeyFrameTable != 0) {
        delete[] mpKeyFrameTable;
    }
}

// FUNCTION: 0x0019A670 __ct__14PSTAnimChannelFv
PSTAnimChannel::PSTAnimChannel() {
    mpKeyFrameTable = 0;
    muNumKeyFrames = 0;
}
