#include "types.h"
#include "ZinShell.h"
#include "PArray.h"

// TODO(header): foreign declarations
extern "C" void __dl__FPv(void *);
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void CdsAssert__FPciPc(const char *, int, const char *);
extern "C" void *__nw__FUi(unsigned int);
extern "C" void sceVu0SubVector(float *, float *, float *);
extern "C" void sceVu0AddVector(float *, float *, float *);
extern "C" void sceVu0Normalize(float *, float *);
extern "C" void sceVu0ScaleVector(float *, float *, float);
extern "C" float atan2f(float, float);
extern "C" float Round180__Ff(float);
extern "C" float sqrtf(float);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(float (*)[4], float (*)[4]);
extern "C" void ShakeScreen__9CameraAPIFfffUi(void *, float, float, float, unsigned int);
extern "C" void Terminate__14ZinShellShadowFv(void *);
extern "C" void DisableAllHitBox__6PMNodeFv(void *);
extern "C" void *Spawn__13EntityManagerFUibi(void *, unsigned int, bool, int);
extern "C" void *GetPtrToApparition__13EntityManagerFUi(void *, unsigned int);
extern "C" void *FindTrigger__13EntityManagerFUii(void *, unsigned int, int);
extern "C" void *ApparitionIsValid__15EntityBaseClassFUi(unsigned int);
extern "C" void GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(void *, int, PArray *, float (*)[4], float, int, bool, bool);
extern "C" void *__ct__13TriggerSystemFiPA4_fUisbsfbUiUiUiUiUiUiUiUiUiUibb(void *, int, float (*)[4], unsigned int, short, bool, short, float, bool, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, bool, bool);
extern unsigned int ZinShell_InitShellSeq[];
extern unsigned int ZinShell_ShellExplodeSeq[13];
extern void *mpEntMgr__15EntityBaseClass;
extern PArray mTempArray__15EntityBaseClass;
extern char *mPlayerAPI__13EntityManager;
extern char mCameraAPI__13EntityManager[];
extern float gUnitMatrix[16];

// FUNCTION: 0x001AF330 __dt__8ZinShellFv
ZinShell::~ZinShell() {
}

// FUNCTION: 0x001AF390 GetClassName__8ZinShellFv
const char *ZinShell::GetClassName() {
    return "Zin Shell";
}

// FUNCTION: 0x001AF3A0 SetEditableVars__8ZinShellFPc
void ZinShell::SetEditableVars(char *arg0) {
    memcpy(&m_unk1B0, arg0, 0x20);
    float temp = m_unk1B4;
    if (temp == 0.0f && m_unk1B8 == 0.0f && m_unk1BC == 0.0f) {
        m_unk1D0[0] = (m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190)[0];
        m_unk1D0[1] = 50.0f + (m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190)[1];
        m_unk1D0[2] = (m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190)[2];
    } else {
        m_unk1D0[0] = temp;
        m_unk1D0[1] = m_unk1B8;
        m_unk1D0[2] = m_unk1BC;
    }
    m_unk1E0[0] = (m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190)[0];
    m_unk1E0[1] = (m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190)[1];
    m_unk1E0[2] = (m_unk3C ? (float *)((char *)m_unk3C + 0x80) : m_unk190)[2];
}

// DRAFT: 0x001AF500 SetShellStartAndDest__8ZinShellFRA4_fRA4_f
// note: 12 words differ; loads match the original's registers, but the stores run in reverse order (forward stores give a different register mapping), tried 6 local-declaration and store-order variants.
void ZinShell::SetShellStartAndDest(float (&arg0)[4], float (&arg1)[4]) {
    float d = arg0[3];
    float c = arg0[2];
    float b = arg0[1];
    float a = arg0[0];
    m_unk1D0[3] = d;
    m_unk1D0[2] = c;
    m_unk1D0[1] = b;
    m_unk1D0[0] = a;
    float h = arg1[3];
    float g = arg1[2];
    float f = arg1[1];
    float e = arg1[0];
    m_unk1E0[3] = h;
    m_unk1E0[2] = g;
    m_unk1E0[1] = f;
    m_unk1E0[0] = e;
}

