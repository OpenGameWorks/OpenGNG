#include "types.h"
#include "PGrimReaperCape.h"
#include "PAnim.h"
#include "PMNode.h"

// TODO(header): foreign declarations
extern unsigned char giGrimLagControlMatrixIndices[936];
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void *__dt__19PDynamicSplinePatchFv(PDynamicSplinePatch *pThis, short nFlag);
float FastMath_Sin180(float fAngle);
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern float gfGrimPosBlendValues[18];
extern float gfGrimRotBlendValues[18];

// DRAFT: 0x001F41B0 AnimateControlNode__15PGrimReaperCapeFP5PAnimf
// note: frame 0x60 vs 0x70 and this in s1 vs s0; aNode zeroed by lq copy, not sq $zero. Tried partial {0.0f} init, no change.
void PGrimReaperCape::AnimateControlNode(PAnim *pAnim, float fTime)
{
    if (m_unk1F6C != 0) {
        if (pAnim != 0) {
            float aOut[4];
            float aNode[4] = {0.0f, 0.0f, 0.0f, 0.0f};
            float aTmp[4];
            float *pNode = aNode;
            float fPhase = m_unk2020 + m_unk2024;
            if (fPhase >= 360.0f) {
                m_unk2020 = fPhase;
                m_unk2020 = fPhase - 360.0f;
            }
            pAnim->Animate(fTime, 0.0f, (float (*)[4])aOut, aTmp, true);
            pNode[0] = 30.0f + 15.0f * FastMath_Sin180(m_unk2020 - 180.0f);
            aNode[2] = 0.0f;
            *(u_long128 *)((PMNode *)m_unk1F6C)->m_unk90 = *(u_long128 *)aNode;
            ((PMNode *)m_unk1F6C)->m_unk3E |= 8;
            *(u_long128 *)((PMNode *)m_unk1F6C)->m_unk80 = *(u_long128 *)aOut;
            ((PMNode *)m_unk1F6C)->m_unk3E |= 8;
        }
    }
}

// FUNCTION: 0x001F42A0 Enable__15PGrimReaperCapeFbP6PMNode
void PGrimReaperCape::Enable(bool bEnable, PMNode *pNode)
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

// FUNCTION: 0x001F42F0 SetAnimation__15PGrimReaperCapeF14eGrimCapeTable
void PGrimReaperCape::SetAnimation(eGrimCapeTable eTable)
{
    memcpy(m_unk1F20, giGrimLagControlMatrixIndices + eTable * 0x48, 0x48);
}

// FUNCTION: 0x001F4320 SetAnimation__15PGrimReaperCapeFUi
void PGrimReaperCape::SetAnimation(unsigned int nAnimId)
{
    int nTable;
    switch (nAnimId) {
    case 0x820002E6:
        nTable = 1;
        break;
    case 0x820002E7:
        nTable = 2;
        break;
    case 0x820002FE:
        nTable = 12;
        break;
    case 0x82000339:
        nTable = 8;
        break;
    case 0x8200033A:
        nTable = 7;
        break;
    case 0x820002E3:
        nTable = 6;
        break;
    case 0x820002FF:
        nTable = 11;
        break;
    case 0x820002DF:
        nTable = 9;
        break;
    case 0x820002E0:
        nTable = 10;
        break;
    case 0x820002E2:
        nTable = 3;
        break;
    case 0x820002E5:
        nTable = 4;
        break;
    default:
        nTable = 0;
        break;
    }
    SetAnimation((eGrimCapeTable)nTable);
}

// FUNCTION: 0x001F4400 Init__15PGrimReaperCapeFPf
void PGrimReaperCape::Init(float *pVec)
{
    float aVecA[4] = {-3.5f, 0.0f, 0.0f, 1.0f};
    float aVecB[4] = {3.5f, 0.0f, 6.75f, 1.0f};
    PDynamicSplinePatch::Init(10, 8, 4, aVecA, aVecB);
    m_unk1FE8 = ((long long)((m_unk2010 != 0) ? 0 : 0x7E) << 4) | 0x5000D;
    m_unk1F74 = 5.0f;
    m_unk1F80 = 0.1f;
    m_unk1F84 = 1.75f;
    m_unk1F88 = 0.1f;
    m_unk1F8C = 0.5f;
    sceVu0CopyVector(m_unk1FB0, pVec);
    sceVu0CopyVector(m_unk1FB0 + 4, pVec);
    m_unk2011 = 0;
    m_unk2020 = 0.0f;
    m_unk2024 = 3.5f;
    memcpy(m_unk1E90, gfGrimPosBlendValues, 0x48);
    memcpy(m_unk1ED8, gfGrimRotBlendValues, 0x48);
}

// FUNCTION: 0x001F4510 Init__15PGrimReaperCapeFv
void PGrimReaperCape::Init()
{
    float aVecA[4] = {-3.5f, 0.0f, 0.0f, 1.0f};
    float aVecB[4] = {3.5f, 0.0f, 6.75f, 1.0f};
    PDynamicSplinePatch::Init(10, 8, 4, aVecA, aVecB);
    m_unk1FE8 = ((long long)((m_unk2010 != 0) ? 0 : 0x7E) << 4) | 0x5000D;
    m_unk1F74 = 5.0f;
    m_unk1F80 = 0.1f;
    m_unk1F84 = 1.75f;
    m_unk1F88 = 0.1f;
    m_unk1F8C = 0.5f;
    m_unk1FB0[0] = 128.0f;
    m_unk1FB0[1] = 50.0f;
    m_unk1FB0[2] = 20.0f;
    m_unk1FB0[3] = 128.0f;
    m_unk1FB0[4] = 128.0f;
    m_unk1FB0[5] = 50.0f;
    m_unk1FB0[6] = 20.0f;
    m_unk1FB0[7] = 128.0f;
    m_unk2011 = 0;
    m_unk2020 = 0.0f;
    m_unk2024 = 3.5f;
    memcpy(m_unk1E90, gfGrimPosBlendValues, 0x48);
    memcpy(m_unk1ED8, gfGrimRotBlendValues, 0x48);
}

// FUNCTION: 0x001F4620 __dt__15PGrimReaperCapeFv
PGrimReaperCape::~PGrimReaperCape()
{
    __dt__19PDynamicSplinePatchFv(this, 0);
}

// FUNCTION: 0x001F4680 __ct__15PGrimReaperCapeFv
PGrimReaperCape::PGrimReaperCape() : PDynamicSplinePatch()
{
}
