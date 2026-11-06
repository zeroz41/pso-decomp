#ifndef PSO_OBJECT_WARP_TOBJMAPFORCEWARP_H
#define PSO_OBJECT_WARP_TOBJMAPFORCEWARP_H

#include "types.h"
#include "pso/object/warp/TObjMapWarp.h"

struct TObjMapForceWarp : public TObjMapWarp {
    virtual ~TObjMapForceWarp();
    virtual void run_task();
    void create_warp_id_string(void *);
    virtual void slot3C();
    u32 m_fc;
    virtual void render();
    static void register_warp(void* a0);
};

typedef char TObjMapForceWarp_size[sizeof(TObjMapForceWarp) == 0x100 ? 1 : -1];
#endif
