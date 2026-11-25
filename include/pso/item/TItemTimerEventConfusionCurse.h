#ifndef PSO_ITEM_TITEMTIMEREVENTCONFUSIONCURSE_H
#define PSO_ITEM_TITEMTIMEREVENTCONFUSIONCURSE_H
#include "types.h"
#include "pso/item/TItemTimerEvent.h"

// The confusion curse timer (its constructor was confusion_curse_timer_ct): every
// period frames it applies the curse with probability unk_2C.
class TItemTimerEventConfusionCurse : public TItemTimerEvent {
public:
    TItemTimerEventConfusionCurse(TItemHeapObject *parent, u16 client, s32 period, f32 rate);
    virtual void vfunc_6();
    virtual ~TItemTimerEventConfusionCurse();
    f32 unk_2C;
};
LAYOUT_ASSERT(TItemTimerEventConfusionCurse_size, sizeof(TItemTimerEventConfusionCurse) == 0x30);

#endif
