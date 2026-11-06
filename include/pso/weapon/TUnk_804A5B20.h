#ifndef PSO_WEAPON_TUNK_804A5B20_H
#define PSO_WEAPON_TUNK_804A5B20_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// The Slicer-type weapon class (vtable 0x804A5B20; old names
// launch_slicer_shot, construct_slicer_weapon): emit_marker_effects throws
// a TTecSlicer from the weapon's two blade joints; item variants 5 and 7
// rotate and scale their blade model while attacking. Made by
// create_slicer_weapon.
class TUnk_804A5B20 : public TItemWeapon {
public:
    virtual void vfunc_60();
    virtual void emit_marker_effects();
    virtual void update_idle();
    virtual void update_attack();
    TUnk_804A5B20(TObject *parent, u8 *item);
    virtual ~TUnk_804A5B20();

    s32 rotation;       // 0x1F8: blade angle (rotate_matrix_x/z)
    WeaponVector scale; // 0x1FC: blade scale (variant 5) or offset (variant 7)
};

u8 *create_slicer_weapon(u8 *item);

#endif
