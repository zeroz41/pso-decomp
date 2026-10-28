#ifndef PSO_OBJECT_TOBJILLGILLKAGE_H
#define PSO_OBJECT_TOBJILLGILLKAGE_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjIllGillKage : public TObjBase {
    virtual ~TObjIllGillKage();
    virtual void render();
    virtual void run_task();
    u32 m_90;
    u32 m_94;
    u16 m_98;
    int queue_destruction();
    void attack_target();
    u8 unk_9A[0x2];
    void tick_persistent_sound();
};

typedef char TObjIllGillKage_size[sizeof(TObjIllGillKage) == 0x9C ? 1 : -1];
#endif
