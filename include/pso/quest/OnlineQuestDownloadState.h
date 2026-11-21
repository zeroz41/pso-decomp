#ifndef PSO_QUEST_ONLINEQUESTDOWNLOADSTATE_H
#define PSO_QUEST_ONLINEQUESTDOWNLOADSTATE_H

#include "types.h"
#include <stddef.h>

struct OnlineQuestDownloadState {
    char name[0x34];
    s32 size;
    u8 *buffer;
};

LAYOUT_ASSERT(OnlineQuestDownloadStateSize, sizeof(OnlineQuestDownloadState) == 0x3C);
LAYOUT_ASSERT(OnlineQuestDownloadSizeOffset, offsetof(OnlineQuestDownloadState, size) == 0x34);
LAYOUT_ASSERT(OnlineQuestDownloadBufferOffset, offsetof(OnlineQuestDownloadState, buffer) == 0x38);

extern "C" {
extern OnlineQuestDownloadState TQuestListOnline__dat_download_state;
extern OnlineQuestDownloadState TQuestListOnline__bin_download_state;
void TQuestListOnline__sub_802176DC(const u8 *data, s32 size);
}

#endif
