#ifndef PSO_WEAPON_TUNK_804A62F8_H
#define PSO_WEAPON_TUNK_804A62F8_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Weapon class with vtable 0x804A62F8, made by create_sword_weapon (old ctor name
// TObjPlayer::init_from_item).
class TUnk_804A62F8 : public TItemWeapon {
public:
    virtual ~TUnk_804A62F8();
    virtual void vfunc_60();
    virtual void update_weapon();
    TUnk_804A62F8(TObject *parent, u8 *item);
    s32 glows;  // item[2] == 5 or item[1] == 0x8F: projection-tex model pass, weapon flag 0x800 (name inferred)
};

u8 *create_sword_weapon(u8 *item);

#endif
