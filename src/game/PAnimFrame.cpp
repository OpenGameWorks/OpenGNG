#include "types.h"
#include "PAnimFrame.h"

// TODO(header): foreign declarations
class AnimData {
public:
    short unk0;
    short unk2;
    short unk4;
    short unk6;
    short unk8;
    char _pad0A[0x2];
    float unkC;
};
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);

// FUNCTION: 0x0018CE10 SetFrameTime__10PAnimFrameFf
void PAnimFrame::SetFrameTime(float value) {
    m_unk2C = value;
}

// FUNCTION: 0x0018CE30 SetEndFrame__10PAnimFrameFs
void PAnimFrame::SetEndFrame(short value) {
    m_unk28 = value;
    m_unk24 = value;
}

// FUNCTION: 0x0018CE40 GetFrameTime__10PAnimFrameFv
float PAnimFrame::GetFrameTime() {
    return m_unk2C;
}

// FUNCTION: 0x0018CE50 SetLoopEndFrame__10PAnimFrameFs
void PAnimFrame::SetLoopEndFrame(short value) {
    m_unk28 = value;
}

// FUNCTION: 0x0018CE60 GetFrameRate__10PAnimFrameFv
float PAnimFrame::GetFrameRate() {
    return m_unk30;
}

// FUNCTION: 0x0018CE70 IsPAnimFrame__10PAnimFrameFv
int PAnimFrame::IsPAnimFrame() {
    return 1;
}

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

// FUNCTION: 0x0018CFD0 SetAllAnimFlags__10PAnimFrameFP8AnimData
void PAnimFrame::SetAllAnimFlags(AnimData *pData) {
    static AnimData Default = {0, -1, 0, -1, 1, {3, 0}, 0.5f};
    if (!pData) {
        pData = &Default;
    }
    m_unk20 = pData->unk8;
    m_unk30 = pData->unkC;
    m_unk2A = 1;
    short v = pData->unk0;
    if (v < 0) {
        v = m_unk8;
    }
    m_unk22 = v;
    m_unk2C = (float)v;
    v = pData->unk2;
    if (v < 0) {
        v = m_unk8;
    }
    m_unk24 = v;
    v = pData->unk4;
    if (v < 0) {
        v = m_unk8;
    }
    m_unk26 = v;
    v = pData->unk6;
    if (v < 0) {
        v = m_unk8;
    }
    m_unk28 = v;
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

// FUNCTION: 0x0018D0B0 Animate__10PAnimFrameFffPA4_fPfb
float PAnimFrame::Animate(float fTime, float fUnused, float (*pMatrix)[4], float *pOut, bool bFlag) {
    float fResult = m_unk2C;
    if (m_unk2A != 0) {
        fResult = AnimateFrame(fUnused);
    }
    PAnim::Animate(fResult, fUnused, pMatrix, pOut, bFlag);
    return fResult;
}

// DRAFT: 0x0018D140 AnimateFrame__10PAnimFrameFf
// note: DIFF 72 words. First-diff at 0x24 (beqz offset); bc1t offsets at 0x74/0x94/0x168/0x178; shared store `b`+`swc1 $f20,0x2C` at 0x18D300 not reproduced; loop-exit mov.s/lh/cvt.s.w/add.s ordering differs. Tried: plain structure (40 words), goto-store tail (72); the 40-word form was overwritten.
float PAnimFrame::AnimateFrame(float fTime) {
    float fResult = m_unk2C;
    if (m_unk2A != 0) {
        m_unk2A = m_unk2A & ~4;
        if (m_unk24 == -1) {
            CdsAssert__FPciPc("PAnimFrame.cpp", 0x38, "miEndFrame != -1");
        }
        if (!(m_unk30 < 0.0f)) {
            if (!(fResult < (float)m_unk28)) {
                short n = m_unk20;
                if (n != 0) {
                    n = n - 1;
                    m_unk20 = n;
                    if (n == 0) {
                        short e = m_unk24;
                        if (!(fResult < (float)e)) {
                            m_unk2C = (float)e;
                            m_unk2A = 0;
                            return m_unk2C;
                        }
                        m_unk28 = e;
                        m_unk20 = 1;
                        goto store;
                    }
                }
                m_unk2A |= 4;
                {
                    short hi = m_unk28;
                    fResult = fResult - (float)hi;
                    float r = (float)(hi - m_unk26);
                    if (r < 0.0f) {
                        CdsAssert__FPciPc("PAnimFrame.cpp", 0x57, "loop >= 0");
                    }
                    if (!(r <= 0.0f)) {
                        if (!(fResult < r)) {
                            do {
                                fResult -= r;
                            } while (!(fResult < r));
                        }
                    } else {
                        fResult = 0.0f;
                    }
                    fResult = fResult + (float)m_unk26;
                }
store:
                m_unk2C = fResult;
            }
        } else {
            if (fResult <= (float)m_unk26) {
                short n = m_unk20;
                if (n != 0) {
                    n = n - 1;
                    m_unk20 = n;
                    if (n == 0) {
                        if (fResult <= 0.0f) {
                            m_unk2C = 0.0f;
                            m_unk2A = 0;
                            return 0.0f;
                        }
                        m_unk26 = 0;
                        m_unk20 = 1;
                        goto tail;
                    }
                }
                m_unk2A |= 4;
                fResult += (float)(m_unk28 - m_unk26);
                m_unk2C = fResult;
            }
        }
tail:
        m_unk2C += fTime * m_unk30;
    }
    return fResult;
}

// FUNCTION: 0x0018D3E0 __ct__10PAnimFrameFP5PAnim
PAnimFrame::PAnimFrame(PAnim *pSrc) {
    void *vt = *(void **)this;
    *(u_long128 *)this = *(u_long128 *)pSrc;
    *(u_long128 *)((char *)this + 0x10) = *(u_long128 *)((char *)pSrc + 0x10);
    *(void **)this = vt;
    m_unkB = 0;
    m_unk2A = 0;
    m_unk20 = 1;
    m_unk22 = 0;
    m_unk26 = 0;
    short nFrame = pSrc->m_unk8;
    m_unk24 = nFrame;
    m_unk28 = nFrame;
    m_unk2C = 0.0f;
    m_unk30 = 0.5f;
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
