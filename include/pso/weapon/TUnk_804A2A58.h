#ifndef PSO_WEAPON_TUNK_804A2A58_H
#define PSO_WEAPON_TUNK_804A2A58_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A2A58 : public TItemWeapon {
public:
    TUnk_804A2A58(TObject *parent, u8 *item);
    virtual ~TUnk_804A2A58();
    virtual void update_weapon();
    virtual void emit_marker_effects();
    virtual void vfunc_60();
    s32 rotation_y; // rotate_matrix_y angle of the barrel, wound back by update_weapon
    s32 spin_speed; // barrel spin added per shot, decays in update_weapon
};


#endif
