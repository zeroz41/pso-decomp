#ifndef PSO_OBJECT_WARP_TOBJWARPBOSS_H
#define PSO_OBJECT_WARP_TOBJWARPBOSS_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjWarpBoss : public TObjAreaWarp {
    virtual ~TObjWarpBoss();
    void close_windows();
    void update();
    virtual void debug_print_area_num();
    s32 update_warp_dialogs();
    void update_warp_occupants();
    void update_warp_state();
    void update_state();
    void warp_boss_handle_window();
    void update_floor_switch_state();
    void warp_player(s32);
    void send_cmd_6A(u16);
    s32 are_all_players_in_range();
    s32 sub_8019E418();
    void update_warp_boss_visibility();
    u8 unk_AC[0x4];
    u32 m_b0;
    u32 m_d0;
    u32 m_d4;
    u8 _padD8[0x4];
    s16 m_dc;
    s16 m_de;
    s16 m_e0;
    s16 m_e2;
    u8 _padE4[0x80];
    u32 m_164;
    u32 m_168;
    u32 m_16c;
    u8 _pad170[0x10];
    u32 m_180;
    void update_warp_confirmation();
    void render();
    void run_task();
    u8 unk_168[0x1C];
};

typedef char TObjWarpBoss_size[sizeof(TObjWarpBoss) == 0x184 ? 1 : -1];
#endif
