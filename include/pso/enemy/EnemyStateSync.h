#ifndef PSO_ENEMY_ENEMYSTATESYNC_H
#define PSO_ENEMY_ENEMYSTATESYNC_H

#include "types.h"

struct TObjEnemy;

f32 get_challenge4p_exp_multiplier(void);
f32 get_challenge_exp_multiplier(void);
int get_attack_credit_slot_count(TObjEnemy *enemy);
void init_6x0A_enemy_state_packet(void *p);
void init_6x9C_enemy_low_game_flags_packet(u8 *packet);
s32 load_current_floor_resources(void);
s32 load_floor_resources(s32 selector);
void send_6x0A_enemy_state_packet(void *p);
void unload_current_floor_resources(void);
void unload_floor_resources(s32 selector);

// --- C functions defined in EnemyStateSync.cpp ---
f32 get_challenge4p_exp_multiplier(void);
f32 get_challenge_exp_multiplier(void);
int get_attack_credit_slot_count(TObjEnemy *enemy);
// --- end of C functions

#endif
