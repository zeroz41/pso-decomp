#ifndef PSO_SYSTEM_CVFSTYPES_H
#define PSO_SYSTEM_CVFSTYPES_H

#include "types.h"

struct TLobbyEntry { CvFsDeviceInterface *device; char name[12]; };

struct CvFsHandle {
    CvFsDeviceInterface *vtbl;
    void *fd;
};

#endif
