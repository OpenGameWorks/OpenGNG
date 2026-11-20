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

    int m_unk0;             // 0x00 node count (muNumNodes in the assert text)
    PListNode *m_unk4;      // 0x04 head node, cleared by RemoveAll
    PListNode *m_unk8;      // 0x08 tail node, cleared by RemoveAll
    PListNode *m_unkC;      // 0x0C current node (mpCur in the assert text)
};

#endif
