#ifndef PSO_UI_TADSYSTEMFILECHECKGC_H
#define PSO_UI_TADSYSTEMFILECHECKGC_H
#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMessage;
struct TWindowMenu;

class TAdSystemFileCheckGC : public TObject {
public:
    TAdSystemFileCheckGC(TObject *object);
    virtual ~TAdSystemFileCheckGC();
    virtual void run_task();
    void close_windows_on_selection();
    s32 get_message(s32 index, s32 text_set);
    void enter_state_10();
    void update_confirm_selection();
    void close_windows_and_cleanup();
    void update_card_confirm_selection();
    void close_windows_and_reopen();
    void close_window_30();
    void handle_menu_input();
    void create_back_objects();
    void enter_state_3();
    void update_mode_selection();
    void load_system_on_mode_default();
    s32 handle_mode_selection();
    void run_state_7();
    void enter_state_7();
    void update_mode_selection_and_save();
    void enter_state_6();
    void check_player_load_result();
    void enter_state_2();
    void request_scene_change_vt();
    void enter_state_9();
    void run_state_8();
    void enter_state_8();
    void set_state(s32 new_state);
    void confirm_mode_selection();
    void enter_state_0();
    void setup_mode_menu(s32 mode);
    void open_message_window(s32 index);
    void close_menu_window();

    s32 state;          // the entry of multi_chg_game_mode_entry_table that is running
    s32 status;         // what check_system_file_status reported
    s32 language;
    void *back;
    void *back_text;
    TWindowMessage *message_window;
    TWindowMenu *menu_window;
};
LAYOUT_ASSERT(TAdSystemFileCheckGC_size, sizeof(TAdSystemFileCheckGC) == 0x38);

#endif
