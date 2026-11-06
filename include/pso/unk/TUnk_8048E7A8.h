#ifndef PSO_UNK_TUNK_8048E7A8_H
#define PSO_UNK_TUNK_8048E7A8_H
#include "types.h"
#include "pso/unk/TUnk_8048E728.h"

class TUnk_8048E7A8 : public TUnk_8048E728 {
public:
    virtual ~TUnk_8048E7A8();
    virtual void run_task();
    void check_radial_particle_retire();
    virtual void render();
    u8 unk_C0[0x4];
};

#endif
