#ifndef PSO_ITEM_TUNK_804A05C8_H
#define PSO_ITEM_TUNK_804A05C8_H
#include "types.h"
#include "pso/item/TItemTimerEvent.h"

class TUnk_804A05C8 : public TItemTimerEvent {
public:
    // The armor particle timer (TItemProArmorParticle::on_equip): plays
    // particle on the client's player every duration frames.
    TUnk_804A05C8(TItemHeapObject *parent, u16 client, s32 duration, s32 particle);
    virtual void vfunc_6();
    virtual ~TUnk_804A05C8();
    s32 unk_2C;
};
LAYOUT_ASSERT(TUnk_804A05C8_size, sizeof(TUnk_804A05C8) == 0x30);

#endif
