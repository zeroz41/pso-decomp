#ifndef PSO_WEAPON_TITEMWEAPONDARKFLOW_H
#define PSO_WEAPON_TITEMWEAPONDARKFLOW_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponDarkFlow : public TItemWeapon {
public:
    TItemWeaponDarkFlow(TObject *parent, u8 *item);
    virtual ~TItemWeaponDarkFlow();
    virtual void emit_marker_effects();
    virtual void update_weapon();
    virtual void init_weapon_effect_descriptor(WeaponEffectDescriptor *desc);
};

TItem *create_dark_flow(u8 *item);

#endif
