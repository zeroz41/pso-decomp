#ifndef PSO_WEAPON_TUNK_804A0FA0_H
#define PSO_WEAPON_TUNK_804A0FA0_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A0FA0 : public TItemWeapon {
public:
    virtual ~TUnk_804A0FA0();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_attack();
    TUnk_804A0FA0(TObject *parent, u8 *item);
    f32 blade_scale;  // item index 5: eased to 1.0 on attack, 0.0 at idle (transform_model_node scale)
};

// Factory
TItem *create_dagger_weapon(u8 *item);

#endif
