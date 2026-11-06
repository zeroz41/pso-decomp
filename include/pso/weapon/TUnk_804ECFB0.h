#ifndef PSO_WEAPON_TUNK_804ECFB0_H
#define PSO_WEAPON_TUNK_804ECFB0_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804ECFB0 : public TItemWeapon {
public:
    virtual ~TUnk_804ECFB0();
    virtual void update_weapon();
    u8 unk_1F8[0x4];
    s16 m_1fc;
    u8 unk_1FE[0x2];
};

#endif
