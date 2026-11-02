#ifndef PSO_PLAYER_TUNK_804A6108_H
#define PSO_PLAYER_TUNK_804A6108_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A6108 : public TItemWeapon {
public:
    virtual ~TUnk_804A6108();
    virtual void vfunc_60();
    void *init_effect_state();
    virtual void update_weapon();
    u8 unk_1F8[0x4];
};

#endif
