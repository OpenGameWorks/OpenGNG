// FLAGS: -str readonly
#include "CEifInstanceGroup.h"
#include "CEifInstance.h"
#include "CBefEntityData.h"
#include "types.h"

// TODO(header): foreign declarations
class PPakFile;
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" int Read__7PCDFileFPvUi(void *pThis, void *pBuffer, unsigned int nSize);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void __dla__FPv(void *pBlock);
extern "C" void __dl__FPv(void *pBlock);
extern "C" void *__ct__12CEifInstanceFv(void *pThis);
extern "C" void *__dt__12CEifInstanceFv(void *pThis, short nFlag);
extern "C" void *__ct__14CBefEntityDataFv(void *pThis);
extern "C" void *__dt__14CBefEntityDataFv(void *pThis, short nFlag);

// The game's assert evaluates the condition at runtime, so the message is passed as text.
#define CDS_ASSERT(line, cond, text) ((cond) ? (void)0 : CdsAssert__FPciPc("CEifInstanceGroup.cpp", line, text))

// FUNCTION: 0x172650 Cleanup__17CEifInstanceGroupFv
void CEifInstanceGroup::Cleanup()
{
    if (m_unk0) {
        for (int i = 0; i < m_unk8; i++) {
            if (m_unk0[i]) {
                __dt__12CEifInstanceFv(m_unk0[i], 1);
            }
        }
        __dla__FPv(m_unk0);
        m_unk0 = 0;
        m_unk8 = 0;
    }
    if (m_unk4) {
        __dt__14CBefEntityDataFv(m_unk4, 1);
        m_unk4 = 0;
    }
}

// FUNCTION: 0x172700 GetInstanceData__17CEifInstanceGroupFi
CEifInstance *CEifInstanceGroup::GetInstanceData(int nIndex)
{
    CDS_ASSERT(0x93, nIndex < m_unk8, "iInstanceIndex < miNumInstances");
    CDS_ASSERT(0x94, m_unk0, "mpInstances");
    return m_unk0[nIndex];
}

// FUNCTION: 0x172780 Read__17CEifInstanceGroupFP8PPakFileUi
int CEifInstanceGroup::Read(PPakFile *pFile, unsigned int nVersion)
{
    CDS_ASSERT(0x27, pFile, "pFile");
    Cleanup();
    if (Read__7PCDFileFPvUi((void *)pFile, &m_unk8, 4) != 4) {
        return 0;
    }
    CDS_ASSERT(0x34, m_unk8 > 0, "miNumInstances > 0");
    CBefEntityData *pData = (CBefEntityData *)__nw__FUi(0x90);
    if (pData) {
        pData = (CBefEntityData *)__ct__14CBefEntityDataFv(pData);
    }
    m_unk4 = pData;
    CDS_ASSERT(0x38, m_unk4, "mpEntityData");
    unsigned int nFlag = (nVersion < 0x10003) ? 0x10000 : 0x10001;
    if (m_unk4->Read(pFile, nFlag) == 0) {
        Cleanup();
        return 0;
    }
    m_unk0 = (CEifInstance **)__nwa__FUi(m_unk8 * 4);
    CDS_ASSERT(0x47, m_unk0, "mpInstances");
    for (int i = 0; i < m_unk8; i++) {
        CEifInstance *p = (CEifInstance *)__nw__FUi(0x12C);
        if (p) {
            p = (CEifInstance *)__ct__12CEifInstanceFv(p);
        }
        CDS_ASSERT(0x4C, p, "apoInstance");
        if (p->Read(pFile, nVersion) == 0) {
            __dt__12CEifInstanceFv(p, 1);
            Cleanup();
            return 0;
        }
        m_unk0[i] = p;
    }
    return 1;
}

// FUNCTION: 0x1729A0 __dt__17CEifInstanceGroupFv
CEifInstanceGroup::~CEifInstanceGroup()
{
    Cleanup();
}

// FUNCTION: 0x172A00 __ct__17CEifInstanceGroupFv
CEifInstanceGroup::CEifInstanceGroup()
{
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk8 = 0;
}
