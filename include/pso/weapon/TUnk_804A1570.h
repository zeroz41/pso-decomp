#ifndef PSO_WEAPON_TUNK_804A1570_H
#define PSO_WEAPON_TUNK_804A1570_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A1570 : public TItemWeapon {
public:
    virtual ~TUnk_804A1570();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    virtual void reserved_53();
    TUnk_804A1570(TObject *parent, u8 *item);
    WeaponVector scale;  // model scale (scale_current_matrix); x and y follow z
};

#endif
