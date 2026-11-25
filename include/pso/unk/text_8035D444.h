#ifndef PSO_UNK_TEXT_8035D444_H
#define PSO_UNK_TEXT_8035D444_H

#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The Ruby Bullet weapon, made by weapon factory table entry 0xA3.
class TItemWeaponRubyBullet : public TItemWeapon {
public:
    TItemWeaponRubyBullet(TObject *parent, u8 *item);
    virtual ~TItemWeaponRubyBullet();
    static TItem *create(u8 *item);
    virtual void init_weapon_effect_descriptor(WeaponEffectDescriptor *desc);
};


#endif
