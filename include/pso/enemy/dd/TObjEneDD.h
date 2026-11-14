#ifndef PSO_ENEMY_DD_TOBJENEDD_H
#define PSO_ENEMY_DD_TOBJENEDD_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

struct TObjEneDD : public TObjEnemy {
    TObjEneDD(TObject *parent);
    virtual ~TObjEneDD();
    void set_part_local_pos(void *, s32);
    void transition_enemy_state(s32);
    void sub_800BBA0C();
    void invoke_initialization_hook(void *set_data);
    void reset_state_fields();
    void init_common_from(u8 *);
    void clear_attack_receipts();
    virtual void vfunc_79(s32 *);
    virtual s32 vfunc_83();
    virtual s32 vfunc_84();
    virtual void vfunc_85();
    virtual u8 vfunc_86();
    virtual void dispatch_action(u32 state, s32 reason) = 0;
    virtual void vfunc_88();
    virtual void vfunc_89();
    virtual s32 vfunc_90();
    virtual void vfunc_91();
    virtual void vfunc_92();
    virtual void vfunc_93();
    virtual void vfunc_94();
    virtual void vfunc_95();
    virtual void vfunc_96();
    virtual void vfunc_97();
    virtual void vfunc_98();
    virtual s32 vfunc_99();
    virtual void vfunc_100();
    virtual u8 *vfunc_101(u8 *);
    virtual u8 *vfunc_102();
    virtual u8 *vfunc_103(u8 *);
    // The table ends at slot 103 (the word after it is padding): dispatch_action's state handlers
    // start at slot 104 and each subclass declares its own (TObjEneDD_ST f32, TBoss2Mine s32, FlyNest init).
    int get_flag_b4();
    static f32 calc_elapsed_scaled();
    void update_velocity();
    void turn_toward_target_direction(s32 max_step);
    void set_target_destination(const Vec *position);
    static void init_lights();
    static s32 clamp_frame_index(s32 arg0);
    static s32 check_v2_mode();
    int get_target_state_a();
    int get_target_state_b();
    int query_teammate_state();
    int update_lobby_state();
    static u8 is_phase_e();
    static u8 is_main_phase_15();
    static void clear_global_flag_400();
    void draw_ground_shadow(const Vec *scale, s32 forceDraw);
    void draw_oriented_shadow(s32 arg1, s32 arg2, u32 arg3);
    int update_primary_light();
    int update_secondary_light();
    void reload_stats_keep_hp_tp();
    void reset_hp(u8 *base_stats, u8 *attack_stats, u8 *resistance_stats);
    int get_camera_ctrl();
    int update_camera_sequence();
    void initialize_enemy_state(s32 parameter);
    static s32 get_random_scaled();
    f32 rand_range(f32 farg0, f32 farg1);
    int set_state_8();
    int check_state_flag_4();
    int check_state_flag_2();
    int check_state_flag_1();
    static void send_damage_message(s32 arg0, u8 *arg1);
    static void inflict_poison(s32 arg0, u8 *arg1);
    void emit_effect_at_position(void* a1);
    static void emit_effect(void* p, int a1, int a2);
    static void emit_enemy_effect(s32 arg0, s32 arg1, u8 *arg2, s32 arg3);
    static void setup(void* p, int a1, int a2);
    static void setup_instance(s32 arg0, s32 arg1, u8 *arg2, s32 arg3);
    void transform_relative_position(void* a1);
    s32 is_target_unobstructed(s32 arg1);
    u8 is_valid_target();
    void transform_part_positions();
    void init_model(CollisionBody *bodies, s32 count);
    void clear_field_388();
    int has_move_failures(s32 arg1);
    void move_to_wall_clamped_destination(f32 farg0, f32 farg1, f32 farg2);
    void move_with_wall_slide_commit(f32 farg0, f32 farg1, f32 farg2);
    void move_with_wall_stop(f32 farg0, f32 farg1, f32 farg2);
    void move_clamped_on_ground(f32 farg0, f32 farg1, f32 farg2);
    void move_with_wall_slide_on_ground(f32 farg0, f32 farg1, f32 farg2);
    void move_to_shot_position(f32 farg0, f32 farg1, f32 farg2);
    static void set_squared_value(f32 farg0);
    static void collect_target_candidates(s32 arg0, f32 farg0);
    static void create_instance();
    static int get_enemy_count();
    void handle_state(s32 arg1);
    void noop();
    void state_damaged(s32 arg1);
    void state_chase_target(s32 arg1);
    int get_target_info();
    void copy_resource_desc(u8 *arg1);
    void set_field_378(s32 v);
    void init_position_vectors();
    static void release_resource();
};

#endif
