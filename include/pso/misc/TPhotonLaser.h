#ifndef PSO_MISC_TPHOTONLASER_H
#define PSO_MISC_TPHOTONLASER_H

#include "types.h"
#include "pso/player/TObjChara.h"

struct TPhotonLaser : public TObjChara {
    virtual ~TPhotonLaser();
    virtual void run_task();
    void* m_334;
    u8 _pad338[0x8];
    void* m_340;
    u8 _pad344[0x8];
    void* m_34c;
    u8 _pad350[0x14];
    u32 m_364;
    u8 _pad368[0x4];
    u32 m_36c;
    u16 m_370;
    virtual void render();
    u8 unk_372[0xE];
};

typedef char TPhotonLaser_size[sizeof(TPhotonLaser) == 0x380 ? 1 : -1];
#endif
