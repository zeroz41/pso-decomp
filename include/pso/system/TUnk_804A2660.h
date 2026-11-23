#ifndef PSO_SYSTEM_TUNK_804A2660_H
#define PSO_SYSTEM_TUNK_804A2660_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TItemWeapon;
class TParticleCtrl;

// Keeps a particle emitter on a weapon joint while the weapon is out.
class TUnk_804A2660 : public TObject {
public:
    TUnk_804A2660(TObject *parent, TItemWeapon *weapon, s32 joint, s32 effect_id);
    virtual ~TUnk_804A2660();
    virtual void run_task();

    s32 item_id;
    s32 joint;
    TParticleCtrl *particle;
    u32 item_generation;  // get_item_system_generation() when built; a change ends it
};
LAYOUT_ASSERT(TUnk_804A2660_size, sizeof(TUnk_804A2660) == 0x2C);

#endif
