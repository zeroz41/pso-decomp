#ifndef PSO_OBJECT_TOBJCITYMAINWARP_H
#define PSO_OBJECT_TOBJCITYMAINWARP_H

#include "types.h"
#include "pso/object/TObjAreaWarp.h"

struct TObjCityMainWarp : public TObjAreaWarp {
    virtual ~TObjCityMainWarp();
    virtual void vfunc_14();
    virtual u8 is_warp_enabled();
    virtual void vfunc_18(s32);
    virtual void debug_print_area_num();
    void run_task();
    u8 unk_AC[0x4];
    u32 m_b0;
    u8 unk_B4[0x10];
    f32 m_c4;
    u8 unk_C8[0x8];
    s32 m_d0;
    u8 unk_D4[0xC];
    s16 m_e0;
    u8 unk_E2[0x52];
    u32 m_150;
    static void update_unlock_flags();
    static void set_active_bit(s32 _w0);
    static void reset();
    static s32 get_phase_flag();
    s32 find_local_player_in_range(f32 farg0);
    static void notify_player_warp(void *arg0, s32 arg1);
    void update_floor_switch_state();
    void update_state();
    void update_warp_sequence();
    void render();
    void *create();
    static void clear_active_bit();
    void update_warp_flags_from_story();
    void init_visible_mask();
    u8 unk_138[0x1C];
    static s32 get_floor_warp_bit(s32 floor);
};

typedef char TObjCityMainWarp_size[sizeof(TObjCityMainWarp) == 0x154 ? 1 : -1];
#endif
