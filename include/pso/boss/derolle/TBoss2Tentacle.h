#ifndef PSO_BOSS_DEROLLE_TBOSS2TENTACLE_H
#define PSO_BOSS_DEROLLE_TBOSS2TENTACLE_H
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "types.h"
#include <stddef.h>

// One of De Rol Le's four tentacles (twin of Barba Ray's TBoss7Tentacle). state is the running behaviour
// (0 sway, 1 raise, 2 aim, 3 strike at target, 4 turn to its rest angle, 5 drop back); next_state is the
// one requested, entered at the top of run_task().
class TBoss2Tentacle : public TObject {
public:
    TBoss2Tentacle(TObject *parent, saddr joint, s32 index);
    virtual ~TBoss2Tentacle();
    void request_strike();
    void enter_sway();
    virtual void render();
    virtual void run_task();
public:
    // Load and release the shared tentacle model nodes (the boss's resource callbacks).
    static void load_shared_model();
    static void release_shared_model();

    void sub_8003998C();
    void sub_80039990();
    void shape_strike_arc(f32 length);
    void advance_motion_position();
    void enter_drop_back();
    void reset();
    void init_motion_from_table();
    void enter_turn_to_rest();
    void enter_raise();
    void request_drop_back();
    void request_aim();
    void request_turn_to_rest();
    void request_raise();
    void request_sway();
    void reset_segment_points();
    void speed_up_sway();
    void drop_back();
    void start_attack_at_target(u8 *target_pos, s32 hold_time);
    void raise();

    s32 state;
    s32 next_state;
    s32 attack_phase;          // state 3: shrink, reach out, hold, pull back
    u8 pad_28[0x4];
    s32 index;                 // which of the four tentacles; picks its angle-table entries
    Vec segment_pos[14];
    s32 segment_ang[14];
    saddr joint;               // the boss matrix the tentacle hangs from
    f32 frame;
    f32 frame_speed;
    s32 yaw;
    s32 pitch;
    s32 sway_speed;
    s32 sway_phase;
    Vec target;
    f32 reach;
    f32 bend;
    Vec position;              // the joint's origin, set while striking
    s32 timer;
    f32 segment_scale;
    s32 hold_time;
};

LAYOUT_ASSERT(TBoss2TentacleSegmentPos, offsetof(TBoss2Tentacle, segment_pos) == 0x30);
LAYOUT_ASSERT(TBoss2TentacleReach, offsetof(TBoss2Tentacle, reach) == 0x138);
LAYOUT_ASSERT(TBoss2Tentacle_size, sizeof(TBoss2Tentacle) == 0x158);

#endif
