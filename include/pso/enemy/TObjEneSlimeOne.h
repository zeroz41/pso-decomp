#ifndef PSO_ENEMY_TOBJENESLIMEONE_H
#define PSO_ENEMY_TOBJENESLIMEONE_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "dolphin/mtx.h"

struct TObjEneSlimeOne : public TObjEnemy {
    virtual ~TObjEneSlimeOne();
    void initialize_slime_instance_state();
    void sub_800E9090();
    virtual void vfunc_63();
    virtual void vfunc_62();
    virtual void vfunc_61();
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual void render();
    virtual void run_task();
    u8 unk_374[0xC];
    u8 * model_archive;  // get_instance(); its texlist and bml models
    u32 state;  // index into the {enter, update} state table; set_state
    u32 m_388;
    void *collision_body_parts;  // init_collision_body_parts / free_collision_body_parts
    s32 state_timer;  // set_random_timer, counted down by the states
    u8 unk_394[0x4];
    f32 m_398;
    s32 m_39c;
    f32 alpha;  // render skips the slime at 0 and fades it below 1
    f32 draw_offset_y;  // render adds it to the position's y
    Vec draw_scale;  // render's scale_matrix_vec3
    f32 move_speed;
    f32 move_dir_x;  // position += move_speed * move_dir
    f32 move_dir_y;
    f32 move_dir_z;
    s32 turn_speed;  // added to rotation_y per frame, +-0x888
    s32 m_3c8;
    s32 target_client_id;  // 0xFFFF for none; calc_distance_to_client
    u8 unk_3D0[0xC];
    Vec launch_velocity;  // the ctor's start vector; falls by 0.075 per frame, added to position
    void * particle;  // TParticleCtrl, released in the dtor
    u32 m_3ec;
    u32 parent_slime;  // the ctor's spawner; try_spawn_child is called on it when this one is hit
    s32 get_attack_target();
    s32 is_in_water_bomb_states();
    static int get_instance();
    int is_timer_active();
    int find_nearest_enemy_with_flag(s32 arg1, f32 farg0);
    int check_player_field_7cc();
    void draw_part(s32 arg1);
    void advance_animation_state();
    s32 is_reached_target_depth();
    void set_motion_state(s32 arg1);
    void copy_position();
    void set_random_timer_15();
    void clear_child_flag();
    void set_target_flag_bit0();
    static s32 create(s32 arg0, s32 arg1, s32 arg2);
    static s32 create(s32 arg0, s32 arg1);
    void set_state(s32 arg1);
    s32 try_spawn_child(void *arg1);
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

typedef char TObjEneSlimeOne_size[sizeof(TObjEneSlimeOne) == 0x3F4 ? 1 : -1];
#endif
