#ifndef PSO_WEAPON_TUNK_804A1098_H
#define PSO_WEAPON_TUNK_804A1098_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A1098 : public TItemWeapon {
public:
    virtual ~TUnk_804A1098();
    virtual void on_equipped();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_weapon();
    virtual void update_attack();
    virtual void emit_marker_effects();
    TUnk_804A1098(TObject *parent, u8 *item);
    saddr open_angle;  // BAMS, 0..0x2AAA, rotate_matrix_x in transform_model_node
    s32 open_state;  // 0 closed, 1 closing, 2 opening, 3 open
};

// Factory
extern "C" TItem *TObjPlayer__sub_801228CC(u8 *item);

#endif
