#ifndef PSO_WEAPON_TUNK_804A69DC_H
#define PSO_WEAPON_TUNK_804A69DC_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// A spinning cane-type weapon class (vtable 0x804A69DC; old name
// init_state_35): spins faster while attacking and, once fast enough,
// releases a charged shot (TUnk_804A69C0 shoot models via
// create_shoot_model). Made by TObjPlayer::create_state_35_alt.
class TUnk_804A69DC : public TItemWeapon {
public:
    virtual void activate_effect(s32 effect);
    virtual void emit_marker_effects();
    virtual void vfunc_60();
    virtual void reserved_53();
    virtual void update_idle();
    virtual void update_attack();
    virtual void update_weapon();
    virtual ~TUnk_804A69DC();
    TUnk_804A69DC(TObject *parent, u8 *item);
    void for_each_target_in_range(f32);

    s32 rotation;           // 0x1F8: spin angle (rotate_matrix_x)
    s32 spin_speed;         // 0x1FC: angle step per frame (0xCCC..0x3333)
    s32 attack_frames;      // 0x200: frames spent attacking
    s32 charge_ready;       // 0x204: 0 for 30 frames after a charged release
    WeaponVector gun_point; // 0x208: get_gun_point, where shots start
};

#endif
