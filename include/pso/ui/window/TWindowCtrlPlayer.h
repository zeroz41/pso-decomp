#ifndef PSO_UI_WINDOW_TWINDOWCTRLPLAYER_H
#define PSO_UI_WINDOW_TWINDOWCTRLPLAYER_H

#include <stddef.h>
#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowActionPalette;
struct TWindowLockOn;
struct TWindowMainMenu;
struct TWindowMessageInfomation;
struct TWindowShortListCtrl;
struct TWindowSimpleStatus;

// One player's HUD windows: main menu, message log, status, action palette, lock-on and short list.
struct TWindowCtrlPlayer : public TObject {
    TWindowCtrlPlayer(TObject *parent, s32 client_id);
    virtual ~TWindowCtrlPlayer();
    void update_open_sequence();
    void run_all_updates();
    void update_trade_window_visibility();
    void update_child_window_visibility();
    void update_target_info_window();
    void update_main_menu_request();
    void show_active_window();
    void update_short_list_request();
    void update_countdown();
    s32 is_main_menu_open();
    s32 is_log_active();
    void append_message_line(const char *text, s32 mode);
    void spawn_palette_slot_light(s32 kind);
    void replace_submenu(s16 id);
    void try_open_battle_menu(s16 key);
    s32 is_countdown_done();
    void start_countdown();
    s32 is_main_menu_locked();
    void lock_main_menu();
    void unlock_main_menu();
    void disable_main_menu();
    void enable_main_menu();
    void hide_lock_on_window();
    void show_lock_on_window();
    void begin_keyboard_hold();
    void end_keyboard_hold();
    void hide_status_window();
    void show_status_window();
    void suppress();
    void unsuppress();
    s32 has_short_list();
    s32 is_main_menu_disabled();
    s32 is_lock_on_window_hidden();
    s32 is_keyboard_held();
    s32 is_status_window_hidden();
    s32 is_suppressed();
    u16 flags;
    s16 open_timer;
    s16 countdown;
    u8 _pad22[0x2];
    s32 client_id;
    TWindowMainMenu *main_menu;
    TWindowMessageInfomation *message_information;
    TWindowSimpleStatus *simple_status;
    TWindowActionPalette *action_palette;
    TWindowLockOn *lock_on_window;
    TWindowShortListCtrl *short_list;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowCtrlPlayer_flags_offset, offsetof(TWindowCtrlPlayer, flags) == 0x1C);
LAYOUT_ASSERT(TWindowCtrlPlayer_status_offset, offsetof(TWindowCtrlPlayer, simple_status) == 0x30);
LAYOUT_ASSERT(TWindowCtrlPlayer_lock_on_offset, offsetof(TWindowCtrlPlayer, lock_on_window) == 0x38);
LAYOUT_ASSERT(TWindowCtrlPlayer_menu_offset, offsetof(TWindowCtrlPlayer, main_menu) == 0x28);
LAYOUT_ASSERT(TWindowCtrlPlayer_information_offset, offsetof(TWindowCtrlPlayer, message_information) == 0x2C);
LAYOUT_ASSERT(TWindowCtrlPlayer_action_palette_offset, offsetof(TWindowCtrlPlayer, action_palette) == 0x34);
LAYOUT_ASSERT(TWindowCtrlPlayer_short_list_offset, offsetof(TWindowCtrlPlayer, short_list) == 0x3C);
LAYOUT_ASSERT(TWindowCtrlPlayer_size, sizeof(TWindowCtrlPlayer) == 0x40);

#endif
