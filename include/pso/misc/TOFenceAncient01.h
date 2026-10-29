#ifndef PSO_MISC_TOFENCEANCIENT01_H
#define PSO_MISC_TOFENCEANCIENT01_H

#include "types.h"
#include "pso/player/TUnk_804B1B80.h"

struct TOFenceAncient01 : public TUnk_804B1B80 {
    virtual ~TOFenceAncient01();
    virtual void open();
    virtual void close();
    virtual void update_demo();
    static void *create(void *arg0);
    static void free_resources();
    static void load_resources();
};

typedef char TOFenceAncient01_size[sizeof(TOFenceAncient01) == 0xD8 ? 1 : -1];
#endif
