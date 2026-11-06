#ifndef PSO_PLAYER_TUNK_804A4138_H
#define PSO_PLAYER_TUNK_804A4138_H
#include "types.h"
#include "pso/unk/TUnk_804A4948.h"

class TUnk_804A4138 : public TUnk_804A4948 {
public:
    TUnk_804A4138(TObject *parent, u8 *item);
    virtual ~TUnk_804A4138();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    s32 rotation;  // rotate_matrix_z angle in vfunc_60, swung by update_attack
};

#endif
