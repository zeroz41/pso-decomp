#ifndef PSO_WEAPON_TUNK_804A5C18_H
#define PSO_WEAPON_TUNK_804A5C18_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// A five-muzzle gun weapon class (vtable 0x804A5C18; old names
// TObjPlayer::apply_frame_camera_shake, TObjPlayer::update_approach_value,
// construct_shot_weapon): emit_marker_effects fires a shot from each muzzle
// joint; update_idle/update_attack open and close barrel_angle and
// slide_offset, which the model hook (slot 60) applies to the barrel and
// slide nodes. The joint and node numbers depend on item code byte 2 (5, 6,
// 7, other). Made by create_shot_weapon.
class TUnk_804A5C18 : public TItemWeapon {
public:
    virtual void vfunc_60();
    virtual void emit_marker_effects();
    virtual void update_idle();
    virtual void update_attack();
    TUnk_804A5C18(TObject *parent, u8 *item);
    virtual ~TUnk_804A5C18();
    s32 muzzle_joints[5];  // 0x1F8: get_joint_position joints of the shots (inferred name)
    s32 barrel_nodes[4];   // 0x20C: rotated by +/-barrel_angle in vfunc_60 (inferred name)
    s32 slide_node;        // 0x21C: translated by slide_offset in vfunc_60 (inferred name)
    s32 barrel_angle;      // 0x220 (inferred name)
    f32 slide_offset;      // 0x224 (inferred name)
    u8 pad_228[4];
};

u8 *create_shot_weapon(u8 *item);

#endif
