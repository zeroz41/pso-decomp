#ifndef PSO_WEAPON_TUNK_804A2868_H
#define PSO_WEAPON_TUNK_804A2868_H

#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The weapon class whose effect descriptor carries spawn_flame_effect (vtable 0x804A2868).
// Made by TObjPlayer__sub_80126054 (weapon_factory_table+0x54).
class TUnk_804A2868 : public TItemWeapon {
public:
    TUnk_804A2868(TObject *parent, u8 *item);
    virtual ~TUnk_804A2868();
    virtual void init_weapon_effect_descriptor(Desc_8011E5C4 *desc);

    s32 unk_1f8; // 10 for item index 1, else 1; copied to the descriptor's +0x10
};

extern "C" u8 *TObjPlayer__sub_80126054(u8 *item);

#endif
