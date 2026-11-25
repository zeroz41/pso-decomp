#ifndef PSO_WEAPON_TITEMWEAPONFLIGHTFAN_H
#define PSO_WEAPON_TITEMWEAPONFLIGHTFAN_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include <dolphin/mtx/GeoTypes.h>

// Slicer weapon class (old ctor name init_position_state): its special
// throws TTecSlicer from joints 5 and 4. Made by TObjPlayer::create_position_state.
class TItemWeaponFlightFan : public TItemWeapon {
public:
    virtual ~TItemWeaponFlightFan();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void emit_marker_effects();
    virtual void update_attack();
    TItemWeaponFlightFan(TObject *parent, u8 *item);
    Vec scale;       // 0x1F8: scale_current_matrix of model 2; 1 idle, 10 attacking
    s32 rotation_x;  // 0x204: rotate_matrix_x of models 1 and 3 (opposite ways)
};

#endif
