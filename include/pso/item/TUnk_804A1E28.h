#ifndef PSO_ITEM_TUNK_804A1E28_H
#define PSO_ITEM_TUNK_804A1E28_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A1E28 : public TItemWeapon {
public:
    virtual ~TUnk_804A1E28();
    virtual void update_idle();
    virtual void update_attack();
    virtual void update_weapon();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_60();
    TUnk_804A1E28(TObject *parent, u8 *item);
    s32 scale_step;   // 0..7, index into the cane's x/y/z scale tables (vfunc_60)
    s16 cached_tp;    // owner TP last seen by update_weapon; -1 to resync
    s16 scale_state;  // 1: stepping up, 2: stepping down, 0/3: at rest
};

u8 *create_sorcerers_cane(u8 *arg0);

#endif
