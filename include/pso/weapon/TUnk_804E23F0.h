#ifndef PSO_WEAPON_TUNK_804E23F0_H
#define PSO_WEAPON_TUNK_804E23F0_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The base of the weapons in this group (all in
// TObjPlayer_802D5174.cpp): two callbacks it hands to the effect descriptor.
class TUnk_804E23F0 : public TItemWeapon {
public:
    TUnk_804E23F0(TObject *parent, u8 *item);
    virtual ~TUnk_804E23F0();
    virtual void emit_marker_effects();
    virtual void reserved_53();
    virtual void update_weapon();
    virtual void init_weapon_effect_descriptor(Desc_8011E5C4 *desc);
    virtual void vfunc_60();
    // New in this class (slot 62): emit_marker_effects calls it with the gun
    // point after its shots (inferred: the weapon's attack effect).
    virtual void vfunc_62(Vec *pos);
    u32 pad_1f8;    // bit 0 while the attack stage is 2; the draw then adds two rotated copies
    s32 effect_id;  // create_item_eff_cane's effect: 445, 341 or 447
    f32 pad_200;    // the descriptor's pad_4c
    void *pad_204;  // the descriptor's pad_70
    void *pad_208;  // the descriptor's pad_74
};

#endif
