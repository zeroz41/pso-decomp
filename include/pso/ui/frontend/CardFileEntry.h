#ifndef PSO_UI_FRONTEND_CARDFILEENTRY_H
#define PSO_UI_FRONTEND_CARDFILEENTRY_H

#include "types.h"
#include "dolphin/os/OSThread.h"
#include "dolphin/card.h"

// One entry of the open-file table: in use, the card slot it is on (2 = none) and its CARD handles.
struct CardFileEntry {
    s16 in_use;
    s16 pad2;
    s32 channel;
    CARDFileInfo file_info;
    CARDStat stat;
};

#endif
