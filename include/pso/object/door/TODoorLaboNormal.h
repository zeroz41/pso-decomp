#ifndef PSO_OBJECT_DOOR_TODOORLABONORMAL_H
#define PSO_OBJECT_DOOR_TODOORLABONORMAL_H

#include "types.h"
#include "pso/object/door/TODoorFourLightBase.h"

struct TODoorLaboNormal : public TODoorFourLightBase {
    virtual ~TODoorLaboNormal();
    virtual s32 vfunc_21();
    virtual s32 vfunc_22();
    void init_field_d4();
};

LAYOUT_ASSERT(TODoorLaboNormal_size, sizeof(TODoorLaboNormal) == 0xFC);
#endif
