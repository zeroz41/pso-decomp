#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

extern "C" {
void fn_80255A38(TWindowHelpItem *item);
}

void fn_80255A38(TWindowHelpItem *item) {
    item->entry_list.destroy_all_items();
    item->help_flags &= ~1;
    item->active_item = NULL;
    item->item_data = 0;
    item->displayed_item_data = 0;
    item->shown_item_id = -1;
    item->item_id = -1;
    item->displayed_item_id = -1;
    item->m_callback = NULL;
}
