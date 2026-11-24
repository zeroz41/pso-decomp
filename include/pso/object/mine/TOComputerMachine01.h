#ifndef PSO_OBJECT_MINE_TOCOMPUTERMACHINE01_H
#define PSO_OBJECT_MINE_TOCOMPUTERMACHINE01_H

#include "types.h"
#include "pso/quest/TOQuestTalkBase.h"
#include "pso/system/BmlResource.h"

// The Mines' research computer: four screens scroll their textures, and it
// stays drawn while the camera is within its radius.
struct GinjaModel;

struct TOComputerMachine01 : public TOQuestTalkBase {
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
    static GinjaModel *screen_meshes[4];

    u8 pad_e4[0x4];
};

LAYOUT_ASSERT(TOComputerMachine01_size, sizeof(TOComputerMachine01) == 0xE8);

#endif
