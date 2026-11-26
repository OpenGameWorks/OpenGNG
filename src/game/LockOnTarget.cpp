// FLAGS: -str readonly
#include "types.h"
#include "LockOnTarget.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// FUNCTION: 0x001D3A30 __dt__12LockOnTargetFv
LockOnTarget::~LockOnTarget() {
}

// FUNCTION: 0x001D3A90 GetClassName__12LockOnTargetFv
const char *LockOnTarget::GetClassName() {
    return "LockOnTarget";
}

// FUNCTION: 0x001D3AA0 SetEditableVars__12LockOnTargetFPc
void LockOnTarget::SetEditableVars(char *) {
}

// FUNCTION: 0x001D3AB0 OnHitEvent__12LockOnTargetFP15EntityBaseClassiUiUi
int LockOnTarget::OnHitEvent(EntityBaseClass *, int, unsigned int, unsigned int) {
    return 0;
}

// FUNCTION: 0x001D3AC0 Execute__12LockOnTargetFv
void LockOnTarget::Execute() {
    switch (m_unk20) {
    case -1:
        EnableSleep(false, false);
        ((char *)this)[0x179] = 0;
        m_unk163 = 1;
        SetState(0);
        /* fallthrough */
    case 0:
        if (m_unk1B0 != 0) {
            m_unk190 = *(u_long128 *)((char *)m_unk1B0 + 0x70);
        }
        return;
    }
}

// FUNCTION: 0x001D3B40 __ct__12LockOnTargetFv
LockOnTarget::LockOnTarget() : EntityBaseClass((LoadClass)3, 1) {
    m_unk1B0 = 0;
}
