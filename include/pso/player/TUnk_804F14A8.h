#ifndef PSO_PLAYER_TUNK_804F14A8_H
#define PSO_PLAYER_TUNK_804F14A8_H
#include "types.h"
#include "pso/items/TItemWeapon.h"

class TUnk_804F14A8 : public TItemWeapon {
public:
    virtual ~TUnk_804F14A8();
    virtual void vfunc_60();
    virtual void update_idle();
    void *init_state_34_alt(s32, void *);
    virtual void update_attack();
    virtual void emit_marker_effects();
    u8 unk_1F8[0x4];
};

#endif
