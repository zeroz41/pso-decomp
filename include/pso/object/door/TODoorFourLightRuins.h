#ifndef PSO_OBJECT_DOOR_TODOORFOURLIGHTRUINS_H
#define PSO_OBJECT_DOOR_TODOORFOURLIGHTRUINS_H

#include "types.h"
#include "pso/object/door/TODoorBase.h"

struct TODoorFourLightRuins : public TODoorBase {
    TODoorFourLightRuins(saddr, saddr);
    virtual ~TODoorFourLightRuins();
    virtual s32 init_door_switch_binding();
    virtual void update_door_switch_state();
    virtual void vfunc_6(s16 *, s32);
    uaddr m_d4;
    static void draw_model_and_lights(void *arg0);
    virtual void render();
    u8 unk_D8[0x20];
};

LAYOUT_ASSERT(TODoorFourLightRuins_size, sizeof(TODoorFourLightRuins) == 0xF8);
#endif
