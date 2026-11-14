#ifndef PSO_OBJECT_DOOR_TODOORFOURLIGHTSEABED_H
#define PSO_OBJECT_DOOR_TODOORFOURLIGHTSEABED_H

#include "types.h"
#include "pso/object/door/TODoorFourLightBase.h"

struct TODoorFourLightSeabed : public TODoorFourLightBase {
    virtual ~TODoorFourLightSeabed();
    virtual s32 vfunc_21();
    virtual s32 vfunc_22();
};
typedef char TODoorFourLightSeabed_size[sizeof(TODoorFourLightSeabed) == 0xFC ? 1 : -1];

#endif
