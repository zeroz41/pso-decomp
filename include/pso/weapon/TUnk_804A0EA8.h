#ifndef PSO_WEAPON_TUNK_804A0EA8_H
#define PSO_WEAPON_TUNK_804A0EA8_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A0EA8 : public TItemWeapon {
public:
    virtual ~TUnk_804A0EA8();
    virtual void reserved_53();
    virtual void emit_marker_effects();
    TUnk_804A0EA8(TObject *parent, u8 *item);
    WeaponVector gun_point;         // get_gun_point with item_model
    WeaponVector second_gun_point;  // get_gun_point with second_model
};

// Factory
u8 *create_guld_milla(s32 arg0);

#endif
