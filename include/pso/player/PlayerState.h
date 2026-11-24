#ifndef PSO_PLAYER_PLAYERSTATE_H
#define PSO_PLAYER_PLAYERSTATE_H

#include "types.h"

struct Vec;

extern "C" {
void TObjPlayer__sub_801BF8F8(s32 *p);
Vec *TObjPlayer__sub_801BF914(Vec *position);
void set_equip_slot_entry(saddr arg0, s32 val_ext, s32 arg2);
s32 TObjPlayer__sub_801BF918(u8 *arg0);
void TObjPlayer__sub_801BF954(void *p, s32 v);
s32 TObjPlayer__sub_801BF95C(void *p);
void TObjPlayer__sub_801BF9E0(void *p, u16 v);
void *TObjPlayer__sub_801BFAD4(void *arg0, s16 arg1);
void TObjPlayer__sub_801BFB4C(Vec *position);
void TObjPlayer__sub_801BFF80(u8 *arg0);
s32 TObjPlayer__sub_801BFFA0(void *p);
}

#endif
