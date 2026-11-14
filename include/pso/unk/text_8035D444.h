#ifndef PSO_UNK_TEXT_8035D444_H
#define PSO_UNK_TEXT_8035D444_H

#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The weapon made by alloc_and_init_obj_effect (vtable 0x804F1EC8, labelled
// ruby_bullet_weapon_vtable before; that name is inferred, not from a symbol).
class TUnk_804F1EC8 : public TItemWeapon {
public:
    TUnk_804F1EC8(TObject *parent, u8 *item);
    virtual ~TUnk_804F1EC8();
    virtual void init_weapon_effect_descriptor(Desc_8011E5C4 *desc);
};

u8 *alloc_and_init_obj_effect(u8 *arg0);

#endif
