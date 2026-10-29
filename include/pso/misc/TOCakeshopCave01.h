#ifndef PSO_MISC_TOCAKESHOPCAVE01_H
#define PSO_MISC_TOCAKESHOPCAVE01_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

struct TOCakeshopCave01 : public TObjMapObject {
    TOCakeshopCave01(void *set_data);
    virtual ~TOCakeshopCave01();
    void update_blink_state(s32 index);
    virtual void run_task();
    virtual void render();
    static void *create(void *set_data);
    static void release_static_resource();
    static void load_shared_resource();
    u8 pad_c8[4];
    f32 blink_fade[8];  // counts up while a light is lit, 0 to -1 while it is off
    u8 blink_state[8];  // 0 lit, 1 fading out, 2 fading back in
};

typedef char TOCakeshopCave01_size[sizeof(TOCakeshopCave01) == 0xF4 ? 1 : -1];

#endif
