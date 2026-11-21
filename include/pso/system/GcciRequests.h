#ifndef PSO_SYSTEM_GCCI_REQUESTS_H
#define PSO_SYSTEM_GCCI_REQUESTS_H
#include "types.h"
#include <stddef.h>
#include <dolphin/dvd.h>

struct GcciRequest {
    u8 active;
    u8 unknown01;
    s8 state;
    u8 unknown03[5];
    void *buf;
    s32 status;
    s32 unit;
    s32 file_size;
    s32 sector_count;
    s32 pos;
    s32 done;
    s32 count;
    DVDFileInfo block;
};

struct GcciStatus {
    s32 status;
    s8 state;
    u8 unknown05[3];
    s32 unknown08;
};
typedef char GcciRequestSize[sizeof(GcciRequest) == 0x64 ? 1 : -1];
typedef char GcciRequestState[offsetof(GcciRequest, state) == 2 ? 1 : -1];
typedef char GcciRequestBuffer[offsetof(GcciRequest, buf) == 8 ? 1 : -1];
typedef char GcciRequestStatus[offsetof(GcciRequest, status) == 0xC ? 1 : -1];
typedef char GcciRequestUnit[offsetof(GcciRequest, unit) == 0x10 ? 1 : -1];
typedef char GcciRequestPosition[offsetof(GcciRequest, pos) == 0x1C ? 1 : -1];
typedef char GcciRequestDone[offsetof(GcciRequest, done) == 0x20 ? 1 : -1];
typedef char GcciRequestCount[offsetof(GcciRequest, count) == 0x24 ? 1 : -1];
typedef char GcciRequestDvdInfo[offsetof(GcciRequest, block) == 0x28 ? 1 : -1];
typedef char GcciRequestDvdInfoSize[sizeof(DVDFileInfo) == 0x3C ? 1 : -1];
typedef char GcciRequestCommandBlock[offsetof(DVDFileInfo, cb) == 0 ? 1 : -1];
typedef char GcciRequestDvdLength[offsetof(DVDFileInfo, length) == 0x34 ? 1 : -1];
typedef char GcciStatusSize[sizeof(GcciStatus) == 12 ? 1 : -1];
typedef char GcciStatusState[offsetof(GcciStatus, state) == 4 ? 1 : -1];
extern "C" {
void *gcCiOpen(const char *name, s32 entry, s32 mode);
s32 gcCiGetFileSize(char *name);
}

#endif
