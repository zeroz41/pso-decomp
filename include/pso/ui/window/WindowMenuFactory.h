#ifndef PSO_UI_WINDOW_WINDOWMENUFACTORY_H
#define PSO_UI_WINDOW_WINDOWMENUFACTORY_H

#include "types.h"

struct NJS_POINT2;
struct TWindowMenu;
TWindowMenu *create_window_menu(const NJS_POINT2 *position, s32 count, s32 client_id);
TWindowMenu *create_yes_no_window(const NJS_POINT2 *position, s32 id, const char *yes_text, const char *no_text);

#endif
