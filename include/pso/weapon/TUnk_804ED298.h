#ifndef PSO_WEAPON_TUNK_804ED298_H
#define PSO_WEAPON_TUNK_804ED298_H
#include "types.h"
#include "pso/weapon/TItemWeapon.h"

class TUnk_804ED298 : public TItemWeapon {
public:
    virtual ~TUnk_804ED298();
    virtual void update_idle();
    virtual void update_attack();
    void*set_mode_floats(s32, void *);
    u8 unk_1F8[0x4];
    float m_1fc;
};

#endif
