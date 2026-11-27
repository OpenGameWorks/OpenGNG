// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "MineableItem.h"

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert("MineableItem.cpp", line, #cond))
#define CDS_ASSERT_TEXT(line, cond, text) ((cond) ? (void)0 : CdsAssert("MineableItem.cpp", line, text))
#define MIT_ENTRY(off) ((unsigned char *)&MineableItemTable[off] + m_unk1B0 * 24)

// TODO(header): foreign declarations
extern unsigned char __vt__12MineableItem[];
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
extern "C" void __dl__FPv(void *pMem);
extern "C" void CheckVariable__15EntityBaseClassFii(void *pThis, int nIndex, int nValue);
extern "C" void WriteApparitionData__15EntityBaseClassFicUi(void *pThis, int nIndex, char cType, unsigned int nData);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bFlag0, bool bFlag1);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__ct__7PhysicsFv(void *pThis);
extern "C" void SetPhysicsType__7PhysicsFUiPA4_f(void *pThis, unsigned int nType, float (*pMatrix)[4]);
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *pThis, unsigned int *pSequence);
extern "C" void UpdateShadowVolume__15EntityBaseClassFv(void *pThis);
extern "C" void SpawnPickups__15EntityBaseClassFiiPA4_fb(void *pThis, int nArg0, int nArg1, float (*pVelocity)[4], bool bFlag);
extern "C" void CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(void *pThis, unsigned int nA, unsigned int nB, float (*pC)[4], float (*pD)[4], void *pOwner, float fScale, bool bFlagA, int nCount, bool bFlagB);
extern "C" int RandomIntRange__7MathAPIFii(int nMin, int nMax);
extern unsigned char MineableItemTable[72];
extern float TreasureVelocity[4][4];
extern unsigned char mEffectAPI__13EntityManager[20];

// Shape of the object at m_unk3C: virtual slot 0x10 is the third virtual (dtor takes slot 0x08).
class MineableItemTarget {
public:
    virtual ~MineableItemTarget();
    virtual void Slot1();
    virtual void Slot2(float fValue);

    char _pad04[0x2C - 0x04];
    float m_unk2C;
    char _pad30[0x108 - 0x30];
    int m_unk108;
};

