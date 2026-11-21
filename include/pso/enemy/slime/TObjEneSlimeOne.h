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
    void sub_800E9090();
    virtual void vfunc_63();
    virtual void vfunc_62();
    virtual void vfunc_61();
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
    f32 m_398;
    s32 motion_phase;
    f32 alpha;  // render skips the slime at 0 and fades it below 1
    f32 draw_offset_y;  // render adds it to the position's y
    Vec draw_scale;  // render's scale_matrix_vec3
    f32 move_speed;
    Vec movement_direction;  // position += move_speed * movement_direction
    s32 turn_speed;  // added to rotation.yaw per frame, +-0x888
    s32 m_3c8;
    s32 target_client_id;  // 0xFFFF for none; calc_distance_to_client
    Vec attack_position;
    Vec launch_velocity;  // the ctor's start vector; falls by 0.075 per frame, added to position
    TParticleCtrl *particle;  // TParticleCtrl, released in the dtor
    u32 m_3ec;
    TObjEneSlime *parent_slime;  // the ctor's spawner; try_spawn_child is called on it when this one is hit
    s32 variant;
    s32 get_attack_target();
    s32 is_in_water_bomb_states();
    static int get_instance();
    int is_timer_active();
    int find_nearest_enemy_with_flag(Vec *arg1, f32 farg0);
    int check_player_field_7cc();
    void copy_position();
    void set_random_timer_15();
    void set_random_timer(s32 minimum, s32 range);
    void set_display_mode(s32 mode);
    s32 project_to_ground();
    void clear_child_flag();
    void set_target_flag_bit0();
    static s32 create(s32 arg0, s32 arg1, s32 arg2);
    static s32 create(s32 arg0, s32 arg1);
    void set_state(s32 arg1);
    void update_trail_position();
    void sub_800E92D8();
    void sub_800E9538();
    void update_effect_fade_lifetime();
    void sub_800E95F4();
    void sub_800E969C();
    void init_split_effect();
    void update_tick();
    void reset_display_state();
    void tick_timer();
    void start_tail_attack();
    void update_water_bomb_timer();
    void begin_appear();
    void sub_800E9BCC();
    void sub_800E9D7C();
    void sub_800E9DC8();
    void init_slime_state();
    void sub_800E9EFC();
    void sub_800EA120();
    void update_dive_timer();
    void enter_appear_state();
    void update_slime_timer();
    void enter_slime_state();
    void sub_800EA364();
    void sub_800EA56C();
    void sub_800EA678();
    void init_slime_display();
    void sub_800EA820();
    void reset_display();
    void update_wait_search();
    void init_state();
};

typedef char SlimeOneAnimationOffset[offsetof(TObjEneSlimeOne, animation) == 0x388 ? 1 : -1];
typedef char SlimeOneEffectTimerOffset[offsetof(TObjEneSlimeOne, effect_timer) == 0x394 ? 1 : -1];
typedef char SlimeOneAttackPositionOffset[offsetof(TObjEneSlimeOne, attack_position) == 0x3D0 ? 1 : -1];
typedef char SlimeOneVariantOffset[offsetof(TObjEneSlimeOne, variant) == 0x3F4 ? 1 : -1];
typedef char TObjEneSlimeOne_size[sizeof(TObjEneSlimeOne) == 0x3F8 ? 1 : -1];
#endif
