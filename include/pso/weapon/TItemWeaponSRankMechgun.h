#ifndef PSO_WEAPON_TITEMWEAPONSRANKMECHGUN_H
#define PSO_WEAPON_TITEMWEAPONSRANKMECHGUN_H
#include "types.h"
#include "pso/weapon/TItemWeaponSRank.h"

class TItemWeaponSRankMechgun : public TItemWeaponSRank {
public:
    TItemWeaponSRankMechgun(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponSRankMechgun();
    virtual void draw_held_model();
    virtual void emit_marker_effects();
    // The two points emit_marker_effects shoots from (launch_shot origins);
    // draw_held_model fills them (draw_status_icons).
    Vec shot_origins[2];
};

#endif
