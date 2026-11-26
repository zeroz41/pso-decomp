#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_802671F0_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_802671F0_H

#include "types.h"

class TWindowBase;
class TWindowMenuIconLine;
struct NJS_POINT2;
struct WindowDrawContext;

void draw_item_list_capacity(void *, WindowDrawContext *context, s32 current_items, s32 capacity);
extern "C" {
void TAdVIConfigGC__sub_80267704(s32 arg0);
TWindowMenuIconLine *create_menu_icon_line(saddr parent, saddr position, uaddr count, s16 client);
}
void set_menu_icon_line_params(const NJS_POINT2 *size, s32 count);

#endif
