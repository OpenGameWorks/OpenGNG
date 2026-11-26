// FLAGS: -str readonly
#include "PSTAnim.h"
#include "types.h"

// TODO(header): foreign declarations
extern "C" void sceVu0UnitMatrix(float *pMatrix);
extern "C" void *__dt__14PSTAnimChannelFv(void *pThis, short nFlag);
extern "C" void __dla__FPv(void *pBlock);
extern "C" void __dl__FPv(void *pBlock);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" int Read__7PCDFileFPvUi(void *pThis, void *pBuffer, unsigned int nSize);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" PSTAnimChannel *__ct__14PSTAnimChannelFv(PSTAnimChannel *pThis);
extern "C" PSTAnimChannel *__ct__14PSTAnimChannelFR14PSTAnimChannel(PSTAnimChannel *pThis, PSTAnimChannel *pSrc);
extern "C" int Load__14PSTAnimChannelFP8PPakFile(PSTAnimChannel *pThis, PPakFile *pFile);
extern "C" float GetNumFrames__14PSTAnimChannelFv(PSTAnimChannel *pThis);
extern "C" void EvaluateAnim__14PSTAnimChannelFfRf(PSTAnimChannel *pThis, float fTime, float *pOut);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);

// DRAFT: 0x00199BE0 Animate__7PSTAnimFfb
// note: 89 words differ from 0x4C: the bnez guarding the m_unk8 assert takes a lui from its fallthrough in its delay slot where the original has nop; the arg copy and first assert match; tried !m_unk8 form (no change).
void PSTAnim::Animate(float fTime, bool bFlag) {
    float fValue;

    if (m_unk4 == 0) {
        CdsAssert__FPciPc("PSTAnim.cpp", 0xBF, "mpChannelTable");
    }
    if (m_unk8 == 0) {
        CdsAssert__FPciPc("PSTAnim.cpp", 0xC0, "muNumChannels");
    }
    if (m_unk0 != 0) {
        if (m_unk2 != 0) {
            return;
        }
        m_unk2 = m_unk3;
        if (bFlag) {
            m_unkC = fTime;
        } else {
            m_unkC += fTime;
        }
        if (!(m_unkC <= m_unk14)) {
            m_unkC = m_unk10;
            if (m_unk18 > 0) {
                int nLoop = m_unk1C - 1;
                if (nLoop < 0) {
                    nLoop = 0;
                }
                m_unk1C = nLoop;
            }
        }
        if (m_unk1C != 0) {
            for (unsigned int i = 0; i < (unsigned char)m_unk8; i++) {
                PSTAnimChannel *pChannel = m_unk4[i];
                if (pChannel == 0) {
                    CdsAssert__FPciPc("PSTAnim.cpp", 0xE5, "apChannel");
                }
                EvaluateAnim__14PSTAnimChannelFfRf(pChannel, m_unkC, &fValue);
                int nType = *(int *)((char *)pChannel + 8);
                if (nType == 7) {
                    m_unk50 = fValue;
                } else if (nType == 8) {
                    m_unk54 = fValue;
                }
            }
        }
    }
}

// FUNCTION: 0x00199DA0 Load__7PSTAnimFP8PPakFile
int PSTAnim::Load(PPakFile *pFile) {
    unsigned char aHeader[16];
    unsigned int i;

    if (pFile == 0) {
        CdsAssert__FPciPc("PSTAnim.cpp", 0x79, "poFile");
    }
    if (Read__7PCDFileFPvUi(pFile, aHeader, 0x10) != 0x10) {
        return 0;
    }
    m_unk8 = aHeader[0];
    m_unkC = 0.0f;
    m_unkA = 0;
    m_unk4 = (PSTAnimChannel **)__nwa__FUi(m_unk8 * 4);
    if (m_unk4 == 0) {
        return 0;
    }
    memset(m_unk4, 0, m_unk8 * 4);
    for (i = 0; i < m_unk8; i++) {
        PSTAnimChannel *pChannel = (PSTAnimChannel *)__nw__FUi(0xC);
        if (pChannel != 0) {
            pChannel = __ct__14PSTAnimChannelFv(pChannel);
        }
        m_unk4[i] = pChannel;
        if (m_unk4[i] == 0) {
            return 0;
        }
        if (Load__14PSTAnimChannelFP8PPakFile(m_unk4[i], pFile) == 0) {
            return 0;
        }
        float fFrames = GetNumFrames__14PSTAnimChannelFv(m_unk4[i]);
        unsigned int nFrames = (unsigned int)fFrames;
        if ((unsigned int)(unsigned short)m_unkA < (unsigned int)nFrames) {
            m_unkA = (short)nFrames;
        }
    }
    m_unk1 = 1;
    m_unk0 = 1;
    m_unk10 = 0.0f;
    unsigned short nMax = (unsigned short)m_unkA;
    m_unk14 = (float)nMax;
    return 1;
}

