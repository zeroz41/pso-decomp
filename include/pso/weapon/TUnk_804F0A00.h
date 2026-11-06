#ifndef PSO_WEAPON_TUNK_804F0A00_H
#define PSO_WEAPON_TUNK_804F0A00_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804F0A00 : public TItemWeapon {
public:
    virtual ~TUnk_804F0A00();
    virtual void vfunc_60();
    virtual void update_idle();
    virtual void update_attack();
    u8 unk_1F8[0x4];
    s32 m_1fc;
    u8 unk_200[0x4];
};

#endif
