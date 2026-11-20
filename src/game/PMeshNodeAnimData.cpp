// FLAGS: -str readonly
#include "PMeshNodeAnimData.h"
#include "PAnim.h"
#include "PCDFile.h"

// TODO(header): foreign declarations
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void __dl__FPv(void *pMem);

// DRAFT: 0x00191160 DestroyFxTriggers__17PMeshNodeAnimDataFv
// note: 32 words differ; ours keeps this in s3 and adds a pointer induction (addiu s2,s2,4) over the loop index, original keeps this in s2 with sll/addu indexing. Tried ternary, for, signed, if/else variants; none closer.
void PMeshNodeAnimData::DestroyFxTriggers() {
    unsigned int nCount = m_unk8.m_unk0;
    unsigned int i = 0;
    if (nCount != 0) {
        do {
            void *pItem = 0;
            if (i < m_unk8.m_unk0) {
                pItem = m_unk8.m_unk8[i];
            }
            if (pItem != 0) {
                __dl__FPv(pItem);
            }
            i++;
        } while (i < nCount);
    }
    if (m_unk8.m_unk8 != 0) {
        m_unk8.m_unk0 = 0;
        m_unk8.m_unk4 = 0;
    }
}

// FUNCTION: 0x00191200 LoadFxTriggers__17PMeshNodeAnimDataFP8PPakFile
int PMeshNodeAnimData::LoadFxTriggers(PPakFile *pFile) {
    unsigned int i;
    unsigned int nCount = 0;
    DestroyFxTriggers();
    if (((PCDFile *)pFile)->Read(&nCount, 4) != 4) {
        return 0;
    }
    i = 0;
    while (i < nCount) {
        tagPMeshNodeFxTrigger *pTrigger = (tagPMeshNodeFxTrigger *)__nw__FUi(0x28);
        if (pTrigger == 0) {
            CdsAssert("PMeshNodeAnimData.cpp", 0x71, "apTrigger");
        }
        if (((PCDFile *)pFile)->Read(pTrigger, 0x28) != 0x28) {
            return 0;
        }
        pTrigger->m_unk20 = 0;
        pTrigger->m_unk24 = 0;
        m_unk8.Add(pTrigger);
        i++;
    }
    return 1;
}

// FUNCTION: 0x001912F0 Load__17PMeshNodeAnimDataFP8PPakFile16ePsx2FileVersion
int PMeshNodeAnimData::Load(PPakFile *pFile, ePsx2FileVersion eVersion) {
    int nBuf[8];
    int nTag;
    if (pFile == 0) {
        CdsAssert("PMeshNodeAnimData.cpp", 0x20, "poFile");
    }
    if (eVersion >= 0x20000) {
        if (((PCDFile *)pFile)->Read(&m_unk0, 4) != 4) {
            return 0;
        }
    } else {
        if (((PCDFile *)pFile)->Read(nBuf, 0x20) != 0x20) {
            return 0;
        }
        m_unk0 = nBuf[0];
    }
    nTag = 0;
    if (((PCDFile *)pFile)->Read(&nTag, 4) != 4) {
        return 0;
    }
    if (nTag != 4) {
        return 0;
    }
    if (m_unk4 != 0) {
        CdsAssert("PMeshNodeAnimData.cpp", 0x42, "mpAnim == NULL");
    }
    m_unk4 = new PAnim;
    if (m_unk4 == 0) {
        return 0;
    }
    if (m_unk4->Load(pFile) == 0) {
        return 0;
    }
    if (m_unk4->m_unk4 == 1) {
        m_unk4->m_unk4 = 0;
    }
    if (eVersion >= 0x10001 && LoadFxTriggers(pFile) == 0) {
        return 0;
    }
    return 1;
}

// FUNCTION: 0x001914A0 __dt__17PMeshNodeAnimDataFv
PMeshNodeAnimData::~PMeshNodeAnimData() {
    if (m_unk4 != 0) {
        delete m_unk4;
        m_unk4 = 0;
    }
    DestroyFxTriggers();
}

// FUNCTION: 0x00191530 __ct__17PMeshNodeAnimDataFv
PMeshNodeAnimData::PMeshNodeAnimData() {
    m_unk0 = 0;
    m_unk4 = 0;
}
