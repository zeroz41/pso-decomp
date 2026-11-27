#ifndef PSO_OBJECT_DOOR_TODOORFOURLIGHTSEABEDU_H
#define PSO_OBJECT_DOOR_TODOORFOURLIGHTSEABEDU_H

#include "types.h"
#include "pso/object/door/TODoorFourLightBase.h"

struct TODoorFourLightSeabedU : public TODoorFourLightBase {
    TODoorFourLightSeabedU(TObject *parent, ObjectSetData *set_data);
    virtual ~TODoorFourLightSeabedU();
    static void *create(ObjectSetData *set_data);
    virtual s32 get_unlit_textures();
    virtual s32 get_lit_textures();
};
LAYOUT_ASSERT(TODoorFourLightSeabedU_size, sizeof(TODoorFourLightSeabedU) == 0xFC);

#endif
