#ifndef PSO_WEAPON_TUNK_804ED0A8_H
#define PSO_WEAPON_TUNK_804ED0A8_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804ED0A8 : public TItemWeapon {
public:
    TUnk_804ED0A8(TObject *parent, u8 *item);
    virtual ~TUnk_804ED0A8();
    virtual void update_attack();
    virtual void update_idle();
    virtual void vfunc_60();
    s32 pad_1f8;  // rotate_matrix_x angle for pass 1
    s32 pad_1fc;  // rotate_matrix_x angle for pass 2
};

#endif
