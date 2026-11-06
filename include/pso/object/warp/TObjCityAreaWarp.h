#ifndef PSO_OBJECT_WARP_TOBJCITYAREAWARP_H
#define PSO_OBJECT_WARP_TOBJCITYAREAWARP_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjCityAreaWarp : public TObjAreaWarp {
    virtual ~TObjCityAreaWarp();
    virtual void debug_print_area_num();
    virtual void confirm_area_transfer(s32);
    void render();
    void do_warp();
    void run_task();
    static void *create(void *arg0);
    u8 unk_AC[0x4];
    u32 m_b0;
    u8 unk_B4[0x4];
    s16 m_b8;
    u8 unk_BA[0x2];
    u32 m_bc;
    u8 unk_C0[0x4];
    f32 m_c4;
};

typedef char TObjCityAreaWarp_size[sizeof(TObjCityAreaWarp) == 0xC8 ? 1 : -1];
#endif
