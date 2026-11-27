#ifndef PSO_ENEMY_TOBJENEME1GIGUEHOMINGSHOT_H
#define PSO_ENEMY_TOBJENEME1GIGUEHOMINGSHOT_H
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/object/base/TObjMotion.h"

class TParticleCtrl;


// GiGue's homing shot: waits `timer` frames, then flies from *start toward target_id and hits it
// (made by TObjEneMe1GiGue; it overrides only the dtor and run_task).
class TObjEneMe1GiGueHomingShot : public TObjCollidable {
public:
    TObjEneMe1GiGueHomingShot(Vec *start, u16 target_id, Angle3 *angles, s32 delay, s32 double_hit, u16 src_id);
    virtual ~TObjEneMe1GiGueHomingShot();
    virtual void run_task();
    Vec pos;
    Vec prev;
    Vec vel;
    u8 pad_D0[0x18];
    f32 pad_e8;
    s32 timer;
    Vec *start;
    f32 speed;
    TParticleCtrl *ptcl0;
    TParticleCtrl *ptcl1;
    s32 state;
    s32 double_hit;            // 1: a second hit of kind 0x12 follows
    u16 target_id;
    u16 src_id;
};
LAYOUT_ASSERT(TObjEneMe1GiGueHomingShot_size, sizeof(TObjEneMe1GiGueHomingShot) == 0x10C);

#endif
