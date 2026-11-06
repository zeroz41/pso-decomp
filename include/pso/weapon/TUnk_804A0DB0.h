#ifndef PSO_WEAPON_TUNK_804A0DB0_H
#define PSO_WEAPON_TUNK_804A0DB0_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include <dolphin/mtx/GeoTypes.h>

// Weapon class with vtable 0x804A0DB0 (old ctor name init_state_vector), made by
// TObjPlayer::create_state_vector_state.
class TUnk_804A0DB0 : public TItemWeapon {
public:
    virtual ~TUnk_804A0DB0();
    virtual void vfunc_60();
    virtual void update_weapon();
    TUnk_804A0DB0(TObject *parent, u8 *item);
    virtual void emit_marker_effects();
    Vec scale;  // scale_current_matrix of model 1; y drops to 0.1 on the special, regrows
};

#endif
