#ifndef PSO_OBJECT_DOOR_TOBJDOORJUNG_H
#define PSO_OBJECT_DOOR_TOBJDOORJUNG_H

#include "types.h"
#include "pso/object/door/TODoorBase.h"

struct TObjDoorJung : public TODoorBase {
    TObjDoorJung(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjDoorJung();
    void clamp_state();
    virtual void update_door_switch_state();
    virtual void run_task();
    virtual void render();
    s32 active_light_count;
    static void free_buffers();
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TObjDoorJung_size, sizeof(TObjDoorJung) == 0xD8);
void load_door_jung_resources(void);

#endif
