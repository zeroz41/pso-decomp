#ifndef PSO_ENEMY_GEE_TUNK_8049387C_H
#define PSO_ENEMY_GEE_TUNK_8049387C_H
#include "types.h"
#include "pso/enemy/gee/TObjEneMe1Gee.h"

class TUnk_8049387C : public TObjEneMe1Gee {
public:
    virtual ~TUnk_8049387C();
    void run_task();
    virtual void spawn_members();
    virtual void remove_member(uaddr);
    virtual void select_model();
    virtual void select_next_attack_state();
    virtual s32 check_retreat_trigger();
    virtual int can_member_attack_target(TObjChara *target);
    virtual void apply_model_color();
    virtual int has_no_members();
    virtual void vfunc_110(s32);
    virtual void vfunc_111(s32);
    virtual void state_dead(s32);
    void update_formation_state();
    s32 member_total;
    s32 member_count;
    TObjEneMe1Gee *members[8];
    u32 formation_state;
};

#endif
