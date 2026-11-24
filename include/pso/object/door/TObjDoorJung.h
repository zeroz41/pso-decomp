#ifndef PSO_OBJECT_DOOR_TOBJDOORJUNG_H
#define PSO_OBJECT_DOOR_TOBJDOORJUNG_H

#include "types.h"
#include "pso/object/door/TODoorBase.h"

struct TObjDoorJung : public TODoorBase {
    TObjDoorJung(TObject *parent, void *set_data);
    virtual ~TObjDoorJung();
    void clamp_state();
    virtual void update_door_switch_state();
    virtual void run_task();
    virtual void render();
    s32 active_light_count;
    static void free_buffers();
    static void *create(void *set_data);
};

extern "C" void set_material_texture_slot_on_neighbours(TObject *node, void *slot);

LAYOUT_ASSERT(TObjDoorJung_size, sizeof(TObjDoorJung) == 0xD8);
#endif
