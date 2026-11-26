// FLAGS: -str readonly
#include "PStaticInstanceGroup.h"
#include "PArray.h"
#include "PCDFile.h"
#include "PGfxEngine.h"

// TODO(header): foreign declarations
extern "C" void __dla__FPv(void *pBlock);
extern "C" void *__nwa__FUi(unsigned int nSize);
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" void sceVu0CopyVector(float *pDst, void *pSrc);
extern "C" void sceVu0ScaleVectorXYZ(float *pDst, float *pSrc, float fScale);
extern PGfxEngine gGfxEng;
class PShader {
public:
    void Render(int nFlags, bool bFlag, bool *pFlag);
};
struct PDisplayList {
    void DrawStaticInstances(tagVuStaticInstance *pInst, int nA, int nB, int nC, int nD, bool bE);
};
class PParticleManager {
public:
    void AddParticleInstanceGroup(PStaticInstanceGroup *pGroup);
};

struct StaticEntry {
    int nSize;
    void *pData;
};
struct StaticMasterMesh {
    PShader *m_unk0;
    int m_unk4;
    unsigned int m_unk8;
    StaticEntry *m_unkC;
    int m_unk10;
};
struct ParticleBlock {
    char _pad0[4];
    int m_unk4;
    struct tagVuParticle *m_unk8;
    char _pad0C[4];
    int m_unk10;
    char _pad14[5];
    unsigned char m_unk19;
    char _pad1A[0x16];
    unsigned long long m_unk30;
    char _pad38[0x80];
    float m_unkB8;
    float m_unkBC;
    float m_unkC0[4];
};

// DRAFT: 0x001D6EB0 RenderParticleInstances__20PStaticInstanceGroupFb
// note: DIFF 37; pBlock/nChunks registers swapped (orig s3/s2, ours s2/s3), remainder-branch lw s7 not in delay slot, path B srl/nLeft regs differ. Tried: pParticles local (path A+B, kept), hoisting it above nChunks (44/83), shared vec local (76 before path B fix).
unsigned int PStaticInstanceGroup::RenderParticleInstances(bool bFlag) {
    unsigned int nCount = 0;
    StaticMasterMesh *pMaster = (StaticMasterMesh *)m_unk8;
    if (pMaster != 0 && m_unk0 != 0 && m_unk4 != 0) {
        ParticleBlock *pBlock = (ParticleBlock *)pMaster->m_unk10;
        if (pBlock != 0) {
            float vec[4];
            if (bFlag && pBlock->m_unk19 != 0) {
                sceVu0CopyVector(vec, pBlock->m_unkC0);
                sceVu0ScaleVectorXYZ(vec, vec, 1.05f);
                gGfxEng.SetMaterial(vec, true, (unsigned long)pBlock->m_unk30, 0x50000);
                nCount = pBlock->m_unk4;
                unsigned int nChunks = nCount / 20;
                if (nCount % 20 != 0) {
                    nChunks += 1;
                }
                tagVuParticle *pParticles = pBlock->m_unk8;
                unsigned int nLeft = nCount;
                unsigned int nIndex = 0;
                unsigned int nOff = 0;
                if (nChunks != 0) {
                    do {
                        unsigned int nN = (nLeft < 0x14) ? nLeft : 0x14;
                        nLeft -= nN;
                        gGfxEng.BeginHeatHazeInstances((tagVuParticle *)((char *)pParticles + nOff), nN, pBlock->m_unkB8, pBlock->m_unkBC, false);
                        gGfxEng.m_unk154C80->DrawStaticInstances(m_unk0, m_unk4, 0x14, 0, 1, false);
                        nIndex++;
                        nOff += 0x280;
                    } while (nIndex < nChunks);
                }
            } else if (!bFlag && pBlock->m_unk19 == 0) {
                sceVu0CopyVector(vec, pBlock->m_unkC0);
                gGfxEng.SetMaterial(pBlock->m_unk10, vec, true, (unsigned long)pBlock->m_unk30, 0x50000);
                nCount = pBlock->m_unk4;
                unsigned int nChunks = nCount / 40;
                if (nCount % 40 != 0) {
                    nChunks += 1;
                }
                tagVuParticle *pParticles = pBlock->m_unk8;
                unsigned int nLeft = nCount;
                unsigned int nIndex = 0;
                unsigned int nOff = 0;
                if (nChunks != 0) {
                    do {
                        unsigned int nN = (nLeft < 0x28) ? nLeft : 0x28;
                        nLeft -= nN;
                        gGfxEng.BeginParticleInstances((tagVuParticle *)((char *)pParticles + nOff), nN, pBlock->m_unkB8, pBlock->m_unkBC, false);
                        gGfxEng.m_unk154C80->DrawStaticInstances(m_unk0, m_unk4, 0x28, 0, 1, false);
                        nIndex++;
                        nOff += 0x500;
                    } while (nIndex < nChunks);
                }
            }
            nCount *= m_unk4;
        }
    }
    return nCount;
}


