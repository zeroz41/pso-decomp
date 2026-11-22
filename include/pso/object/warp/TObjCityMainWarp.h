#ifndef PSO_OBJECT_WARP_TOBJCITYMAINWARP_H
#define PSO_OBJECT_WARP_TOBJCITYMAINWARP_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjCityMainWarp : public TObjAreaWarp {
    TObjCityMainWarp(TObject *parent, void *set_data);
    virtual ~TObjCityMainWarp();
    virtual void vfunc_14();
    virtual void open_confirm_window(s32 client_id);
    virtual s32 is_warp_enabled();
    virtual s32 vfunc_17();
    virtual s32 vfunc_18(s32);
    virtual void debug_print_area_num();
    void run_task();
    static void update_unlock_flags();
    static void set_active_bit(s32 _w0);
    static void reset();
    static s32 get_phase_flag();
    static void notify_player_warp(void *arg0, s32 local_client_id);
    void update_floor_switch_state();
    void update_state();
    void render();
    void *create();
    static void clear_active_bit(s32 floor);
    static void update_warp_flags_from_story();
    static void init_visible_mask();
    static s32 get_floor_warp_bit(s32 floor);
    // Adds a text entry to the trade window `p` (TWindowSubTradeMain::add_text_entry with -1).
    static int forward_trade_action_default(void *p, int a1, int a2, int a3);
    f32 m_c4;
    // Destination index of each menu entry, built by open_confirm_window from the visible
    // destination mask and read back by vfunc_17 (inferred). Offline / lobby menus keep
    // their own list.
    s32 menu_destinations[17];
    s32 lobby_menu_destinations[17];
    // set_params[1] clamped to 0-2; debug_print_area_num prints it as "SELECT TYPE NORMAL",
    // "SELECT TYPE VR" or "SELECT TYPE CTRL CENTER".
    s32 select_type;
};

LAYOUT_ASSERT(TObjCityMainWarp_size, sizeof(TObjCityMainWarp) == 0x154);
#endif
