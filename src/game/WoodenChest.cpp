#include "types.h"
#include "WoodenChest.h"

// TODO(header): foreign declarations
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int eLoadClass, unsigned int nFlags);
extern "C" void *ApparitionIsValid__15EntityBaseClassFUi(unsigned int nId);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bA, bool bB);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern unsigned char __vt__11WoodenChest[];

// FUNCTION: 0x001A1600 GetTallyType__11WoodenChestFv
int WoodenChest::GetTallyType()
{
    if (m_unk1CC != 0) {
        return 4;
    }
    return (m_unk1C8 == 2) ? 1 : 2;
}

// FUNCTION: 0x001A1640 SetDefaultVars__11WoodenChestFv
void WoodenChest::SetDefaultVars()
{
    m_unk1B0 = -1;
    m_unk1B4 = 0;
    m_unk1B8 = -1;
    m_unk1BC = 0;
    m_unk1C0 = -1;
    m_unk1C4 = 0;
    m_unk1C8 = 0;
    m_unk1CC = 0;
    m_unk1D0 = 10.0f;
    m_unk1D4 = 40.0f;
    m_unk1E0 = 150;
}

// FUNCTION: 0x001A1740 OnSleepEvent__11WoodenChestFv
void WoodenChest::OnSleepEvent()
{
    if (ApparitionIsValid__15EntityBaseClassFUi(m_unk210)) {
        EnableSleep__15EntityBaseClassFbb(ApparitionIsValid__15EntityBaseClassFUi(m_unk210), true, false);
    }
}

// FUNCTION: 0x001A1BB0 OnAttackEvent__11WoodenChestFP15EntityBaseClassi
void WoodenChest::OnAttackEvent(class EntityBaseClass *pEntity, int nEvent)
{
    if (*(int *)((char *)pEntity + 8) == 3 && m_unk20 == 7) {
        SetState__15EntityBaseClassFi(this, 12);
    }
}

// FUNCTION: 0x001A30B0 __ct__11WoodenChestFv
WoodenChest::WoodenChest()
{
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 1, 0U);
    m_unk0 = __vt__11WoodenChest;
    m_unk1EC = 0;
    m_unk210 = 0;
}
