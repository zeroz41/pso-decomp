#ifndef PSO_TECHNIQUE_TTECFOIE_H
#define PSO_TECHNIQUE_TTECFOIE_H

#include "types.h"
#include "pso/effect/TUnk_804CCC68.h"

struct TTecFoie : public TUnk_804CCC68 {
    TTecFoie(s32 source, u8 *pos, u8 *target, s32 level);
    TTecFoie(s32 source, Vec *pos, s32 angle, s32 level);
    virtual ~TTecFoie();
    virtual void vfunc_8(void *);
    virtual void vfunc_6();
    void play_foie_cast_sound();
    void run_task();
    void render();
    void create_particle_emitters();
    void init_projectile_params();
    static void create_ex(void *arg0, void *arg1, void *arg2, void *arg3);
    static void create(void *arg0, void *arg1, void *arg2, void *arg3);
    void **emitters; // the particle emitters of the band, queued for destruction with it
};

LAYOUT_ASSERT(TTecFoie_size, sizeof(TTecFoie) == 0x134);
#endif