// DRAFT: 0x001D7160 Render__20PStaticInstanceGroupFv
// note: DIFF 10 (was 39); guard is `if (nRet < cnt) do {...} while (nRet < cnt)` with nSize ternary before pData (orig loads offset 0 first). Left: second ternary's count not reloaded (ours CSEs a0, orig lw v0,8(v1) at 0x00A8), extra nop in its arm, so exit branch is one word short. Tried: `> 0` guard (folds to beqz), bool guard, while form (57), pMaster in pData ternary (83), operand-flipped pData compare (10).
unsigned int PStaticInstanceGroup::Render() {
    unsigned int nRet = 0;
    StaticMasterMesh *pMaster = (StaticMasterMesh *)m_unk8;
    if (pMaster != 0 && m_unk0 != 0 && m_unk4 != 0) {
        if (pMaster->m_unk10 != 0) {
            ((PParticleManager *)((char *)&gGfxEng + 0x154F00))->AddParticleInstanceGroup(this);
        } else {
            pMaster->m_unk0->Render(0x80, false, 0);
            if (nRet < ((StaticMasterMesh *)m_unk8)->m_unk8) {
                do {
                    int nSize = (nRet < ((StaticMasterMesh *)m_unk8)->m_unk8) ? ((StaticMasterMesh *)m_unk8)->m_unkC[nRet].nSize : 0;
                    void *pData = (nRet < ((StaticMasterMesh *)m_unk8)->m_unk8) ? ((StaticMasterMesh *)m_unk8)->m_unkC[nRet].pData : 0;
                    gGfxEng.BeginStaticInstances(pData, nSize);
                    gGfxEng.m_unk154C80->DrawStaticInstances(m_unk0, m_unk4, 0x28, 0, 1, false);
                    nRet++;
                } while (nRet < ((StaticMasterMesh *)m_unk8)->m_unk8);
            }
            nRet = m_unk4 * ((StaticMasterMesh *)m_unk8)->m_unk4;
        }
    }
    return nRet;
}

// FUNCTION: 0x001D72B0 Load__20PStaticInstanceGroupFP8PPakFileP6PArray16ePsx2FileVersion
int PStaticInstanceGroup::Load(PPakFile *pFile, PArray *pMasterMeshes, ePsx2FileVersion eVersion) {
    struct {
        unsigned int nIndex;
        int nCount;
        char _pad[0x10];
    } hdr;

    if (pFile == 0) {
        CdsAssert("PStaticInstanceGroup.cpp", 0x22, "poFile");
    }
    if (pMasterMeshes == 0) {
        CdsAssert("PStaticInstanceGroup.cpp", 0x23, "poMasterMeshes");
    }
    if (((PCDFile *)pFile)->Read(&hdr, 0x18) != 0x18) {
        return 0;
    }
    if (hdr.nIndex >= pMasterMeshes->m_unk0 || hdr.nCount == 0) {
        return 0;
    }
    m_unk8 = (hdr.nIndex < pMasterMeshes->m_unk0) ? pMasterMeshes->m_unk8[hdr.nIndex] : 0;
    if (m_unk8 == 0) {
        CdsAssert("PStaticInstanceGroup.cpp", 0x32, "mpMasterMesh");
    }
    m_unk4 = hdr.nCount;
    m_unk0 = (tagVuStaticInstance *)__nwa__FUi(m_unk4 * 0x50);
    if (m_unk0 == 0) {
        CdsAssert("PStaticInstanceGroup.cpp", 0x38, "mpInstances");
    }
    unsigned int nSize = m_unk4 * 0x50;
    if (((PCDFile *)pFile)->Read(m_unk0, nSize) != nSize) {
        return 0;
    }
    return 1;
}

// FUNCTION: 0x001D7440 __dt__20PStaticInstanceGroupFv
PStaticInstanceGroup::~PStaticInstanceGroup() {
    if (m_unk0 != 0) {
        __dla__FPv(m_unk0);
        m_unk0 = 0;
    }
    m_unk8 = 0;
}

// FUNCTION: 0x001D74B0 __ct__20PStaticInstanceGroupFv
PStaticInstanceGroup::PStaticInstanceGroup() {
    m_unk0 = 0;
    m_unk8 = 0;
    m_unk4 = 0;
}
