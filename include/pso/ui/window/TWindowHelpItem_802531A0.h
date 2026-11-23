#ifndef PSO_UI_WINDOW_TWINDOWHELPITEM_802531A0_H
#define PSO_UI_WINDOW_TWINDOWHELPITEM_802531A0_H

#include "types.h"
#include "pso/ui/window/TWindowHelpItem.h"

extern TWindowHelpItem::CallbackWords TWindowHelpItem__photon_blast_update_callback;

struct HelpItemStarRowEntry {
    u8 pad0[0x10];
    s32 stars;
};

struct HelpItemLevelEntry {
    u8 pad0[0x20];
    s32 value;
};

extern "C" {
void TWindowHelpItem__sub_802531A0(void);
void TWindowHelpItem__sub_80253268(u8 *window_base);
void TWindowHelpItem__vt11(u8 *window);
}

#endif
