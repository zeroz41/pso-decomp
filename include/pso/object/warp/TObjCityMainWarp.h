#ifndef PSO_OBJECT_WARP_TOBJCITYMAINWARP_H
#define PSO_OBJECT_WARP_TOBJCITYMAINWARP_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjCityMainWarp : public TObjAreaWarp {
    static const char *class_name;
    TObjCityMainWarp(TObject *parent, void *set_data);
    virtual ~TObjCityMainWarp();
    virtual void close_menu();
    virtual void open_confirm_window(s32 client_id);
    virtual s32 is_warp_enabled();
    virtual s32 is_choice_confirmed();
    virtual s32 is_choice_confirmed_by(s32);
    virtual void debug_print_area_num();
    void run_task();
    static void update_unlock_flags();
    static void set_active_bit(s32 floor);
    static void reset();
    static s32 get_phase_flag();
    static void notify_player_warp(void *arg0, s32 local_client_id);
    void update_floor_switch_state();
    void update_state();
    void render();
    static void *create(void *set_data);
    static void clear_active_bit(s32 floor);
    static void update_warp_flags_from_story();
    static void init_visible_mask();
    static s32 get_floor_warp_bit(s32 floor);
    f32 frame;
    // Destination index of each menu entry, built by open_confirm_window from the visible
    // destination mask and read back by is_choice_confirmed (inferred). Offline / lobby menus keep
    // their own list.
    s32 menu_destinations[17];
    s32 lobby_menu_destinations[17];
    // set_params[1] clamped to 0-2; debug_print_area_num prints it as "SELECT TYPE NORMAL",
    // "SELECT TYPE VR" or "SELECT TYPE CTRL CENTER".
    s32 select_type;
};

LAYOUT_ASSERT(TObjCityMainWarp_size, sizeof(TObjCityMainWarp) == 0x154);
#endif
