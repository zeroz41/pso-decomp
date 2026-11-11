#ifndef PSO_TECHNIQUE_TTECGIFOIE_H
#define PSO_TECHNIQUE_TTECGIFOIE_H

#include "types.h"
#include "pso/effect/TUnk_804CC148.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

// One flame of Gifoie, a task TTecGiFoie creates per orbit (vtable lbl_804CC800).
// Nothing names the class or its fields; the comments are readings of the code.
class TUnk_804CC800 : public TObject {
public:
    virtual ~TUnk_804CC800();
    virtual void run_task();

    TParticleCtrl **pad_1C; // one particle per entry of the band's profile, or a single one
    Vec pad_20;             // centre of the orbit
    Vec pad_2C;             // current position
    f32 pad_38;             // distance from the centre
    s32 pad_3C;             // angle on the orbit
    s32 pad_40;             // frames run
    u8 pad_44;              // level band, 0..5
    s8 pad_45;
    u8 pad_46;              // nonzero: circles in the plane facing pad_48
    u8 pad_47;              // nonzero: one continuous particle
    s32 pad_48;             // yaw
};

typedef char TUnk_804CC800_size[sizeof(TUnk_804CC800) == 0x4C ? 1 : -1];

struct TTecGiFoie : public TUnk_804CC148 {
    virtual ~TTecGiFoie();
    virtual void vfunc_6(void *);
    virtual void run_task();
    u32 m_ec;
    u8 _padF0[0x48];
    u32 m_138;
    void calc_params();
    static void create(void *arg0, void *arg1, void *arg2);
    virtual void render();
};

typedef char TTecGiFoie_size[sizeof(TTecGiFoie) == 0x13C ? 1 : -1];
#endif
