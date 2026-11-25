#ifndef PSO_WEAPON_TITEMWEAPONSORCERERSCANE_H
#define PSO_WEAPON_TITEMWEAPONSORCERERSCANE_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponSorcerersCane : public TItemWeapon {
public:
    virtual ~TItemWeaponSorcerersCane();
    virtual void update_idle();
    virtual void update_attack();
    virtual void update_weapon();
    virtual void on_equipped();
    virtual void on_unequipped();
    virtual void transform_model_node();
    TItemWeaponSorcerersCane(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    s32 scale_step;   // 0..7, index into the cane's x/y/z scale tables (transform_model_node)
    s16 cached_tp;    // owner TP last seen by update_weapon; -1 to resync
    s16 scale_state;  // 1: stepping up, 2: stepping down, 0/3: at rest
};

#endif
