#include "types.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/unk/text_801F43B4.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/misc/TRaderMapCore.h"

extern "C" {

int is_quest_active(void);
s32 memcpy(s32, s32 *, s32);
u8 quest_story_flags_by_difficulty[4][128];
extern s32 game_difficulty_selection;

void copy_card_window_data(void) {
    u32 character_save_record;

    if ((get_main_phase() != 0xF) && (TRaderMapCore::is_not_split_screen() != 1)) {
        if (is_quest_active() != 0) {
            THunterGuildSeqOffline::notify_quest_thread();
        }
        character_save_record = get_character_save_record(0);
        if (character_save_record != 0U) {
            memcpy(character_save_record + 0x44, (s32 *)quest_story_flags_by_difficulty, 0x200);
        }
    }
}

s32 TLevelSelect::get_difficulty_flag_bit(s32 n, s32 flag) {
    s32 v;
    s32 bit;
    s32 byteIdx;
    s32 shift;

    if (flag < 0 || flag > 0x3FF) return -1;
    if (n < 0 || n >= 4) return -1;
    v = flag + 1;
    byteIdx = v / 8;
    bit = v % 8;
    if (bit > 0) {
        shift = 8 - bit;
        return (quest_story_flags_by_difficulty[n][byteIdx] & (1 << shift)) >> shift;
    }
    return quest_story_flags_by_difficulty[n][byteIdx - 1] & 1;
}
}

s32 get_story_flag(s32 flag) {
    s32 v;
    s32 n;
    s32 byteIdx;
    s32 bit;
    s32 shift;

    if (flag < 0 || flag > 0x3FF) return -1;
    n = game_difficulty_selection;
    if (n < 0 || n >= 4) return -1;
    v = flag + 1;
    byteIdx = v / 8;
    bit = v % 8;
    if (bit > 0) {
        shift = 8 - bit;
        return (quest_story_flags_by_difficulty[n][byteIdx] & (1 << shift)) >> shift;
    }
    return quest_story_flags_by_difficulty[n][byteIdx - 1] & 1;
}
