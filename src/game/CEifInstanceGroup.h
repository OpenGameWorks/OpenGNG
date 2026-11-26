#ifndef CEIFINSTANCEGROUP_H
#define CEIFINSTANCEGROUP_H

#include "types.h"

class PPakFile;
class CEifInstance;
class CBefEntityData;

// CEifInstanceGroup members are named by their offset from the object start.
class CEifInstanceGroup {
public:
    CEifInstanceGroup();
    ~CEifInstanceGroup();
    void Cleanup();
    CEifInstance *GetInstanceData(int nIndex);
    int Read(PPakFile *pFile, unsigned int nVersion);
    int GetNumInstances();

    CEifInstance **m_unk0;                  // 0x000 instance pointer array (count at 0x8)
    CBefEntityData *m_unk4;                 // 0x004 entity data block
    int m_unk8;                             // 0x008 instance count
};

#endif
