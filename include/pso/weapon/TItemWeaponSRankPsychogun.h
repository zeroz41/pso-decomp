#ifndef PSO_WEAPON_TITEMWEAPONSRANKPSYCHOGUN_H
#define PSO_WEAPON_TITEMWEAPONSRANKPSYCHOGUN_H
#include "types.h"
#include "pso/weapon/TUnk_804A4948.h"

class TItemWeaponSRankPsychogun : public TUnk_804A4948 {
public:
    TItemWeaponSRankPsychogun(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponSRankPsychogun();
    virtual void draw_held_model();
    virtual void emit_marker_effects();
    // The two points emit_marker_effects shoots from (launch_shot origins);
    // draw_held_model fills them (draw_status_icons).
    Vec shot_origins[2];
};

#endif
