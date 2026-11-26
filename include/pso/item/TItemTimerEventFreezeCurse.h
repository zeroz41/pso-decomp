#ifndef PSO_ITEM_TITEMTIMEREVENTFREEZECURSE_H
#define PSO_ITEM_TITEMTIMEREVENTFREEZECURSE_H
#include "types.h"
#include "pso/item/TItemTimerEvent.h"

// The freeze curse timer (its constructor was freeze_curse_timer_ct): every
// period frames it applies the curse with probability chance.
class TItemTimerEventFreezeCurse : public TItemTimerEvent {
public:
    TItemTimerEventFreezeCurse(TItemHeapObject *parent, u16 client, s32 period, f32 rate);
    virtual void apply_effect();
    virtual ~TItemTimerEventFreezeCurse();
    f32 chance;
};
LAYOUT_ASSERT(TItemTimerEventFreezeCurse_size, sizeof(TItemTimerEventFreezeCurse) == 0x30);

#endif
