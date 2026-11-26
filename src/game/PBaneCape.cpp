#include "types.h"
#include "PBaneCape.h"
#include "PAnim.h"
#include "PMNode.h"

// TODO(header): foreign declarations
extern "C" void *__dt__19PDynamicSplinePatchFv(PDynamicSplinePatch *pThis, short nFlag);
float FastMath_Sin180(float fAngle);
extern float gfBanePosBlendValues[18];
extern float gfBaneRotBlendValues[18];
extern int giBaneLagControlMatrixIndices[18];
extern "C" void sceVu0CopyVector(float *pDst, float *pSrc);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int n);

// DRAFT: 0x00214560 AnimateControlNode__9PBaneCapeFP5PAnimf
// note: 45 words differ: frame 0x60 vs 0x70 (original has a 16-byte slot at sp+0x50, aTmp at sp+0x60), aNode addressed via s0 in ours vs sp for [1]/[2]; tried pNode alias (45, kept), no alias (59), dummy local (dropped), aTmp-first order (worse).
void PBaneCape::AnimateControlNode(PAnim *pAnim, float fTime)
{
    if (m_unk1F6C != 0) {
        float aOut[4];
        float aNode[4];
        float aTmp[4];
        float *pNode = aNode;
        *(u_long128 *)pNode = 0;
        float fPhase = m_unk2020 + m_unk2024;
        m_unk2020 = fPhase;
        if (fPhase >= 360.0f) {
            m_unk2020 = fPhase - 360.0f;
        }
        if (pAnim != 0) {
            pAnim->Animate(fTime, 0.0f, (float (*)[4])aOut, aTmp, true);
            *(u_long128 *)((PMNode *)m_unk1F6C)->m_unk80 = *(u_long128 *)aOut;
            ((PMNode *)m_unk1F6C)->m_unk3E |= 8;
        } else {
            pNode[1] = 0.0f;
        }
        pNode[0] = 50.0f + 5.0f * FastMath_Sin180(m_unk2020 - 180.0f);
        pNode[2] = 0.0f;
        *(u_long128 *)((PMNode *)m_unk1F6C)->m_unk90 = *(u_long128 *)aNode;
        ((PMNode *)m_unk1F6C)->m_unk3E |= 8;
    }
}

// FUNCTION: 0x00214660 Enable__9PBaneCapeFbP6PMNode
void PBaneCape::Enable(bool bEnable, PMNode *pNode)
{
    if (pNode == 0) {
        m_unk2011 = 0;
        return;
    }
    m_unk2011 = bEnable;
    if (m_unk2011 != 0) {
        SetControlNode(pNode);
        m_unk2012 = 1;
    }
}

// FUNCTION: 0x002146B0 Init__9PBaneCapeFPf
void PBaneCape::Init(float *pVec)
{
    float aVecA[4] = {-4.0f, 0.0f, -0.2f, 1.0f};
    float aVecB[4] = {4.0f, 0.0f, 7.8f, 1.0f};
    PDynamicSplinePatch::Init(10, 8, 4, aVecA, aVecB);
    m_unk1FE8 = ((long long)((m_unk2010 != 0) ? 0 : 0x7E) << 4) | 0x5000D;
    m_unk1F74 = 4.0f;
    m_unk1F80 = 0.1f;
    m_unk1F84 = 1.25f;
    m_unk1F88 = 0.1f;
    m_unk1F8C = 0.75f;
    sceVu0CopyVector(m_unk1FB0, pVec);
    sceVu0CopyVector(m_unk1FB0 + 4, pVec);
    m_unk2011 = 0;
    m_unk2020 = 0.0f;
    m_unk2024 = 3.5f;
    memcpy(m_unk1E90, gfBanePosBlendValues, 0x48);
    memcpy(m_unk1ED8, gfBaneRotBlendValues, 0x48);
    memcpy(m_unk1F20, giBaneLagControlMatrixIndices, 0x48);
}

// FUNCTION: 0x002147D0 Init__9PBaneCapeFv
void PBaneCape::Init()
{
    float aVec[4] = {128.0f, 128.0f, 128.0f, 128.0f};
    Init(aVec);
}

// FUNCTION: 0x00214800 __dt__9PBaneCapeFv
PBaneCape::~PBaneCape()
{
    __dt__19PDynamicSplinePatchFv(this, 0);
}

// FUNCTION: 0x00214860 __ct__9PBaneCapeFv
PBaneCape::PBaneCape() : PDynamicSplinePatch()
{
}
