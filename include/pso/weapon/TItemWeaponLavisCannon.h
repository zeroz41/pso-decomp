#ifndef PSO_WEAPON_TITEMWEAPONLAVISCANNON_H
#define PSO_WEAPON_TITEMWEAPONLAVISCANNON_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Lavis shot weapon class (old ctor name init_state_object): its special
// drains 5% of the owner's HP. Made by TItemWeaponLavisCannon::create.
class TItemWeaponLavisCannon : public TItemWeapon {
public:
    virtual ~TItemWeaponLavisCannon();
    virtual void transform_model_node();
    virtual void emit_marker_effects();
    TItemWeaponLavisCannon(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    s32 rotation_z;  // rotate_matrix_z angle of the model hook, spun there
};


#endif
