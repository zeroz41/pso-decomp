#ifndef PSO_TECHNIQUE_TTECGIZONDE_H
#define PSO_TECHNIQUE_TTECGIZONDE_H

#include "types.h"
#include "pso/effect/TUnk_804CCC68.h"

struct TTecGiZonde : public TUnk_804CCC68 {
    TTecGiZonde(saddr source, Vec *pos, void *targets, s32 level);
    virtual ~TTecGiZonde();
    virtual void vfunc_8(void *);
    s32 find_chain_targets();
    void create(void *arg1, void *arg2, void *arg3);
    void run_task();
    void init_parameters();
    u8 targetList[0x5C]; // copy_technique_target_list fills it from the list create() is handed
    void deliver_chain_hits();
};

LAYOUT_ASSERT(TTecGiZonde_size, sizeof(TTecGiZonde) == 0x18C);
#endif
