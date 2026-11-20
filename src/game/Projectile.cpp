#include "Projectile.h"
#include "types.h"

// TODO(header): foreign declarations
extern unsigned char __vt__10Projectile[];
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bA, bool bB);
extern "C" void LoadMesh__15EntityBaseClassFUibb(void *pThis, unsigned int nMesh, bool bA, bool bB);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" void ProcessFxTriggers__6PMNodeFfP5PMat4bb(void *pThis, float fTime, void *pMat, bool bA, bool bB);
extern "C" void __dl__FPv(void *pMem);
extern "C" int InitProjectile__10ProjectileFQ210Projectile14ProjectileTypePA4_fPA4_fPA4_f(void *pThis, int nType, float (*pA)[4], float (*pB)[4], float (*pC)[4]);
extern "C" float sinf(float fX);
extern "C" float cosf(float fX);
extern float IceDoomPos[5][4];

// FUNCTION: 0x00166BB0 __dt__10ProjectileFv
extern "C" Projectile *__dt__10ProjectileFv(Projectile *pThis, short nFlag) {
    if (pThis != 0) {
        pThis->m_unk0 = __vt__10Projectile;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x00166C20 Delete__10ProjectileFv
void Projectile::Delete() {
    PMNode *pNode = m_unk3C;
    if (pNode != 0) {
        ProcessFxTriggers__6PMNodeFfP5PMat4bb(pNode, -1.0f, 0, true, false);
        LoadMesh__15EntityBaseClassFUibb(this, 0, false, true);
    }
    SetState__15EntityBaseClassFi(this, -2);
}

// FUNCTION: 0x00166C80 DoDamage__10ProjectileFb
void Projectile::DoDamage(bool bFlag) {
    ProjectileRecord *pRec = &ProjectileTable[m_unk1B0];
    if (bFlag) {
        unsigned short nHi = pRec->m_unk1A;
        m_unk15C = pRec->m_unk18;
        m_unk15E = nHi;
    } else {
        unsigned short nHi = pRec->m_unk1A;
        m_unk15C = 0;
        m_unk15E = nHi;
    }
}

// DRAFT: 0x00166F00 InitIceDoom__10ProjectileFiPA4_fPA4_f
// note: 36 words differ: original has dead lui v0,0x3F80 and keeps the IceDoomPos row in v1 (ours uses v0); tried inline indexing (40), float*/float(*)[4] row pointers (36), unused 1.0f local (dropped by compiler)
void Projectile::InitIceDoom(int nIndex, float (*pOut)[4], float (*pIn)[4]) {
    float vec[4];
    m_unk1BC = nIndex;
    float fAngle = 0.017453292f * pIn[0][1];
    float fSin = sinf(fAngle);
    float fCos = cosf(fAngle);
    float (*pRow)[4] = IceDoomPos + nIndex;
    vec[0] = pOut[0][0] + (pRow[0][2] * fSin + pRow[0][0] * fCos);
    vec[1] = pOut[0][1];
    vec[2] = pOut[0][2] + (pRow[0][2] * fCos - pRow[0][0] * fSin);
    InitProjectile__10ProjectileFQ210Projectile14ProjectileTypePA4_fPA4_fPA4_f(this, 0x19, (float (*)[4])vec, pIn, 0);
    *(u_long128 *)&m_unk1D0 = *(u_long128 *)pOut;
    *(u_long128 *)&m_unk1C0 = *(u_long128 *)pIn;
    m_unk1B4 = 15.0f;
}

// FUNCTION: 0x00168140 __ct__10ProjectileFv
Projectile::Projectile() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 5, 1);
    m_unk0 = __vt__10Projectile;
    EnableSleep__15EntityBaseClassFbb(this, false, false);
    m_unk1BC = 0;
    m_unk1F4 = 0;
}
