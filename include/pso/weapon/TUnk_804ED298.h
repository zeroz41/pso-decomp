#ifndef PSO_WEAPON_TUNK_804ED298_H
#define PSO_WEAPON_TUNK_804ED298_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804ED298 : public TItemWeapon {
public:
    TUnk_804ED298(TObject *parent, u8 *item);
    virtual ~TUnk_804ED298();
    virtual void update_attack();
    virtual void update_idle();
    virtual void vfunc_60();
    f32 pad_1f8;  // translate_matrix z offset for passes 3 and 4
    f32 pad_1fc;  // offset material colour alpha for pass 2
};

#endif
