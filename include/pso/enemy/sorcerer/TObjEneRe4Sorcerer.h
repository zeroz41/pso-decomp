#ifndef PSO_ENEMY_SORCERER_TOBJENERE4SORCERER_H
#define PSO_ENEMY_SORCERER_TOBJENERE4SORCERER_H

#include "types.h"

struct NJS_OBJECT;
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/player/TargetCursorList.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/TUnk_80490470.h"
#include <stddef.h>

struct TObjEneRe4Sorcerer : public TObjEneDD_ST {
    TObjEneRe4Sorcerer(TObject *parent, void *set_data);
    virtual ~TObjEneRe4Sorcerer();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void update_body_colliders();
    virtual CsnHit *move_xz_on_ground(const Vec *);
    virtual CsnHit *update_ground_contact();
    virtual void run_demo_task();
    virtual void render_demo();
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void refresh_target();
    void render();
    void run_task();
    static void step_effect_sequence(NJS_OBJECT *);
    void handle_death_state(s32 mode);
    void update_state_machine(s32 reason);
    void state_wait(s32 mode);
    void handle_state(s32 mode);
    void create_effect();
    s32 cast_resta();
    s32 cast_technique();
    void turn_to_target();
    void calc_orb_positions();
    void apply_mylla_effect();
    void set_photon_state();
    s32 check_shield(TObjChara *target);
    void advance_anim_frame();
    void request_death_effect();
    s32 try_attack(f32 ranger_range_sq, f32 range_sq);
    void update_collision_center();
    void init_enemy();
    void create_enabled(Vec *anchor, u16 id, s32 set_index);
    void create_disabled(Vec *anchor, u16 id, s32 set_index);
    static void free_bits();
    TObjEneRe4Sorcerer *create();
    static void load_resources();
    s32 update_farthest_target(TObjChara *player, f32 *farthest);

    s16 strip_scroll;
    u8 pad_3c2[0x2];
    f32 texture_scroll;
    s32 behavior_flags;
    Vec bit_anchors[2];
    u16 bit_ids[2];
    s32 attack_cycle;
    s32 warp_count;
    s32 warp_angle;
    s32 pad_3f4;
    f32 effect_scale;
    TUnk_80490470 fade;
    TargetCursorList targets;
    RenderFadeState fades[4];
    s32 state_timer;
    s32 state_step;
    f32 farthest_distance;
    void set_motion_by_state();
    s32 select_attack_target(f32 ranger_range_sq, f32 range_sq);
    void update_damage_state(s32 reason);
    void update_cure_state(s32 reason);
    void update_attack_state(s32 reason);
    void update_fade_out_state(s32 reason);
    void update_enter_state(s32 reason);
    void update_hidden_state(s32 reason);
    void sub_800EF214();
    void enable_hits();
    void disable_hits();
    void warp_around_target(f32 speed);
    void sub_800EFE30();
};

LAYOUT_ASSERT(TObjEneRe4Sorcerer_m_3c0_offset, offsetof(TObjEneRe4Sorcerer, strip_scroll) == 0x3C0);
LAYOUT_ASSERT(TObjEneRe4Sorcerer_bit_ids_offset, offsetof(TObjEneRe4Sorcerer, bit_ids) == 0x3E4);
LAYOUT_ASSERT(TObjEneRe4Sorcerer_fade_offset, offsetof(TObjEneRe4Sorcerer, fade) == 0x3FC);
LAYOUT_ASSERT(TObjEneRe4Sorcerer_fades_offset, offsetof(TObjEneRe4Sorcerer, fades) == 0x474);
LAYOUT_ASSERT(TObjEneRe4Sorcerer_size, sizeof(TObjEneRe4Sorcerer) == 0x4F0);

struct BmlResource;
// The sorcerer model file; the Bit models come from it too (TObjEneRe4Bit::load_resources).
extern BmlResource *sorcerer_bml_resource;

#endif
