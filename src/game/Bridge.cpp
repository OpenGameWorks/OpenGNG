// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "Bridge.h"
#include "EntityBaseClass.h"
#include "Physics.h"
#include "PMNode.h"
#include "PMeshNode.h"
#include "PLightManager.h"
#include "MathAPI.h"
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

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
extern float aBridgeHalfLength;
extern char *mPlayerAPI__13EntityManager;
extern "C" void sceVu0SubVector(float *dst, float *a, float *b);
extern "C" float FastMath_Fabs__Ff(float fValue);
extern "C" float sqrtf(float x);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(float (*arg0)[4], float (*arg1)[4]);
extern "C" float atanf(float x);
extern "C" void CheckVariable__15EntityBaseClassFii(void *pThis, int nVar, int nValue);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *pThis, unsigned int *pSeq);
extern "C" void PlaySound__15EntityBaseClassFUi(void *pThis, unsigned int nSound);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bA, bool bB);
extern "C" void *ApparitionIsValid__15EntityBaseClassFUi(unsigned int nId);
extern "C" void GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(void *pThis, int nClass, void *pArray, float (*pPos)[4], float fRadius, int nArg, bool bA, bool bB);
extern "C" float sceVu0InnerProduct(float *a, float *b);
extern "C" int CreateTimer__8TimerAPIFUiUib(void *pThis, unsigned int nId, unsigned int nTime, bool bPal);
extern "C" PMNode *IsPlayerOnNode__6PlayerFP9PMeshNodeb(void *pThis, PMeshNode *pMesh, bool bFlag);
extern "C" int printf(const char *fmt, ...);
extern "C" int RandomIntRange__7MathAPIFii(int nLo, int nHi);
extern void *BridgeTable[2];
extern void *mpEntMgr__15EntityBaseClass;
extern unsigned char mTempArray__15EntityBaseClass[0x249C];
extern unsigned char mTimerAPI__13EntityManager[40];
extern unsigned char gEng[105360];

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

// FUNCTION: 0x001DC750 GetClassName__6BridgeFv
const char *Bridge::GetClassName() {
    return "Bridge";
}

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
            CdsAssert("Bridge.cpp", 0x299, "m_pBridgeRope");
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
        CdsAssert("Bridge.cpp", 0x262, "GetMeshNode()");
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

// FUNCTION: 0x001DCCA0 LeanOnSides__6BridgeFv
void Bridge::LeanOnSides() {
    float vec[4];
    void *t = *(void **)((char *)mPlayerAPI__13EntityManager + 0x3C);
    float *a1 = t ? (float *)((char *)t + 0x80) : (float *)((char *)mPlayerAPI__13EntityManager + 0x190);
    int h = m_unk330 / 2;
    sceVu0SubVector(vec, a1, (float *)((char *)this + (h << 5) + 0x210));
    float *src = m_unk3C ? (float *)((char *)m_unk3C + 0x90) : (float *)((char *)this + 0x1A0);
    MathAPI::VectorRotateY((float (*)[4])vec, -src[1]);
    float f20 = vec[0];
    float d = (1.0f > FastMath_Fabs__Ff(vec[2])) ? 1.0f : FastMath_Fabs__Ff(vec[2]);
    float f21 = 40.0f / sqrtf(sqrtf(d)) / (float)(m_unk330 / 2);
    for (int i = 0, off = 0; i < m_unk330; off += 4, i++) {
        float f3 = (aBridgeHalfLength < FastMath_Fabs__Ff(f20)) ? aBridgeHalfLength : FastMath_Fabs__Ff(f20);
        if (f20 > 0.0f) {
            f3 *= -1.0f;
        }
        float x = (i <= (m_unk330 / 2)) ? (float)i * f21 : f21 * (float)(m_unk330 - i);
        f3 = f3 * (x / aBridgeHalfLength);
        if (f3 < -180.0f) {
            f3 += 360.0f;
        } else if (f3 > 180.0f) {
            f3 -= 360.0f;
        }
        float tmp[4];
        tmp[0] = *(float *)((char *)*(void **)((char *)this + off + 0x1E4) + 0x90);
        tmp[1] = *(float *)((char *)*(void **)((char *)this + off + 0x1E4) + 0x94);
        tmp[2] = f3;
        PMNode *pNode = (PMNode *)*(void **)((char *)this + off + 0x1E4);
        *(u_long128 *)((char *)pNode + 0x90) = *(u_long128 *)tmp;
        pNode->m_unk3E |= 8;
    }
}

