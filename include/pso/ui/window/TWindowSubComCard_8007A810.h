#ifndef PSO_UI_WINDOW_TWINDOWSUBCOMCARD_8007A810_H
#define PSO_UI_WINDOW_TWINDOWSUBCOMCARD_8007A810_H

#include "types.h"

extern "C" {
void TWindowSubComCard__sub_8007AF10(saddr client_id);
u32 TWindowSubComCard__sub_8007B070(u8 *keyboard_mode);
void TWindowSubComCard__sub_8007B1AC(void *ply_guild_card_tag, u8 *arg1, s32 count);
int clear(void *p);
s32 copy_card__17TWindowSubComCardFiPv(saddr dest, u8 *src);
s32 fn_8007B2E0(u8 *ply_guild_card_tag, s32 id);
void forward_to_matching_card__17TWindowSubComCardFPvPvi(void *card, u8 *slots, s32 count);
s32 init__17TWindowSubComCardFi(s32 object);
s32 init_guild_card_tag__17TWindowSubComCardFi(s32 ply_guild_card_tag);
s32 reinit__17TWindowSubComCardFi(s32 object);
}

void handle_6x06_send_guild_card(s32 packet);

#endif
