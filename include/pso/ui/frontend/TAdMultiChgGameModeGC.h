#ifndef PSO_UI_FRONTEND_TADMULTICHGGAMEMODEGC_H
#define PSO_UI_FRONTEND_TADMULTICHGGAMEMODEGC_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TAdGuideTxtGC;
class TAdSelectCurGC;

class TAdMultiChgGameModeGC : public TObject {
public:
    TAdMultiChgGameModeGC(TObject *parent);
    virtual ~TAdMultiChgGameModeGC();
    virtual void run_task();
    virtual void render();
public:
    static s32 check_players_ready(void * _w0);
    static s32 is_input_phase_active();
    static void set_default_camera();
    static void set_mode_change_state();
    static void set_change_mode_flags();
    static void apply_bgm_col_ctrl(const char *name);
    void set_state_0x1a();
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
    void set_mode_1c();
    static void render_scene();
    static void render_game_mode_change();
    static void sync_mode_state();
public:

    s32 pad_1C;
    s32 selection;
    s32 prev_selection;
    TAdGuideTxtGC *guide_text;
    TAdSelectCurGC *select_cursor;
};

LAYOUT_ASSERT(TAdMultiChgGameModeGC_size, sizeof(TAdMultiChgGameModeGC) == 0x30);

extern "C" {
void fn_802FFC78(void);
void fn_802FFC7C(void);
}

#endif
