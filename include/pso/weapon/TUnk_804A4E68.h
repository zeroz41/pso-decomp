#ifndef PSO_WEAPON_TUNK_804A4E68_H
#define PSO_WEAPON_TUNK_804A4E68_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804A4E68 : public TItemWeapon {
public:
    virtual ~TUnk_804A4E68();
    virtual void transform_model_node();
    virtual void update_idle();
    virtual void update_attack();
    TUnk_804A4E68(TObject *parent, u8 *item);
    s32 rotation_z;  // rotate_matrix_z in transform_model_node
};

#endif
