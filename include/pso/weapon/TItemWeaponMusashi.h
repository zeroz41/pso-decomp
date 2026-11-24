#ifndef PSO_WEAPON_TITEMWEAPONMUSASHI_H
#define PSO_WEAPON_TITEMWEAPONMUSASHI_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Weapon group 0x89: Musashi, Yamato, Asuka and Sange & Yasha; the second model goes in the other hand.
class TItemWeaponMusashi : public TItemWeapon {
public:
    TItemWeaponMusashi(TObject *parent, u8 *item);
    static TItem *create(u8 *item); // weapon_factory_table entry
    virtual ~TItemWeaponMusashi();
    virtual void reserved_53();
};

#endif
