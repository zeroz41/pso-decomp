#ifndef PSO_UNK_TTITLE_SCENE_H
#define PSO_UNK_TTITLE_SCENE_H
// Owns the title layers, attract timer, and game-mode transitions.
#include <stddef.h>
#include "types.h"
#include "pso/system/task/TObject.h"

class TTitleMenu;
class TTitleLogo;
class TTitleBackground;

class TTitleScene : public TObject {
public:
    TTitleScene(TObject *parent);
    virtual ~TTitleScene();
    virtual void run_task();
    virtual void render();
    void set_flag_and_clear_download();
    s32 start_offline_seq();
    // Once the title menu has a confirmed entry: fades out and runs the state handler for its cursor.
    void dispatch_title_choice();
    void enter_chg_game_mode();
    void enter_game_mode_change();
    void request_change_game_mode();
    void open_keyboard();
    void close_auxiliary_window();

    TTitleBackground *title_layer;
    TTitleLogo *overlay_layer;
    TTitleMenu *transition_controller;
    s32 m_28;
    TObject *auxiliary_window;
    s32 m_30;
    s32 attract_tick;
    s32 attract_timeout;
    u32 transition_flags;
    TObject *transition_children[3];
};

void hide_title_layers_and_release(TTitleScene *scene);
LAYOUT_ASSERT(TTitleScene_size, sizeof(TTitleScene) == 0x4C);

LAYOUT_ASSERT(TTitleScene_title_layer_offset, offsetof(TTitleScene, title_layer) == 0x1C);
LAYOUT_ASSERT(TTitleScene_controller_offset, offsetof(TTitleScene, transition_controller) == 0x24);
LAYOUT_ASSERT(TTitleScene_auxiliary_window_offset, offsetof(TTitleScene, auxiliary_window) == 0x2C);
LAYOUT_ASSERT(TTitleScene_attract_tick_offset, offsetof(TTitleScene, attract_tick) == 0x34);
LAYOUT_ASSERT(TTitleScene_flags_offset, offsetof(TTitleScene, transition_flags) == 0x3C);
LAYOUT_ASSERT(TTitleScene_children_offset, offsetof(TTitleScene, transition_children) == 0x40);

s8 lobby_server_choice_stub(void);

// One scene resource: load runs front to back (run_load_callback_table),
// release back to front (call_funcs_reverse); field names inferred from those.
struct LobbyLoadCallback {
    void (*load)(void);
    void (*release)(void);
};

class TTitleScene;

void title_choice_stub(TTitleScene *scene);
void initialize_lobby_title_scene(void);

#endif
