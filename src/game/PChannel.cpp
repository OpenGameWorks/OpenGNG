// FLAGS: -str readonly
#include "types.h"
#include "PChannel.h"
#include "PCDFile.h"

// TODO(header): foreign declarations
class PPakFile;
void CdsAssert(char *pFile, int nLine, char *pExpr);

// DRAFT: 0x0018D4E0 AnimateBox__8PChannelFfRUc
// note: 6 words differ; the original keeps this+0x10 in a0 and sums unkA*8 before (nIndex-1)<<5, ours loads unkA into v0 and folds +0x10 last. Tried: int nCount (20->7), hoisted base pointer (frame grows), local offset, member array base at 0x10, term reorder (7->6), signed nIndex (worse).
void *PChannel::AnimateBox(float fTime, unsigned char &ucMask) {
    void *pResult = 0;
    int nCount = m_unk6;
    char *pRec = (char *)this + 0x10;
    if (nCount != 0) {
        do {
            if (fTime < *(float *)pRec) {
                break;
            }
            nCount--;
            pRec += 8;
        } while (nCount != 0);
    }
    ucMask = *(unsigned char *)(pRec - 4);
    unsigned int nIndex = ucMask & ~0xE0;
    if (nIndex != 0) {
        if (m_unk8 < nIndex) {
            CdsAssert("PChannel.cpp", 0x218, "iMask <= muNumKeyFrames[1]");
        }
        pResult = (char *)this + 0x10 + ((nIndex - 1) << 5) + m_unkA * 8;
    }
    return pResult;
}

// FUNCTION: 0x0018DDA0 LoadChannel__FP8PPakFile
PChannel *LoadChannel(PPakFile *pFile) {
    int nCount;
    char *pBuf;
    if (((PCDFile *)pFile)->Read(&nCount, 4) != 4) {
        return 0;
    }
    pBuf = new char[nCount];
    if (pBuf == 0) {
        CdsAssert("PChannel.cpp", 0x3B, "pChannel");
    }
    if (((PCDFile *)pFile)->Read(pBuf, nCount) != nCount) {
        delete[] pBuf;
        pBuf = 0;
    }
    return (PChannel *)pBuf;
}

// FUNCTION: 0x0018DE40 __dt__8PChannelFv
PChannel::~PChannel() {
    m_unk0 = 0;
    m_unkA = 0;
    m_unk8 = 0;
    m_unk6 = 0;
}
