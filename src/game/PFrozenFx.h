#ifndef PFROZENFX_H
#define PFROZENFX_H

#include "types.h"
#include "PParticleSystem.h"

class PMNode;

// Frozen-effect particle system. The PParticleSystem base occupies the first
// 0xE0 bytes; the members below start at 0xE0. The vtable (__vt__9PFrozenFx)
// is stored by the constructor and destructor, not by a C++ virtual.
class PFrozenFx : public PParticleSystem {
public:
    PFrozenFx();
    int Create(PMNode *pNode, float *pVec, float fA, float fB, float fC);
    void Start();
    void Stop();
    void FadeAndDie(unsigned int nFlag);
    void UpdateFxInstances();
    void UpdateMeshInstances();
    void GetValidNodes(PMNode *pNode, PMNode **ppOut);
    void Animate(float fArg);
    void Render();

    char m_unkE0[0x100];        // 0x0E0 cleared by the constructor (memset)
    void *m_unk1E0;             // 0x1E0 freed with __dla__ by the destructor
    int m_unk1E4;               // 0x1E4 cleared by Start and Stop
    int m_unk1E8;               // 0x1E8
    void *m_unk1EC;             // 0x1EC shader and fx-instance list, tested by Render
    void *m_unk1F0;             // 0x1F0 child object; its vtable slots 0x20 and 0x1C are called
    void *m_unk1F4;             // 0x1F4 freed with __dla__ by the destructor
    int m_unk1F8;               // 0x1F8
    float m_unk1FC;             // 0x1FC
    float m_unk200;             // 0x200
    int m_unk204;               // 0x204 copied to m_unkD0 by Animate
};

#endif
