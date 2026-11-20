#include "types.h"
#include "SpitterItem.h"
#include "EntityBaseClass.h"
#include "Physics.h"
#include "MathAPI.h"

// TODO(header): foreign declarations
extern "C" void sceVu0Normalize(float *, float *);
extern "C" void sceVu0ScaleVector(float *, float *, float);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int eLoadClass, unsigned int nFlags);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" Physics *__ct__7PhysicsFv(Physics *pThis);
extern "C" void CdsAssert__FPciPc(const char *pFile, int nLine, const char *pExpr);
extern "C" float *GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc(void *pThis, struct tagWaypointGroup *pGroup, unsigned int nIndex, unsigned char &rbFlag);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern void *mpEntMgr__15EntityBaseClass;
extern unsigned char __vt__11SpitterItem[];

// FUNCTION: 0x001D9450 __dt__11SpitterItemFv
extern "C" SpitterItem *__dt__11SpitterItemFv(SpitterItem *pThis, short nFlag) {
    if (pThis != 0) {
        pThis->m_unk0 = __vt__11SpitterItem;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001D94C0 SpitterItemBounceOff__11SpitterItemFv
void SpitterItem::SpitterItemBounceOff() {
    u_long128 sp20 = *(u_long128 *)m_unk38;
    if (MathAPI::RandomIntRange(1, 100) & 1) {
        MathAPI::VectorRotateY((float (*)[4])&sp20, MathAPI::RandomFloatRange(30.0f, 40.0f));
    } else {
        MathAPI::VectorRotateY((float (*)[4])&sp20, MathAPI::RandomFloatRange(-30.0f, -40.0f));
    }
    sceVu0Normalize((float *)&sp20, (float *)&sp20);
    sceVu0ScaleVector((float *)&sp20, (float *)&sp20, m_unk200);
    *(u_long128 *)m_unk38 = sp20;
    m_unk1B4 = 0xB4;
    m_unk1BC = 1;
    m_unk38->m_unk10C = 0;
    SetState__15EntityBaseClassFi(this, 3);
}

// FUNCTION: 0x001D95A0 GetNextPosition__11SpitterItemFRA4_f
int SpitterItem::GetNextPosition(float (&rOut)[4]) {
    if (m_unk204 != 0) {
        if (m_unk1E4 < *(unsigned int *)((char *)m_unk204 + 4)) {
            unsigned char bFlag;
            float *pPoint = GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc((char *)mpEntMgr__15EntityBaseClass + 0x30, m_unk204, m_unk1E4, bFlag);
            rOut[0] = pPoint[0];
            rOut[1] = pPoint[1];
            rOut[2] = pPoint[2];
            m_unk1E4 = m_unk1E4 + 1;
            return 1;
        }
    }
    return 0;
}

// FUNCTION: 0x001D9640 OnHitEvent__11SpitterItemFP15EntityBaseClassiUiUi
void SpitterItem::OnHitEvent(EntityBaseClass *pArg, int nType, unsigned int nA, unsigned int nB) {
    if (((unsigned char *)pArg)[0x10C] == 1) {
        if (m_unk1B8 == 2) {
            if (m_unk20 != 3) {
                SpitterItemBounceOff();
                m_unk10C &= 0xF8FFFFFF;
            }
        }
    }
}

// FUNCTION: 0x001D96B0 OnAttackEvent__11SpitterItemFP15EntityBaseClassi
void SpitterItem::OnAttackEvent(EntityBaseClass *pArg, int nType) {
    if (((unsigned char *)pArg)[0x10C] == 1) {
        if (m_unk1B8 == 2) {
            if (m_unk20 != 3) {
                SpitterItemBounceOff();
                m_unk10C &= 0xF8FFFFFF;
            } else {
                m_unk10C &= 0xF8FFFFFF;
            }
        } else {
            struct {
                int a;
                int b;
                int c;
            } local;
            local.a = 0;
            local.b = 0;
            local.c = 0;
            *(u_long128 *)m_unk38 = *(u_long128 *)&local;
            SetState__15EntityBaseClassFi(this, 1);
        }
    }
}

// FUNCTION: 0x001D9F00 __ct__11SpitterItemFv
SpitterItem::SpitterItem() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 3, 1);
    m_unk0 = __vt__11SpitterItem;
    Physics *pPhysics = (Physics *)__nw__FUi(0x120);
    if (pPhysics != 0) {
        pPhysics = __ct__7PhysicsFv(pPhysics);
    }
    m_unk38 = pPhysics;
    if (m_unk38 == 0) {
        CdsAssert__FPciPc("SpitterItem.cpp", 0x4C, "mpPhysics");
    }
    m_unk1E0 = -1;
}
