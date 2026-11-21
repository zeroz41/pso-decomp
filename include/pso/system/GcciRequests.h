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
LAYOUT_ASSERT(GcciRequestSize, sizeof(GcciRequest) == 0x64);
LAYOUT_ASSERT(GcciRequestState, offsetof(GcciRequest, state) == 2);
LAYOUT_ASSERT(GcciRequestBuffer, offsetof(GcciRequest, buf) == 8);
LAYOUT_ASSERT(GcciRequestStatus, offsetof(GcciRequest, status) == 0xC);
LAYOUT_ASSERT(GcciRequestUnit, offsetof(GcciRequest, unit) == 0x10);
LAYOUT_ASSERT(GcciRequestPosition, offsetof(GcciRequest, pos) == 0x1C);
LAYOUT_ASSERT(GcciRequestDone, offsetof(GcciRequest, done) == 0x20);
LAYOUT_ASSERT(GcciRequestCount, offsetof(GcciRequest, count) == 0x24);
LAYOUT_ASSERT(GcciRequestDvdInfo, offsetof(GcciRequest, block) == 0x28);
LAYOUT_ASSERT(GcciRequestDvdInfoSize, sizeof(DVDFileInfo) == 0x3C);
LAYOUT_ASSERT(GcciRequestCommandBlock, offsetof(DVDFileInfo, cb) == 0);
LAYOUT_ASSERT(GcciRequestDvdLength, offsetof(DVDFileInfo, length) == 0x34);
LAYOUT_ASSERT(GcciStatusSize, sizeof(GcciStatus) == 12);
LAYOUT_ASSERT(GcciStatusState, offsetof(GcciStatus, state) == 4);
extern "C" {
void *gcCiOpen(const char *name, s32 entry, s32 mode);
s32 gcCiGetFileSize(char *name);
}

#endif
