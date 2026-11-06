#ifndef PSO_WEAPON_TUNK_804A5740_H
#define PSO_WEAPON_TUNK_804A5740_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Weapon class with vtable 0x804A5740 (old ctor name init_state_1f8): idle swings
// rotation_x up to 0x2AAA, attack back to 0; the model hook (slot 60) turns the
// models after the first by it. Made by TObjPlayer__sub_8012CF84.
class TUnk_804A5740 : public TItemWeapon {
public:
    virtual ~TUnk_804A5740();
    virtual void vfunc_60();
    virtual void update_idle();
    TUnk_804A5740(TObject *parent, u8 *item);
    virtual void update_attack();
    s32 rotation_x;  // rotate_matrix_x angle of the model hook
};

extern "C" u8 *TObjPlayer__sub_8012CF84(u8 *item);

#endif
