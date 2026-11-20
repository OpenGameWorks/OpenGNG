// FLAGS: -str readonly
#include "types.h"
#include "PAnim.h"
#include "PCDFile.h"

// TODO(header): foreign declarations
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" void __dt__8PChannelFv(PChannel *pThis, short nFlag);

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
