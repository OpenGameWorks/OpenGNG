#include "types.h"
#include "PAnimFrame.h"

// FUNCTION: 0x0018CE80 RestoreAnim__10PAnimFrameFP10PAnimFrame
void PAnimFrame::RestoreAnim(PAnimFrame *pSrc) {
    m_unk20 = pSrc->m_unk20;
    m_unk22 = pSrc->m_unk22;
    m_unk24 = pSrc->m_unk24;
    m_unk26 = pSrc->m_unk26;
    m_unk28 = pSrc->m_unk28;
    m_unk2A = pSrc->m_unk2A;
    m_unk2C = pSrc->m_unk2C;
    m_unk30 = pSrc->m_unk30;
}

// DRAFT: 0x0018CED0 Load__10PAnimFrameFP8PPakFile
// note: 7 words differ: original shares one epilogue via b; ours repeats ld ra/jr ra per return. Tried ||, single trailing return (14), result variable (20).
int PAnimFrame::Load(PPakFile *pFile) {
    if (!PAnim::Load(pFile)) {
        return 0;
    }
    m_unk24 = m_unk8;
    m_unk28 = m_unk8;
    if (m_unk4 != 1000 && m_unk4 != 1) {
        return 1;
    }
    m_unk2A = 1;
    m_unk20 = 0;
    return 1;
}

// DRAFT: 0x0018CF50 Load__10PAnimFrameFP8PPakFileP26tagMeshNodeAnimationHeader
// note: 7 words differ, same epilogue-sharing difference as Load(PPakFile*) (calls PAnim::Load(pFile, pHeader)).
int PAnimFrame::Load(PPakFile *pFile, tagMeshNodeAnimationHeader *pHeader) {
    if (!PAnim::Load(pFile, pHeader)) {
        return 0;
    }
    m_unk24 = m_unk8;
    m_unk28 = m_unk8;
    if (m_unk4 != 1000 && m_unk4 != 1) {
        return 1;
    }
    m_unk2A = 1;
    m_unk20 = 0;
    return 1;
}

// FUNCTION: 0x0018D070 EnableAnim__10PAnimFrameFb
void PAnimFrame::EnableAnim(bool bEnable) {
    if (!bEnable) {
        if (m_unk4 != 1000 && m_unk4 != 1) {
            m_unk2A = bEnable;
            return;
        }
        bEnable = 1;
    }
    m_unk2A = bEnable;
}

// FUNCTION: 0x0018D470 __ct__10PAnimFrameFs
PAnimFrame::PAnimFrame(short nFrame) {
    m_unk2A = 0;
    m_unk20 = 1;
    m_unk22 = 0;
    m_unk26 = 0;
    m_unk24 = nFrame;
    m_unk28 = nFrame;
    m_unk2C = 0.0f;
    m_unk30 = 0.5f;
}
