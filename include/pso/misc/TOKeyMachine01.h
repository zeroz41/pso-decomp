#ifndef PSO_MISC_TOKEYMACHINE01_H
#define PSO_MISC_TOKEYMACHINE01_H

#include "types.h"
#include "pso/misc/TOKey.h"

struct TOKeyMachine01 : public TOKey {
    virtual ~TOKeyMachine01();
    virtual void trigger_activate_sound();
    virtual s32 is_confirm_pressed();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_19();
    virtual void vfunc_25();
    u8 unk_D8[0x4];
    u32 m_dc;
    void run_task();
    void render();
    static void *create(void *arg0);
    static void free_statics();
    static void load_assets();
    void send_switch_changed(s32 flags);
    u8 unk_E0[0x8];
    f32 m_e8;
    f32 m_ec;
    u8 unk_F0[0x4];
    f32 m_f4;
    s32 m_f8;
};

typedef char TOKeyMachine01_size[sizeof(TOKeyMachine01) == 0xFC ? 1 : -1];
#endif
