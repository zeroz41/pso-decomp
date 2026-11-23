#ifndef PSO_SYSTEM_CHARACTER_SAVE_RECORD_LOOKUP_H
#define PSO_SYSTEM_CHARACTER_SAVE_RECORD_LOOKUP_H

#include "types.h"
#include "pso/ui/city/BankItemRecord.h"

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
    s32 register_in_free_room_slot(saddr item);

    u8 pad_0[0x4];
    s32 pad_4;
    u8 pad_8[0x4];
    // Seconds played; update_elapsed_time adds the time since the character was selected.
    s32 play_time;
    u8 pad_10[0x4];
    u32 pad_14;
    u8 pad_18[0x248 - 0x18];
    s32 bank_item_count;    // rows of bank_items in use
    s32 pad_24C;
    BankItemRecord bank_items[200];
    // Set up by init_guild_card_tag.
    u8 guild_card[0x229C - 0x1510];
    // The character's name as stored, obfuscated; read it with decode_obfuscated_string.
    char name[12];
    u8 pad_22A8[0x2370 - 0x22A8];
};

// In split screen the record of player `client` (0xFFFF: the first player), otherwise the active
// character's record.
extern "C" saddr get_character_save_record(u32 client);

// The decoded name of the character get_character_save_record(0xFFFF) returns, in a shared buffer.
char *get_active_character_name();

#endif
