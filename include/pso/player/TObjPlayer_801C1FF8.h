#ifndef PSO_PLAYER_TOBJPLAYER_801C1FF8_H
#define PSO_PLAYER_TOBJPLAYER_801C1FF8_H

#include "types.h"
#include "pso/player/PlayerTelepipe.h"

class TPlyCharData;
class TPlyInventoryItem;
struct TItemData;

extern "C" {
s32 is_field_0_positive(s32 *count);
TItemData *get_ptr_8(TPlyInventoryItem *item);
void set_field_0_s32(void *p, s32 v);
u8 get_byte_1ab(const TPlyCharData *data);
u8 get_byte_18f(const TPlyCharData *data);
u8 get_byte_173(const TPlyCharData *data);
// No telepipe: owner 0xFFFF, floor 0, at the origin.
PlayerTelepipe *init_player_telepipe_record(PlayerTelepipe *telepipe);
}

#endif
