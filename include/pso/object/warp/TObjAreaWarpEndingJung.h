#ifndef PSO_OBJECT_WARP_TOBJAREAWARPENDINGJUNG_H
#define PSO_OBJECT_WARP_TOBJAREAWARPENDINGJUNG_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarpEnding.h"

struct TObjAreaWarpEndingJung : public TObjAreaWarpEnding {
    static const char *class_name;
    TObjAreaWarpEndingJung(TObject *parent, void *set_data);
    virtual ~TObjAreaWarpEndingJung();
    virtual void debug_print_area_num();
    void render();
    void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjAreaWarpEndingJung_size, sizeof(TObjAreaWarpEndingJung) == 0xDC);
#endif
