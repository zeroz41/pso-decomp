#ifndef PSO_UI_FRONTEND_TADTIMESETGC_H
#define PSO_UI_FRONTEND_TADTIMESETGC_H

#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/T_ATS_DrawCalendar.h"
#include "types.h"
#include <stddef.h>

class TAdBackGC;
class TAdBackTxtGC;
struct TWindowMenu;
struct TWindowMessage;

// Start-up scene that checks the memory card in slot A, creates the missing save files and applies the saved options.
class TAdTimeSetGC : public TObject {
public:
    TAdTimeSetGC(TObject *parent);
    virtual ~TAdTimeSetGC();
    virtual void run_task();

    static s32 is_card_file_missing_a();
    static s32 is_card_file_missing_b();
    static s32 is_system_card_file_missing();
    static s32 is_card_file_absent_a();
    static s32 is_card_file_absent_b();
    static s32 is_system_card_file_absent();
    static s32 is_load_complete();
    s32 poll_load_status();
    s32 is_message_skip_pressed();
    void request_reset_phase();
    void apply_settings();
    void close_and_next(s32 entry, s32 sel, s32 first_entry, s32 second_entry);
    void close_and_dispatch(u32 text, s32 sel, u32 first_text, u32 second_text);
    void open_message_choice_by_entries(s32 entry, s32 sel, s32 first_entry, s32 second_entry);
    void open_message_choice(u32 text, s32 sel, u32 first_text, u32 second_text);
    void close_windows();
    void create_backgrounds();
    s32 check_capacity();
    s32 count_selected_flags();
    s32 count_flags();
    void change_state(s32 new_state);
    void init();
    void reset_check_state();

    // State handlers, last state first.
    void update_state();
    void enter_state_24();
    void run_state_23();
    void show_confirm_dialog();
    void sub_802E2158();
    void create_result_bg();
    void build_selection_summary();
    void run_states_19_21();
    void init_menu_window();
    void enter_state_19();
    void enter_state_18();
    void run_states_17_18();
    void enter_state_17();
    void run_state_16();
    void enter_state_16();
    void update_close_on_load();
    void try_setup();
    void enter_state_14();
    void update_close_timer();
    void enter_state_13();
    void run_state_12();
    void init_screen();
    void update_char_timer();
    void arm_guildcard_delete_timer();
    void advance_when_load_done();
    void enter_state_10();
    void update_timer();
    void arm_char_delete_timer();
    void run_state_8();
    void close_scene();
    void update_load_countdown();
    void arm_load_countdown();
    void update_load_state();
    void close_and_next_cancel();
    void handle_confirm_menu();
    void open_char_select();
    void reset_on_load_complete();
    void enter_state_4();
    void ensure_player_loaded();
    void enter_state_3();
    void run_state_2();
    void enter_state_2();
    void ensure_system_file_loaded();
    void enter_state_1();
    void report_card_status();
    void rebuild_and_maybe_close();

    static void free_scene_resources();
    static void load_scene_resources();

    s32 state_index;                 // 0x1C: index into the state table
    s32 system_file_loaded;                      // 0x20: set once the system file was loaded (state 2)
    s32 system_file_check;                      // 0x24: system file check: -1 not done, 0 passed, 1 failed
    s32 character_file_check;                      // 0x28: character file check, same values
    s32 guild_card_file_check;                      // 0x2C: Guild Card file check, same values
    s32 state7_message_closed;                      // 0x30: set when the message of state 7 was closed
    s32 state12_message_closed;                      // 0x34: set when the message of state 12 was closed
    s32 state13_message_closed;                      // 0x38: set when the message of state 13 was closed
    s32 state15_load_ended;                      // 0x3C: set when state 15 saw the load end
    s32 busy_count;                  // 0x40: consecutive poll_load_status() calls that found the card busy
    s32 load_status;                 // 0x44: poll_load_status() result bits; 0 when every check passed
    TAdBackGC *back;                 // 0x48
    TAdBackTxtGC *back_text;         // 0x4C
    TWindowMessage *message_window;  // 0x50
    TWindowMenu *menu_window;        // 0x54
    T_ATS_DrawCalendar *calendar;    // 0x58
    s32 skip_apply_options;                  // 0x5C: 1 when a menu asked to leave without applying the saved options
    s32 timer;                       // 0x60: set to 7 when a window closes, counted down by run_task
    s32 message_frames;                      // 0x64: frames a message stays up; the state handlers set it to 30
    char text[0x400];                // 0x68: message text built by the state handlers
};

LAYOUT_ASSERT(TAdTimeSetGC_size, sizeof(TAdTimeSetGC) == 0x468);
LAYOUT_ASSERT(TAdTimeSetGC_state_index_offset, offsetof(TAdTimeSetGC, state_index) == 0x1C);
LAYOUT_ASSERT(TAdTimeSetGC_load_status_offset, offsetof(TAdTimeSetGC, load_status) == 0x44);
LAYOUT_ASSERT(TAdTimeSetGC_message_window_offset, offsetof(TAdTimeSetGC, message_window) == 0x50);
LAYOUT_ASSERT(TAdTimeSetGC_menu_window_offset, offsetof(TAdTimeSetGC, menu_window) == 0x54);
LAYOUT_ASSERT(TAdTimeSetGC_calendar_offset, offsetof(TAdTimeSetGC, calendar) == 0x58);
LAYOUT_ASSERT(TAdTimeSetGC_timer_offset, offsetof(TAdTimeSetGC, timer) == 0x60);
LAYOUT_ASSERT(TAdTimeSetGC_text_offset, offsetof(TAdTimeSetGC, text) == 0x68);

// One entry per state: enter is called by change_state, run by run_task every frame.
struct TAdTimeSetGCState {
    void (TAdTimeSetGC::*enter)();
    void (TAdTimeSetGC::*run)();
};

#endif
