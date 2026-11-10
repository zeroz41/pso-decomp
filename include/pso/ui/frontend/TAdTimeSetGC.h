#ifndef PSO_UI_FRONTEND_TADTIMESETGC_H
#define PSO_UI_FRONTEND_TADTIMESETGC_H

#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/T_ATS_DrawCalendar.h"
#include "types.h"

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
    static s32 sub_802E1528();
    static s32 is_card_file_absent_a();
    static s32 is_card_file_absent_b();
    static s32 sub_802E15C8();
    static s32 is_load_complete();
    s32 poll_load_status();
    s32 sub_802E1868();
    void sub_802E18C8();
    void apply_settings();
    void close_and_next(s32 entry, s32 sel, s32 first_entry, s32 second_entry);
    void close_and_dispatch(u32 text, s32 sel, u32 first_text, u32 second_text);
    void sub_802E1A04(s32 entry, s32 sel, s32 first_entry, s32 second_entry);
    void open_message_choice(u32 text, s32 sel, u32 first_text, u32 second_text);
    void close_windows();
    void create_backgrounds();
    s32 check_capacity();
    s32 count_selected_flags();
    s32 count_flags();
    void change_state(s32 new_state);
    void init();
    void sub_802E1F14();

    // State handlers, last state first.
    void update_state();
    void sub_802E1F8C();
    void sub_802E1FAC();
    void show_confirm_dialog();
    void sub_802E2158();
    void create_result_bg();
    void build_selection_summary();
    void sub_802E22A4();
    void init_menu_window();
    void sub_802E23E8();
    void sub_802E2450();
    void sub_802E24B8();
    void sub_802E2520();
    void sub_802E2588();
    void sub_802E2610();
    void update_close_on_load();
    void try_setup();
    void sub_802E2728();
    void update_close_timer();
    void sub_802E2848();
    void sub_802E289C();
    void init_screen();
    void update_char_timer();
    void sub_802E2A7C();
    void advance_when_load_done();
    void sub_802E2AD4();
    void update_timer();
    void sub_802E2BC8();
    void sub_802E2BD4();
    void close_scene();
    void update_load_countdown();
    void sub_802E2D3C();
    void update_load_state();
    void close_and_next_cancel();
    void handle_confirm_menu();
    void open_char_select();
    void reset_on_load_complete();
    void sub_802E2F20();
    void ensure_player_loaded();
    void sub_802E2F68();
    void sub_802E2F88();
    void sub_802E2FEC();
    void ensure_system_file_loaded();
    void sub_802E3038();
    void report_card_status();
    void rebuild_and_maybe_close();

    static void sub_802E34A4();
    static void sub_802E34A8();

    s32 state_index;                 // 0x1C: index into the state table
    s32 unk_20;                      // 0x20: set once the system file was loaded (state 2)
    s32 unk_24;                      // 0x24: system file check: -1 not done, 0 passed, 1 failed
    s32 unk_28;                      // 0x28: character file check, same values
    s32 unk_2C;                      // 0x2C: Guild Card file check, same values
    s32 unk_30;                      // 0x30: set when the message of state 7 was closed
    s32 unk_34;                      // 0x34: set when the message of state 12 was closed
    s32 unk_38;                      // 0x38: set when the message of state 13 was closed
    s32 unk_3C;                      // 0x3C: set when state 15 saw the load end
    s32 busy_count;                  // 0x40: consecutive poll_load_status() calls that found the card busy
    s32 load_status;                 // 0x44: poll_load_status() result bits; 0 when every check passed
    TAdBackGC *back;                 // 0x48
    TAdBackTxtGC *back_text;         // 0x4C
    TWindowMessage *message_window;  // 0x50
    TWindowMenu *menu_window;        // 0x54
    T_ATS_DrawCalendar *calendar;    // 0x58
    s32 unknown_5c;                  // 0x5C: 1 when a menu asked to leave without applying the saved options
    s32 timer;                       // 0x60: set to 7 when a window closes, counted down by run_task
    s32 unk_64;                      // 0x64: frames a message stays up; the state handlers set it to 30
    char text[0x400];                // 0x68: message text built by the state handlers
};

typedef char TAdTimeSetGC_size[sizeof(TAdTimeSetGC) == 0x468 ? 1 : -1];

#endif
