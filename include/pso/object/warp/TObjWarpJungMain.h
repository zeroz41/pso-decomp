#ifndef PSO_OBJECT_WARP_TOBJWARPJUNGMAIN_H
#define PSO_OBJECT_WARP_TOBJWARPJUNGMAIN_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjWarpJungMain : public TObjAreaWarp {
    virtual ~TObjWarpJungMain();
    virtual void vfunc_14();
    virtual void debug_print_area_num();
    virtual void confirm_area_transfer(s32);
    void render();
    void run_task();
    u8 unk_AC[0x4];
    u32 m_b0;
    u8 unk_B4[0x4];
    s16 m_b8;
    u8 unk_BA[0x2];
    s32 m_bc;
    u8 unk_C0[0x4];
    f32 m_c4;
};

typedef char TObjWarpJungMain_size[sizeof(TObjWarpJungMain) == 0xC8 ? 1 : -1];
#endif
