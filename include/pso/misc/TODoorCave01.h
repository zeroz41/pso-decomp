#ifndef PSO_MISC_TODOORCAVE01_H
#define PSO_MISC_TODOORCAVE01_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct TODoorCave01 : public TODoorBase {
    virtual ~TODoorCave01();
    void send_state(void *);
    virtual void update_demo();
    virtual s32 init_door_switch_binding();
    virtual void update_open();
    virtual void update_closed();
    virtual void update_door_switch_state();
    virtual void vfunc_6(s16 *, s32);
    virtual void render();
    u32 m_d4;
    u32 m_d8;
    static s32 draw_door_model(void *p0, int p1, int arg2);
    static void *create(void *arg0);
    static void free_resources();
    static void load_resources();
    u8 unk_DC[0x4];
    f32 m_e0;
    u8 unk_E4[0x4];
    f32 m_e8;
};

typedef char TODoorCave01_size[sizeof(TODoorCave01) == 0xEC ? 1 : -1];

extern "C" {
void render__12TODoorCave01Fv(TODoorCave01 *arg0);
}

#endif
