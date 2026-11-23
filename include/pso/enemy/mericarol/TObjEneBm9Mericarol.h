#ifndef PSO_ENEMY_MERICAROL_TOBJENEBM9MERICAROL_H
#define PSO_ENEMY_MERICAROL_TOBJENEBM9MERICAROL_H

#include <stddef.h>
#include "types.h"

struct NJS_OBJECT;
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/effect/TAttackTrace.h"
#include "pso/enemy/AttackTargetHistory.h"
#include "pso/enemy/TObjEnemyCustom.h"

// What TObjEnemy::movementParameters points at.
struct TObjEneBm9MericarolMovementParameters {
    EnemyMoveParams move;
    u32 unknown_c[4];
};

class TObjPlayer;
class TParticleCtrl;

struct TObjEneBm9MericarolParams {
    f32 attack_power;         // the swipe's DirectAttackPayload power
    f32 technique_value;      // TTecKafun::create's value
    f32 bomb_power;           // the bomb's DirectAttackPayload power
    f32 bomb_speed;
    f32 technique_radius;     // TTecKafun::create's radius
    f32 laugh_chance;         // chance to laugh (state 8) instead of casting
    s32 pad_18;
    s32 pad_1c;
    s32 shot_delay;           // chase frames before the bomb shot
    s32 technique_delay;      // wait frames before casting
    s32 attack_recovery;      // frames after the swipe
    s32 final_blast_percent;  // percent chance the bomb gets its final blast
};

struct TObjEneBm9Mericarol : public TObjEneDD_ST {
    TObjEneBm9Mericarol(TObject *parent, void *set_data);
    virtual ~TObjEneBm9Mericarol();
    virtual void run_task();
    virtual void render();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void update_body_colliders();
    virtual void run_demo_task();
    virtual void draw_color_variant();
    virtual void run_death_reaction();
    virtual void run_hit_reaction();
    virtual void run_miss_reaction();
    virtual void refresh_target();
    s32 get_phase();
    void init_size_tier_and_offsets();
    TObjPlayer *find_nearby_target();
    // flags 0x2 (its bomb hit): laugh (state 8) instead; the Re2 Flower twin's check_hit_flag.
    s32 check_hit_flag();
    void sync_center_position();
    static void load_resources();
    static void free_shared_instances();
    static void *create(void *set_data);
    static void update_particle_effect(NJS_OBJECT *);
    // inferred: footstep sound plus splash or dust on frames 5, 15 and 25 of a rush step (Dell Biter's
    // play_step_effect shape).
    void play_step_effect();
    void get_node_position(Vec *out, s32 node);
    // The bomb sets flags 0x2 on its owner when it hits (the Re2 Flower twin's notify_bomb_hit).
    void notify_bomb_hit();
    s32 get_clamped_level();
    // dispatch_action's states 0-12, named by the motions they request through mericarol_motion_actions
    // (atack0 damage1 dead2 fire3 laugh4 wait5 wait2_6 wake7) and what they do, with the Re2 Flower
    // twin's names: hidden 0, fade_in 1, wait 2, chase_target 3, shoot 4 (fire, the bomb), attack 5
    // (atack), rush 6 (the 200-unit rush), curse 7 (EffCurse3 plus set_tp(0)), laugh 8, cast_technique 9
    // (TTecKafun), damaged 10, die 11 (dead, sinks), destroy 12.
    void state_cast_technique(s32 reason);
    void state_laugh(s32 reason);
    void state_destroy(s32 reason);
    void state_die(s32 reason);
    void state_wait(s32 reason);
    void state_hidden(s32 reason);
    void state_damaged(s32 reason);
    void state_curse(s32 reason);
    s32 check_attack_hits();
    void state_rush(s32 reason);
    void state_attack(s32 reason);
    void state_shoot(s32 reason);
    void state_chase_target(s32 reason);
    void state_fade_in(s32 reason);
    // The persistent move sound of the walking states (Bringer's play_move_sound shape).
    void play_move_sound();
    // Empty here; the Re2 Flower twin's states call its clear/set_child_flags at the same points.
    void clear_child_flags();
    void set_child_flags();
    TAttackTraceStrip *trails[2];          // fed the two sampled arm points each swipe frame
    RenderFadeState camera_fades[4];   // one per split-screen camera
    u32 flags;                         // 0x10 while it has a target, 0x400 for the rare colour
    f32 draw_offset_y;                 // render's translate_matrix y
    f32 rush_chance;                   // chance to rush (state 6) when hurt
    f32 rush_speed;
    f32 technique_chance;              // chance to cast (state 9) instead of swiping
    s32 m_44c;
    s32 retarget_counter;              // tick_period_counter of the chase's target search
    s32 hit_cooldown;                  // only zeroed here; the Re2 Flower twin's hit cooldown
    s32 blink_level;                   // only zeroed here; the Re2 Flower twin's blink level
    s32 phase;                         // 0..2: param table and texture set
    Vec shot_origin;                   // node 0x43, where the bomb starts
    TUnk_80494938 appear_fade;
    AreaAttackHistory *attack_history;
    TObjCollidable *attack_body;       // the swipe's 50-radius hit body
    s32 state_step;                    // step inside the current state
    s32 state_timer;                   // frame counter of the current state
    s32 rush_delay;                    // frames before the rush starts
    s32 m_49c;
    s32 target_angle;                  // rotation_y turns toward it
    f32 slide_speed;                   // the rush's slowing speed; the death sink depth
    f32 rush_distance;                 // the rush stops at 200
    TParticleCtrl *charge_effect;      // destroyed when the shot ends, as the Re2 Flower twin's
};

extern TObjEneBm9MericarolParams *mericarol_phase_param_table[3];

// MericarolData.cpp: the battle-parameter ids of the three phases, one table per TLobby lookup.
extern const u32 mericarol_phase_hp_ids[3];
extern const u32 mericarol_phase_attack_ids[3];
extern const u32 mericarol_phase_resist_ids[3];
extern const u32 mericarol_phase_param_ids[3];

LAYOUT_ASSERT(TObjEneBm9MericarolParams_size, sizeof(TObjEneBm9MericarolParams) == 0x30);
LAYOUT_ASSERT(TObjEneBm9MericarolFadeOffset, offsetof(TObjEneBm9Mericarol, appear_fade) == 0x46C);
LAYOUT_ASSERT(TObjEneBm9Mericarol_size, sizeof(TObjEneBm9Mericarol) == 0x4B0);
#endif
