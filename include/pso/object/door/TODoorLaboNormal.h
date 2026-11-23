#ifndef PSO_OBJECT_DOOR_TODOORLABONORMAL_H
#define PSO_OBJECT_DOOR_TODOORLABONORMAL_H

#include "types.h"
#include "pso/object/door/TODoorFourLightBase.h"

struct TODoorLaboNormal : public TODoorFourLightBase {
    TODoorLaboNormal(TObject *parent, void *set_data);
    virtual ~TODoorLaboNormal();
    static void *create(void *set_data);
    virtual s32 get_unlit_textures();
    virtual s32 get_lit_textures();
    void init_field_d4();
};

LAYOUT_ASSERT(TODoorLaboNormal_size, sizeof(TODoorLaboNormal) == 0xFC);
#endif
