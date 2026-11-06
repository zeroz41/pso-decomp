#ifndef PSO_WEAPON_TUNK_804F0810_H
#define PSO_WEAPON_TUNK_804F0810_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804F0810 : public TItemWeapon {
public:
    virtual ~TUnk_804F0810();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    virtual void reserved_53();
    virtual void emit_marker_effects();
    void *enter_timed_state(s32, void *);
    u8 unk_1F8[0x4];
};

#endif
