#ifndef PSO_WEAPON_SHOOT_TITEMSHOOTGUN_H
#define PSO_WEAPON_SHOOT_TITEMSHOOTGUN_H

#include "pso/weapon/shoot/TItemShootModel.h"
#include "types.h"

class TItemShootGun : public TItemShootModel {
public:
 s32 m_6C;
 u32 m_70;

public:
    TItemShootGun(void* owner, const Vec* pos, const Vec* endpoint, f32 life);
    virtual ~TItemShootGun();
    virtual void render();
    virtual void hook();
public:
    static u32 create(s32 owner, s32 pos, s32 endpoint, f32 life);
};

#endif
