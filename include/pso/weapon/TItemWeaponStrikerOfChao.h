#ifndef PSO_WEAPON_TITEMWEAPONSTRIKEROFCHAO_H
#define PSO_WEAPON_TITEMWEAPONSTRIKEROFCHAO_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponStrikerOfChao : public TItemWeapon {
public:
    virtual ~TItemWeaponStrikerOfChao();
    virtual void draw_held_model();
    virtual void emit_marker_effects();
    virtual void update_weapon();
    TItemWeaponStrikerOfChao(TObject *parent, u8 *item);
    s32 swing_angle;  // BAMS, stepped 0x38E between 0 and 0x1555 by update_weapon, added to model node +0x18
    s32 swing_rising; // 1 while swing_angle counts up
};

// Factory
extern "C" {
TItem *TObjPlayer__sub_8012380C(u8 *item);
}

#endif
