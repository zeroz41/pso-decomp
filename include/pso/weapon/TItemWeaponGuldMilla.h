#ifndef PSO_WEAPON_TITEMWEAPONGULDMILLA_H
#define PSO_WEAPON_TITEMWEAPONGULDMILLA_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponGuldMilla : public TItemWeapon {
public:
    virtual ~TItemWeaponGuldMilla();
    virtual void draw_held_model();
    virtual void emit_marker_effects();
    TItemWeaponGuldMilla(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    Vec gun_point;         // get_gun_point with item_model
    Vec second_gun_point;  // get_gun_point with second_model
};

#endif
