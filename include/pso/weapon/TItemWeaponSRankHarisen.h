#ifndef PSO_WEAPON_TITEMWEAPONSRANKHARISEN_H
#define PSO_WEAPON_TITEMWEAPONSRANKHARISEN_H
#include "types.h"
#include "pso/weapon/TItemWeaponSRank.h"

// The S-rank Harisen weapon class, the S-rank form of
// TItemWeaponHarisenBattleFan: start_attack_effect flattens the fan, update_weapon grows it back.
class TItemWeaponSRankHarisen : public TItemWeaponSRank {
public:
    virtual void transform_model_node();
    virtual void start_attack_effect();
    virtual void update_weapon();
    virtual ~TItemWeaponSRankHarisen();
    TItemWeaponSRankHarisen(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    Vec scale;  // model scale (scale_current_matrix); y is animated
};

#endif
