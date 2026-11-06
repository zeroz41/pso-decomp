#ifndef PSO_WEAPON_TUNK_804A3928_H
#define PSO_WEAPON_TUNK_804A3928_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include <dolphin/mtx/GeoTypes.h>

class TUnk_804A3928 : public TItemWeapon {
public:
    TUnk_804A3928(TObject *parent, u8 *item);
    virtual ~TUnk_804A3928();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    Vec scale; // scale_current_matrix of model 0; update_idle/update_attack ease z
};

#endif
