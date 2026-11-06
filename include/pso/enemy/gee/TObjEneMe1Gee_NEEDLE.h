#ifndef PSO_ENEMY_GEE_TOBJENEME1GEE_NEEDLE_H
#define PSO_ENEMY_GEE_TOBJENEME1GEE_NEEDLE_H
#include "types.h"
#include "pso/enemy/TNeedleShoot.h"

class TObjEneMe1Gee_NEEDLE : public TNeedleShoot {
public:
    virtual ~TObjEneMe1Gee_NEEDLE();
    virtual void vfunc_9(void *);
    virtual int queue_destruction();
    virtual int vfunc_6();
    virtual void render();
    virtual void run_task();
    u8 unk_BC[0x4];
    s32 m_c0;
};
typedef char TObjEneMe1Gee_NEEDLE_size[sizeof(TObjEneMe1Gee_NEEDLE) == 0xC4 ? 1 : -1];

#endif
