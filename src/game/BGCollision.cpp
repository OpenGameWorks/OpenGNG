// FLAGS: -sdatathreshold 0
#include "BGCollision.h"

// TODO(header): foreign declarations
extern "C" void *__ct__6PArrayFv(void *);
extern "C" void Allocate__6PArrayFUi(void *, unsigned int);
extern "C" void __dl__FPv(void *);
extern float vUp_1253[4];

// DRAFT: 0x0016C8A0 CheckCeiling__11BGCollisionFPA4_f
// note: only the two lui/addiu words differ; the reloc target is vUp$1253, which C++ cannot name (vUp_1253 emitted).
int BGCollision::CheckCeiling(float (*pVec)[4])
{
    return CheckIntersectAnim(pVec, &vUp_1253, 0, 0x40) != 0;
}

// FUNCTION: 0x00170910 BoxLineCheck__FPA2_A4_f
int BoxLineCheck(float (*pBox)[2][4])
{
    asm {
        .set noreorder
        lqc2 vf3, 0x0(a0)
        lqc2 vf8, 0x10(a0)
        vmove.xyzw vf4, vf27
        lui v0, 0x3F00
        qmtc2.ni v0, vf1
        vmulx.xyz vf4, vf4, vf1x
        vadd.xyz vf1, vf4, vf26
        vsub.xyz vf1, vf1, vf3
        vabs.xyz vf2, vf1
        vabs.xyz vf9, vf4
        vadd.xyz vf9, vf9, vf8
        vsub.xyz vf9, vf9, vf2
        qmfc2.ni t0, vf9
        pcgtw t0, zero, t0
        bnez t0, box_ret
        addi v0, zero, 0x0
        prot3w t0, t0
        bnez t0, box_ret
        vsub.xyz vf3, vf26, vf3
        vopmula.xyz ACC, vf4, vf3
        vopmsub.xyz vf3, vf3, vf4
        vabs.xyz vf6, vf4
        vabs.xyz vf7, vf3
        vopmula.xyz ACC, vf8, vf6
        vsub.xyz vf9, vf0, vf6
        vopmsub.xyz vf6, vf9, vf8
        vsub.xyz vf9, vf7, vf6
        qmfc2.ni t0, vf9
        pcgtw v0, zero, t0
        bnez v0, box_ret
        nop
        prot3w v0, v0
    box_ret:
        jr ra
        nop
    }
}

// FUNCTION: 0x001709A0 GetGroundPos__11BGCollisionFPA4_f
int BGCollision::GetGroundPos(float (*pPos)[4])
{
    float from[4];
    float to[4];

    pPos[0][3] = 1.0f;
    *(u_long128 *)to = *(u_long128 *)pPos[0];
    to[1] -= 100.0f;
    *(u_long128 *)from = *(u_long128 *)pPos[0];
    if (FindIntersect((PVec3 &)from, (PVec3 &)to, 0x40, 0) != 0) {
        *(u_long128 *)pPos[0] = *(u_long128 *)to;
        return 1;
    }
    return 0;
}

// FUNCTION: 0x00170DD0 Destroy__11BGCollisionFv
void BGCollision::Destroy()
{
    void *p = m_unk4C;
    if (p != 0) {
        __dl__FPv(p);
        m_unk4C = 0;
        m_unk40 = 0;
    }
    if (m_unk78 != 0) {
        m_unk70 = 0;
        m_unk74 = 0;
    }
}

// DRAFT: 0x00170E20 __ct__11BGCollisionFv
// note: 18 words differ; original spills this to 0x1C(sp) and reloads it per store, stores m_unk44 before Allocate, and uses no s0.
BGCollision::BGCollision()
{
    __ct__6PArrayFv(&m_unk70);
    m_unk4C = 0;
    m_unk40 = 0;
    m_unk44 = 0;
    Allocate__6PArrayFUi(&m_unk70, 0x80);
}
