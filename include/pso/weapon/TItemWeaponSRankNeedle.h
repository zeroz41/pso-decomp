#ifndef PSO_WEAPON_TITEMWEAPONSRANKNEEDLE_H
#define PSO_WEAPON_TITEMWEAPONSRANKNEEDLE_H
#include "types.h"
#include "pso/weapon/TItemWeaponSRank.h"

class TItemWeaponSRankNeedle : public TItemWeaponSRank {
public:
    TItemWeaponSRankNeedle(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponSRankNeedle();
    virtual void emit_marker_effects();
};

#endif
