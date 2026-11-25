#ifndef PSO_WEAPON_TITEMWEAPONSLICER_H
#define PSO_WEAPON_TITEMWEAPONSLICER_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The Slicer-type weapon class (old names
// launch_slicer_shot, construct_slicer_weapon): emit_marker_effects throws
// a TTecSlicer from the weapon's two blade joints; item variants 5 and 7
// rotate and scale their blade model while attacking. Made by
// TItemWeaponSlicer::create.
class TItemWeaponSlicer : public TItemWeapon {
public:
    virtual void transform_model_node();
    virtual void emit_marker_effects();
    virtual void update_idle();
    virtual void update_attack();
    TItemWeaponSlicer(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
    virtual ~TItemWeaponSlicer();

    s32 rotation;       // 0x1F8: blade angle (rotate_matrix_x/z)
    WeaponVector scale; // 0x1FC: blade scale (variant 5) or offset (variant 7)
};

void enlarge_flight_cutter_slicer(void *arg0);

#endif
