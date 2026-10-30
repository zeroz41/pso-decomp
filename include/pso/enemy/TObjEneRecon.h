#ifndef PSO_ENEMY_TOBJENERECON_H
#define PSO_ENEMY_TOBJENERECON_H

#include "types.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/enemy/TObjEneDD_ST.h"

struct TObjEneRecon : public TObjEneDD_ST {
    virtual ~TObjEneRecon();
    s32 render_model_if_visible();
    virtual void vfunc_89();
    virtual void vfunc_88();
    virtual s32 vfunc_83();
    virtual void vfunc_106();
    void update_flag_0x444();
    void sub_8031D4B0(s32);
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    void render();
    void run_task();
    u32 m_390;
    u8 _pad394[0x78];
    void* m_40c;
    u8 _pad410[0x8];
    u32 m_418;
    u8 _pad41C[0xC];
    void* m_428;
    u8 _pad42C[0x8];
    u16 m_434;
    u8 _pad436[0x2];
    void* m_438;
    u8 _pad43C[0x8];
    u32 m_444;
    u8 _pad448[0x30];
    u32 m_478;
    u32 m_47c;
    void* m_480;
    u8 _pad484[0x10];
    u32 m_494;
    f32 get_field_4d4();
    f32 get_field_4d0();
    static void destroy_instance();
    static void alloc_if_valid_state();
    static void set_active();
    static void *create_bomb(void *arg0, void *arg1, void *arg2);
    void render_shadows();
    static void advance_intro_stage();
    void update_ground_probe();
    u8 is_anim_5();
    void spawn_trap_a();
    void spawn_trap_b();
    static f32 approach_value(f32 farg0, f32 farg1);
    void clamp_min_height();
    void update_position_from_offsets();
    void init_state();
    static void release_static_instance();
    static void *create(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
    static void load_resources();
    void remove_tracked_id(s32 id);
    u16 alloc_child_id();
    u8 is_anim_6();
    void handle_death_state(s32 arg1);
    void handle_action_state(s32 arg1);
    void update_state(s32 arg1);
    void handle_state(s32 arg1);
    void update_child_spawn();
    u8 is_out_of_range();
    void restore_position();
    void*get_field_38_ptr();
    void remove_child_entity(u8 *arg1);
    s32 has_child_in_anim_5();
    s32 is_below_child_limit(u16 arg1);

    u8 _padBeforeFade[0x4];
    MaterialOpacityFade fade;
    u8 _padAfterFade[0x34];
    f32 m_4d0;
    u8 unk_4D4[0x4];
    s32 m_4d8;
    u8 unk_4DC[0x8];
    static s32 render_player_marker(u16 arg0, s32 arg1);
    static void update_particle_if_active();
    static void notify_scene(s32 arg0);
    static s32 calc_scaled_value();
    void handle_message(s32 arg1);
    void retarget();
    void select_next_target();
    void update_collide_flag();
    void set_flag2();
    void set_orbit_destination(s32 arg1);
    void advance_field398();
    void sync_height();
};

typedef char TObjEneReconFadeOffset[offsetof(TObjEneRecon, fade) == 0x480 ? 1 : -1];

typedef char TObjEneRecon_size[sizeof(TObjEneRecon) == 0x4E4 ? 1 : -1];
#endif
