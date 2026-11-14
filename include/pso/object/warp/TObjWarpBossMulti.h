#ifndef PSO_OBJECT_WARP_TOBJWARPBOSSMULTI_H
#define PSO_OBJECT_WARP_TOBJWARPBOSSMULTI_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjWarpBossMulti : public TObjAreaWarp {
    TObjWarpBossMulti(TObject *parent, void *set_data);
    virtual ~TObjWarpBossMulti();
    virtual void debug_print_area_num();
    void render();
    void run_task();
    u32 m_e0;
    u32 m_e4;
    u32 m_e8;
    u32 m_ec;
    u32 m_f0;
    u32 m_f4;
    void *create();
    void init_warp_params();
    void update();
    static s32 is_lobby_active();
    static s32 get_boss_warp_flag();
    static void notify_player(void *arg0, s32 arg1);
    u8 unk_DC[0x1C];
    f32 m_f8;
    u8 unk_FC[0x4];
    static int is_flag_clear(void* p);
};

typedef char TObjWarpBossMulti_size[sizeof(TObjWarpBossMulti) == 0x100 ? 1 : -1];
#endif
