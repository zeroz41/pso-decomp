#ifndef PSO_ITEM_TUNK_804A05A8_H
#define PSO_ITEM_TUNK_804A05A8_H
#include "types.h"
#include "pso/item/TItemTimerEvent.h"

// The slow curse timer (its constructor was slow_curse_timer_ct): every
// period frames it applies the curse with probability unk_2C.
class TUnk_804A05A8 : public TItemTimerEvent {
public:
    TUnk_804A05A8(TItemHeapObject *parent, u16 client, s32 period, f32 rate);
    virtual void vfunc_6();
    virtual ~TUnk_804A05A8();
    f32 unk_2C;
};
LAYOUT_ASSERT(TUnk_804A05A8_size, sizeof(TUnk_804A05A8) == 0x30);

#endif
