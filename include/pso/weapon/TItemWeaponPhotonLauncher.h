#ifndef PSO_WEAPON_TITEMWEAPONPHOTONLAUNCHER_H
#define PSO_WEAPON_TITEMWEAPONPHOTONLAUNCHER_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Same shape as TItemWeaponSRankLauncher (vtable 0x804E24F0); made by its weapon_factory_table entry.
class TItemWeaponPhotonLauncher : public TItemWeapon {
public:
    TItemWeaponPhotonLauncher(TObject *parent, u8 *item);
    static TItem *create(u8 *item); // weapon_factory_table entry
    virtual ~TItemWeaponPhotonLauncher();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void emit_marker_effects();
    virtual void init_weapon_effect_descriptor(WeaponEffectDescriptor *desc);
    virtual void update_attack();
    f32 muzzle_offset;
};

#endif
