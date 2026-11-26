#ifndef PSO_UI_KEYBOARD_KEYBOARDMENU_H
#define PSO_UI_KEYBOARD_KEYBOARDMENU_H

#include "types.h"

const char *get_localized_text_entry(s32 group, s32 id);
void free_keyboard_soft_resources();
void update_menu_cursor();
void update_keyboard_menu();

#endif