// DRAFT: 0x001AF550 Execute__8ZinShellFv
// note: 531 differing words; switch now lowers to the -2..3 jump table, but the frame is -0xC0 not -0xD0 and the case -1 and case 0 blocks are ordered differently.
void ZinShell::Execute() {
    switch (m_unk20) {
    case -1:
        if (m_unk18 != 0) {
            m_unk200[0] = m_unk1C0[0];
            m_unk200[1] = m_unk1C0[1];
            m_unk200[2] = m_unk1C0[2];
            m_unk20C = 1.0f;
            if (m_unk200[0] == 0.0f && m_unk200[1] == 0.0f && m_unk200[2] == 0.0f) {
                SetState(-2);
                return;
            }
            SetState(3);
            return;
        }
        SetState(0);
        return;
    case 3: {
        char *pPlayer = mPlayerAPI__13EntityManager;
        char *pPlayerSrc = ((EntityBaseClass *)pPlayer)->m_unk3C;
        float *pTarget = (pPlayerSrc != 0) ? (float *)(pPlayerSrc + 0x80) : (float *)(pPlayer + 0x190);
        if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])m_unk200, (float (*)[4])pTarget) <= m_unk1CC) {
            SetState(0);
            return;
        }
        return;
    }
    case -2:
    case 2:
    default:
        return;
    case 0:
        if (((unsigned char *)this)[0xE9] != 0) {
            m_unkE8 = 0xB;
            sceVu0SubVector(m_unk1F0, m_unk1E0, m_unk1D0);
            sceVu0Normalize(m_unk1F0, m_unk1F0);
            if (m_unk3C != 0) {
                *(u_long128 *)(((ZinShellSource *)m_unk3C)->m_unk80) = *(u_long128 *)m_unk1D0;
                m_unk3C[0x3E] |= 8;
            } else {
                *(u_long128 *)m_unk190 = *(u_long128 *)m_unk1D0;
            }
            void *pSpawn = Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0x12, 0, 0);
            if (pSpawn == 0) {
                CdsAssert__FPciPc("ZinShell.cpp", 0x71, "pZinShellShadow");
            }
            EntityBaseClass *pEnt = (EntityBaseClass *)pSpawn;
            if (pEnt->m_unk3C != 0) {
                *(u_long128 *)(pEnt->m_unk3C + 0x80) = *(u_long128 *)m_unk1E0;
                pEnt->m_unk3C[0x3E] |= 8;
            } else {
                *(u_long128 *)((char *)pEnt + 0x190) = *(u_long128 *)m_unk1E0;
            }
            m_unk220 = pEnt->m_unk04;
            PlaySequence(ZinShell_InitShellSeq);
            m_unk230 = PlaySoundUbiquitous(0x82);
            m_unk210 = 1.0f;
        }
        {
            float *pPos = (m_unk3C != 0) ? (float *)(m_unk3C + 0x80) : m_unk190;
            if (pPos[1] < m_unk1E0[1]) {
                StopSoundBySoundRef(m_unk230);
                SetState(1);
                return;
            }
        }
        if (*(int *)((char *)mpEntMgr__15EntityBaseClass + 0x5058) == 0) {
            sceVu0ScaleVector(m_unk1F0, m_unk1F0, m_unk210);
            float *pPos = (m_unk3C != 0) ? (float *)(m_unk3C + 0x80) : m_unk190;
            sceVu0AddVector(pPos, m_unk1F0, pPos);
            float spC[4];
            if (m_unk1F0[0] != 0.0f || m_unk1F0[2] != 0.0f) {
                float len = sqrtf(m_unk1F0[0] * m_unk1F0[0] + m_unk1F0[2] * m_unk1F0[2]);
                spC[0] = 57.295776f * atan2f(-m_unk1F0[1], -len) - 90.0f;
                spC[1] = 57.295776f * (3.1415927f + atan2f(m_unk1F0[0], m_unk1F0[2]));
                spC[2] = 0.0f;
                Round180__Ff(spC[0]);
                Round180__Ff(spC[1]);
                if (m_unk3C != 0) {
                    *(u_long128 *)(m_unk3C + 0x90) = *(u_long128 *)spC;
                    m_unk3C[0x3E] |= 8;
                } else {
                    *(u_long128 *)&m_unk190[4] = *(u_long128 *)spC;
                }
            }
            float fSpeed;
            {
                static float aaaSpeedMult;
                static int init;
                if (init == 0) {
                    init = 1;
                    aaaSpeedMult = 1.007f;
                }
                fSpeed = m_unk210 * aaaSpeedMult;
            }
            m_unk210 = fSpeed;
            {
                static float aaaSpeedCap;
                static int init;
                if (init == 0) {
                    init = 1;
                    aaaSpeedCap = 1.02f;
                }
                if (!(fSpeed < aaaSpeedCap)) {
                    fSpeed = aaaSpeedCap;
                }
            }
            m_unk210 = fSpeed;
            return;
        }
        break;
    case 1:
        if (((unsigned char *)this)[0xE9] != 0) {
            m_unk22D = 1;
            void *pShadow = GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, m_unk220);
            if (pShadow != 0) {
                Terminate__14ZinShellShadowFv(pShadow);
            }
            ShakeScreen__9CameraAPIFfffUi(mCameraAPI__13EntityManager, 0.0f, 2.0f, 3.0f, 0);
            if (m_unk3C != 0) {
                *(u_long128 *)(m_unk3C + 0x90) = *(u_long128 *)&gUnitMatrix[12];
                m_unk3C[0x3E] |= 8;
            } else {
                *(u_long128 *)&m_unk190[4] = *(u_long128 *)&gUnitMatrix[12];
            }
            PlaySequence(ZinShell_ShellExplodeSeq);
            DisableAllHitBox__6PMNodeFv(m_unk3C);
            void *pExp = Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0x11, 0, 0);
            if (pExp == 0) {
                CdsAssert__FPciPc("ZinShell.cpp", 0xBB, "pExplosion");
            }
            float *pPos = (m_unk3C != 0) ? (float *)(m_unk3C + 0x80) : m_unk190;
            EntityBaseClass *pE = (EntityBaseClass *)pExp;
            if (pE->m_unk3C != 0) {
                *(u_long128 *)(pE->m_unk3C + 0x80) = *(u_long128 *)pPos;
                pE->m_unk3C[0x3E] |= 8;
            } else {
                *(u_long128 *)((char *)pE + 0x190) = *(u_long128 *)pPos;
            }
            int s3 = m_unk224;
            if (s3 != 0 || m_unk1B0 != 0) {
                int s2;
                if (s3 != 0) {
                    s2 = m_unk228;
                } else {
                    s3 = m_unk1B0;
                    s2 = m_unk04;
                }
                void *pTrig = FindTrigger__13EntityManagerFUii(mpEntMgr__15EntityBaseClass, s3, -1);
                if (pTrig != 0) {
                    if (((unsigned char *)pTrig)[9] == 0) {
                        ((unsigned char *)pTrig)[9] = 2;
                    }
                } else if (s3 != 0) {
                    void *pNew = __nw__FUi(0x50);
                    if (pNew != 0) {
                        pNew = __ct__13TriggerSystemFiPA4_fUisbsfbUiUiUiUiUiUiUiUiUiUibb(pNew, s2, (float (*)[4])pPos, s3, 0, 0, 0, 0.0f, 0, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0, 0);
                    }
                    if (((unsigned char *)pNew)[9] == 0) {
                        ((unsigned char *)pNew)[9] = 2;
                    }
                    ((PArray *)((char *)mpEntMgr__15EntityBaseClass + 0x5B60))->Add(pNew);
                }
            }
            if (m_unk214 != 0) {
                unsigned int i = 0;
                if (m_unk22C != 0) {
                    void *pS = Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0x41, 0, 0);
                    if (pS == 0) {
                        CdsAssert__FPciPc("ZinShell.cpp", 0xE5, "pZSCrater");
                    }
                    float *pP = (m_unk3C != 0) ? (float *)(m_unk3C + 0x80) : m_unk190;
                    EntityBaseClass *pSE = (EntityBaseClass *)pS;
                    if (pSE->m_unk3C != 0) {
                        *(u_long128 *)(pSE->m_unk3C + 0x80) = *(u_long128 *)pP;
                        pSE->m_unk3C[0x3E] |= 8;
                    } else {
                        *(u_long128 *)((char *)pSE + 0x190) = *(u_long128 *)pP;
                    }
                    i = 0;
                }
                while ((int)i < m_unk21C) {
                    if (m_unk214 != 2) {
                        CdsAssert__FPciPc("ZinShell.cpp", 0x101, "0");
                    } else {
                        void *pC = Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0x17, 0, 0);
                        if (pC == 0) {
                            CdsAssert__FPciPc("ZinShell.cpp", 0xF2, "pClockworkReaper");
                        }
                        float *pP = (m_unk3C != 0) ? (float *)(m_unk3C + 0x80) : m_unk190;
                        EntityBaseClass *pCE = (EntityBaseClass *)pC;
                        if (pCE->m_unk3C != 0) {
                            *(u_long128 *)(pCE->m_unk3C + 0x80) = *(u_long128 *)pP;
                            pCE->m_unk3C[0x3E] |= 8;
                        } else {
                            *(u_long128 *)((char *)pCE + 0x190) = *(u_long128 *)pP;
                        }
                        *(int *)((char *)pC + 0x1E0) = 1;
                        *(float *)((char *)pC + 0x238) = m_unk218;
                        float tf = m_unk218 + (360.0f / (float)m_unk21C);
                        m_unk218 = tf;
                        if (!(tf <= 360.0f)) {
                            m_unk218 = tf - 360.0f;
                        }
                    }
                    i++;
                }
            }
            if (mTempArray__15EntityBaseClass.m_unk8 != 0) {
                mTempArray__15EntityBaseClass.m_unk0 = 0;
                mTempArray__15EntityBaseClass.m_unk4 = 0;
            }
            float *pAll = (m_unk3C != 0) ? (float *)(m_unk3C + 0x80) : m_unk190;
            GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(mpEntMgr__15EntityBaseClass, 6, &mTempArray__15EntityBaseClass, (float (*)[4])pAll, 30.0f, 0, false, false);
            int n = (int)mTempArray__15EntityBaseClass.m_unk0;
            if (n > 0) {
                unsigned int j = 0;
                do {
                    void *pa = (j < mTempArray__15EntityBaseClass.m_unk0) ? mTempArray__15EntityBaseClass.m_unk8[j] : 0;
                    m_unk238 = pa;
                    void *pv = ApparitionIsValid__15EntityBaseClassFUi((unsigned int)m_unk238);
                    m_unk234 = pv;
                    if (pv != 0) {
                        ((unsigned char *)pv)[0x269] = 1;
                    }
                    j++;
                } while ((int)j < n);
            }
        }
        if (m_unk160 == 0) {
            WriteApparitionData(1, -3, 0);
            SetState(-2);
        }
        break;
    }
}

// FUNCTION: 0x001AFE40 __ct__8ZinShellFv
ZinShell::ZinShell() : EntityBaseClass((LoadClass)2, 0) {
    EnableSleep(false, false);
    m_unk214 = 0;
    m_unk218 = 0;
    m_unk22D = 0;
    m_unk22C = 0;
    m_unk224 = 0;
    m_unk228 = 0;
    m_unk1B0 = 0;
    m_unk1B4 = 0;
    m_unk1B8 = 0;
    m_unk1BC = 0;
}
