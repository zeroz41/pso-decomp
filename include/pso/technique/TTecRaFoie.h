#ifndef PSO_TECHNIQUE_TTECRAFOIE_H
#define PSO_TECHNIQUE_TTECRAFOIE_H

#include "types.h"
#include "pso/technique/TTecCircle.h"
#include "pso/player/TargetCursorList.h"


struct TTecRaFoie : public TTecCircle {
    virtual void play_cast_sound();
    virtual void spawn_effects(Vec *pos);
    virtual void apply_to_target(TObjChara *);
    virtual ~TTecRaFoie();
    virtual void run_task();
    TTecRaFoie(TObjBase *source, Vec *origin, Vec *pos, s32 level);
    TTecRaFoie(TObjBase *source, Vec *origin, TargetCursorList *list, s32 level);
    TargetCursorList m_targets;  // the targets the list constructor copies
    s32 m_148;              // 1: bursts where it was cast (the Vec constructor), 0: on its first target
    void calc_area_parameters();
    virtual void render();
    void update_detonation(Vec *pos);
    static void create(TObjBase *source, Vec *origin, Vec *pos, s32 level);
    static void create_ex(TObjBase *source, Vec *origin, TargetCursorList *targets, s32 level);
};

LAYOUT_ASSERT(TTecRaFoie_size, sizeof(TTecRaFoie) == 0x14C);
#endif
