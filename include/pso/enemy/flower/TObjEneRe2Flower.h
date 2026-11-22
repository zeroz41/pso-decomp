#ifndef PSO_ENEMY_FLOWER_TOBJENERE2FLOWER_H
#define PSO_ENEMY_FLOWER_TOBJENERE2FLOWER_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80494938.h"

class TParticleCtrl;
class TObjPlayer;

struct TObjEneRe2Flower : public TObjEneDD_ST {
    TObjEneRe2Flower(TObject *parent, void *setData);
    virtual ~TObjEneRe2Flower();
    virtual void run_task();
    virtual void render();
    virtual void refresh_target();
    virtual void run_miss_reaction();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void update_body_colliders();
    virtual void run_demo_task();
    virtual void render_demo();
    void sync_center_offset();
    s32 is_rare_variant();
    void sub_800C3BA8();
    s32 remap_sound_for_variant(s32 sound_id);
    // dispatch_action's states 0-11, named by the motions they request through
    // TObjEneRe2Flower__animation_descriptors (attack0 damege1 die2 laugh3 waitc4 waito5 wake6)
    // and by what they do.
    void state_hidden(s32 reason);
    void state_fade_in(s32 reason);
    void state_wait(s32 reason);
    void state_chase_target(s32 reason);
    void state_shoot(s32 reason);
    void state_attack(s32 reason);
    void state_curse(s32 reason);
    void state_laugh(s32 reason);
    void state_self_destruct(s32 reason);
    void state_damaged(s32 reason);
    void state_die(s32 reason);
    void state_destroy(s32 reason);
    void noop();
    void notify_bomb_hit();
    void start_hit_cooldown();
    s32 check_hit_flag();
    void clear_child_flags();
    void set_child_flags();
    TObjPlayer *find_target_in_range();
    static void destroy_instance();
    static void *create(void *setData);
    int is_tower_variant();

    s32 base_yaw;            // the stem's yaw; rotation_y - base_yaw turns the head (node 1)
    u32 flags;               // 0x800 tower, 0x400 rare colour, 0x8 fading in, 0x4 self-destruct started,
                             // 0x2 its bomb hit (check_hit_flag laughs)
    f32 draw_offset_y;       // render's translate_matrix y
    s32 pad_3cc;
    s32 retarget_counter;    // tick_period_counter of the chase's target search
    s32 hit_cooldown;        // frames before a self-destructing flower takes hits again
    s32 blink_level;         // 0..255 self-destruct blink, render's alt model colour
    Vec node_points[2];      // node 14 in world space: [0] the shot origin, [1] the charge effect
    TUnk_80494938 appear_fade;
    s32 state_step;          // frame counter of the current state
    s32 state_timer;         // the chase's frame count, the attack's phase, the curse's hit flag
    s32 swing_count;         // attack motion loops before the swipe ends
    s32 pad_41c;
    s32 target_angle;        // rotation_y turns toward it
    f32 sink_depth;          // how far the dying flower has sunk
    TParticleCtrl *charge_effect; // the shot's charge particles at node_points[1]
};

// The archive loader the enemy factory table pairs with destroy_instance.
extern "C" void load_re2_flower_resources(void);

LAYOUT_ASSERT(TObjEneRe2Flower_size, sizeof(TObjEneRe2Flower) == 0x42C);
#endif
