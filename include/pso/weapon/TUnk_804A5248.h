#ifndef PSO_WEAPON_TUNK_804A5248_H
#define PSO_WEAPON_TUNK_804A5248_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Made by create_rifle_weapon.
class TUnk_804A5248 : public TItemWeapon {
public:
    TUnk_804A5248(TObject *parent, u8 *item);
    virtual ~TUnk_804A5248();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    f32 barrel_scale;
};

#endif
