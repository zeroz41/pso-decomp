#ifndef PSO_MISC_TOKEYJUNGLEMAIN_H
#define PSO_MISC_TOKEYJUNGLEMAIN_H

#include "types.h"
#include "pso/misc/TOKey.h"

struct TOKeyJungleMain : public TOKey {
    virtual ~TOKeyJungleMain();
    virtual void update_lock_state();
    virtual void update_switch_on();
    virtual void update_switch_off();
    virtual void send_switch_on();
    virtual void debug_draw_key_id();
    virtual void play_activate_sound();
    void render();
    static void init_key_slots(void* _w0);
    f32 m_e8;
    u8 unk_EC[0x4];
    static void dispatch_by_phase(s32 arg0, u16 arg1);
    static void *create(void *arg0);
    static void release_static_resource();
    static void load_static_resource();
};

typedef char TOKeyJungleMain_size[sizeof(TOKeyJungleMain) == 0xF0 ? 1 : -1];
#endif
