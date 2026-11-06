#ifndef PSO_UNK_TUNK_80488D70_H
#define PSO_UNK_TUNK_80488D70_H
#include "types.h"
#include "pso/unk/TUnk_80488A28.h"

class TUnk_80488D70 : public TUnk_80488A28 {
public:
    virtual ~TUnk_80488D70();
    virtual void run_task();
    virtual void vfunc_6();
    void *init_subobject();
};
typedef char TUnk_80488D70_size[sizeof(TUnk_80488D70) == 0x6C ? 1 : -1];

#endif
