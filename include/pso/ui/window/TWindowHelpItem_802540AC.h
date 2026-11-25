#ifndef PSO_UI_WINDOW_TWINDOWHELPITEM_802540AC_H
#define PSO_UI_WINDOW_TWINDOWHELPITEM_802540AC_H

#include "types.h"

struct TWindowHelpItem;

// Run each frame while the resistance page is shown.
extern void (TWindowHelpItem::*item_help_resistance_stat_callback)();

extern "C" {
void show_item_by_id__15TWindowHelpItemFPvi(u8 *window_help_item, saddr id);
}

#endif
