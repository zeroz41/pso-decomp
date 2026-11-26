#ifndef PSO_UI_WINDOW_TWINDOWSUBCOMCARD_80265410_H
#define PSO_UI_WINDOW_TWINDOWSUBCOMCARD_80265410_H

#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"

struct NJS_POINT2;
struct TWindowMenu;
TWindowMenu *create_titled_window_menu(const NJS_POINT2 *position, s32 count, saddr title, s32 client_id);
TWindowMenu *create_window_menu_default(const NJS_POINT2 *pos, s32 entries);
TWindowMenu *create_titled_window_menu_default(const NJS_POINT2 *pos, s32 entries, saddr title);
void set_window_menu_rows(s32 rows);
TWindowMenu *init_shop_judgment_window(void *p);

#endif
