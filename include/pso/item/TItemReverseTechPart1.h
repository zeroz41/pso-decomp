#ifndef PSO_ITEM_TITEMREVERSETECHPART1_H
#define PSO_ITEM_TITEMREVERSETECHPART1_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TAdRicoRingCtrl;

class TItemReverseTechPart1 : public TObject {
public:
    TItemReverseTechPart1(TObject *parent, void *texture_archive);
    virtual ~TItemReverseTechPart1();
    virtual void run_task();

    s32 state;  // 0 waiting, 1 ring fading in, 2 shown, 3 fading out, 4 done
    s32 timer;
    s32 fade_in_time;
    s32 hold_time;
    s32 fade_out_time;
    TAdRicoRingCtrl *ring;
};
LAYOUT_ASSERT(TItemReverseTechPart1Size, sizeof(TItemReverseTechPart1) == 0x34);

#endif
