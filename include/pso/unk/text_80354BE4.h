#ifndef PSO_UNK_TEXT_80354BE4_H
#define PSO_UNK_TEXT_80354BE4_H

#include "types.h"

extern "C" {
void run_palettex_callback(u16 client_index);
void set_palettex_callback(u16 client_index, s32 arg1);
u8 TObjPlayer__sub_80354C7C(u16 client_index);
void TObjPlayer__sub_80354CCC(u16 client_index);
void TObjPlayer__sub_80354D14(u16 client_index);
s32 is_palettex_activated(u16 client_index);
void TObjPlayer__sub_80354DAC(u16 client_index);
void activate_palettex(u16 client_index);
s32 is_local_client(u16 client_index);
void reset_client_quest_slot_table(void);
}

#endif
