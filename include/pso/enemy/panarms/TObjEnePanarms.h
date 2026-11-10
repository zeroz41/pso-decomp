#ifndef PSO_ENEMY_PANARMS_TOBJENEPANARMS_H
#define PSO_ENEMY_PANARMS_TOBJENEPANARMS_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/render/RenderFadeState.h"

/* One state's motion of the Pan Arms body: motion indexes bm7_s_paa_body_motion_names
   (state 0 wait, state 4 deada); same layout as shinowa_mirage_motion_param_table. */
struct PanarmsMotionParam {
    s32 unk_0;
    s32 motion;
    f32 unk_8;
    s32 unk_c;
};

struct TObjEnePanarms : public TObjEnemy {
    TObjEnePanarms(TObject *parent, void *setData);
    virtual ~TObjEnePanarms();
    virtual void run_task();
    virtual void render();
    s32 sub_800DE390();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    s32 state; // index into the TU's {enter, update} state table
    Vec move_velocity; // added to position every frame (0x378)
    u8 unk_384[0x4];
    s32 m_388;
    s32 m_38c;
    CollisionBody *collision_body_parts; // init_collision_body_parts / free_collision_body_parts
    u32 particle_handles[2]; // released by destroy_handles
    u32 m_39c;
    void* m_3a0;
    u8 unk_3A4[0x4];
    f32 m_3a8;
    u8 unk_3AC[0xC];
    u8 unk_3B8[0x18];
    u8 unk_3D0[0xC];
    void* m_3dc;
    u8 unk_3E0[0x4];
    u32 m_3e4; // the two TObjEnePanBARA halves (create_bara)
    u32 m_3e8;
    s32 attack_count; // bit 0 / bit 1 pick the next arm attack
    s32 spin_count;
    s32 max_hp; // the split starts at max_hp / 3
    s32 has_split;
    s32 move_count; // moves since the last split check
    RenderFadeState fades[4]; // one per camera (render)
    f32 pad_470;
    s32 search_range; // range passed to find_nearest_visible_player while waiting hidden
    s32 wait_frames; // state timer start value of the hidden wait
    int find_nearest_enemy_with_flag(s32 arg1, f32 farg0);
    static void spawn_npc_pair();
    static int do_action_2(void* p);
    static s32 create_bara(void *setData, s32 index);
    static s32 create(s32 arg0);
    void init(s16 action);
    int get_state_flag();
    void update_spin();
    void enter_down_state();
    void update_state_effect();
    void update_timed_action();
    void merge_halves();
    void update_separated_parts();
    void update_hit_effect();
    void update_wait_then_set_state();
    void update_particle_emitters();
    void set_flags_and_field_b8();
    void update_destroy_child();
    void update_particle_emitters_set2();
    void set_state_flags_6();
    void update_fall();
    void set_hidden_flags();
    void try_activate();
    // State-table entries (enter, update) indexed by the state at +0x374; names from their table slots.
    void enter_idle();
    void enter_wait_hidden();
    void update_wait_hidden();
    void enter_move();
    void update_move();
    void enter_dead();
    void update_dead();
    void enter_arm_attack_0();
    void enter_arm_attack_1();
    void enter_split();
    void enter_separated();
    void enter_rejoin();
    static s32 find_combine_position(void *p);
    void turn_toward_target(s32 arg1);
    u16 turn_to_nearest_player(s32 arg1, s32 arg2);
    void snap_to_ground();
    void set_state(s32 arg1);
    void draw_shadow();
    void destroy_handles();
    static void free_data();
    static void load_and_spawn_npc();
};

#endif
