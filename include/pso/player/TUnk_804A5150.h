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
    void *init_vtable_and_handlers();
    u8 unk_1F8[0x4];
    s32 m_1fc;
};

#endif
