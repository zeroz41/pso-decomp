#ifndef PSO_UI_WINDOW_TWINDOWSUBCOMCARD_8007A810_H
#define PSO_UI_WINDOW_TWINDOWSUBCOMCARD_8007A810_H

#include "types.h"
#include "pso/player/GuildCardEntry.h"

extern "C" {
void TWindowSubComCard__sub_8007AF10(saddr client_id);
u32 TWindowSubComCard__sub_8007B070(u8 *keyboard_mode);
void replace_matching_card(GuildCardSlotBase *card, GuildCardSlotBase *entries, s32 count);
int clear(void *p);
s32 fn_8007B2E0(u8 *ply_guild_card_tag, s32 id);
void forward_to_matching_card__17TWindowSubComCardFPvPvi(GuildCardSlotBase *card, GuildCardSlot *slots, s32 count);
}


extern "C" {
void __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(void *arg0, void *src);
void remove_first_received_card(void);
GuildCardEntry *get_received_guild_card_tags(void);
void clear_received_guild_cards(s32 _w0);
void TWindowGetComCard__sub_8007B65C(void *p);
void TWindowGetComCard__sub_8007B67C(void *p);
}

extern GuildCardEntry TWindowGetComCard__received_guild_card_tags[4];
extern s32 com_card_keyboard_mode;

#endif
