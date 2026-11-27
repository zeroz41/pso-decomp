#ifndef PSO_UI_WINDOW_WINDOWMENUFACTORY_H
#define PSO_UI_WINDOW_WINDOWMENUFACTORY_H

#include "types.h"

struct NJS_POINT2;
struct TWindowMenu;
TWindowMenu *create_window_menu(const NJS_POINT2 *position, s32 count, s32 client_id);
TWindowMenu *create_yes_no_window(const NJS_POINT2 *position, s32 id, const char *yes_text, const char *no_text);

TWindowMenu *create_titled_window_menu(const NJS_POINT2 *position, s32 count, const char *title, s32 client_id);
TWindowMenu *create_window_menu_default(const NJS_POINT2 *pos, s32 entries);
TWindowMenu *create_titled_window_menu_default(const NJS_POINT2 *pos, s32 entries, const char *title);
void set_window_menu_rows(s32 rows);
TWindowMenu *init_shop_judgment_window(const NJS_POINT2 *p);

#endif
