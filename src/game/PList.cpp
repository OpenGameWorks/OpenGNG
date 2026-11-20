// FLAGS: -str readonly
#include "types.h"
#include "PList.h"

// TODO(header): foreign declarations
extern "C" void __dl__FPv(void *pMem);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);

// DRAFT: 0x00131990 RemoveAll__5PListFv
// note: 7 words differ; original keeps head in s0 and loads next into s0 in the jal delay slot, ours keeps node in a0. Tried pDead temp (14), while loop (14), pNext outside if (7), pNext in block (7).
void PList::RemoveAll() {
    PListNode *pNode = m_unk4;
    if (pNode != 0) {
        do {
            PListNode *pNext = pNode->m_unk4;
            __dl__FPv(pNode);
            pNode = pNext;
        } while (pNode != 0);
    }
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk8 = 0;
    m_unkC = 0;
}

// FUNCTION: 0x00131A00 Remove__5PListFPv
int PList::Remove(void *pItem) {
    if (pItem == 0) {
        return 0;
    }
    PListNode *pNode = m_unk4;
    if (pNode != 0) {
        do {
            if (pNode->m_unk0 == pItem) {
                RemoveAt(pNode);
                m_unkC = 0;
                return 1;
            }
            pNode = pNode->m_unk4;
        } while (pNode != 0);
    }
    return 0;
}

// FUNCTION: 0x00131A70 RemoveAt__5PListFPv
void PList::RemoveAt(void *pNode) {
    PListNode *node = (PListNode *)pNode;
    if (node == 0) {
        CdsAssert__FPciPc("PList.cpp", 0x8C, "pNode");
    }
    PListNode *prev = node->m_unk8;
    PListNode *next = node->m_unk4;
    if (prev != 0) {
        prev->m_unk4 = next;
    } else {
        m_unk4 = next;
    }
    if (next != 0) {
        next->m_unk8 = prev;
    } else {
        m_unk8 = prev;
    }
    __dl__FPv(node);
    m_unk0 -= 1;
    if (m_unk0 < 0) {
        CdsAssert__FPciPc("PList.cpp", 0x9E, "(int)muNumNodes >= 0");
    }
}

// FUNCTION: 0x00131B20 RemoveCurrent__5PListFv
void PList::RemoveCurrent() {
    if (m_unkC == 0) {
        CdsAssert__FPciPc("PList.cpp", 0x76, "mpCur");
    }
    PListNode *prev = m_unkC->m_unk8;
    PListNode *next = m_unkC->m_unk4;
    if (prev != 0) {
        prev->m_unk4 = next;
    } else {
        m_unk4 = next;
    }
    if (next != 0) {
        next->m_unk8 = prev;
    } else {
        m_unk8 = prev;
    }
    __dl__FPv(m_unkC);
    m_unkC = prev;
    m_unk0 -= 1;
}

// FUNCTION: 0x00131BB0 InsertBefore__5PListFPv
void PList::InsertBefore(void *pItem) {
    if (m_unk4 == 0) {
        CdsAssert__FPciPc("PList.cpp", 0x5D, "mpList");
    }
    if (m_unkC == 0) {
        CdsAssert__FPciPc("PList.cpp", 0x5E, "mpCur");
    }
    PListNode *pNode = (PListNode *)__nw__FUi(0xC);
    if (pNode == 0) {
        CdsAssert__FPciPc("PList.cpp", 0x61, "pNode");
    }
    pNode->m_unk0 = pItem;
    pNode->m_unk4 = m_unkC;
    PListNode *prev = m_unkC->m_unk8;
    pNode->m_unk8 = prev;
    if (prev == 0) {
        m_unk4 = pNode;
    } else {
        prev->m_unk4 = pNode;
    }
    m_unkC->m_unk8 = pNode;
    m_unk0 += 1;
}

// FUNCTION: 0x00131C90 Add__5PListFPv
int PList::Add(void *pItem) {
    PListNode *pNode = (PListNode *)__nw__FUi(0xC);
    if (pNode == 0) {
        CdsAssert__FPciPc("PList.cpp", 0x33, "apNode");
    }
    if (pNode == 0) {
        return 0;
    }
    pNode->m_unk0 = pItem;
    pNode->m_unk4 = 0;
    pNode->m_unk8 = 0;
    if (m_unk4 == 0) {
        m_unk4 = pNode;
        m_unk8 = m_unk4;
    } else {
        if (m_unk8 == 0) {
            CdsAssert__FPciPc("PList.cpp", 0x48, "mpTail");
        }
        pNode->m_unk8 = m_unk8;
        m_unk8->m_unk4 = pNode;
        m_unk8 = pNode;
    }
    m_unk0 += 1;
    m_unkC = 0;
    return 1;
}

// FUNCTION: 0x00131D70 __dt__5PListFv
PList::~PList() {
    RemoveAll();
}

// FUNCTION: 0x00131DD0 __ct__5PListFv
PList::PList() {
    m_unk4 = 0;
    m_unk8 = 0;
    m_unkC = 0;
    m_unk0 = 0;
}
