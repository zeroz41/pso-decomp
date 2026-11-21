#ifndef PSO_UNK_TEXT_80354BE4_H
#define PSO_UNK_TEXT_80354BE4_H

#include "types.h"

extern "C" {
void finish_client_quest_thread(s32 arg0);
void set_client_quest_slot_player_index(s32 arg0, s32 arg1);
u8 test_client_quest_slot_bits01(s32 arg0);
void clear_client_quest_slot_bit1(s32 arg0);
void set_client_quest_slot_bits01(s32 arg0);
s32 test_client_quest_slot_lock_flag(s32 arg0);
void clear_client_quest_slot_bits01(s32 arg0);
void set_client_quest_slot_flag1(s32 arg0);
s32 is_client_quest_slot_local(s32 arg0);
void reset_client_quest_slot_table(void);
}

#endif
