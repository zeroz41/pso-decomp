#ifndef PSO_MISC_TWINDOWUSERSORT_H
#define PSO_MISC_TWINDOWUSERSORT_H

#include "types.h"
#include "pso/misc/TWindowBase.h"

struct TWindowUserSort : public TWindowBase {
    virtual ~TWindowUserSort();
    virtual void render();
    u8 _pad1C[0x8];
    void* m_24;
    u8 _pad28[0x38];
    u32 m_60;
    virtual void run_task();
};

typedef char TWindowUserSort_size[sizeof(TWindowUserSort) == 0x64 ? 1 : -1];
#endif
