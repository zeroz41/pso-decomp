#ifndef PSO_ENEMY_SLIME_TOBJENESLIMEONE_H
#define PSO_ENEMY_SLIME_TOBJENESLIMEONE_H

#include <stddef.h>
#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "dolphin/mtx.h"

struct TObjEneSlime;
struct SlimeAnimationState;
struct BmlResource;
class TParticleCtrl;

struct TObjEneSlimeOne : public TObjEnemy {
    TObjEneSlimeOne(TObject *parent, TObjEneSlime *owner, void *set_data);
    TObjEneSlimeOne(TObject *parent, TObjEneSlime *owner, void *set_data, const Vec *velocity);
    virtual ~TObjEneSlimeOne();
    void initialize_slime_instance_state();
    void render_trail();
    virtual void run_death_reaction();
    virtual void run_hit_reaction();
    virtual void run_miss_reaction();
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual void render();
    virtual void run_task();
    Vec trail_position;
    BmlResource *model_archive;  // get_instance(); its texlist and bml models
    u32 state;  // index into the {enter, update} state table; set_state
    SlimeAnimationState *animation;
    CollisionBody *collision_body_parts;  // init_collision_body_parts / free_collision_body_parts
    s32 state_timer;  // set_random_timer, counted down by the states
    s32 effect_timer;
    f32 state_value;  // grow/shrink progress (0 puddle .. 1 full size); the slide distance left in update_slide
    s32 motion_phase;
    f32 alpha;  // render skips the slime at 0 and fades it below 1
    f32 draw_offset_y;  // render adds it to the position's y
    Vec draw_scale;  // render's scale_matrix_vec3
    f32 move_speed;
    Vec movement_direction;  // position += move_speed * movement_direction
    s32 turn_speed;  // added to rotation.yaw per frame, +-0x888
    s32 search_count;  // update_wait_search: searches without a player in range; at 5 it snaps back home
    s32 target_client_id;  // 0xFFFF for none; calc_distance_to_client
    Vec attack_position;
    Vec launch_velocity;  // the ctor's start vector; falls by 0.075 per frame, added to position
    TParticleCtrl *particle;  // TParticleCtrl, released in the dtor
    u32 targetable;  // 1 only in set_display_mode 2 (fully out): run_task submits it as a lock-on candidate; while 0, clear_child_flag drops collision flag bit 0
    TObjEneSlime *parent_slime;  // the ctor's spawner; try_spawn_child is called on it when this one is hit
    s32 variant;
    s32 get_attack_target();
    s32 is_in_water_bomb_states();
    static BmlResource *get_instance();
    int is_timer_active();
    int find_nearest_enemy_with_flag(Vec *direction, f32 range);
    void copy_position();
    void clear_parent_slime();
    void set_random_timer_15();
    void set_random_timer(s32 minimum, s32 range);
    void set_display_mode(s32 mode);
    s32 project_to_ground();
    void clear_child_flag();
    void set_target_flag_bit0();
    static saddr create(saddr owner, saddr set_data, saddr velocity);
    static saddr create(saddr owner, saddr set_data);
    void set_state(s32 new_state);
    void update_trail_position();
    // The {enter, update} pairs of the state table, by state: 0 init_state/update_wait_search,
    // 1 reset_display/update_grow (out of the puddle; 3 if a player is near, else 2),
    // 2 init_slime_display/update_shrink (back into the puddle, then 0), 3 enter_slide/update_slide
    // (towards the player, 50..70 units), 6 enter_scan/update_scan (pulsed turns until a player is in
    // front, then 8, else 5), 7 init_slime_state/update_aim_at_enemy (turns to the nearest flagged
    // enemy, then the water bomb 9), 8 enter_approach/update_approach (creeps to the target, then 9
    // or the tail attack 10), 12 init_split_effect/update_damage (until the motion ends, then 5),
    // 13 enter_death/update_effect_fade_lifetime, 14 enter_launched/update_launched (falls along
    // launch_velocity, splashes on landing, then 1). render ends with render_trail.
    void update_launched();
    void enter_launched();
    void update_effect_fade_lifetime();
    void enter_death();
    void update_damage();
    void init_split_effect();
    void update_tick();
    void reset_display_state();
    void tick_timer();
    void start_tail_attack();
    void update_water_bomb_timer();
    void begin_appear();
    void update_approach();
    void enter_approach();
    void update_aim_at_enemy();
    void init_slime_state();
    void update_scan();
    void enter_scan();
    void update_dive_timer();
    void enter_appear_state();
    void update_slime_timer();
    void enter_slime_state();
    void update_slide();
    void enter_slide();
    void update_shrink();
    void init_slime_display();
    void update_grow();
    void reset_display();
    void update_wait_search();
    void init_state();
};

LAYOUT_ASSERT(SlimeOneAnimationOffset, offsetof(TObjEneSlimeOne, animation) == 0x388);
LAYOUT_ASSERT(SlimeOneEffectTimerOffset, offsetof(TObjEneSlimeOne, effect_timer) == 0x394);
LAYOUT_ASSERT(SlimeOneAttackPositionOffset, offsetof(TObjEneSlimeOne, attack_position) == 0x3D0);
LAYOUT_ASSERT(SlimeOneVariantOffset, offsetof(TObjEneSlimeOne, variant) == 0x3F4);
LAYOUT_ASSERT(TObjEneSlimeOne_size, sizeof(TObjEneSlimeOne) == 0x3F8);
#endif
