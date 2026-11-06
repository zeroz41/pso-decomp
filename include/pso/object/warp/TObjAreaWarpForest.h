#ifndef PSO_OBJECT_WARP_TOBJAREAWARPFOREST_H
#define PSO_OBJECT_WARP_TOBJAREAWARPFOREST_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjAreaWarpForest : public TObjAreaWarp {
    virtual ~TObjAreaWarpForest();
    virtual void confirm_area_transfer(s32);
    virtual void debug_print_area_num();
    u32 m_c8;
    u32 m_cc;
    u32 m_d0;
    u32 m_d4;
    u32 m_d8;
    void render();
    void run_task();
    void render_if_active();
    void *init(void *, void *);
    void *alloc_and_init();
    u8 unk_C0[0x4];
    f32 m_c4;
    u8 unk_C8[0x14];
};

typedef char TObjAreaWarpForest_size[sizeof(TObjAreaWarpForest) == 0xDC ? 1 : -1];
#endif
