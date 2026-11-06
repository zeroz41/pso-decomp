#ifndef PSO_ITEM_TUNK_804A68C8_H
#define PSO_ITEM_TUNK_804A68C8_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A68C8 : public TItemWeapon {
public:
    TUnk_804A68C8(TObject *parent, u8 *item);
    virtual ~TUnk_804A68C8();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    f32 scale;          // uniform model scale of item index 5, eased per state
    s32 attack_spawned; // set once update_attack has spawned its cane effect
};

u8 *create_cane_weapon(u8 *item);

#endif
