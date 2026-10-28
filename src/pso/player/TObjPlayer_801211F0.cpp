#include "types.h"
#include "pso/player/TObjPlayer_801211F0.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"



void increment_model_node_counter(void) {
    int temp_r3 = model_node_counter;
    model_node_counter = temp_r3 + 1;
}

int TObjPlayer::get_player_list() {  return model_node_counter; }

void TItemWeapon::sub_80121208(s32 v) { *(s32*)((char*)this + 0xe0) = v; }

void reset_model_node_counter(void) { model_node_counter = 0; }
