#ifndef PSO_WEAPON_TITEMWEAPONFIST_H
#define PSO_WEAPON_TITEMWEAPONFIST_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TItemWeaponFist : public TItemWeapon {
public:
    virtual ~TItemWeaponFist();
    virtual void draw_held_model();
    virtual void emit_marker_effects();
    virtual void on_equipped();
    virtual void on_unequipped();
    virtual void transform_model_node();
    TItemWeaponFist(TObject *parent, u8 *item);
    static TItem *create(u8 *item);
};

extern s32 knuckle_marker_joint_table[];
// Mirror plane for the second hand: a point and a normal.
struct MirrorPlane {
    f32 point_x;
    f32 point_y;
    f32 point_z;
    f32 normal_x;
    f32 normal_y;
    f32 normal_z;
};

#endif
