#ifndef PSO_UI_WINDOW_TWINDOWKEYBOARDHARD_801FBA48_H
#define PSO_UI_WINDOW_TWINDOWKEYBOARDHARD_801FBA48_H

#include "types.h"

void delete_character_save_file(void);
void delete_guild_card_save_file(void);
void decrypt_character_save(void *save_data);
struct NJS_OBJECT;

void draw_ginja_box_tree(NJS_OBJECT *node);

#endif
