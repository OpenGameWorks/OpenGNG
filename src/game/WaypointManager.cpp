// FLAGS: -str readonly
#include "types.h"
#include "WaypointManager.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void __dl__FPv(void *pMem);

#define WAYPOINT_BUFFER_SIZE 0x5000
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("WaypointManager.cpp", line, #cond))

// DRAFT: 0x00155020 GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc
// note: 19 words; original loads m_unk4 before the word, computes the word address as addiu+addu+lw 0, and emits lui 0xF000 after the load, beqz is +0xD vs ours +0xC. Tried: bRef mask form (19), hoisted base (24), word pointer (19), pointer-first m_unk18 (19).
int WaypointManager::GetWaypoint(tagWaypointGroup *pGroup, unsigned int iWpNumber, unsigned char &bRef) {
    CDS_ASSERT(0x263, pGroup);
    CDS_ASSERT(0x264, iWpNumber < pGroup->iNWaypoints);
    if (m_unk0 != 0) {
        unsigned int *pWords = pGroup->m_unk18;
        unsigned int uWord = pWords[iWpNumber];
        bRef = (uWord & 0xF0000000) >> 28;
        return m_unk4 + (uWord & 0x0FFFFFFF);
    }
    return 0;
}

// FUNCTION: 0x001550E0 GetWaypointGroupInfo__15WaypointManagerFUi
tagWaypointGroup *WaypointManager::GetWaypointGroupInfo(unsigned int iGroupId) {
    if (m_unk0 != 0) {
        for (unsigned int i = 0; i < m_unk10; i++) {
            tagWaypointGroup *pGroup = (tagWaypointGroup *)(m_unk8 + *(int *)(m_unkC + i * 4));
            if (pGroup->m_unk0 == iGroupId) {
                return pGroup;
            }
        }
    }
    return 0;
}

// DRAFT: 0x00155150 LoadWaypoints__15WaypointManagerFP8PPakFileUi
// note: 21 words; original computes &m_unk20 then adds 0xC in two steps for m_unkC, ours folds to one addiu 0x2C; (char*)&m_unk20+0xC, a local base, and (unsigned int*)&m_unk20+3 all fold the same way.
int WaypointManager::LoadWaypoints(PPakFile *pPak, unsigned int uSizeWpBlock) {
    CDS_ASSERT(0x189, uSizeWpBlock < WAYPOINT_BUFFER_SIZE);
    if (pPak->Read(&m_unk20, uSizeWpBlock) == 0) {
        return 0;
    }
    m_unk10 = m_unk20;
    m_unk8 = (char *)this + m_unk24 + 0x20;
    m_unk4 = (int)(m_unk8 + m_unk28);
    m_unkC = m_unk2C;
    m_unk0 = 1;
    return 1;
}

// FUNCTION: 0x00155210 __dt__15WaypointManagerFv
WaypointManager::~WaypointManager() {}

// FUNCTION: 0x00155260 __ct__15WaypointManagerFv
WaypointManager::WaypointManager() {
    m_unk4 = 0;
    m_unk8 = 0;
    m_unkC = 0;
    m_unk0 = 0;
    m_unk10 = 0;
}
