// FLAGS: -str readonly
#include "types.h"
#include "PFireDamageFx.h"
#include "PMNode.h"
#include "PParticleManager.h"

// TODO(header): foreign declarations
class PParticleSystem;
class PParticleOneShot;
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void __dl__FPv(void *pMem);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" int rand(void);
extern char gGfxEng[1504384];

// One row of the character table: six node ids, the node count, the number of
// nodes on fire, and the particle system id. The row is 0x24 bytes.
struct CharacterInfo {
    unsigned int uNodeIDs[6];
    int uNumNodeIDs;
    int uNumNodesOnFire;
    unsigned int uFxID;
};
extern CharacterInfo gCharacterInfoTable[13];

// Virtual view of a PParticleSystem subobject. Slot 0x08 is the virtual
// destructor and Start sits at slot 0x20; the slots in between are unnamed.
class PFireDamageFxView {
public:
    virtual ~PFireDamageFxView();
    virtual void Slot0C();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Start();
};

// FUNCTION: 0x00202FC0 GetCharacterType__FUi
int GetCharacterType(unsigned int uType) {
    int nType = 0;
    switch (uType) {
    case 0x3:
        nType = 0x1;
        break;
    case 0x17:
        nType = 0x2;
        break;
    case 0x22:
        nType = 0x3;
        break;
    case 0x37:
        nType = 0x4;
        break;
    case 0x36:
        nType = 0x6;
        break;
    case 0x2b:
        nType = 0x5;
        break;
    case 0x2a:
        nType = 0xa;
        break;
    case 0x4a:
        nType = 0x9;
        break;
    case 0x72:
        nType = 0xb;
        break;
    case 0x6b:
        nType = 0xc;
        break;
    }
    return nType;
}

// DRAFT: 0x00203090 Create__13PFireDamageFxFP6PMNodeUi
// note: DIFF 202 words. Original frame is 0x80 with apNodes at sp+0x70 and s4/s5 holding pNode/pFx; ours is 0x70 with pFx in s1. Tried: block-scope vs merged pNode/pFx locals, apNodes declared first, pFx hoisted to function scope; all 202.
int PFireDamageFx::Create(PMNode *poRoot, unsigned int uCharType) {
    PMNode *apNodes[3];
    ((poRoot) ? (void)0 : CdsAssert__FPciPc("PFireDamageFx.cpp", 0x59, "poRoot"));
    CharacterInfo *apInfo = &gCharacterInfoTable[GetCharacterType(uCharType)];
    int nFired = 0;
    memset(apNodes, 0, 0xC);
    int bResult = 0;
    PParticleSystem *pFx = 0;
    if (apInfo->uNumNodesOnFire != 0) {
        PParticleManager *pMgr = (PParticleManager *)(gGfxEng + 0x154F00);
        ((apInfo->uNumNodeIDs == 6) ? (void)0 : CdsAssert__FPciPc("PFireDamageFx.cpp", 0x67, "apInfo->uNumNodeIDs == 6"));
        ((apInfo->uNumNodesOnFire == 2) ? (void)0 : CdsAssert__FPciPc("PFireDamageFx.cpp", 0x68, "apInfo->uNumNodesOnFire == 2"));
        apNodes[0] = poRoot->Find(apInfo->uNodeIDs[(int)(0.5f + (2.0f * ((float)rand() / 2.1474836e9f)))]);
        PMNode *pNode = apNodes[0];
        if (pNode != 0) {
            pFx = (PParticleSystem *)pMgr->Create(apInfo->uFxID, 0.0f, 0.0f, 0.0f, 0, true);
            ((pFx)? (void)0 : CdsAssert__FPciPc("PFireDamageFx.cpp", 0x72, "ahFx"));
            if (pFx != 0) {
                if (pMgr->IsValid(pFx) != 0) {
                    ((PFireDamageFxView *)pFx)->Start();
                }
            }
            pNode->AttachFx((unsigned int)pFx, 25000.0f, 25000.0f, 26000.0f, 26000.0f, false);
            nFired = 1;
        }
        apNodes[nFired] = poRoot->Find(apInfo->uNodeIDs[(int)(0.5f + (3.0f + (2.0f * ((float)rand() / 2.1474836e9f))))]);
        PMNode *pNode2 = apNodes[nFired];
        if (pNode2 != 0) {
            PParticleSystem *pFx2 = (PParticleSystem *)pMgr->Create(apInfo->uFxID, 0.0f, 0.0f, 0.0f, 0, true);
            ((pFx2)? (void)0 : CdsAssert__FPciPc("PFireDamageFx.cpp", 0x82, "ahFx"));
            if (pFx2 != 0) {
                if (pMgr->IsValid(pFx2) != 0) {
                    ((PFireDamageFxView *)pFx2)->Start();
                }
            }
            pNode2->AttachFx((unsigned int)pFx2, 25000.0f, 25000.0f, 26000.0f, 26000.0f, false);
            nFired += 1;
        }
        bResult = nFired > 0;
    }
    return bResult;
}

// FUNCTION: 0x002033C0 __dt__13PFireDamageFxFv
PFireDamageFx::~PFireDamageFx() {}
