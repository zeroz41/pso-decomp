#ifndef PSO_OBJECT_WARP_TOBJMAPWARPANCIENT_H
#define PSO_OBJECT_WARP_TOBJMAPWARPANCIENT_H

#include "types.h"
#include "pso/object/warp/TObjMapWarp.h"

struct TObjMapWarpAncient : public TObjMapWarp {
    virtual ~TObjMapWarpAncient();
    virtual void slot4C();
    u8 unk_FC[0x4];
    u32 m_100;
    u32 m_104;
    u32 m_108;
    u32 m_10c;
    u32 m_110;
    u32 m_114;
    u32 m_118;
    virtual void render();
    virtual void run_task();
    static void free_globals();
};

typedef char TObjMapWarpAncient_size[sizeof(TObjMapWarpAncient) == 0x11C ? 1 : -1];
#endif
