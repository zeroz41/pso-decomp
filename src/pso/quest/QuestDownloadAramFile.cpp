#include <dolphin/ar.h>
#include "types.h"
#include "pso/quest/TQuestVmDownLoadServer_803E6970.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/quest/QuestDownloadServer.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"

// The ARAM back end of the keyboard's ASKDIC dictionary ("ASKDIC:ARAM DMA Timeout!!"): TWindowKeyBoardBase sets the
// ARAM image up with aram_dma_setup, then start_askdic starts the dictionary.
struct QuestDownloadAramFile {
    s32 remain;
    s32 pos;
};
LAYOUT_ASSERT(QuestDownloadAramFileSize, sizeof(QuestDownloadAramFile) == 8);
LAYOUT_ASSERT(QuestDownloadAramFilePosition, offsetof(QuestDownloadAramFile, pos) == 4);

s32 lbl_805D7908;
s32 lbl_805D790C;
// The ARAM file opened by sub_803F0C04 and read through ARQPostRequest (names from those parameters).
u32 quest_download_aram_size;
QuestDownloadAramFile quest_download_aram_file;
u32 quest_download_aram_timeout;
u32 quest_download_aram_priority;
u32 quest_download_aram_owner;
u32 quest_download_aram_dma_pending;
u32 quest_download_aram_base;

struct QuestDownloadAramDmaBuffer {
    u8 reserved[0x40];
    u8 bytes[0x2000];
    ARQRequest request;
};

LAYOUT_ASSERT(QuestDownloadAramDmaBytesOffset, offsetof(QuestDownloadAramDmaBuffer, bytes) == 0x40);
LAYOUT_ASSERT(QuestDownloadAramDmaRequestOffset, offsetof(QuestDownloadAramDmaBuffer, request) == 0x2040);
LAYOUT_ASSERT(QuestDownloadAramDmaBufferSize, sizeof(QuestDownloadAramDmaBuffer) == 0x2060);

extern "C" {
extern QuestDownloadAramDmaBuffer quest_download_aram_dma_buffer;
void aram_dma_done(uaddr request);

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

s32 aram_seek(s32 handle, s32 offset, s32 whence) {
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

s32 TQuestVmDownLoadServer::aram_dma_read(s32 handle, void *dst, s32 size) {
    u32 n;
    u32 len;
    u32 start;
    QuestDownloadAramDmaBuffer *base = &quest_download_aram_dma_buffer;
    n = quest_download_aram_file.remain;
    if ((u32)quest_download_aram_file.remain >= (u32)size) {
        n = size;
    }
    len = n;
    if (n & 3) {
        len = (n | 3) + 1;
    }
    DCInvalidateRange(base->bytes, sizeof(base->bytes));
    quest_download_aram_dma_pending = 1;
    ARQPostRequest(&base->request, quest_download_aram_owner, 1, quest_download_aram_priority,
                   quest_download_aram_base + quest_download_aram_file.pos, reinterpret_cast<uaddr>(base->bytes), len,
                   aram_dma_done);
    start = OSGetTick();
    for (;;) {
        if (quest_download_aram_dma_pending == 0) {
            memcpy(dst, base->bytes, n);
            break;
        }
        if (OSGetTick() - start > quest_download_aram_timeout) {
            quest_download_aram_dma_pending = 0;
            ARQRemoveRequest(&base->request);
            OSReport(aram_dma_timeout_message);
            return -1;
        }
    }
    quest_download_aram_file.remain -= n;
    quest_download_aram_file.pos += n;
    return n;
}

s32 aram_close(s32 handle) {
    return 0;
}

s32 aram_open(const char *name, s32 mode) {
    return 1;
}

void aram_dma_done(uaddr request) {
    if (reinterpret_cast<const ARQRequest *>(request)->owner == quest_download_aram_owner) {
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

QuestDownloadAramDmaBuffer quest_download_aram_dma_buffer;
