// FLAGS: -str readonly
#include "types.h"
#include "PChannel.h"
#include "PCDFile.h"

// TODO(header): foreign declarations
class PPakFile;
void CdsAssert(char *pFile, int nLine, char *pExpr);
struct tagAnimationKeyFrameSplineData;
float GetSpline(float fDt, tagAnimationKeyFrameSplineData *pA, tagAnimationKeyFrameSplineData *pNext);

// DRAFT: 0x0018D4E0 AnimateBox__8PChannelFfRUc
// note: 4 diff lines; only the v0/v1 register swap of (nIndex-1)<<5 and this+0x10 remains. Kept (unsigned int)this + 0x10 + m_unkA*8 + ((nIndex-1)<<5) (6->4). Tried: int nCount (20->7), hoisted base (46), local offset, member array base, plain term reorders (7), signed int cast (4), unkA<<3 (4), (nIndex-1)*32 (5).
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
        pResult = (char *)((unsigned int)this + 0x10 + m_unkA * 8 + ((nIndex - 1) << 5));
    }
    return pResult;
}

// DRAFT: 0x0018D5A0 EvaluateAnim__8PChannelFfPfif
// note: 420 words differ, size 0x64c vs 0x6e0; case 3 VU0 lqc2 run not in asm, case 2 assert at +0x110 vs +0xFC, GetSpline/BezierVec sites differ; zeroing pKey inside the branch gave 421
void PChannel::EvaluateAnim(float fTime, float *pOut, int nCount, float fDefault) {
    switch (m_unk4) {
    case 1: {
        float *pSrc = (float *)((char *)this + 0x14);
        int nIdx;
        for (nIdx = 0; nIdx < nCount; nIdx++) {
            float fVal = *pSrc;
            if (fVal == 1.1754944e-38f) {
                fVal = fDefault;
            }
            pOut[nIdx] = fVal;
            pSrc++;
        }
        break;
    }
    case 2: {
        void *pKey[6] = {0, 0, 0, 0, 0, 0};
        unsigned int nRec = 0;
        int nLeft;
        if (m_unk6 == 0) {
            CdsAssert("PChannel.cpp", 0x128, "muNumKeyFrames[0]");
        }
        if ((int)m_unk6 >= 2) {
            while (nRec < m_unk6) {
                char *pRec = (char *)this + 0x10 + nRec * 0x10;
                if (!(*(float *)pRec <= fTime)) {
                    break;
                }
                if (*(float *)(pRec + 4) != 1.1754944e-38f) {
                    pKey[0] = pRec;
                }
                if (*(float *)(pRec + 8) != 1.1754944e-38f) {
                    pKey[2] = pRec;
                }
                if (*(float *)(pRec + 0xC) != 1.1754944e-38f) {
                    pKey[4] = pRec;
                }
                nRec++;
            }
            nLeft = 0;
            if (pKey[0] != 0) {
                nLeft = 1;
            }
            if (pKey[2] != 0) {
                nLeft += 1;
            }
            if (pKey[4] != 0) {
                nLeft += 1;
            }
            while (nLeft != 0 && nRec < m_unk6) {
                char *pRec = (char *)this + 0x10 + nRec * 0x10;
                if (pKey[1] == 0 && *(float *)(pRec + 4) != 1.1754944e-38f) {
                    pKey[1] = pRec;
                    nLeft--;
                }
                if (pKey[3] == 0 && *(float *)(pRec + 8) != 1.1754944e-38f) {
                    pKey[3] = pRec;
                    nLeft--;
                }
                if (pKey[5] == 0 && *(float *)(pRec + 0xC) != 1.1754944e-38f) {
                    pKey[5] = pRec;
                    nLeft--;
                }
                nRec++;
            }
            {
                int nIdx;
                for (nIdx = 0; nIdx < nCount; nIdx++) {
                    char *pBefore = (char *)pKey[nIdx * 2];
                    char *pAfter = (char *)pKey[nIdx * 2 + 1];
                    if (pBefore != 0 && pAfter != 0) {
                        float fT0 = *(float *)pBefore;
                        float fV1 = *(float *)(pBefore + 4 + nIdx * 4);
                        pOut[nIdx] = fV1 + ((fTime - fT0) * (*(float *)(pAfter + 4 + nIdx * 4) - fV1)) / (*(float *)pAfter - fT0);
                    } else if (pBefore != 0) {
                        pOut[nIdx] = *(float *)(pBefore + 4 + nIdx * 4);
                    } else {
                        pOut[nIdx] = fDefault;
                    }
                }
            }
        }
        break;
    }
    case 3: {
        char *pKey = (char *)this + 0x10;
        unsigned int ch;
        for (ch = 0; ch < (unsigned int)nCount; ch++) {
            unsigned short cnt = (&m_unk6)[ch];
            if (cnt == 0) {
                pOut[ch] = fDefault;
            } else {
                char *pA = pKey;
                char *pNext = 0;
                float fRes;
                if (fTime <= *(float *)pA) {
                    fRes = *(float *)(pA + 4);
                } else if (!(fTime < *(float *)(pKey + (cnt - 1) * 0x10))) {
                    fRes = *(float *)(pKey + (cnt - 1) * 0x10 + 4);
                } else {
                    int nFound = 0;
                    unsigned int k = 0;
                    fRes = *(float *)(pA + 4);
                    while (k < (unsigned int)(cnt - 1)) {
                        pNext = pA + 0x10;
                        if (!(*(float *)pNext <= fTime)) {
                            nFound = 1;
                            break;
                        }
                        pA = pNext;
                        k++;
                    }
                    if (nFound == 0 && cnt >= 2) {
                        fRes = *(float *)(pNext + 4);
                    }
                    if (nFound != 0) {
                        float fT0 = *(float *)pA;
                        float fDt = fTime - fT0;
                        if (fDt == 0.0f) {
                            fRes = *(float *)(pA + 4);
                        } else if (*(float *)(pA + 0xC) == *(float *)(pNext + 8)) {
                            float fV1 = *(float *)(pA + 4);
                            fRes = fV1 + ((*(float *)(pNext + 4) - fV1) * fDt) / (*(float *)pNext - fT0);
                        } else {
                            fRes = GetSpline(fDt, (tagAnimationKeyFrameSplineData *)pA, (tagAnimationKeyFrameSplineData *)pNext);
                        }
                    }
                }
                pOut[ch] = fRes;
            }
            pKey += cnt * 0x10;
        }
        break;
    }
    case 4: {
        char *pRec = (char *)this + 0x10;
        int nI = 0;
        while (nI < (int)m_unk6) {
            if (!(fTime < *(float *)pRec)) {
                pRec += 8;
                nI = (nI + 1) & 0xFF;
            } else {
                break;
            }
        }
        int nVal = 0;
        if (nI != 0) {
            nVal = *(int *)(pRec - 4);
        }
        float fOut;
        if (nVal >= 0) {
            fOut = (float)nVal;
        } else {
            fOut = 2.0f * (float)(((unsigned int)nVal >> 1) | (nVal & 1));
        }
        pOut[1] = fOut;
        break;
    }
    case 7: {
        int nIdx7 = (int)fTime;
        float fFrac = fTime - (float)nIdx7;
        char *pVals = (char *)this + 0x10;
        unsigned int ch;
        for (ch = 0; ch < (unsigned int)nCount; ch++) {
            unsigned short cnt = (&m_unk6)[ch];
            float fRes = fDefault;
            if (cnt == 0) {
            } else if ((unsigned int)nIdx7 >= (unsigned int)(cnt - 1)) {
                fRes = *(float *)(pVals + cnt * 4 - 4);
            } else {
                fRes = *(float *)(pVals + nIdx7 * 4);
                if (fFrac != 0.0f) {
                    fRes += fFrac * (*(float *)(pVals + 4 + nIdx7 * 4) - fRes);
                }
            }
            pVals += cnt * 4;
            pOut[ch] = fRes;
        }
        break;
    }
    }
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
