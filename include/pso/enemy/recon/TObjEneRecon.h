#ifndef PSO_ENEMY_RECON_TOBJENERECON_H
#define PSO_ENEMY_RECON_TOBJENERECON_H

#include "types.h"

struct NJS_OBJECT;
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80494938.h"

struct TObjEneRecon : public TObjEneDD_ST {
    virtual ~TObjEneRecon();
    virtual s32 acquire_target(f32);
    s32 render_model_if_visible();
    virtual void check_collisions();
    virtual void update_body_colliders();
    virtual void run_demo_task();
    virtual void render_demo();
    virtual void dispatch_action(u32 state, s32 reason);
    void update_flag_0x444();
    void sub_8031D4B0(s32);
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void refresh_target();
    void render();
    void run_task();
    u8 pad_3C0[0x30];
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
    void render_shadows();
    static void advance_intro_stage(NJS_OBJECT *);
    void update_ground_probe();
    u8 is_anim_5();
    void spawn_trap_a();
    void spawn_trap_b();
    f32 approach_value(f32 farg0, f32 farg1);
    void clamp_min_height();
    void update_position_from_offsets();
    void init_state();
    static void release_static_instance();
    static void *create(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4);
    static void load_resources();
    void*get_field_38_ptr();
    u8 unk_47C[0x4];
    TUnk_80494938 fade;
    u8 unk_49C[0x34];
    f32 m_4d0;
    u8 unk_4D4[0x4];
    s32 m_4d8;
    u8 unk_4DC[0x8];
    s32 calc_scaled_value();
    void handle_message(s32 arg1);
    void retarget();
    void select_next_target();
    void update_collide_flag();
    void set_flag2(f32 x, f32 z, f32 r);
    void set_orbit_destination(s32 arg1);
    void advance_field398();
    void sync_height();
};

LAYOUT_ASSERT(TObjEneRecon_size, sizeof(TObjEneRecon) == 0x4E4);

#endif
