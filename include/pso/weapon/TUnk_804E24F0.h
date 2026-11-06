#ifndef PSO_WEAPON_TUNK_804E24F0_H
#define PSO_WEAPON_TUNK_804E24F0_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804E24F0 : public TItemWeapon {
public:
    virtual ~TUnk_804E24F0();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void emit_marker_effects();
    void*init_object(s32, void *);
    virtual void update_attack();
    u8 unk_1F8[0x4];
};

#endif
