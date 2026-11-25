#ifndef PSO_SYSTEM_CHARACTER_SAVE_RECORD_LOOKUP_H
#define PSO_SYSTEM_CHARACTER_SAVE_RECORD_LOOKUP_H

#include "types.h"
#include <stddef.h>
#include "pso/quest/challenge/ChallengeRecord.h"
#include "pso/ui/city/BankItemRecord.h"
#include "pso/system/ChoiceSearchSelection.h"

// A character's battle mode results: wins in each place (first to fourth) and battles left early.
// The client keeps the remaining counts and values only to send them on.
struct BattleRecord {
    u16 place_counts[4];
    u16 disconnect_count;
    u16 reserved_counts[3];
    u32 reserved_values[2];
};

LAYOUT_ASSERT(BattleRecord_size, sizeof(BattleRecord) == 0x18);

struct ChatShortcutBodyCopy {
    u8 bytes[0x50];
};

struct ChatShortcutRecordCopy {
    u32 header;
    ChatShortcutBodyCopy body;
};

// The parts of a character's save record that are read by name.
struct CharacterSaveRecord {
    CharacterSaveRecord();
    // Whether every row of bank_items is in use.
    s32 is_bank_full();
    // Whether the bank holds an item of the same kind as item.
    s32 find_bank_item(saddr item);
    // Puts item in the first free bank row; 0 when the bank is full.
    s32 register_in_free_room_slot(TItemData *item);

    u8 pad_0[0x4];
    s32 pad_4;
    u8 pad_8[0x4];
    // Seconds played; update_elapsed_time adds the time since the character was selected.
    s32 play_time;
    s32 card_window_flags;  // test/set_card_window_flags (TWindowKeyBoardHard)
    u32 pad_14;
    u8 pad_18[0x248 - 0x18];
    s32 bank_item_count;    // rows of bank_items in use
    s32 pad_24C;
    BankItemRecord bank_items[200];
    // Set up by init_guild_card_tag.
    u8 guild_card[0x21A8 - 0x1510];
    // Battle results sent with the character data (61/98) and shown in the lobby.
    BattleRecord online_battle;
    u8 pad_21C0[0x21C4 - 0x21C0];
    // Challenge mode records; the 6x7C packet carries a copy.
    ChallengeRecord challenge;
    u8 pad_22C4[0x22EC - 0x22C4];
    // Choice search settings, sent in C2/C3 and with the character data.
    ChoiceSearchSelection choice_search[5];
    u8 pad_2314[0x2354 - 0x2314];
    // Split-screen battles finished in each place (first to fourth), and battles left early.
    u16 battle_place_counts[4];
    u16 battle_disconnect_count;
    u8 pad_235E[0x2370 - 0x235E];
};

LAYOUT_ASSERT(CharacterSaveRecord_online_battle, offsetof(CharacterSaveRecord, online_battle) == 0x21A8);
LAYOUT_ASSERT(CharacterSaveRecord_challenge, offsetof(CharacterSaveRecord, challenge) == 0x21C4);
LAYOUT_ASSERT(CharacterSaveRecord_choice_search, offsetof(CharacterSaveRecord, choice_search) == 0x22EC);
LAYOUT_ASSERT(CharacterSaveRecord_battle_place_counts, offsetof(CharacterSaveRecord, battle_place_counts) == 0x2354);
LAYOUT_ASSERT(CharacterSaveRecord_size, sizeof(CharacterSaveRecord) == 0x2370);

// In split screen the record of player `client` (0xFFFF: the first player), otherwise the active
// character's record.
extern "C" saddr get_character_save_record(u32 client);

// The decoded challenge rank title of the record get_character_save_record(0xFFFF) returns, in a
// shared buffer.
char *get_active_challenge_title();

#endif
