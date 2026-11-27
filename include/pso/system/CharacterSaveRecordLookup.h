#ifndef PSO_SYSTEM_CHARACTER_SAVE_RECORD_LOOKUP_H
#define PSO_SYSTEM_CHARACTER_SAVE_RECORD_LOOKUP_H

#include "types.h"
#include <stddef.h>
#include "pso/quest/challenge/ChallengeRecord.h"
#include "pso/ui/city/BankItemRecord.h"
#include "pso/system/ChoiceSearchSelection.h"
#include "pso/ui/chat/SymbolChatPreset.h"
#include "pso/ui/chat/ChatShortcut.h"

// A character's battle mode results: wins in each place (first to fourth) and battles left early.
// The client keeps the remaining counts and values only to send them on.
struct BattleRecord {
    u16 place_counts[4];
    u16 disconnect_count;
    u16 reserved_counts[3];
    u32 reserved_values[2];
    u8 pad_18[0x1C - 0x18];
};

LAYOUT_ASSERT(BattleRecord_size, sizeof(BattleRecord) == 0x1C);


// The parts of a character's save record that are read by name.
struct CharacterSaveRecord {
    CharacterSaveRecord();
    // Whether every row of bank_items is in use.
    s32 is_bank_full();
    // Whether the bank holds an item of the same kind as item.
    s32 find_bank_item(TItemData *item);
    // Puts item in the first free bank row; 0 when the bank is full.
    s32 register_in_free_room_slot(TItemData *item);

    s32 flags;              // set_global_flags / clear_flags / check_flag
    s32 creation_seconds;   // when the character was made; tells two records of one slot apart
    u32 magic;              // 0xA205B064 once the slot holds a character
    // Seconds played; update_elapsed_time adds the time since the character was selected.
    s32 play_time;
    s32 card_window_flags;  // test/set_card_window_flags (TWindowKeyBoardHard)
    u32 save_count;         // raised before every save; the copy with the higher count is newer
    u8 account[0x1C];       // the account's entry, copied in when the character is created
    u8 user_name[0x10];
    // The story flags of each difficulty; save_quest_story_flags and load_quest_story_flags copy
    // quest_story_flags_by_difficulty to and from here.
    u8 quest_story_flags[4][0x80];
    s32 death_count;        // raised when a local player dies (enter_death_state)
    s32 bank_item_count;    // rows of bank_items in use
    s32 bank_meseta;        // meseta kept in the bank
    BankItemRecord bank_items[200];
    // The player's own GuildCardEntry (set_com_card_window fills it); set up by init_guild_card_tag.
    u8 guild_card[0x90];
    SymbolChatPreset symbol_chat_presets[12];
    ChatShortcut chat_shortcuts[20];
    char short_mail_text[0xAC];   // the auto-reply text
    char info_board_text[0xAC];
    // Battle results sent with the character data (61/98) and shown in the lobby.
    BattleRecord online_battle;
    // Challenge mode records; the 6x7C packet carries a copy.
    ChallengeRecord challenge;
    s16 short_list_order[0x14];   // filled by init_default_short_list_order
    // Choice search settings, sent in C2/C3 and with the character data.
    ChoiceSearchSelections choice_search;
    s32 quest_counters[16];  // the quest counter opcodes (write_counter, read_counter) read and write these
    // Split-screen battles finished in each place (first to fourth), and battles left early.
    BattleRecord split_screen_battle;
};

LAYOUT_ASSERT(CharacterSaveRecord_online_battle, offsetof(CharacterSaveRecord, online_battle) == 0x21A8);
LAYOUT_ASSERT(CharacterSaveRecord_challenge, offsetof(CharacterSaveRecord, challenge) == 0x21C4);
LAYOUT_ASSERT(CharacterSaveRecord_choice_search, offsetof(CharacterSaveRecord, choice_search) == 0x22EC);
LAYOUT_ASSERT(CharacterSaveRecord_quest_counters, offsetof(CharacterSaveRecord, quest_counters) == 0x2314);
LAYOUT_ASSERT(CharacterSaveRecord_chat_shortcuts, offsetof(CharacterSaveRecord, chat_shortcuts) == 0x19C0);
LAYOUT_ASSERT(CharacterSaveRecord_split_screen_battle, offsetof(CharacterSaveRecord, split_screen_battle) == 0x2354);
LAYOUT_ASSERT(CharacterSaveRecord_size, sizeof(CharacterSaveRecord) == 0x2370);

// In split screen the record of player `client` (0xFFFF: the first player), otherwise the active
// character's record.
CharacterSaveRecord *get_character_save_record(u32 client);

// The decoded challenge rank title of the record get_character_save_record(0xFFFF) returns, in a
// shared buffer.
char *get_active_challenge_title();

#endif
