#include "types.h"
#include "pso/quest/TQuestVmDownLoadServer_803E6970.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/quest/QuestDownloadServer.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"

// The ARAM back end of the keyboard's ASKDIC dictionary ("ASKDIC:ARAM DMA Timeout!!"): TWindowKeyBoardBase sets the
// ARAM image up with sub_803F0C04, then sub_803F09A4 starts the dictionary; sub_803F0BE0 / sub_803F09FC /
// aram_dma_read are the open / seek / read calls of TQuestVmDownLoadServer_803E6970's file reader.
s32 lbl_805D7908;
s32 lbl_805D790C;
// The ARAM file opened by sub_803F0C04 and read through ARQPostRequest (names from those parameters).
u32 quest_download_aram_size;
File_803F09FC quest_download_aram_file;
u32 quest_download_aram_timeout;
u32 quest_download_aram_priority;
u32 quest_download_aram_owner;
s32 quest_download_aram_dma_pending;
u32 quest_download_aram_base;

extern "C" {
s32 start_askdic(void) {
    s32 result;
    quest_download_state = 0;
    quest_download_initialized = 1;
    lbl_805D7908 = 0;
    lbl_805D790C = 0;
    result = TWindowKeyBoardSoft::dispatch_request_0x20("Dummy", "");
    if (result == 0) {
        result = TWindowKeyBoardSoft::dispatch_request_0x1c();
    }
    if (result > 0) {
        result = -1;
    }
    return result;
}

s32 aram_seek(void *handle, int offset, int whence) {
    s32 r;
    switch (whence) {
    case 0:
        if (offset < 0) {
            return -1;
        }
        quest_download_aram_file.remain = quest_download_aram_size - offset;
        quest_download_aram_file.pos = offset;
        break;
    case 1:
        r = quest_download_aram_file.remain - offset;
        if (r < 0 || (u32)r > quest_download_aram_size) {
            return -1;
        }
        quest_download_aram_file.remain = r;
        quest_download_aram_file.pos += offset;
        break;
    case 2:
        if (offset > 0) {
            return -1;
        }
        quest_download_aram_file.remain = -offset;
        offset = quest_download_aram_size + offset;
        quest_download_aram_file.pos = offset - 1;
        break;
    }
    return quest_download_aram_file.pos;
}

const char aram_dma_timeout_message[] = "ASKDIC:ARAM DMA Timeout!!\n";

u32 TQuestVmDownLoadServer::aram_dma_read(void *h, void *dst, int size) {
    u32 n;
    u32 len;
    u32 start;
    u8 *base;
    base = quest_download_aram_dma_buffer;
    n = quest_download_aram_file.remain;
    if ((u32)quest_download_aram_file.remain >= (u32)size) {
        n = size;
    }
    len = n;
    if (n & 3) {
        len = (n | 3) + 1;
    }
    DCInvalidateRange(base + 0x40, 0x2000);
    (*(u32 *)&quest_download_aram_dma_pending) = 1;
    ARQPostRequest(base + 0x2040, quest_download_aram_owner, 1, quest_download_aram_priority, quest_download_aram_base + quest_download_aram_file.pos,
                   (uaddr)(base + 0x40), len, aram_dma_done);
    start = OSGetTick();
    for (;;) {
        if ((*(u32 *)&quest_download_aram_dma_pending) == 0) {
            memcpy(dst, base + 0x40, n);
            break;
        }
        if (OSGetTick() - start > quest_download_aram_timeout) {
            (*(u32 *)&quest_download_aram_dma_pending) = 0;
            ARQRemoveRequest(base + 0x2040);
            OSReport(aram_dma_timeout_message);
            return -1;
        }
    }
    quest_download_aram_file.remain -= n;
    quest_download_aram_file.pos += n;
    return n;
}

s32 aram_close(void *handle) {
    return 0;
}

s32 aram_open(const char *name, s32 mode) {
    return 1;
}

void aram_dma_done(u8 *request) {
    if ((u32) *(u32 *)((s8 *)request + 4) == (u32) quest_download_aram_owner) {
        quest_download_aram_dma_pending = 0;
    }
}

void aram_dma_setup(u32 aram_addr, s32 size, u32 owner, u32 priority, u32 timeout_ms) {
    quest_download_aram_base = aram_addr;
    quest_download_aram_file.remain = size;
    quest_download_aram_file.pos = 0;
    quest_download_aram_owner = owner;
    quest_download_aram_size = quest_download_aram_file.remain;
    quest_download_aram_priority = priority;
    quest_download_aram_timeout = timeout_ms * (__OSBusClock / 4 / 1000);
}

}

u8 quest_download_aram_dma_buffer[0x2060];
