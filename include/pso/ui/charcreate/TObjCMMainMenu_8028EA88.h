#ifndef PSO_UI_CHARCREATE_TOBJCMMAINMENU_8028EA88_H
#define PSO_UI_CHARCREATE_TOBJCMMAINMENU_8028EA88_H

#include "types.h"

class TObjCMMainMenu;
struct BmlResource;

extern "C" {
extern BmlResource *creation_menu_main_obj;
s32 get_selected_menu_entry_kind(TObjCMMainMenu *menu);
void enable_dressing_room_mode(void);
void clear_creation_name_buffer(void);
void disable_dressing_room_mode(void);
}
void init_creation_menu_scene(void);
// The name typed on the creation name screen.
extern char character_creation_name_buffer[0x18];
// Set while character creation runs as the dressing room.
extern int creation_dressing_room_mode_flag;

#endif
