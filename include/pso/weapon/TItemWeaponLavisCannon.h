#ifndef PSO_WEAPON_TITEMWEAPONLAVISCANNON_H
#define PSO_WEAPON_TITEMWEAPONLAVISCANNON_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Lavis shot weapon class (old ctor name init_state_object): its special
// drains 5% of the owner's HP. Made by TObjPlayer__sub_8012AB1C.
class TItemWeaponLavisCannon : public TItemWeapon {
public:
    virtual ~TItemWeaponLavisCannon();
    virtual void transform_model_node();
    virtual void emit_marker_effects();
    TItemWeaponLavisCannon(TObject *parent, u8 *item);
    s32 rotation_z;  // rotate_matrix_z angle of the model hook, spun there
};

extern "C" TItem *TObjPlayer__sub_8012AB1C(u8 *item);

#endif
