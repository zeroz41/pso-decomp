#ifndef PSO_OBJECT_DOOR_TODOORFOURLIGHTSEABED_H
#define PSO_OBJECT_DOOR_TODOORFOURLIGHTSEABED_H

#include "types.h"
#include "pso/object/door/TODoorFourLightBase.h"

struct TODoorFourLightSeabed : public TODoorFourLightBase {
    TODoorFourLightSeabed(TObject *parent, void *set_data);
    virtual ~TODoorFourLightSeabed();
    static void *create(void *set_data);
    virtual s32 vfunc_21();
    virtual s32 vfunc_22();
};
LAYOUT_ASSERT(TODoorFourLightSeabed_size, sizeof(TODoorFourLightSeabed) == 0xFC);

#endif
