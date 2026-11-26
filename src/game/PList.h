#ifndef PLIST_H
#define PLIST_H

// Doubly linked list (PList.cpp). Nodes hold the item
// pointer at 0x00, the next node at 0x04 and the previous node at 0x08.
struct PListNode {
    void *m_unk0;           // 0x00 item pointer compared by Remove
    PListNode *m_unk4;      // 0x04 next node
    PListNode *m_unk8;      // 0x08 previous node
};

class PList {
public:
    PList();
    ~PList();
    int Add(void *pItem);
    void InsertBefore(void *pItem);
    void RemoveAll();
    int Remove(void *pItem);
    void RemoveAt(void *pNode);
    void RemoveCurrent();

    // Cursor iteration: GetFirst rewinds the cursor to the head; GetNext advances it and
    // restarts from the head when the cursor is unset. Both return the node's item.
    void *GetFirst() {
        m_unkC = m_unk4;
        if (m_unk4 != 0) {
            return m_unk4->m_unk0;
        }
        return 0;
    }
    void *GetNext() {
        if (m_unkC == 0) {
            return GetFirst();
        }
        PListNode *pNext = m_unkC->m_unk4;
        if (pNext != 0) {
            m_unkC = pNext;
            return m_unkC->m_unk0;
        }
        return 0;
    }

    int m_unk0;             // 0x00 node count (muNumNodes in the assert text)
    PListNode *m_unk4;      // 0x04 head node, cleared by RemoveAll
    PListNode *m_unk8;      // 0x08 tail node, cleared by RemoveAll
    PListNode *m_unkC;      // 0x0C current node (mpCur in the assert text)
};

#endif
