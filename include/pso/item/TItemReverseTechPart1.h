#ifndef PSO_ITEM_TITEMREVERSETECHPART1_H
#define PSO_ITEM_TITEMREVERSETECHPART1_H

#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"

class TAdRicoRingCtrl;

class TItemReverseTechPart1 : public TObject {
public:
    TItemReverseTechPart1(TObject *parent, NJS_TEXLIST *texlist);
    virtual ~TItemReverseTechPart1();
    virtual void run_task();

    s32 state;  // 0 waiting, 1 ring fading in, 2 shown, 3 fading out, 4 done
    s32 timer;
    s32 fade_in_time;
    s32 hold_time;
    s32 fade_out_time;
    TAdRicoRingCtrl *ring;

    static TItemReverseTechPart1 *instance;  // set by the constructor; TItemReverseTechPart2::destroy_and_flag starts it
};
LAYOUT_ASSERT(TItemReverseTechPart1Size, sizeof(TItemReverseTechPart1) == 0x34);

#endif
