// FLAGS: -str readonly
#include "PSTAnimChannel.h"
#include "types.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void __dla__FPv(void *pMem);
extern "C" void *memcpy(void *, const void *, unsigned int);
class PCDFile {
public:
    int Read(void *pBuf, unsigned int nSize);
};

// DRAFT: 0x0019A2D0 GetNumFrames__14PSTAnimChannelFv
// note: 4 words: the m_unk4/m_unk0 loads land in v1/v0 where the original uses v0/v1 (addu order now matches with the shifted count first). Tried indexed, pointer-arithmetic, [-1], unsigned index and declaration-order variants.
float PSTAnimChannel::GetNumFrames() {
    if (m_unk4 == 0) {
        CdsAssert__FPciPc("PSTAnimChannel.cpp", 0x8E, "mpKeyFrameTable");
    }
    if (m_unk0 == 0) {
        CdsAssert__FPciPc("PSTAnimChannel.cpp", 0x8F, "muNumKeyFrames");
    }
    int nBase = (int)m_unk4 - 8;
    return *(float *)((m_unk0 << 3) + nBase);
}

// DRAFT: 0x0019A350 EvaluateAnim__14PSTAnimChannelFfRf
// note: DIFF 54 words; the original's 2-keyframe branch (count == 2 jumps into the lerp) and its loop register layout are missing, and the first branch differs at 0x60.
void PSTAnimChannel::EvaluateAnim(float fTime, float &fOut) {
    if (m_unk4 == 0) {
        CdsAssert__FPciPc("PSTAnimChannel.cpp", 0x53, "mpKeyFrameTable");
    }
    if (m_unk0 == 0) {
        CdsAssert__FPciPc("PSTAnimChannel.cpp", 0x54, "muNumKeyFrames");
    }
    PSTAnimKeyFrame *pNext = m_unk4;
    int nIdx = 0;
    while (nIdx < m_unk0) {
        pNext = &m_unk4[nIdx];
        if (pNext->m_unk0 > fTime) {
            break;
        }
        nIdx++;
    }
    if (nIdx >= m_unk0) {
        fOut = pNext->m_unk4;
    } else if (nIdx - 1 >= 0) {
        PSTAnimKeyFrame *pPrev = &m_unk4[nIdx - 1];
        fOut = pPrev->m_unk4 + ((fTime - pPrev->m_unk0) / (pNext->m_unk0 - pPrev->m_unk0)) * (pNext->m_unk4 - pPrev->m_unk4);
    } else {
        fOut = pNext->m_unk4;
    }
}

// FUNCTION: 0x0019A490 Load__14PSTAnimChannelFP8PPakFile
int PSTAnimChannel::Load(PPakFile *pFile) {
    if (pFile == 0) {
        CdsAssert__FPciPc("PSTAnimChannel.cpp", 0x2B, "poFile");
    }
    int aHeader[4];
    if (((PCDFile *)pFile)->Read(aHeader, 0x10) != 0x10) {
        return 0;
    }
    if (aHeader[0] == 0) {
        return 0;
    }
    m_unk8 = aHeader[1];
    m_unk4 = (PSTAnimKeyFrame *)__nwa__FUi(aHeader[0] * 8);
    if (m_unk4 == 0) {
        return 0;
    }
    unsigned int nBytes = aHeader[0] * 8;
    if ((int)nBytes != ((PCDFile *)pFile)->Read(m_unk4, nBytes)) {
        __dla__FPv(m_unk4);
        m_unk4 = 0;
        return 0;
    }
    m_unk0 = aHeader[0];
    return 1;
}

// FUNCTION: 0x0019A580 __ct__14PSTAnimChannelFR14PSTAnimChannel
PSTAnimChannel::PSTAnimChannel(PSTAnimChannel &other) {
    m_unk0 = other.m_unk0;
    m_unk8 = other.m_unk8;
    m_unk4 = (PSTAnimKeyFrame *)__nwa__FUi(m_unk0 * 8);
    if (m_unk4 == 0) {
        CdsAssert__FPciPc("PSTAnimChannel.cpp", 0x20, "mpKeyFrameTable");
    }
    memcpy(m_unk4, other.m_unk4, m_unk0 * 8);
}

// FUNCTION: 0x0019A610 __dt__14PSTAnimChannelFv
PSTAnimChannel::~PSTAnimChannel() {
    if (m_unk4 != 0) {
        __dla__FPv(m_unk4);
    }
}

// FUNCTION: 0x0019A670 __ct__14PSTAnimChannelFv
PSTAnimChannel::PSTAnimChannel() {
    m_unk4 = 0;
    m_unk0 = 0;
}
