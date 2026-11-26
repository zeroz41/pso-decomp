#ifndef PSO_UI_WINDOW_EQUIPITEMFILTER_H
#define PSO_UI_WINDOW_EQUIPITEMFILTER_H

#include "types.h"

struct TWindowSubEquipKind;

void disable_pack_item_rows(void *qst_pack_select_window, s32 item);

void mark_unequippable_items(TWindowSubEquipKind *window);

#endif
