#ifndef PSO_WEAPON_TITEMWEAPONFROZENSHOOTER_H
#define PSO_WEAPON_TITEMWEAPONFROZENSHOOTER_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The frozen shooter weapon class, made by TItemWeaponFrozenShooter::create.
class TItemWeaponFrozenShooter : public TItemWeapon {
public:
    TItemWeaponFrozenShooter(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponFrozenShooter();
    virtual void emit_marker_effects();
    virtual void on_equipped();
    virtual void init_weapon_effect_descriptor(WeaponEffectDescriptor *desc);

    s32 unk_1f8;     // 10 for item index 1, else 1; the descriptor's +0x10
    s32 skip_freeze; // set by the item index 1 shot: the descriptor gets no frozen_shooter_freeze_hit
    s32 unk_200;     // 0x1F5 for item index 1, else 0x95; the descriptor's +0x78
};

#endif
