#ifndef PSO_OBJECT_WARP_TOBJAREAWARPENDINGJUNG_H
#define PSO_OBJECT_WARP_TOBJAREAWARPENDINGJUNG_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarpEnding.h"

struct TObjAreaWarpEndingJung : public TObjAreaWarpEnding {
    virtual ~TObjAreaWarpEndingJung();
    virtual void debug_print_area_num();
    void render();
    void run_task();
};

typedef char TObjAreaWarpEndingJung_size[sizeof(TObjAreaWarpEndingJung) == 0xDC ? 1 : -1];
#endif
