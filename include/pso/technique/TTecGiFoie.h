#ifndef PSO_TECHNIQUE_TTECGIFOIE_H
#define PSO_TECHNIQUE_TTECGIFOIE_H

#include "types.h"
#include "pso/technique/TTecCircle.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

// One flame of Gifoie, a task TTecGiFoie creates per orbit (vtable lbl_804CC800).
// Nothing names the class or its fields; the comments are readings of the code.
class TTecGiFoieFlame : public TObject {
public:
    TTecGiFoieFlame(Vec *pos, s32 angle, s32 band, s32 level, TObject *parent, u8 single);
    virtual ~TTecGiFoieFlame();
    virtual void run_task();

    TParticleCtrl **particles; // one particle per entry of the band's profile, or a single one
    Vec center;             // centre of the orbit
    Vec pos;             // current position
    f32 radius;             // distance from the centre
    s32 angle;             // angle on the orbit
    s32 frames;             // frames run
    u8 band;              // level band, 0..5
    s8 level;              // technique level
    u8 planar;              // nonzero: circles in the plane facing yaw
    u8 single;              // nonzero: one continuous particle
    s32 yaw;             // yaw
};

LAYOUT_ASSERT(TTecGiFoieFlame_size, sizeof(TTecGiFoieFlame) == 0x4C);

struct TTecGiFoie : public TTecCircle {
    TTecGiFoie(saddr source, Vec *origin, s32 level);
    virtual ~TTecGiFoie();
    virtual void apply_to_target(TObjChara *);
    virtual void run_task();
    TTecGiFoieFlame *orbits[3];  // one flame per orbit, orbit_counts[band] of them
    u16 hitIds[32];            // entity ids apply_to_target has already hit
    s32 hitCursor;
    void calc_params();
    static void create(void *source, void *origin, s32 level);
    virtual void render();
};

LAYOUT_ASSERT(TTecGiFoie_size, sizeof(TTecGiFoie) == 0x13C);

extern const char *TTecGiFoie__name;
#endif
