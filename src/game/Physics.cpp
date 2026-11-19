// FLAGS: -str readonly
#include "Physics.h"

// TODO(header): foreign declarations
class PMNode;
extern "C" int Find__6PArrayFPv(PArray *pArr, void *pItem);
extern "C" void BuildAnimList__6PMNodeFP6PArrayUi(PMNode *pNode, PArray *pArr, unsigned int uID);
extern "C" float FastMath_Sin180__Ff(float fAngle);
extern "C" float FastMath_Cos180__Ff(float fAngle);
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern float gUnitMatrix[16];

// FUNCTION: 0x00170E80 SulfurCheck__7PhysicsFv
int Physics::SulfurCheck()
{
    if (m_unkE8 & 0x100000) {
        if (m_unkC4 > m_unkB4 && m_unkC4 > m_unkFC + m_unk94) {
            return 1;
        }
    }
    return 0;
}

// FUNCTION: 0x00170EE0 AddBGAnimNode__7PhysicsFP9PMeshNode
void Physics::AddBGAnimNode(PMeshNode *pNode)
{
    if (Find__6PArrayFPv(&mBGAnimList__7Physics, this) < 0) {
        if (mBGAnimList__7Physics.m_unk0 >= 0x40) {
            CdsAssert("Physics.cpp", 0x387, "mBGAnimList.GetCount() < MAX_BGANIM");
        }
        mBGAnimList__7Physics.Add(this);
    }
}

// FUNCTION: 0x00170F50 BuildBGAnimList__7PhysicsFP9PMeshNode
void Physics::BuildBGAnimList(PMeshNode *pNode)
{
    BuildAnimList__6PMNodeFP6PArrayUi((PMNode *)this, &mBGAnimList__7Physics, 0x1FE);
    if (mBGAnimList__7Physics.m_unk0 > 0x40) {
        CdsAssert("Physics.cpp", 0x37E, "mBGAnimList.GetCount() <= MAX_BGANIM");
    }
}

// FUNCTION: 0x00170FA0 SetVelocity__7PhysicsFff
void Physics::SetVelocity(float fAngle, float fSpeed)
{
    m_unk0 = fSpeed * -FastMath_Sin180__Ff(fAngle);
    m_unk8 = fSpeed * -FastMath_Cos180__Ff(fAngle);
}

// FUNCTION: 0x00172470 ResetPhysics__7PhysicsFP9PMeshNode
void Physics::ResetPhysics(PMeshNode *pNode)
{
    m_unk11C = *(float *)((char *)pNode + 0x94);
    *(u_long128 *)&m_unk0 = *(u_long128 *)gUnitMatrix;
    *(u_long128 *)&m_unk10 = *(u_long128 *)gUnitMatrix;
    *(u_long128 *)&m_unkA0 = *(u_long128 *)((char *)pNode + 0x80);
    m_unkF8 = 0;
    m_unk108 = 0;
    m_unk114 = 0;
    m_unkCC = 0;
    m_unkE4 = 0;
}
