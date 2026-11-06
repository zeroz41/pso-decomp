#ifndef PSO_WEAPON_TUNK_804A4F60_H
#define PSO_WEAPON_TUNK_804A4F60_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TargetCursorList.h"
#include <dolphin/mtx/GeoTypes.h>

// The Psycho Wand weapon class (vtable 0x804A4F60; old names psycho_wand_ct,
// psycho_wand_equip/unequip, psycho_wand_node_callback): refunds spent TP
// out of the owner's HP, and its extra technique roll casts Zonde, Foie or
// Barta from joint 4 at the owner's first locked target. Made by
// create_psycho_wand.
class TUnk_804A4F60 : public TItemWeapon {
public:
    TUnk_804A4F60(TObject *parent, u8 *item);
    virtual ~TUnk_804A4F60();
    virtual void activate_effect(s32);
    virtual void update_idle();
    virtual void update_attack();
    virtual void emit_marker_effects();
    virtual void update_weapon();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_60();
    void psycho_wand_roll_extra();

    s16 last_tp;              // 0x1F8: owner TP seen last frame, -1 after (un)equip (inferred name)
    Vec cast_point;           // 0x1FC: joint 4, where the techniques start (inferred name)
    TargetCursorList targets; // 0x208: Zonde's target
    s32 cast_rotation_y;      // 0x264: owner rotation_y for Foie and Barta (inferred name)
    Vec cast_position;        // 0x268: owner position for Barta (inferred name)
    f32 extension;            // 0x274: model node 1 offset (inferred name)
    s32 rotation_z;           // 0x278: rotate_matrix_z angle of the model hook
};

u8 *create_psycho_wand(u8 *item);

#endif
