#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

extern "C" {
extern TWindowHelpItem::CallbackWords __ptmf_null;
void fn_80255A38(TWindowHelpItem *item);
}

void fn_80255A38(TWindowHelpItem *item) {
    item->entry_list.destroy_all_items();
    item->m_60 &= ~1;
    item->active_item = NULL;
    item->secondary_item = 0;
    item->primary_item = 0;
    item->active_id = -1;
    item->secondary_id = -1;
    item->primary_id = -1;
    item->m_callback = __ptmf_null;
}
