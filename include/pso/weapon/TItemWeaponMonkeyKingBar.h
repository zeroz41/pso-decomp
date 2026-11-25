#ifndef PSO_WEAPON_TITEMWEAPONMONKEYKINGBAR_H
#define PSO_WEAPON_TITEMWEAPONMONKEYKINGBAR_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include <dolphin/mtx/GeoTypes.h>

class TItemWeaponMonkeyKingBar : public TItemWeapon {
public:
    TItemWeaponMonkeyKingBar(TObject *parent, u8 *item);
    virtual ~TItemWeaponMonkeyKingBar();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_attack();
    Vec scale; // scale_current_matrix of model 0; update_idle/update_attack ease z
};

#endif
