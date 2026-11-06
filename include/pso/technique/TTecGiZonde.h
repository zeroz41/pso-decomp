#ifndef PSO_TECHNIQUE_TTECGIZONDE_H
#define PSO_TECHNIQUE_TTECGIZONDE_H

#include "types.h"
#include "pso/effect/TUnk_804CCC68.h"

struct TTecGiZonde : public TUnk_804CCC68 {
    virtual ~TTecGiZonde();
    virtual void vfunc_8(void *);
    s32 find_chain_targets();
    void create(void *arg1, void *arg2, void *arg3);
    void run_task();
    void init_parameters();
    u8 unk_130[0x5C];
    void deliver_chain_hits();
};

typedef char TTecGiZonde_size[sizeof(TTecGiZonde) == 0x18C ? 1 : -1];
#endif
