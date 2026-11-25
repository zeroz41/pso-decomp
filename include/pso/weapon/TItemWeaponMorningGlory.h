#ifndef PSO_WEAPON_TITEMWEAPONMORNINGGLORY_H
#define PSO_WEAPON_TITEMWEAPONMORNINGGLORY_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponMorningGlory : public TItemWeapon {
public:
    // No destructor of its own: the compiler's comes last in the TU.
    TItemWeaponMorningGlory(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual void draw_held_model();
    virtual void update_weapon();
};

#endif
