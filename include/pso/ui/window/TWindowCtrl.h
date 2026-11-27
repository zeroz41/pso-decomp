#ifndef PSO_UI_WINDOW_TWINDOWCTRL_H
#define PSO_UI_WINDOW_TWINDOWCTRL_H

#include "types.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/ui/window/WindowCtrlCallback.h"

struct NJS_POINT2;
struct PlayerLevelStats;
struct TWindowTradeRequest;
struct TWindowTimer;
class TWindowArea;
struct TWindowMessageLog;
struct TWindowSimpleStatus;

struct TWindowGetComCard;
struct TWindowBreakIn;
class TWindowChat;
struct TWindowCtrlPlayer;
struct TObjPlayer;
class TPlyGuildCardTag;
struct TWindowBreakIn;

class TWindowFukidasi;
class TObjBase;

struct TWindowCtrl : public TObject {
    static const char *class_name;
    TWindowCtrl(TObject *parent);
    virtual ~TWindowCtrl();
    static TWindowCtrl *instance;
    u16 flags;
    s16 tick;  // frames since the windows opened; the open sequence and the pulse colour read it
    s16 open_step;  // next entry of the open sequence
    s16 submit_cooldown;
    u32 pulse_color;  // ARGB that update_pulse_color cycles
    u16 window_id;
    u8 _pad2A[0x2];
    TWindowBreakIn *break_in;
    TWindowTimer *timer_window;
    TWindowArea *area_window;
    TWindowChat *chat_window;
    TWindowGetComCard *com_card_window;
    TWindowTradeRequest *trade_request;
    TWindowMessageLog *message_log;
    TWindowCtrlPlayer *players[12];
    TWindowSimpleStatus *simple_status[3];
    TWindowFukidasi *balloons[4];
    void *submission;
    virtual void run_task();
    virtual void render();
    static s32 get_flag_bit3();
    static void clear_flag_2();
    static void set_close_flag();
    static s32 get_pulse_color();
    static s32 get_flag_bit0();
    static void clear_flag();
    static void start_client_countdown(s32 client);
    static s32 is_client_countdown_done(s32 client);
    static void start_submit_cooldown();
    static s32 is_submit_cooldown_clear();
    static void update_focused();
    static s32 get_active_sub();
    static s32 is_chat_window_in_use();
    // Flag 0x10 is held while a quest board is open.
    static void set_quest_board_open();
    static void clear_quest_board_open();
    // Flag 0x20 is held while the return-to-city prompt is open.
    static void set_return_city_open();
    static void clear_return_city_open();
    static void open_status_111();
    static void open_status_112();
    static void close_active_window();
    static void ensure_initialized();
    static void create_timer();
    static void set_timer_window_time(u32 secs);
    static void close_timer_window();
    static void create_alt_timer();
    static char *skip_name_prefix(void *self, char *s);
    void get_speaker_balloon_anchor(u16 speaker, f32 *height, char **name);
    s32 find_farthest_balloon_slot(u16 speaker);
    f32 get_squared_distance_to_entity(TObjBase *from, u16 id);
    TWindowFukidasi *acquire_balloon_slot(u16 speaker, s32 flags, s32 client);
    s32 count_balloon_slots();
    TWindowFukidasi *show_chat_balloon(u16 player, s32 flags, const char *text, s32 client);
    // The handle_06_recv_chat handler construct_lobby_players installs: opens the speaker's balloon.
    static void handle_recv_chat(TPlyGuildCardTag &tag, char *message);
    static void suppress_all_slots();
    static void unsuppress_all_slots();
    static void suppress_slot(s32 client);
    static void unsuppress_slot(s32 client);
    static void disable_client_main_menu(s32 client);
    static void enable_client_main_menu(s32 client);
    static s32 has_player_active_menu(s32 client);
    s32 has_client_short_list(s32 client);
    s32 is_client_main_menu_disabled(s32 client);
    static void show_client_status_window(s32 client);
    static void hide_client_status_window(s32 client);
    static void show_client_lock_on_window(s32 client);
    static void hide_client_lock_on_window(s32 client);
    static void lock_client_main_menu(s32 client);
    static void unlock_client_main_menu(s32 client);
    static void begin_client_keyboard_hold(s32 client);
    static void end_client_keyboard_hold(s32 client);
    static s32 is_slot_visible(s32 client);
    static const NJS_POINT2 *get_message_by_type(s8 type, s32 client_id);
    static void release_slot(s8 *slot);
    static void close_windows_by_flags(u16 flags);
    static s32 open_balloon(u16 player, u8 *text, s32 flags, s32 client);
    static saddr open(u16 id, const char *text, s32 flags);
    static int open_default(u16 id, const char *text);
    static void create_level_up_window(const PlayerLevelStats *stats, saddr client);
    static void append_client_message(s32 client, const char *text, s32 mode);
    static void append_client_message(s32 client, const char *text);
    static void append_message_all(const char *text, s32 mode);
    static void append_message_all(const char *text);
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
    static TWindowCtrlPlayer *get_window(s32 client_id);
    static void replace_submenu(s32 client_id, s16 id);
    static void try_open_battle_menu(s32 client_id, s16 key);
    static s32 query_window(s32 client_id, PlayerWindowQuery query);
    static void call_window_method(s32 client_id, PlayerWindowCommand command);
    static s32 get_flag_bit4();
    static s32 get_flag_bit5();
    static s32 get_display_flag();
    static TWindowMessageLog *get_field44();
    static void set_flag_active();
    static void clear_flag_8();
    static void set_flag_bit0();
    static void clear_active_flag();
    u8 pad_98[0x50];
    static void set_flag_bit2();
    static void clear_flag_bit2();
    s32 is_flag_bit2_set();
    static void set_window_id(u16 id);
    static u16 get_window_id();
    void update_party_status_rows();
    int is_flag_2_set();
};

LAYOUT_ASSERT(WindowCtrlTradeRequestOffset, offsetof(TWindowCtrl, trade_request) == 0x40);
LAYOUT_ASSERT(TWindowCtrlPlayersOffset, offsetof(TWindowCtrl, players) == 0x48);
LAYOUT_ASSERT(TWindowCtrlBalloonSlotsOffset, offsetof(TWindowCtrl, balloons) == 0x84);
LAYOUT_ASSERT(TWindowCtrl_size, sizeof(TWindowCtrl) == 0xE8);

extern u16 short_mail_flags;

void close_window_if_active(s32 client);
s32 is_com_card_window_open(void);
void update_timer_window(TWindowCtrl *ctrl);
void complete_actor_speech_balloons(u16 id);
s32 is_actor_speech_balloon_done(u16 id);
saddr get_party_member_name(s32 n);
s32 is_chat_flag2_clear(const TWindowChat *chat);
void destroy_com_card_window(void);
s32 is_player_input_active(s32 client);
void send_card_window_state();

#endif
