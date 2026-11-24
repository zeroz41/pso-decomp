#ifndef PSO_WEAPON_TUNK_804E24F0_H
#define PSO_WEAPON_TUNK_804E24F0_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Same shape as TUnk_804F28E0 (vtable 0x804E24F0); made by its weapon_factory_table entry.
class TUnk_804E24F0 : public TItemWeapon {
public:
    TUnk_804E24F0(TObject *parent, u8 *item);
    static TItem *create(u8 *item); // weapon_factory_table entry
    virtual ~TUnk_804E24F0();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void emit_marker_effects();
    virtual void init_weapon_effect_descriptor(WeaponEffectDescriptor *desc);
    virtual void update_attack();
    f32 muzzle_offset;
};

#endif
