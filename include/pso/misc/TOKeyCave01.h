#ifndef PSO_MISC_TOKEYCAVE01_H
#define PSO_MISC_TOKEYCAVE01_H

#include "types.h"
#include "pso/misc/TOKey.h"

struct TOKeyCave01 : public TOKey {
    virtual ~TOKeyCave01();
    virtual void trigger_activate_sound();
    virtual s32 is_confirm_pressed();
    virtual void update_switch_on();
    virtual void update_switch_off();
    virtual void trigger_deactivate_sound();
    virtual void vfunc_25();
    void send_switch_changed(s32 flags);
    void run_task();
    void render();
    static void *create(void *arg0);
    static void free_objects();
    static void load_resources();
    f32 m_e8;
    f32 m_ec;
    u8 unk_F0[0x4];
    f32 m_f4;
    s32 m_f8;
    u8 unk_FC[0x4];
};

typedef char TOKeyCave01_size[sizeof(TOKeyCave01) == 0x100 ? 1 : -1];
#endif
