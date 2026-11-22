#ifndef PSO_ENEMY_GEE_TOBJENEME1GEELEADER_H
#define PSO_ENEMY_GEE_TOBJENEME1GEELEADER_H
#include "types.h"
#include "pso/enemy/gee/TObjEneMe1Gee.h"

// The Gee formation leader (vtable 0x8049387C). Name inferred: no class string (its ctor installs the
// "TObjEneMe1Gee" name), but its table is TObjEneMe1CanadinLeader's slot for slot (same size, the same 13
// leader overrides: dtor, run_task, spawn_members, remove_member, select_model, ... in the same slots).
class TObjEneMe1GeeLeader : public TObjEneMe1Gee {
public:
    virtual ~TObjEneMe1GeeLeader();
    void run_task();
    virtual void spawn_members();
    virtual void remove_member(TObjEneMe1Gee *member);
    virtual void select_model();
    virtual void select_next_attack_state();
    virtual s32 check_retreat_trigger();
    virtual int can_member_attack_target(TObjChara *target);
    virtual void apply_model_color();
    virtual int has_no_members();
    virtual void state_activate(s32);
    virtual void state_rise(s32);
    virtual void state_dead(s32);
    void update_formation_state();
    s32 member_total;
    s32 member_count;
    TObjEneMe1Gee *members[8];
    u32 formation_state;
};

#endif
