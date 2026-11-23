#ifndef PSO_WEAPON_TUNK_804A2164_H
#define PSO_WEAPON_TUNK_804A2164_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

// Made by create_drill_launcher.
class TUnk_804A2164 : public TItemWeapon {
public:
    TUnk_804A2164(TObject *parent, u8 *item);
    virtual ~TUnk_804A2164();
    virtual void vfunc_60();
    virtual void emit_marker_effects();
    virtual void update_weapon();
    s32 projectile_visible;   // drill_launcher_return_timer sets it back
    s32 projectile_spin;
    s32 recoil_angle;         // rotate_matrix_z in vfunc_60
    s32 recoil_phase;
};

#endif
