#ifndef PSO_OBJECT_DOOR_TODOORFOURLIGHTSPACE_H
#define PSO_OBJECT_DOOR_TODOORFOURLIGHTSPACE_H

#include "types.h"
#include "pso/object/door/TODoorBase.h"

struct TODoorFourLightSpace : public TODoorBase {
    TODoorFourLightSpace(saddr, saddr);
    virtual ~TODoorFourLightSpace();
    virtual s32 init_door_switch_binding();
    virtual void update_door_switch_state();
    virtual void vfunc_6(s16 *, s32);
    uaddr m_d4;
    void draw_lights();
    virtual void render();
    u8 unk_D8[0x20];
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TODoorFourLightSpace_size, sizeof(TODoorFourLightSpace) == 0xF8);
#endif
