#ifndef PSO_WEAPON_TITEMWEAPONBELRACANNON_H
#define PSO_WEAPON_TITEMWEAPONBELRACANNON_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponBelraCannon : public TItemWeapon {
public:
    virtual ~TItemWeaponBelraCannon();
    TItemWeaponBelraCannon(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual void update_weapon();
    virtual void emit_marker_effects();
    // 0 after a shot until belra_cannon_return_timer fires (0x1E frames); update_weapon
    // hides model node child bit 8 while 0.
    s32 shot_ready;
};

// Timer callback: lets the cannon shoot again.
void belra_cannon_return_timer(TItemWeaponBelraCannon *weapon);
u32 belra_cannon_create_extra_shot(TItemWeapon *player, s32 pos, s32 dir, f32 life);
saddr belra_cannon_create_shot(TItemWeapon *owner, s32 pos, s32 dir, f32 life);

#endif
