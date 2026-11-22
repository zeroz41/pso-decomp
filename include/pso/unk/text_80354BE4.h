#ifndef PSO_UNK_TEXT_80354BE4_H
#define PSO_UNK_TEXT_80354BE4_H

#include "types.h"

extern "C" {
void run_palettex_callback(s32 arg0);
void set_palettex_callback(s32 arg0, s32 arg1);
u8 TObjPlayer__sub_80354C7C(s32 client_index);
void TObjPlayer__sub_80354CCC(s32 arg0);
void TObjPlayer__sub_80354D14(s32 arg0);
s32 is_palettex_activated(s32 client_index);
void TObjPlayer__sub_80354DAC(s32 arg0);
void activate_palettex(s32 arg0);
s32 is_local_client(s32 arg0);
void reset_client_quest_slot_table(void);
}

#endif
