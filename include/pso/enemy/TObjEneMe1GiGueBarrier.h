#ifndef PSO_ENEMY_TOBJENEME1GIGUEBARRIER_H
#define PSO_ENEMY_TOBJENEME1GIGUEBARRIER_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjEneMe1GiGueBarrier : public TObjMotion {
    TObjEneMe1GiGueBarrier(TObject *parent, void *owner);
    virtual ~TObjEneMe1GiGueBarrier();
    u32 m_fc;
    u16 m_100;
    u8 _pad102[0x2];
    u32 m_104;
    u32 m_108;
    virtual void render();
    virtual void run_task();
    static void *create(void *arg0, void *arg1);
    static void init_global();
    void clear_flag388_bit80000();
    u8 is_active_state();
    s32 get_field_44c();
    s32 get_timer();
    void*update_and_get_pos();
};

typedef char TObjEneMe1GiGueBarrier_size[sizeof(TObjEneMe1GiGueBarrier) == 0x10C ? 1 : -1];
#endif
