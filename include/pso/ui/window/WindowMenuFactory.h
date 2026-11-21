#ifndef PSO_UI_WINDOW_WINDOWMENUFACTORY_H
#define PSO_UI_WINDOW_WINDOWMENUFACTORY_H

#include "types.h"

struct TWindowMenu;
extern "C" {
TWindowMenu *create_window_menu(s32 position, s32 count, s32 client_id);
void align_menu_entry_positions(TWindowMenu *menu);
}

#endif
