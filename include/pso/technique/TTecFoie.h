#ifndef PSO_TECHNIQUE_TTECFOIE_H
#define PSO_TECHNIQUE_TTECFOIE_H

#include "types.h"
#include "pso/technique/TTecShot.h"
#include "pso/technique/TechniqueEmitterTable.h"

struct TTecFoie : public TTecShot {
    static const char *name;
    static const TechniqueEmitterSourceTable emitter_bands[6];
    TTecFoie(saddr source, u8 *pos, u8 *target, s32 level);
    TTecFoie(saddr source, Vec *pos, s32 angle, s32 level);
    virtual ~TTecFoie();
    virtual void apply_to_target(TObjChara *);
    virtual void vfunc_6();
    void play_foie_cast_sound();
    void run_task();
    void render();
    void create_particle_emitters();
    void init_projectile_params();
    static void create_ex(void *source, void *origin, void *aim, s32 level);
    static void create(void *source, void *origin, s32 angle, s32 level);
    void **emitters; // the particle emitters of the band, queued for destruction with it
};

LAYOUT_ASSERT(TTecFoie_size, sizeof(TTecFoie) == 0x134);
#endif
