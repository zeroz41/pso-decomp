#ifndef PSO_UI_FRONTEND_TADMULTICHGGAMEMODEGC_H
#define PSO_UI_FRONTEND_TADMULTICHGGAMEMODEGC_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/frontend/TAdSelectTxtGC.h"

class TAdGuideTxtGC;
class TAdSelectCurGC;

class TAdMultiChgGameModeGC : public TObject {
public:
    static const char *class_name;
    TAdMultiChgGameModeGC(TObject *parent);
    virtual ~TAdMultiChgGameModeGC();
    virtual void run_task();
    virtual void render();
public:
    static s32 check_players_ready(void * _w0);
    static s32 is_input_phase_active();
    static void set_default_camera();
    static void open_dialing_select_scene();
    static void open_level_select_scene();
    static void apply_bgm_col_ctrl(const char *name);
    static void open_pso_pass_save_scene();
    static void open_enter_ppp_pass_scene();
    static void set_mode_18();
    static void open_trial_agreement_scene();
    static void open_ex_net_confirm_scene();
    static void open_sn_ak_pass_confirm_scene();
    static void open_lic_agreement_scene();
    static void open_enter_serial_access_scene();
    static void set_mode_state_0e();
    static void set_mode_state_0d();
    static void open_multi_sel_game_mode_scene();
    static void open_multi_chg_game_mode_scene();
    static void open_multi_confirm_scene();
    static void open_multi_save_scene();
    static void open_time_set_scene();
    static void open_multi_ply_chr_select_scene();
    static void open_single_ply_chr_select_scene();
    static void open_select_game_mode_scene();
    static void open_story_select_scene();
    static void open_title_scene();
    static void create_mode_scene();
    static void open_ep3_exist_scene();
    static void open_enter_password_scene();
    // Init hooks of main_phase_table: build the front-end scene and open one screen.
    static void init_dialing_select_phase();
    static void init_level_select_phase();
    static void init_trial_agreement_phase();
    static void init_enter_password_phase();
    static void init_multi_save_phase();
    static void init_time_set_phase();
    static void init_story_select_phase();
    static void init_title_phase();
    // Load and free entry of game_mode_select_scene_callbacks.
    static void load_scene_resources();
    static void free_scene_resources();
    static void sync_mode_state();
public:

    s32 pad_1C;
    s32 selection;
    s32 prev_selection;
    TAdGuideTxtGC *guide_text;
    TAdSelectCurGC *select_cursor;
};

LAYOUT_ASSERT(TAdMultiChgGameModeGC_size, sizeof(TAdMultiChgGameModeGC) == 0x30);

// Defined in TAdMultiChgGameModeGC_Scenes.cpp. The unload/load pair runs the lobby
// scene hook table (unload halves in reverse, then the load halves): the options and
// time-set screens call it after a language change.
void unload_lobby_scene_resources(void);
void load_lobby_scene_resources(void);
void init_game_mode_select_scene(void);

// The front-end phases' frame loop (main_phase_table), defined in
// TAdMultiChgGameModeGC_Scenes.cpp.
void run_game_mode_select_frame(void);

struct MultiChgGameModeTextLayouts { TAdSelectTxtLayout v[3]; };

struct MultiChgGameModePositions { NJS_POINT2 v[3]; };
extern s32 multi_chr_select_state;

extern int chg_game_mode_state_synced;

#endif
