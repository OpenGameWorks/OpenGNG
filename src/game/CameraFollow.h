#ifndef CAMERAFOLLOW_H
#define CAMERAFOLLOW_H

#include "types.h"

// TODO(header): foreign declarations
class PVec3;

class tag_ControlData {
public:
    ~tag_ControlData();
};

class CameraFollow {
public:
    void SetSourceAndTarget(PVec3 arg0, PVec3 arg1);

    char _pad000[0x20];
    float m_unk20[4];       // 0x020
    char _pad030[0x40 - 0x30];
    float m_unk40[4];       // 0x040
};

#endif
