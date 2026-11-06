#ifndef PSO_WEAPON_SHOOT_TITEMSHOOTPARTICLE_H
#define PSO_WEAPON_SHOOT_TITEMSHOOTPARTICLE_H
#include "types.h"
#include "pso/weapon/shoot/TItemShoot.h"

class TItemShootParticle : public TItemShoot {
public:
    virtual ~TItemShootParticle();
    virtual void hook();
    u8 unk_58[0x8];
    u16 m_60;
    u8 unk_62[0x2];
public:
    s32 spawn_slot_emitter(s32 arg1, s32 arg2);
};
typedef char TItemShootParticle_size[sizeof(TItemShootParticle) == 0x64 ? 1 : -1];

#endif
