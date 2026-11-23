#ifndef PSO_OBJECT_DOOR_TODOORFOURLIGHTRUINS_H
#define PSO_OBJECT_DOOR_TODOORFOURLIGHTRUINS_H

#include "types.h"
#include "pso/object/door/TODoorBase.h"
#include "pso/system/NinjaTypes.h"

struct TODoorFourLightRuins : public TODoorBase {
    TODoorFourLightRuins(saddr, saddr);
    virtual ~TODoorFourLightRuins();
    virtual s32 init_door_switch_binding();
    virtual void update_door_switch_state();
    virtual void vfunc_6(s16 *, s32);
    uaddr m_d4;
    // Draws the door, its four switch lights green when their switch is set.
    void draw_model_and_lights();
    virtual void render();
    // The model nodes of the four switch lights: the lamps, then their glows.
    NJS_OBJECT *light_nodes[8];
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TODoorFourLightRuins_size, sizeof(TODoorFourLightRuins) == 0xF8);
#endif
