#ifndef PSO_ENEMY_GIGUE_TOBJENEME1GIGUEBARRIER_H
#define PSO_ENEMY_GIGUE_TOBJENEME1GIGUEBARRIER_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjEneMe1GiGue;

struct TObjEneMe1GiGueBarrier : public TObjMotion {
    TObjEneMe1GiGueBarrier(TObject *parent, void *owner);
    virtual ~TObjEneMe1GiGueBarrier();
    TObjEneMe1GiGue *m_fc;
    u16 m_100;
    u8 _pad102[0x2];
    u32 m_104;
    s32 m_108;
    virtual void render();
    virtual void run_task();
    static void *create(void *arg0, void *arg1);
    static void init_global();
};

typedef char TObjEneMe1GiGueBarrier_size[sizeof(TObjEneMe1GiGueBarrier) == 0x10C ? 1 : -1];
#endif
