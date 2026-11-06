#ifndef PSO_OBJECT_WARP_TOBJGOALWARPANCIENT_H
#define PSO_OBJECT_WARP_TOBJGOALWARPANCIENT_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjGoalWarpAncient : public TObjAreaWarp {
    virtual ~TObjGoalWarpAncient();
    virtual void debug_print_area_num();
    void render();
    void run_task();
    u8 unk_AC[0x4];
    u32 m_cc;
    u32 m_d0;
    u32 m_d4;
    u32 m_d8;
    u32 m_dc;
    u32 m_e0;
    u32 m_e4;
    u32 m_e8;
    static void load_resources();
    static void register_warp_object(void* a0);
    static s32 get_instance();
    static void register_warp(void* a0);
    u8 unk_D0[0x1C];
};

typedef char TObjGoalWarpAncient_size[sizeof(TObjGoalWarpAncient) == 0xEC ? 1 : -1];
#endif
