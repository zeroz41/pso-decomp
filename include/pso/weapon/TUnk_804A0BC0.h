#ifndef PSO_WEAPON_TUNK_804A0BC0_H
#define PSO_WEAPON_TUNK_804A0BC0_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A0BC0 : public TItemWeapon {
public:
    virtual ~TUnk_804A0BC0();
    virtual void vfunc_57();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_weapon();
    virtual void update_attack();
    virtual void emit_marker_effects();
    TUnk_804A0BC0(TObject *parent, u8 *item);
    s32 open_angle;  // BAMS, 0..0x2AAA, rotate_matrix_x in vfunc_60
    s32 open_state;  // 0 closed, 1 closing, 2 opening, 3 open
};

#endif
