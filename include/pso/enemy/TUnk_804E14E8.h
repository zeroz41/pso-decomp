#ifndef PSO_ENEMY_TUNK_804E14E8_H
#define PSO_ENEMY_TUNK_804E14E8_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TParticleCtrl;

// x turns the start velocity about x, y about y (rotate_matrix_x / rotate_matrix_y)
struct GiGueShotAngles { s32 x, y, z; };

// GiGue's homing shot: waits `timer` frames, then flies from *start toward target_id and hits it
// (made by TObjEneMe1GiGue__sub_802CB824; the vtable at 0x804E14E8 overrides only the dtor and run_task).
class TUnk_804E14E8 : public TObjCollidable {
public:
    TUnk_804E14E8(Vec *start, u16 target_id, GiGueShotAngles *angles, s32 delay, s32 double_hit, u16 src_id);
    virtual ~TUnk_804E14E8();
    virtual void run_task();
    Vec pos;
    Vec prev;
    Vec vel;
    u8 pad_D0[0x18];
    f32 m_e8;
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
typedef char TUnk_804E14E8_size[sizeof(TUnk_804E14E8) == 0x10C ? 1 : -1];

#endif
