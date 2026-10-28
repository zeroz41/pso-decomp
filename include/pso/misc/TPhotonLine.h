#ifndef PSO_MISC_TPHOTONLINE_H
#define PSO_MISC_TPHOTONLINE_H

#include "types.h"
#include "pso/player/TObjChara.h"

struct TPhotonLine : public TObjChara {
    virtual ~TPhotonLine();
    virtual void run_task();
    void* m_334;
    u8 _pad338[0x18];
    u32 m_350;
    u8 _pad354[0x14];
    u16 m_368;
    virtual void render();
    u8 unk_36A[0xE];
};

typedef char TPhotonLine_size[sizeof(TPhotonLine) == 0x378 ? 1 : -1];
#endif
