#ifndef PSO_TITEMEFFARMORPARTICLE_H
#define PSO_TITEMEFFARMORPARTICLE_H

#include "pso/TObject.h"
#include "types.h"

class TParticleCtrl;

// The particle a TItemProArmorParticle plays on its owner: it follows the
// client's player while the item stays equipped in this item system
// generation, and is hidden while the item or the player is.
class TItemEffArmorParticle : public TObject {
public:
    TItemEffArmorParticle(TObject *parent, s32 item_id, u16 client, s32 particle);
    virtual ~TItemEffArmorParticle();
    virtual void run_task();

    s32 item_id;
    TParticleCtrl *particle;
    u16 client;
    u8 pad_26[2];
    u32 item_generation;  // get_item_system_generation when it was made
};

typedef char TItemEffArmorParticle_size[(sizeof(TItemEffArmorParticle) == 0x2C) ? 1 : -1];

#endif
