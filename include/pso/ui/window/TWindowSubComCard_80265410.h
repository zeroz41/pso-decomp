#ifndef PSO_UI_WINDOW_TWINDOWSUBCOMCARD_80265410_H
#define PSO_UI_WINDOW_TWINDOWSUBCOMCARD_80265410_H

#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"

struct NJS_POINT2;
struct TWindowMenu;
extern "C" {
void TWindowSubComCard__sub_80265500(TWindowMenu *menu);
void TWindowSubComCard__sub_80265680(TWindowMenu *menu, s16 row);
}
TWindowMenu *create_titled_window_menu(const NJS_POINT2 *position, s32 count, saddr title, s32 client_id);
TWindowMenu *create_window_menu_default(const NJS_POINT2 *pos, s32 entries);
TWindowMenu *create_titled_window_menu_default(const NJS_POINT2 *pos, s32 entries, saddr title);
extern "C" {
void fn_80266378(s32 rows);
}
u8 *init_shop_judgment_window(void *p);

#endif
