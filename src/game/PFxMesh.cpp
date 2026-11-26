// FLAGS: -str readonly
#include "types.h"
#include "PFxMesh.h"
#include "PMNode.h"

// TODO(header): foreign declarations
extern "C" void SetWorldMatrix__10PGfxEngineFP5PMat4(void *pThis, PMat4 *pMat);
extern "C" void BeginVertexGlow__10PGfxEngineFv(void *pThis);
extern "C" void EndVertexGlow__10PGfxEngineFv(void *pThis);
extern "C" void RenderAllPolys__5PMeshFv(void *pThis);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern char gGfxEng[1504384];

// The game's assert tests the condition at runtime and reports its source text.
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("PFxMesh.cpp", line, #cond))

// FUNCTION: 0x001BEDE0 Render__7PFxMeshFv
void PFxMesh::Render() {
    if (m_unk4 != 0) {
        SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, m_unk0);
        BeginVertexGlow__10PGfxEngineFv(gGfxEng);
        RenderAllPolys__5PMeshFv(m_unk4);
        EndVertexGlow__10PGfxEngineFv(gGfxEng);
    }
    m_unk8.m_unk4 = 0;
    PFxMesh *pChild = 0;
    if (m_unk8.m_unk0 != 0) {
        pChild = (PFxMesh *)m_unk8.m_unk8[0];
    }
    while (pChild != 0) {
        pChild->Render();
        unsigned int nIndex = m_unk8.m_unk4 + 1;
        m_unk8.m_unk4 = nIndex;
        pChild = (nIndex < m_unk8.m_unk0) ? (PFxMesh *)m_unk8.m_unk8[m_unk8.m_unk4] : 0;
    }
}

// FUNCTION: 0x001BEEA0 Init__7PFxMeshFP6PMNodeP6PMNode
bool PFxMesh::Init(PMNode *pFxObj, PMNode *pAnimObj) {
    CDS_ASSERT(0x27, pFxObj);
    CDS_ASSERT(0x28, pAnimObj);
    PMNode *pFoundNode = pFxObj->Find(pAnimObj->m_unk08);
    if (pFoundNode == 0) {
        return 0;
    }
    m_unk4 = (PMesh *)pFoundNode->m_unk10;
    m_unk0 = (PMat4 *)&pAnimObj->m_unk40;
    PArray *apFxObjChildList = (PArray *)&pFoundNode->m_unk14;
    CDS_ASSERT(0x3C, apFxObjChildList);
    PArray *apAnimObjChildList = (PArray *)&pAnimObj->m_unk14;
    CDS_ASSERT(0x3F, apAnimObjChildList);

    apFxObjChildList->m_unk4 = 0;
    PMNode *pFxChild = (apFxObjChildList->m_unk0 != 0) ? (PMNode *)apFxObjChildList->m_unk8[0] : 0;
    apAnimObjChildList->m_unk4 = 0;
    PMNode *pAnimChild = (apAnimObjChildList->m_unk0 != 0) ? (PMNode *)apAnimObjChildList->m_unk8[0] : 0;

    while (pFxChild != 0 && pAnimChild != 0) {
        PFxMesh *apChildFxMesh = new PFxMesh;
        CDS_ASSERT(0x4A, apChildFxMesh);
        apChildFxMesh->Init(pFxChild, pAnimChild);
        m_unk8.Add(apChildFxMesh);

        pFxChild = (++apFxObjChildList->m_unk4 < apFxObjChildList->m_unk0) ? (PMNode *)apFxObjChildList->m_unk8[apFxObjChildList->m_unk4] : 0;

        pAnimChild = (++apAnimObjChildList->m_unk4 < apAnimObjChildList->m_unk0) ? (PMNode *)apAnimObjChildList->m_unk8[apAnimObjChildList->m_unk4] : 0;
    }
    return 1;
}

// FUNCTION: 0x001BF0B0 __dt__7PFxMeshFv
PFxMesh::~PFxMesh() {
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk8.m_unk4 = 0;
    PFxMesh *pChild = 0;
    if (m_unk8.m_unk0 != 0) {
        pChild = (PFxMesh *)m_unk8.m_unk8[0];
    }
    while (pChild != 0) {
        delete pChild;
        unsigned int nIndex = m_unk8.m_unk4 + 1;
        m_unk8.m_unk4 = nIndex;
        pChild = (nIndex < m_unk8.m_unk0) ? (PFxMesh *)m_unk8.m_unk8[m_unk8.m_unk4] : 0;
    }
    if (m_unk8.m_unk8 != 0) {
        m_unk8.m_unk0 = 0;
        m_unk8.m_unk4 = 0;
    }
}

// FUNCTION: 0x001BF190 __ct__7PFxMeshFv
PFxMesh::PFxMesh() {
    m_unk0 = 0;
    m_unk4 = 0;
}
