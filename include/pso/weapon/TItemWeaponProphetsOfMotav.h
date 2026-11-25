#ifndef PSO_WEAPON_TITEMWEAPONPROPHETSOFMOTAV_H
#define PSO_WEAPON_TITEMWEAPONPROPHETSOFMOTAV_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The weapon class whose emit_marker_effects casts Jellen or, with TP,
// Zalure. Made by TItemWeaponProphetsOfMotav::create.
class TItemWeaponProphetsOfMotav : public TItemWeapon {
public:
    virtual void on_equipped();
    virtual void emit_marker_effects();
    virtual ~TItemWeaponProphetsOfMotav();
    TItemWeaponProphetsOfMotav(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
};

#endif
