#ifndef PSO_WEAPON_TITEMWEAPONMARINASBAG_H
#define PSO_WEAPON_TITEMWEAPONMARINASBAG_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponMarinasBag : public TItemWeapon {
public:
    virtual ~TItemWeaponMarinasBag();
    virtual void emit_marker_effects();
    virtual void on_equipped();
    TItemWeaponMarinasBag(TObject *parent, u8 *item);
};

#endif
