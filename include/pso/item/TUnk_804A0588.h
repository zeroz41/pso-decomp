#ifndef PSO_ITEM_TUNK_804A0588_H
#define PSO_ITEM_TUNK_804A0588_H
#include "types.h"
#include "pso/item/TItemTimerEvent.h"

// The confusion curse timer (its constructor was confusion_curse_timer_ct): every
// period frames it applies the curse with probability unk_2C.
class TUnk_804A0588 : public TItemTimerEvent {
public:
    TUnk_804A0588(TItemHeapObject *parent, u16 client, s32 period, f32 rate);
    virtual void vfunc_6();
    virtual ~TUnk_804A0588();
    f32 unk_2C;
};
LAYOUT_ASSERT(TUnk_804A0588_size, sizeof(TUnk_804A0588) == 0x30);

#endif
