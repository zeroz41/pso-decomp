#ifndef PSO_PLAYER_PLAYERSTATE_H
#define PSO_PLAYER_PLAYERSTATE_H

#include "types.h"

struct Vec;

extern "C" {
void TObjPlayer__sub_801BF8F8(s32 *p);
Vec *TObjPlayer__sub_801BF914(Vec *position);
void set_equip_slot_entry(saddr slots, s32 slot, s32 item);
void TObjPlayer__sub_801BF954(void *p, s32 v);
s32 TObjPlayer__sub_801BF95C(void *p);
void *TObjPlayer__sub_801BFAD4(void *timer, s16 flags);
void TObjPlayer__sub_801BFB4C(Vec *position);
void TObjPlayer__sub_801BFF80(u8 *arg0);
s32 TObjPlayer__sub_801BFFA0(void *p);
}

#endif
