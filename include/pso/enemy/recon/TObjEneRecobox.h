#ifndef PSO_ENEMY_RECON_TOBJENERECOBOX_H
#define PSO_ENEMY_RECON_TOBJENERECOBOX_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/TUnk_80494938.h"

struct BmlResource;
struct TObjEneRecon;

struct TObjEneRecobox : public TObjEneDD_ST {
    TObjEneRecobox(TObject *parent, void *set_data);
    virtual ~TObjEneRecobox();
    virtual void run_task();
    virtual void render();
    virtual void refresh_target();
    virtual void run_miss_reaction();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void update_body_colliders();
    virtual void update_if_800BB858();
    virtual void draw_with_debug_info();
    s32 render_trap_model_if_visible();
    void apply_set_parameters();
    void state_idle(s32 reason);
    void handle_state(s32 reason);
    void state_closed(s32 reason);
    void update_state(s32 reason);
    void handle_action_state(s32 reason);
    void state_close(s32 reason);
    void handle_death_state(s32 reason);
    s32 can_spawn_recons();
    void update_floor_probe();
    // Child bookkeeping: each Recon calls these on its owner box (the entity its 0x434 id names).
    void remove_tracked_id(s32 id);
    s32 alloc_child_id();
    s32 is_anim_6();
    void update_child_spawn();
    s32 is_out_of_range();
    void restore_position();
    void remove_child_entity(u8 *child);
    void remove_tracked_target(TObjEneRecon *child);
    s32 has_child_in_anim_5();
    s32 is_below_child_limit(u16 id);
    void spawn_debris_chips();
    static u32 remap_area_sound_id(u32 id);
    static void release_static_instance();
    static void load_resources();
    static void *create(void *set_data);
    static BmlResource *get_bml_resource();
    f32 get_recon_rotate_rad();
    f32 get_recon_offset_max();

    TUnk_80494938 fade;
    s32 mount_type;               // debug TYPE: 0 NORMAL, 1 BOTTOM (rotated 0x8000), 2 SIDE (0x4000)
    s32 floor_flags;              // flags of the floor under the box (update_floor_probe); 0x4000 = reflective
    Vec floor_point;              // that floor point: the reflection plane of render_trap_model_if_visible
    u8 pad_3F0[0x4];
    s32 recon_total;              // Recons it may spawn in all (30, capped by its set-data id range)
    s32 recon_max;                // live Recons at once (debug "RECON MAX(Min:0 Max:6)")
    s32 pad_3FC[4];
    u32 status_flags;             // bit 0 set while idle (state_idle), cleared on activation
    s32 live_recons;              // Recons alive now (against recon_max)
    s32 spawned_recons;           // Recons spawned so far (against recon_total)
    u16 live_recon_ids[6];        // entity ids of the live Recons
    u16 recon_id_slots[30];       // entity ids handed out by alloc_child_id, 0xFFFF free
    RenderFadeState fades[4];
    f32 recon_offset_max;         // debug "RECON OFFSET MAX(+45.f)": added to each Recon's orbit height
    f32 recon_rotate_rad;         // debug "RECON ROTATE RAD(+50.f)": added to each Recon's orbit radius, >= -30
    s32 spawn_timer;              // frames since the last spawn (update_child_spawn)
    s32 spawn_interval;           // frames between spawns (30)
    s32 pad_4E0[4];
    f32 m_4f0;
};

LAYOUT_ASSERT(TObjEneRecobox_size, sizeof(TObjEneRecobox) == 0x4F4);
#endif
