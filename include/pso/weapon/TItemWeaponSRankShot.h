#ifndef PSO_WEAPON_TITEMWEAPONSRANKSHOT_H
#define PSO_WEAPON_TITEMWEAPONSRANKSHOT_H
#include "types.h"
#include "pso/weapon/TUnk_804A4948.h"

class TItemWeaponSRankShot : public TUnk_804A4948 {
public:
    TItemWeaponSRankShot(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponSRankShot();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_attack();
    virtual void emit_marker_effects();
    u8 pad_1fc[0x200 - 0x1FC];
    s32 barrel_angle;  // rotate_matrix_z angle in transform_model_node; update_idle winds it up to 0x2000
};

#endif
