// FLAGS: -str readonly
#include "types.h"
#include "PAnim.h"
#include "PCDFile.h"

// TODO(header): foreign declarations
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" void __dt__8PChannelFv(PChannel *pThis, short nFlag);
PChannel *LoadChannel(PPakFile *pFile);

// TODO(header): PChannel is a placeholder shape here; only the type word at offset 0 and EvaluateAnim matter.
class PChannel {
public:
    void EvaluateAnim(float fTime, float *pOut, int nMode, float fParam);

    int m_unk0;
};

// FUNCTION: 0x0018C810 IsPAnimFrame__5PAnimFv
int PAnim::IsPAnimFrame() {
    return 0;
}

// FUNCTION: 0x0018C830 SetFrameRate__5PAnimFf
void PAnim::SetFrameRate(float) {
}

// FUNCTION: 0x0018C840 SetLoopEndFrame__5PAnimFs
void PAnim::SetLoopEndFrame(short) {
}

// FUNCTION: 0x0018C850 SetLoopFrame__5PAnimFs
void PAnim::SetLoopFrame(short) {
}

// FUNCTION: 0x0018C860 EnableAnim__5PAnimFb
void PAnim::EnableAnim(bool) {
}

// FUNCTION: 0x0018C870 SetAnimLoopCount__5PAnimFi
void PAnim::SetAnimLoopCount(int) {
}

// FUNCTION: 0x0018C890 SetEndFrame__5PAnimFs
void PAnim::SetEndFrame(short) {
}

// FUNCTION: 0x0018C8A0 SetFrameTime__5PAnimFf
void PAnim::SetFrameTime(float) {
}

// DRAFT: 0x0018C8B0 FindChannel__5PAnimF9eAnimType
// note: DIFF 7; original shares one epilogue for null and match returns, ours duplicates the return tail. Tried: else-branch (14), single-exit break (20), pointer-walk loop (20).
PChannel *PAnim::FindChannel(eAnimType eType)
{
    int i;
    for (i = 0; i < 5; i++) {
        PChannel *pChannel = m_unkC[i];
        if (pChannel == 0) {
            return pChannel;
        }
        if ((int)eType == *(int *)pChannel) {
            return pChannel;
        }
    }
    return 0;
}

// FUNCTION: 0x0018C910 Animate__5PAnimFffPA4_fPfb
float PAnim::Animate(float fTime, float fUnused, float (*pMatrix)[4], float *pOut, bool bFlag)
{
    int i;
    if (m_unk8 == 0) {
        return fTime;
    }
    for (i = 0; i < 5; i++) {
        PChannel *pChannel = m_unkC[i];
        if (pChannel == 0) {
            break;
        }
        switch (pChannel->m_unk0) {
        case 1:
            pChannel->EvaluateAnim(fTime, (float *)pMatrix, 3, 0.0f);
            break;
        case 2:
            pChannel->EvaluateAnim(fTime, pMatrix[1], 3, 0.0f);
            break;
        case 3:
            pChannel->EvaluateAnim(fTime, pMatrix[2], 3, 1.0f);
            break;
        case 4:
            if (bFlag) {
                pChannel->EvaluateAnim(fTime, pOut, 1, 1.0f);
            }
            break;
        case 6:
        case 9:
            if (bFlag) {
                pChannel->EvaluateAnim(fTime, pOut, 1, 0.0f);
            }
            break;
        }
    }
    return fTime;
}

// FUNCTION: 0x0018CA90 Load__5PAnimFP8PPakFile
int PAnim::Load(PPakFile *pFile)
{
    char buf[0x10];
    if (pFile == 0) {
        CdsAssert("PAnim.cpp", 0x79, "poFile");
    }
    if (((PCDFile *)pFile)->Read(buf, 0x10) != 0x10) {
        return 0;
    }
    return this->Load(pFile, (tagMeshNodeAnimationHeader *)buf);
}

// DRAFT: 0x0018CB20 Load__5PAnimFP8PPakFileP26tagMeshNodeAnimationHeader
// note: DIFF 12; remaining: lh vs lhu on m_unk0 at 0x4C, loop-exit b offset at 0xA4, return-tail andi/sltu order at 0x180-0x19C. Tried: count test inversion (83 to 16), unsigned loop bound (15), !(tag!=5) tail (14), assert > 5 (12), tag==5 tail (13).
int PAnim::Load(PPakFile *pFile, tagMeshNodeAnimationHeader *pHeader)
{
    int i;
    int tag;
    if (pHeader->m_unk4 > 5) {
        CdsAssert("PAnim.cpp", 0x38, "pHeader->uNumChannels <= CHANNEL_MAX");
    }
    m_unk8 = pHeader->m_unk0 - 1;
    if (m_unk8 < 0) {
        m_unk8 = 0;
    }
    m_unk4 = pHeader->m_unk8;
    if (pHeader->m_unk4 != 0) {
        m_unkB = 1;
        for (i = 0; i < pHeader->m_unk4; i++) {
            PChannel *pChannel = LoadChannel(pFile);
            if (pChannel == 0) {
                Cleanup();
                return 0;
            }
            m_unkC[i] = pChannel;
            switch (*(int *)pChannel) {
            case 1:
                m_unkA |= 0x01;
                break;
            case 2:
                m_unkA |= 0x02;
                break;
            case 3:
                m_unkA |= 0x04;
                break;
            case 4:
                m_unkA |= 0x08;
                break;
            case 5:
                m_unkA |= 0x10;
                break;
            case 6:
                m_unkA |= 0x20;
                break;
            default:
                break;
            }
        }
    } else {
        m_unk8 = 0;
    }
    if (((PCDFile *)pFile)->Read(&tag, 4) != 4) {
        return 0;
    }
    return !(tag != 5);
}

// FUNCTION: 0x0018CCE0 Cleanup__5PAnimFv
void PAnim::Cleanup()
{
    int i;
    if (m_unkB != 0 && m_unkC[0] != 0) {
        m_unkB = 0;
        for (i = 0; i < 5; i++) {
            if (m_unkC[i] != 0) {
                __dt__8PChannelFv(m_unkC[i], 1);
                m_unkC[i] = 0;
            }
        }
    }
    m_unk8 = 0;
}

// FUNCTION: 0x0018CD70 __dt__5PAnimFv
PAnim::~PAnim()
{
    Cleanup();
}

// FUNCTION: 0x0018CDD0 __ct__5PAnimFv
PAnim::PAnim()
{
    m_unk8 = 0;
    m_unk4 = 0;
    m_unkA = 0;
    m_unkB = 0;
    m_unkC[0] = 0;
    m_unkC[1] = 0;
    m_unkC[2] = 0;
    m_unkC[3] = 0;
    m_unkC[4] = 0;
}
