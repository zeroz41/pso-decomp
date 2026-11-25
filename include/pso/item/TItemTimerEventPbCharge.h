#ifndef PSO_ITEM_TITEMTIMEREVENTPBCHARGE_H
#define PSO_ITEM_TITEMTIMEREVENTPBCHARGE_H
#include "types.h"
#include "pso/item/TItemTimerEvent.h"

class TItemTimerEventPbCharge : public TItemTimerEvent {
public:
    TItemTimerEventPbCharge(TItemHeapObject *parent, u16 client, s32 period);
    virtual void vfunc_6();
    virtual ~TItemTimerEventPbCharge();
};
LAYOUT_ASSERT(TItemTimerEventPbCharge_size, sizeof(TItemTimerEventPbCharge) == 0x2C);

#endif
