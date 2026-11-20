#include "types.h"
#include "Bridge.h"
#include "EntityBaseClass.h"
#include "Physics.h"
#include "PMNode.h"
#include "PMeshNode.h"
#include "PLightManager.h"
#include "MathAPI.h"

// TODO(header): foreign declarations
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int eLoadClass, unsigned int nFlags);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" int Render__15EntityBaseClassFP13PLightManager(void *pThis, PLightManager *pLights);
extern "C" void __dl__FPv(void *);
extern unsigned char __vt__6Bridge[];
extern "C" void Animate__6PMNodeFffP5PMat4ib(void *pThis, float fA, float fB, void *pMat, int nArg, bool bFlag);
extern float aAddHeight;
extern float aAddHeightStart;
extern void *mpResMgr__15EntityBaseClass;
extern unsigned int BridgeRopeName[9];
extern unsigned int BridgeName[9];
extern "C" void *GetResource__16PResourceManagerFUib(void *pThis, unsigned int nId, bool bFlag);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern float aBridgeHalfLength;
extern char *mPlayerAPI__13EntityManager;
extern "C" void sceVu0SubVector(float *dst, float *a, float *b);
extern "C" float FastMath_Fabs__Ff(float fValue);
extern "C" float sqrtf(float x);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(float (*arg0)[4], float (*arg1)[4]);

// Placeholder for the object at Bridge+0x3C: only the three words copied by Render are placed.
class BridgeSource {
public:
    char _pad000[0x70];
    float m_unk70;
    float m_unk74;
    float m_unk78;
};

