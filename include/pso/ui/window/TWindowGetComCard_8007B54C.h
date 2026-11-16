#ifndef PSO_UI_WINDOW_TWINDOWGETCOMCARD_8007B54C_H
#define PSO_UI_WINDOW_TWINDOWGETCOMCARD_8007B54C_H

#include "types.h"

extern "C" {
void TWindowGetComCard__sub_8007B54C(void);
s32 *TWindowGetComCard__sub_8007B594(void);
void TWindowGetComCard__sub_8007B60C(s32 _w0);
void TWindowGetComCard__sub_8007B65C(void *p);
void TWindowGetComCard__sub_8007B67C(void *p);
}

// --- C functions defined in TWindowGetComCard_8007B54C.cpp ---
extern "C" {
void TWindowGetComCard__sub_8007B54C(void);
s32 *TWindowGetComCard__sub_8007B594(void);
void TWindowGetComCard__sub_8007B60C(s32 _w0);
void TWindowGetComCard__sub_8007B65C(void *p);
void TWindowGetComCard__sub_8007B67C(void *p);
}
// --- end of C functions

// TWindowGetComCard__received_guild_card_tags: layout known from its uses only.
struct TWindowGetComCardReceivedGuildCardTags { s32 value; u8 remaining[0x23C]; };
extern TWindowGetComCardReceivedGuildCardTags TWindowGetComCard__received_guild_card_tags;

#endif
