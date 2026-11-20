#ifndef PPARTICLEBUBBLES_H
#define PPARTICLEBUBBLES_H

#include "types.h"
#include "PParticleSystem.h"

// Eight bytes of padding with an empty destructor. Embedding it makes
// CodeWarrior keep 'this' in a stack slot in the constructor.
struct PBubblePad {
    char _pad[8];
    ~PBubblePad() {}
};

// Bubble emitter. The PParticleSystem base occupies the first 0xE0 bytes.
class PParticleBubbles : public PParticleSystem {
public:
    // One bubble, 0x30 bytes. The array at m_unk188 holds m_unk04 of them.
    struct tagBubble {
        float m_unk00;
        float m_unk04;
        float m_unk08;
        int m_unk0C;
        u_long128 m_unk10;
        float m_unk20;          // rise speed, multiplied by the frame delta
        float m_unk24;          // accumulated rise
        float m_unk28;          // remaining life
        int m_unk2C;
    };

    PParticleBubbles();
    void Animate(float fDelta);
    void SpawnBubble(tagBubble *pBubble);

    PBubblePad m_unkE0;         // 8 bytes; its destructor makes the constructor spill 'this'
    char _padE8[0x18];          // base ends at 0xE0 after 16-byte alignment
    int m_unk100;
    int m_unk104;
    int m_unk108;
    float m_unk10C;             // set to 1.0f by the constructor
    int m_unk110;
    int m_unk114;
    int m_unk118;
    float m_unk11C;             // set to 1.0f by the constructor
    char m_unk120[0x60];        // cleared by the constructor
    char _pad180[4];
    int m_unk184;               // cleared by the constructor
    tagBubble *m_unk188;        // bubble array, released by the destructor
    unsigned int m_unk18C;      // number of bubbles spawned so far
    int m_unk190;               // spawn countdown
};

#endif
