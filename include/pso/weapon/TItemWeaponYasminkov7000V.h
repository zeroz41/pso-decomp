#ifndef PSO_WEAPON_TITEMWEAPONYASMINKOV7000V_H
#define PSO_WEAPON_TITEMWEAPONYASMINKOV7000V_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include <dolphin/mtx/GeoTypes.h>

class TItemWeaponYasminkov7000V : public TItemWeapon {
public:
    TItemWeaponYasminkov7000V(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponYasminkov7000V();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    virtual void transform_model_node();
    s32 state;
    Vec model_offset;  // transform_model_node's translation; y slides 0..2.7 with the shot

};

#endif