// FUNCTION: 0x001B42E0 __dt__12MineableItemFv
extern "C" MineableItem *__dt__12MineableItemFv(MineableItem *pThis, short nFlag)
{
    if (pThis != 0) {
        pThis->m_unk0 = __vt__12MineableItem;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001B4340 GetClassName__12MineableItemFv
const char *MineableItem::GetClassName() {
    return "MineableItem";
}

// FUNCTION: 0x001B4350 GetTallyType__12MineableItemFv
int MineableItem::GetTallyType() {
    return 2;
}

// FUNCTION: 0x001B4360 SetEditableVars__12MineableItemFPc
void MineableItem::SetEditableVars(char *arg0)
{
    memcpy(&m_unk1B0, arg0, 0x10);
    CheckVariable__15EntityBaseClassFii(this, m_unk1B0, 1);
    m_unk10C |= 0x02000000;
    m_unk103 = 0xFF;
    if (m_unk1B8 != 0) {
        m_unk1BC = 0;
    }
}

// FUNCTION: 0x001B43D0 OnHitEvent__12MineableItemFP15EntityBaseClassiUiUi
int MineableItem::OnHitEvent(EntityBaseClass *arg0, int arg1, unsigned int arg2, unsigned int arg3)
{
    if (arg1 == 0) {
        return 0;
    }
    if (*((unsigned char *)arg0 + 0x10C) == 1) {
        if ((arg2 & ~0x5C0) == 2 || m_unk1C0 >= 3) {
            WriteApparitionData__15EntityBaseClassFicUi(this, 0, 2, 0);
            WriteApparitionData__15EntityBaseClassFicUi(this, 1, -3, 0);
            SetState__15EntityBaseClassFi(this, 3);
            EnableSleep__15EntityBaseClassFbb(this, 0, 0);
            m_unk10C &= 0xFDFFFFFF;
        } else {
            SetState__15EntityBaseClassFi(this, 1);
        }
        m_unk1C8 = arg2;
    }
    return 1;
}

// DRAFT: 0x001B44B0 Execute__12MineableItemFv
// note: DIFF 224 words, size 0x544 vs 0x57C; jump-table base and MIT_ENTRY folding, the 0x18 default branch and the 0x2B0 assert block differ; tried compare chain, jump table, m_unk1C0 if/switch forms, macro variants.
void MineableItem::Execute()
{
    int nRandom;

    switch (m_unk20) {
    case -1:
        if (m_unk1B8 != 0) {
            if (m_unk38 == 0) {
                void *pPhysics = __nw__FUi(0x120);
                if (pPhysics != 0) {
                    pPhysics = __ct__7PhysicsFv(pPhysics);
                }
                m_unk38 = pPhysics;
                CDS_ASSERT_TEXT(0xA5, m_unk38, "mpPhysics");
            }
            SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x40, (float (*)[4])((char *)this + 0x190));
        }
        if (m_unk1C0 != 0) {
            SetState__15EntityBaseClassFi(this, 2);
            switch (m_unk1C0) {
            case 1:
                PlaySequence__15EntityBaseClassFPUi(this, *(unsigned int **)MIT_ENTRY(4));
                break;
            case 2:
                PlaySequence__15EntityBaseClassFPUi(this, *(unsigned int **)MIT_ENTRY(8));
                break;
            case 3:
                PlaySequence__15EntityBaseClassFPUi(this, *(unsigned int **)MIT_ENTRY(0xC));
                break;
            default:
                SetState__15EntityBaseClassFi(this, -2);
                break;
            }
            ((MineableItemTarget *)m_unk3C)->Slot2((float)((MineableItemTarget *)m_unk3C)->m_unk108);
        } else {
            SetState__15EntityBaseClassFi(this, 0);
        }
        break;
    case 0:
        if (m_unkE9 != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, *(unsigned int **)MIT_ENTRY(0));
        }
        if (m_unk1BC != 0) {
            UpdateShadowVolume__15EntityBaseClassFv(this);
        }
        break;
    case 1:
        if (m_unkE9 != 0) {
            if (m_unk1C0 == 2) {
                PlaySequence__15EntityBaseClassFPUi(this, *(unsigned int **)MIT_ENTRY(0xC));
            } else if (m_unk1C0 == 1) {
                PlaySequence__15EntityBaseClassFPUi(this, *(unsigned int **)MIT_ENTRY(8));
            } else if (m_unk1C0 == 0) {
                PlaySequence__15EntityBaseClassFPUi(this, *(unsigned int **)MIT_ENTRY(4));
            } else {
                CDS_ASSERT(0xEB, false);
            }
            m_unk1C4 = 1;
            m_unk1C0++;
            SpawnPickups__15EntityBaseClassFiiPA4_fb(this, 0, 1, TreasureVelocity, true);
            if (m_unk1B0 == 0) {
                CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(
                    mEffectAPI__13EntityManager, 0x0100013D, 0x02000290, 0, 0, this, 0.5f, false, 0, false);
            }
        }
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, 2);
        }
        break;
    case 3:
        if (m_unkE9 != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, *(unsigned int **)MIT_ENTRY(0x10));
            if ((m_unk1C8 & ~0x5C0) == 2) {
                SpawnPickups__15EntityBaseClassFiiPA4_fb(this, 0, m_unk1B4 + 3 - m_unk1C0, TreasureVelocity, true);
            } else {
                nRandom = RandomIntRange__7MathAPIFii(1, 100);
                if (nRandom < 11) {
                    SpawnPickups__15EntityBaseClassFiiPA4_fb(this, 0, 1, TreasureVelocity, true);
                } else if (nRandom < 36) {
                    SpawnPickups__15EntityBaseClassFiiPA4_fb(this, 0, 2, TreasureVelocity, true);
                } else if (nRandom < 71) {
                    SpawnPickups__15EntityBaseClassFiiPA4_fb(this, 0, 4, TreasureVelocity, true);
                } else if (nRandom < 96) {
                    SpawnPickups__15EntityBaseClassFiiPA4_fb(this, 1, 1, TreasureVelocity, false);
                } else {
                    SpawnPickups__15EntityBaseClassFiiPA4_fb(this, 10, 1, TreasureVelocity, false);
                }
            }
        }
        if (m_unk160 == 0) {
            int nState = 4;
            if (*(unsigned char *)MIT_ENTRY(0x14) == 0) {
                nState = -2;
            }
            SetState__15EntityBaseClassFi(this, nState);
        }
        break;
    case 4:
        if (m_unk3C != 0) {
            float fValue = ((MineableItemTarget *)m_unk3C)->m_unk2C;
            if (fValue <= 0.0f) {
                SetState__15EntityBaseClassFi(this, -2);
            } else {
                ((MineableItemTarget *)m_unk3C)->m_unk2C = fValue - 0.01f;
            }
        }
        break;
    case -2:
    case 2:
    default:
        break;
    }
}

// FUNCTION: 0x001B4A30 __ct__12MineableItemFv
extern "C" MineableItem *__ct__12MineableItemFv(MineableItem *pThis)
{
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(pThis, 2, 0);
    pThis->m_unk0 = __vt__12MineableItem;
    pThis->m_unk1C0 = 0;
    pThis->m_unk1C4 = 0;
    return pThis;
}
