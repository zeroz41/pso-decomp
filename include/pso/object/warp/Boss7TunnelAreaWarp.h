#ifndef PSO_OBJECT_WARP_BOSS7TUNNELAREAWARP_H
#define PSO_OBJECT_WARP_BOSS7TUNNELAREAWARP_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarpForest.h"

// A forest area warp that stays hidden until the Boss7 tunnel (TObjBoss7Tunnel::has_stopped) has stopped.
struct Boss7TunnelAreaWarp : public TObjAreaWarpForest {
    Boss7TunnelAreaWarp(TObject *parent, void *set_data);
    static void *create(void *set_data);
    virtual ~Boss7TunnelAreaWarp();
    virtual void run_task();
    virtual void render();
    s32 visible; // set once TObjBoss7Tunnel::has_stopped passes; render is skipped until then
};

LAYOUT_ASSERT(Boss7TunnelAreaWarp_size, sizeof(Boss7TunnelAreaWarp) == 0xE0);
#endif
