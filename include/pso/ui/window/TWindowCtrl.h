#ifndef PSO_UI_WINDOW_TWINDOWCTRL_H
#define PSO_UI_WINDOW_TWINDOWCTRL_H

#include "types.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/ui/window/WindowCtrlCallback.h"

struct TWindowTradeRequest;
struct TWindowTimer;
class TWindowArea;
struct TWindowMessageLog;
struct TWindowSimpleStatus;

struct TWindowGetComCard;

class TWindowFukidasi;

struct TWindowCtrl : public TObject {
    TWindowCtrl(TObject *parent);
    virtual ~TWindowCtrl();
    static TWindowCtrl *instance;
    u16 flags;
    u16 m_1e;
    s16 countdown;
    s16 submit_cooldown;
    u32 m_24;
    u16 window_id;
    u8 _pad2A[0x2];
    uaddr m_2c;
    TWindowTimer *m_30;
    TWindowArea *m_34;
    uaddr m_38;
    TWindowGetComCard *m_3c;
    TWindowTradeRequest *trade_request;
    TWindowMessageLog *message_log;
    u8 unk_48[0x8];
    s32 m_50;
    u8 unk_54[0x1D];
    u8 m_71;
    u8 unk_72[0x4];
    u16 m_76;
    TWindowSimpleStatus *simple_status[3];
    TWindowFukidasi *balloons[4];
    void* m_94;
    virtual void run_task();
    virtual void render();
    static s32 get_flag_bit3();
    static s32 is_map_visible();
    static void clear_flag_2();
    static void set_close_flag();
    static s32 get_field24();
    static s32 get_flag_bit0();
    static void clear_flag();
    static void call_window_method_with_default_vec(s32 client);
    static void set_field22();
    static bool is_submit_cooldown_clear();
    static void update_focused();
    static s32 get_active_sub();
    static void open_status_111();
    static void open_status_112();
    static void close_active_window();
    static void ensure_initialized();
    static void create_timer();
    static void set_timer_window_time(u32 secs);
    static void close_timer_window();
    static void create_alt_timer();
    static char *skip_name_prefix(void *self, char *s);
    void get_speaker_balloon_anchor(u16 speaker, f32 *height, s32 *name);
    s32 find_farthest_balloon_slot(u16 speaker);
    TWindowFukidasi *acquire_balloon_slot(u16 speaker, s32 flags, s32 client);
    s32 count_balloon_slots();
    TWindowFukidasi *show_chat_balloon(u16 player, s32 flags, const char *text, s32 client);
    void handle_chat_message(char *arg1);
    static void init_all_slots();
    static void init_all_slots2();
    static void suppress_slot(s32 client);
    static void unsuppress_slot(s32 client);
    static void disable_client_main_menu(s32 client);
    static void enable_client_main_menu(s32 client);
    static s32 has_player_active_menu(s32 client);
    static void apply_default_vec(s32 arg0, saddr client_id);
    static s32 is_slot_visible(s32 client);
    static saddr get_message_by_type(s8 type, s32 client_id);
    static void release_slot(s8 *arg0);
    static void close_windows_by_flags(u16 flags);
    static s32 open_balloon(u16 player, u8 *arg1, s32 flags, s32 client);
    static saddr open(u16 id, const char *text, s32 flags);
    static int open_default(u16 id, const char *text);
    static void create_level_up_window(saddr stats, saddr client);
    static void set_window_flags(void *client_id, s32 flags, s32 arg2);
    static void set_window_flags_off(s32 client, s32 flags);
    static void init_all(void* p, void* a1);
    void init_all_default();
    static void show_party_effect(u16 from, u16 to, u32 kind);
    static void create_party_effect(u16 from, u16 to);
    static void dispatch_to_child(s32 client, s32 kind);
    void update_pulse_color();
    void update_trade_window();
    void handle_controller();
    void update_trade_request_window();
    void update_com_card_window();
    void update_window_visibility();
    void update();
    void update_open_sequence();
    static void shutdown();
    static void close();
    void set_flag1e_bit40();
    static saddr get_window(s32 client_id);
    static s32 query_window(s32 client_id, PlayerWindowQuery query);
    static void call_window_method(s32 client_id, PlayerWindowCommand command);
    static s32 get_flag_bit4();
    static s32 get_flag_bit5();
    static s32 get_display_flag();
    int is_enabled();
    s32 is_visible();
    s32 get_active_menu();
    void update_short_list_request();
    void show_active_window();
    void update_main_menu_request();
    void update_target_info_window();
    void update_child_window_visibility();
    void update_trade_window_visibility();
    void run_all_updates();
    void update_countdown();
    static TWindowMessageLog *get_field44();
    static void set_flag_active();
    static void clear_flag_8();
    static void set_flag_bit0();
    static void clear_active_flag();
    u8 unk_98[0x50];
    static void set_flag_bit2();
    static void clear_flag_bit2();
    static void set_field28(u16 arg0);
    static u16 get_window_id();
    void update_party_status_rows();
    int is_flag_2_set();
    void set_flag1e_bit8();
    void clear_flag1e_bit8();
    void set_radar_dirty_flag();
    void clear_flag_bit0();
    // Mark chat balloon slot 0 taken or free (see TWindowFukidasi::alloc_nearest_free_slot).
    void reserve_balloon_slot_0();
    void release_balloon_slot_0();
    void disable_main_menu();
    void enable_main_menu();
    void hide_lock_on_window();
    void show_lock_on_window();
    void begin_keyboard_hold();
    void end_keyboard_hold();
    void hide_status_window();
    void show_status_window();
    s32 has_get_com_card_window();
    s32 is_main_menu_disabled();
    s32 is_lock_on_window_hidden();
    s32 is_status_window_hidden();
    void start_countdown();
    s32 is_countdown_done();
};

LAYOUT_ASSERT(WindowCtrlTradeRequestOffset, offsetof(TWindowCtrl, trade_request) == 0x40);
LAYOUT_ASSERT(TWindowCtrlBalloonSlotsOffset, offsetof(TWindowCtrl, balloons) == 0x84);
LAYOUT_ASSERT(TWindowCtrl_size, sizeof(TWindowCtrl) == 0xE8);

extern u16 lbl_805D63FC;


#endif
