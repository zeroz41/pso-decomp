#ifndef PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_80202A68_H
#define PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_80202A68_H

#include "types.h"
#include <stddef.h>
#include "pso/player/TPlyCharData.h"
#include "pso/ui/city/BankItemRecord.h"

struct Pso3CharacterSaveRecord {
    Pso3CharacterSaveRecord();

    u8 pad_0[0x450];
    BankItemRecord items[4];
    // Set up by init_guild_card_tag.
    u8 guild_card[0x3598 - 0x4B0];
};

struct Pso3CharacterFileSlot {
    Pso3CharacterFileSlot();
    ~Pso3CharacterFileSlot();

    TPlyCharData chardata;
    Pso3CharacterSaveRecord record;
};

struct Words_80202C68 { u32 w[32]; };

struct Blk_80202C68 { u32 a; Words_80202C68 b; };

struct Pair_80202C68 { u32 a; u32 b; };

struct Tail_80202C68 { Pair_80202C68 p0, p1, p2, p3, p4, p5, p6; };

// The PSO3_CHARACTER memory card file: seven character slots behind a CRC32.
struct Pso3CharacterFile {
    Pso3CharacterFile();
    ~Pso3CharacterFile();

    s32 checksum;
    Pso3CharacterFileSlot slots[7];
    Tail_80202C68 tail;
    Blk_80202C68 blk;
    // Seeds the cipher over everything before it.
    s32 cipher_seed;
};

LAYOUT_ASSERT(Pso3CharacterFileSlot_record_offset, offsetof(Pso3CharacterFileSlot, record) == 0x41C);
LAYOUT_ASSERT(Pso3CharacterFileSlot_size, sizeof(Pso3CharacterFileSlot) == 0x39B4);
LAYOUT_ASSERT(Pso3CharacterFile_size, sizeof(Pso3CharacterFile) == 0x194B0);

extern "C" {
s32 TAdSinglePlyChrSelectGC__sub_80202A68(u8 *file);
void *TAdSinglePlyChrSelectGC__sub_80202D7C(void *a0, void *a1);
}
void clear_equipped_flag(void *item);
int is_unit_item_data(void *entry);

#endif
