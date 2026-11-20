#ifndef PSO_ENEMY_ILLGILL_TOBJILLGILLKAGE_H
#define PSO_ENEMY_ILLGILL_TOBJILLGILLKAGE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjIllGillKage : public TObjBase {
    TObjIllGillKage(saddr, uaddr);
    virtual ~TObjIllGillKage();
    virtual void render();
    virtual void run_task();
    u32 m_90;
    u32 m_94;
    u16 m_98;
    void queue_destruction();
    void attack_target();
    u8 unk_9A[0x2];
    void tick_persistent_sound();
};

LAYOUT_ASSERT(TObjIllGillKage_size, sizeof(TObjIllGillKage) == 0x9C);
#endif
