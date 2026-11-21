#ifndef PSO_ITEM_TUNK_8049F148_H
#define PSO_ITEM_TUNK_8049F148_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TParticleCtrl;

class TUnk_8049F148 : public TObject {
public:
    TUnk_8049F148(TObject *, s16);
    virtual ~TUnk_8049F148();
    virtual void run_task();
    // create_particle_emitter(hand position, 0x101) while the player is on
    // its floor (name inferred).
    TParticleCtrl *particle;
    s32 m_20;
    u16 client_id;  // the player it follows (get_player_by_client_id)
    u8 pad_26[0x2];
    u32 m_28;
};
LAYOUT_ASSERT(TUnk_8049F148_size, sizeof(TUnk_8049F148) == 0x2C);

#endif
