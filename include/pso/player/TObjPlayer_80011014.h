#ifndef PSO_PLAYER_TOBJPLAYER_80011014_H
#define PSO_PLAYER_TOBJPLAYER_80011014_H

#include "pso/enemy/EnemyTargeting.h"
#include "types.h"

struct Vec;
struct TObjEnemy;
class TObjBase;
class TObjChara;
struct EnemyMoveParams;

extern "C" {
void obj_setFlags30(void *object, u32 flags);
void clear_velocity(u8 *arg0);
s16 TObjPlayer__sub_800194E8(void *p);
void TObjPlayer__sub_8001951C(void *p);
s32 TObjectV8047c128_subtract_hp(u8 *owner, s16 arg1);
void activate_switch_attacks__10TObjPlayerFii(saddr arg0, saddr arg1);
s32 add_actor_hp(u8 *arg0, s16 amount);
s32 add_actor_tp(u8 *owner, s16 half);
void add_id_to_slots__10TObjPlayerFiUs(s32 arg0, u16 arg1);
}
void apply_actor_gravity(TObjEnemy *enemy, s32 *arg1, f32 hover_height);
extern "C" {
void assign_slots_from_list(void *arg0, saddr arg1);
f32 atan2_float(f32 y, f32 x);
void attach_mine_trap__10TObjPlayerFiUi(saddr arg0, u32 arg1);
f32 calc_random_ratio__10TObjPlayerFv(void);
f32 calc_xz_distance_sq(TObjBase *actor, TObjBase *other, Vec *offset);
s32 check_can_act__10TObjPlayerFii(saddr player, s32 dmg);
s32 copy_position_if_valid__10TObjPlayerFii(s32 arg0, s32 arg1);
s32 damage_hp__10TObjPlayerFii(saddr arg0, saddr arg1);
}
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
extern "C" {
f32 fabs_float(f32 x);
u16 fn_80010F4C(void *p);
s16 get_attack_params_atp_max(void *p);
s16 get_attack_params_atp_min(void *p);
s32 get_current_floor(void);
int get_player_data__10TObjPlayerFi(int a0);
s32 get_type__10TObjPlayerFPv(void *p);
BOOL is_split_screen(void);
void main(void);
// The frame counter main advances once a frame.
extern s32 actor_frame_tick;
f32 newton_sqrtf(f32 x);
int obj_getPtr2B0_20(u8 *p);
s16 obj_getS16_2BA(u8 *p);
s16 get_actor_hp__9TObjCharaFv(void *object);
s16 get_actor_tp(void *object);
s32 obj_is_hit_receivable(u8 *target);
void play_shock_feedback__10TObjPlayerFii(saddr arg0, s32 arg1);
void show_meseta_label(saddr arg0, u32 arg1, s32 arg2, s32 arg3);
void spawn_poison_effect__10TObjPlayerFii(saddr arg0, s32 arg1);
void spawn_slow_effect__10TObjPlayerFii(saddr arg0, s32 arg1);
s32 try_spend_actor_meseta(u8 *player, s32 count);
s32 update_slow_status__9TObjCharaFv(u8 *player);
s32 update_attack_stat_status__9TObjCharaFv(u8 *player);
void calc_velocity_toward_destination(TObjEnemy *enemy, Vec from, Vec to, f32 speed);
// 1 when csnLookAt finds a wall between the body centre and `target` (a far target is
// pulled in to 300 units along the same heading), else 0.
s32 check_path_obstructed(TObjChara *chara, Vec *target);
// Turns rotation_y half way toward move_destination.
void enemy_turn_half_toward_dest(TObjChara *chara);
f32 update_enemy_wander_move(TObjEnemy *enemy, Vec *dest, s32 mode, EnemyMoveParams *params, f32 min_distance);
s32 enemy_turn_toward_dest__9TObjEnemyFl(TObjEnemy *enemy, s32 turn_speed);
u16 get_entity_id(TObjBase *object);
}

void move_with_wall_slide(u8 *actor);

#endif
