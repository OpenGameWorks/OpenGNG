// FLAGS: -str readonly
#include "Physics.h"
#include "BGCollision.h"

// TODO(header): foreign declarations
class PMNode;
extern "C" int Find__6PArrayFPv(PArray *pArr, void *pItem);
extern "C" void BuildAnimList__6PMNodeFP6PArrayUi(PMNode *pNode, PArray *pArr, unsigned int uID);
extern "C" float FastMath_Sin180__Ff(float fAngle);
extern "C" float FastMath_Cos180__Ff(float fAngle);
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern float gUnitMatrix[16];
extern "C" float sceVu0InnerProduct(float *, float *);
extern "C" void sceVu0Normalize(float *, float *);
extern "C" void sceVu0ScaleVector(float *, float *, float);
extern "C" void sceVu0SubVector(float *, float *, float *);
extern "C" void sceVu0ApplyMatrix(float *, float (*)[4], float *);
extern "C" void sceVu0AddVector(float *, float *, float *);
extern "C" float Round180__Ff(float fAngle);
extern "C" float FastMath_Fabs__Ff(float fAngle);
extern "C" void sceVu0UnitMatrix(float (*)[4]);
extern "C" float atan2f(float y, float x);
extern char mBGCollision__15EntityBaseClass[0x20];
extern char StaticBox[0x20];
extern float SandSpeed[8];

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

// Local view of a PMNode with the virtual slots and fields CheckBGAnim and ApplyGroundMove use.
// Virtual slot 5 (vtable offset 0x1C) is SetAllAnimFlags.
class PMNodeAnimView {
public:
    virtual ~PMNodeAnimView();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void SetAllAnimFlags(void *pAnimData);

    char _pad004[0x8];
    unsigned int m_unkC;            // 0x0C, zero skips the node
    float m_unk10[4];               // 0x10 vector (CalculateVelocity)
    char _pad020[0x8];
    float *m_unk28;                // 0x28 vector pointer, 0 selects m_unk110
    char _pad02C[0x3F - 0x2C];
    char m_unk3F;                   // 0x3F, low 3 bits gate the node
    float m_unk40[4][4];            // 0x40 matrix
    char _pad080[0x100 - 0x80];
    unsigned short m_unk100;        // 0x100
    char _pad102[0x110 - 0x102];
    float m_unk110[4];              // 0x110 default vector
};

// Local view of the PMeshNode fields ApplyGroundMove touches (0x4 type, 0x140/0x148 gates).
struct PMeshNodeGroundView {
    char _pad0[0x4];
    int m_unk4;
    char _pad8[0x138];
    float m_unk140;
    char _pad144[0x4];
    float m_unk148;
};

