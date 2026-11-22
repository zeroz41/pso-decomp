#ifndef PSO_BOSS_DEROLLE_TUNK_80036250_H
#define PSO_BOSS_DEROLLE_TUNK_80036250_H

#include "types.h"

// TUnk_80036250: placeholder name (no vtable or string names it), taken from its
// constructor's address. A 0x20 one-axis motion profile: it speeds up by `accel`
// to `max_speed`, cruises, then slows by `decel` so that `travelled` stops at
// `distance` (advance steps it, state 3 = arrived).
// TBoss2DeRolLe holds two (0x664/0x684), TBoss7DeRolLeC three (0x630/0x650/0x670);
// its methods are the copies emitted at the end of TBoss2DeRolLe.cpp.
// Field names are inferred from advance.
struct TUnk_80036250 {
    TUnk_80036250();
    ~TUnk_80036250();
    void init_float_block();
    void set_move_params(f32 max_speed, f32 distance, f32 accel, f32 decel);
    void init_params(f32 max_speed, f32 distance, f32 accel);
    void plan_profile();  // caps max_speed so it fits distance, sets brake_point
    s32 advance();        // one frame's step; returns the state

    s32 state;          // 0 speeding up, 1 cruising, 2 slowing down, 3 arrived
    f32 accel;
    f32 decel;
    f32 max_speed;
    f32 speed;
    f32 distance;
    f32 travelled;
    f32 brake_point;    // `travelled` at which it starts slowing down
};

LAYOUT_ASSERT(TUnk_80036250_size, sizeof(TUnk_80036250) == 0x20);

#endif
