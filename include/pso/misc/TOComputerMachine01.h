#ifndef PSO_MISC_TOCOMPUTERMACHINE01_H
#define PSO_MISC_TOCOMPUTERMACHINE01_H

#include "types.h"
#include "pso/misc/TUnk_804B27D8.h"
#include "pso/system/BmlResource.h"

// The Mines' research computer: four screens scroll their textures, and it
// stays drawn while the camera is within its radius.
struct TOComputerMachine01 : public TUnk_804B27D8 {
    TOComputerMachine01(void *set_data);
    virtual ~TOComputerMachine01();
    virtual s32 update_object_view_visibility(f32 range, f32 radius);
    virtual void render();

    static void *create(void *set_data);
    static void unload_resources();
    static void load_resources();

    static const char *class_name;
    static BmlResource *model_resource;
    // The frame the screens last scrolled on: once a frame for every
    // computer on the floor.
    static s32 last_scroll_frame;
    // The screen meshes: the model's first child and its siblings, last
    // first.
    static void *screen_meshes[4];

    u8 pad_e4[0x4];
};

typedef char TOComputerMachine01_size[sizeof(TOComputerMachine01) == 0xE8 ? 1 : -1];

#endif
