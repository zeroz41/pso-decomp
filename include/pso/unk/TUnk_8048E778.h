#ifndef PSO_UNK_TUNK_8048E778_H
#define PSO_UNK_TUNK_8048E778_H
#include "types.h"
#include "pso/unk/TUnk_8048E728.h"

class TUnk_8048E778 : public TUnk_8048E728 {
public:
    virtual ~TUnk_8048E778();
    virtual void run_task();
    void *init_particle_random_spread(void *, void *, void *);
    void retire_ballistic_particle_if_done();
    void draw_sprite_quad(s32);
    virtual void render();
    u8 unk_C0[0x10];
};

#endif
