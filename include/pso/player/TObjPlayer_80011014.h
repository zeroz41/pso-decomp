#ifndef PSO_PLAYER_TOBJPLAYER_80011014_H
#define PSO_PLAYER_TOBJPLAYER_80011014_H

#include "pso/enemy/EnemyTargeting.h"
#include "pso/object/base/HitEligibility.h"
#include "types.h"
#include "pso/system/SubtractiveRng.h"
#include "pso/unk/TLobby_800FD78C.h"

struct Vec;
struct TObjEnemy;
class TObjBase;
class TObjChara;

extern "C" {
void clear_velocity(u8 *arg0);
s32 TObjectV8047c128_subtract_hp(u8 *owner, s16 arg1);
void activate_switch_attacks__10TObjPlayerFii(saddr arg0, saddr pos);
}
void apply_actor_gravity(TObjEnemy *enemy, s32 *arg1, f32 hover_height);
extern "C" {
void assign_slots_from_list(void *arg0, saddr arg1);
f32 atan2_float(f32 y, f32 x);
void attach_mine_trap__10TObjPlayerFiUi(saddr object, u32 arg1);
s32 damage_hp__10TObjPlayerFii(saddr arg0, saddr arg1);
}
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
extern "C" {
f32 fabs_float(f32 x);
s16 get_attack_params_atp_max(void *p);
s16 get_attack_params_atp_min(void *p);
s32 get_current_floor(void);
int get_player_data__10TObjPlayerFi(int a0);
s32 get_type__10TObjPlayerFPv(void *p);
BOOL is_split_screen(void);
void main(void);
f32 newton_sqrtf(f32 x);
int obj_getPtr2B0_20(u8 *p);
s16 obj_getS16_2BA(u8 *p);
s16 get_actor_hp__9TObjCharaFv(void *object);
s16 get_actor_tp(void *object);
void show_meseta_label(saddr player, u32 arg1, s32 arg2, s32 arg3);
s32 update_slow_status__9TObjCharaFv(u8 *player);
s32 update_attack_stat_status__9TObjCharaFv(u8 *player);
// 1 when csnLookAt finds a wall between the body centre and `target` (a far target is
// pulled in to 300 units along the same heading), else 0.
s32 check_path_obstructed(TObjChara *chara, Vec *target);
// Turns rotation_y half way toward move_destination.
void enemy_turn_half_toward_dest(TObjChara *chara);
s32 enemy_turn_toward_dest__9TObjEnemyFl(TObjEnemy *enemy, s32 turn_speed);
}

#endif
