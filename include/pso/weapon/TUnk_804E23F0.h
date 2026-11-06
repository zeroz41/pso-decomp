#ifndef PSO_WEAPON_TUNK_804E23F0_H
#define PSO_WEAPON_TUNK_804E23F0_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804E23F0 : public TItemWeapon {
public:
    virtual ~TUnk_804E23F0();
    virtual void reserved_53();
    virtual void update_weapon();
    u8 unk_1F8[0x4];
    u32 m_1fc;
    u8 unk_200[0x4];
};

#endif
