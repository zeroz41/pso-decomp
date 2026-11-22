#ifndef PSO_ENEMY_GIGUE_TOBJENEME1GIGUEBARRIER_H
#define PSO_ENEMY_GIGUE_TOBJENEME1GIGUEBARRIER_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjEneMe1GiGue;

struct TObjEneMe1GiGueBarrier : public TObjMotion {
    TObjEneMe1GiGueBarrier(TObject *parent, void *owner);
    virtual ~TObjEneMe1GiGueBarrier();
    TObjEneMe1GiGue *owner;
    u16 owner_id;
    u8 _pad102[0x2];
    u32 phase;
    s32 timer;
    virtual void render();
    virtual void run_task();
    static void *create(void *parent, void *owner);
    static void init_global();
    static void free_global();
};

LAYOUT_ASSERT(TObjEneMe1GiGueBarrier_size, sizeof(TObjEneMe1GiGueBarrier) == 0x10C);
#endif
