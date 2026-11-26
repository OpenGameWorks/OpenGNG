// FLAGS: -str readonly
#include "TimerAPI.h"

// TODO(header): foreign declarations
extern "C" void __ct__5PListFv(void *pThis);
extern "C" void RemoveCurrent__5PListFv(void *pThis);
extern "C" void Add__5PListFPv(void *pThis, void *pItem);
extern "C" void InsertBefore__5PListFPv(void *pThis, void *pItem);
extern "C" void CallOnTimerEvent__13EntityManagerFUiUi(void *pThis, unsigned int nId, unsigned int nSeq);
extern "C" void __dl__FPv(void *p);
extern "C" void *__nw__FUi(unsigned int nSize);
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern char gEng[105360];
extern unsigned char MODE_PAL;
extern float GAME_FPS;
extern EntityManager *mpEntMgr__15EntityBaseClass;

// FUNCTION: 0x00158790 KillAllApparitionTimers__8TimerAPIFUib
void TimerAPI::KillAllApparitionTimers(unsigned int nId, bool bFlag) {
    m_unk10 = m_unk8;
    TimerNode *pNode = m_unk8 ? (TimerNode *)m_unk8->pData : 0;
    while (pNode != 0) {
        unsigned int nNodeId = pNode->nId;
        if (nNodeId == nId) {
            if (bFlag) {
                CallOnTimerEvent__13EntityManagerFUiUi(mpEntMgr__15EntityBaseClass, nNodeId, *(unsigned int *)((char *)pNode + 0xC));
            }
            __dl__FPv(pNode);
            RemoveCurrent__5PListFv((char *)this + 4);
        }
        if (m_unk10 == 0) {
            m_unk10 = m_unk8;
            pNode = m_unk8 ? (TimerNode *)m_unk8->pData : 0;
        } else {
            TimerLink *pNext = m_unk10->pNext;
            if (pNext != 0) {
                m_unk10 = pNext;
                pNode = (TimerNode *)m_unk10->pData;
            } else {
                pNode = 0;
            }
        }
    }
}

// DRAFT: 0x00158890 ProcessTimers__8TimerAPIFP13EntityManager
// note: 10 words differ; register map is this=s1 EM=s0 nNow=s2 vs original this=s2 EM=s1 nNow=s0; tried nNow/pNode/nId/nSeq declaration orders (14 to 36 words).
void TimerAPI::ProcessTimers(EntityManager *pEntityManager) {
    m_unk10 = m_unk8;
    TimerNode *pNode = m_unk8 ? (TimerNode *)m_unk8->pData : 0;
    unsigned int nNow = *(unsigned int *)(gEng + 0x19A80);
    while (pNode != 0 && (unsigned long long)nNow >= pNode->nTime) {
        unsigned int nId = pNode->nId;
        int nSeq = pNode->nSeq;
        __dl__FPv(pNode);
        RemoveCurrent__5PListFv((char *)this + 4);
        CallOnTimerEvent__13EntityManagerFUiUi(pEntityManager, nId, nSeq);
        m_unk10 = m_unk8;
        pNode = m_unk8 ? (TimerNode *)m_unk8->pData : 0;
    }
}

// FUNCTION: 0x00158960 KillTimer__8TimerAPIFUi
void TimerAPI::KillTimer(unsigned int nSeq) {
    m_unk10 = m_unk8;
    TimerNode *pNode = m_unk8 ? (TimerNode *)m_unk8->pData : 0;
    while (pNode != 0) {
        if (pNode->nSeq == nSeq) {
            __dl__FPv(pNode);
            RemoveCurrent__5PListFv((char *)this + 4);
            break;
        }
        if (m_unk10 == 0) {
            m_unk10 = m_unk8;
            pNode = m_unk8 ? (TimerNode *)m_unk8->pData : 0;
        } else {
            TimerLink *pNext = m_unk10->pNext;
            if (pNext != 0) {
                m_unk10 = pNext;
                pNode = (TimerNode *)m_unk10->pData;
            } else {
                pNode = 0;
            }
        }
    }
}

// DRAFT: 0x00158A30 CreateTimer__8TimerAPIFUiUib
// note: 49 words differ; FPS operand order fixed, but the 0x11C/0x124 loop-entry branches (orig: m_unk8 test jumps straight to exit, extra pCur beqz) and the 0xD8 addu operand order still differ; tried do-while guard, if-form cursor init (56), and addend swap (no change).
int TimerAPI::CreateTimer(unsigned int nId, unsigned int nTime, bool bPal) {
    TimerNode *pNode = (TimerNode *)__nw__FUi(0x10);
    if (pNode != 0) {
        pNode->nTime = 0;
        pNode->nId = 0;
        pNode->nSeq = 0;
    }
    if (pNode == 0) {
        CdsAssert("TimerAPI.cpp", 0x1D, "pNewTimer");
    }
    if (bPal) {
        unsigned int nScaled = nTime;
        if (MODE_PAL) {
            nScaled = (nTime * 6) / 5;
        }
        pNode->nTime = nScaled + *(unsigned int *)(gEng + 0x19A80);
    } else {
        pNode->nTime = (int)nTime * (int)GAME_FPS + *(unsigned int *)(gEng + 0x19A80);
    }
    pNode->nId = nId;
    int nSeq = m_unk0;
    m_unk0 = nSeq + 1;
    pNode->nSeq = nSeq;

    m_unk10 = m_unk8;
    TimerNode *pCur = m_unk8 ? (TimerNode *)m_unk8->pData : 0;
    int bInserted = 0;
    while (pCur != 0) {
        if (!(pCur->nTime < pNode->nTime)) {
            InsertBefore__5PListFPv((char *)this + 4, pNode);
            bInserted = 1;
            break;
        }
        if (m_unk10 == 0) {
            m_unk10 = m_unk8;
            pCur = m_unk8 ? (TimerNode *)m_unk8->pData : 0;
        } else {
            TimerLink *pNext = m_unk10->pNext;
            if (pNext != 0) {
                m_unk10 = pNext;
                pCur = (TimerNode *)m_unk10->pData;
            } else {
                pCur = 0;
            }
        }
    }
    if (!bInserted) {
        Add__5PListFPv((char *)this + 4, pNode);
    }
    return pNode->nSeq;
}

// FUNCTION: 0x00158C20 __ct__8TimerAPIFv
TimerAPI::TimerAPI() {
    __ct__5PListFv((char *)this + 4);
    m_unk0 = 1;
    m_unk18 = 0;
    m_unk20 = 0;
}
