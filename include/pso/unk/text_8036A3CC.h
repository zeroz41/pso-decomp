#ifndef PSO_UNK_TEXT_8036A3CC_H
#define PSO_UNK_TEXT_8036A3CC_H

#include "types.h"

// --- C functions defined in text_8036A3CC.cpp ---
extern "C" {
u32 *get_flag_word_mask(s32 arg0, u32 *mask);
void unlock_sequencer_flag(s32 arg0);
void unlock_music_flag(s32 flag);
s32 check_flag_index_set(s32 arg0);
s32 is_music_flag_unlocked_stub(s32 idx);
s32 get_bgm_filename(s32 arg0);
}
// --- end of C functions

s32 get_option_table_entry(s32 arg0);

#endif
