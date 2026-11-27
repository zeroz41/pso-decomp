#ifndef PSO_OBJECT_DOOR_TODOORFOURLIGHTSEABED_H
#define PSO_OBJECT_DOOR_TODOORFOURLIGHTSEABED_H

#include "types.h"
#include "pso/object/door/TODoorFourLightBase.h"

struct TODoorFourLightSeabed : public TODoorFourLightBase {
    TODoorFourLightSeabed(TObject *parent, ObjectSetData *set_data);
    virtual ~TODoorFourLightSeabed();
    static void *create(ObjectSetData *set_data);
    virtual s32 get_unlit_textures();
    virtual s32 get_lit_textures();
};
LAYOUT_ASSERT(TODoorFourLightSeabed_size, sizeof(TODoorFourLightSeabed) == 0xFC);

#endif
