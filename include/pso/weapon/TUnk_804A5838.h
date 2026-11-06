#ifndef PSO_WEAPON_TUNK_804A5838_H
#define PSO_WEAPON_TUNK_804A5838_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The Soul Eater weapon class (vtable 0x804A5838; old names
// construct_soul_eater_weapon, TObjPlayer::trigger_megid_special):
// update_attack swings rotation_z over the attack's frames, the model hook (slot 60) turns
// model node 0 by it, emit_marker_effects casts Megid from joint 2 and
// drains 7% of the owner's HP. Made by create_soul_eater_weapon.
class TUnk_804A5838 : public TItemWeapon {
public:
    virtual void update_idle();
    virtual void vfunc_60();
    virtual void update_attack();
    virtual void vfunc_57();
    virtual void emit_marker_effects();
    TUnk_804A5838(TObject *parent, u8 *item);
    virtual ~TUnk_804A5838();
    s32 rotation_z;  // rotate_matrix_z angle of the model hook
};

u8 *create_soul_eater_weapon(u8 *item);

#endif
