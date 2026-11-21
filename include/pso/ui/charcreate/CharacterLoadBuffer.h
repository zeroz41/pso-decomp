#ifndef PSO_UI_CHARCREATE_CHARACTERLOADBUFFER_H
#define PSO_UI_CHARCREATE_CHARACTERLOADBUFFER_H

#include "types.h"

extern "C" {
extern u8 *chr_select_load_buffer_base;
extern u8 *chr_select_load_buffer;
uaddr reset_character_load_buffer(s32 slot);
uaddr advance_character_load_buffer(s32 slot, s32 size);
void *get_character_load_buffer(s32 slot);
}

#endif
