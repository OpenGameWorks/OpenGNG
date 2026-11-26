#ifndef PPARTICLELITEEXPLOSION_H
#define PPARTICLELITEEXPLOSION_H

#include "types.h"
#include "PParticleSystem.h"

class PMat4;
class PFrustrum;

// Parameter block copied into the emitter by Create. The copy covers
// 0xB0 bytes starting at member offset 0xE0.
struct tagParticleLiteExplosionParams {
    char _pad000[0x70];
    unsigned int m_unk70;       // 0x070 copied to m_unk150
    char _pad074[0x08];
    float m_unk7C;              // 0x07C copied to m_unk15C
    char _pad080[0x10];
    float m_unk90;              // 0x090 copied to m_unk170
    char _pad094[0x1C];
};

// Lite explosion emitter. The PParticleSystem base occupies the first 0xE0
// bytes; the members below start at 0xE0.
class PParticleLiteExplosion : public PParticleSystem {
public:
    int Create(tagParticleLiteExplosionParams *pParams, float fA, float fB, float fC);
    void Start(float fScale);
    void Start();
    void ModifyPosition(PMat4 *pMat);
    void AnimateRotatableParticles(float fDt);

    void SetPosition(float *, float *);
    float m_unkE0[4];           // 0x0E0 position, offset by Create's fA/fB/fC
    float m_unkF0[4];           // 0x0F0 vector used by Create
    float m_unk100[4];          // 0x100 vector used by Create
    float m_unk110[4];          // 0x110 parameter block tail
    float m_unk120[4];          // 0x120
    float m_unk130[4];          // 0x130 vector read by AnimateRotatableParticles
    float m_unk140[4];          // 0x140 vector read by AnimateRotatableParticles
    unsigned int m_unk150;      // 0x150 copied from params 0x70
    float m_unk154;             // 0x154
    float m_unk158;             // 0x158
    float m_unk15C;             // 0x15C copied from params 0x7C
    float m_unk160;             // 0x160 scale set by Start(float)
    float m_unk164;             // 0x164 flag compared against zero by AnimateRotatableParticles
    float m_unk168;             // 0x168
    float m_unk16C;             // 0x16C scale read by AnimateRotatableParticles
    float m_unk170;             // 0x170 copied from params 0x90
    char _pad174[0x1C];
    float m_unk190;             // 0x190 computed by Create
    float m_unk194;             // 0x194 cleared by Start
    char _pad198[0x08];
    float m_unk1A0[4];          // 0x1A0 copy of m_unk1B0 made by Start
    float m_unk1B0[4];          // 0x1B0 copy of m_unkE0 made by Create
    int m_unk1C0;               // 0x1C0 computed by Start
};

// Virtual view of PParticleLiteExplosion. The emitter itself declares no
// virtuals, because a vptr in the derived class would shift the base data.
// Slot indices follow (offset - 8) / 4; Start is at slot 6 (offset 0x20).
class PParticleLiteExplosionView {
public:
    virtual void Slot00();
    virtual void Animate(float fDelta);
    virtual void Render();
    virtual void ModifyPosition(PMat4 *pMat);
    virtual void FrustrumTest(PFrustrum *pFrustrum, float *pVec, float fNear, float fFar);
    virtual void FadeAndDie(unsigned int nUnused);
    virtual void Start();
};

#endif
