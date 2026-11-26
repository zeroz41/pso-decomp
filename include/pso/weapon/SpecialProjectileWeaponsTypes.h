#ifndef PSO_WEAPON_SPECIALPROJECTILEWEAPONSTYPES_H
#define PSO_WEAPON_SPECIALPROJECTILEWEAPONSTYPES_H

#include "types.h"

struct RecoilWeaponView : TItemWeapon {
    s32 projectileVisible;
    s32 projectileSpin;
    s32 recoilAngle;
    s32 recoilPhase;
};
LAYOUT_ASSERT(RecoilVisibleOffset, offsetof(RecoilWeaponView, projectileVisible) == 0x1F8);
LAYOUT_ASSERT(RecoilSpinOffset, offsetof(RecoilWeaponView, projectileSpin) == 0x1FC);
LAYOUT_ASSERT(RecoilAngleOffset, offsetof(RecoilWeaponView, recoilAngle) == 0x200);
LAYOUT_ASSERT(RecoilPhaseOffset, offsetof(RecoilWeaponView, recoilPhase) == 0x204);
LAYOUT_ASSERT(RecoilWeaponExtent, sizeof(RecoilWeaponView) == 0x208);

#endif
