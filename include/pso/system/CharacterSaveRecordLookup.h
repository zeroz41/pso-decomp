#ifndef PSO_SYSTEM_CHARACTER_SAVE_RECORD_LOOKUP_H
#define PSO_SYSTEM_CHARACTER_SAVE_RECORD_LOOKUP_H

#include "types.h"

// The parts of a character's save record that are read by name.
struct CharacterSaveRecord {
    u8 pad_0[0x229C];
    // The character's name as stored, obfuscated; read it with decode_obfuscated_string.
    char name[12];
};

// In split screen the record of player `client` (0xFFFF: the first player), otherwise the active
// character's record.
extern "C" saddr get_character_save_record(u32 client);

// The decoded name of the character get_character_save_record(0xFFFF) returns, in a shared buffer.
char *get_active_character_name();

#endif
