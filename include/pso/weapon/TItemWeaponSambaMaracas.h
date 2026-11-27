#ifndef PSO_WEAPON_TITEMWEAPONSAMBAMARACAS_H
#define PSO_WEAPON_TITEMWEAPONSAMBAMARACAS_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Weapon class made by TItemWeaponSambaMaracas::create.
class TItemWeaponSambaMaracas : public TItemWeapon {
public:
    virtual ~TItemWeaponSambaMaracas();
    virtual void emit_marker_effects();
    TItemWeaponSambaMaracas(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual void draw_held_model();
    // The two points emit_marker_effects shoots from (launch_shot origins);
    // draw_held_model fills them (draw_status_icons).
    Vec shot_origins[2];
};


#endif
