#ifndef PSO_OBJECT_WARP_TOBJAREAWARPFOREST_H
#define PSO_OBJECT_WARP_TOBJAREAWARPFOREST_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjAreaWarpForest : public TObjAreaWarp {
    TObjAreaWarpForest(TObject *parent, void *set_data);
    virtual ~TObjAreaWarpForest();
    virtual void confirm_area_transfer(s32);
    virtual void debug_print_area_num();
    void render();
    void run_task();
    void *alloc_and_init();
    f32 m_c4;
    u8 unk_C8[0x14];
};

typedef char TObjAreaWarpForest_size[sizeof(TObjAreaWarpForest) == 0xDC ? 1 : -1];
#endif
