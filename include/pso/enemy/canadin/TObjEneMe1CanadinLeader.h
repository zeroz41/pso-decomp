#ifndef PSO_ENEMY_CANADIN_TOBJENEME1CANADINLEADER_H
#define PSO_ENEMY_CANADIN_TOBJENEME1CANADINLEADER_H

#include <stddef.h>
#include "types.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin.h"

struct TObjEneMe1CanadinLeader : public TObjEneMe1Canadin {
    TObjEneMe1CanadinLeader(TObject *parent, void *set_data);
    virtual ~TObjEneMe1CanadinLeader();
    virtual void run_task();
    virtual void select_next_attack_state();
    virtual void select_model();
    virtual void spawn_members();
    virtual s32 check_retreat_trigger();
    virtual int has_no_members();
    virtual void vfunc_110(s32);
    virtual void vfunc_111(s32);
    virtual void state_dead(s32);
    virtual void apply_model_color();
    virtual int can_member_attack_target(TObjChara *);
    virtual void remove_member(uaddr);
    s32 m_4CC;
    s32 m_4D0;
    TObjEneMe1Canadin *m_4D4[8];
    s32 m_4F4;
    void update_formation_state();
    static void *create(void *set_data);
    static TObjEneMe1Canadin *create_canadin(TObjEneMe1Canadin *leader, Vec *position, s32 id, s32 index);
};

LAYOUT_ASSERT(TObjEneMe1CanadinLeader_size, sizeof(TObjEneMe1CanadinLeader) == 0x4F8);

LAYOUT_ASSERT(CanadinLeaderMembersOffset, offsetof(TObjEneMe1CanadinLeader, m_4D4) == 0x4D4);

#endif
