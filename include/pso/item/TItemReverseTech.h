#ifndef PSO_ITEM_TITEMREVERSETECH_H
#define PSO_ITEM_TITEMREVERSETECH_H

#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include <stddef.h>

// One load/release pair of the reverse tech scene: init_scene calls each load,
// run_cleanup_callbacks each release, last pair first.
struct TItemReverseTechSceneHook {
    void (*load)(void);
    void (*release)(void);
};

class TItemReverseTech : public TObject {
public:
    TItemReverseTech(TObject *parent);
    virtual ~TItemReverseTech();
    virtual void run_task();
    u32 pad_1C;
    TObject *part_one;
    TObject *part_two;
public:
    static void create();
    static void load_textures();
    static void free();
    static void run_frame();
    static void run_cleanup_callbacks();
    static void init_scene();

    static TItemReverseTechSceneHook cleanup_callback_table[7];
    // The 17 textures of ItemRTT.prs, all named name_buffer, and their list.
    static NJS_TEXLIST *texture_list;
    static NJS_TEXNAME *texnames;
    static char *name_buffer;
};

LAYOUT_ASSERT(ReverseTechPartOneOffset, offsetof(TItemReverseTech, part_one) == 0x20);
LAYOUT_ASSERT(ReverseTechPartTwoOffset, offsetof(TItemReverseTech, part_two) == 0x24);

#endif