// FUNCTION: 0x00199F90 Clone__7PSTAnimFP7PSTAnim
void PSTAnim::Clone(PSTAnim *pSrc) {
    if (pSrc == 0) {
        CdsAssert__FPciPc("PSTAnim.cpp", 0x4C, "poSource");
    }
    m_unkC = 0.0f;
    m_unk18 = -1;
    m_unk1C = -1;
    m_unk2 = 0;
    m_unk3 = 1;
    m_unk8 = pSrc->m_unk8;
    m_unk4 = (PSTAnimChannel **)__nwa__FUi(m_unk8 * 4);
    unsigned int i = 0;
    if (m_unk4 == 0) {
        CdsAssert__FPciPc("PSTAnim.cpp", 0x58, "mpChannelTable");
        i = 0;
    }
    for (i = 0; i < (unsigned char)m_unk8; i++) {
        PSTAnimChannel *pSrcChannel = pSrc->m_unk4[i];
        if (pSrcChannel == 0) {
            CdsAssert__FPciPc("PSTAnim.cpp", 0x5F, "apSrcChannel");
        }
        PSTAnimChannel *pChannel = (PSTAnimChannel *)__nw__FUi(0xC);
        if (pChannel != 0) {
            pChannel = __ct__14PSTAnimChannelFR14PSTAnimChannel(pChannel, pSrcChannel);
        }
        m_unk4[i] = pChannel;
        if (m_unk4[i] == 0) {
            CdsAssert__FPciPc("PSTAnim.cpp", 0x62, "mpChannelTable[auCount]");
        }
        float fFrames = GetNumFrames__14PSTAnimChannelFv(m_unk4[i]);
        unsigned int nFrames = (unsigned int)fFrames;
        if ((unsigned int)(unsigned short)m_unkA < (unsigned int)nFrames) {
            m_unkA = (short)nFrames;
        }
    }
    m_unk1 = 1;
    m_unk0 = 1;
    m_unk10 = 0.0f;
    unsigned short nMax = (unsigned short)m_unkA;
    m_unk14 = (float)nMax;
}

// FUNCTION: 0x0019A190 __dt__7PSTAnimFv
extern "C" PSTAnim *__dt__7PSTAnimFv(PSTAnim *pThis, short nFlag) {
    if (pThis != 0) {
        if (pThis->m_unk4 != 0) {
            if (pThis->m_unk1 != 0) {
                for (unsigned int i = 0; i < pThis->m_unk8; i++) {
                    PSTAnimChannel *pChannel = pThis->m_unk4[i];
                    if (pChannel != 0) {
                        __dt__14PSTAnimChannelFv(pChannel, 1);
                        pThis->m_unk4[i] = 0;
                    }
                }
                __dla__FPv(pThis->m_unk4);
                pThis->m_unk4 = 0;
                pThis->m_unk1 = 0;
            }
        }
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x0019A260 __ct__7PSTAnimFv
PSTAnim::PSTAnim() {
    sceVu0UnitMatrix(m_unk20);
    m_unkA = 0;
    m_unkC = 0.0f;
    m_unk8 = 0;
    m_unk4 = 0;
    m_unk1 = 0;
    m_unk10 = 0.0f;
    m_unk14 = -1.0f;
    m_unk18 = -1;
    m_unk1C = -1;
    m_unk0 = 0;
    m_unk2 = 0;
    m_unk3 = 1;
}
