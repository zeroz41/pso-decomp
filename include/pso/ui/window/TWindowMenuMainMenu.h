#ifndef PSO_UI_WINDOW_TWINDOWMENUMAINMENU_H
#define PSO_UI_WINDOW_TWINDOWMENUMAINMENU_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct WindowDrawContext;

struct TWindowMenuMainMenu : public TWindowBase {
    TWindowMenuMainMenu(saddr arg1, s16 arg2);
    virtual ~TWindowMenuMainMenu();
    void handle_navigation_input();
    void handle_confirm();
    void handle_cancel();
    int get_menu_flag();
    int is_flag_set();
    void draw_frame(WindowDrawContext *frame);
    void set_target_y(f32 y);
    void update_scaled_position();
    void update_slide_position();
    virtual void render();
    virtual void run_task();
    u8 m_60;
    u8 m_61;
    u16 m_62;
    void* m_64;
    u8 unk_68[0xDC];
};

LAYOUT_ASSERT(TWindowMenuMainMenu_size, sizeof(TWindowMenuMainMenu) == 0x144);

extern "C" {
void render__19TWindowMenuMainMenuFv(saddr arg0);
void run_task__19TWindowMenuMainMenuFv(TWindowMenuMainMenu *window_menu_main_menu);
}

// --- C functions defined in TWindowMenuMainMenu.cpp ---
extern "C" {
void render__19TWindowMenuMainMenuFv(saddr arg0);
void run_task__19TWindowMenuMainMenuFv(TWindowMenuMainMenu *window_menu_main_menu);
}
// --- end of C functions

#endif
