#ifndef PSO_OBJECT_AMBIENT_TOBJFISH_H
#define PSO_OBJECT_AMBIENT_TOBJFISH_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include <stddef.h>

// One fish of a school (0x44 bytes; init_fish_school allocates m_94 of them at m_a0).
struct TObjFishEntry {
    Vec pos;         // relative to the school's position
    Vec target;
    Vec velocity;
    s32 yaw;
    f32 frame;
    s16 angle;
    s16 target_angle;
    s16 anim;
    s16 timer;
    s32 seen;        // render sets it when it retargets the fish at the camera; run_task clears it
    s32 mode;        // 1 while it swims back to its target
    u8 pad_3c[0x8];
};

struct TObjFish : public TObjBase {
    TObjFish(TObject *parent, void *set_data);
    virtual ~TObjFish();
    s32 init_fish_school(void *, s32, s32);
    s32 update_state();
    virtual void render();
    virtual void run_task();
    s16 m_90;
    s16 m_92;
    u32 m_94;              // fish count
    u32 m_98;              // frame counter
    f32 m_9c;
    TObjFishEntry *m_a0;   // the fish
    void sync_position_vectors();
    static void *alloc(void *arg0);
    static void reset_fish_globals();
    s32 get_phase();
    static saddr get_fish_count();
    static void spawn_default_particle(s32 position, s32 particle_index);
    static void create_splash_particle(saddr arg0, s32 arg1, saddr arg2);
    static void spawn_particle(saddr arg0, s32 arg1, f32 farg0);
    static void free_resource();
    static void load_area_resource();
    static void draw_callback_transform_to_view();
    void set_draw_callback_list();
    void clear_render_callback();
    s32 is_entry_table_valid();
    static void init_state_1(void *arg0);
    void update_attached_orientation();
    void destroy_child();
    static s32 set_global_param(saddr arg0);
    void handle_death_state(u32 arg1);
    static void spawn_via_trap(s32 arg0, s32 arg1, s32 arg2);
    static void set_effect_target_position(void* p, void* a1, void* a2);
    void set_hooked_effect_target();
    void apply_damage_and_set_effect(s32 arg1);
    void pick_random_target();
    u32 update_phase_rising();
    u32 update_tail_anim_state();
    u32 update_phase_settling();
    u32 update_anim_state();
    s32 is_all_parts_done();
    void update_wobble_angle();
};

LAYOUT_ASSERT(TObjFishEntry_size, sizeof(TObjFishEntry) == 0x44);
LAYOUT_ASSERT(TObjFishEntry_target_offset, offsetof(TObjFishEntry, target) == 0xC);
LAYOUT_ASSERT(TObjFishEntry_velocity_offset, offsetof(TObjFishEntry, velocity) == 0x18);
LAYOUT_ASSERT(TObjFishEntry_yaw_offset, offsetof(TObjFishEntry, yaw) == 0x24);
LAYOUT_ASSERT(TObjFishEntry_frame_offset, offsetof(TObjFishEntry, frame) == 0x28);
LAYOUT_ASSERT(TObjFishEntry_angle_offset, offsetof(TObjFishEntry, angle) == 0x2C);
LAYOUT_ASSERT(TObjFishEntry_target_angle_offset, offsetof(TObjFishEntry, target_angle) == 0x2E);
LAYOUT_ASSERT(TObjFishEntry_anim_offset, offsetof(TObjFishEntry, anim) == 0x30);
LAYOUT_ASSERT(TObjFishEntry_timer_offset, offsetof(TObjFishEntry, timer) == 0x32);
LAYOUT_ASSERT(TObjFishEntry_seen_offset, offsetof(TObjFishEntry, seen) == 0x34);
LAYOUT_ASSERT(TObjFishEntry_mode_offset, offsetof(TObjFishEntry, mode) == 0x38);
LAYOUT_ASSERT(TObjFish_size, sizeof(TObjFish) == 0xA4);
#endif
