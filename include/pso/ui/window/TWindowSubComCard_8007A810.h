#ifndef PSO_UI_WINDOW_TWINDOWSUBCOMCARD_8007A810_H
#define PSO_UI_WINDOW_TWINDOWSUBCOMCARD_8007A810_H

#include "types.h"
#include "pso/player/GuildCardEntry.h"

void send_guild_card_to_client(saddr client_id);
s32 has_free_card_slot(GuildCardEntry *cards, s32 count);
s32 is_guild_card_invalid(GuildCardEntry *card);
s32 update_matching_card_slot(GuildCardSlotBase *card, GuildCardSlotBase *cards, s32 count);
void replace_matching_card(GuildCardSlotBase *card, GuildCardSlotBase *entries, s32 count);
s32 fill_guild_card_from_short_mail(GuildCardEntry *card, s32 id);
s32 has_inactive_card(GuildCardSlot *cards, s32 count);
void copy_card_to_matching_slot(GuildCardSlotBase *card, GuildCardSlot *slots, s32 count);


void remove_first_received_card(void);
GuildCardEntry *get_received_guild_card_tags(void);
void clear_received_guild_cards(void);
void free_received_guild_cards(void);
void init_received_guild_cards(void);
extern "C" {
void __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(void *dst, void *src);
}

extern GuildCardEntry *own_guild_card;

#endif
