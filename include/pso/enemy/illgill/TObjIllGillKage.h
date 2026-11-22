#ifndef PSO_ENEMY_ILLGILL_TOBJILLGILLKAGE_H
#define PSO_ENEMY_ILLGILL_TOBJILLGILLKAGE_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjIllGillKage : public TObjBase {
    TObjIllGillKage(saddr, uaddr);
    virtual ~TObjIllGillKage();
    virtual void render();
    virtual void run_task();
    u32 state;      // run_task: 0 attack_target, 1 tick_persistent_sound, then queue_destruction
    s32 timer;      // frames the effect lasts (180); play_effect gets it, tick_persistent_sound counts it down
    u16 target_id;  // entity id of the player it was spawned on
    void queue_destruction();
    void attack_target();
    u8 pad_9A[0x2];
    void tick_persistent_sound();
};

LAYOUT_ASSERT(TObjIllGillKage_size, sizeof(TObjIllGillKage) == 0x9C);
#endif
