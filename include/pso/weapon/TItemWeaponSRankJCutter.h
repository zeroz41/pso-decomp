#ifndef PSO_WEAPON_TITEMWEAPONSRANKJCUTTER_H
#define PSO_WEAPON_TITEMWEAPONSRANKJCUTTER_H
#include "types.h"
#include "pso/weapon/TItemWeaponSRank.h"

class TItemWeaponSRankJCutter : public TItemWeaponSRank {
public:
    TItemWeaponSRankJCutter(TObject *parent, u8 *item);
    virtual ~TItemWeaponSRankJCutter();
    virtual void emit_marker_effects();
};

TItem *create_s_rank_j_cutter_weapon(u8 *item);
void enlarge_s_rank_j_cutter_blade(TObjBase *object);

#endif
