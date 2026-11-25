#ifndef PSO_WEAPON_TITEMWEAPONTWINBLAZE_H
#define PSO_WEAPON_TITEMWEAPONTWINBLAZE_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponTwinBlaze : public TItemWeapon {
public:
    TItemWeaponTwinBlaze(TObject *parent, u8 *item);
    virtual ~TItemWeaponTwinBlaze();
    virtual void on_equipped();
    virtual void on_unequipped();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    s32 floor_area; // floor area update_weapon last spawned its follow effects in
};

#endif
