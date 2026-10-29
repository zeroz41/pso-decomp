#ifndef PSO_MISC_TODOORVOSHIP_H
#define PSO_MISC_TODOORVOSHIP_H

#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"

struct TODoorVoShip : public TUnk_804AFBF8 {
    TODoorVoShip(TObject *parent, void *set_data);
    virtual ~TODoorVoShip();
    u8 unk_C8[0x4];
    u32 light_flags;  // bits 1-3: which of the three lights still show, bit 4: brightening
    u32 light_motion;
    u32 light_model;
    u32 light_texlist;
    f32 light_color[4];  // the constant material colour the door's lights draw with (a, r, g, b)
    virtual void run_task();
    virtual void render();
    static void *create(void *arg0);
    static void free_static_data();
    static void load_shared_resource();
};

typedef char TODoorVoShip_size[sizeof(TODoorVoShip) == 0xEC ? 1 : -1];

#endif
