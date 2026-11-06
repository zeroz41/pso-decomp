#ifndef PSO_WEAPON_TUNK_804ED0A8_H
#define PSO_WEAPON_TUNK_804ED0A8_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804ED0A8 : public TItemWeapon {
public:
    virtual ~TUnk_804ED0A8();
    virtual void update_idle();
    virtual void update_attack();
    void *init_state_1536(s32, void *);
    u8 unk_1F8[0x4];
    s32 m_1fc;
};

#endif
