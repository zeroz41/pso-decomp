#ifndef PSO_WEAPON_TUNK_804A4138_H
#define PSO_WEAPON_TUNK_804A4138_H
#include "types.h"
#include "pso/weapon/TUnk_804A4948.h"

class TUnk_804A4138 : public TUnk_804A4948 {
public:
    TUnk_804A4138(TObject *parent, u8 *item);
    virtual ~TUnk_804A4138();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_attack();
    s32 rotation;  // rotate_matrix_z angle in transform_model_node, swung by update_attack
};

#endif
