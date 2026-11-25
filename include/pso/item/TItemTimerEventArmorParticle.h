#ifndef PSO_ITEM_TITEMTIMEREVENTARMORPARTICLE_H
#define PSO_ITEM_TITEMTIMEREVENTARMORPARTICLE_H
#include "types.h"
#include "pso/item/TItemTimerEvent.h"

class TItemTimerEventArmorParticle : public TItemTimerEvent {
public:
    // The armor particle timer (TItemProArmorParticle::on_equip): plays
    // particle on the client's player every duration frames.
    TItemTimerEventArmorParticle(TItemHeapObject *parent, u16 client, s32 duration, s32 particle);
    virtual void vfunc_6();
    virtual ~TItemTimerEventArmorParticle();
    s32 unk_2C;
};
LAYOUT_ASSERT(TItemTimerEventArmorParticle_size, sizeof(TItemTimerEventArmorParticle) == 0x30);

#endif
