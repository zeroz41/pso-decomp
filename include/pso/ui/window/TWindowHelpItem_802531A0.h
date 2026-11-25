#ifndef PSO_UI_WINDOW_TWINDOWHELPITEM_802531A0_H
#define PSO_UI_WINDOW_TWINDOWHELPITEM_802531A0_H

#include "types.h"
#include "pso/ui/window/TWindowHelpItem.h"

struct HelpItemStarRowEntry {
    u8 pad0[0x10];
    s32 stars;
};

struct HelpItemLevelEntry {
    u8 pad0[0x20];
    s32 value;
};

#endif
