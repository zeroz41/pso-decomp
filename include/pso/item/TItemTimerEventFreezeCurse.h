#ifndef PSO_ITEM_TITEMTIMEREVENTFREEZECURSE_H
#define PSO_ITEM_TITEMTIMEREVENTFREEZECURSE_H
#include "types.h"
#include "pso/item/TItemTimerEvent.h"

// The freeze curse timer (its constructor was freeze_curse_timer_ct): every
// period frames it applies the curse with probability unk_2C.
class TItemTimerEventFreezeCurse : public TItemTimerEvent {
public:
    TItemTimerEventFreezeCurse(TItemHeapObject *parent, u16 client, s32 period, f32 rate);
    virtual void vfunc_6();
    virtual ~TItemTimerEventFreezeCurse();
    f32 unk_2C;
};
LAYOUT_ASSERT(TItemTimerEventFreezeCurse_size, sizeof(TItemTimerEventFreezeCurse) == 0x30);

#endif
