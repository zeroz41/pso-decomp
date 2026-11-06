#ifndef PSO_UNK_TUNK_80488B08_H
#define PSO_UNK_TUNK_80488B08_H
#include "types.h"
#include "pso/unk/TUnk_80488A28.h"

class TUnk_80488B08 : public TUnk_80488A28 {
public:
    virtual ~TUnk_80488B08();
    virtual void vfunc_6();
    virtual void run_task();
};
typedef char TUnk_80488B08_size[sizeof(TUnk_80488B08) == 0x6C ? 1 : -1];

#endif
