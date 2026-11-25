#ifndef PSO_WEAPON_TITEMWEAPONSRANKBAZOOKA_H
#define PSO_WEAPON_TITEMWEAPONSRANKBAZOOKA_H
#include "types.h"
#include "pso/weapon/TUnk_804A4948.h"

// The S-rank bazooka-type weapon class: after a shot
// (vfunc_62) update_weapon slides the barrel back and returns it.
class TItemWeaponSRankBazooka : public TUnk_804A4948 {
public:
    virtual void transform_model_node();
    virtual void update_weapon();
    TItemWeaponSRankBazooka(TObject *parent, u8 *item);
    virtual void vfunc_62();
    virtual ~TItemWeaponSRankBazooka();
    f32 barrel_offset;  // translate_matrix y offset in transform_model_node, 0 to -2
    s32 recoil_state;   // 1 sliding back, 2 returning, 0 at rest
};

#endif
