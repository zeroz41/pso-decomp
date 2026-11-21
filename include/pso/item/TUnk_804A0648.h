#ifndef PSO_ITEM_TUNK_804A0648_H
#define PSO_ITEM_TUNK_804A0648_H
#include "types.h"
#include "pso/item/TItemTimerEvent.h"

class TUnk_804A0648 : public TItemTimerEvent {
public:
    TUnk_804A0648(TItemHeapObject *parent, u16 client, s32 period);
    virtual void vfunc_6();
    virtual ~TUnk_804A0648();
};
LAYOUT_ASSERT(TUnk_804A0648_size, sizeof(TUnk_804A0648) == 0x2C);

#endif
