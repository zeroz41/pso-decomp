#ifndef PSO_PLAYER_TUNK_804F0AF8_H
#define PSO_PLAYER_TUNK_804F0AF8_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804F0AF8 : public TItemWeapon {
public:
    virtual ~TUnk_804F0AF8();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void reserved_53();
    virtual void update_attack();
    void *init_fields(s32, void *);
    u8 unk_1F8[0x4];
    u32 m_1fc;
};

#endif
