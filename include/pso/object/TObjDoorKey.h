#ifndef PSO_OBJECT_TOBJDOORKEY_H
#define PSO_OBJECT_TOBJDOORKEY_H

#include "types.h"
#include "pso/misc/TOKey.h"

struct TObjDoorKey : public TOKey {
    virtual ~TObjDoorKey();
    virtual void trigger_activate_sound();
    virtual void update_armed_switch();
    virtual void update_switch_off();
    virtual void update_switch_on();
    virtual void trigger_deactivate_sound();
    virtual void debug_draw_key_id();
    void render();
    s32 draw_active_beam();
    s32 draw_inactive_badge();
    void run_task();
    static void free_key();
    static void load_resources();
    s32 m_e8;
    u8 unk_EC[0x4];
    s32 m_f0;
    u8 unk_F4[0x4];
    u32 m_f8;
};

typedef char TObjDoorKey_size[sizeof(TObjDoorKey) == 0xFC ? 1 : -1];

extern "C" {
void *TObjDoorKey__create(void *arg0);
void *TObjDoorKey__ct(TObjDoorKey *arg0, void *arg1, void *arg2);
void TObjDoorKey__sub_8018FAEC(void);
void trigger_activate_sound__11TObjDoorKeyFv(u8 *arg0);
void *TObjEnvSoundGlobal__create(void *arg0);
void *__dt__11TObjDoorKeyFv(void *arg0, s16 arg1);
}

#endif
