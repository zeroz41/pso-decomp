#ifndef PSO_WEAPON_TITEMWEAPONSRANKCLAW_H
#define PSO_WEAPON_TITEMWEAPONSRANKCLAW_H
#include "types.h"
#include "pso/weapon/TUnk_804A4948.h"

class TItemWeaponSRankClaw : public TUnk_804A4948 {
public:
    TItemWeaponSRankClaw(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponSRankClaw();
    virtual void draw_held_model();
};

#endif
