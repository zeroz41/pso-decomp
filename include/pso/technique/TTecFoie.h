#ifndef PSO_TECHNIQUE_TTECFOIE_H
#define PSO_TECHNIQUE_TTECFOIE_H

#include "types.h"
#include "pso/effect/TUnk_804CCC68.h"

struct TTecFoie : public TUnk_804CCC68 {
    virtual ~TTecFoie();
    virtual void vfunc_8(void *);
    virtual void vfunc_6();
    void play_foie_cast_sound();
    void run_task();
    void render();
    u8 *construct_aimed(s32 arg1, u8 *arg2, u8 *arg3, s16 arg4);
    void create_particle_emitters();
    void init_projectile_params();
    static void create_ex(void *arg0, void *arg1, void *arg2, void *arg3);
    static void create(void *arg0, void *arg1, void *arg2, void *arg3);
    u8 unk_130[0x4];
};

typedef char TTecFoie_size[sizeof(TTecFoie) == 0x134 ? 1 : -1];
#endif
