#ifndef PSO_TECHNIQUE_TTECGIZONDE_H
#define PSO_TECHNIQUE_TTECGIZONDE_H

#include "types.h"
#include "pso/effect/TUnk_804CCC68.h"
#include "pso/player/TargetCursorList.h"

struct TTecGiZonde : public TUnk_804CCC68 {
    TTecGiZonde(s32 source, Vec *pos, void *targets, s32 level);
    virtual ~TTecGiZonde();
    virtual void vfunc_8(void *);
    s32 find_chain_targets();
    static void create(void *caster, Vec *pos, void *targets, s32 level);
    void run_task();
    void init_parameters();
    TargetCursorList targetList; // copy_technique_target_list fills it from the list create() is handed
    void deliver_chain_hits();
};

typedef char TTecGiZonde_size[sizeof(TTecGiZonde) == 0x18C ? 1 : -1];
#endif
