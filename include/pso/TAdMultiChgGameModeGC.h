#ifndef PSO_TADMULTICHGGAMEMODEGC_H
#define PSO_TADMULTICHGGAMEMODEGC_H
#include "pso/TObject.h"
#include "types.h"

class TAdMultiChgGameModeGC : public TObject {
public:
    virtual ~TAdMultiChgGameModeGC();
    virtual void run_task();
    virtual void render();
public:
    static void render();
    static s32 check_players_ready(void * _w0);
    static s32 is_input_phase_active();
    static void set_default_camera();
    static void set_mode_change_state();
    static void set_change_mode_flags();
    static void apply_bgm_col_ctrl(s32 arg0);
    static void set_state_0x1a();
    static void reset_and_set_mode();
    static void set_mode_18();
    static void set_mode_17();
    static void set_mode_0x15();
    static void set_mode_0x14();
    static void request_transition();
    static void reset_mode_state();
    static void set_mode_state_0e();
    static void set_mode_state_0d();
    static void set_state_0xc();
    static void begin_change_game_mode();
    static void begin_transition();
    static void set_state_0x9();
    static void request_scene_change();
    static void set_change_game_mode();
    static void set_game_mode();
    static void set_game_mode_state();
    static void set_game_mode_changed();
    static void init_change_mode();
    static void create_mode_scene();
    static void set_mode_1c();
    static void render_scene();
    static void render_game_mode_change();
    static void sync_mode_state();
public:
    void close_windows_on_selection();
    void update_confirm_selection();
    void update_card_confirm_selection();
    void close_windows_and_reopen();
    void close_window_30();
    static s32 setup_mode_menu(void *arg0, s32 arg1);
    void handle_menu_input();
    void create_back_objects();
    void update_mode_selection();
    void load_system_on_mode_default();
    s32 handle_mode_selection();
    void update_mode_selection_and_save();
    void check_player_load_result();
    void request_scene_change_vt();
    void set_state(s32 arg1);
    void confirm_mode_selection();
    void sub_8036DEDC();
    void close_windows_and_cleanup();
    void sub_8036E51C();
    void sub_8036E6A0();
    void sub_8036E6EC();
    void sub_8036E750();
    void sub_8036E7DC();
    void sub_8036E830();
    void sub_8036E834();
    void sub_8036E854();
    void sub_8036E9EC();
};

#endif
