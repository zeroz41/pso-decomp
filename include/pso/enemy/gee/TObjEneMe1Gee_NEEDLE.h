#ifndef PSO_ENEMY_GEE_TOBJENEME1GEE_NEEDLE_H
#define PSO_ENEMY_GEE_TOBJENEME1GEE_NEEDLE_H
#include "types.h"
#include "pso/enemy/TNeedleShoot.h"
#include <dolphin/mtx.h>

class TObjEneMe1Gee_NEEDLE : public TNeedleShoot {
public:
    TObjEneMe1Gee_NEEDLE(TObjBase *owner, Vec *from, Vec *to, f32 speed, f32 power);
    virtual ~TObjEneMe1Gee_NEEDLE();
    virtual void on_target_hit(TObjCollidable *target);
    virtual void queue_destruction();
    virtual void on_wall_hit();
    virtual void render();
    virtual void run_task();
    static void free_global();
    static void init_global();
    f32 power;
    s32 linger_frames;  // frames the needle stays stuck after a wall hit (150)
};
LAYOUT_ASSERT(TObjEneMe1Gee_NEEDLE_size, sizeof(TObjEneMe1Gee_NEEDLE) == 0xC4);

#endif
