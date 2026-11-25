#ifndef PSO_WEAPON_TITEMWEAPONMAGICALPIECE_H
#define PSO_WEAPON_TITEMWEAPONMAGICALPIECE_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Weapon class (old ctor name init_variant_34), made by
// TItemWeaponMagicalPiece::create.
class TItemWeaponMagicalPiece : public TItemWeapon {
public:
    virtual ~TItemWeaponMagicalPiece();
    virtual void emit_marker_effects();
    TItemWeaponMagicalPiece(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
};


#endif
