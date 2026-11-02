#ifndef PSO_ENEMY_TOBJENEDD_800BA754_H
#define PSO_ENEMY_TOBJENEDD_800BA754_H

#include "types.h"

extern "C" {
int TObjEneDD__sub_800BA804(u16 arg0);
s32 is_player_entity_id(u16 arg0);
}
void set_collider_contact_high(u8 *arg0);
void set_collider_contact_low(u8 *arg0);
void update_collider_contact_by_height(u8 *arg0, f32 farg0);

// --- C functions defined in TObjEneDD_800BA754.cpp ---
extern "C" {
int TObjEneDD__sub_800BA804(u16 arg0);
s32 is_player_entity_id(u16 arg0);
}
// --- end of C functions

#endif
