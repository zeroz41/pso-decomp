#ifndef PSO_WEAPON_TITEMWEAPONYASMINKOV2000H_H
#define PSO_WEAPON_TITEMWEAPONYASMINKOV2000H_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The Yasminkov 2000H weapon class (old names
// yasminkov_2000h_node_callback, yasminkov_2000h_ct): update_attack and
// update_idle show or shrink model node 2 (scale), emit_marker_effects
// starts the slide and update_weapon moves slide.y and ejects a casing; the
// model hook (slot 60) translates node 1 by slide. Made by
// TItemWeaponYasminkov2000H::create.
class TItemWeaponYasminkov2000H : public TItemWeapon {
public:
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_attack();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    virtual ~TItemWeaponYasminkov2000H();
    TItemWeaponYasminkov2000H(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    s32 shown;           // 0x1F8: 1 while scale is full size (inferred name)
    WeaponVector scale;  // scale_current_matrix in transform_model_node
    s32 slide_state;     // 2 opening, 3 open, 1 closing, 0 closed
    WeaponVector slide;  // post_translate_matrix in transform_model_node
};

#endif
