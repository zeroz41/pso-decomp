#ifndef PSO_OBJECT_WARP_TOBJWARPBOSS03_H
#define PSO_OBJECT_WARP_TOBJWARPBOSS03_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjWarpBoss03 : public TObjAreaWarp {
    virtual ~TObjWarpBoss03();
    virtual void debug_print_area_num();
    void sub_8019F9E4();
    void run_task();
    static void *create(void *arg0);
    u8 unk_AC[0x18];
};

typedef char TObjWarpBoss03_size[sizeof(TObjWarpBoss03) == 0xC4 ? 1 : -1];
#endif
