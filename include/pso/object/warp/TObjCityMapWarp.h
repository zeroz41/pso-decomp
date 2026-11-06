#ifndef PSO_OBJECT_WARP_TOBJCITYMAPWARP_H
#define PSO_OBJECT_WARP_TOBJCITYMAPWARP_H

#include "types.h"
#include "pso/object/warp/TObjMapWarp.h"

struct TObjCityMapWarp : public TObjMapWarp {
    virtual ~TObjCityMapWarp();
    virtual void slot4C();
    virtual void render();
    virtual void run_task();
    int is_field88_zero();
    void clamp_destination_index();
    static void *create(void *arg0);
    u8 unk_FC[0x4];
};

typedef char TObjCityMapWarp_size[sizeof(TObjCityMapWarp) == 0x100 ? 1 : -1];
#endif
