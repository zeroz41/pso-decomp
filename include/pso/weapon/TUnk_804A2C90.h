#ifndef PSO_WEAPON_TUNK_804A2C90_H
#define PSO_WEAPON_TUNK_804A2C90_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Made by create_handgun_weapon.
class TUnk_804A2C90 : public TItemWeapon {
public:
    virtual ~TUnk_804A2C90();
    virtual void update_weapon();
    TUnk_804A2C90(TObject *parent, u8 *item);
};

// Made by create_suppressed_gun_weapon. No destructor of its own: the
// compiler's comes last in the TU.
class TUnk_804A2D88 : public TItemWeapon {
public:
    TUnk_804A2D88(TObject *parent, u8 *item);
};

u8 *create_suppressed_gun_weapon(u8 *item);
u8 *create_handgun_weapon(u8 *item);

#endif
