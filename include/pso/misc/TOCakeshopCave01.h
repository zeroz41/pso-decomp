#ifndef PSO_MISC_TOCAKESHOPCAVE01_H
#define PSO_MISC_TOCAKESHOPCAVE01_H

#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"

struct TOCakeshopCave01 : public TUnk_804AFBF8 {
    TOCakeshopCave01(void *set_data);
    virtual ~TOCakeshopCave01();
    void update_blink_state(void *arg1);
    virtual void run_task();
    virtual void render();
    void *create();
    static void close_dialog_window();
    static void load_resource_instance();
    u8 pad_c8[4];
    f32 m_cc[8];
    u8 m_ec[8];
};

typedef char TOCakeshopCave01_size[sizeof(TOCakeshopCave01) == 0xF4 ? 1 : -1];

#endif
