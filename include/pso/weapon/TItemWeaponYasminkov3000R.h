#ifndef PSO_WEAPON_TITEMWEAPONYASMINKOV3000R_H
#define PSO_WEAPON_TITEMWEAPONYASMINKOV3000R_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The Yasminkov 3000R weapon class (old names
// yasminkov_3000r_*): emit_marker_effects ejects a casing and starts the
// slide, update_weapon moves slide.z back and forth, the model hook (slot 60) translates
// model node 1 by slide. Made by TItemWeaponYasminkov3000R::create.
class TItemWeaponYasminkov3000R : public TItemWeapon {
public:
    virtual void transform_model_node();
    virtual void emit_marker_effects();
    virtual void update_weapon();
    virtual ~TItemWeaponYasminkov3000R();
    TItemWeaponYasminkov3000R(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    WeaponVector slide;
    s32 slide_state;  // 2 opening, 3 open, 1 closing, 0 closed
};

#endif
