#ifndef PSO_WEAPON_TUNK_804A5150_H
#define PSO_WEAPON_TUNK_804A5150_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A5150 : public TItemWeapon {
public:
    virtual ~TUnk_804A5150();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_attack();
    TUnk_804A5150(TObject *parent, u8 *item);
    s32 rotation_x;  // rotate_matrix_x in transform_model_node
    s32 rotation_z;  // rotate_matrix_z in transform_model_node
};

#endif
