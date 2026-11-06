#ifndef PSO_WEAPON_SHOOT_TITEMSHOOTMODEL_H
#define PSO_WEAPON_SHOOT_TITEMSHOOTMODEL_H
#include "pso/weapon/shoot/TItemShoot.h"
#include "types.h"

class TItemShootModel : public TItemShoot {
public:
 void* m_58;
 void* m_5C;
 s32   m_60;
 s32   m_64;
 s32   m_68;

public:
    TItemShootModel(void* owner, const Vec* pos, const Vec* dir, f32 life);
    virtual ~TItemShootModel();
    void sub_80129118(s32, s32);
    s32 is_owner_alive();
    virtual void render();
};

#endif
