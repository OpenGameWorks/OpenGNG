#ifndef EFFECTAPI_H
#define EFFECTAPI_H

#include "types.h"

class EntityBaseClass;
class EffectNode;
class GhostEffect;
class PLightManager;
class PMeshNode;
class PlingEffect;
class PMat4;

// EffectAPI derives from PArray at offset 0; the base is not declared here,
// so the constructor reaches it through the .cpp foreign declarations.
class EffectAPI {
public:
    EffectAPI();
    EffectNode *FindPling(EntityBaseClass *arg0);
    void CreatePling(EntityBaseClass *arg0, float arg1, unsigned int arg2, unsigned int arg3, bool arg4);
    PlingEffect *CreatePling(EntityBaseClass *arg0, float (*arg1)[4], unsigned int arg2, unsigned int arg3, bool arg4);
    GhostEffect *CreateGhost(PMeshNode *arg0);
    int CreateOneshot(unsigned int arg0, unsigned int arg1, PMat4 *arg2, EntityBaseClass *arg3, float arg4, int arg5, bool arg6);
    int CreateOneshot(unsigned int arg0, unsigned int arg1, float (*arg2)[4], float (*arg3)[4], EntityBaseClass *arg4, float arg5, bool arg6, int arg7, bool arg8);
    EffectNode *EffectValid(unsigned int arg0);
    void DeleteEffect(EffectNode *arg0);
    void DeleteEffect(EntityBaseClass *arg0);
    void DeleteEffect(unsigned int arg0);
    int Render(PLightManager *arg0);
    void Reset();
    void Animate(float arg0);
    void EnableParticleFx(bool arg0);

    unsigned int m_unk0;        // 0x000 effect count (PArray base region)
    unsigned int m_unk4;        // 0x004 scan index used by EffectValid
    EffectNode **m_ppEntries;   // 0x008 entry array
    char _pad00C[4];
    int m_unk10;                // 0x010 next effect id
};

class EffectNode {
public:
    virtual ~EffectNode();
    void SendDeleteEvent(int arg0);
    int Update(float arg0);
    int Render(PLightManager *arg0);

    int m_unk4;                 // 0x004 object whose virtual slot 3 draws the node
    int m_unk8;                 // 0x008 argument forwarded to SendDeleteEvent
    unsigned char m_unkC;       // 0x00C flag; gates the light pointer in Render
};

class PlingEffect : public EffectNode {
public:
    virtual ~PlingEffect();

    char _pad010[4];
    int m_unk14;                // 0x014 cleared when an existing pling is reused
};

class GhostEffect : public EffectNode {
public:
    GhostEffect(PMeshNode *arg0);
    virtual ~GhostEffect();
    int Render(PLightManager *arg0);

    u_long128 m_unk10[8];       // 0x010 per-slot matrix rows (world translation in row 3)
    unsigned char m_unk90;      // 0x090 first slot visibility flag
    char _pad091[7];
    void *m_unk98;              // 0x098 PMesh pointer
    short m_unk9C;              // 0x09C slot count
    char _pad09E[1];
    unsigned char m_unk9F;      // 0x09F wrap flag
};

class OneshotEffect : public EffectNode {
public:
    virtual ~OneshotEffect();
    int Update(float arg0);

    int m_unk10;                // 0x010
    char _pad014[4];
    unsigned int m_unk18;       // 0x018
    unsigned char m_unk1C;      // 0x01C
};

#endif
