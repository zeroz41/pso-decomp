#ifndef PSO_BOSS_DEROLLE_TUNK_80036250_H
#define PSO_BOSS_DEROLLE_TUNK_80036250_H

#include "types.h"

// TUnk_80036250: placeholder name (no vtable or string names it), taken from its
// constructor's address. A 0x20 one-axis motion profile: it speeds up by `accel`
// to `max_speed`, cruises, then slows by `decel` so that `travelled` stops at
// `distance` (advance_scalar_motion_profile steps it, state 3 = arrived).
// TBoss2DeRolLe holds two (0x664/0x684), TBoss7DeRolLeC three (0x630/0x650/0x670);
// its methods are the copies emitted at the end of TBoss2DeRolLe.cpp.
// Field names are inferred from advance_scalar_motion_profile.
struct TUnk_80036250 {
    TUnk_80036250();
    ~TUnk_80036250();
    void init_float_block();
    void set_move_params(f32 max_speed, f32 distance, f32 accel, f32 decel);
    void init_params(f32 max_speed, f32 distance, f32 accel);

    s32 state;          // 0 speeding up, 1 cruising, 2 slowing down, 3 arrived
    f32 accel;
    f32 decel;
    f32 max_speed;
    f32 speed;
    f32 distance;
    f32 travelled;
    f32 brake_point;    // `travelled` at which it starts slowing down
};

// The constructors of TBoss2DeRolLe and TBoss7DeRolLeC are not real C++ yet and
// construct their members by calling this one through its linkage name.
extern "C" TUnk_80036250 *__ct__13TUnk_80036250Fv(void *self);

typedef char TUnk_80036250_size[sizeof(TUnk_80036250) == 0x20 ? 1 : -1];

#endif