// DRAFT: 0x00171000 ApplyGroundMove__7PhysicsFRA4_fP9PMeshNode
// note: 43 words differ: s0 daddiu vs addiu; compare operand order in gate and fDiff tests; 0x140 addiu scheduling; fDiff constant in f1 vs f2 and zero in f3 vs f1, so the nop/tail shift by one word. Tried: 0x148 pointer form, 0.0f== flips, mul operand swap, != flip, local pointer for 0x140.
int Physics::ApplyGroundMove(float (&vOut)[4], PMeshNode *pNode)
{
    float vA[4];
    float vB[4];
    int nResult = 0;
    float (*pMat)[4];

    pMat = (float (*)[4])(m_unkCC + 0x40);
    sceVu0ApplyMatrix(vA, (float (*)[4])m_unk40, (float *)&m_unkD0);
    sceVu0ApplyMatrix(vB, pMat, (float *)&m_unkD0);
    sceVu0SubVector(m_unk20, vB, vA);
    ((unsigned int *)m_unk20)[3] = 0;
    if (sceVu0InnerProduct(m_unk20, m_unk20) > 1e-5f) {
        nResult = 1;
        m_unk108 |= 8;
    }
    {
        PMNodeAnimView *pCC = (PMNodeAnimView *)m_unkCC;
        if ((((signed char)(pCC->m_unk3F & 7) != 0) || pCC->m_unk100 != 0)
            && ((PMeshNodeGroundView *)pNode)->m_unk4 == 2
            && ((float *)&m_unk10)[0] == 0.0f
            && ((float *)&m_unk10)[1] == 0.0f
            && ((float *)&m_unk10)[2] == 0.0f
            && ((PMeshNodeGroundView *)pNode)->m_unk140 == 0.0f
            && ((PMeshNodeGroundView *)pNode)->m_unk148 == 0.0f) {
            if (IsAnimatedWallHit() != 0) {
                *(u_long128 *)((char *)this + 0x30) = m_unkD0;
            } else {
                sceVu0ApplyMatrix(vOut, pMat, (float *)((char *)this + 0x30));
                *(u_long128 *)((char *)this + 0xB0) = *(u_long128 *)vOut;
            }
        } else {
            m_unk3C = 0.0f;
            if (m_unkE4 == 0) {
                vOut[0] += m_unk20[0];
                vOut[2] += m_unk20[2];
                sceVu0AddVector((float *)((char *)this + 0xB0), (float *)((char *)this + 0xB0), m_unk20);
            }
        }
    }
    {
        float fCur = 57.295776f * atan2f(pMat[0][0], pMat[0][2]);
        float fDiff = fCur - 57.295776f * atan2f(m_unk40[0], m_unk40[2]);
        if (0.0f != fDiff) {
            m_unk108 |= 0x10;
        }
        if (pMat[1][1] < 0.0f) {
            fDiff = -fDiff;
        }
        m_unkF4 = fDiff;
        m_unk11C = Round180__Ff(fDiff + m_unk11C);
    }
    return nResult;
}

// Local views of the animated-wall objects IsAnimatedWallHit reads (0x24 surface link, 0x8 type).
struct AnimWallSurface {
    char _pad0[0x8];
    short m_unk8;
};

struct AnimWallObject {
    char _pad0[0x24];
    AnimWallSurface *m_unk24;
};

