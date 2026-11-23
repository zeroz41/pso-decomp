#ifndef PSO_OBJECT_COLLISION_TOBJEVTCOLLISION_H
#define PSO_OBJECT_COLLISION_TOBJEVTCOLLISION_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjEvtCollision : public TObjCollidable {
    TObjEvtCollision(TObject *parent, void *set_data);
    virtual ~TObjEvtCollision();
    f32 trigger_radius;
    u32 m_b0;
    s32 countdown;
    s32 is_any_player_in_range(f32 farg0);
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjEvtCollision_size, sizeof(TObjEvtCollision) == 0xB8);
#endif
