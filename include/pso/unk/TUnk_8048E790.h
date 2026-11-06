#ifndef PSO_UNK_TUNK_8048E790_H
#define PSO_UNK_TUNK_8048E790_H
#include "types.h"
#include "pso/unk/TUnk_8048E728.h"

class TUnk_8048E790 : public TUnk_8048E728 {
public:
    virtual ~TUnk_8048E790();
    virtual void run_task();
    void *init_random_particle(void *, void *, void *, void *);
    void retire_orbit_particle();
    virtual void render();
    u8 unk_C0[0x1C];
    s32 m_dc;
};

#endif