// DRAFT: 0x00171280 IsAnimatedWallHit__7PhysicsFv
// note: 36 words differ; original shares one exit at 0xB0, separate returns and c.eq.s operand order tried, not matched.
int Physics::IsAnimatedWallHit()
{
    AnimWallSurface *pA;
    AnimWallSurface *pB;

    if (m_unk3C == 0.0f) {
        return 1;
    }
    if (m_unkE4 == 0) {
        return 0;
    }
    pA = 0;
    if (m_unkCC == m_unkE0) {
        return 0;
    }
    pB = 0;
    if (m_unkCC != 0) {
        pA = ((AnimWallObject *)m_unkCC)->m_unk24;
        if (pA != 0 && pA->m_unk8 < 2) {
            pA = 0;
        }
    }
    if (m_unkE0 != 0) {
        pB = ((AnimWallObject *)m_unkE0)->m_unk24;
        if (pB != 0 && pB->m_unk8 < 2) {
            pB = 0;
        }
    }
    if (pA != 0 || pB != 0) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x00171340 CheckBGAnim__7PhysicsFRA4_ff
void Physics::CheckBGAnim(float (&vPos)[4], float fOffset)
{
    float vTmp[4];
    float fRadius;
    float *pVec;
    PMNodeAnimView *pNode;
    int nIdx;

    mBGAnimList__7Physics.m_unk4 = 0;
    if (mBGAnimList__7Physics.m_unk0 != 0) {
        pNode = (PMNodeAnimView *)mBGAnimList__7Physics.m_unk8[0];
    } else {
        pNode = 0;
    }
    while (pNode != 0) {
        if (pNode->m_unkC != 0 && (signed char)(pNode->m_unk3F & 7) == 0) {
            pVec = pNode->m_unk28;
            if (pVec == 0) {
                pVec = pNode->m_unk110;
            }
            sceVu0ApplyMatrix(vTmp, pNode->m_unk40, pVec);
            sceVu0SubVector(vTmp, vPos, vTmp);
            vTmp[1] += fOffset;
            fRadius = pVec[4];
            if (fRadius > pVec[6]) {
                fRadius = pVec[6];
            }
            if (sceVu0InnerProduct(vTmp, vTmp) < fRadius * fRadius) {
                pNode->SetAllAnimFlags(0);
            }
        }
        nIdx = mBGAnimList__7Physics.m_unk4 + 1;
        mBGAnimList__7Physics.m_unk4 = nIdx;
        pNode = (nIdx < mBGAnimList__7Physics.m_unk0)
                    ? (PMNodeAnimView *)mBGAnimList__7Physics.m_unk8[mBGAnimList__7Physics.m_unk4]
                    : 0;
    }
}

// Local view of the PMeshNode fields AdjustFaceAngle touches (0x3E flags, 0x94 heading).
struct PMeshNodeAngleView {
    char _pad0[0x3E];
    unsigned char m_unk3E;
    char _pad1[0x94 - 0x3F];
    float m_unk94;
};

// DRAFT: 0x001720C0 AdjustFaceAngle__7PhysicsFP9PMeshNodef
// note: 63 words differ; 0x118 compare loads into f0 not f1, fDiff compare order and 0x11C load order differ; fDiff-before-fCur kept.
void Physics::AdjustFaceAngle(PMeshNode *pNode, float fRate)
{
    PMeshNodeAngleView *pView = (PMeshNodeAngleView *)pNode;
    m_unk108 &= ~0x800;
    if (m_unk118 != 0.0f) {
        float fDiff;
        float fCur = pView->m_unk94;
        fDiff = Round180__Ff(m_unk11C - fCur);
        if (fDiff != 0.0f) {
            float fNew;
            if (m_unk118 <= 1.0f) {
                float fStep = m_unk118 * fRate;
                if (FastMath_Fabs__Ff(fDiff) <= 2.0f || !(fStep < 1.0f)) {
                    fNew = m_unk11C;
                } else {
                    fNew = fCur + fDiff * fStep;
                    m_unk108 |= 0x800;
                }
            } else if (FastMath_Fabs__Ff(fDiff) <= fRate) {
                fNew = m_unk11C;
            } else {
                float fStep = fRate;
                if (fDiff < 0.0f) {
                    fStep = -fStep;
                }
                fNew = fCur + fStep;
                m_unk108 |= 0x800;
            }
            pView->m_unk94 = Round180__Ff(fNew);
            pView->m_unk3E |= 8;
        }
    }
}

// FUNCTION: 0x00172240 CalculateVelocity__7PhysicsFfPA4_f
void Physics::CalculateVelocity(float fSpeed, float (*pMatrix)[4])
{
    float vTmp[4];
    float fRem;
    float fScale;
    unsigned int nFlags;

    *(u_long128 *)pMatrix = *(u_long128 *)this;
    if (m_unk106 & 0x20) {
        m_unk100 = 1.0f;
        nFlags = m_unkE8;
        if (m_unk108 & 1) {
            if (nFlags & ((PMNodeAnimView *)m_unkC0)->m_unkC & 0x80000) {
                *(u_long128 *)vTmp = *(u_long128 *)((PMNodeAnimView *)m_unkC0)->m_unk10;
                if (vTmp[1] != 1.0f) {
                    vTmp[1] = 0.0f;
                    sceVu0Normalize(vTmp, vTmp);
                    sceVu0ScaleVector(vTmp, vTmp, SandSpeed[(((PMNodeAnimView *)m_unkC0)->m_unkC >> 11) & 7]);
                    pMatrix[0][0] += vTmp[0];
                    pMatrix[0][2] += vTmp[2];
                }
            }
        }
        fRem = m_unkC4;
        fRem = fRem - fSpeed;
        if (!(fRem <= 0.0f)) {
            if (!(fRem <= 2.5f)) {
                fRem = 2.5f;
            }
            if (nFlags & 1) {
                fScale = 1.0f - (0.1f * fRem);
                m_unk0 = m_unk0 * fScale;
                m_unk8 = m_unk8 * fScale;
                m_unk100 = fScale;
                *(u_long128 *)pMatrix = *(u_long128 *)this;
            }
        }
    }
    m_unk10 = *(u_long128 *)pMatrix;
}

// FUNCTION: 0x001723E0 GetReflectionVec__FPfPfPf
void GetReflectionVec(float *pIn, float *pNormal, float *pOut)
{
    float aNormal[4];
    float aScaled[4];

    sceVu0Normalize(aNormal, pIn);
    sceVu0ScaleVector(aScaled, pNormal, 2.0f * sceVu0InnerProduct(aNormal, pNormal));
    sceVu0SubVector(pOut, pIn, aScaled);
    sceVu0Normalize(pOut, pOut);
}

// FUNCTION: 0x00172470 ResetPhysics__7PhysicsFP9PMeshNode
void Physics::ResetPhysics(PMeshNode *pNode)
{
    m_unk11C = *(float *)((char *)pNode + 0x94);
    *(u_long128 *)&m_unk0 = *(u_long128 *)&gUnitMatrix[12];
    *(u_long128 *)&m_unk10 = *(u_long128 *)&gUnitMatrix[12];
    *(u_long128 *)&m_unkA0 = *(u_long128 *)((char *)pNode + 0x80);
    m_unkF8 = 0;
    m_unk108 = 0;
    m_unk114 = 0;
    m_unkCC = 0;
    m_unkE4 = 0;
}

// FUNCTION: 0x001724B0 SetPhysicsType__7PhysicsFUiPA4_f
void Physics::SetPhysicsType(unsigned int nType, float (*pPos)[4])
{
    float aMat[4][4];

    m_unk106 = (short)nType;
    if ((nType & 0x40) && m_unkCC == 0) {
        if (pPos == 0) {
            CdsAssert("Physics.cpp", 0x4D, "pPos");
        }
        sceVu0UnitMatrix(aMat);
        *(u_long128 *)aMat[3] = *(u_long128 *)pPos;
        ((BGCollision *)mBGCollision__15EntityBaseClass)->BGDetection((float (*)[2][4])StaticBox, (PMat4 *)aMat, 0.0f, (SurfaceInfo &)m_unkA0, 1, 0);
        if (m_unkCC == 0) {
            m_unk106 = 0x800;
            if (m_unkC0 != 0) {
                *(u_long128 *)pPos = *(u_long128 *)((char *)this + 0xB0);
            }
        } else {
            float *pM = (float *)(m_unkCC + 0x40);
            sceVu0CopyMatrix((float (*)[4])m_unk40, (float (*)[4])pM);
            m_unkF4 = 57.295776f * atan2f(pM[0], pM[2]);
        }
    }
}

// FUNCTION: 0x001725B0 __ct__7PhysicsFv
Physics::Physics()
{
    static float DefaultBox[8] = {0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 2.0f};

    *(u_long128 *)&m_unk0 = *(u_long128 *)&gUnitMatrix[12];
    *(u_long128 *)&m_unk10 = *(u_long128 *)&gUnitMatrix[12];
    m_unk106 = 1;
    m_unk10C = 0;
    m_unk110 = 0.03f;
    m_unk11C = 0.0f;
    m_unk118 = 0.0f;
    m_unkEC = 0x80113FD5;
    m_unkCC = 0;
    m_unkC0 = 0;
    m_unkE4 = 0;
    m_unkE0 = 0;
    m_unkC4 = -1000.0f;
    *(unsigned int *)((char *)this + 0xAC) = 0;
    m_unkE8 = 0;
    m_unkB4 = -1000.0f;
    m_unkFC = -1000.0f;
    m_unkF8 = 0;
    m_unk108 = 0;
    m_unkF4 = 0.0f;
    m_unk104 = 0;
    m_unk114 = 0;
    *(u_long128 *)((char *)this + 0x80) = *(u_long128 *)DefaultBox;
    *(u_long128 *)((char *)this + 0x90) = *(u_long128 *)&DefaultBox[4];
}