// DRAFT: 0x001DCF40 RunPhysics__6BridgeFv
// note: 269 words; frame 0x120 vs 0x110; no PList cursor walk (index loop over m_unk1E4 with record stride 32); loop 1 keeps s0/s1 allocation not a1/s5/s6/s7; off/roff and else-closed variants gave 281, reverted.
void Bridge::RunPhysics() {
    int closed = 0;
    int i;
    int off;
    for (i = 0; i < m_unk330; i++) {
        float tmp[4];
        PMNode *node = (PMNode *)m_unk1E4[i];
        char *rec = (char *)this + (i << 5);
        tmp[0] = node->m_unk80[0];
        static float aDropDist = 1.5f;
        tmp[1] = m_unk1C0[i] + *(float *)(rec + 0x224) * aDropDist;
        tmp[2] = node->m_unk80[2];
        *(u_long128 *)((char *)node + 0x80) = *(u_long128 *)tmp;
        node->m_unk3E |= 8;
        if (*(float *)(rec + 0x228) == 0.0f) {
            closed++;
        } else {
            float d = FastMath_Fabs__Ff(*(float *)((char *)this + (m_unk334 << 5) + 0x224));
            float *m220 = (float *)(rec + 0x220);
            float *m224 = (float *)(rec + 0x224);
            float *m228 = (float *)(rec + 0x228);
            if (*m220 > *m224) {
                *m224 = *m224 + *m228 * (1.0f - d);
            } else {
                *m224 = *m224 - *m228 * (1.0f - d);
            }
            if (FastMath_Fabs__Ff(*m224 - *m220) < 1e-4f + *m228) {
                float tmp2[4];
                static float aTargetkill = 0.8f;
                *m220 = *m220 * aTargetkill;
                static float aTargetAccDieTol = 1e-5f;
                if (FastMath_Fabs__Ff(*m220) < aTargetAccDieTol) {
                    *m220 = 0.0f;
                    *m224 = 0.0f;
                    *m228 = 0.0f;
                    tmp2[0] = node->m_unk80[0];
                    tmp2[1] = m_unk1C0[i];
                    tmp2[2] = node->m_unk80[2];
                    *(u_long128 *)((char *)node + 0x80) = *(u_long128 *)tmp2;
                    node->m_unk3E |= 8;
                }
                *m220 = *m220 * -1.0f;
                *m228 = FastMath_Fabs__Ff(*m220 / m_unk348);
            }
        }
    }
    int flag = 0;
    if (closed == m_unk330) {
        m_unk340 = 0;
    }
    off = 0;
    for (i = 0; i < m_unk330; i++, off += 4) {
        char *p = (char *)this + off;
        if (i == m_unk330 / 2) {
            static float aNumFrames = 30.0f;
            float tmp3[4];
            PMNode *node = *(PMNode **)(p + 0x1E4);
            tmp3[0] = node->m_unk90[0];
            tmp3[1] = node->m_unk90[1];
            tmp3[2] = node->m_unk90[2] - node->m_unk90[2] / aNumFrames;
            *(u_long128 *)((char *)node + 0x90) = *(u_long128 *)tmp3;
            node->m_unk3E |= 8;
            flag = 1;
        } else {
            PMNode *node0 = *(PMNode **)(p + 0x1E4);
            PMNode *other = flag ? *(PMNode **)(p + 0x1E0) : *(PMNode **)(p + 0x1E8);
            float slope = -(node0->m_unk80[1] - other->m_unk80[1]) / (node0->m_unk80[2] - other->m_unk80[2]);
            if (FastMath_Fabs__Ff(slope) <= 1.0f) {
                float tmp4[4];
                float ang = atanf(slope) * 57.2957763671875f;
                if (ang < -180.0f) {
                    ang = ang + 360.0f;
                } else if (ang > 180.0f) {
                    ang = ang - 360.0f;
                }
                tmp4[0] = ang;
                tmp4[1] = node0->m_unk90[1];
                tmp4[2] = node0->m_unk90[2];
                *(u_long128 *)((char *)node0 + 0x90) = *(u_long128 *)tmp4;
                node0->m_unk3E |= 8;
            }
        }
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
// note: 9 words: original keeps v in f0 and 1.0f/-1.0f in f1, ours uses f1/f2 and one extra mov.s; volatile reload of arg0 in the second compare is the best form (store/reload, volatile first load, volatile pointer reload 18 all worse).
void Bridge::Clamp(float &arg0) {
    float v = arg0;
    if (1.0f < v) {
        v = 1.0f;
    }
    arg0 = v;
    if (!(-1.0f <= *(volatile float *)&arg0)) {
        v = -1.0f;
    }
    arg0 = v;
}

// FUNCTION: 0x001DD890 OnHitEvent__6BridgeFP15EntityBaseClassiUiUi
void Bridge::OnHitEvent(EntityBaseClass *, int, unsigned int, unsigned int) {
}

// FUNCTION: 0x001DD8A0 OnTimerEvent__6BridgeFUi
void Bridge::OnTimerEvent(unsigned int arg0) {
    if (arg0 == m_unk344) {
        m_unk344 = 0;
    }
}

// FUNCTION: 0x001DD8C0 OnTouchEvent__6BridgeFP15EntityBaseClass
void Bridge::OnTouchEvent(EntityBaseClass *) {
}

// FUNCTION: 0x001DD8D0 SetEditableVars__6BridgeFPc
void Bridge::SetEditableVars(char *pSrc) {
    memcpy((char *)this + 0x1B0, pSrc, 0x10);
}

// DRAFT: 0x001DD8E0 Execute__6BridgeFv
// note: 430 words differ; frame 0xB0 vs 0x80 (extra fp/s6/s7 saves, live block locals); mTempArray ternary-walk and block-scoped player pointer variants tried, no gain
void Bridge::Execute() {
    switch (m_unk20) {
    case -1:
        m_unk10C &= 0xF8FFFFFF;
        CheckVariable__15EntityBaseClassFii(this, m_unk1B0, 2);
        if (m_unk1B0 == 0) {
            printf("No more web bridge: Code optimized\n");
            SetState__15EntityBaseClassFi(this, -2);
            return;
        }
        PlaySequence__15EntityBaseClassFPUi(this, (unsigned int *)BridgeTable[m_unk1B0]);
        m_unk338 = 1;
        m_unk344 = 0;
        m_unk348 = 5.0f;
        m_unk33C = 10;
        LoadBridgeParts();
        LoadBridgeRope();
        m_unk334 = 1;
        PushPlank(0, -0.25f, 1.0f);
        m_unk340 = 1;
        SetState__15EntityBaseClassFi(this, 0);
        return;
    case 0: {
        float fDist;
        {
            float (*pPos)[4] = m_unk3C ? (float (*)[4])((char *)m_unk3C + 0x80) : &m_unk190;
            char *pApi = mPlayerAPI__13EntityManager;
            char *pApi3C = *(char **)(pApi + 0x3C);
            float (*pPlayer)[4] = pApi3C ? (float (*)[4])(pApi3C + 0x80) : (float (*)[4])(pApi + 0x190);
            fDist = Distance__7MathAPIFPA4_fPA4_f(pPlayer, pPos);
        }
        if (fDist > 50.0f) {
            EnableSleep__15EntityBaseClassFbb(this, true, false);
        } else if (m_unk1B != 0) {
            EnableSleep__15EntityBaseClassFbb(this, false, false);
        }
        if (m_unkE9 != 0) {
            RunPhysics();
            UpdateBridgeRope();
        }
        char *pSys = *(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C);
        float fLen = sqrtf(sceVu0InnerProduct(*(float **)(pSys + 0x38), *(float **)(pSys + 0x38)));
        unsigned char nState = (unsigned char)pSys[0x163];
        if (IsPlayerOnNode__6PlayerFP9PMeshNodeb(*(void **)((char *)gEng + 0x1883C), (PMeshNode *)m_unk3C, false) != 0) {
            if (fLen != 0.0f || nState == 2 || nState == 6) {
                m_unk334 = -1;
                float fMin = 3.4028235e38f;
                int nOff = 0;
                for (int i = 0; i < m_unk330; nOff += 0x20, i++) {
                    char *pApi2 = mPlayerAPI__13EntityManager;
                    char *pApi2_3C = *(char **)(pApi2 + 0x3C);
                    float (*pP)[4] = pApi2_3C ? (float (*)[4])(pApi2_3C + 0x80) : (float (*)[4])(pApi2 + 0x190);
                    float fD = Distance__7MathAPIFPA4_fPA4_f(pP, (float (*)[4])((char *)this + nOff + 0x210));
                    if (fD < fMin) {
                        fMin = fD;
                        m_unk334 = i;
                    }
                }
                int nIdx = m_unk334;
                if (nIdx == 0 || nIdx == m_unk330 - 1) {
                    int nNew = 1;
                    if (nIdx != 0) {
                        nNew = nIdx - 1;
                    }
                    m_unk334 = nNew;
                }
                char *pTimer = *(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C);
                if ((*(unsigned int *)(*(char **)(pTimer + 0x38) + 0x108) & 0x80) && m_unk344 == 0) {
                    static unsigned int aResetTimerFrame;
                    static char init;
                    if (init == 0) {
                        aResetTimerFrame = 0x1E;
                        init = 1;
                    }
                    m_unk344 = CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk4, aResetTimerFrame, true);
                    static float aWalkForce;
                    static char init2;
                    if (init2 == 0) {
                        aWalkForce = -0.25f;
                        init2 = 1;
                    }
                    PushPlank(m_unk334, aWalkForce, 1.0f);
                }
                if (m_unk338 == 1) {
                    m_unk338 = 0;
                    if (m_unk334 != -1 && m_unk1E4[0] != 0) {
                        PushPlank(m_unk334, -1.0f, 1.0f);
                    }
                }
                LeanOnSides();
                m_unk33C -= 1;
                if (m_unk33C < 0) {
                    PlaySound__15EntityBaseClassFUi(this, 0x4E58);
                    m_unk33C = RandomIntRange__7MathAPIFii(0xA, 0x78);
                }
                m_unk340 = 1;
            } else {
                m_unk338 = 1;
            }
        } else {
            m_unk338 = 1;
        }
        if (*(void **)(mTempArray__15EntityBaseClass + 8) != 0) {
            *(void **)mTempArray__15EntityBaseClass = 0;
            *(int *)(mTempArray__15EntityBaseClass + 4) = 0;
        }
        float (*pPos2)[4] = m_unk3C ? (float (*)[4])((char *)m_unk3C + 0x80) : &m_unk190;
        GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(mpEntMgr__15EntityBaseClass, 3, mTempArray__15EntityBaseClass, pPos2, 25.0f, 0, true, true);
        int nCount = *(int *)mTempArray__15EntityBaseClass;
        void **ppData = *(void ***)(mTempArray__15EntityBaseClass + 8);
        for (int i = 0; i < nCount; i++) {
            char *pEnt = (char *)ApparitionIsValid__15EntityBaseClassFUi((unsigned int)ppData[i]);
            if (pEnt != 0 && *(int *)(pEnt + 0x20) >= 0) {
                char *pMat = *(char **)(pEnt + 0x38);
                if (pMat != 0) {
                    sceVu0InnerProduct((float *)pMat, (float *)pMat);
                    if (IsEntityOnNode((EntityBaseClass *)pEnt, (PMeshNode *)m_unk3C) != 0 && (*(unsigned int *)(pMat + 0x108) & 0x80)) {
                        m_unk334 = -1;
                        float fMin2 = 3.4028235e38f;
                        int nOff2 = 0;
                        for (int j = 0; j < m_unk330; nOff2 += 0x20, j++) {
                            char *pE3C = *(char **)(pEnt + 0x3C);
                            float (*pQ)[4] = pE3C ? (float (*)[4])(pE3C + 0x80) : (float (*)[4])(pEnt + 0x190);
                            float fD2 = Distance__7MathAPIFPA4_fPA4_f(pQ, (float (*)[4])((char *)this + nOff2 + 0x210));
                            if (fD2 < fMin2) {
                                fMin2 = fD2;
                                m_unk334 = j;
                            }
                        }
                        int nIdx2 = m_unk334;
                        if (nIdx2 == 0 || nIdx2 == m_unk330 - 1) {
                            int nNew2 = 1;
                            if (nIdx2 != 0) {
                                nNew2 = nIdx2 - 1;
                            }
                            m_unk334 = nNew2;
                        }
                        if ((*(unsigned int *)(pMat + 0x108) & 0x80) && m_unk344 == 0) {
                            static unsigned int aResetTimerFrame2;
                            static char init3;
                            if (init3 == 0) {
                                aResetTimerFrame2 = 0x1E;
                                init3 = 1;
                            }
                            m_unk344 = CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk4, aResetTimerFrame2, true);
                            static float aWalkForce2;
                            static char init4;
                            if (init4 == 0) {
                                aWalkForce2 = -0.25f;
                                init4 = 1;
                            }
                            PushPlank(m_unk334, aWalkForce2, 1.0f);
                        }
                        m_unk33C -= 1;
                        if (m_unk33C < 0) {
                            PlaySound__15EntityBaseClassFUi(this, 0x4E58);
                            m_unk33C = RandomIntRange__7MathAPIFii(0xA, 0x78);
                        }
                        m_unk340 = 1;
                    }
                }
            }
        }
        if (m_unk340 != 0 && m_unk1E4[0] != 0) {
            RunPhysics();
            UpdateBridgeRope();
        }
        return;
    }
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