// Placeholder for the object at Bridge+0x34C: slot 0x08 is Release, slot 0x0C is Render,
// slot 0x14 is CreateObjectDisplayList (virtual 3, as in the PMNode vtable).
class BridgeView {
public:
    virtual void Release(int nFlag);
    virtual int Render(PLightManager *pLights, unsigned int nFlags, int nArg);
    virtual void Unk10();
    virtual int CreateObjectDisplayList();
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

// FUNCTION: 0x001DC930 LoadBridgeRope__6BridgeFv
void Bridge::LoadBridgeRope() {
    if (m_unk1B0 == 1) {
        BridgeView *p = m_unk34C;
        if (p) {
            if (p) {
                p->Release(1);
            }
            m_unk34C = 0;
        }
        m_unk34C = (BridgeView *)GetResource__16PResourceManagerFUib(mpResMgr__15EntityBaseClass, 0x010002C4, 0);
        if (!m_unk34C) {
            CdsAssert__FPciPc("Bridge.cpp", 0x299, "m_pBridgeRope");
        }
    }
    u_long128 *src = m_unk3C ? (u_long128 *)((char *)m_unk3C + 0x80) : (u_long128 *)m_unk190;
    BridgeView *p = m_unk34C;
    *(u_long128 *)((char *)p + 0x80) = *src;
    ((PMNode *)p)->m_unk3E |= 8;
    if (m_unk1B0 == 1) {
        *(float *)((char *)m_unk34C + 0x84) += aAddHeightStart;
    }
    src = m_unk3C ? (u_long128 *)((char *)m_unk3C + 0x90) : (u_long128 *)m_unk1A0;
    p = m_unk34C;
    *(u_long128 *)((char *)p + 0x90) = *src;
    ((PMNode *)p)->m_unk3E |= 8;
    m_unk34C->CreateObjectDisplayList();
    Animate__6PMNodeFffP5PMat4ib(m_unk34C, 0.0f, 0.0f, 0, 0, false);
    for (int i = 0, off = 0; i < m_unk330; i++, off += 4) {
        *(void **)((char *)this + off + 0x350) = ((PMNode *)m_unk34C)->Find(*(unsigned int *)((char *)BridgeRopeName + off));
        *(float *)((char *)this + off + 0x374) = *(float *)((char *)*(void **)((char *)this + off + 0x350) + 0x84);
    }
}

// DRAFT: 0x001DCAD0 LoadBridgeParts__6BridgeFv
// note: 69 words differ; frame, saves and loop registers match. Remaining: branch layout of the ternaries (original beqz/b/nop placement), beqz offset 0x3F vs 0x3B, and the v[] load order (0x84,0x88,0x80 in original; reordering did not change the count).
void Bridge::LoadBridgeParts() {
    if (m_unk3C == 0) {
        CdsAssert__FPciPc("Bridge.cpp", 0x262, "GetMeshNode()");
    }
    m_unk330 = 9;
    int i = 1;
    int off = 4;
    int off2 = 0x20;
    do {
        *(void **)((char *)this + off + 0x1E0) = ((PMNode *)m_unk3C)->Find(*(unsigned int *)((char *)BridgeName + off - 4));
        if (*(void **)((char *)this + off + 0x1E0) != 0) {
            *(float *)((char *)this + off + 0x1BC) = *(float *)((char *)*(void **)((char *)this + off + 0x1E0) + 0x84);
            float v[4];
            v[0] = *(float *)((char *)*(void **)((char *)this + off + 0x1E0) + 0x80);
            v[1] = *(float *)((char *)*(void **)((char *)this + off + 0x1E0) + 0x84);
            v[2] = *(float *)((char *)*(void **)((char *)this + off + 0x1E0) + 0x88);
            float *pv = m_unk3C ? (float *)((char *)m_unk3C + 0x90) : m_unk1A0;
            MathAPI::VectorRotateY((float (*)[4])v, pv[1]);
            *(float *)((char *)this + off2 + 0x1F0) = v[0] + (m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190)[0];
            *(float *)((char *)this + off2 + 0x1F4) = v[1] + (m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190)[1];
            *(float *)((char *)this + off2 + 0x1F8) = v[2] + (m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190)[2];
            *(int *)((char *)this + off2 + 0x200) = 0;
            *(int *)((char *)this + off2 + 0x204) = 0;
            *(int *)((char *)this + off2 + 0x208) = 0;
            *(int *)((char *)this + off2 + 0x20C) = 0;
        } else {
            int t = i - 1;
            if (t < m_unk330) {
                m_unk330 = t;
            }
        }
        i += 1;
        off += 4;
        off2 += 0x20;
    } while (i < 10);
}

// DRAFT: 0x001DC850 UpdateBridgeRope__6BridgeFv
// note: 42 words differ; original ternary has nops at 0x34/0x3C (ours none), which shifts everything after; if-override form gives 46; split temp still 42; aAddHeight gp load is -0x7E38 in original vs 0 in ours.
void Bridge::UpdateBridgeRope() {
    for (int i = 0, off = 0; i < m_unk330; i++) {
        float *v = m_unk3C ? (float *)((char *)m_unk3C + 0x80) : (float *)((char *)this + 0x190);
        char *t = (char *)this + off;
        float f = *(float *)((char *)*(void **)(t + 0x1E4) + 0x84) + v[1] - *(float *)((char *)m_unk34C + 0x84);
        if (m_unk1B0 == 1) {
            *(float *)((char *)*(void **)(t + 0x350) + 0x84) = aAddHeight + (*(float *)(t + 0x374) + f);
        }
        off += 4;
    }
    Animate__6PMNodeFffP5PMat4ib(m_unk34C, 0.0f, 0.0f, 0, 0, false);
    ((PMNode *)m_unk34C)->m_unk3E |= 8;
}

// DRAFT: 0x001DCCA0 LeanOnSides__6BridgeFv
// note: 16 words differ: clamp compare sense (c.le.s/bc1t vs c.lt.s/bc1f), mul.s operand order at 0x17C, slt operand at 0x194, loop-body register and interleave (a0/a1). Tried: negated and reversed clamp ternary (118), swapped product operands (no change), flipped segment ternary (23 to 16).
void Bridge::LeanOnSides() {
    float vec[4];
    void *t = *(void **)((char *)mPlayerAPI__13EntityManager + 0x3C);
    float *a1 = t ? (float *)((char *)t + 0x80) : (float *)((char *)mPlayerAPI__13EntityManager + 0x190);
    int h = m_unk330 / 2;
    sceVu0SubVector(vec, a1, (float *)((char *)this + (h << 5) + 0x210));
    float *src = m_unk3C ? (float *)((char *)m_unk3C + 0x90) : (float *)((char *)this + 0x1A0);
    MathAPI::VectorRotateY((float (*)[4])vec, -src[1]);
    float f20 = vec[0];
    float d = (FastMath_Fabs__Ff(vec[2]) < 1.0f) ? 1.0f : FastMath_Fabs__Ff(vec[2]);
    float f21 = 40.0f / sqrtf(sqrtf(d)) / (float)(m_unk330 / 2);
    for (int i = 0, off = 0; i < m_unk330; i++, off += 4) {
        float f3 = (aBridgeHalfLength < FastMath_Fabs__Ff(f20)) ? aBridgeHalfLength : FastMath_Fabs__Ff(f20);
        if (f20 > 0.0f) {
            f3 = f3 * -1.0f;
        }
        float x = ((m_unk330 / 2) >= i) ? (float)i * f21 : f21 * (float)(m_unk330 - i);
        f3 = f3 * (x / aBridgeHalfLength);
        if (f3 < -180.0f) {
            f3 += 360.0f;
        } else if (f3 > 180.0f) {
            f3 -= 360.0f;
        }
        float tmp[4];
        void *node = *(void **)((char *)this + off + 0x1E4);
        tmp[0] = *(float *)((char *)node + 0x90);
        tmp[1] = *(float *)((char *)node + 0x94);
        tmp[2] = f3;
        *(u_long128 *)((char *)*(void **)((char *)this + off + 0x1E4) + 0x90) = *(u_long128 *)tmp;
        ((PMNode *)*(void **)((char *)this + off + 0x1E4))->m_unk3E |= 8;
    }
}

// DRAFT: 0x001DD400 PushPlank__6BridgeFiff
// note: first C attempt, not yet compared against the asm.
void Bridge::PushPlank(int arg0, float arg1, float arg2) {
    static float aFakeDistance;
    static char init583;
    static float aFakeDistanceDelta;
    static char init586;
    if (init583 == 0) {
        init583 = 1;
    }
    if (init586 == 0) {
        init586 = 1;
        aFakeDistanceDelta = 0.1f;
    }
    int s = arg0 << 5;
    char *pushed = (char *)this + s;
    float *seg = (float *)(pushed + 0x220);
    aFakeDistance = 1.0f - aFakeDistanceDelta;
    *seg = arg1;
    Clamp(*seg);
    *(float *)(pushed + 0x22C) = arg2;
    *(float *)(pushed + 0x228) = FastMath_Fabs__Ff(*seg / m_unk348);
    float f20 = Distance__7MathAPIFPA4_fPA4_f((float (*)[4])(pushed + 0x210), (float (*)[4])((char *)this + 0x210));
    for (int i = arg0 - 1; i >= 0; i--) {
        char *r = (char *)this + (i << 5);
        *(float *)(r + 0x22C) = 1.0f - Distance__7MathAPIFPA4_fPA4_f((float (*)[4])(pushed + 0x210), (float (*)[4])(r + 0x210)) / f20;
        float *v = (float *)(r + 0x220);
        if (FastMath_Fabs__Ff(*v) > FastMath_Fabs__Ff(arg1 * aFakeDistance)) {
            *v = -1.0f * FastMath_Fabs__Ff(*v);
        } else {
            *v = -1.0f * FastMath_Fabs__Ff(arg1 * aFakeDistance);
        }
        Clamp(*v);
        *(float *)(r + 0x228) = FastMath_Fabs__Ff(*v / m_unk348);
        aFakeDistance = aFakeDistance - aFakeDistanceDelta;
        aFakeDistance = (0.0f <= aFakeDistance) ? aFakeDistance : 0.0f;
    }
    aFakeDistance = 1.0f - aFakeDistanceDelta;
    float f20b = Distance__7MathAPIFPA4_fPA4_f((float (*)[4])(pushed + 0x210), (float (*)[4])((char *)this + ((m_unk330 - 1) << 5) + 0x210));
    for (int j = arg0 + 1; j < m_unk330; j++) {
        char *r = (char *)this + (j << 5);
        *(float *)(r + 0x22C) = 1.0f - Distance__7MathAPIFPA4_fPA4_f((float (*)[4])(pushed + 0x210), (float (*)[4])(r + 0x210)) / f20b;
        float *v = (float *)(r + 0x220);
        if (FastMath_Fabs__Ff(*v) > FastMath_Fabs__Ff(arg1 * aFakeDistance)) {
            *v = -1.0f * FastMath_Fabs__Ff(*v);
        } else {
            *v = -1.0f * FastMath_Fabs__Ff(arg1 * aFakeDistance);
        }
        Clamp(*v);
        *(float *)(r + 0x228) = FastMath_Fabs__Ff(*v / m_unk348);
        aFakeDistance = aFakeDistance - aFakeDistanceDelta;
        aFakeDistance = (0.0f <= aFakeDistance) ? aFakeDistance : 0.0f;
    }
    for (int k = 0, off = 0; k < m_unk330; k++, off += 0x20) {
        float *p = (float *)((char *)this + off + 0x220);
        if (m_unk330 / 2 >= k) {
            *p = *p * ((float)(k + 1) / (float)((m_unk330 + 1) / 2));
        } else {
            *p = *p * ((float)(m_unk330 - k) / (float)((m_unk330 + 1) / 2));
        }
    }
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

// FUNCTION: 0x001DD8A0 OnTimerEvent__6BridgeFUi
void Bridge::OnTimerEvent(unsigned int arg0) {
    if (arg0 == m_unk344) {
        m_unk344 = 0;
    }
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
