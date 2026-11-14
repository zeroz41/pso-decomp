#ifndef PSO_WEAPON_TUNK_804F14A8_H
#define PSO_WEAPON_TUNK_804F14A8_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The weapon TObjPlayer::create_state_34_alt builds (vtable 0x804F14A8).
class TUnk_804F14A8 : public TItemWeapon {
public:
    TUnk_804F14A8(TObject *parent, u8 *item);
    virtual ~TUnk_804F14A8();
    virtual void emit_marker_effects();
    virtual void update_attack();
    virtual void update_idle();
    virtual void init_weapon_effect_descriptor(Desc_8011E5C4 *desc);
    virtual void vfunc_60();
    s32 rotation_z;  // inferred: update_idle/update_attack clamp it, vfunc_60 rotate_matrix_z's by it
};

#endif
