// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "PStaticInstanceMesh.h"
#include "PPakFile.h"
#include "PShader.h"

// TODO(header): foreign declarations
class PMNode;
class PParticleOneShot;
class PParticleManager {
public:
    PParticleOneShot *Create(unsigned int hFx, float fA, float fB, float fC, PMNode *pNode, bool bFlag);
};
extern "C" void *__dt__7PShaderFv(void *pThis, short nFlag);
extern "C" void __dla__FPv(void *pBlock);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" int Load__7PShaderFP8PPakFileP6PArrayb(PShader *pThis, PPakFile *pFile, PArray *pArray, bool bFlag);
extern char gGfxEng[1504384];

#define CDS_ASSERT(line, cond, expr) ((cond) ? (void)0 : CdsAssert("PStaticInstanceMesh.cpp", line, expr))

// Virtual slot 0x08 is the destructor (virtual #0); slot 0x20 is Slot06.
class PParticleOneShot {
public:
    virtual ~PParticleOneShot();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();

    char _pad04[0x17];
    unsigned char m_unk1B;     // 0x1B
    char _pad1C[4];
    unsigned int m_unk20;      // 0x20
    unsigned int m_unk24;      // 0x24
};

// FUNCTION: 0x001D6AE0 Load__19PStaticInstanceMeshFP8PPakFileP6PArray16ePsx2FileVersion
int PStaticInstanceMesh::Load(PPakFile *pFile, PArray *pArray, ePsx2FileVersion eVersion) {
    struct Header {
        unsigned int count;
        unsigned int field;
        unsigned int flag;
        unsigned int pad[3];
    };
    Header hdr;
    unsigned int entryHdr[4];
    unsigned int i;

    CDS_ASSERT(0x3A, pFile, "poFile");
    CDS_ASSERT(0x3B, pArray, "poTextureHandles");
    if (pFile->Read(&hdr, 0x18) != 0x18) {
        return 0;
    }
    if (hdr.flag) {
        PParticleOneShot *pFx = ((PParticleManager *)(gGfxEng + 0x154F00))->Create(hdr.flag, 0.0f, 0.0f, 0.0f, 0, false);
        m_unk10 = pFx;
        if (!m_unk10) {
            return 0;
        }
        pFx = m_unk10;
        pFx->m_unk1B = 0;
        pFx->m_unk20 = 0;
        pFx->m_unk24 = 0;
        m_unk10->Slot06();
        return 1;
    }
    if (!hdr.count) {
        return 0;
    }
    m_unk0 = new PShader;
    CDS_ASSERT(0x5B, m_unk0, "mpoShader");
    if (!Load__7PShaderFP8PPakFileP6PArrayb(m_unk0, pFile, pArray, false)) {
        return 0;
    }
    m_unkC = (PStaticInstanceEntry *)__nwa__FUi(hdr.count << 3);
    CDS_ASSERT(0x64, m_unkC, "mpStrips");
    for (i = 0; i < hdr.count; i++) {
        if (pFile->Read(entryHdr, 0x10) != 0x10) {
            return 0;
        }
        m_unkC[i].m_unk0 = entryHdr[0];
        m_unkC[i].m_unk4 = __nwa__FUi(entryHdr[0]);
        CDS_ASSERT(0x71, m_unkC[i].m_unk4, "mpStrips[uCount].pvVertexData");
        if (pFile->Read(m_unkC[i].m_unk4, entryHdr[0]) != (int)entryHdr[0]) {
            return 0;
        }
    }
    m_unk4 = hdr.field;
    m_unk8 = hdr.count;
    return 1;
}

// FUNCTION: 0x001D6D80 __dt__19PStaticInstanceMeshFv
PStaticInstanceMesh::~PStaticInstanceMesh() {
    unsigned int i;
    PStaticInstanceEntry *pEntry;

    if (m_unk0) {
        __dt__7PShaderFv(m_unk0, 1);
        m_unk0 = 0;
    }
    if (m_unkC) {
        if (m_unk8) {
            for (i = 0; i < m_unk8; i++) {
                pEntry = (PStaticInstanceEntry *)((char *)m_unkC + i * 8);
                if (pEntry && pEntry->m_unk4) {
                    __dla__FPv(pEntry->m_unk4);
                }
            }
            __dla__FPv(m_unkC);
            m_unkC = 0;
            m_unk8 = 0;
        }
    }
    if (m_unk10) {
        delete m_unk10;
        m_unk10 = 0;
    }
}

// FUNCTION: 0x001D6E90 __ct__19PStaticInstanceMeshFv
PStaticInstanceMesh::PStaticInstanceMesh() {
    m_unk0 = 0;
    m_unk4 = 0;
    m_unkC = 0;
    m_unk8 = 0;
    m_unk10 = 0;
}
