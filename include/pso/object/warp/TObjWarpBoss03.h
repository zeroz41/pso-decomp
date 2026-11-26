#ifndef PSO_OBJECT_WARP_TOBJWARPBOSS03_H
#define PSO_OBJECT_WARP_TOBJWARPBOSS03_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjWarpBoss03 : public TObjAreaWarp {
    TObjWarpBoss03(TObject *parent, void *set_data);
    virtual ~TObjWarpBoss03();
    virtual void debug_print_area_num();
    void draw_debug_range();
    void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjWarpBoss03_size, sizeof(TObjWarpBoss03) == 0xC4);
#endif
