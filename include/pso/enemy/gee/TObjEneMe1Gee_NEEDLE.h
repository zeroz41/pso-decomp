#ifndef PSO_ENEMY_GEE_TOBJENEME1GEE_NEEDLE_H
#define PSO_ENEMY_GEE_TOBJENEME1GEE_NEEDLE_H
#include "types.h"
#include "pso/enemy/TNeedleShoot.h"
#include <dolphin/mtx.h>

class TObjEneMe1Gee_NEEDLE : public TNeedleShoot {
public:
    virtual ~TObjEneMe1Gee_NEEDLE();
    virtual void vfunc_9(void *);
    virtual int queue_destruction();
    virtual int vfunc_6();
    virtual void render();
    virtual void run_task();
    f32 m_bc;
    s32 m_c0;
};
typedef char TObjEneMe1Gee_NEEDLE_size[sizeof(TObjEneMe1Gee_NEEDLE) == 0xC4 ? 1 : -1];

extern "C" {
TObjEneMe1Gee_NEEDLE *TObjEneMe1Gee_NEEDLE__ct(TObjEneMe1Gee_NEEDLE *self, TObject *owner, Vec *from, Vec *to, f32 farg0,
                                               f32 power);
void TObjEneMe1Gee__sub_802A4D4C(void);
}

#endif
