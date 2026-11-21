#ifndef PSO_ENEMY_CANADIN_TOBJENEME1CANADINLEADER_H
#define PSO_ENEMY_CANADIN_TOBJENEME1CANADINLEADER_H

#include <stddef.h>
#include "types.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin.h"

struct TObjEneMe1CanadinLeader : public TObjEneMe1Canadin {
    TObjEneMe1CanadinLeader(TObject *parent, void *set_data);
    virtual ~TObjEneMe1CanadinLeader();
    virtual void run_task();
    virtual void vfunc_105();
    virtual void vfunc_106();
    virtual void vfunc_107();
    virtual s32 vfunc_108();
    virtual int vfunc_109();
    virtual void vfunc_110(s32);
    virtual void vfunc_111(s32);
    virtual void vfunc_112(s32);
    virtual void vfunc_113();
    virtual int vfunc_116(TObjChara *);
    virtual void vfunc_117(u32);
    s32 m_4CC;
    s32 m_4D0;
    TObjEneMe1Canadin *m_4D4[8];
    s32 m_4F4;
    void update_formation_state();
    static void *create(void *arg0);
    static TObjEneMe1Canadin *create_canadin(TObjEneMe1Canadin *leader, Vec *position, s32 id, s32 index);
};

typedef char TObjEneMe1CanadinLeader_size[sizeof(TObjEneMe1CanadinLeader) == 0x4F8 ? 1 : -1];

typedef char CanadinLeaderMembersOffset[offsetof(TObjEneMe1CanadinLeader, m_4D4) == 0x4D4 ? 1 : -1];

#endif
