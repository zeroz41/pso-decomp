#ifndef PSO_WEAPON_TUNK_804A2F78_H
#define PSO_WEAPON_TUNK_804A2F78_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include <dolphin/mtx/GeoTypes.h>

// Weapon class with vtable 0x804A2F78 (old ctor name setup_effect), made by
// TObjPlayer::create_effect_state.
class TUnk_804A2F78 : public TItemWeapon {
public:
    virtual ~TUnk_804A2F78();
    virtual void vfunc_57();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    TUnk_804A2F78(TObject *parent, u8 *item);
    Vec scale;  // scale_current_matrix of model 2; z eases to 4 attacking, 1 idle
};

#endif
