#ifndef PSO_MISC_TODRAGONFLY_H
#define PSO_MISC_TODRAGONFLY_H

#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"

struct TODragonfly : public TUnk_804AFBF8 {
    TODragonfly();
    virtual ~TODragonfly();
    virtual void vfunc_14();
    void sub_80164A90();
    void sub_80164990();
    virtual void render();
    virtual void run_task();
    u8 unk_C8[0x4];
    u32 m_cc;
    f32 wander_radius;  // how far from home pick_random_destination may aim
    Vec destination;    // the point it is flying to
    Vec step;           // per-frame move toward destination, scaled by scale.z
    f32 m_ec;
    union { u8 unk_F0[4]; f32 bob_offset; };
    f32 m_f4;
    u32 m_f8;
    u32 m_fc;
    s32 pick_random_destination(f32 farg0);
    void move_toward_target();
    void update_idle();
};

typedef char TODragonfly_size[sizeof(TODragonfly) == 0x100 ? 1 : -1];
#endif
