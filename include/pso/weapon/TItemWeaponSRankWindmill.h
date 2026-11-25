#ifndef PSO_WEAPON_TITEMWEAPONSRANKWINDMILL_H
#define PSO_WEAPON_TITEMWEAPONSRANKWINDMILL_H
#include "types.h"
#include "pso/weapon/TUnk_804A4948.h"

class TItemWeaponSRankWindmill : public TUnk_804A4948 {
public:
    TItemWeaponSRankWindmill(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponSRankWindmill();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_weapon();
    virtual void update_attack();
    virtual void draw_held_model();
    s32 blade_angle;    // rotate_matrix_x angle in transform_model_node, advanced by blade_speed
    s32 blade_speed;    // 0xCCC idle, up to 0x3333 while attacking
    s32 attack_frames;  // counts update_attack calls
    s32 blend_off;      // 0: draw_held_model sets bit 0x10 of the model's flags while drawing
    u8 pad_20c[0x218 - 0x20C];
};

#endif
