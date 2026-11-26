#ifndef PSO_SYSTEM_SAVE_CHARACTER_FILE_H
#define PSO_SYSTEM_SAVE_CHARACTER_FILE_H

#include "types.h"
#include <stddef.h>
#include "pso/player/TPlyCharData.h"
#include "pso/system/CharacterSaveRecordLookup.h"

// Marks a character copied to the other page of the file.
struct CharacterCopyStamp {
    u32 copied;      // set when the character is copied to the other page
    s32 copy_time;   // seconds at the copy; both copies of one character carry the same value
};

// One slot of the character file: the character's data and its save record.
struct CharacterFileSlot {
    CharacterFileSlot();
    ~CharacterFileSlot();

    TPlyCharData chardata;
    CharacterSaveRecord record;
    CharacterCopyStamp copy_stamp;
    u8 pad_2794[0x2798 - 0x2794];
};

// The PSO_CHARACTER memory card file: seven character slots.
struct CharacterFile {
    CharacterFile();
    ~CharacterFile();

    u32 checksum;    // CRC32 of the file, written by encrypt_save_data
    CharacterFileSlot slots[7];
    // The online registration the player entered, each a NUL-terminated string of up to 15 characters.
    char serial_number[0x10];
    char access_key[0x10];
    char password[0x10];
    u32 music_flags[2]; // songs unlocked in the options jukebox, one bit per music flag
    u32 save_count;  // raised on every save; the two cards' copies are compared by it
    s32 cipher_seed; // seeds the cipher over everything before it
};

LAYOUT_ASSERT(CharacterSaveRecord_size, sizeof(CharacterSaveRecord) == 0x2370);
LAYOUT_ASSERT(CharacterFileSlot_record_offset, offsetof(CharacterFileSlot, record) == 0x41C);
LAYOUT_ASSERT(CharacterFileSlot_size, sizeof(CharacterFileSlot) == 0x2798);
LAYOUT_ASSERT(CharacterFile_serial_number_offset, offsetof(CharacterFile, serial_number) == 0x1152C);
LAYOUT_ASSERT(CharacterFile_size, sizeof(CharacterFile) == 0x1156C);

#endif
