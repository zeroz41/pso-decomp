#ifndef PSO_WEAPON_TITEMWEAPONPANTHERSCLAW_H
#define PSO_WEAPON_TITEMWEAPONPANTHERSCLAW_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponPanthersClaw : public TItemWeapon {
public:
    virtual ~TItemWeaponPanthersClaw();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_attack();
    virtual void draw_held_model();
    TItemWeaponPanthersClaw(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    Vec scale;  // model scale (scale_current_matrix); x and y follow z
};

#endif
