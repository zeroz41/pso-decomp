#ifndef PSO_WEAPON_TUNK_804A5248_H
#define PSO_WEAPON_TUNK_804A5248_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A5248 : public TItemWeapon {
public:
    virtual ~TUnk_804A5248();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    f32 barrel_scale;
};

#endif
