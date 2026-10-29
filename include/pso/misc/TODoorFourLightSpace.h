#ifndef PSO_MISC_TODOORFOURLIGHTSPACE_H
#define PSO_MISC_TODOORFOURLIGHTSPACE_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct TODoorFourLightSpace : public TODoorBase {
    virtual ~TODoorFourLightSpace();
    virtual s32 init_door_switch_binding();
    virtual void update_door_switch_state();
    virtual void vfunc_6(s16 *, s32);
    u32 m_d4;
    s32 draw_lights();
    virtual void render();
    u8 unk_D8[0x20];
};

typedef char TODoorFourLightSpace_size[sizeof(TODoorFourLightSpace) == 0xF8 ? 1 : -1];
#endif
