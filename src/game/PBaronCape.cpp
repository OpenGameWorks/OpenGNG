#include "types.h"
#include "PBaronCape.h"
#include "PAnim.h"
#include "PMNode.h"

// TODO(header): foreign declarations
extern "C" void *__dt__19PDynamicSplinePatchFv(PDynamicSplinePatch *pThis, short nFlag);
float FastMath_Sin180(float fAngle);

// DRAFT: 0x00214230 AnimateControlNode__10PBaronCapeFP5PAnimf
// note: 45 words differ: frame 0x60 vs 0x70 (original has a 16-byte slot at sp+0x50, aTmp at sp+0x60), aNode addressed via s0 in ours vs sp for [1]/[2]; tried pNode alias (45, kept), no alias (59), dummy local (dropped), aTmp-first order (worse).
void PBaronCape::AnimateControlNode(PAnim *pAnim, float fTime)
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

// FUNCTION: 0x00214330 Enable__10PBaronCapeFbP6PMNode
void PBaronCape::Enable(bool bEnable, PMNode *pNode)
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

// FUNCTION: 0x002144A0 Init__10PBaronCapeFv
void PBaronCape::Init()
{
    float aVec[4] = {128.0f, 128.0f, 128.0f, 128.0f};
    Init(aVec);
}

// FUNCTION: 0x002144D0 __dt__10PBaronCapeFv
PBaronCape::~PBaronCape()
{
    __dt__19PDynamicSplinePatchFv(this, 0);
}

// FUNCTION: 0x00214530 __ct__10PBaronCapeFv
PBaronCape::PBaronCape() : PDynamicSplinePatch()
{
}
