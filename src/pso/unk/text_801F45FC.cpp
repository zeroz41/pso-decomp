#include "types.h"
#include "pso/quest/QuestStoryFlags.h"
#include "pso/ui/TLevelSelect.h"
void clear_story_flag(s32 flag) {
    s32 v;
    s32 bit;
    s32 byteIdx;
    if (flag < 0 || flag > 0x3FF) return;
    if (game_difficulty_selection < 0 || game_difficulty_selection >= 4) return;
    v = flag + 1;
    byteIdx = v / 8;
    bit = v % 8;
    if (bit > 0) {
        quest_story_flags_by_difficulty[game_difficulty_selection][byteIdx] &= ~(1 << (8 - bit));
        return;
    }
    quest_story_flags_by_difficulty[game_difficulty_selection][byteIdx - 1] &= 0xFE;
}
