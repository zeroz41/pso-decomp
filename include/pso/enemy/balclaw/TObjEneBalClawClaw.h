#ifndef PSO_ENEMY_BALCLAW_TOBJENEBALCLAWCLAW_H
#define PSO_ENEMY_BALCLAW_TOBJENEBALCLAWCLAW_H

struct EnemyPlacement;

#include "types.h"
#include "pso/enemy/balclaw/TObjEneBalClaw.h"

struct TObjEneBalClawBody;

struct TObjEneBalClawClaw : public TObjEneBalClaw {
    TObjEneBalClawClaw(TObject *parent, TObjEneBalClawBody *body, u16 id, s32 index, const Vec *pos, s32 rot_y, s32);
    TObjEneBalClawClaw(TObject *parent, EnemyPlacement *set_data);
    virtual ~TObjEneBalClawClaw();
    void init();
    virtual void run_task();
    virtual void render();
    void update_attack_distance_state();
    // update_state's mode handlers (the Body twin uses the same modes and names).
    void update_wait();
    void update_chase();
    void update_attack();
    void update_damage();
    void run_death_sequence();
    void update_appear();
    void update_return_home();
    void update_drop();
    void update_follow_parent();
    void run_active_state();
    void update_retreat();
    void detach();
    void detach_at(Vec *pos, s32 rot_y, s16 hp);
    virtual void run_idle_action();
    void load_params();
    void run_demo_task();
    void update_state();
    static TObjEneBalClawClaw *create_from_body(TObjEneBalClawBody *body, u16 id, s32 index, const Vec *pos, s32 rot_y, s32 hp);
    static void *create(void *set_data);
    static void load_resources();  // registers the claw model for the NPC model registry
    static void free_resources();
    f32 target_distance_sq;  // xz distance squared to where it is moving (the body while following it)
    u8 pad_3c4[0x2];
    u16 body_id;  // entity id of the body it follows
    s16 retreat_timer;  // frames left to back away from the target (update_retreat)
    u8 pad_3ca[0x5E];
    void attach();
    void clear_flag();
    void join_body(u16 body_id);
    s32 check_active();
    void reset_active_state();
};

LAYOUT_ASSERT(TObjEneBalClawClaw_size, sizeof(TObjEneBalClawClaw) == 0x428);


#endif
