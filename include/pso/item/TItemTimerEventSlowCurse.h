#ifndef PSO_ITEM_TITEMTIMEREVENTSLOWCURSE_H
#define PSO_ITEM_TITEMTIMEREVENTSLOWCURSE_H
#include "types.h"
#include "pso/item/TItemTimerEvent.h"

// The slow curse timer (its constructor was slow_curse_timer_ct): every
// period frames it applies the curse with probability chance.
class TItemTimerEventSlowCurse : public TItemTimerEvent {
public:
    TItemTimerEventSlowCurse(TItemHeapObject *parent, u16 client, s32 period, f32 rate);
    virtual void apply_effect();
    virtual ~TItemTimerEventSlowCurse();
    f32 chance;
};
LAYOUT_ASSERT(TItemTimerEventSlowCurse_size, sizeof(TItemTimerEventSlowCurse) == 0x30);

#endif
