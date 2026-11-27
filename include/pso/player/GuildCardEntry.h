#ifndef PSO_PLAYER_GUILDCARDENTRY_H
#define PSO_PLAYER_GUILDCARDENTRY_H

#include <stddef.h>
#include "types.h"
#include "pso/player/TPlyGuildCardTag.h"

// One guild card: the owner's tag and card number, name, description and flags.
struct GuildCardEntry {
    s32 get_card_id() const;
    char *get_name();
    int is_active() const;
    s8 get_char_class();
    s8 get_language();
    s8 get_section_id();
    // The card description the com card keyboard edits.
    char *get_text();
    // 1 unless flag 2 is set; cards filled from a short mail or another player get flags 3, the
    // player's own card (fill_from_char) only flag 1.
    s32 is_own_card() const;
    // Fills the card with the name, class and section id of the character in save slot index, the
    // current language and this console's guild card tag.
    void fill_from_char(s32 index);
    void clear();
    void clear_and_fill_from_char(s32 index);
    // Copies src into the card description, cut to fit.
    void set_text(const char *src);
    // Updates the matching card of the guild card file (update_matching_card); 1 if the file has it.
    s32 update_in_card_file();
    void bswap();

    TPlyGuildCardTag tag;
    char name[0x18];
    char text[0x6C];
    s8 flags;
    s8 language;  // index of the Jpn./Eng./Ger./Fr./Span. label
    s8 section_id;
    s8 char_class;
};

LAYOUT_ASSERT(GuildCardEntry_size, sizeof(GuildCardEntry) == 0x90);
LAYOUT_ASSERT(GuildCardEntry_name_offset, offsetof(GuildCardEntry, name) == 8);
LAYOUT_ASSERT(GuildCardEntry_flags_offset, offsetof(GuildCardEntry, flags) == 0x8C);

struct GuildCardNote {
    char text[0x6C];
};

// Inferred name: the base GuildCardSlot derives from. It adds nothing to GuildCardEntry, but it
// has its own generated assignment and constructor between the slot's and the entry's.
struct GuildCardSlotBase : public GuildCardEntry {
};

// One card of the guild card file list (0xD2 of them): the card and the note written on it.
struct GuildCardSlot : public GuildCardSlotBase {
    u8 pad_90;
    u8 pad_91;
    u8 pad_92;
    u8 pad_93;
    GuildCardNote note;
};

LAYOUT_ASSERT(GuildCardSlotSize, sizeof(GuildCardSlot) == 0x100);
LAYOUT_ASSERT(GuildCardSlotNoteOffset, offsetof(GuildCardSlot, note) == 0x94);

// Fills a GuildCardEntry with the name, section id, class and language of the player of
// client; 0 when there is none or it has no guild card number.
s32 fill_guild_card_from_player(GuildCardEntry *card, u32 client);

#endif
