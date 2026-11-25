#ifndef PSO_ITEM_TITEMTIMEREVENTTPREGEN_H
#define PSO_ITEM_TITEMTIMEREVENTTPREGEN_H
#include "types.h"
#include "pso/item/TItemTimerEvent.h"

class TItemTimerEventTpRegen : public TItemTimerEvent {
public:
    TItemTimerEventTpRegen(TItemHeapObject *parent, u16 client, s32 period);
    virtual void vfunc_6();
    virtual ~TItemTimerEventTpRegen();
};
LAYOUT_ASSERT(TItemTimerEventTpRegen_size, sizeof(TItemTimerEventTpRegen) == 0x2C);

#endif
