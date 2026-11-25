#ifndef PSO_ITEM_TITEMTIMEREVENTTPDRAIN_H
#define PSO_ITEM_TITEMTIMEREVENTTPDRAIN_H
#include "types.h"
#include "pso/item/TItemTimerEvent.h"

class TItemTimerEventTpDrain : public TItemTimerEvent {
public:
    TItemTimerEventTpDrain(TItemHeapObject *parent, u16 client, s32 period);
    virtual void vfunc_6();
    virtual ~TItemTimerEventTpDrain();
    virtual void vfunc_7();
};
LAYOUT_ASSERT(TItemTimerEventTpDrain_size, sizeof(TItemTimerEventTpDrain) == 0x2C);

#endif
