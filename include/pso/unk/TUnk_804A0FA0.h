#ifndef PSO_UNK_TUNK_804A0FA0_H
#define PSO_UNK_TUNK_804A0FA0_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A0FA0 : public TItemWeapon {
public:
    virtual ~TUnk_804A0FA0();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    TUnk_804A0FA0(TObject *parent, u8 *item);
    f32 blade_scale;  // item index 5: eased to 1.0 on attack, 0.0 at idle (vfunc_60 scale)
};

// Factory
u8 *create_dagger_weapon(u8 *arg0);

#endif
