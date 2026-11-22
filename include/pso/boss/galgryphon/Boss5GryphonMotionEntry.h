#ifndef PSO_BOSS_GALGRYPHON_BOSS5GRYPHONMOTIONENTRY_H
#define PSO_BOSS_GALGRYPHON_BOSS5GRYPHONMOTIONENTRY_H

#include "types.h"

// The views of Boss5GryphonMotionArgs.
struct Boss5GryphonFlightArgs {  // update_turning_flight, update_low_flight_circle
    s32 turn;       // added to turn_velocity; its sign picks the circling side
    f32 speed;
    f32 radius_sq;  // update_low_flight_circle widens its turn beyond it
    f32 pad_C;
};

struct Boss5GryphonCircleArgs {  // circle_arena
    s32 turn_rate;
    s32 direction;  // > 0 circles one way, else the other
    f32 speed;
    f32 radius;
};

struct Boss5GryphonMoveArgs {  // move_to_motion_destination
    f32 x;
    f32 z;
    f32 speed;
    s32 turn_rate;
};

// The arguments an action script step leaves for its state; each state reads its own view.
union Boss5GryphonMotionArgs {
    s32 seed;  // the rng seed of update_ground_lightning_attack and update_offscreen_dive
    Boss5GryphonFlightArgs flight;
    Boss5GryphonCircleArgs circle;
    Boss5GryphonMoveArgs move;
    u32 words[4];  // as init, copy and bswap treat them
};

// One step of the gryphon's motion: the action state it runs, its frame count and that state's arguments.
// The 6xA0 subcommand carries one to the other clients.
struct Boss5GryphonMotionEntry {
    s16 state;
    s16 timer;
    Boss5GryphonMotionArgs args;
    void init();  // state 0x21 (choose the next action), no timer, no arguments
    void copy(Boss5GryphonMotionEntry *src);
    void bswap();
};

#endif
