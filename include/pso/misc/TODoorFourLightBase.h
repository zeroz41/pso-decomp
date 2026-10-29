#ifndef PSO_MISC_TODOORFOURLIGHTBASE_H
#define PSO_MISC_TODOORFOURLIGHTBASE_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct TODoorFourLightBase : public TODoorBase {
    virtual ~TODoorFourLightBase();
    virtual void vfunc_21() = 0;
    virtual void vfunc_22() = 0;
    virtual s32 init_door_switch_binding();
    virtual void update_door_switch_state();
    virtual void vfunc_6(s16 *, s32);
    virtual void render();
    u32 m_d4;
    u8 unk_D8[0x4];
    u32 m_dc;
    u8 unk_E0[0x18];
    u32 m_f8;
    void clamp_light_index();
    void render_lights();
    void draw_node_tree(u8 *arg1);
};

typedef char TODoorFourLightBase_size[sizeof(TODoorFourLightBase) == 0xFC ? 1 : -1];
#endif
