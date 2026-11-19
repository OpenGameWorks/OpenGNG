#ifndef EFFECTAPI_H
#define EFFECTAPI_H

#include "types.h"

class EntityBaseClass;
class EffectNode;
class GhostEffect;
class PLightManager;
class PMeshNode;

// EffectAPI derives from PArray at offset 0; the base is not declared here,
// so the constructor reaches it through the .cpp foreign declarations.
class EffectAPI {
public:
    EffectAPI();
    void CreatePling(EntityBaseClass *arg0, float arg1, unsigned int arg2, unsigned int arg3, bool arg4);
    void CreatePling(EntityBaseClass *arg0, float (*arg1)[4], unsigned int arg2, unsigned int arg3, bool arg4);
    GhostEffect *CreateGhost(PMeshNode *arg0);
    EffectNode *EffectValid(unsigned int arg0);
    void DeleteEffect(EffectNode *arg0);
    void DeleteEffect(unsigned int arg0);
    int Render(PLightManager *arg0);
    void Reset();

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
};

class GhostEffect : public EffectNode {
public:
    virtual ~GhostEffect();
};

class OneshotEffect : public EffectNode {
public:
    virtual ~OneshotEffect();
};

#endif
