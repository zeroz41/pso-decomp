#ifndef PSO_OBJECT_WARP_TOBJAREAWARPENDING_H
#define PSO_OBJECT_WARP_TOBJAREAWARPENDING_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjAreaWarpEnding : public TObjAreaWarp {
    virtual ~TObjAreaWarpEnding();
    virtual void debug_print_area_num();
    virtual void confirm_area_transfer(s32);
    u32 m_c8;
    u32 m_cc;
    u32 m_d0;
    u32 m_d4;
    u32 m_d8;
    void open_confirm_window(s16 arg1);
    void render();
    void run_task();
    u8 unk_C0[0x4];
    f32 m_c4;
    u8 unk_C8[0x14];
};

typedef char TObjAreaWarpEnding_size[sizeof(TObjAreaWarpEnding) == 0xDC ? 1 : -1];
#endif
