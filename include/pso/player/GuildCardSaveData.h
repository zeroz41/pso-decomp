#ifndef PSO_PLAYER_GUILDCARDSAVEDATA_H
#define PSO_PLAYER_GUILDCARDSAVEDATA_H

#include "types.h"
#include "pso/player/GuildCardEntry.h"

// The guild card file (the part after the card header): the checksum, the card list, the tag
// blocks and the cipher seed.
struct GuildCardList {
    GuildCardList();
    u8 pad_0[0xC0];
    GuildCardSlot entries[0xD2];
};

struct GuildCardTags {
    GuildCardTags();
    GuildCardEntry entries[0x1C];
};

struct GuildCardSaveData {
    GuildCardSaveData();
    u32 checksum;
    GuildCardList list;
    GuildCardTags tags;
    s32 timestamp_seconds;
    s32 cipher_seed;
};

LAYOUT_ASSERT(GuildCardSaveData_size, sizeof(GuildCardSaveData) == 0xE28C);

#endif
