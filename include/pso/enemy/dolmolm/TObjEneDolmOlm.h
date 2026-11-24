#ifndef PSO_ENEMY_DOLMOLM_TOBJENEDOLMOLM_H
#define PSO_ENEMY_DOLMOLM_TOBJENEDOLMOLM_H

#include "types.h"

struct NJS_OBJECT;
#include "pso/enemy/TUnk_80493450.h"
#include "pso/render/TUnk_80494938.h"

class TAttackTraceStrip;

struct TObjEneDolmOlm : public TUnk_80493450 {
    TObjEneDolmOlm(TObject *parent, void *set_data);
    static void *create(void *set_data);
    virtual ~TObjEneDolmOlm();
    virtual void run_task();
    virtual void render();
    s32 render_model_if_visible();
    s32 check_path_ahead(s32 angle, f32 speed);
    void apply_variant();          // clamps variant to 0/1, loads its model, resamples the attack trails and sets the mode odds (name inferred)
    void update_retreat();         // mode 10 (name inferred)
    void update_special_attack();  // mode 11 (name inferred)
    void spawn_ground_effects(Vec *pos);
    virtual void run_attack_action();
    virtual void run_idle_action();
    virtual void run_move_action();
    virtual void beast_update_appear();
    virtual void request_stand_action();
    virtual void run_demo_task();
    virtual void select_post_attack_mode();
    virtual void play_death_sound();
    virtual void play_hurt_sound();
    virtual void play_attack_sound();
    virtual void play_alert_sound();
    virtual void spawn_death_effect();
    virtual void update_attack_trail();
    TUnk_80494938 fade;
    TAttackTraceStrip *attack_traces[2]; // driven by update_attack_trail
    f32 retreat_chance;        // 0.3 + parameters[2]: select_post_attack_mode's odds of mode 10 (update_retreat)
    f32 special_attack_chance; // 0.3 + parameters[3]: run_attack_action's odds of mode 11 (update_special_attack)
    f32 retreat_distance;      // how far update_retreat has backed away; it stops at 50
    Vec floor_point;           // the floor hit under it, or its position off a reflecting floor
    u32 floor_flags;           // the floor hit's flags; 0x4000 is a reflecting floor
    void load_params_from_table(s32 i);
    static void load_shared_resources();
    static void free_shared_resources();
    static void toggle_effect_render(NJS_OBJECT *);
    void advance_position();
    void init_body_sub();
    static void reset_count();
};

LAYOUT_ASSERT(TObjEneDolmOlm_size, sizeof(TObjEneDolmOlm) == 0x3E8);

struct BmlResource;
struct SampledMotionPoints;
struct TObjMotionAction;

// What TLobby::dispatch_shared_handler_a(0x4E / 0x4F) gives each variant.
struct DolmOlmBehaviorParams {
    f32 params[4];     // the ctor copies them to far_move_speed, far_anim_speed, near_move_speed and near_anim_speed
    f32 special_range; // how near the target has to be for mode 11 (update_special_attack)
    f32 pad_14;
    s32 special_angle; // how far off its heading the target may be for mode 11's hit
    s32 special_power; // mode 11's hit passes 30 times this to TObjPlayer::play_effect
};

extern "C" {
s32 TObjEneDolmOlm__sub_80300CF0(void);
}

extern BmlResource *TObjEneDolmOlm__resource_bundle;
extern SampledMotionPoints *TObjEneDolmOlm__left_attack_samples; // the left attack's (action 3) trail samples
extern SampledMotionPoints *TObjEneDolmOlm__right_attack_samples; // the right attack's (action 4) trail samples
extern player_stats **dolm_olm_combat_stat_id_pair;
extern AttackParams **TObjEneDolmOlm__shared_handler_ids;
extern ActorParamBlock **TObjEneDolmOlm__registered_object_ids;
extern DolmOlmBehaviorParams **TObjEneDolmOlm__behavior_params_by_variant;
extern s32 TObjEneDolmOlm__effect_render_state;
extern TObjMotionAction TObjEneDolmOlm__param_table[13];
extern const char *obj_ene_dolm_olm_class_name;

#endif
