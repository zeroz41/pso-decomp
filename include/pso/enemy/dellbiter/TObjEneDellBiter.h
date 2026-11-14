#ifndef PSO_ENEMY_DELLBITER_TOBJENEDELLBITER_H
#define PSO_ENEMY_DELLBITER_TOBJENEDELLBITER_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80490470.h"
#include "pso/render/RenderFadeState.h"

class TNowLoading;
class TParticleCtrl;
class AreaAttackHistory;
class TUnk_804928CC;
class TUnk_80494968;

struct DelbiterInitialParameters {
    f32 max_distance;
    f32 min_distance;
    s32 turn_speed;
    u32 unknown_c[4];
};

struct DelbiterContactAttack {
    f32 power;
    s32 flags;
};

// What TLobby::spawn_npc_enemy animates the NPC copy with (laid out like MojaAnimationBinding).
struct DelbiterAttackDefinition {
    void *motion;
    TObjMotionAction *actions;
    u32 unknown_08;
    u16 action_count;
    u16 pad_0E;
};

struct DelbiterMovementParameters {
    f32 rush_speed;
    f32 walk_speed;
    f32 animation_speed_4;
    f32 animation_speed_5;
    f32 rush_distance;
    f32 rush_start_distance;
    s32 state_duration;
    s32 powered_attack_power;
    s32 attack_power;
    s32 tp_attack_power;
    s32 attack_distance;
    s32 effect_duration;
};

struct TObjEneDellBiter : public TObjEneDD_ST {
    TObjEneDellBiter(TObject *parent, void *set_data);
    virtual ~TObjEneDellBiter();
    static void *create(void *set_data);
    void sub_803055C8();
    s32 render_model_if_visible();
    virtual void vfunc_88();
    virtual s32 vfunc_104(f32);
    virtual void fn_80303538();
    virtual void dispatch_action(u32, s32);
    virtual void vfunc_106();
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    void render();
    void run_task();
    s32 previous_mode;
    s32 next_mode;
    f32 field_37c;
    u8 unknown_380[0x10];
    TObjChara *current_target;
    u8 unknown_394[0xC];
    Vec target_direction;
    f32 target_distance;
    u8 unknown_3b0[0x10];
    u32 flags;
    u32 flags_3c4;
    Vec reflection_position;
    TUnk_80490470 fade;
    RenderFadeState camera_fades[4];
    Vec part_positions[3];
    s32 part_rotation_x;
    s32 field_488;
    s32 field_48c;
    s32 effect_timer;
    TUnk_804928CC *attack_bodies[2];
    TObjCollidable *rush_body;
    AreaAttackHistory *attack_history;
    TUnk_80494968 *saver;
    f32 field_4a8;
    f32 field_4ac;
    f32 field_4b0;
    f32 field_4b4;
    f32 field_4b8;
    s32 field_4bc;
    TParticleCtrl *effect;
    TParticleCtrl *status_effects[2];
    s32 state_timer;
    s32 field_4d0;
    s32 field_4d4;
    s32 field_4d8;
    f32 field_4dc;
    f32 field_4e0;
    s32 fn_803054A8();
    s32 fn_803054FC();
    void state_death(s32 reason);
    void fn_803042B0(s32 reason);
    void fn_80305034(s32 reason);
    void fn_80305268(s32 reason);
    void fn_80303AA0(s32 reason);
    void fn_80303BC0(s32 reason);
    void fn_80303F04(s32 reason);
    void fn_803040D0(s32 reason);
    void fn_803044AC(s32 reason);
    void fn_8030492C(s32 reason);
    void fn_80304B88(s32 reason);
    void fn_80304D10(s32 reason);
    s32 check_rush_collisions();
    void update_contact_attacks();
    s32 select_farthest_visible_player();
    s32 validate_or_update_target();
    void fn_803058DC();
    void fn_8030591C();
    void fn_80305684();
    void fn_80305688();
    static void step_demo_script();
    void update_state(s32 arg1);
    s32 check_low_hp_transition();
    s32 fn_803059BC(const Vec *origin);
    void spawn_front_particle();
    void update_attack_effect();
    void init_target_offsets();
    void update_particle_emitters();
    void set_effect_pos_above_self();
    void init_params();
    static void set_min_clamped_entry_value(s32 arg0, f32 farg0);
    static void destroy_static_instance();
    static void load_resources();
};

typedef char TObjEneDellBiter_size[sizeof(TObjEneDellBiter) == 0x4E4 ? 1 : -1];

#endif
