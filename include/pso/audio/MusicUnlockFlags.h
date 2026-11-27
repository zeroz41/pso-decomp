#ifndef PSO_AUDIO_MUSICUNLOCKFLAGS_H
#define PSO_AUDIO_MUSICUNLOCKFLAGS_H

#include "types.h"

u32 *get_flag_word_mask(s32 flag, u32 *mask);
void unlock_sequencer_flag(s32 program);
void unlock_music_flag(s32 flag);
s32 check_flag_index_set(s32 flag);
s32 is_music_flag_unlocked_stub(s32 idx);
char *get_bgm_filename(s32 index);

const char *get_option_table_entry(s32 idx);

struct MusicFlagLink {
    s32 flag;
    s32 linked;
};

void update_all_zones(const char *filename);

#endif
