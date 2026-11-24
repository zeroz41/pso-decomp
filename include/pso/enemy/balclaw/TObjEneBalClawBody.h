#ifndef PSO_ENEMY_BALCLAW_TOBJENEBALCLAWBODY_H
#define PSO_ENEMY_BALCLAW_TOBJENEBALCLAWBODY_H

struct EnemyPlacement;

#include "types.h"
#include "pso/enemy/balclaw/TObjEneBalClaw.h"

class TParticleCtrl;

struct TObjEneBalClawBody : public TObjEneBalClaw {
    TObjEneBalClawBody(TObject *parent, EnemyPlacement *set_data);
    virtual ~TObjEneBalClawBody();
    void sub_800C73F4();
    int get_flag_0x388_b24();
    s32 get_int_parameter(s32 i);  // balclaw_body_behavior_params[variant]->int_params[i]
    virtual void run_task();
    virtual void render();
    virtual void run_attack_action();
    virtual void run_idle_action();
    void load_params();
    void update_return_home();
    s32 summon_claws();
    void update_split();
    void update_combine();
    void update_appear();
    void update_combined_attack();
    void update_attack();
    void update_damage();
    void update_chase();
    void run_death_sequence();
    void update_retreat();
    void reset_enemy_state();
    void set_form(s32 form);
    void show_claw_arms(s32 count);
    void calc_slot_offset_position(s32 slot, Vec *out, s32 *angle_out);
    void run_demo_task();
    void update_attack_distance_state();
    void update_state();
    void update_wait();
    static void *create(void *set_data);
    static void load_resources();  // registers the bcbody model for the NPC model registry
    static void free_resources();
    f32 target_distance_sq;  // xz distance squared to the target
    u32 child_ids[4];  // entity ids of the claws; the dtor destroys the first child_count of them
    s32 form_timer;  // frames since the last merge/split (not counted while idle or returning home)
    s16 child_count;  // how many of child_ids are in use (the ctor sets 4)
    s16 melee_hit_count;  // melee hits landed since set_form(1); at 2, update_attack_distance_state moves to mode 0xB
    TParticleCtrl *effects[4];  // queue_destruction'd by the dtor
    Vec attack_effect_position;  // node 8, where effects[2] and [3] (particles 0x12B/0x12C) sit
    s32 attack_effect_angle[3];  // their direction
};

LAYOUT_ASSERT(TObjEneBalClawBody_size, sizeof(TObjEneBalClawBody) == 0x404);
#endif
