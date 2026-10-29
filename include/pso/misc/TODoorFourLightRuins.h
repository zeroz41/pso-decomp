#ifndef PSO_MISC_TODOORFOURLIGHTRUINS_H
#define PSO_MISC_TODOORFOURLIGHTRUINS_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct TODoorFourLightRuins : public TODoorBase {
    virtual ~TODoorFourLightRuins();
    virtual s32 init_door_switch_binding();
    virtual void update_door_switch_state();
    virtual void vfunc_6(s16 *, s32);
    u32 m_d4;
    static s32 draw_model_and_lights(void *arg0);
    virtual void render();
    u8 unk_D8[0x20];
};

typedef char TODoorFourLightRuins_size[sizeof(TODoorFourLightRuins) == 0xF8 ? 1 : -1];
#endif
