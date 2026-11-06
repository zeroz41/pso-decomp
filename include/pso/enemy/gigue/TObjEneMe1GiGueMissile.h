#ifndef PSO_ENEMY_GIGUE_TOBJENEME1GIGUEMISSILE_H
#define PSO_ENEMY_GIGUE_TOBJENEME1GIGUEMISSILE_H

#include "types.h"
#include "pso/enemy/TNeedleShoot.h"

struct TObjEneMe1GiGueMissile : public TNeedleShoot {
    virtual ~TObjEneMe1GiGueMissile();
    virtual void vfunc_9(void *);
    virtual int vfunc_6();
    void explode(void *pos);
    static void create(s32 arg0, s32 arg1, s32 arg2, f32 farg0, f32 farg1);
    virtual void render();
    virtual void run_task();
    void update_lifetime();
    u8 unk_BC[0x4];
    f32 m_c0;
};

typedef char TObjEneMe1GiGueMissile_size[sizeof(TObjEneMe1GiGueMissile) == 0xC4 ? 1 : -1];
#endif
