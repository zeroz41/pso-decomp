#ifndef PSO_MISC_TOSWITCHITEM_H
#define PSO_MISC_TOSWITCHITEM_H

#include "types.h"
#include "pso/misc/TOKey.h"

struct TOSwitchItem : public TOKey {
    virtual ~TOSwitchItem();
    virtual void send_switch_on();
    virtual void debug_draw_key_id();
    void run_task();
    void update_anim();
    void render();
    static void *create(void *arg0);
    f32 m_e8;
    u8 unk_EC[0x4];
    s32 m_f0;
    u8 unk_F4[0x4];
};

typedef char TOSwitchItem_size[sizeof(TOSwitchItem) == 0xF8 ? 1 : -1];
#endif
