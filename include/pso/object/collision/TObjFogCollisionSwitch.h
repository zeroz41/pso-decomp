#ifndef PSO_OBJECT_COLLISION_TOBJFOGCOLLISIONSWITCH_H
#define PSO_OBJECT_COLLISION_TOBJFOGCOLLISIONSWITCH_H

#include "types.h"
#include "pso/object/collision/TObjFogCollision.h"

struct TObjFogCollisionSwitch : public TObjFogCollision {
    TObjFogCollisionSwitch(TObject *parent, void *set);
    virtual ~TObjFogCollisionSwitch();
    s32 get_switch_mode();
    virtual void vfunc_14();
    virtual void vfunc_13(s32);
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjFogCollisionSwitch_size, sizeof(TObjFogCollisionSwitch) == 0x98);
#endif
