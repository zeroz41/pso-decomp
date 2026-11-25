#ifndef PSO_WEAPON_TITEMWEAPONGASSASSINSSABERS_H
#define PSO_WEAPON_TITEMWEAPONGASSASSINSSABERS_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponGAssassinsSabers : public TItemWeapon {
public:
    TItemWeaponGAssassinsSabers(TObject *parent, u8 *item);
    virtual ~TItemWeaponGAssassinsSabers();
    virtual void update_attack();
    virtual void update_idle();
    virtual void transform_model_node();
    s32 pad_1f8;  // rotate_matrix_x angle for pass 1
    s32 pad_1fc;  // rotate_matrix_x angle for pass 2
};

#endif
