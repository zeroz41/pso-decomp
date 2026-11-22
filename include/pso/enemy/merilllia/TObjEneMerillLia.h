#ifndef PSO_ENEMY_MERILLLIA_TOBJENEMERILLLIA_H
#define PSO_ENEMY_MERILLLIA_TOBJENEMERILLLIA_H

#include "types.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/render/TUnk_80494938.h"

// The row of merill_lia_behavior_params a Merill Lia's subtype picks (what
// TLobby::dispatch_shared_handler_a(74 + subtype) returns).
struct MerillLiaBehaviorParams {
    f32 far_move_speed;
    f32 far_anim_speed;
    f32 near_move_speed;
    f32 near_anim_speed;
    f32 kafun_value;       // TTecKafun::create's value for its pollen attack
    f32 retreat_speed;
    s32 react_hp_percent;  // a hit at or below this share of its hp picks a reaction
};

struct TObjEneMerillLia : public TUnk_80493450 {
    TObjEneMerillLia(TObject *parent, void *setData);
    virtual ~TObjEneMerillLia();
    static void *create(void *setData);
    virtual void beast_idle_update();
    virtual void beast_update_hurt();
    virtual void run_task();
    virtual void render();
    virtual void beast_update_approach();
    virtual void beast_update_group_chase();
    virtual void update_attack_trail();
    virtual void spawn_death_effect();
    virtual void play_attack_sound();
    virtual void play_hurt_sound();
    virtual void play_death_sound();
    virtual void play_group_chase_sound();
    virtual void run_demo_task();
    void update_fade_in();
    virtual void beast_update_appear();
    virtual void run_attack_action();
    virtual void run_move_action();
    virtual void run_idle_action();
    TUnk_80494938 fade;  // the fade-in of its first appearance (mode 13)
    s32 get_clamped_level();
    void select_subtype();
    void start_burrow();
    void start_retreat();
    void start_kafun_attack();
    void search_target();
    void update_burrow();
    void update_kafun_attack();
    void init_behavior_params();
    void select_hurt_action();
    static void load_resources();
    static void free_resources();
    void select_model_record(s32 i);
    void play_kafun_sound();
    void play_dig_sound();
    void spawn_ground_effect();
    f32 retreat_chance;   // set param 0 - 0.2: odds a hit or a finished pollen attack starts a retreat
    f32 kafun_chance;     // set param 2 - 0.2: odds a hit starts a pollen attack instead
    f32 react_hp_ratio;   // react_hp_percent / 100
    f32 notice_range;     // 100 + set param 4 (at least 15): search_target's reach
    f32 retreat_speed;    // the retreat's backstep speed, far_move_speed while it is 0
    s16 retreat_frames;   // 300 + set param 3: start_retreat's retreat_timer
    u8 pad_3DA[0x2];
};

LAYOUT_ASSERT(TObjEneMerillLia_size, sizeof(TObjEneMerillLia) == 0x3DC);

#endif
