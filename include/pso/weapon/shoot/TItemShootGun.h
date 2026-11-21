#ifndef PSO_WEAPON_SHOOT_TITEMSHOOTGUN_H
#define PSO_WEAPON_SHOOT_TITEMSHOOTGUN_H

#include "pso/weapon/shoot/TItemShootModel.h"
#include "types.h"

class TItemShootGun : public TItemShootModel {
public:
 s32 m_6C;
 uaddr m_70;

public:
    TItemShootGun(void* owner, const Vec* pos, const Vec* endpoint, f32 life);
    // render is the key function (the vtable follows its definition order).
    virtual void render();
    virtual void hook();
    virtual ~TItemShootGun();
public:
    static u32 create(saddr owner, saddr pos, saddr endpoint, f32 life);
    void set_texture_id(s32 id);
};

#endif
