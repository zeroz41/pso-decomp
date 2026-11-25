#ifndef PSO_WEAPON_TITEMWEAPONSOULEATER_H
#define PSO_WEAPON_TITEMWEAPONSOULEATER_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The Soul Eater weapon class (old names
// construct_soul_eater_weapon, TObjPlayer::trigger_megid_special):
// update_attack swings rotation_z over the attack's frames, the model hook (slot 60) turns
// model node 0 by it, emit_marker_effects casts Megid from joint 2 and
// drains 7% of the owner's HP. Made by create_soul_eater_weapon.
class TItemWeaponSoulEater : public TItemWeapon {
public:
    virtual void update_idle();
    virtual void transform_model_node();
    virtual void update_attack();
    virtual void on_equipped();
    virtual void emit_marker_effects();
    TItemWeaponSoulEater(TObject *parent, u8 *item);
    virtual ~TItemWeaponSoulEater();
    s32 rotation_z;  // rotate_matrix_z angle of the model hook
};

TItem *create_soul_eater_weapon(u8 *item);

#endif
