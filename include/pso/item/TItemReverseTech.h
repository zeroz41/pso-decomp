#ifndef PSO_ITEM_TITEMREVERSETECH_H
#define PSO_ITEM_TITEMREVERSETECH_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <stddef.h>

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
};

LAYOUT_ASSERT(ReverseTechPartOneOffset, offsetof(TItemReverseTech, part_one) == 0x20);
LAYOUT_ASSERT(ReverseTechPartTwoOffset, offsetof(TItemReverseTech, part_two) == 0x24);

#endif
