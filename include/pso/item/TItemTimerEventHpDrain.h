#ifndef PSO_ITEM_TITEMTIMEREVENTHPDRAIN_H
#define PSO_ITEM_TITEMTIMEREVENTHPDRAIN_H
#include "types.h"
#include "pso/item/TItemTimerEvent.h"

class TItemTimerEventHpDrain : public TItemTimerEvent {
public:
    TItemTimerEventHpDrain(TItemHeapObject *parent, u16 client, s32 period);
    virtual void apply_effect();
    virtual ~TItemTimerEventHpDrain();
    virtual void advance_timer();
};
LAYOUT_ASSERT(TItemTimerEventHpDrain_size, sizeof(TItemTimerEventHpDrain) == 0x2C);

#endif
