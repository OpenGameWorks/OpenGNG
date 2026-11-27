// FLAGS: -str readonly
#include "CEifFile.h"
#include "Debug.h"
#include "types.h"

// TODO(header): foreign declarations
class CEifInstanceGroup;
class PPakFile;
extern PCDFile gPFile;
extern char gEng[105360];
extern "C" void __dla__FPv(void *pBlock);
extern "C" void __dt__17CEifInstanceGroupFv(void *pThis, short nDestroyFlag);
extern "C" void *__ct__17CEifInstanceGroupFv(void *pThis);
extern "C" int Read__17CEifInstanceGroupFP8PPakFileUi(void *pThis, PPakFile *pPak, unsigned int nSize);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" int strcmp(const char *pA, const char *pB);
extern "C" int sceClose(int nFd);

// FUNCTION: 0x172E00 Cleanup__8CEifFileFv
void CEifFile::Cleanup()
{
    if (m_unk110 != 0 && m_unk10C == 1) {
        Close(0);
    } else if (m_unk110 != 0) {
        sceClose((int)m_unk110);
        m_unk110 = 0;
    }
    if (m_unk0 != 0) {
        for (int i = 0; i < m_unk4; i++) {
            CEifInstanceGroup *pGroup = m_unk0[i];
            if (pGroup != 0) {
                __dt__17CEifInstanceGroupFv(pGroup, 1);
            }
        }
        __dla__FPv(m_unk0);
        m_unk0 = 0;
        m_unk4 = 0;
    }
    memset(_pad114, 0, 0x218);
    memset(_pad008, 0, 0x104);
    m_unk10C = 0;
}

// FUNCTION: 0x00172F00 GetNumInstanceGroups__8CEifFileFv
int CEifFile::GetNumInstanceGroups() {
    return m_unk4;
}

// FUNCTION: 0x172F10 Load__8CEifFileFPCc
int CEifFile::Load(const char *pszFilename)
{
    struct EifHeader {
        char magic[4];
        int unk4;
        int nGroupSize;
        int nGroupCount;
        int nHasBlock;
        unsigned int nWaypointSize;
        char _pad18[0xC];
    } hdr;

    if (m_unk10C != 0) {
        CdsAssert("CEifFile.cpp", 0xED, "meMode == EIF_INVALID");
    }
    if (pszFilename == 0) {
        CdsAssert("CEifFile.cpp", 0xEE, "pszFilename");
    }
    if (m_unk0 != 0) {
        CdsAssert("CEifFile.cpp", 0xEF, "mpInstanceGroups == NULL");
    }
    if (gPFile.Open(pszFilename, OPEN_READ) == 0) {
        return 0;
    }
    m_unk110 = &gPFile;
    if (m_unk110->Read(&hdr, 0x24) != 0x24) {
        m_unk110->Close();
        m_unk110 = 0;
        return 0;
    }
    if (strcmp(hdr.magic, "EIF!") != 0 || hdr.nGroupCount <= 0) {
        m_unk110->Close();
        m_unk110 = 0;
        return 0;
    }
    m_unk4 = hdr.nGroupCount;
    m_unk10C = 2;
    if (hdr.nHasBlock > 0) {
        memset(_pad114, 0, 0x218);
        if (m_unk110->Read(_pad114, 0x218) != 0x218) {
            m_unk110->Close();
            m_unk110 = 0;
            return 0;
        }
    }
    m_unk0 = (CEifInstanceGroup **)__nwa__FUi(m_unk4 * 4);
    if (m_unk0 == 0) {
        CdsAssert("CEifFile.cpp", 0x140, "mpInstanceGroups");
    }
    memset(m_unk0, 0, m_unk4 * 4);
    for (int i = 0; i < m_unk4; i++) {
        CEifInstanceGroup *pGroup = (CEifInstanceGroup *)__nw__FUi(0xC);
        if (pGroup != 0) {
            pGroup = (CEifInstanceGroup *)__ct__17CEifInstanceGroupFv(pGroup);
        }
        if (pGroup == 0) {
            CdsAssert("CEifFile.cpp", 0x147, "apoData");
        }
        if (Read__17CEifInstanceGroupFP8PPakFileUi(pGroup, (PPakFile *)m_unk110, hdr.nGroupSize) == 0) {
            m_unk110->Close();
            m_unk110 = 0;
            Cleanup();
            return 0;
        }
        m_unk0[i] = pGroup;
    }
    if (hdr.nWaypointSize != 0) {
        m_unk32C = (WaypointManager *)(gEng + 0x13810);
        if (m_unk32C == 0) {
            CdsAssert("CEifFile.cpp", 0x163, "m_pWpMgr");
        }
        if (m_unk32C->LoadWaypoints((PPakFile *)m_unk110, hdr.nWaypointSize) == 0) {
            m_unk110->Close();
            m_unk110 = 0;
            Cleanup();
            return 0;
        }
    }
    m_unk110->Close();
    m_unk110 = 0;
    return 1;
}

// FUNCTION: 0x173200 GetInstanceGroup__8CEifFileFi
CEifInstanceGroup *CEifFile::GetInstanceGroup(int nIndex)
{
    if (nIndex >= m_unk4) {
        CdsAssert("CEifFile.cpp", 0xE2, "iIndex < miNumInstanceGroups");
    }
    return m_unk0[nIndex];
}

// FUNCTION: 0x00173260 Close__8CEifFileFb
int CEifFile::Close(bool) {
    return 0;
}

// FUNCTION: 0x00173270 __dt__8CEifFileFv
CEifFile::~CEifFile() {
    Cleanup();
}

// FUNCTION: 0x001732D0 __ct__8CEifFileFv
CEifFile::CEifFile() {
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk10C = 0;
    m_unk110 = 0;
    memset(_pad008, 0, 0x104);
    memset(_pad114, 0, 0x218);
}
