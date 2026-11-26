#ifndef PSO_ITEM_TITEMTIMEREVENTHPREGEN_H
#define PSO_ITEM_TITEMTIMEREVENTHPREGEN_H
#include "types.h"
#include "pso/item/TItemTimerEvent.h"

class TItemTimerEventHpRegen : public TItemTimerEvent {
public:
    TItemTimerEventHpRegen(TItemHeapObject *parent, u16 client, s32 period);
    virtual void apply_effect();
    virtual ~TItemTimerEventHpRegen();
};
LAYOUT_ASSERT(TItemTimerEventHpRegen_size, sizeof(TItemTimerEventHpRegen) == 0x2C);

#endif
