#ifndef PSO_WEAPON_TITEMWEAPONSBEATSBLADE_H
#define PSO_WEAPON_TITEMWEAPONSBEATSBLADE_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Weapon class (old ctor name init_state_1f8): idle swings
// rotation_x up to 0x2AAA, attack back to 0; the model hook (slot 60) turns the
// models after the first by it. Made by TItemWeaponSBeatsBlade::create.
class TItemWeaponSBeatsBlade : public TItemWeapon {
public:
    virtual ~TItemWeaponSBeatsBlade();
    virtual void transform_model_node();
    virtual void update_idle();
    TItemWeaponSBeatsBlade(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual void update_attack();
    s32 rotation_x;  // rotate_matrix_x angle of the model hook
};

extern "C" TItem *TItemWeaponSBeatsBlade::create(u8 *item);

#endif
