#ifndef PSO_WEAPON_TITEMWEAPONHEAVENPUNISHER_H
#define PSO_WEAPON_TITEMWEAPONHEAVENPUNISHER_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/CapturedTargetList.h"

class TItemWeaponHeavenPunisher : public TItemWeapon {
public:
    TItemWeaponHeavenPunisher(TObject *parent, u8 *item);
    virtual ~TItemWeaponHeavenPunisher();
    virtual void activate_effect(s32);
    void heaven_punisher_strike_locks();
    virtual void emit_marker_effects();

    CapturedTargetList captured_targets;
    Vec captured_muzzle;
};

LAYOUT_ASSERT(HeavenPunisherMuzzleOffset, offsetof(TItemWeaponHeavenPunisher, captured_muzzle) == 0x224);

#endif
