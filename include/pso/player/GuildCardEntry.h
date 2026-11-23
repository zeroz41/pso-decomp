#ifndef PSO_PLAYER_GUILDCARDENTRY_H
#define PSO_PLAYER_GUILDCARDENTRY_H

#include <stddef.h>
#include "types.h"

struct GuildCardEntry {
    s32 get_card_id() const;
    char *get_name();
    int is_active() const;

    u8 tag[4];
    s32 id;
    char name[0x18];
    char text[0x6C];
    s8 flags;
    u8 unk_8d[3];
};

LAYOUT_ASSERT(GuildCardEntry_size, sizeof(GuildCardEntry) == 0x90);
LAYOUT_ASSERT(GuildCardEntry_id_offset, offsetof(GuildCardEntry, id) == 4);
LAYOUT_ASSERT(GuildCardEntry_name_offset, offsetof(GuildCardEntry, name) == 8);
LAYOUT_ASSERT(GuildCardEntry_flags_offset, offsetof(GuildCardEntry, flags) == 0x8C);

struct GuildCardNote {
    char text[0x6C];
};

struct GuildCardSlot {
    GuildCardEntry entry;
    u8 pad_90[4];
    GuildCardNote note;
};

LAYOUT_ASSERT(GuildCardSlotSize, sizeof(GuildCardSlot) == 0x100);
LAYOUT_ASSERT(GuildCardSlotNoteOffset, offsetof(GuildCardSlot, note) == 0x94);

#endif
