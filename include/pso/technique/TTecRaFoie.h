#ifndef PSO_TECHNIQUE_TTECRAFOIE_H
#define PSO_TECHNIQUE_TTECRAFOIE_H

#include "types.h"
#include "pso/technique/TTecCircle.h"
#include "pso/player/TargetCursorList.h"


struct TTecRaFoie : public TTecCircle {
    virtual void vfunc_9();
    virtual void vfunc_8(void *);
    virtual void vfunc_6(void *);
    virtual ~TTecRaFoie();
    virtual void run_task();
    TTecRaFoie(saddr source, Vec *origin, Vec *pos, s32 level);
    TTecRaFoie(saddr source, Vec *origin, TargetCursorList *list, s32 level);
    TargetCursorList m_targets;  // the targets the list constructor copies
    s32 m_148;              // 1: bursts where it was cast (the Vec constructor), 0: on its first target
    void calc_area_parameters();
    virtual void render();
    void update_detonation(void *arg1);
    static void create(TObject *source, Vec *origin, Vec *pos, s32 level);
    static void create_ex(void *source, void *origin, void *targets, s32 level);
};

LAYOUT_ASSERT(TTecRaFoie_size, sizeof(TTecRaFoie) == 0x14C);
#endif
