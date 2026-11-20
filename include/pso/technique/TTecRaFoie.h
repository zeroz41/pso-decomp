#ifndef PSO_TECHNIQUE_TTECRAFOIE_H
#define PSO_TECHNIQUE_TTECRAFOIE_H

#include "types.h"
#include "pso/effect/TUnk_804CC148.h"

struct TargetCursorList;

struct TTecRaFoie : public TUnk_804CC148 {
    // Declared in definition order: the first (key) virtual must be defined before
    // TUnk_804CCB28's so that its vtable follows TUnk_804CCB28's in .data (0x804CCB40).
    virtual void vfunc_9();
    virtual void vfunc_8(void *);
    virtual void vfunc_6(void *);
    virtual ~TTecRaFoie();
    virtual void run_task();
    TTecRaFoie(s32 source, Vec *origin, Vec *pos, s32 level);
    TTecRaFoie(s32 source, Vec *origin, TargetCursorList *list, s32 level);
    u8 m_ec[0x5C];  // a TargetCursorList: the targets the list constructor copies
    s32 m_148;              // 1: bursts where it was cast (the Vec constructor), 0: on its first target
    void calc_area_parameters();
    virtual void render();
    void update_detonation(void *arg1);
    void create(void *origin, void *pos, void *level);
    void create_ex(void *origin, void *targets, void *level);
};

typedef char TTecRaFoie_size[sizeof(TTecRaFoie) == 0x14C ? 1 : -1];
#endif
