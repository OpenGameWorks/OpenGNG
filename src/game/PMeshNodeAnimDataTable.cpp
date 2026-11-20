// FLAGS: -str readonly
#include "PMeshNodeAnimDataTable.h"
#include "PCDFile.h"

// TODO(header): foreign declarations
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void *__construct_new_array(void *pArray, void (*pCtor)(void *), void (*pDtor)(void *, short), unsigned int nElemSize, int nCount);
extern "C" void __destroy_new_array(void *pArray, void (*pDtor)(void *, short));
extern "C" void *__ct__17PMeshNodeAnimDataFv(PMeshNodeAnimData *pThis);
extern "C" void __dt__17PMeshNodeAnimDataFv(PMeshNodeAnimData *pThis, short nFlag);
extern unsigned char __vt__9PResource[];
extern unsigned char __vt__22PMeshNodeAnimDataTable[];

// FUNCTION: 0x00191570 Load__22PMeshNodeAnimDataTableFP8PPakFile16ePsx2FileVersion
int PMeshNodeAnimDataTable::Load(PPakFile *pFile, ePsx2FileVersion eVersion) {
    if (pFile == 0) {
        CdsAssert("PMeshNodeAnimDataTable.cpp", 0x22, "poFile");
    }
    if (((PCDFile *)pFile)->Read(&m_unk08, 4) != 4) {
        return 0;
    }
    if (((PCDFile *)pFile)->Read(&m_unk10, 0x20) != 0x20) {
        return 0;
    }
    m_unk0C = (PMeshNodeAnimData *)__construct_new_array(__nwa__FUi(m_unk08 * 0x18 + 0x10), (void (*)(void *))__ct__17PMeshNodeAnimDataFv, (void (*)(void *, short))__dt__17PMeshNodeAnimDataFv, 0x18, m_unk08);
    if (m_unk0C == 0) {
        CdsAssert("PMeshNodeAnimDataTable.cpp", 0x2F, "mpAnimTable");
    }
    for (unsigned int i = 0; i < m_unk08; i++) {
        if (m_unk0C[i].Load(pFile, eVersion) == 0) {
            return 0;
        }
    }
    int nTag = 0;
    if (((PCDFile *)pFile)->Read(&nTag, 4) != 4) {
        return 0;
    }
    return (nTag != 0xB) ^ 1;
}

// FUNCTION: 0x00191700 __dt__22PMeshNodeAnimDataTableFv
PMeshNodeAnimDataTable::~PMeshNodeAnimDataTable() {
    *(unsigned char **)this = __vt__22PMeshNodeAnimDataTable;
    if (m_unk0C != 0) {
        __destroy_new_array(m_unk0C, (void (*)(void *, short))__dt__17PMeshNodeAnimDataFv);
        m_unk0C = 0;
    }
    m_unk08 = 0;
    if (this != 0) {
        *(unsigned char **)this = __vt__9PResource;
        m_unk04 = 0;
    }
}

// FUNCTION: 0x00191790 __ct__22PMeshNodeAnimDataTableFv
PMeshNodeAnimDataTable::PMeshNodeAnimDataTable() {
    *(unsigned char **)this = __vt__9PResource;
    m_unk04 = 0;
    *(unsigned char **)this = __vt__22PMeshNodeAnimDataTable;
    m_unk08 = 0;
    m_unk0C = 0;
    m_unk04 = 5;
    m_unk10 = 0x44FFE000;
}
