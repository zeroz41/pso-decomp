#ifndef PSO_ITEM_TITEMREVERSETECHPART2_H
#define PSO_ITEM_TITEMREVERSETECHPART2_H

#include "pso/TObject.h"
#include "types.h"

class TItemReverseTechPart2 : public TObject {
public:
    virtual ~TItemReverseTechPart2();
    virtual void run_task();
    virtual void render();
public:
    void destroy_and_flag();
    static void render();
};

extern "C" {
u8 *__ct__21TItemReverseTechPart2Fv(u8 *arg0, s32 arg1, s32 arg2);
}

// --- C functions defined in TItemReverseTechPart2.cpp ---
extern "C" {
u8 *__ct__21TItemReverseTechPart2Fv(u8 *object, s32 arg1, s32 arg2);
}
// --- end of C functions

#endif
