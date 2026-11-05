#ifndef PSO_PLAYER_TUNK_804A5150_H
#define PSO_PLAYER_TUNK_804A5150_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A5150 : public TItemWeapon {
public:
    virtual ~TUnk_804A5150();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    TUnk_804A5150(TObject *parent, u8 *item);
    s32 rotation_x;  // rotate_matrix_x in vfunc_60
    s32 rotation_z;  // rotate_matrix_z in vfunc_60
};

#endif
