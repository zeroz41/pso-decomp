#ifndef PSO_ENEMY_RECON_TOBJENERECOBOX_H
#define PSO_ENEMY_RECON_TOBJENERECOBOX_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"

struct BmlResource;

struct TObjEneRecobox : public TObjEneDD_ST {
    virtual ~TObjEneRecobox();
    virtual void run_task();
    virtual void render();
    s32 render_trap_model_if_visible();
    virtual void update_if_800BB858();
    virtual void draw_with_debug_info();
    void sub_8031F800();
    void sub_8031F6C0(s32);
    void update_floor_probe();
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void refresh_target();
    // Child bookkeeping: each Recon calls these on its owner box (the entity its 0x434 id names).
    void remove_tracked_id(s32 id);
    s32 alloc_child_id();
    s32 is_anim_6();
    void handle_death_state(s32 arg1);
    void handle_action_state(s32 reason);
    void update_state(s32 arg1);
    void handle_state(s32 arg1);
    void update_child_spawn();
    u8 is_out_of_range();
    void restore_position();
    void remove_child_entity(u8 *arg1);
    s32 has_child_in_anim_5();
    s32 is_below_child_limit(u16 id);
    void spawn_debris_chips();
    u8 pad_3C0[0x4];
    u32 m_3c4;
    void* m_3c8;
    u8 pad_3CC[0xC];
    u32 m_3d8;
    u32 mount_type;               // debug TYPE: 0 NORMAL, 1 BOTTOM (rotated 0x8000), 2 SIDE (0x4000)
    u8 pad_3E0[0x10];
    u32 m_3f0;
    u32 recon_total;              // Recons it may spawn in all (30, capped by its set-data id range)
    u32 recon_max;                // live Recons at once (debug "RECON MAX(Min:0 Max:6)")
    u8 pad_3FC[0x10];
    u32 status_flags;             // bit 0 set while idle (sub_8031F6C0), cleared on activation
    u8 pad_410[0x34];
    void* m_444;
    u8 pad_448[0x74];
    u32 m_4bc;
    u32 m_4c0;
    u32 m_4c4;
    u32 m_4c8;
    u32 m_4cc;
    u32 m_4d0;
    static u32 remap_area_sound_id(u32 arg0);
    static void release_static_instance();
    static void load_resources();
    static void *create(void *set_data);
    static BmlResource *get_bml_resource();
    f32 m_4d4;
    s32 spawn_timer;              // frames since the last spawn (update_child_spawn)
    s32 spawn_interval;           // frames between spawns (30)
    u8 pad_4E0[0x10];
    f32 m_4f0;
};

LAYOUT_ASSERT(TObjEneRecobox_size, sizeof(TObjEneRecobox) == 0x4F4);
#endif
