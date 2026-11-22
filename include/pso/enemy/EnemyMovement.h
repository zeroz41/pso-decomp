#ifndef PSO_ENEMY_ENEMYMOVEMENT_H
#define PSO_ENEMY_ENEMYMOVEMENT_H

#include "types.h"

struct Vec;
struct TObjEnemy;
class TObjChara;

extern "C" {
// Sets the velocity that carries `from` toward `to` at `speed`.
void calc_velocity_toward_destination(TObjChara *chara, Vec from, Vec to, f32 speed);
// Makes `dest` the new move_destination when it is on the ground and reachable (flags: 2 skips
// the check_path_obstructed test, 4 the csnVector line test).
s32 select_enemy_destination(TObjChara *chara, Vec dest, s32 flags);
f32 enemy_move_toward(TObjEnemy *enemy, s32 turn_speed, Vec dest, s32 flags, f32 speed);
f32 enemy_pursue_point(TObjEnemy *enemy, s32 turn_speed, Vec point, f32 speed, f32 step);
f32 enemy_backstep_from_point(TObjEnemy *enemy, Vec point, f32 speed);
f32 update_enemy_wander_move(TObjEnemy *enemy, Vec dest, s32 flags, f32 speed);
// Starts a new move at the current position when `pos` is on the ground.
s32 copy_position_if_valid(TObjChara *chara, Vec pos);
f32 step_toward_destination(TObjChara *chara, Vec dest, f32 speed);
}

#endif
