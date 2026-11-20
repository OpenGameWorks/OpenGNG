// FLAGS: -str readonly
#include "types.h"
#include "PShadowVolume.h"
#include "PMNode.h"
#include "PCDFile.h"

// TODO(header): foreign declarations
void operator delete(void *pMem);
void operator delete[](void *pMem);
extern "C" void *__nw__FUi(unsigned int);
extern "C" void *__nwa__FUi(unsigned int);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void memcpy(void *, const void *, unsigned int);

// DRAFT: 0x001D8EA0 SetShadowCaster__13PShadowVolumeFP6PMNode
// note: 2 words differ: the count==1 ternary test uses a sltu into v1 where the original uses at; tried unsigned compare, bool local (folded away), and deferred i/off init (fixed register map).
void PShadowVolume::SetShadowCaster(PMNode *pNode) {
    if (pNode != 0) {
        unsigned int i;
        unsigned int off;
        int count = (int)m_unk0;
        if (count == 1) {
            int nonZero = (count != 0);
            PShadowVolumeNode *pFirst = nonZero ? (PShadowVolumeNode *)m_unk8[0] : 0;
            pFirst->m_unk1C = (char *)pNode + 0x40;
            pFirst->m_unk20 = pNode;
            return;
        }
        if (0 < count) {
            i = 0;
            off = 0;
            do {
                PShadowVolumeNode *pEntry = (i < m_unk0) ? (PShadowVolumeNode *)*(void **)((char *)m_unk8 + off) : 0;
                if (pEntry != 0) {
                    PMNode *pFound = pNode->Find(pEntry->m_unk0);
                    if (pFound != 0) {
                        pEntry->m_unk1C = (char *)pFound + 0x40;
                        pEntry->m_unk20 = pFound;
                    } else {
                        pEntry->m_unk1C = 0;
                        pEntry->m_unk20 = 0;
                    }
                }
                i++;
                off += 4;
            } while ((int)i < count);
        }
    } else {
        m_unk18 = 0;
        int count = (int)m_unk0;
        if (0 < count) {
            unsigned int i = 0;
            do {
                PShadowVolumeNode *pEntry = (i < m_unk0) ? (PShadowVolumeNode *)m_unk8[i] : 0;
                pEntry->m_unk1C = 0;
                i++;
                pEntry->m_unk20 = 0;
            } while ((int)i < count);
        }
    }
}

// DRAFT: 0x001D8FF0 Load__13PShadowVolumeFP8PPakFile
// note: 68 words differ: size and node pointer swap registers (original keeps &size in s2, node in s1). Tried pointer locals for size/count (121 words), block-scope and function-scope size locals (68).
int PShadowVolume::Load(PPakFile *pFile) {
    char header[0x20];
    char entry[0x38];
    unsigned int size;
    unsigned int i;
    if (pFile == 0) {
        CdsAssert__FPciPc("PShadowVolume.cpp", 0x5C, "poFile");
    }
    if (((PCDFile *)pFile)->Read(header, 0x20) != 0x20) {
        return 0;
    }
    if (*(unsigned int *)header != 0xD00BD00B) {
        return 0;
    }
    if (*(int *)(header + 8) == 0) {
        return 0;
    }
    i = 0;
    while ((int)i < *(int *)(header + 8)) {
        if (((PCDFile *)pFile)->Read(entry, 0x38) != 0x38) {
            return 0;
        }
        size = *(unsigned int *)(entry + 0x14);
        if (size == 0) {
            return 0;
        }
        PShadowVolumeNode *pNode = (PShadowVolumeNode *)__nw__FUi(0x28);
        if (pNode == 0) {
            CdsAssert__FPciPc("PShadowVolume.cpp", 0x78, "apNode");
        }
        pNode->m_unk0 = *(int *)entry;
        memcpy(pNode->m_unkC, entry + 4, 0x10);
        pNode->m_unk8 = size;
        pNode->m_unk1C = 0;
        pNode->m_unk4 = __nwa__FUi(size);
        if (pNode->m_unk4 == 0) {
            CdsAssert__FPciPc("PShadowVolume.cpp", 0x7F, "apNode->pvVertexData");
        }
        if (((PCDFile *)pFile)->Read(pNode->m_unk4, size) != size) {
            operator delete[](pNode->m_unk4);
            operator delete(pNode);
            return 0;
        }
        pNode->m_unk24 = 1;
        Add(pNode);
        i++;
    }
    return 1;
}

// DRAFT: 0x001D91D0 __dt__13PShadowVolumeFv
// note: 1 word differs, base PArray dtor flag is 0 (original -1); explicit PArray::~PArray() and __dt__6PArrayFv(this,-1) give 19 words.
PShadowVolume::~PShadowVolume() {
    int count = (int)m_unk0;
    if (0 < count) {
        unsigned int i = 0;
        do {
            PShadowVolumeNode *pNode = (i < m_unk0) ? (PShadowVolumeNode *)m_unk8[i] : 0;
            if (pNode != 0) {
                if (pNode->m_unk4 != 0 && pNode->m_unk24 != 0) {
                    operator delete[](pNode->m_unk4);
                }
                operator delete(pNode);
            }
            i++;
        } while ((int)i < count);
    }
    if (m_unk8 != 0) {
        m_unk0 = 0;
        m_unk4 = 0;
    }
    m_unk14 = 0;
}

// FUNCTION: 0x001D92D0 __ct__13PShadowVolumeFP13PShadowVolume
PShadowVolume::PShadowVolume(PShadowVolume *pSource) {
    if (pSource == 0) {
        CdsAssert__FPciPc("PShadowVolume.cpp", 0x19, "apNodeArray");
    }
    int count = (int)pSource->m_unk0;
    if (0 < count) {
        unsigned int i = 0;
        do {
            PShadowVolumeNode *pNode = 0;
            if (i < pSource->m_unk0) {
                pNode = (PShadowVolumeNode *)pSource->m_unk8[i];
            }
            if (pNode != 0) {
                PShadowVolumeNode *pCopy = (PShadowVolumeNode *)__nw__FUi(0x28);
                if (pCopy == 0) {
                    CdsAssert__FPciPc("PShadowVolume.cpp", 0x22, "apNewNode");
                }
                memcpy(pCopy, pNode, 0x28);
                pCopy->m_unk24 = 0;
                pCopy->m_unk1C = 0;
                pCopy->m_unk20 = 0;
                Add(pCopy);
            }
            i++;
        } while ((int)i < count);
    }
    if (m_unk0 != pSource->m_unk0) {
        CdsAssert__FPciPc("PShadowVolume.cpp", 0x2B, "moShadowVolumeNodes.GetCount() == apNodeArray->GetCount()");
    }
    m_unk18 = 0;
}

// FUNCTION: 0x001D9410 __ct__13PShadowVolumeFv
PShadowVolume::PShadowVolume() {
    m_unk18 = 0;
    m_unk14 = 0;
    m_unk10 = 0xC9742400;
}
