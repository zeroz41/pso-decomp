#ifndef PSO_WEAPON_TUNK_804A1D30_H
#define PSO_WEAPON_TUNK_804A1D30_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include <dolphin/mtx/GeoTypes.h>

// Weapon class with vtable 0x804A1D30 (old ctor name TObjPlayer::init_state()), made by
// TObjPlayer::create_state.
class TUnk_804A1D30 : public TItemWeapon {
public:
    virtual ~TUnk_804A1D30();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    TUnk_804A1D30(TObject *parent, u8 *item);
    Vec scale;  // scale_current_matrix of model 0; update_idle/update_attack ease z
};

#endif
