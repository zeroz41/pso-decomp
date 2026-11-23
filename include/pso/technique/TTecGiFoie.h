#ifndef PSO_TECHNIQUE_TTECGIFOIE_H
#define PSO_TECHNIQUE_TTECGIFOIE_H

#include "types.h"
#include "pso/technique/TTecCircle.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

// One flame of Gifoie, a task TTecGiFoie creates per orbit (vtable lbl_804CC800).
// Nothing names the class or its fields; the comments are readings of the code.
class TUnk_804CC800 : public TObject {
public:
    TUnk_804CC800(Vec *pos, s32 angle, s32 band, s32 level, TObject *parent, u8 single);
    virtual ~TUnk_804CC800();
    virtual void run_task();

    TParticleCtrl **pad_1C; // one particle per entry of the band's profile, or a single one
    Vec pad_20;             // centre of the orbit
    Vec pad_2C;             // current position
    f32 pad_38;             // distance from the centre
    s32 pad_3C;             // angle on the orbit
    s32 pad_40;             // frames run
    u8 pad_44;              // level band, 0..5
    s8 pad_45;              // technique level
    u8 pad_46;              // nonzero: circles in the plane facing pad_48
    u8 pad_47;              // nonzero: one continuous particle
    s32 pad_48;             // yaw
};

LAYOUT_ASSERT(TUnk_804CC800_size, sizeof(TUnk_804CC800) == 0x4C);

struct TTecGiFoie : public TTecCircle {
    TTecGiFoie(saddr source, Vec *origin, s32 level);
    virtual ~TTecGiFoie();
    virtual void vfunc_6(void *);
    virtual void run_task();
    TUnk_804CC800 *orbits[3];  // one flame per orbit, orbit_counts[band] of them
    u16 hitIds[32];            // entity ids vfunc_6 has already hit
    s32 hitCursor;
    void calc_params();
    static void create(void *source, void *origin, s32 level);
    virtual void render();
};

LAYOUT_ASSERT(TTecGiFoie_size, sizeof(TTecGiFoie) == 0x13C);

extern "C" const char *TTecGiFoie__name;
#endif
