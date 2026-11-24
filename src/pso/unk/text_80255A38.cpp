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
    item->m_6c = 0;
    item->m_70 = 0;
    item->m_9c = -1;
    item->m_a0 = -1;
    item->m_a4 = -1;
    item->m_callback = __ptmf_null;
}
