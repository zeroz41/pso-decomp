#ifndef PSO_SYSTEM_CHARACTER_SAVE_RECORD_LOOKUP_H
#define PSO_SYSTEM_CHARACTER_SAVE_RECORD_LOOKUP_H

#include "types.h"
#include "pso/ui/city/BankItemRecord.h"

// The parts of a character's save record that are read by name.
struct CharacterSaveRecord {
    CharacterSaveRecord();

    u8 pad_0[0x4];
    s32 pad_4;
    u8 pad_8[0x14 - 0x8];
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
