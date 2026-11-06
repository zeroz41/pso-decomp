#ifndef PSO_OBJECT_WARP_TOBJAREAWARPQUEST_H
#define PSO_OBJECT_WARP_TOBJAREAWARPQUEST_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjAreaWarpQuest : public TObjAreaWarp {
    virtual ~TObjAreaWarpQuest();
    virtual void debug_print_area_num();
    u8 _padC8[0x4];
    u32 m_cc;
    u32 m_d0;
    u32 m_d4;
    u32 m_d8;
    u32 m_dc;
    void render();
    void run_task();
    s32 get_dest_area();
    u8 unk_C4[0x1C];
};

typedef char TObjAreaWarpQuest_size[sizeof(TObjAreaWarpQuest) == 0xE0 ? 1 : -1];
#endif
