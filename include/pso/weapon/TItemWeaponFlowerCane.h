#ifndef PSO_WEAPON_TITEMWEAPONFLOWERCANE_H
#define PSO_WEAPON_TITEMWEAPONFLOWERCANE_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Cane weapon class (old ctor name TObjPlayer__sub_80125F24), made by
// TItemWeaponFlowerCane::create.
class TItemWeaponFlowerCane : public TItemWeapon {
public:
    virtual ~TItemWeaponFlowerCane();
    virtual void emit_marker_effects();
    TItemWeaponFlowerCane(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
};

#endif
