#ifndef PSO_ENEMY_TUNK_80493450_H
#define PSO_ENEMY_TUNK_80493450_H
#include "types.h"
#include "pso/enemy/TObjEnemy.h"

// What TObjEnemy::movementParameters points at for a beast (one row per
// subtype): the detection radius find_nearest_visible_player takes and the
// turn step approach_angle_limited takes.
struct BeastMovementParams {
    f32 detectionRadius;
    f32 wanderSpeed;        // enemy_wander_home's step; also widens the home range idling keeps
    s32 turnSpeed;
    s32 pad_0C[4];
};

class TUnk_80493450 : public TObjEnemy {
public:
    virtual void run_task();
    virtual ~TUnk_80493450();
    TUnk_80493450(TObject *parent);
    virtual void refresh_target();
    virtual void run_idle_action();
    virtual void run_death_reaction();
    void update_target_near_flag();
    void select_move_speed();
    virtual void run_hit_reaction();
    s32 test_elt_flag(s32, s32);
    s32 countChildren();
    void link_into_group_chain();
    void unlink_enemy_group_relations();
    virtual void beast_update_appear();
    virtual void beast_idle_update();
    virtual void update_turn_toward_target();
    virtual void beast_update_approach();
    virtual void beast_update_group_chase();
    virtual void beast_update_attack();
    virtual void vfunc_89();
    virtual void beast_update_hurt();
    virtual void beast_update_dead();
    virtual void beast_retire_corpse();
    virtual void update_attack_trail();
    virtual void spawn_death_effect();
    virtual void play_alert_sound();
    virtual void play_attack_sound();
    virtual void play_hurt_sound();
    virtual void play_death_sound();
    virtual void play_group_chase_sound();
    virtual void select_post_attack_mode();
    virtual void run_demo_task();
    virtual void request_stand_action();
    virtual void run_miss_reaction();
    virtual void run_move_action();
    virtual s32 update_action_hold_status();
    virtual s32 update_movement_status();
    virtual void run_attack_action();
    virtual int test_flag_256();
    s16 retreat_timer;      // frames left of mode 4's backing away (beast_update_group_chase)
    u16 pad_376;            // cleared by every beast ctor, read nowhere
    s32 in_group;           // has_group() when it starts idling; it then takes its group root's target
    s32 child_count;        // countChildren(); idling evens it out against the next beast's
    f32 corpse_offset_y;    // render raises the model by it; the corpse sinks by corpse_sink_speed a frame
    f32 corpse_sink_speed;
    f32 corpse_sink_limit;  // beast_update_dead retires the corpse once corpse_offset_y reaches it
    u32 home_chase_frames;  // frames it has headed home since the target left its reach
    s32 appearing;          // 1 until the appear action has played
    f32 move_speed;         // this frame's chase speed: near_move_speed while the target is near, else far_move_speed
    f32 far_move_speed;
    f32 near_move_speed;
    f32 far_anim_speed;     // play_speed to go with far_move_speed
    f32 near_anim_speed;    // ... and with near_move_speed
};

u16 get_enemy_target_id(TObjEnemy *enemy);

#endif
