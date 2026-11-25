#ifndef PSO_WEAPON_TITEMWEAPONSRANKSLICER_H
#define PSO_WEAPON_TITEMWEAPONSRANKSLICER_H
#include "types.h"
#include "pso/weapon/TItemWeaponSRank.h"

class TItemWeaponSRankSlicer : public TItemWeaponSRank {
public:
    TItemWeaponSRankSlicer(TObject *parent, u8 *item);
    virtual ~TItemWeaponSRankSlicer();
    virtual void emit_marker_effects();
};

TItem *create_s_rank_slicer_weapon(u8 *item);

#endif
