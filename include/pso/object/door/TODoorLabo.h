#ifndef PSO_OBJECT_DOOR_TODOORLABO_H
#define PSO_OBJECT_DOOR_TODOORLABO_H

#include "types.h"
#include "pso/object/door/TODoorFourLightBase.h"

struct TODoorLabo : public TODoorFourLightBase {
    TODoorLabo(TObject *parent, void *set_data);
    virtual ~TODoorLabo();
    static void *create(void *set_data);
    virtual s32 get_unlit_textures();
    virtual s32 get_lit_textures();
    void init_model_by_type();
    static void free_resources();
    static void load_resources();
};

LAYOUT_ASSERT(TODoorLabo_size, sizeof(TODoorLabo) == 0xFC);

void load_seabed_u_four_light_door_resources(void);
void load_seabed_four_light_door_resources(void);
void free_seabed_four_light_door_resources(void);
void free_seabed_u_four_light_door_resources(void);
void load_labo_door_resources(void);
void free_labo_door_resources(void);

#endif
