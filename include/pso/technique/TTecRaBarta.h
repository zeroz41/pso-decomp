#ifndef PSO_TECHNIQUE_TTECRABARTA_H
#define PSO_TECHNIQUE_TTECRABARTA_H

#include "types.h"
#include "pso/technique/TTecCircle.h"

struct TTecRaBarta : public TTecCircle {
    TTecRaBarta(saddr source, Vec *origin, Vec *pos, s32 level);
    TTecRaBarta(saddr source, Vec *origin, s32 level);
    virtual ~TTecRaBarta();
    virtual void vfunc_6(void *);
    virtual void vfunc_9();
    virtual void vfunc_8(void *);
    void calc_parameters();
    u32 m_ec;
    u32 m_f0;
    u32 m_f4;
    u16 hit_ids[32];  // entity ids vfunc_6 has already hit
    u32 m_138;
    static void create(void *source, void *origin, void *pos, s32 level);
    static void create(void *source, void *origin, s32 level);
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TTecRaBarta_size, sizeof(TTecRaBarta) == 0x13C);
#endif
