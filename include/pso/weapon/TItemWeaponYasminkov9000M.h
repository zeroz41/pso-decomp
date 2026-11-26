#ifndef PSO_WEAPON_TITEMWEAPONYASMINKOV9000M_H
#define PSO_WEAPON_TITEMWEAPONYASMINKOV9000M_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The Yasminkov 9000M weapon class (old names
// yasminkov_9000m_*): two guns, the second drawn at joint 35 by draw_held_model.
// emit_marker_effects fires a shot from each muzzle and starts the slide,
// update_weapon moves slide.y and ejects a casing per gun; the model hook (slot 60)
// translates model node 2 by slide. Made by TItemWeaponYasminkov9000M::create.
class TItemWeaponYasminkov9000M : public TItemWeapon {
public:
    virtual void draw_held_model();
    virtual void transform_model_node();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    void yasminkov_9000m_eject_casing(Vec *pos, s32 angle_offset);
    virtual ~TItemWeaponYasminkov9000M();
    TItemWeaponYasminkov9000M(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    s32 slide_state;  // 2 opening, 3 open, 1 closing, 0 closed
    Vec slide;
    Vec muzzles[2];   // joint 3 of each gun
    Vec ejectors[2];  // joint 1 of each gun
};

#endif
