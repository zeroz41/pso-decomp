#ifndef PSO_ITEM_TITEMREVERSETECH_H
#define PSO_ITEM_TITEMREVERSETECH_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <stddef.h>

class TItemReverseTech : public TObject {
public:
    virtual ~TItemReverseTech();
    virtual void run_task();
    u32 unknown_1c;
    TObject *part_one;
    TObject *part_two;
public:
    static void create();
    static void load_textures();
    static void run_frame();
    static void run_cleanup_callbacks();
    static void init_scene();
};

typedef char ReverseTechPartOneOffset[offsetof(TItemReverseTech, part_one) == 0x20 ? 1 : -1];
typedef char ReverseTechPartTwoOffset[offsetof(TItemReverseTech, part_two) == 0x24 ? 1 : -1];

extern "C" {
void *TItemReverseTech__ct(void *item_reverse_tech, void *parent);
}

#endif
