#ifndef PSO_ENEMY_GIGUE_TOBJENEME1GIGUEMISSILE_H
#define PSO_ENEMY_GIGUE_TOBJENEME1GIGUEMISSILE_H

#include "types.h"
#include "pso/enemy/TNeedleShoot.h"

struct TObjEneMe1GiGueMissile : public TNeedleShoot {
    TObjEneMe1GiGueMissile(TObjBase *owner, Vec *from, Vec *to, f32 speed, f32 power);
    virtual ~TObjEneMe1GiGueMissile();
    virtual void on_target_hit(TObjCollidable *target);
    virtual void on_wall_hit();
    void explode(void *pos);
    static void create(TObjBase *owner, Vec *from, Vec *to, f32 speed, f32 power);
    virtual void render();
    virtual void run_task();
    static void free_global();
    static void init_global();
    f32 motion_frame;
    f32 power;
};

LAYOUT_ASSERT(TObjEneMe1GiGueMissile_size, sizeof(TObjEneMe1GiGueMissile) == 0xC4);
#endif
