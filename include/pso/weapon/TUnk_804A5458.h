#ifndef PSO_WEAPON_TUNK_804A5458_H
#define PSO_WEAPON_TUNK_804A5458_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Made by create_rod_weapon (weapon_factory_table+0x2C).
class TUnk_804A5458 : public TItemWeapon {
public:
    virtual ~TUnk_804A5458();
    TUnk_804A5458(TObject *parent, u8 *item);
};

u8 *create_rod_weapon(u8 *item);

#endif
