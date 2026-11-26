#ifndef PSO_ENEMY_ENEMYSTATESYNC_H
#define PSO_ENEMY_ENEMYSTATESYNC_H

#include "types.h"

struct TObjEnemy;
struct G_UpdateEnemyState_6x0A;
struct G_SetEnemyLowGameFlagsUltimate_6x9C;

f32 get_challenge4p_exp_multiplier(void);
f32 get_challenge_exp_multiplier(void);
int get_attack_credit_slot_count(TObjEnemy *enemy);
void init_6x0A_enemy_state_packet(G_UpdateEnemyState_6x0A *packet);
void init_6x9C_enemy_low_game_flags_packet(G_SetEnemyLowGameFlagsUltimate_6x9C *packet);
s32 load_current_floor_resources(void);
s32 load_floor_resources(s32 selector);
void unload_current_floor_resources(void);
void unload_floor_resources(s32 selector);

// --- C functions defined in EnemyStateSync.cpp ---
f32 get_challenge4p_exp_multiplier(void);
f32 get_challenge_exp_multiplier(void);
int get_attack_credit_slot_count(TObjEnemy *enemy);
// --- end of C functions

#endif
