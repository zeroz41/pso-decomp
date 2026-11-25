#ifndef PSO_WEAPON_TITEMWEAPONMETEORCUDGEL_H
#define PSO_WEAPON_TITEMWEAPONMETEORCUDGEL_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include <dolphin/mtx/GeoTypes.h>

// Weapon class (old ctor name TObjPlayer::init_state()), made by
// TItemWeaponMeteorCudgel::create.
class TItemWeaponMeteorCudgel : public TItemWeapon {
public:
    virtual ~TItemWeaponMeteorCudgel();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_attack();
    TItemWeaponMeteorCudgel(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    Vec scale;  // scale_current_matrix of model 0; update_idle/update_attack ease z
};

#endif
