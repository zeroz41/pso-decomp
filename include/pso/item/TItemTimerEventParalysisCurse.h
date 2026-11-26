#ifndef PSO_ITEM_TITEMTIMEREVENTPARALYSISCURSE_H
#define PSO_ITEM_TITEMTIMEREVENTPARALYSISCURSE_H
#include "types.h"
#include "pso/item/TItemTimerEvent.h"

// The paralysis curse timer (its constructor was paralysis_curse_timer_ct): every
// period frames it applies the curse with probability chance.
class TItemTimerEventParalysisCurse : public TItemTimerEvent {
public:
    TItemTimerEventParalysisCurse(TItemHeapObject *parent, u16 client, s32 period, f32 rate);
    virtual void apply_effect();
    virtual ~TItemTimerEventParalysisCurse();
    f32 chance;
};
LAYOUT_ASSERT(TItemTimerEventParalysisCurse_size, sizeof(TItemTimerEventParalysisCurse) == 0x30);

#endif
