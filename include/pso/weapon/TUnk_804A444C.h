#ifndef PSO_WEAPON_TUNK_804A444C_H
#define PSO_WEAPON_TUNK_804A444C_H
#include "types.h"
#include "pso/weapon/TUnk_804A4948.h"

class TUnk_804A444C : public TUnk_804A4948 {
public:
    TUnk_804A444C(TObject *parent, u8 *item);
    virtual ~TUnk_804A444C();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    virtual void emit_marker_effects();
    u8 pad_1fc[0x200 - 0x1FC];
    s32 barrel_angle;  // rotate_matrix_z angle in vfunc_60; update_idle winds it up to 0x2000
};

#endif
