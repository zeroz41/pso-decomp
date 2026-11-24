#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_802671F0_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_802671F0_H

#include "types.h"

class TWindowBase;
class TWindowMenuIconLine;
struct NJS_POINT2;
struct WindowDrawContext;

extern "C" {
void draw_item_list_capacity(void *, WindowDrawContext *context, s32 current_items, s32 capacity);
void TAdVIConfigGC__sub_80267704(s32 arg0);
TWindowMenuIconLine *fn_80267F38(saddr parent, saddr position, uaddr count, s16 client);
void TShopJudgmentItemWindow__sub_80267F9C(const NJS_POINT2 *size, s32 count);
}

#endif
