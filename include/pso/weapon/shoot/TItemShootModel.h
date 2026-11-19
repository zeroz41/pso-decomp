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
    // render is declared first: it is the key function that puts the vtable
    // in TItemShoot.cpp (the destructor's kept copy is in another TU).
    virtual void render();
    virtual ~TItemShootModel();
    void sub_80129118(s32, s32);
    s32 is_owner_alive();
};

#endif
