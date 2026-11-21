#ifndef PSO_BOSS_BARBARAY_TBOSS7TENTACLE_H
#define PSO_BOSS_BARBARAY_TBOSS7TENTACLE_H
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "types.h"
#include <stddef.h>

struct NJS_OBJECT;
struct AnimationMotion;

// One of Barba Ray's four tentacles. state is the running behaviour (0 sway, 1 raise, 2 lower, 3 strike at
// target, 4 turn to its rest angle, 5 drop back); next_state is the one requested, entered by switch_state().
class TBoss7Tentacle : public TObject {
public:
    // flags bit: the tentacle shrinks out of sight (update_extend_amount) while set.
    enum { HIDDEN = 2 };

    TBoss7Tentacle(TObject *parent, s32 joint, s32 index);
    virtual ~TBoss7Tentacle();
    void sub_802F09FC();
    void sub_802F09EC();
    virtual void render();
    virtual void run_task();
public:
    void update_extend_amount();
    void switch_state();
    void sub_802F0608(f32 length);
    void advance_path_position();
    void sub_802F0918();
    void reset_state();
    void setup_state();
    void sub_802F09B4();
    void sub_802F09C8();
    void sub_802F0A14();
    void sub_802F0A2C();
    void sub_802F0A44();
    void init_segments();
    void start_attack_at_position(u8 *target, s32 hold_time);
    s32 sub_802F0904();
    void sub_802F0AD0();
    void sub_802F0AF0();
    void sub_802F0B58();
    void sub_802F0B70();
    void sub_802F0B80();
    // Load and release the shared tentacle model nodes (the boss's resource callback table, as the
    // TBoss7Crawfish pair next to them).
    static void load_static_resource();
    static void destroy_instance();

    NJS_OBJECT *model;
    AnimationMotion *motion;   // get_boss7_motion(0x11)
    Vec scale;
    s32 state;
    s32 next_state;
    s32 attack_phase;          // state 3: shrink, reach out, hold, pull back
    u32 flags;
    Vec position;              // the joint's origin, set while striking
    s32 index;                 // which of the four tentacles; picks its angle-table entries
    Vec segment_pos[14];
    s32 segment_ang[14];
    s32 joint;                 // the boss matrix the tentacle hangs from
    f32 frame;
    f32 frame_speed;
    s32 yaw;
    s32 pitch;
    s32 sway_speed;
    s32 sway_phase;
    Vec target;
    f32 reach;
    f32 bend;
    f32 segment_scale;
    s32 timer;
    s32 hold_time;
};

LAYOUT_ASSERT(TBoss7TentacleSegmentPos, offsetof(TBoss7Tentacle, segment_pos) == 0x50);
LAYOUT_ASSERT(TBoss7TentacleReach, offsetof(TBoss7Tentacle, reach) == 0x158);
LAYOUT_ASSERT(TBoss7Tentacle_size, sizeof(TBoss7Tentacle) == 0x16C);

#endif
