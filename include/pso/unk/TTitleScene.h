#ifndef PSO_UNK_TTITLE_SCENE_H
#define PSO_UNK_TTITLE_SCENE_H
// Owns the title layers, attract timer, and game-mode transitions.
#include <stddef.h>
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804EE458;
class TUnk_804EE470;
class TUnk_804EEF80;

class TTitleScene : public TObject {
public:
    virtual ~TTitleScene();
    virtual void run_task();
    virtual void render();
    TTitleScene *construct_title_scene();
    void set_flag_and_clear_download();
    s32 start_offline_seq();
    void enter_chg_game_mode();
    void enter_game_mode_change();
    void request_change_game_mode();
    void open_keyboard();
    void close_auxiliary_window();

    TUnk_804EEF80 *title_layer;
    TUnk_804EE470 *overlay_layer;
    TUnk_804EE458 *transition_controller;
    s32 m_28;
    TObject *auxiliary_window;
    s32 m_30;
    s32 attract_tick;
    s32 m_38;
    u32 transition_flags;
    TObject *transition_children[3];
};
LAYOUT_ASSERT(TTitleScene_size, sizeof(TTitleScene) == 0x4C);

typedef char TTitleScene_title_layer_offset[offsetof(TTitleScene, title_layer) == 0x1C ? 1 : -1];
typedef char TTitleScene_controller_offset[offsetof(TTitleScene, transition_controller) == 0x24 ? 1 : -1];
typedef char TTitleScene_auxiliary_window_offset[offsetof(TTitleScene, auxiliary_window) == 0x2C ? 1 : -1];
typedef char TTitleScene_attract_tick_offset[offsetof(TTitleScene, attract_tick) == 0x34 ? 1 : -1];
typedef char TTitleScene_flags_offset[offsetof(TTitleScene, transition_flags) == 0x3C ? 1 : -1];
typedef char TTitleScene_children_offset[offsetof(TTitleScene, transition_children) == 0x40 ? 1 : -1];

#endif
