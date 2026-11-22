#ifndef PSO_SYSTEM_ITEMEFFECTS_H
#define PSO_SYSTEM_ITEMEFFECTS_H

#include "types.h"

u8 *construct_item_follow_effect(u8 *arg0, saddr arg1, saddr arg2, s32 arg3, s32 arg4);
void *destroy_item_follow_effect(void *arg0, s16 arg1);
void spawn_item_follow_effect(saddr arg0, uaddr arg1, s32 arg2, s32 arg3);


#endif
