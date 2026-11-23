#ifndef PSO_PLAYER_CONTACTSURFACESTATE_H
#define PSO_PLAYER_CONTACTSURFACESTATE_H

#include "types.h"
#include "pso/system/data/FlagWord.h"

// The surface bits of the ground under the player, cleared when built.
struct ContactSurfaceFlags {
    FlagWord word;

    ContactSurfaceFlags();
    ~ContactSurfaceFlags();
    void reset();
};

// TObjPlayer + 0x360. Name inferred from its API: get_contact_surface_type reads it for the footstep
// effects. update_actor_ground_y_at sets one flag per surface bit of the ground polygon under the player:
// flag 2 grass (type 1), flag 4 water (type 2), flag 8 sand (type 3), flag 16 foot stamp (type 4).
// fn_801BF584 starts the timer (150 frames) when the player leaves water or sand, and emit_footstep_effect
// keeps leaving foot stamps while it runs.
struct ContactSurfaceState : ContactSurfaceFlags {
    s32 timer;       // -1 when stopped
    s32 prev_flags;  // the flags of the previous frame, stored by update_field8

    ContactSurfaceState();
    ~ContactSurfaceState();
    void fn_801BFED4();
    int has_water_ground_flag();
    s32 is_timer_running();
    s32 fn_801BF584();
    void fn_801BF5F0(s32 v);
    s32 fn_801BF5F8(s32 v);
    s32 fn_801BF60C();
    int fn_801BF640();
    s32 update_timer();
    void fn_801BF7B8();
    void update_field8();
    void test_flag_16();
    void fn_801BF840();
    void set_flag_4();
    void check_flag_2();
    void fn_801BF8AC();
    void fn_801BF8CC();
    s32 get_contact_surface_type();
    int set_action_flag16();
    int test_flag_8();
    int fn_801C7098();
};

#endif
