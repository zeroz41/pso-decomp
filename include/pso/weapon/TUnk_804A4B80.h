#ifndef PSO_WEAPON_TUNK_804A4B80_H
#define PSO_WEAPON_TUNK_804A4B80_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A4B80 : public TItemWeapon {
public:
    virtual ~TUnk_804A4B80();
    virtual void activate_effect(s32);
    void heaven_punisher_strike_locks();
    virtual void emit_marker_effects();

    u32 captured_targets[11];
    Vec captured_muzzle;
};

typedef char HeavenPunisherMuzzleOffset[offsetof(TUnk_804A4B80, captured_muzzle) == 0x224 ? 1 : -1];

#endif
