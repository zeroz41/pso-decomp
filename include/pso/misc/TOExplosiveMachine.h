#ifndef PSO_MISC_TOEXPLOSIVEMACHINE_H
#define PSO_MISC_TOEXPLOSIVEMACHINE_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TOExplosiveMachine : public TObjBase {
    virtual ~TOExplosiveMachine();
    virtual void run_task();
    u8 unk_90[0x4];
    f32 m_94;
    u8 unk_98[0x4];
    u32 m_9c;
    u32 m_a0;
    u32 m_a4;
    u32 m_a8;
    void explode();
    static void destroy_static_lobby();
    static void load_shared_resource();
    s32 check_trigger();
    s32 update_trigger();
    void update();
};

typedef char TOExplosiveMachine_size[sizeof(TOExplosiveMachine) == 0xAC ? 1 : -1];
#endif
