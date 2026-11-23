#ifndef PSO_UNK_TUNK_8048E7A8_H
#define PSO_UNK_TUNK_8048E7A8_H
#include "types.h"
#include "pso/unk/TUnk_8048E728.h"

class TUnk_8048E7A8 : public TUnk_8048E728 {
public:
    TUnk_8048E7A8(ParticleParam *entry, Vec *position, TObject *parent, u16 particle_flags, u16 target);
    TUnk_8048E7A8(void *param, void *pos, void *parent);
    virtual ~TUnk_8048E7A8();
    virtual void run_task();
    void check_radial_particle_retire();
    virtual void render();
};

#endif
