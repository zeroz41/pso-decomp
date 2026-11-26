#ifndef PSO_UNK_TEXT_8036A3CC_H
#define PSO_UNK_TEXT_8036A3CC_H

#include "types.h"

u32 *get_flag_word_mask(s32 flag, u32 *mask);
void unlock_sequencer_flag(s32 program);
void unlock_music_flag(s32 flag);
s32 check_flag_index_set(s32 flag);
s32 is_music_flag_unlocked_stub(s32 idx);
char *get_bgm_filename(s32 index);

s32 get_option_table_entry(s32 idx);

struct GetFlagWordMaskInst { u8 pad0[0x1155C]; u32 flags[2]; };

struct FlagLink_8036A514 {
    s32 flag;
    s32 linked;
};

#endif
