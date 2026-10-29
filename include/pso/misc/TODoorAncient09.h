#ifndef PSO_MISC_TODOORANCIENT09_H
#define PSO_MISC_TODOORANCIENT09_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct TODoorAncient09 : public TODoorBase {
    virtual ~TODoorAncient09();
    void sub_80160968();
    void door_ancient09_sync_state(void *);
    virtual void update_demo();
    virtual s32 init_door_switch_binding();
    virtual void update_open();
    virtual void update_closed();
    virtual void update_door_switch_state();
    virtual void vfunc_6(s16 *, s32);
    u16 m_d4;
    u8 _padD6[0x2];
    u32 m_d8;
    u32 m_dc;
    u32 m_e0;
    u32 m_e4;
    void draw_model();
    virtual void render();
    static void *create(void *arg0);
    static void free_rocks();
    static void load_resources();
};

typedef char TODoorAncient09_size[sizeof(TODoorAncient09) == 0xE8 ? 1 : -1];
extern "C" {
void *__dt__15TODoorAncient09Fv(void *arg0, s16 arg1);
}

#endif
