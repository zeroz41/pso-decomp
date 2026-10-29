#ifndef PSO_MISC_TODOORANCIENT08_H
#define PSO_MISC_TODOORANCIENT08_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct TODoorAncient08 : public TODoorBase {
    virtual ~TODoorAncient08();
    void door_ancient08_sync_state(void *);
    virtual void update_demo();
    virtual s32 init_door_switch_binding();
    virtual void update_open();
    virtual void update_closed();
    virtual void update_door_switch_state();
    virtual void vfunc_6(s16 *, s32);
    u16 m_d4;
    u16 m_d6;
    u16 m_d8;
    u8 _padDA[0x2];
    u32 m_dc;
    u32 m_e0;
    u32 m_e4;
    u32 m_e8;
    void play_open_sound();
    void draw_switch_lights();
    virtual void render();
    static void *create(void *arg0);
    static void free_objects();
    static void load_resources();
};

typedef char TODoorAncient08_size[sizeof(TODoorAncient08) == 0xEC ? 1 : -1];
extern "C" {
u8 *TODoorAncient08__ct(TODoorAncient08 *arg0, s32 arg1, s32 arg2);
void *__dt__15TODoorAncient08Fv(void *arg0, s16 arg1);
}

#endif
