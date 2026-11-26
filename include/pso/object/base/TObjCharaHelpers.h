#ifndef PSO_OBJECT_BASE_TOBJCHARAHELPERS_H
#define PSO_OBJECT_BASE_TOBJCHARAHELPERS_H

#include "pso/enemy/EnemyTargeting.h"
#include "pso/object/base/HitEligibility.h"
#include "types.h"
#include "pso/system/SubtractiveRng.h"
#include "pso/unk/TLobby_800FD78C.h"

struct Vec;
struct TObjEnemy;
class TObjBase;
class TObjChara;

void apply_actor_gravity(TObjEnemy *enemy, s32 *ground_position, f32 hover_height);
f32 atan2_float(f32 y, f32 x);
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
f32 fabs_float(f32 x);
s32 get_current_floor(void);
BOOL is_split_screen(void);
void main(void);
f32 newton_sqrtf(f32 x);
// Floating damage/heal numbers over a character: green HP, blue TP, yellow meseta and
// magenta EXP, shown at `pos`.
void display_exp_gain(TObjChara *chara, Vec *pos, s32 delay, s16 value);
void show_meseta_label(TObjChara *chara, Vec *pos, s32 delay, s16 value);
void show_tp_font(TObjChara *chara, Vec *pos, s32 delay, s16 value);
void draw_hp_label(TObjChara *chara, Vec *pos, s32 delay, s16 value);

// 1 when csnLookAt finds a wall between the body centre and `target` (a far target is
// pulled in to 300 units along the same heading), else 0.
s32 check_path_obstructed(TObjChara *chara, Vec *target);
// Turns rotation_y half way toward move_destination.
void enemy_turn_half_toward_dest(TObjChara *chara);

#endif
