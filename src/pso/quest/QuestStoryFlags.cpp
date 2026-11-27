#include "types.h"
#include <string.h>
#include "pso/quest/QuestStoryFlags.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/network/TLobby.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/ui/hud/SplitScreenQuery.h"

u8 quest_story_flags_by_difficulty[4][128];

void save_quest_story_flags(void) {
    CharacterSaveRecord *character_save_record;

    if ((get_main_phase() != 0xF) && (is_not_split_screen() != 1)) {
        if (is_quest_active() != 0) {
            THunterGuildSeqOffline::notify_quest_thread();
        }
        character_save_record = get_character_save_record(0);
        if (character_save_record != NULL) {
            memcpy(character_save_record->quest_story_flags, quest_story_flags_by_difficulty, sizeof(character_save_record->quest_story_flags));
        }
    }
}

s32 get_story_flag_in_bank(s32 bank, s32 flag) {
    s32 v;
    s32 bit;
    s32 byteIdx;
    s32 shift;

    if (flag < 0 || flag > 0x3FF) return -1;
    if (bank < 0 || bank >= 4) return -1;
    v = flag + 1;
    byteIdx = v / 8;
    bit = v % 8;
    if (bit > 0) {
        shift = 8 - bit;
        return (quest_story_flags_by_difficulty[bank][byteIdx] & (1 << shift)) >> shift;
    }
    return quest_story_flags_by_difficulty[bank][byteIdx - 1] & 1;
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

void clear_story_flag_in_bank(s32 bank, s32 flag) {
    s32 v;
    s32 bit;
    s32 byteIdx;
    if (flag < 0 || flag > 0x3FF) return;
    if (bank < 0 || bank >= 4) return;
    v = flag + 1;
    byteIdx = v / 8;
    bit = v % 8;
    if (bit > 0) {
        quest_story_flags_by_difficulty[bank][byteIdx] &= ~(1 << (8 - bit));
        return;
    }
    quest_story_flags_by_difficulty[bank][byteIdx - 1] &= 0xFE;
}

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

void set_story_flag_in_bank(s32 bank, s32 flag) {
    s32 v;
    s32 bit;
    s32 byteIdx;
    if (flag < 0 || flag > 0x3FF) return;
    if (bank < 0 || bank >= 4) return;
    v = flag + 1;
    byteIdx = v / 8;
    bit = v % 8;
    if (bit > 0) {
        quest_story_flags_by_difficulty[bank][byteIdx] |= 1 << (8 - bit);
        return;
    }
    quest_story_flags_by_difficulty[bank][byteIdx - 1] |= 1;
}

void set_story_flag_in_bank_or_send_quest_flag(s32 bank, s32 flag) {
    if (get_main_phase() == 0xF) {
        send_6x75_quest_flag(flag, 0, bank);
        return;
    }
    set_story_flag_in_bank(bank, flag);
}

void set_story_flag(s32 flag) {
    s32 v;
    s32 bit;
    s32 byteIdx;
    if (flag < 0 || flag > 0x3FF) return;
    if (game_difficulty_selection < 0 || game_difficulty_selection >= 4) return;
    v = flag + 1;
    byteIdx = v / 8;
    bit = v % 8;
    if (bit > 0) {
        quest_story_flags_by_difficulty[game_difficulty_selection][byteIdx] |= 1 << (8 - bit);
        return;
    }
    quest_story_flags_by_difficulty[game_difficulty_selection][byteIdx - 1] |= 1;
}

void set_story_flag_or_send_quest_flag(s32 flag) {
    if (get_main_phase() == 0xF) {
        send_6x75_quest_flag_cur_difficulty(flag, 0);
        return;
    }
    set_story_flag(flag);
}

const s32 lobby_story_flag_clear_list[6] = { 151, 152, 153, 154, -1, 0 };

void load_view_player_story_flags(void) {
    if (is_not_split_screen() == 1) {
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
    CharacterSaveRecord *character_save_record;
    character_save_record = get_character_save_record(client);
    if (character_save_record != NULL) {
        memcpy(quest_story_flags_by_difficulty, character_save_record->quest_story_flags, sizeof(character_save_record->quest_story_flags));
    }
}

void clear_all_story_flags(void) {
    memset(quest_story_flags_by_difficulty, 0, 0x200);
}
