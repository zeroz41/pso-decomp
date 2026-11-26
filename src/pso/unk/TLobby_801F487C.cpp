#include "pso/system/CharacterSaveRecordLookup.h"
#include "types.h"
#include <string.h>
#include "pso/quest/QuestStoryFlags.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/hud/TRaderMapCore.h"

const s32 lobby_story_flag_clear_list[6] = { 151, 152, 153, 154, -1, 0 };

void load_view_player_story_flags(void) {
    if (TRaderMapCore::is_not_split_screen() == 1) {
        load_quest_story_flags(TCameraCtrl::get_nth_view_player_id(0));
    }
}

void clear_story_flag_list(void) {
    s32 i;
    for (i = 0; lobby_story_flag_clear_list[i] != -1; i++) {
        clear_story_flag(lobby_story_flag_clear_list[i]);
    }
}

void clear_story_flag_list_and_reload(void) {
    s32 i;
    for (i = 0; lobby_story_flag_clear_list[i] != -1; i++) {
        clear_story_flag(lobby_story_flag_clear_list[i]);
    }
    load_view_player_story_flags();
}

void load_quest_story_flags(u16 client) {
    uaddr character_save_record;
    character_save_record = get_character_save_record(client);
    if (character_save_record != 0U) {
        memcpy(quest_story_flags_by_difficulty, (void *)(character_save_record + 0x44), 0x200);
    }
}
