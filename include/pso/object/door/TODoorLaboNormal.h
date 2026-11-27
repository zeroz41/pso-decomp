#ifndef PSO_OBJECT_DOOR_TODOORLABONORMAL_H
#define PSO_OBJECT_DOOR_TODOORLABONORMAL_H

#include "types.h"
#include "pso/object/door/TODoorFourLightBase.h"

struct TODoorLaboNormal : public TODoorFourLightBase {
    TODoorLaboNormal(TObject *parent, ObjectSetData *set_data);
    virtual ~TODoorLaboNormal();
    static void *create(ObjectSetData *set_data);
    virtual s32 get_unlit_textures();
    virtual s32 get_lit_textures();
    void load_model();
};

LAYOUT_ASSERT(TODoorLaboNormal_size, sizeof(TODoorLaboNormal) == 0xFC);
#endif
