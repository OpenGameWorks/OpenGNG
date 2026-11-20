#include "types.h"
#include "PParticleBubbles.h"

// TODO(header): foreign declarations
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dla__FPv(void *);
extern "C" void __dl__FPv(void *);
extern "C" void *memset(void *, int, unsigned int);
extern unsigned char __vt__16PParticleBubbles[];

// DRAFT: 0x002023A0 Animate__16PParticleBubblesFf
// note: DIFF 1 word, the fDelta != 0.0f float compare orders operands as c.eq.s $f0,$f20 where the original has $f20,$f0; the combined early return matches the rest. Tried: separate returns, nested if, if/else return, flat, operand swap.
void PParticleBubbles::Animate(float fDelta) {
    if (m_unk15 == 0 || m_unk16 != 0) {
        return;
    }
    if (m_unk18C < m_unk04 && 0.0f != fDelta) {
        m_unk190 -= 1;
        if (m_unk190 <= 0) {
            SpawnBubble(m_unk188 + m_unk18C);
            m_unk18C += 1;
            m_unk190 = 0x14;
        }
    }
    unsigned int nAlive = m_unk04;
    unsigned int i = 0;
    int offset = 0;
    while (i < m_unk04) {
        tagBubble *pBubble = (tagBubble *)((char *)m_unk188 + offset);
        pBubble->m_unk24 += fDelta * pBubble->m_unk20;
        float fLife = pBubble->m_unk28 - fDelta;
        pBubble->m_unk28 = fLife;
        if (fLife <= 0.0f && m_unk18 != 0) {
            nAlive -= 1;
            if ((int)nAlive <= 0) {
                m_unk16 = m_unk17;
            }
            if (m_unk18 != 0) {
                SpawnBubble(pBubble);
            } else {
                pBubble->m_unk24 = 0.0f;
            }
        }
        offset += 0x30;
        i += 1;
    }
}

// FUNCTION: 0x002027E0 __dt__16PParticleBubblesFv
extern "C" void *__dt__16PParticleBubblesFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PParticleBubbles *pSelf = (PParticleBubbles *)pThis;
        *(void **)pThis = __vt__16PParticleBubbles;
        pSelf->m_unk184 = 0;
        if (pSelf->m_unk188 != 0) {
            __dla__FPv(pSelf->m_unk188);
            pSelf->m_unk188 = 0;
        }
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x00202860 __ct__16PParticleBubblesFv
PParticleBubbles::PParticleBubbles() {
    *(void **)this = __vt__16PParticleBubbles;
    memset(m_unk120, 0, 0x60);
    m_unk184 = 0;
    m_unk188 = 0;
    m_unk118 = 0;
    m_unk114 = 0;
    m_unk110 = 0;
    m_unk11C = 1.0f;
    m_unk108 = 0;
    m_unk104 = 0;
    m_unk100 = 0;
    m_unk10C = 1.0f;
}
