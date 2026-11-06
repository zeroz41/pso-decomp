#ifndef PSO_OBJECT_COLLISION_TOBJFOGCOLLISIONSWITCH_H
#define PSO_OBJECT_COLLISION_TOBJFOGCOLLISIONSWITCH_H

#include "types.h"
#include "pso/object/collision/TObjFogCollision.h"

struct TObjFogCollisionSwitch : public TObjFogCollision {
    virtual ~TObjFogCollisionSwitch();
    s32 sub_80153A0C();
    virtual void vfunc_14();
    virtual void vfunc_13(s32);
    virtual void run_task();
};

typedef char TObjFogCollisionSwitch_size[sizeof(TObjFogCollisionSwitch) == 0x98 ? 1 : -1];
#endif
