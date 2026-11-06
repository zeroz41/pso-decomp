#ifndef PSO_WEAPON_TUNK_804A1A48_H
#define PSO_WEAPON_TUNK_804A1A48_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A1A48 : public TItemWeapon {
public:
    virtual ~TUnk_804A1A48();
    virtual void reserved_53();
    virtual void emit_marker_effects();
    virtual void update_weapon();
    TUnk_804A1A48(TObject *parent, u8 *item);
    s32 swing_angle;  // BAMS, stepped 0x38E between 0 and 0x1555 by update_weapon, added to model node +0x18
    s32 swing_rising; // 1 while swing_angle counts up
};

// Factory
extern "C" {
u8 *TObjPlayer__sub_8012380C(u8 *arg0);
}

#endif
