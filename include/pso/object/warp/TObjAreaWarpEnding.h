#ifndef PSO_OBJECT_WARP_TOBJAREAWARPENDING_H
#define PSO_OBJECT_WARP_TOBJAREAWARPENDING_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjAreaWarpEnding : public TObjAreaWarp {
    TObjAreaWarpEnding(TObject *parent, void *set_data);
    virtual ~TObjAreaWarpEnding();
    virtual void debug_print_area_num();
    virtual void confirm_area_transfer(s32);
    void open_confirm_window(s16 arg1);
    void render();
    void run_task();
    f32 m_c4;
    u8 unk_C8[0x14];
};

typedef char TObjAreaWarpEnding_size[sizeof(TObjAreaWarpEnding) == 0xDC ? 1 : -1];
#endif
