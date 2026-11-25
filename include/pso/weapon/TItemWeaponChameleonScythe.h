#ifndef PSO_WEAPON_TITEMWEAPONCHAMELEONSCYTHE_H
#define PSO_WEAPON_TITEMWEAPONCHAMELEONSCYTHE_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include <dolphin/mtx/GeoTypes.h>

// Weapon class (old ctor name setup_effect), made by
// TItemWeaponChameleonScythe::create.
class TItemWeaponChameleonScythe : public TItemWeapon {
public:
    virtual ~TItemWeaponChameleonScythe();
    virtual void on_equipped();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_attack();
    TItemWeaponChameleonScythe(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    Vec scale;  // scale_current_matrix of model 2; z eases to 4 attacking, 1 idle
};

#endif
