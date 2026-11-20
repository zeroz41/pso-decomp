#ifndef PSO_ITEM_TUNK_804A0668_H
#define PSO_ITEM_TUNK_804A0668_H
#include "types.h"
#include "pso/item/TItemTimerEvent.h"

class TUnk_804A0668 : public TItemTimerEvent {
public:
    TUnk_804A0668(TItemHeapObject *parent, u16 client, s32 period);
    virtual void vfunc_6();
    virtual ~TUnk_804A0668();
    virtual void vfunc_7();
};
LAYOUT_ASSERT(TUnk_804A0668_size, sizeof(TUnk_804A0668) == 0x2C);

#endif
