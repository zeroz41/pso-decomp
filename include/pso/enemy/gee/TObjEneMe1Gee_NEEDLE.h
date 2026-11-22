#ifndef PSO_ENEMY_GEE_TOBJENEME1GEE_NEEDLE_H
#define PSO_ENEMY_GEE_TOBJENEME1GEE_NEEDLE_H
#include "types.h"
#include "pso/enemy/TNeedleShoot.h"
#include <dolphin/mtx.h>

class TObjEneMe1Gee_NEEDLE : public TNeedleShoot {
public:
    TObjEneMe1Gee_NEEDLE(TObject *owner, Vec *from, Vec *to, f32 speed, f32 power);
    virtual ~TObjEneMe1Gee_NEEDLE();
    virtual void on_target_hit(void *);
    virtual void queue_destruction();
    virtual void on_wall_hit();
    virtual void render();
    virtual void run_task();
    f32 m_bc;
    s32 m_c0;
};
LAYOUT_ASSERT(TObjEneMe1Gee_NEEDLE_size, sizeof(TObjEneMe1Gee_NEEDLE) == 0xC4);

extern "C" {
void TObjEneMe1Gee__sub_802A4D4C(void);
}

#endif
