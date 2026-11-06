#ifndef PSO_WEAPON_TUNK_804A6108_H
#define PSO_WEAPON_TUNK_804A6108_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Weapon class with vtable 0x804A6108 (old ctor name init_effect_state): update_weapon
// spins rotation_z; the model hook (slot 60) turns model 1 by it and model 2 the
// other way. Made by TObjPlayer__sub_8012EFAC.
class TUnk_804A6108 : public TItemWeapon {
public:
    virtual ~TUnk_804A6108();
    virtual void vfunc_60();
    TUnk_804A6108(TObject *parent, u8 *item);
    virtual void update_weapon();
    s32 rotation_z;  // rotate_matrix_z angle of the model hook
};

extern "C" u8 *TObjPlayer__sub_8012EFAC(u8 *item);

#endif
