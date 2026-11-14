#ifndef PSO_WEAPON_TUNK_804ED390_H
#define PSO_WEAPON_TUNK_804ED390_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804ED390 : public TItemWeapon {
public:
    TUnk_804ED390(TObject *parent, u8 *item);
    virtual ~TUnk_804ED390();
    virtual void update_attack();
    virtual void update_idle();
    virtual void vfunc_60();
    f32 pad_1f8;  // scale_matrix y/z for passes 1 and 2
};

#endif
