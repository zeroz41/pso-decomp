#ifndef PSO_OBJECT_DOOR_TODOORFOURLIGHTSPACE_H
#define PSO_OBJECT_DOOR_TODOORFOURLIGHTSPACE_H

#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/object/door/TODoorBase.h"

struct TODoorFourLightSpace : public TODoorBase {
    TODoorFourLightSpace(saddr, saddr);
    virtual ~TODoorFourLightSpace();
    virtual s32 init_door_switch_binding();
    virtual void update_door_switch_state();
    virtual void apply_saved_state(s16 *, s32);
    uaddr model_tree;  // the door model's node tree
    void draw_lights();
    virtual void render();
    // The model nodes of the four switch lights: the lamps, then their glows.
    NJS_OBJECT *light_nodes[8];
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TODoorFourLightSpace_size, sizeof(TODoorFourLightSpace) == 0xF8);
extern "C" void fn_802898EC(void);
extern "C" void fn_802898E8(void);

#endif
