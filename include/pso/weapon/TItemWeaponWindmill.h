#ifndef PSO_WEAPON_TITEMWEAPONWINDMILL_H
#define PSO_WEAPON_TITEMWEAPONWINDMILL_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// A spinning cane-type weapon class (vtable 0x804A69DC; old name
// init_state_35): spins faster while attacking and, once fast enough,
// releases a charged shot (TItemShootWindmill shoot models via
// create_shoot_model). Made by TItemWeaponWindmill::create.
class TItemWeaponWindmill : public TItemWeapon {
public:
    virtual void activate_effect(s32 effect);
    virtual void emit_marker_effects();
    virtual void transform_model_node();
    virtual void draw_held_model();
    virtual void update_idle();
    virtual void update_attack();
    virtual void update_weapon();
    virtual ~TItemWeaponWindmill();
    TItemWeaponWindmill(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    void for_each_target_in_range(f32);

    s32 rotation;           // 0x1F8: spin angle (rotate_matrix_x)
    s32 spin_speed;         // 0x1FC: angle step per frame (0xCCC..0x3333)
    s32 attack_frames;      // 0x200: frames spent attacking
    s32 charge_ready;       // 0x204: 0 for 30 frames after a charged release
    Vec gun_point; // 0x208: get_gun_point, where shots start
};

// The TItemWeaponWindmill shot callback: a TItemShootWindmill from owner.
saddr create_shoot_model(saddr owner, saddr pos, saddr dir, f32 life);
// Item timer: sets charge_ready again 30 frames after a charged release.
void charge_ready_timer(void *weapon);

#endif
