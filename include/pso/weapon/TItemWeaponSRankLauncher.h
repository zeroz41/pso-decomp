#ifndef PSO_WEAPON_TITEMWEAPONSRANKLAUNCHER_H
#define PSO_WEAPON_TITEMWEAPONSRANKLAUNCHER_H
#include "types.h"
#include "pso/weapon/TUnk_804A4948.h"

class TItemWeaponSRankLauncher : public TUnk_804A4948 {
public:
    TItemWeaponSRankLauncher(TObject *parent, u8 *item);
    static TItem *create(u8 *item); // weapon_factory_table entry
    virtual ~TItemWeaponSRankLauncher();
    virtual void update_idle();
    virtual void update_attack();
    virtual void emit_marker_effects();
    virtual void init_weapon_effect_descriptor(WeaponEffectDescriptor *desc);
    virtual void transform_model_node();
    f32 muzzle_offset;
};

#endif
