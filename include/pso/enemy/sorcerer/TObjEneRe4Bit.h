#ifndef PSO_ENEMY_SORCERER_TOBJENERE4BIT_H
#define PSO_ENEMY_SORCERER_TOBJENERE4BIT_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80490470.h"
#include <stddef.h>

struct TObjEneRe4Sorcerer;

struct TObjEneRe4InitParams {
    f32 max_distance;
    f32 min_distance;
    s32 turn_speed;
    u32 unk_c[4];
};

struct TObjEneRe4Bit : public TObjEneDD_ST {
    TObjEneRe4Bit(TObject *parent, TObjEneRe4Sorcerer *owner, Vec *anchor, s32 enabled, u16 id, s32 set_index);
    virtual ~TObjEneRe4Bit();
    virtual void update_body_colliders();
    virtual void run_demo_task();
    virtual void render_demo();
    virtual void dispatch_action(u32 state, s32 reason);
    void set_flag3cc_bit2000();
    void call_vt_90_91();
    void invoke_state_callbacks();
    void set_state_flags();
    void clear_state_flag_0x10();
    void set_hold_flags();
    void set_flag_and_notify();
    void hide();
    void set_attack_flag();
    void set_state_flag_and_mode(s32 kind);
    void reset_texture();
    Vec *get_spell_data();
    s32 get_state();
    s32 can_cast();
    void clear_state_flags_when_done();
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void apply_defense_stat_status(void *);
    void apply_attack_stat_status(void *);
    void clear_harmful_statuses();
    void apply_shock_status();
    void apply_movement_ailment(s32);
    void apply_confusion_status();
    void apply_slow_status();
    void apply_paralysis();
    void apply_poison_status();
    void refresh_target();
    void render();
    void run_task();
    void handle_event(s32 mode);
    void handle_state_message(s32 msg);
    void reset_transform();
    void update_homing_velocity();
    void update_position_flag();
    void copy_pos();
    void init();
    static void load_resources();
    static void free_resources();
    static TObjEneRe4Bit *create(TObjEneRe4Sorcerer *owner, Vec *anchor, s32 enabled, u16 id, s32 set_index);

    Vec *anchor;
    s16 owner_id;
    u8 pad_3c6[0x2];
    s32 enabled;
    u32 behavior_flags;
    s32 texture_index;
    s32 technique_texture;
    f32 lift_height;
    TUnk_80490470 fade;
    Vec homing_velocity;
    s32 cast_state;
    s32 state_step;
    s32 pad_40c;
    void update_death_state(s32 reason);
    void update_damage_state(s32 reason);
    void update_lower_state(s32 reason);
    void update_raise_state(s32 reason);
};

LAYOUT_ASSERT(TObjEneRe4Bit_fade_offset, offsetof(TObjEneRe4Bit, fade) == 0x3DC);
LAYOUT_ASSERT(TObjEneRe4Bit_size, sizeof(TObjEneRe4Bit) == 0x410);

#endif
