#include "types.h"
#include "Bridge.h"
#include "EntityBaseClass.h"
#include "Physics.h"
#include "PMNode.h"
#include "PMeshNode.h"
#include "PLightManager.h"

// TODO(header): foreign declarations
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int eLoadClass, unsigned int nFlags);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" int Render__15EntityBaseClassFP13PLightManager(void *pThis, PLightManager *pLights);
extern "C" void __dl__FPv(void *);
extern unsigned char __vt__6Bridge[];

// Placeholder for the object at Bridge+0x3C: only the three words copied by Render are placed.
class BridgeSource {
public:
    char _pad000[0x70];
    float m_unk70;
    float m_unk74;
    float m_unk78;
};

// Placeholder for the object at Bridge+0x34C: slot 0x08 is Release, slot 0x0C is Render.
class BridgeView {
public:
    virtual void Release(int nFlag);
    virtual int Render(PLightManager *pLights, unsigned int nFlags, int nArg);
    char _pad004[0x6C];
    float m_unk70;
    float m_unk74;
    float m_unk78;
};

// DRAFT: 0x001DC760 IsEntityOnNode__6BridgeFP15EntityBaseClassP9PMeshNode
// note: size 0x50 vs 0x58; original tests Find's result with bnez into a return-s0 block and shares one return-0 b. Tried ternary (16 words), early returns (13), result variable (22); nested if is best (12).
PMNode *Bridge::IsEntityOnNode(EntityBaseClass *arg0, PMeshNode *arg1) {
    Physics *v = arg0->m_unk38;
    if (v) {
        PMNode *s0 = (PMNode *)v->m_unkCC;
        if (s0) {
            if (((PMNode *)arg1)->Find(s0)) {
                return s0;
            }
        }
    }
    return 0;
}

// FUNCTION: 0x001DC7C0 Render__6BridgeFP13PLightManager
int Bridge::Render(PLightManager *arg0) {
    int s0 = Render__15EntityBaseClassFP13PLightManager(this, arg0);
    m_unk34C->m_unk70 = m_unk3C->m_unk70;
    m_unk34C->m_unk74 = m_unk3C->m_unk74;
    m_unk34C->m_unk78 = m_unk3C->m_unk78;
    s0 += m_unk34C->Render(arg0, 0x80, 0);
    return s0;
}

// DRAFT: 0x001DD830 Clamp__6BridgeFRf
// note: original stores arg0 once and reloads it at 0x85C; ours forwards the value (15 words vs 0x54 size). Tried store/reload, volatile pointer reload (18), second compare on arg0 (15 best).
void Bridge::Clamp(float &arg0) {
    float v = arg0;
    if (v > 1.0f) {
        v = 1.0f;
    }
    arg0 = v;
    if (!(arg0 >= -1.0f)) {
        arg0 = -1.0f;
    }
    v = arg0;
    arg0 = v;
}

// FUNCTION: 0x001DDF70 __dt__6BridgeFv
Bridge::~Bridge() {
    m_unk0 = __vt__6Bridge;
    if (m_unk34C) {
        BridgeView *p = m_unk34C;
        if (p) {
            p->Release(1);
        }
        m_unk34C = 0;
    }
    __dt__15EntityBaseClassFv(this, 0);
}

// FUNCTION: 0x001DE000 __ct__6BridgeFv
Bridge::Bridge() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 2, 0);
    m_unk0 = __vt__6Bridge;
    m_unk34C = 0;
}
