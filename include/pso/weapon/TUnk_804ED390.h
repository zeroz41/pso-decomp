#ifndef PSO_WEAPON_TUNK_804ED390_H
#define PSO_WEAPON_TUNK_804ED390_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804ED390 : public TItemWeapon {
public:
    virtual ~TUnk_804ED390();
    virtual void update_idle();
    virtual void update_attack();
    void*init_vtable_1f8(s32, void *);
    u8 unk_1F8[0x4];
};

#endif
