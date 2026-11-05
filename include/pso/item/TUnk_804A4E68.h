#ifndef PSO_ITEM_TUNK_804A4E68_H
#define PSO_ITEM_TUNK_804A4E68_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A4E68 : public TItemWeapon {
public:
    virtual ~TUnk_804A4E68();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    TUnk_804A4E68(TObject *parent, u8 *item);
    s32 rotation_z;  // rotate_matrix_z in vfunc_60
};

#endif
