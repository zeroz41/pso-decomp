#ifndef PSO_PLAYER_TUNK_804A5740_H
#define PSO_PLAYER_TUNK_804A5740_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804A5740 : public TItemWeapon {
public:
    virtual ~TUnk_804A5740();
    virtual void vfunc_60();
    virtual void update_idle();
    void *init_state_1f8();
    virtual void update_attack();
    u8 unk_1F8[0x4];
};

#endif
