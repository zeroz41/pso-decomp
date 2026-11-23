#ifndef PSO_PLAYER_PLAYERMOVESPEED_H
#define PSO_PLAYER_PLAYERMOVESPEED_H

#include "types.h"
#include "pso/system/data/FlagWord.h"

struct TObjPlayer;

// (name inferred) A player's walk/run speed, at TObjPlayer+0x5E0: update_run_movement and
// update_walk_movement scale the heading by speed.
struct PlayerMoveSpeed {
    PlayerMoveSpeed();
    void reset();
    f32 get_speed();
    void set_speed(f32 v);
    f32 get_unscaled_speed();
    void set_unscaled_speed(f32 v);
    s32 get_run_counter();
    void set_run_counter(s32 v);
    void increment_run_counter();
    f32 calc_speed(TObjPlayer *player, f32 speed);
    f32 calc_speed(TObjPlayer *player);
    void update(TObjPlayer *player, f32 speed);
    void update(TObjPlayer *player);

    f32 speed;
    s32 run_counter;
    f32 unscaled_speed;  // (name inferred) speed before the player's scale_state scalar
    FlagWord flags;      // 4: move target reached or blocked; 8: slowed to 0.75
};
LAYOUT_ASSERT(PlayerMoveSpeed_size, sizeof(PlayerMoveSpeed) == 0x10);

#endif
