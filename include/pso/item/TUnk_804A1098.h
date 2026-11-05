#ifndef PSO_ITEM_TUNK_804A1098_H
#define PSO_ITEM_TUNK_804A1098_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A1098 : public TItemWeapon {
public:
    virtual ~TUnk_804A1098();
    virtual void vfunc_57();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_weapon();
    virtual void update_attack();
    virtual void emit_marker_effects();
    TUnk_804A1098(TObject *parent, u8 *item);
    s32 open_angle;  // BAMS, 0..0x2AAA, rotate_matrix_x in vfunc_60
    s32 open_state;  // 0 closed, 1 closing, 2 opening, 3 open
};

// Factory
extern "C" u8 *TObjPlayer__sub_801228CC(u8 *arg0);

#endif
