#ifndef PSO_OBJECT_TOBJEVTCOLLISION_H
#define PSO_OBJECT_TOBJEVTCOLLISION_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjEvtCollision : public TObjCollidable {
    virtual ~TObjEvtCollision();
    u8 unk_AC[0x4];
    u32 m_b0;
    u32 m_b4;
    s32 is_any_player_in_range(f32 farg0);
    virtual void render();
    virtual void run_task();
};

typedef char TObjEvtCollision_size[sizeof(TObjEvtCollision) == 0xB8 ? 1 : -1];
#endif
