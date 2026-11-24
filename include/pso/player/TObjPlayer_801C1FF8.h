#ifndef PSO_PLAYER_TOBJPLAYER_801C1FF8_H
#define PSO_PLAYER_TOBJPLAYER_801C1FF8_H

#include "types.h"
#include "pso/player/PlayerTelepipe.h"

extern "C" {
s32 is_field_0_positive(s32 *arg0);
void *get_ptr_8(void *p);
void set_field_0_s32(void *p, s32 v);
u8 get_byte_1ab(void *p);
u8 get_byte_18f(void *p);
u8 get_byte_173(void *p);
void *fn_801C2308(void *arg0, s16 arg1);
void *fn_801C2360(void *arg0);
// No telepipe: owner 0xFFFF, floor 0, at the origin.
PlayerTelepipe *init_player_telepipe_record(PlayerTelepipe *telepipe);
}

#endif
